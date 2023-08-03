#include <iostream>
#include <vector>

#include "my_lib.h"

int main(int argc, char* argv[])
{
    // user gives wanted extension
    // and wanted directory
    const std::vector<std::string> arguments(argv + 1, argv + argc);

    // we do not know given arguments
    verify_arg_quantity(arguments);

    const std::string wanted_dir = "dir";
    const std::string wanted_ext = "tex";

    print_hello_world();
    recursively_search_files(wanted_dir, wanted_ext);

    return 0;
}
