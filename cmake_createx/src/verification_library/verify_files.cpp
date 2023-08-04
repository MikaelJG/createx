#include <iostream>
#include <filesystem>
#include <vector>

#include "verify_files.h"

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
