/* main.c */
/* Author: Dowletmyrat */
/* lab3_zadacha2 */

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#include "students.h"

#define TRUE 1
#define FALSE 0

int main(int argc, const char *argv[]) {
    sqlite3 *db;
    int rc = sqlite3_open("src/students.db", &db);

    (void)argc;
    (void)argv;

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    while (TRUE) {
        printf("Menu to manage the database (src/students.db):\n");
        printf("1. SELECT records\n");
        printf("2. INSERT records\n");
        printf("3. DELETE records\n");
        printf("4. Exit\n");

        int choice = 0;
        if (scanf("%d", &choice) != 1) {
            break;
        }
        int exitBool = 0;

        switch (choice) {
        case 1:
            selectRecords(db);
            break;
        case 2:
            insertNewRecord(db);
            break;
        case 3:
            deleteRecord(db);
            break;
        case 4:
            exitBool = 1;
            break;
        default:
            printf("No option which was selected\n");
        }

        if (exitBool == TRUE) {
            break;
        }
    }

    sqlite3_close(db);
    return 0;
}
