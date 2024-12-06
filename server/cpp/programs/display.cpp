#include <iostream>
#include <string>
#include "../include/card.hpp"
#include "../../database/database.hpp"

int main(){
    const char *dir = "./database/cards.db";
    database *db = new database(dir);
    vector<string> cards;
    string outputString;

    cards = db->displayCards();
    for(int i = 0; i < cards.size(); ++i){
        outputString += cards[i];
        outputString += " ";
    }

    std::cout << outputString;
    return 0;
}