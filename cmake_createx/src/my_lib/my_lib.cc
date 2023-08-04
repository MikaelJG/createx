#include <iostream>
#include <filesystem>
#include <vector>

#include "my_lib.h"

namespace fs = std::filesystem;

void recursively_search_files(const std::string& dir, const std::string& wanted_ext, std::vector<std::string> files_for_tex_file)
{
    try {
        for (const auto& entry : fs::directory_iterator(dir)) {
            const std::string& file = entry.path().string();
            const std::string& file_extension = file.substr(file.size() - wanted_ext.size());

            if (fs::is_regular_file(entry) && file_extension == wanted_ext) {
                // If the file is a .tex file, add it to the vector
                files_for_tex_file.push_back(file);
                std::cout << "file found\n";

            } else if (fs::is_directory(entry)) {
                // If the entry is a directory, recursively call the function
                recursively_search_files(file, wanted_ext, files_for_tex_file);
                std::cout << "dir found\n";
            } 
        }
    }
    catch (const fs::filesystem_error& unfindable_dir) {
        const std::string error_message = unfindable_dir.what();
        for (const char& c : error_message) {
            std::cout << c;
            if (c == ':') {
                std::cout << '\n'; // Print newline after each space character
            }
        }
        std::cout << '\n';

        // Filesystem crashed when searching wanted dir
        std::cout << "Neither files or directory were found." << '\n';
        std::cout << "Exiting program..." << '\n';
        std::exit(0);
    }
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
