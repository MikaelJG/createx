# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mjg/code/createx/cmake_createx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mjg/code/createx/cmake_createx/build

# Include any dependencies generated for this target.
include app/CMakeFiles/Createx_executable.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/Createx_executable.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/Createx_executable.dir/flags.make

app/CMakeFiles/Createx_executable.dir/main.cpp.o: app/CMakeFiles/Createx_executable.dir/flags.make
app/CMakeFiles/Createx_executable.dir/main.cpp.o: ../app/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mjg/code/createx/cmake_createx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/Createx_executable.dir/main.cpp.o"
	cd /home/mjg/code/createx/cmake_createx/build/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Createx_executable.dir/main.cpp.o -c /home/mjg/code/createx/cmake_createx/app/main.cpp

app/CMakeFiles/Createx_executable.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Createx_executable.dir/main.cpp.i"
	cd /home/mjg/code/createx/cmake_createx/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mjg/code/createx/cmake_createx/app/main.cpp > CMakeFiles/Createx_executable.dir/main.cpp.i

app/CMakeFiles/Createx_executable.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Createx_executable.dir/main.cpp.s"
	cd /home/mjg/code/createx/cmake_createx/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mjg/code/createx/cmake_createx/app/main.cpp -o CMakeFiles/Createx_executable.dir/main.cpp.s

# Object files for target Createx_executable
Createx_executable_OBJECTS = \
"CMakeFiles/Createx_executable.dir/main.cpp.o"

# External object files for target Createx_executable
Createx_executable_EXTERNAL_OBJECTS =

app/Createx_executable: app/CMakeFiles/Createx_executable.dir/main.cpp.o
app/Createx_executable: app/CMakeFiles/Createx_executable.dir/build.make
app/Createx_executable: src/append_library/libAppend_Library.a
app/Createx_executable: src/verification_library/libVerification_Library.a
app/Createx_executable: src/search_library/libSearch_Library.a
app/Createx_executable: app/CMakeFiles/Createx_executable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mjg/code/createx/cmake_createx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Createx_executable"
	cd /home/mjg/code/createx/cmake_createx/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Createx_executable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/Createx_executable.dir/build: app/Createx_executable

.PHONY : app/CMakeFiles/Createx_executable.dir/build

app/CMakeFiles/Createx_executable.dir/clean:
	cd /home/mjg/code/createx/cmake_createx/build/app && $(CMAKE_COMMAND) -P CMakeFiles/Createx_executable.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/Createx_executable.dir/clean

app/CMakeFiles/Createx_executable.dir/depend:
	cd /home/mjg/code/createx/cmake_createx/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mjg/code/createx/cmake_createx /home/mjg/code/createx/cmake_createx/app /home/mjg/code/createx/cmake_createx/build /home/mjg/code/createx/cmake_createx/build/app /home/mjg/code/createx/cmake_createx/build/app/CMakeFiles/Createx_executable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/Createx_executable.dir/depend

