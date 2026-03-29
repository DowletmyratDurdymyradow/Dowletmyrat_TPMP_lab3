#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *not_used, int argc, char **argv, char **az_col_name) {
    int i;

    (void)not_used;

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", az_col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *z_err_msg = 0;
    int rc;
    const char *sql;

    (void)argc;
    (void)argv;

    rc = sqlite3_open("students.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    fprintf(stdout, "Opened database successfully\n");

    sql = "CREATE TABLE IF NOT EXISTS marks(" \
          "MarkId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
          "Student_id INTEGER NOT NULL," \
          "Subject_id INTEGER NOT NULL," \
          "Date TEXT NOT NULL," \
          "Mark INTEGER NOT NULL);";

    rc = sqlite3_exec(db, sql, callback, 0, &z_err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", z_err_msg);
        sqlite3_free(z_err_msg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
    return 0;
}
