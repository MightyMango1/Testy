#pragma once
#include <iostream>
#include <sqlite3.h>
#include <stdexcept>
#include "../cpp/src/card.cpp"
#include "../cpp/src/cardstack.cpp"

struct database {
    static int createDB(const char *s);
    static int createTable(const char *s);
    static int deleteData(const char *s, Card *card);
    static int insertData(const char *s, Card *card);
    static int updateData(const char *s, Card *oldCard, Card *newCard);
    static int selectData(const char *s, Card *card);
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
};