-- List of the titles of all the movies which were released in 2008
SELECT title FROM movies WHERE year = 2008;

-- Determines the birth year of Emma Stone
SELECT birth FROM people WHERE name = "Emma Stone";

-- List the titles of movies released in or after 2018, ordered alphabetically
SELECT title FROM movies WHERE year >= 2018 ORDER BY title;

-- Determines the number of movies with IMDb rating 10.0
SELECT COUNT(movie_id) FROM ratings WHERE rating = 10.0;

-- Lists the titles and release years of all Harry Potter movies, in chronological order
SELECT title, year FROM movies WHERE title LIKE "%Harry Potter%" ORDER BY year;

-- Determine the average rating of all movies released in 2012
SELECT AVG(rating) FROM ratings JOIN movies ON movie_id = id WHERE year = 2012;

-- List all movies released in 2010 and their raitings, in descending order of rating.
-- If the rating is the same, order them alphabetically by title.
SELECT title, rating FROM movies JOIN ratings ON id = movie_id WHERE year = 2010 ORDER BY rating DESC, title;

-- List the names of the people who starred in Toy Story
SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id =
(SELECT id FROM movies WHERE title = 'Toy Story'));

-- List the names of people who starred in movies released in 2004, ordered by birth year
SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id IN
(SELECT id FROM movies WHERE year = 2004)) ORDER BY birth;

-- List the names of people who directed movies that recieved a rating of at least 9.0
SELECT name FROM people WHERE id IN (SELECT person_id FROM directors WHERE movie_id IN
(SELECT movie_id FROM ratings WHERE rating >= 9.0));

-- List the top 5 highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
SELECT title FROM movies JOIN ratings ON movie_id = id WHERE id IN
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE
name = "Chadwick Boseman")) ORDER BY rating DESC LIMIT 5;

-- List the titles of movies that starred both Bradley Cooper and Jennifer Lawrence
SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id =
(SELECT id FROM people WHERE name = 'Jennifer Lawrence')) AND id IN (
SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Bradley Cooper'));

-- List all the names of people who have starred in movies also starred in by Kevin Bacon
SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id IN
(SELECT id FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id =
(SELECT id FROM people WHERE name = "Kevin Bacon")))) AND name <> "Kevin Bacon";
