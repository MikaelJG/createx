#include <iostream>
#include <vector>
#include <filesystem>

#include "my_lib.h"

// namespace fs = std::filesystem;

std::vector<std::string> files_for_tex_file;

int main(int argc, char* argv[])
{
    // user gives wanted extension
    // and wanted directory
    const std::vector<std::string> arguments(argv + 1, argv + argc);

    // we do not know given arguments
    verify_arg_quantity(arguments);

    // // wanted directory must be in current directory
    // const fs::path current_dir = fs::current_path();
    // const std::string current_dir_string = current_dir.string();

    const std::string wanted_dir = "dir";
    const std::string wanted_ext = "tex";

    recursively_search_files(wanted_dir, wanted_ext);

    verify_file_quantity(files_for_tex_file);


    return 0;
}