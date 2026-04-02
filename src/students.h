#ifndef STUDENTS_H
#define STUDENTS_H

#include <sqlite3.h>

void insertNewRecord(sqlite3 *db);
void deleteRecord(sqlite3 *db);
void PrintSelect(sqlite3_stmt *res, int count);
void selectRecords(sqlite3 *db);

#endif
