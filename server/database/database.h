#pragma once
#include <iostream>
#include <sqlite3.h>
#include <stdexcept>

struct database {
    static int createDB(const char *s);
    static int createTable(const char *s);
    static int deleteData(const char *s);
    static int insertData(const char *s);
    static int updateData(const char *s);
    static int selectData(const char *s);
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);

};