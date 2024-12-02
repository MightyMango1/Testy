#pragma once
#include <iostream>
#include <sqlite3.h>
#include <stdexcept>
//#include <umap>

struct database {
    static int createDB(const char *s);
    static int createTable(const char *s);
    static int deleteData(const char *s);
    static int getLastInsertedCardID(sqlite3 *db);
    static int insertData(const char *s);
    static int updateData(const char *s);
    static int selectData(const char *s);
    //static unordered_map<int> getPileIDs(const char *s);
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);

};