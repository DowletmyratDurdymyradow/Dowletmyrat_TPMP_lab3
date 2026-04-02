CC=gcc
CFLAGS=-Wall -Wextra -std=c11
LDFLAGS=-lsqlite3

SRC_DIR=src

all: example1 example2 example3 students

example1: $(SRC_DIR)/example1_connection.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

example2: $(SRC_DIR)/example2_create_table.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

example3: $(SRC_DIR)/example3_insert_into_table.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

students: $(SRC_DIR)/students.c $(SRC_DIR)/students.h
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/students.c $(LDFLAGS)

clean:
	rm -f example1 example2 example3 students

.PHONY: all clean
