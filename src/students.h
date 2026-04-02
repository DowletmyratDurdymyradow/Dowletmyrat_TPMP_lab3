/* students.h */
/* Author: Dowletmyrat */
/* lab3_zadacha2 */

#ifndef STUDENTS_H
#define STUDENTS_H

#include <sqlite3.h>

// Insert new records into an existing table
void insertNewRecord(sqlite3 *db);

// Delete records from an existing table
void deleteRecord(sqlite3 *db);

// Select records from an existing table
void selectRecords(sqlite3 *db);

#endif
