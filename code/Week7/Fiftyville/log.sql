-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get the crime scene report 28.07.2024
SELECT description FROM crime_scene_reports WHERE year = 2024 AND month = 7 AND day = 28
 AND street = 'Humphrey Street';

-- Activity, license plates and minutes on the bakery security logs in the hour of 10am
SELECT activity, license_plate, minute FROM bakery_security_logs WHERE year = 2024 AND
month = 7 AND day = 28 AND hour = 10;

-- names and transcripts from interviews conducted on the 28th July 2024
SELECT name, transcript FROM interviews WHERE year = 2024 AND month = 7 AND day = 28;

-- list name, phone number, passport number and match to a license plate from someone who left
-- approximately at 10:25
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate = '322W7JE';
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate = '0NTHK55';
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate = 'G412CB7';
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate = 'L93JTIZ';
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate = '5P2BI95';
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate = '94KL13X';
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate = '6P58WS2';
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate = '4328GD8';

--  ATM transactions on Leggett Street 28.07.2024
SELECT account_number, transaction_type, amount FROM atm_transactions WHERE year = 2024 AND month = 7
AND day = 28 AND atm_location = 'Leggett Street';

-- Flights which leave on the 29.07.2024
SELECT id, destination_airport_id, hour, minute FROM flights WHERE year = 2024 AND month = 7 AND day = 29 AND origi
n_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville');

-- Find the airport which is the destination of the earliest flight (08:20)
SELECT city FROM airports WHERE id = 4;

-- Find the passengers which are on the flight to NYC
SELECT passport_number FROM passengers WHERE flight_id = 36;

-- Look at the phone logs from Kelsey's phone at the time of the robbery
SELECT receiver, duration FROM phone_calls WHERE caller = '(499) 555-9472' AND year = 2024
AND month = 7 AND day = 28;

-- Look at the phone logs from Sofia's phone at the time of the robbery
SELECT receiver, duration FROM phone_calls WHERE caller = '(130) 555-0289' AND year = 2024
AND month = 7 AND day = 28;

-- Find the names of the people who withdrew cash at the ATM
SELECT name, account_number FROM people JOIN bank_accounts ON person_id = id WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2024 AND month = 7 AND day = 28 AND
atm_location = 'Leggett Street' AND transaction_type = 'withdraw');

-- Find the names of all passengers on the flight to NYC
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE
flight_id = 36);

-- Find the names of the people who made a call less than one minute on the 28.07.2024
SELECT caller.name AS caller_name, receiver.name AS receiver_name
FROM phone_calls c JOIN people caller ON caller.phone_number = c.caller
JOIN people receiver ON receiver.phone_number = c.receiver
WHERE c.duration < 60;
