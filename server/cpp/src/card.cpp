#include "../include/card.hpp"


Card::Card(int id, std::string f, std::string b){
    pileID = id;
    front = f;
    back = b;
    face = FRONT;
}
void Card::edit_front(string s){
    front = s;
}
void Card::edit_back(std::string s){
    back = s;
}
string Card::get_front(){
    return front;
}
string Card::get_back(){
    return back;
}

int Card::get_pileID(){
    return pileID;
}