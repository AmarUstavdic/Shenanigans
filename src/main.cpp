#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Incorrect usage. Correct usage is.." << std::endl;
        std::cerr << "sng <input.sn>" << std::endl;
        return 1;
    }
    
    std::string contents;
    {
        std::ifstream input(argv[1]);
        if (!input.is_open()) {
            std::cerr << "Failed to open file: " << argv[1] << std::endl;
            return 1;
        }
        std::stringstream contents_stream;
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }
    

    std::cout << contents << std::endl;

    return 0;
}
