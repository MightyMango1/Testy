#include "database.h"


// Create the database in SQLite. You need to open the connection with the given filename.
int database::createDB(const char *s) {
    sqlite3 *DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);

    sqlite3_close(DB);

    return 0;
}

// Create a table for storing the data with different text fields.
// An exception is thrown if the database cannot be opened or read.
int database::createTable(const char *s) {
    sqlite3 *DB;

    std::string sql = "CREATE TABLE IF NOT EXISTS FLASHCARDS("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "TITLE          TEXT NOT NULL, "
                      "DESCRIPTION    TEXT NOT NULL );";

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

// Delete entry from table
int database::deleteData(const char *s, Card *card) {
    sqlite3 *DB;
    
    int exit = sqlite3_open(s, &DB);

    std::string sql = "DELETE FROM FLASHCARDS;";
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
// not sure how this work currently
    return 0;
}

// The database is initially populated with one line of data.
int database::insertData(const char *s, Card *card) {
    sqlite3 *DB;
    char *messageError;
    string title = card->get_front();
    string def = card->get_back();

    int exit = sqlite3_open(s, &DB);
    
    std::string sql("INSERT INTO FLASHCARDS (TITLE, DESCRIPTION) VALUES('"+title+"', '"+def+"');");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messageError);
    }
    else {
        std::cout << "Records created successfully!" << std::endl;
    }

    return 0;
}

int database::updateData(const char *s, Card *oldCard, Card *newCard) {
    sqlite3 *DB;
    char *messageError;
    string oldTitle = oldCard->get_front();
    string oldDef = oldCard->get_back();
    string newTitle = newCard->get_front();
    string newDef = newCard->get_back();
    std::string sql;

    
    int exit = sqlite3_open(s, &DB);
    if(oldTitle == newTitle){//only change the definition
        sql = ("UPDATE FLASHCARDS SET DESCRIPTION  - '"+newDef+"' WHERE TITLE - '"+newTitle+"'");
    }else if (oldDef == newDef){//only change the title
        sql = ("UPDATE FLASHCARDS SET TITLE  - '"+newTitle+"' WHERE DESCRIPTION - '"+oldDef+"'");
    }else {//change everything
        sql = ("UPDATE FLASHCARDS SET DESCRIPTION  - '"+newDef+"' WHERE TITLE - '"+oldTitle+"'"
        "UPDATE FLASHCARDS SET TITLE  - '"+newTitle+"' WHERE DESCRIPTION - '"+newDef+"'");
    }
 

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messageError);
    }
    else {
        std::cout << "Records created successfully!" << std::endl;
    }

    return 0;
}

// Selects everything in the FLASHCARDS database with a wildcard operator
int database::selectData(const char *s, Card *card) {
    sqlite3 *DB;

    int exit = sqlite3_open(s, &DB);

    std::string sql = " SELECT * FROM FLASHCARDS;";

    // With open database, this is the first argument to the callback function -- evaluates SQL statement
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    return 0;
}

// The callback function is used to retrieve the contents of the database used by selectData().
// argc: holds the number of results
// **argv: holds each value in array
// **azColName: holds each column returned in array
int database::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; ++i) {
        std::cout << azColName[i] << ": " << argv[i] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}