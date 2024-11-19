#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) { 
        std::cout << "No input provided";
        return 1;
    }
    std::string frontendInput = argv[1];
    std::cout << "Received input: " << frontendInput << " " << argv[2] << " " << argv[3] << std::endl;
    return 0;
}