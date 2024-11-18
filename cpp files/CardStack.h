#pragma once
#include "Card.h"
#include <vector>
using namespace std;

class CardStack{
    private:
        Card* card;
        int CardAmount;
        vector<Card*> Cards;

    public:
        int cardAmt();
        Card* topCard();
        void DeleteCard(int);
        void addCard(Card*);
        void shuffle();
        string showFace();
        Card* nextCard();
        Card* prevCard();
        void editCard();
        void showAllCards();

};