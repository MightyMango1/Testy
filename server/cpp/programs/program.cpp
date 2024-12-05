#include <iostream>
#include <sqlite3.h>
#include <stdexcept>
#include "../../database/database.hpp"


int main() {
    
    const char *dir = "./database/cards.db";
    string tableName = "FLASHCARDS";

    //if database and table do not exist, then create them
    database *db = new database(dir);

    return 0;
}