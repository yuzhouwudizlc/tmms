# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/go1116/Desktop/tmms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/go1116/Desktop/tmms/build

# Include any dependencies generated for this target.
include src/base/CMakeFiles/TestSingleton.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/base/CMakeFiles/TestSingleton.dir/compiler_depend.make

# Include the progress variables for this target.
include src/base/CMakeFiles/TestSingleton.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/CMakeFiles/TestSingleton.dir/flags.make

src/base/CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o: src/base/CMakeFiles/TestSingleton.dir/flags.make
src/base/CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o: ../src/base/TestSingleton.cpp
src/base/CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o: src/base/CMakeFiles/TestSingleton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/go1116/Desktop/tmms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o"
	cd /home/go1116/Desktop/tmms/build/src/base && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/base/CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o -MF CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o.d -o CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o -c /home/go1116/Desktop/tmms/src/base/TestSingleton.cpp

src/base/CMakeFiles/TestSingleton.dir/TestSingleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSingleton.dir/TestSingleton.cpp.i"
	cd /home/go1116/Desktop/tmms/build/src/base && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/go1116/Desktop/tmms/src/base/TestSingleton.cpp > CMakeFiles/TestSingleton.dir/TestSingleton.cpp.i

src/base/CMakeFiles/TestSingleton.dir/TestSingleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSingleton.dir/TestSingleton.cpp.s"
	cd /home/go1116/Desktop/tmms/build/src/base && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/go1116/Desktop/tmms/src/base/TestSingleton.cpp -o CMakeFiles/TestSingleton.dir/TestSingleton.cpp.s

# Object files for target TestSingleton
TestSingleton_OBJECTS = \
"CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o"

# External object files for target TestSingleton
TestSingleton_EXTERNAL_OBJECTS =

src/base/TestSingleton: src/base/CMakeFiles/TestSingleton.dir/TestSingleton.cpp.o
src/base/TestSingleton: src/base/CMakeFiles/TestSingleton.dir/build.make
src/base/TestSingleton: src/base/CMakeFiles/TestSingleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/go1116/Desktop/tmms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestSingleton"
	cd /home/go1116/Desktop/tmms/build/src/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSingleton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/CMakeFiles/TestSingleton.dir/build: src/base/TestSingleton
.PHONY : src/base/CMakeFiles/TestSingleton.dir/build

src/base/CMakeFiles/TestSingleton.dir/clean:
	cd /home/go1116/Desktop/tmms/build/src/base && $(CMAKE_COMMAND) -P CMakeFiles/TestSingleton.dir/cmake_clean.cmake
.PHONY : src/base/CMakeFiles/TestSingleton.dir/clean

src/base/CMakeFiles/TestSingleton.dir/depend:
	cd /home/go1116/Desktop/tmms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/go1116/Desktop/tmms /home/go1116/Desktop/tmms/src/base /home/go1116/Desktop/tmms/build /home/go1116/Desktop/tmms/build/src/base /home/go1116/Desktop/tmms/build/src/base/CMakeFiles/TestSingleton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/CMakeFiles/TestSingleton.dir/depend

