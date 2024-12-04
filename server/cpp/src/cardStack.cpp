#include "../include/cardstack.hpp"
#include <cstdlib>
#include <ctime>
CardStack::CardStack(){
    
}
int CardStack::get_cardAmt(){
    return cards.size();
}
void CardStack::editName(string n){
    name = n;
}
string CardStack::getName(){
    return name;
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
    cards.insert(cards.begin(), cards[cards.size() - 1]);
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
    if(cardNum > cards.size() || cardNum == 0){
        cout << "Error: out of bounds" << endl;
        return false;
    }
    return true;
}