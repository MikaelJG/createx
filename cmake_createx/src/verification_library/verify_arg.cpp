#include <iostream>
#include <filesystem>
#include <vector>

#include "verify_arg.h"

void verify_arg_quantity(std::vector<std::string> arguments) {

    // the program needs two arguments
    // the wanted extension, first
    // the wanted directory, second
    
    const int arguments_len = arguments.size();  

    if (arguments_len < 2) {
        std::cout << "Please provide at least two arguments." << '\n';
        std::cout << "Exiting program..." << '\n';
        std::exit(0);
    } else if (arguments_len > 2) {
        std::cout << "Please provide only two arguments." << '\n';
        std::cout << "Exiting program..." << '\n';
        std::exit(0);
    } else {
        std::cout << "Two arguments provided." << '\n';
        std::cout << "Executing..." << '\n';
    }
}
