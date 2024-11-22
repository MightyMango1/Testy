#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <activaut.idl>
#include "card.cpp"
#include "cardstack.cpp"

bool findID(int findID);


int main(int argc, char* argv[]) {
    //create a function that pulls ids from Card objects in databse
    //store those ids in a umap
    //generate a random num, and if rand num is in the map, keep create rand numbers
    srand(time(0));
    int randID = 0;
    while(findID(randID)){
        //returns false, means this is a unique ID
    }
    for(int i = 1; i < argc ; i++){
        if((i + 1) > argc){
            std::cout << "Please provide correct parameters";
        }else{
            Card c(randID, argv[i], argv[i + 1]);
            i++;
        }
    }
    
    return 0;
}

bool randID(int potentialID){
    return false;
}