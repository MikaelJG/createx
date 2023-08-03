#include <iostream>

#include "my_lib.h"

void print_hello_world()
{
    std::cout << "Hello World!\n";
}

void recursively_search_files(const std::string& dir, const std::string& wanted_ext)
{
    std::cout << "Hello from recursively_search_function!\n";
}
