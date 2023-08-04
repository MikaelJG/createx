#include <filesystem>
#include <vector>
#include <iostream>

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
