#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "../cpp/include/card.hpp"
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <stdexcept>
#include <unordered_map>

class database {
private:
    const char* dir;    //this will be the directory where the db will be stored in our workspace
    sqlite3 *DB;    //database variable that we will use for all functions
public:
    database(const char *s);

    int openDB(sqlite3 *&DB);
    int createDB();
    int createTable();
    bool checkDBExists(const char *dir);
    bool checkTableExists(sqlite3 *DB, const string &tableName);

    int deleteData(int cardID);
    int insertData(Card *card);
    int updateData(Card modCard);

    int selectData();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    unordered_map<int, int> getPileIDs();
    int getLastInsertedCardID(sqlite3 *&db);
};

#endif