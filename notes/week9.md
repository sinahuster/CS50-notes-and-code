# CS50 Week 9 - Flask 

## Topics Covered
- Flask (Python web framework)
- Routes and Views
- Templates (jinja2)
- Forms and Request Handling
- Sessions and Cookies
- Database with Flask (SQLite)
- APIs with Flask
- Deployment Concepts

## Flask
Flask is a third-party library that allows us to host web applications using the Flask framework, or a micro-framework, within Python.

A basic flask app:
```
from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "Hello, world!"

if __name__ == "__main__":
    app.run()
```

```@app.route("/")``` defines a URL route 
```def index()``` view fucntion to handle requests

The app is run with ```flask run``` which also requires us to have a ```app.py``` and ```requirements.txt```.
```app.py``` contains code the tells Flask how to run your web application. 
```requirements.txt```  includes a list of the libraries that are required for your Flask application to run.

## Routes and Views 
There can be multiple routes:
```
@app.route("/")
def home():
    return "Home Page"

@app.route("/about")
def about():
    return "About Page"
```

Dynamic routes:
```
@app.route("/hello/<name>")
def hello(name):
    return f"Hello, {name}!"
```

## Templates (jinja2)

Templates allow separation of HTML and Python logic.

We have a template called layout.html:
```
<!DOCTYPE html>

<html lang="en">

    <head>
        <meta name="viewport" content="initial-scale=1, width=device-width">
        <title>hello</title>
    </head>

    <body>
        {% block body %}{% endblock %}
    </body>

</html>
```
The ```{% block body %}{% endblock %}``` allows for insertion of code from other HTML files.

Then we can have index.html as follows:
```
{% extends "layout.html" %}

{% block body %}

    <form action="/greet" method="get">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <button type="submit">Greet</button>
    </form>

{% endblock %}
```

So jinja2 features include:
- ```{{ variable }}``` for substitution
- ```{% for item in items %}...{% endfor %}```
- ```{% if condition %}...{% endif %}```

## Forms and Request Handling

In scenarios where usernames and passwords would appear in the URL, it is not safe to use ```get``` so instead we must use ```post```.

An example using the ```post``` method:
```
# Switches to POST

from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/greet", methods=["POST"])
def greet():
    return render_template("greet.html", name=request.form.get("name", "world"))
```

However, both ```post``` and ```get``` can be used through a single route:
```
# Uses a single route

from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        return render_template("greet.html", name=request.form.get("name"))
    return render_template("index.html")
```

## Sessions and Cookies 
app.py is considered a controller. A view is considered what the users see. 
A model is how data is stored and manipulated. Together, this is referred to as MVC (model, view, controller).

Cookies are small files that are stored on your computer such that your computer can communicate with the server to communicate 
authorisation. This authorisation through this cookie is called a session.

Then we can have a login.html 
```
{% extends "layout.html" %}

{% block body %}

    <form action="/login" method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <button type="submit">Log In</button>
    </form>

{% endblock %}
```

and an app.py as follows:
```
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    return render_template("index.html", name=session.get("name"))


@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")


@app.route("/logout")
def logout():
    session.clear()
    return redirect("/")
```

```session["name"]``` is used in the login and logout routes. The login route will assign the login name provided and assign it to ```session["name"]```. 
However, in the logout route, the logging out is implemented by clearing the value of session.

The ```session``` abstraction allows us to ensure only a specific user has access to specific data and features in our application. 
It allows us to ensure that no one acts on behalf of another user.

## Database with Flask (SQLite)

We can use sqlite3 within the python as follows:
```
import sqlite3
from flask import request

conn = sqlite3.connect("users.db")
db = conn.cursor()

@app.route("/register", methods=["POST"])
def register():
    username = request.form.get("username")
    db.execute("INSERT INTO users (username) VALUES (?)", (username,))
    conn.commit()
    return "Registered!"
```

## APIs with Flask 

An application program interface or API is a series of specifications that allow you to interface with another service.

JavaScript Object Notation or JSON is a text file of dictionaries with keys and values.
JSON is a very useful way of getting back data from the server.
Flask can serve JSON responses 
```
from flask import jsonify

@app.route("/api/data")
def api_data():
    data = {"name": "CS50", "language": "Python"}
    return jsonify(data)
```

## Code Descriptions
