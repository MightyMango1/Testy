#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <sqlite3.h>
#include <stdexcept>
#include <filesystem>
#include <unordered_map>
#include "../cpp/include/card.hpp"

struct database {
    static int openDB(const char *s, sqlite3 *&DB);
    static int createDB(const char *s);
    static int createTable(const char *s);
    static bool checkDBExists(const char *dir);
    static bool checkTableExists(sqlite3 *DB, const string &tableName);

    static int deleteData(const char *s, int cardID);
    static int insertData(const char *s, Card card);
    static int updateData(const char *s);

    static int selectData(const char *s);
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
    static unordered_map<int, int> getPileIDs(const char *s);
    static int getLastInsertedCardID(sqlite3 *db);
    
};

#endif