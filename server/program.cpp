#include <iostream>
#include <sqlite3.h>
#include <stdexcept>

static int createDB(const char *s);
static int createTable(const char *s);
static int insertData(const char *s);
static int selectData(const char *s);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);

int main() {
    const char *dir = "./database/cards.db";
    sqlite3 *DB;

    createDB(dir);
    createTable(dir);

    std::cout << "Program Executed Successfully\n";
    return 0;
}

// Create the database in SQLite. You need to open the connection with the given filename.
static int createDB(const char *s) {
    sqlite3 *DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);

    sqlite3_close(DB);

    return 0;
}

// Create a table for storing the data with different text fields.
// An exception is thrown if the database cannot be opened or read.
static int createTable(const char *s) {
    sqlite3 *DB;

    std::string sql = "CREATE TABLE IF NOT EXISTS FLASHCARDS("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "TITLE          TEXT NOT NULL, "
                      "DESCRIPTION    TEXT NOT NULL );";
    // "AGE           INT  NOT NULL, "
    // "ADDRESS       CHAR(50), "
    // "GRADE         CHAR(1) );";

    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        char *messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Error Create Table" << std::endl;
            sqlite3_free(messageError);
        }
        else {
            std::cout << "Table created successfully" << std::endl;
        }
        sqlite3_close(DB);
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
    }

    return 0;
}

// The database is initially populated with one line of data.
static int insertData(const char* s) {
    sqlite3 *DB;
    char *messageError;

    int exit = sqlite3_open(s, &DB);

    std::string sql("INSERT INTO FLASHCARDS (TITLE, DESCRIPTION) VALUES('Bubblesort', 'Sorting algorithm that steps"
                    "through the data element by element, swapping if needed');");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messageError)
    }
    else {
        std::cout << "Records created successfully!" << std::endl;
    }

    return 0;
}

// Selects everything in the FLASHCARDS database with a wildcard operator
static int selectData(const char *s) {
    sqlite3 *DB;

    int exit = sqlite3_open(s, &DB);

    std::string sql = " SELECT * FROM FLASHCARDS;";

    // With open database, this is the first argument to the callback function -- evaluates SQL statement
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
}

// The callback function is used to retrieve the contents of the database used by selectData().
// argc: holds the number of results
// **argv: holds each value in array
// **azColName: holds each column returned in array
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; ++i) {
        std::cout << azColName[i] << ": " << argv[i] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
