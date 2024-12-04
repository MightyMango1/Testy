#include "../include/card.hpp"
Card::Card(int ID, std::string f, std::string b){
    this->ID = ID;
    front = f;
    back = b;
    face = FRONT;
}
void Card::edit_front(string s){
    //save for later
}
void Card::edit_back(std::string s){
    //save for later
}
string Card::get_front(){
    return front;
}
string Card::get_back(){
    return back;
}

int Card::get_id(){
    return ID;
}
void Card::flip(){
    if(face == FRONT){
        face == BACK;
    }else{
        face == FRONT;
    }
}