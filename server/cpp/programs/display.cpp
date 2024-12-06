#include "../include/card.hpp"
#include "../../database/database.hpp"

int main(){
    const char *dir = "./database/cards.db";
    database *db = new database(dir);
    vector<string> cards;

    cards = db->displayCards();
    for(int i = 0; i < cards.size(); i += 3){
        cout << "PileID: " << cards[i] << ", ";
        cout << "front: " << cards[i + 1] << ", ";
        cout << "back: " << cards[i + 2] << endl;
    }

    return 0;
}