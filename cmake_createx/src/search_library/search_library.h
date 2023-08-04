#pragma once

#include "search_library.cpp"

void recursively_search_files(const std::string& dir,
                              const std::string& wanted_ext,
                              std::vector<std::string>& files_for_tex_file);
