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
include app/CMakeFiles/Createx.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/Createx.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/Createx.dir/flags.make

app/CMakeFiles/Createx.dir/main.cc.o: app/CMakeFiles/Createx.dir/flags.make
app/CMakeFiles/Createx.dir/main.cc.o: ../app/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mjg/code/createx/cmake_createx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/Createx.dir/main.cc.o"
	cd /home/mjg/code/createx/cmake_createx/build/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Createx.dir/main.cc.o -c /home/mjg/code/createx/cmake_createx/app/main.cc

app/CMakeFiles/Createx.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Createx.dir/main.cc.i"
	cd /home/mjg/code/createx/cmake_createx/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mjg/code/createx/cmake_createx/app/main.cc > CMakeFiles/Createx.dir/main.cc.i

app/CMakeFiles/Createx.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Createx.dir/main.cc.s"
	cd /home/mjg/code/createx/cmake_createx/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mjg/code/createx/cmake_createx/app/main.cc -o CMakeFiles/Createx.dir/main.cc.s

# Object files for target Createx
Createx_OBJECTS = \
"CMakeFiles/Createx.dir/main.cc.o"

# External object files for target Createx
Createx_EXTERNAL_OBJECTS =

app/Createx: app/CMakeFiles/Createx.dir/main.cc.o
app/Createx: app/CMakeFiles/Createx.dir/build.make
app/Createx: src/my_lib/libVerification_Library.a
app/Createx: app/CMakeFiles/Createx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mjg/code/createx/cmake_createx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Createx"
	cd /home/mjg/code/createx/cmake_createx/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Createx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/Createx.dir/build: app/Createx

.PHONY : app/CMakeFiles/Createx.dir/build

app/CMakeFiles/Createx.dir/clean:
	cd /home/mjg/code/createx/cmake_createx/build/app && $(CMAKE_COMMAND) -P CMakeFiles/Createx.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/Createx.dir/clean

app/CMakeFiles/Createx.dir/depend:
	cd /home/mjg/code/createx/cmake_createx/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mjg/code/createx/cmake_createx /home/mjg/code/createx/cmake_createx/app /home/mjg/code/createx/cmake_createx/build /home/mjg/code/createx/cmake_createx/build/app /home/mjg/code/createx/cmake_createx/build/app/CMakeFiles/Createx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/Createx.dir/depend

