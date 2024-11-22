#include <iostream>
#include <string.h>
#include "card.cpp"
#include "cardstack.cpp"


int main(int argc, char* argv[]) {
    for(int i = 1; i < argc ; i++){
        if(strcmpi(argv[i], "create") == 0){
            if((i + 2) > argc){
                cout << "Please provide correct parameters";
            }else{
                Card c(0, argv[i + 1], argv[i + 2]);
                i += 2;
            }
        }
    }
    
    return 0;
}