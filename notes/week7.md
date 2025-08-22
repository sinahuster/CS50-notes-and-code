# CS50 Week 7 - SQL 

## Topics Covered 
- Flat-file Databases
- Relational Databases
- CRUD Operations (SELECT, INSERT, DELETE, UPDATE)
- JOINs
- Indexes
- Using SQL in Python
- Race Conditions
- SQL Injection Attacks

SQL (Structured Query Language) is the standard language to interact with relational databases. 

## Flat-File Databases 
- A flat-file database stores information in plain text (e.g. CSV)
- Limitations:
    - No relationships betweeen data
    - Redundant and inconsistent values
    - Difficult to query efficiently

 
## Realtional Databases 
- Relational databases organise data into tables (relations)
- Each table is made up of rows (records) and columns (fields)
- Keys:
    - Primary Key: uniquely identifies each row
    - Foreign Key: references a primary key in another table
- Benefits:
    - Reduces redundancy (normalisation)
    - Easier to update and maintain
    - Useful queries using relationships


 ## CRUD Operations

 ### SELECT (Read Data)
 ```
SELECT * FROM students;
SELECT name, gpa FROM students WHERE gpa > 3.5 ORDER BY gpa DESC LIMIT 5;
```


 ### INSERT (Add Data)
 ```
INSERT INTO students (name, age, gpa)
VALUES ("Alice", 20, 3.8);
```


 ### DELETE (Remove Data)
 ```
DELETE FROM students WHERE id = 3;
```


 ### UPDATE (Modify Data)
 ```
UPDATE students
SET gpa = 3.9
WHERE name = "Alice";
```

## JOINs 
- Combine rows from multiple tables
- Inner join:
  ```
  SELECT students.name, courses.title
  FROM students
  JOIN enrollments ON students.id = enrollments.student_id
  JOIN courses ON courses.id = enrollments.course_id;
  ```
- Left join:
  ```
  SELECT students.name, enrollments.course_id
  FROM students
  LEFT JOIN enrollments ON students.id = enrollments.student_id;
  ```

## Indexes 
- Improves the performance of queries
- Speeds up searches but uses extra storage
- More useful on frequently queried columns
  ```
  CREATE INDEX idx_gpa ON students (gpa);
  ```

## Using SQL in Python
- Python has the sqlite3 library which allows interaction with SQLite databases
- We must use parametrised queries (?) to prevent a SQL injection
```
import sqlite3

db = sqlite3.connect("students.db")
cursor = db.cursor()

cursor.execute("SELECT * FROM students WHERE gpa > ?", (3.5,))
rows = cursor.fetchall()

for row in rows:
    print(row)

db.close()
```

## Race Conditions 
- These occur when multiple people try to access and modify a database at once
- They can lead to inconsistent and corrupted data
- Solutions:
    - Transactions (BEGIN, COMMIT, ROLLBACK)
    - Locks which can ensure only one process updates at a time


## SQL Injection Attacks
- This is when input is used to manipulate queries
```
-- Example attack
SELECT * FROM users WHERE username = '' OR '1'='1';
```
- Prevented by:
    - Using parameterised queries in python (?)
    - Validating using input
 

## Code Descriptions

1. favorites.sql - changed the name of data in the favorites.db, using UPDATE 

2. movies.sql - created varies queries which search the movies.db, includes use of JOIN, ORDER BY, LIMIT

3. log.sql, answers.txt (fiftyville) - searched through the data in fiftyville.db to find out who the theif and accomplice were

4. prophecy.py - using SQL within python to create a database and insert the data from a .csv
