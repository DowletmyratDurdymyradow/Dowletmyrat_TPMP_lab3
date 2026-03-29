-- Lab 3 Part 1 bootstrap script for students.db
DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS groups;
DROP TABLE IF EXISTS marks;

CREATE TABLE students (
  Student_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  FirstName TEXT NOT NULL,
  LastName TEXT NOT NULL,
  Group_id INTEGER NOT NULL,
  height INTEGER NOT NULL DEFAULT 0,
  weight INTEGER NOT NULL DEFAULT 0,
  age INTEGER NOT NULL DEFAULT 0
);

CREATE TABLE groups (
  Group_id INTEGER PRIMARY KEY NOT NULL,
  Name TEXT NOT NULL
);

INSERT INTO students (FirstName, LastName, Group_id, height, weight, age) VALUES
('Ivan','Petrov',13,193,76,22),
('Kirill','Ivanov',14,180,86,21),
('Dmitry','Vasilev',15,170,82,23),
('Elena','Bobrova',13,170,60,21),
('Katya','Bozhko',14,164,56,22),
('Nina','Stomina',15,160,54,21),
('Aina','Myradova',13,168,58,20),
('Maksat','Nuryev',14,175,72,22),
('Leyla','Ataeva',15,166,55,20);

INSERT INTO groups (Group_id, Name) VALUES
(13, 'Group 13'),
(14, 'Group 14'),
(15, 'Group 15'),
(16, 'Group 16');
