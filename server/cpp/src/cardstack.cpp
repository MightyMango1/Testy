#include "../include/cardstack.hpp"
#include <cstdlib>
#include <ctime>

CardStack::CardStack(){
    cardAmt = 0;
}

int CardStack::get_cardAmt(){
    return cardAmt;
}

Card CardStack::topCard(){
    return cards[0];
}

Card CardStack::deleteCard(int position){
    /*Card temp;
    if(!inPile(position)){
        return temp;
    }
    temp = cards[position - 1];
    cards.erase(cards.begin() + (position - 1));
    return temp;*/
}

void CardStack::addCard(Card newCard){
    /*cards.push_back(newCard);
    cardAmt++;*/

}

void CardStack::shuffle(){
    vector<Card> shuffled;

    //generate seed
    srand(time(0));
    while(cards.size() > 0){
        //generating random card to add to shuffled pile 
        //and taking that same card out of our cards pile
        int card_pos = rand() % cards.size();
        shuffled.push_back(cards[card_pos]);
        cards.erase(cards.begin() + card_pos);
    }
    cards = shuffled;
}

void CardStack::nextCard(){
    cards.push_back(cards[0]);
    cards.erase(cards.begin());
}

void CardStack::prevCard(){
    cards.insert(cards.begin(), cards[cardAmt - 1]);
    cards.pop_back();
}


Card CardStack::pickCard(int cardNum){
    if(!inPile(cardNum)){
        Card error;
        return error;
    }
    return cards[cardNum - 1];
}

bool CardStack::inPile(int cardNum){
    if(cardNum > cardAmt || cardNum == 0){
        cout << "Error: out of bounds" << endl;
        return false;
    }
    return true;
}