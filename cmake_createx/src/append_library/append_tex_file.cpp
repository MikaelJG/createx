#include <iostream>
// #include <filesystem>
// #include <fstream>
#include <vector>
#include "append_tex_file.h"

// namespace fs = std::filesystem;

void append_tex_file(std::vector<std::string> files_to_append, std::string output_path_string) {

    std::cout << "Output is: " << output_path_string << '\n';

    for (const auto& f : files_to_append) {
        std::cout << "f is: " << f << '\n';
        
        // std::ifstream input_file("file_1.txt");
        // std::ofstream output_file("file.tex", std::ios::app); // Open in append mode

        // if (input_file.is_open() && output_file.is_open()) {
        //     std::string line;
        //     while (std::getline(input_file, line)) {
        //         output_file << line << '\n'; // Append each line to the output file
        //     }

        //     std::cout << "File contents successfully appended." << std::endl;
        // } else {
        //     std::cerr << "Failed to open files." << std::endl;
        // }

        // input_file.close();
        // output_file.close();

    }
}    
