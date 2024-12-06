#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include "../include/card.hpp"
#include "../../database/database.hpp"

bool findID(int findID, unordered_map<int, int> &IDs);
int generateID(unordered_map<int, int> &IDs);

int main(int argc, char *argv[])
{
    const char *dir = "./database/cards.db"; // database
    string tableName = "FLASHCARDS";
    database *db = new database(dir);
    unordered_map<int, int> pileIDs; // umap to store IDs

    // create a function that pulls pile ids from Card objects in databse
    // store those ids in a umap
    // generate a random num, and if rand num is in the map, keep create rand numberS
    pileIDs = db->getPileIDs();
    int newPileID = generateID(pileIDs);

    for (int i = 1; i < argc; i++)
    {
        if ((i + 1) > argc)
        {
            std::cout << "Please provide correct parameters";
        }
        else
        {
            Card *newCard = new Card(newPileID, argv[i], argv[i + 1]);

            cout << newCard->get_front() << " " << newCard->get_back() << " " << newCard->get_pileID() << endl;

            db->insertData(newCard);
            i++;
        }
    }
    db->selectData();
    
    return 0;
}

int generateID(unordered_map<int, int> &IDs)
{
    srand(time(0));
    int randID;
    do
    {
        randID = rand() % 10000;
    } while (findID(randID, IDs));
    return randID;
}

bool findID(int potentialID, unordered_map<int, int> &IDs)
{
    return IDs.find(potentialID) != IDs.end();
}
