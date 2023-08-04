#pragma once

void print_hello_world();

void recursively_search_files(const std::string& dir,
                              const std::string& wanted_ext,
                              std::vector<std::string> files_for_tex_file);

void verify_arg_quantity(std::vector<std::string> arguments);

void verify_file_quantity(std::vector<std::string> found_files);
