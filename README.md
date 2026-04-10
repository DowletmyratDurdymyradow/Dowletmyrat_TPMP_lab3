https://docs.google.com/document/d/117Zcm2XPrDEA48-4c6bkTefMqr5Z2g6z/edit?usp=drive_link&ouid=107887052123702597022&rtpof=true&sd=true
# Overview

Source C project with structures.

# Usage

Use `make` to build project.

# Building

Use follow command:

```bash
make
```

Run app:

```bash
make run
Source C project with examples for SQLite database usage.

# Usage

Use `gcc` and `sqlite3` to build and run examples.

# Building

```bash
gcc -o {binary_file} {c_source_file}.c -l sqlite3
```

# Database initialization

Create local database from SQL script:
Create a local database from SQL script (do not commit binary DB files):

```bash
cd src
sqlite3 students.db < init_students.sql
cd ..
```

Then run examples:

```bash
gcc -o example1 example1_connection.c -l sqlite3
./example1
gcc -o example2 example2_create_table.c -l sqlite3
./example2
gcc -o example3 example3_insert_into_table.c -l sqlite3
./example3
```

# Additional Notes

The repository with `C` source files and Makefile.
The repository contains C source files and SQL initialization script.

# Author

Dowletmyrat

# Отчет по лабораторной работе 3

Публичная ссылка на отчет: TODO
