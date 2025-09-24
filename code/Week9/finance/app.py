import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Determine the avaliable cash of the user
    cash_avaliable = db.execute("SELECT cash FROM users WHERE id = ?",
                                session["user_id"])[0]["cash"]

    # Find all the purchases of the user
    portfolio = db.execute(
        "SELECT symbol, shares FROM portfolio WHERE user_id = ?", session["user_id"])

    # For each symbol, find the current shares value price and total share value
    current = []

    total_stock_value = 0

    for stock in portfolio:
        symbol = stock["symbol"]
        quote = lookup(symbol)
        price = quote["price"]
        shares = stock["shares"]
        stock_value = shares * price

        total_stock_value += stock_value

        current.append({
            "symbol": symbol,
            "shares": shares,
            "price": usd(price),
            "stock_value": usd(stock_value),
        })

    total = usd(total_stock_value + cash_avaliable)
    cash_avaliable = usd(cash_avaliable)

    return render_template("index.html", portfolio=current, cash=cash_avaliable, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # If the user has reached the route POST
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Check if the symbol is blank
        if not symbol:
            return apology("Please enter a symbol")

        # Check the user input a number of shares
        if not shares:
            return apology("Please input a number of shares")

        # Check shares is a postive integer
        if not shares.isdigit() or int(shares) <= 0:
            return apology("Please enter a valid number of shares")

        # Determine the stock the symbol belongs to
        stock = lookup(symbol)

        # Check if the stock exsists
        if stock == None:
            return apology("This symbol does not exsist")

        # Determine how much cash the user has avaliable
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        # Check the user can afford to buy these shares
        cash_spent = stock["price"] * int(shares)
        if cash_spent > cash[0]["cash"]:
            return apology("Unfortunately, you do not have the funds to buy these stocks")

        # Add the purchase to the table
        db.execute("INSERT INTO transactions (user_id, symbol, price, purchase_time, shares) VALUES (?, ?, ?, ?, ?)",
                   session["user_id"], symbol.upper(), stock["price"], datetime.datetime.now(), int(shares))

        # Add to portfolio
        rows = db.execute("SELECT shares FROM portfolio WHERE symbol = ?", symbol.upper())
        if len(rows) == 1:
            db.execute("UPDATE portfolio SET shares = shares + ? WHERE symbol = ? AND user_id = ?",
                       shares, symbol.upper(), session["user_id"])
        else:
            db.execute("INSERT INTO portfolio (user_id, symbol, shares) VALUES (?, ?, ?)",
                       session["user_id"], symbol.upper(), shares)

        # Determine the new value of cash for the user
        cash[0]["cash"] = cash[0]["cash"] - cash_spent
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash[0]["cash"], session["user_id"])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Find all previous transactions
    transactions = db.execute(
        "SELECT symbol, shares, price, purchase_time FROM transactions WHERE user_id = ?", session["user_id"])

    history = []

    for row in transactions:

        if int(row["shares"]) > 0:
            type = "bought"
        else:
            type = "sold"

        history.append({
            "symbol": row["symbol"],
            "shares": abs(row["shares"]),
            "price": usd(row["price"]),
            "type": type,
            "time": row["purchase_time"]
        })

    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # If the user has reached the route POST
    if request.method == "POST":
        symbol = request.form.get("symbol")

        # Check if the symbol is blank
        if not symbol:
            return apology("Please enter a symbol")

        stock = lookup(symbol)

        if (stock == None):
            return apology("This symbol does not exsist")

        # Format the price to 2 decimal places
        stock["price"] = usd(stock["price"])

        return render_template("quoted.html", stock=stock)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # If the user has reached the route POST
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Check if the username is blank
        if not username:
            return apology("Please enter a username")

        # Check if the password is blank
        if not password:
            return apology("Please enter a password")

        # Check if the confirmation is blank
        if not confirmation:
            return apology("Please enter a confirmation")

        # Check if the password and confirmation match
        if password != confirmation:
            return apology("The passwords do not match")

        # Hash the password
        password_hash = generate_password_hash(password)

        # Check if a username exsists
        existing = db.execute("SELECT * FROM users WHERE username = ?", username)
        if existing:
            return apology("This username already exists")

        # Try the insert the person into the database
        try:
            new_user_id = db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?)", username, password_hash)

        except (ValueError, sqlite3.IntegrityError):
            return apology("This username already exists")

        # Check in case ValueError wasn't raised
        if not new_user_id:
            return apology("This username already exists")

        # Log in the user automatically
        session["user_id"] = new_user_id

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # If the user reached route POST
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        # Check the user has input a symbol
        if not symbol:
            return apology("Please enter a symbol")

        # Check the use rhas put in a positive number of shares to sell
        if not shares or shares < 1:
            return apology("Please enter a positive number of shares")

        # Find the symbols and shares of the stocks which are owned
        rows = db.execute(
            "SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)

        if len(rows) != 1:
            return apology("You do not have any shares in this stock")

        owned_shares = rows[0]["shares"]

        if owned_shares == shares:
            db.execute("DELETE FROM portfolio WHERE symbol = ? AND user_id = ?",
                       symbol, session["user_id"])

        elif owned_shares < shares:
            return apology("You do not have enough shares in this stock")

        elif owned_shares > shares:
            db.execute("UPDATE portfolio SET shares = shares - ? WHERE symbol = ? AND user_id = ?",
                       shares, symbol.upper(), session["user_id"])

        # Find the current price of the shares
        quote = lookup(symbol)
        cash_gained = quote["price"] * shares

        db.execute("INSERT INTO transactions (user_id, symbol, price, purchase_time, shares) VALUES (?, ?, ?, ?, ?)",
                   session["user_id"], symbol.upper(), quote["price"], datetime.datetime.now(), -int(shares))

        # Redirect to the homepage
        return redirect("/")

    # If the user reached route GET
    else:
        rows = db.execute("SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"])
        symbols = [rows["symbol"] for rows in rows]
        return render_template("sell.html", symbols=symbols)


@app.route("/reset", methods=["GET", "POST"])
def reset():
    """Reset the users password"""

    # If user uses method POST
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username:
            return apology("Please enter a username")

        if not password:
            return apology("Please enter a password")

        if not confirmation or password != confirmation:
            return apology("Please enter a confirmed password that matches the first one")

        # Check the username exsists
        users = db.execute("SELECT hash FROM users WHERE username = ?", username)

        if len(users) != 1:
            return apology("This username doesn't exsist")

        # Check if new password is equal to the old one
        new_hash = generate_password_hash(password)

        if new_hash == users[0]["hash"]:
            return apology("You cannot use the same password again")

        db.execute("UPDATE users SET hash = ? WHERE username = ?", new_hash, username)

        # Redirect to login
        return redirect("/login")

    # If user uses route is GET
    else:
        return render_template("reset.html")

