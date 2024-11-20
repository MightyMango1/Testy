#ifndef CARDSTACK_HPP
#define CARDSTACK_HPP
#include "card.hpp"
#include <vector>

class CardStack{
    private:
        int cardAmt;
        int ID; //
        vector<Card> cards;

        //helper funcs
        bool inPile(int cardNum);
    public:
        int get_cardAmt();
        Card topCard();

        Card deleteCard(int cardNum);
        void addCard(Card newCard);
        void shuffle(); //shuffles cards in random order
        void nextCard();
        void prevCard();
        Card pickCard(int index);   //returns any card from the pile to allow you to edit it
};

#endif