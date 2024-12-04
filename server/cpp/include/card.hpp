#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>

using namespace std;

enum Side {
    FRONT,
    BACK
};

class Card{
    private:
        string front;
        string back;
        Side face;
        int ID; //matches the same id of that of a cardStack
    public:
        Card();
        Card(int ID, string f, string b);
        void edit_front(string s);
        void edit_back(string s);
        string get_front();
        string get_back();
        int get_id();
        void flip();
};


#endif