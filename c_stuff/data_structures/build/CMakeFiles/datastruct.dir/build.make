# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/build

# Include any dependencies generated for this target.
include CMakeFiles/datastruct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/datastruct.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/datastruct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/datastruct.dir/flags.make

CMakeFiles/datastruct.dir/src/linked_list.c.o: CMakeFiles/datastruct.dir/flags.make
CMakeFiles/datastruct.dir/src/linked_list.c.o: /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/src/linked_list.c
CMakeFiles/datastruct.dir/src/linked_list.c.o: CMakeFiles/datastruct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/datastruct.dir/src/linked_list.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/datastruct.dir/src/linked_list.c.o -MF CMakeFiles/datastruct.dir/src/linked_list.c.o.d -o CMakeFiles/datastruct.dir/src/linked_list.c.o -c /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/src/linked_list.c

CMakeFiles/datastruct.dir/src/linked_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datastruct.dir/src/linked_list.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/src/linked_list.c > CMakeFiles/datastruct.dir/src/linked_list.c.i

CMakeFiles/datastruct.dir/src/linked_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datastruct.dir/src/linked_list.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/src/linked_list.c -o CMakeFiles/datastruct.dir/src/linked_list.c.s

# Object files for target datastruct
datastruct_OBJECTS = \
"CMakeFiles/datastruct.dir/src/linked_list.c.o"

# External object files for target datastruct
datastruct_EXTERNAL_OBJECTS =

libdatastruct.dylib: CMakeFiles/datastruct.dir/src/linked_list.c.o
libdatastruct.dylib: CMakeFiles/datastruct.dir/build.make
libdatastruct.dylib: CMakeFiles/datastruct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libdatastruct.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/datastruct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/datastruct.dir/build: libdatastruct.dylib
.PHONY : CMakeFiles/datastruct.dir/build

CMakeFiles/datastruct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/datastruct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/datastruct.dir/clean

CMakeFiles/datastruct.dir/depend:
	cd /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/build /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/build /Users/segonzal/repos/prog_languages_stuff/c_cpp_stuff/c_stuff/data_structures/build/CMakeFiles/datastruct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/datastruct.dir/depend
