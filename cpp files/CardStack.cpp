#include "CardStack.h"
#include <vector>
#include <random>
#include <algorithm>

int CardStack::cardAmt(){
    if(CardAmount <= 0) throw runtime_error("empty card set");
    return CardAmount;
}

Card* CardStack::topCard(){
    return Cards.front();
}

void CardStack::DeleteCard(int index){
    Cards.erase(Cards.begin() + index);
}

void CardStack::addCard(Card* newCard){
    string topic;
    string definition;
    cout << "Enter the topic of the card: ";
    cin>> topic;
    cout << endl;
    cout << "Enter the definition of the topic: ";
    cin >> definition;
    cout << endl;

    newCard->front = topic;
    newCard->back = definition;
    
    Cards.push_back(newCard);
}

void CardStack::shuffle(){
    random_shuffle(Cards.begin(), Cards.end()); //not sure this works
}

string showFace(){
    //I need the curr index
}

Card* CardStack::nextCard(){
    cout << "FIX ME" << endl;
}

Card* CardStack::prevCard(){
    cout << "FIX ME" << endl;
}

void CardStack::editCard(){
    string input;
    int index = 0;
    cout << "which one you want to edit?";
    cin >> index;
    cout << "Which side you want to edit?";
    while(cin >> input) {
        for (auto& x : input) {//convert the input into lower case
            x = tolower(x); 
        }

        if(input == "front"){//user want to edit front of the card
            string newTopic;
            cout << "Enter new name of the Topic: ";
            cin >> newTopic;
            cout << endl;
            Cards[index]->front = newTopic;
            break;
        }else if(input == "back"){//user want to edit back side of the card
            string newDefinition;
            cout << "Enter new definitions: ";
            cin >> newDefinition;
            cout << endl;
            Cards[index]->back = newDefinition;
            break;
        }else{//invalid input
            cout << "wrong input, please enter front or back" << endl;
        }
    }
}

void CardStack::showAllCards(){
    for(unsigned int i = 0; i < Cards.size(); ++i){
        cout << Cards[i]->front << ": " << Cards[i]->back << endl;
    }
}
