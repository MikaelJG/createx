#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm> // for std::find
#include <vector>
#include <thread>
#include <chrono>

namespace fs = std::filesystem;

std::vector<std::string> files_for_tex_file;

void recursively_search_files(const std::string& dir, const std::string& wanted_ext) {

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
                recursively_search_files(file, wanted_ext);
                std::cout << "dir found\n";
            } 
        }
    }
    catch (const std::filesystem::filesystem_error& unfindable_dir) {
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

void verify_tex_file(fs::path output_file) {

    // the output file might me misplaced
    
    if (fs::is_regular_file(output_file)) {
        std::cout << "Output file created." << '\n';
        std::cout << '\n';
    } else {
        std::cout << "Failed to create output file." << '\n';
        std::cout << "Exiting program..." << '\n';
        std::exit(0);
    } 
}

void append_files_found(std::vector<std::string> files_to_append, std::string output_path_string) {

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

int main(int argc, char* argv[]) {

    // user gives wanted extension
    // and wanted directory
    const std::vector<std::string> arguments(argv + 1, argv + argc);

    // we do not know given arguments
    verify_arg_quantity(arguments);

    // wanted directory must be in current directory
    const fs::path current_dir = fs::current_path();
    const std::string current_dir_string = current_dir.string();

    // extension is first argument
    const std::string wanted_ext = arguments[0];
    const std::string wanted_dir = current_dir_string + "/" + arguments[1];

    // User verification of arguments
    std::cout << "Wanted extension is: " << wanted_ext << '\n';
    std::cout << "Wanted directory is: " << wanted_dir << '\n';


    recursively_search_files(wanted_dir, wanted_ext);

    // we don't know how many files were found
    verify_file_quantity(files_for_tex_file);

    fs::create_directories("new_tex");
    std::ofstream output_file("new_tex/output.tex");
    
    const fs::path new_tex_path = current_dir_string + "/" + "new_tex/" + "output.tex" ;
    const std::string new_tex_path_string = new_tex_path.string();

    // we don't know if the output file was found
    verify_tex_file(new_tex_path_string);

    // Sleep for 5 seconds (5000 milliseconds)
    const auto sleep_time = std::chrono::milliseconds(5000);
    std::this_thread::sleep_for(sleep_time);    

    // append might be impossible
    append_files_found(files_for_tex_file, new_tex_path);


    return 0;
}

