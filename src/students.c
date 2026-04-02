/* students.c */
/* Author: Dowletmyrat */
/* lab3_zadacha2 */

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "students.h"

#define TRUE 1

static void run_sql(sqlite3 *db, const char *sql) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void insertNewRecord(sqlite3 *db) {
    char err_msg_dummy = 0;
    char sql[1000] = "INSERT INTO ";
    char str[100];
    int choice = 0;

    (void)err_msg_dummy;

    printf("1. Insers values to the students table\n");
    printf("2. Insert values to the subjects table\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        strcat(sql, "students(FirstName,LastName,Group_id,height,weight,age) VALUES('");
        printf("Enter FirstName\n");
        scanf("%99s", str);
        strcat(sql, str);
        strcat(sql, "', '");

        printf("Enter last name\n");
        scanf("%99s", str);
        strcat(sql, str);
        strcat(sql, "', ");

        printf("Enter group number\n");
        scanf("%99s", str);
        strcat(sql, str);
        strcat(sql, ", ");

        printf("Enter height\n");
        scanf("%99s", str);
        strcat(sql, str);
        strcat(sql, ", ");

        printf("Enter weight\n");
        scanf("%99s", str);
        strcat(sql, str);
        strcat(sql, ", ");

        printf("Enter age\n");
        scanf("%99s", str);
        strcat(sql, str);
        strcat(sql, ");");
        break;

    case 2:
        strcat(sql, "subjects(Title) VALUES('");
        printf("Enter subject name\n");
        scanf("%99s", str);
        strcat(sql, str);
        strcat(sql, "');");
        break;

    default:
        printf("No option selected\n");
        return;
    }

    run_sql(db, sql);
}

void deleteRecord(sqlite3 *db) {
    char sql[1000] = "DELETE from ";
    char str[100];
    int choice = 0;
    int option = 0;

    printf("1. Delete values from the students table\n");
    printf("2. Delete values from the marks table\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        strcat(sql, "students where ");
        printf("1. Delete by id\n");
        printf("2. Delete by Last Name\n");
        scanf("%d", &option);
        if (option == 1) {
            printf("Enter id\n");
            scanf("%99s", str);
            strcat(sql, "Student_id=");
            strcat(sql, str);
        } else if (option == 2) {
            printf("Enter Last Name\n");
            scanf("%99s", str);
            strcat(sql, "LastName='");
            strcat(sql, str);
            strcat(sql, "'");
        }
        strcat(sql, ";");
        break;

    case 2:
        strcat(sql, "marks where ");
        printf("1. Delete by Student id\n");
        printf("2. Delete by Subject id\n");
        scanf("%d", &option);
        if (option == 1) {
            printf("Enter Student id\n");
            scanf("%99s", str);
            strcat(sql, "Student_id=");
            strcat(sql, str);
        } else if (option == 2) {
            printf("Enter Subject Id\n");
            scanf("%99s", str);
            strcat(sql, "Subject_id=");
            strcat(sql, str);
        }
        strcat(sql, ";");
        break;

    default:
        printf("No option selected\n");
        return;
    }

    run_sql(db, sql);
}

void PrintSelect(sqlite3_stmt *res, int count) {
    while (TRUE) {
        int step = sqlite3_step(res);
        if (step == SQLITE_ROW) {
            for (int i = 0; i < count; i++) {
                const unsigned char *txt = sqlite3_column_text(res, i);
                printf("%s ", txt ? (const char *)txt : "NULL");
            }
            printf("\n");
        } else {
            break;
        }
    }
}

void selectRecords(sqlite3 *db) {
    sqlite3_stmt *res;
    char sql[1000] = "SELECT * from ";
    char str[100] = {0};
    int choice = 0;
    int option = 0;
    int rc = 0;

    printf("1. Select values from the students table\n");
    printf("2. Select values from the subjects table\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        strcat(sql, "students");
        printf("1. Select all table\n");
        printf("2. Select records by id\n");
        printf("3. Select records by last name\n");
        scanf("%d", &option);

        if (option == 2) {
            printf("Enter Student id\n");
            scanf("%99s", str);
            strcat(sql, " where Student_id = @id");
        } else if (option == 3) {
            printf("Enter last name\n");
            scanf("%99s", str);
            strcat(sql, " where LastName like @lname");
        }

        rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
        if (rc == SQLITE_OK) {
            if (option == 2) {
                int idx = sqlite3_bind_parameter_index(res, "@id");
                int value = atoi(str);
                sqlite3_bind_int(res, idx, value);
            } else if (option == 3) {
                int idx = sqlite3_bind_parameter_index(res, "@lname");
                sqlite3_bind_text(res, idx, str, -1, SQLITE_TRANSIENT);
            }
            PrintSelect(res, 7);
            sqlite3_finalize(res);
        } else {
            fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        }
        break;

    case 2:
        strcat(sql, "subjects");
        printf("1. Select all table\n");
        scanf("%d", &option);
        rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
        if (rc == SQLITE_OK) {
            PrintSelect(res, 2);
            sqlite3_finalize(res);
        } else {
            fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        }
        break;

    default:
        printf("No option selected\n");
        break;
    }
}

int main(void) {
    sqlite3 *db;
    int rc;
    int action = -1;

    rc = sqlite3_open("src/students.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    printf("Opened database successfully\n");

    while (action != 0) {
        printf("\nMenu:\n");
        printf("1 - INSERT\n");
        printf("2 - DELETE\n");
        printf("3 - SELECT\n");
        printf("0 - EXIT\n");
        scanf("%d", &action);

        switch (action) {
        case 1:
            insertNewRecord(db);
            break;
        case 2:
            deleteRecord(db);
            break;
        case 3:
            selectRecords(db);
            break;
        case 0:
            break;
        default:
            printf("Unknown option\n");
            break;
        }
    }

    sqlite3_close(db);
    return 0;
}
