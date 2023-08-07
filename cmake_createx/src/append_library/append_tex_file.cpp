#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include "append_tex_file.h"

namespace fs = std::filesystem;

void append_tex_file(std::vector<std::string> files_to_append, std::string output_path_string) {

    try {
        std::cout << "Output is: " << output_path_string << '\n';

        for (const auto& f : files_to_append) {

            // Last '/' is filename
            const size_t tmp = f.find_last_of('/');
            const std::string filename = f.substr(tmp + 1);

            std::ifstream input_file(f);
            std::ofstream output_file(output_path_string, std::ios::app); // Open in append mode

            if (input_file.is_open() && output_file.is_open()) {
                std::string line;
                while (std::getline(input_file, line)) {
                    const std::string section_header = "section{" + filename + "}";
                    const std::string verbatim_header = "begin{verbatim}";
                    const std::string verbatim_footer = "end{verbatim}";

                    output_file << "\\" << section_header << '\n';
                    output_file << '\n';
                    output_file << "\\" << verbatim_header << '\n';
                    output_file << '\n';
                    output_file << line << '\n'; // Append each line to the output file
                    output_file << '\n';
                    output_file << "\\" << verbatim_footer << '\n';
                }

                std::cout << "File: " << f << '\n';
                std::cout << "Successfully appended." << '\n';
            } else {
                std::cerr << "Failed to open files." << '\n';
            }

            input_file.close();
            output_file.close();
        }
    }
    catch (const fs::filesystem_error& unappendable_files) {
        const std::string error_message = unappendable_files.what();
        for (const char& c : error_message) {
            std::cout << c;
            if (c == ':') {
                std::cout << '\n';
            }
        }
        std::cout << '\n';

        // Files could not be open by the fstream, I think
        std::cout << "Files could not be appeneded." << '\n';
        std::cout << "Exiting program..." << '\n';
        std::exit(0);
    }
}    
