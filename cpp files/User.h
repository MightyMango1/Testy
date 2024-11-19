#pragma once;
#include "CardStack.h"
struct User{
    vector<string> pileNames;
    vector<CardStack> Piles;
    string userName;
    string PassWord;
//function
    void TakeTest(CardStack);
    void mergePiles(CardStack, CardStack);
    void moveCard(CardStack, CardStack, Card); //not sure how this work
    
};
