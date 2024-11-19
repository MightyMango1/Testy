#include "Card.h"
using std::string;
using namespace std;


Card::Card()
    : front(""),
      back("")
{
}


string Card::getDef(){// edge cases?
    return back;
}

string Card::getTopic(){// edge cases?
    return front;
}

string Card::setDef(string definition){
    this->back = definition;
}

string Card::setTopic(string vocab){
    this->front = vocab;
}

