-- Lab 3 Part 2 bootstrap script for students.db
DROP TABLE IF EXISTS subj_teach;
DROP TABLE IF EXISTS teachers;
DROP TABLE IF EXISTS subjects;
DROP TABLE IF EXISTS marks;
DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS groups;

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

CREATE TABLE subjects (
  Subject_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  Title TEXT NOT NULL
);

CREATE TABLE teachers (
  Teacher_id INTEGER PRIMARY KEY NOT NULL,
  FirstName TEXT NOT NULL,
  LastName TEXT NOT NULL
);

CREATE TABLE subj_teach (
  ST_id INTEGER PRIMARY KEY NOT NULL,
  Subject_id INTEGER NOT NULL,
  Teacher_id INTEGER NOT NULL,
  Group_id INTEGER NOT NULL
);

CREATE TABLE marks(
  MarkId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  Student_id INTEGER NOT NULL,
  Subject_id INTEGER NOT NULL,
  Date TEXT NOT NULL,
  Mark INTEGER NOT NULL
);

INSERT INTO groups (Group_id, Name) VALUES
(13, 'Group 13'),
(14, 'Group 14'),
(15, 'Group 15'),
(16, 'Group 16');

INSERT INTO students (FirstName, LastName, Group_id, height, weight, age) VALUES
('Ivan','Petrov',13,193,76,22),
('Kirill','Ivanov',14,180,86,21),
('Dmitry','Vasilev',15,170,82,23),
('Elena','Bobrova',13,170,60,21),
('Katya','Bozhko',14,164,56,22),
('Nina','Stomina',15,160,54,21);

INSERT INTO subjects (Title) VALUES
('Programming'),
('Algorithms'),
('Databases'),
('Computer Networks'),
('Operating Systems'),
('Mathematics');

INSERT INTO teachers (Teacher_id, FirstName, LastName) VALUES
(1, 'Tatyana', 'Ivanova'),
(2, 'Ivan', 'Petrov'),
(3, 'Sergey', 'Yaroshevich'),
(4, 'Nikolay', 'Semenov'),
(5, 'Elena', 'Levkovec'),
(6, 'Petr', 'Antonov');

INSERT INTO subj_teach (ST_id, Subject_id, Teacher_id, Group_id) VALUES
(1, 1, 1, 13),
(2, 1, 1, 14),
(3, 2, 3, 15),
(4, 2, 3, 16),
(5, 3, 4, 16),
(6, 4, 2, 13);

INSERT INTO marks (Student_id, Subject_id, Date, Mark) VALUES
(1, 1, '2022-04-28', 6),
(2, 1, '2022-04-28', 7),
(3, 2, '2022-04-28', 7),
(4, 4, '2022-04-28', 6),
(5, 5, '2022-04-28', 7),
(6, 6, '2022-04-17', 8),
(1, 2, '2022-04-17', 9),
(2, 3, '2022-04-17', 3),
(1, 1, '2022-04-20', 5),
(2, 3, '2022-04-20', 8);
