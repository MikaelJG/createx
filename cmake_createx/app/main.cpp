#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

#include "verify_arg.h"
#include "verify_files.h" 
#include "verify_tex_file.h" 
#include "search_library.h"

namespace fs = std::filesystem;


int main(int argc, char* argv[])
{
    // user gives wanted extension
    // and wanted directory
    const std::vector<std::string> arguments(argv + 1, argv + argc);

    // we do not know given arguments
    verify_arg_quantity(arguments);

    // wanted directory must be in current directory
    const fs::path current_dir = fs::current_path();
    const std::string current_dir_string = current_dir.string();

    const std::string wanted_dir = current_dir_string + "/" + arguments[0];
    const std::string wanted_ext = arguments[1];

    std::cout << "wanted_dir: " << wanted_dir << '\n';
    std::cout << "wanted_ext: " << wanted_ext << '\n';

    std::vector<std::string> files_for_tex_file;

    recursively_search_files(wanted_dir, wanted_ext, files_for_tex_file);

    verify_file_quantity(files_for_tex_file);

    fs::create_directories(arguments[0] + "/" + "new_tex");
    std::ofstream output_file(arguments[0] + "/" + "new_tex/output.tex");
    const fs::path new_tex_path = current_dir_string + "/test/test_dir/" + "new_tex/" + "output.tex" ;
    const std::string new_tex_path_string = new_tex_path.string();

    // we don't know if the output file was found
    verify_tex_file(new_tex_path_string);



    return 0;
}
