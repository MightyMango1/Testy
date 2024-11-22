#include "../include/card.hpp"

Card::Card(int id, string f, string b){
    ID = id;
    front = f;
    back = b;
    face = FRONT;
}

void Card::edit_front(string s){
    //save for later
}

void Card::edit_back(string s){
    //save for later
}

string Card::get_front(){
    return front;
}

string Card::get_back(){
    return back;
}

void Card::flip(){
    if(face == FRONT){
        face == BACK;
    }else{
        face == FRONT;
    }
}