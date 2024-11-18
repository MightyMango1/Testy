#pragma once
#include <string>
#include <iostream>
using std::string;

enum Side{
    Back,
    Front
};

class Card {
    
private:


public:
    enum Side face;
    string front;
    string back;

    Card();
    string getDef();
    string getTopic();
    string setDef(string);
    string setTopic(string);
};

