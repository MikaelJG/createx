#include <iostream>
#include <filesystem>

#include "verify_tex_file.h"

namespace fs = std::filesystem;



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
