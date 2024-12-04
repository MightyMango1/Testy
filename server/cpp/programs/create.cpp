#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include "../src/card.cpp"
#include "../../database/database.cpp"

bool findID(int findID, unordered_map<int, int>& IDs);

int main(int argc, char* argv[]) {
    const char *dir = "./database/cards.db";    //database

    //create a function that pulls pile ids from Card objects in databse
    //store those ids in a umap
    //generate a random num, and if rand num is in the map, keep create rand numbers
    srand(time(0));
    int randID;

    unordered_map<int, int> pileIDs;
    pileIDs = getPileIDs(dir);

    do{
        randID = rand() % 10000;
    }while(findID(randID, pileIDs));

    for(int i = 1; i < argc ; i++){
        if((i + 1) > argc){
            std::cout << "Please provide correct parameters";
        }else{
            Card *newCard = new Card(randID, argv[i], argv[i + 1]);
            int cardID = insertData(dir, *newCard);
            i++;
        }
    }
    
    return 0;
}

bool findID(int potentialID, unordered_map<int, int>& IDs){
    return IDs.find(potentialID) != IDs.end();
}