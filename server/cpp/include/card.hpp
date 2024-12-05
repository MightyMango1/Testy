#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>

using namespace std;

class database;

enum Side {
    FRONT,
    BACK
};

class Card{
    private:
        string front;
        string back;
        Side face;
        int pileID; //matches the same id of that of a cardStack
    public:
        Card();
        Card(int pileID, string f, string b);
        
        void edit_front(string s);
        void edit_back(string s);

        int get_pileID();
        string get_front();
        string get_back();
        Side get_face();
};


#endif