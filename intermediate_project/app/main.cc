#include <iostream>

#include "my_lib.h"

int main()
{
    const std::string wanted_dir = "dir";
    const std::string wanted_ext = "tex";
    print_hello_world();
    recursively_search_files(wanted_dir, wanted_ext);
    return 0;
}
