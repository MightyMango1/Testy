#include <iostream>
#include <sqlite3.h>
#include <stdexcept>
#include "../../database/database.cpp"


int main(int argc, char* argv[]) {
    
    const char *dir = "./database/cards.db";
    sqlite3 *DB;
    string tableName = "FLASHCARDS";

    //if database and table do not exist, then create them
    if(!checkDBExists(dir)){
        if(!checkTableExists(DB, tableName)){
            createDB(dir);
            createTable(dir);
        }
    }

    return 0;
}