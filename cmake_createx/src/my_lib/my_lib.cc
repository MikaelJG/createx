#include <iostream>
#include <vector>

#include "my_lib.h"

void print_hello_world()
{
    std::cout << "Hello World!\n";
} 

void recursively_search_files(const std::string& dir, const std::string& wanted_ext)
{
    std::cout << "Hello from recursively_search_function!\n";
}

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

void verify_file_quantity(std::vector<std::string> found_files) {

    // the program needs at least one file
    // the quantity of file might surprise the user
    
    const int number_of_files = found_files.size();  

    if (number_of_files < 1) {
        std::cout << "No files were found. Nothing to extract." << '\n';
        std::cout << "Exiting program..." << '\n';
        std::exit(0);
    } else {
        std::cout << number_of_files << " were found." << '\n';

        std::cout << "Execute program? [Y/n] :" << '\n';
        std::string a;
        std::cin >> a;

        if ( a == "y" || a == "Y" || a == "Yes" || a == "yes" ) {
            std::cout << "Executing Program.";
        } else {
            std::cout << "Creation aborted.";
            std::cout << "Exiting program.";
            std::exit(0);
        }
    }
}
