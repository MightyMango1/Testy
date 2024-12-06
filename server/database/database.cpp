#include "database.hpp"


//constructor for creating the database just once
database::database(const char *s){
    dir = s;
    DB = nullptr;

    if(sqlite3_open(dir, &DB) == SQLITE_OK){
        if(!checkDBExists(dir)){
            createDB();
        }
        createTable();
    }else{
        cerr << "Error opening database: " << sqlite3_errmsg(DB) << endl;
    }

    sqlite3_close(DB);
}


// Create the database in SQLite. You need to open the connection with the given filename.
int database::createDB() {

    if(openDB(DB) != SQLITE_OK){
        return -1;
    }

    sqlite3_close(DB);

    return 0;
}


// Create a table for storing the data with different text fields.
// An exception is thrown if the database cannot be opened or read.
int database::createTable() {
    std::string sql = "CREATE TABLE IF NOT EXISTS FLASHCARDS("
                      "CardID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "PileID         INTEGER, "
                      "TITLE          TEXT NOT NULL, "
                      "DESCRIPTION    TEXT NOT NULL);";

    try {
        int exit = -1;
        
        if(openDB(DB) != SQLITE_OK){
            return -1;
        }

        char *messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Error Create Table" << sqlite3_errmsg(DB) << std::endl;
            sqlite3_free(messageError);
        }
        else {
            std::cout << "Table exists" << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
    }

    sqlite3_close(DB);

    return 0;
}

//checks to see if database exists or not
bool database::checkDBExists(const char *dir){
    int exit = sqlite3_open_v2(dir, &DB, SQLITE_OPEN_READONLY, NULL);

    if (exit == SQLITE_OK) {
        sqlite3_close(DB);
        return true;  // Database exists and is accessible
    } else {
        return false;  // Database doesn't exist or is not accessible
    }
}

//checks if database table exists or not
bool database::checkTableExists(sqlite3 *DB, const string &tableName){
    sqlite3_stmt *stmt;
    bool tableExists = false;

    string sql = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + tableName + "';";

    if(sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK){
        if(sqlite3_step(stmt) == SQLITE_ROW){
            tableExists = true;
        }
        sqlite3_finalize(stmt);
    }

    return tableExists;
}

int database::openDB(sqlite3 *&DB) {
    int exit = sqlite3_open(dir, &DB);
    if (exit != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(DB) << std::endl;
    }
    return exit;
}

// Delete entry from table
int database::deleteData(int cardID) {

    if(openDB(DB) != SQLITE_OK){
        return -1;
    }

    std::string sql = "DELETE FROM FLASHCARDS;";
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

    return 0;
}

int database::insertCard(Card *card) {
    char *messageError;
    int cardID = -1;
    int exit = -1;

    if (openDB(DB) != SQLITE_OK) {
        return -1;
    }

    // Use placeholders for parameters
    std::string sql = "INSERT INTO FLASHCARDS (PileID, TITLE, DESCRIPTION) VALUES(?, ?, ?);";
    
    sqlite3_stmt *stmt;
    
    exit = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);
    if (exit != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(DB) << std::endl;
        return -1;
    }

    // Bind the parameters
    sqlite3_bind_int(stmt, 1, card->get_pileID());  // PileID
    sqlite3_bind_text(stmt, 2, card->get_front().c_str(), -1, SQLITE_STATIC);  // TITLE
    sqlite3_bind_text(stmt, 3, card->get_back().c_str(), -1, SQLITE_STATIC);   // DESCRIPTION

    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return -1;
    }

    std::cout << "Record created successfully!" << std::endl;

    // Get the last inserted ID
    cardID = getLastInsertedCardID(DB);

    sqlite3_finalize(stmt);
    sqlite3_close(DB);

    return cardID;
}


int database::updateData(Card modCard) {
    char *messageError;
    int exit = -1;

    if(openDB(DB) != SQLITE_OK){
        return -1;
    }

    std::string sql("UPDATE FLASHCARDS SET TITLE  = 'Placeholder' WHERE DESCRIPTION = 'Sorting algorithm that steps"
                    "through the data element by element, swapping if needed'");

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
int database::selectData() {
    if(openDB(DB) != SQLITE_OK){
        return -1;
    }

    std::string sql = " SELECT * FROM FLASHCARDS;";

    // With open database, this is the first argument to the callback function -- evaluates SQL statement
    char *errorMessage = nullptr;
    int exit = sqlite3_exec(DB, sql.c_str(), callback, nullptr, &errorMessage);
    if (exit != SQLITE_OK) {
        std::cerr << "Error selecting data: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return -1;
    }

    sqlite3_close(DB);
    return 0;
}

//searches along the database and retrieves all the pileIDs in a umap
unordered_map<int, int> database::getPileIDs(){
    unordered_map<int, int> pileIDs;
    sqlite3_stmt *stmt;

    if(openDB(DB) != SQLITE_OK){
        return pileIDs;
    }

    string sql = "SELECT PileID FROM FLASHCARDS;";

    if(sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK){
        while(sqlite3_step(stmt) == SQLITE_ROW){
            int pile = sqlite3_column_int(stmt, 0);
            pileIDs[pile]++;
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(DB);
    return pileIDs;
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

//returns the unique cardID of recently inserted Card object
int database::getLastInsertedCardID(sqlite3 *&db){
    sqlite3_stmt *stmt;
    int cardID;

    string sql("SELECT LAST_INSERT_ROWID()");

    if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK){
        if(sqlite3_step(stmt) == SQLITE_ROW){
            cardID = sqlite3_column_int(stmt, 0); //returns the CardID value in the last row, column 0
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);

    return cardID;
}

//returns a vector of Cards from the database
vector<string> database::displayCards(){
    sqlite3_stmt *stmt;
    vector<string> arguments;

    if(openDB(DB) != SQLITE_OK){
        return arguments;
    }

    string sql = "SELECT PileID, TITLE, DESCRIPTION " 
                 "FROM FLASHCARDS "
                 "ORDER BY CardID;";

    if(sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK){
        while(sqlite3_step(stmt) == SQLITE_ROW){

            int pileID = sqlite3_column_int(stmt, 0);
            const unsigned char *frontText = sqlite3_column_text(stmt, 1);
            const unsigned char *backText = sqlite3_column_text(stmt, 2);

            //convert to string
            string front = frontText ? reinterpret_cast<const char*>(frontText) : "";
            string back = backText ? reinterpret_cast<const char*>(backText) : "";

            arguments.push_back(to_string(pileID));
            arguments.push_back(front);
            arguments.push_back(back);
        }
        sqlite3_finalize(stmt);
    } else{
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(DB) << endl;
    }

    sqlite3_close(DB);

    return arguments;
}