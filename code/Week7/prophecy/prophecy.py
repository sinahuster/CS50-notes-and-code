from cs50 import SQL
import csv

# This ensures the file exists
open("new_roster.db", "a").close()

# Open database
db = SQL("sqlite:///new_roster.db")

# Delete tables that already exsist
db.execute("DROP TABLE IF EXISTS house_assignments")
db.execute("DROP TABLE IF EXISTS students")
db.execute("DROP TABLE IF EXISTS houses")

# Create table
db.execute("CREATE TABLE IF NOT EXISTS students(id INTEGER, name TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE IF NOT EXISTs houses(id INTEGER, house TEXT, house_head TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE IF NOT EXISTS house_assignments(student_id INTEGER, house_id INTEGER, FOREIGN KEY(student_id) REFERENCES students(id), FOREIGN KEY(house_id) REFERENCES houses(id))")

data = []
houses = {}

with open('students.csv', 'r') as file:
    csv_reader = csv.DictReader(file)
    for row in csv_reader:
        data.append(row)

for row in data:
    db.execute("INSERT INTO students (id, name) values (?, ?)", row['id'], row['student_name'])
    if not row['house'] in houses:
        result = db.execute("INSERT INTO houses (house, house_head) values(?, ?)", row['house'], row['head'])
        houses[row['house']] = result
    house_id = houses[row['house']]
    db.execute("INSERT INTO house_assignments(student_id, house_id) values(?, ?)", row['id'], house_id)

# Check table contents
print(db.execute("SELECT * FROM students"))
print(db.execute("SELECT * FROM houses"))
print(db.execute("SELECT * FROM house_assignments"))
