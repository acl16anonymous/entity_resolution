# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dongxiang/Project/entity

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dongxiang/Project/entity

# Include any dependencies generated for this target.
include src/test/CMakeFiles/match.dir/depend.make

# Include the progress variables for this target.
include src/test/CMakeFiles/match.dir/progress.make

# Include the compile flags for this target's objects.
include src/test/CMakeFiles/match.dir/flags.make

src/test/CMakeFiles/match.dir/match.cpp.o: src/test/CMakeFiles/match.dir/flags.make
src/test/CMakeFiles/match.dir/match.cpp.o: src/test/match.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dongxiang/Project/entity/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/test/CMakeFiles/match.dir/match.cpp.o"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++   $(CXX_DEFINES) INCLUDES $(CXX_FLAGS) -o CMakeFiles/match.dir/match.cpp.o -c /home/dongxiang/Project/entity/src/test/match.cpp

src/test/CMakeFiles/match.dir/match.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/match.dir/match.cpp.i"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++  $(CXX_DEFINES) INCLUDES $(CXX_FLAGS) -E /home/dongxiang/Project/entity/src/test/match.cpp > CMakeFiles/match.dir/match.cpp.i

src/test/CMakeFiles/match.dir/match.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/match.dir/match.cpp.s"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++  $(CXX_DEFINES) INCLUDES $(CXX_FLAGS) -S /home/dongxiang/Project/entity/src/test/match.cpp -o CMakeFiles/match.dir/match.cpp.s

src/test/CMakeFiles/match.dir/match.cpp.o.requires:
.PHONY : src/test/CMakeFiles/match.dir/match.cpp.o.requires

src/test/CMakeFiles/match.dir/match.cpp.o.provides: src/test/CMakeFiles/match.dir/match.cpp.o.requires
	$(MAKE) -f src/test/CMakeFiles/match.dir/build.make src/test/CMakeFiles/match.dir/match.cpp.o.provides.build
.PHONY : src/test/CMakeFiles/match.dir/match.cpp.o.provides

src/test/CMakeFiles/match.dir/match.cpp.o.provides.build: src/test/CMakeFiles/match.dir/match.cpp.o
.PHONY : src/test/CMakeFiles/match.dir/match.cpp.o.provides.build

# Object files for target match
match_OBJECTS = \
"CMakeFiles/match.dir/match.cpp.o"

# External object files for target match
match_EXTERNAL_OBJECTS =

bin/match: src/test/CMakeFiles/match.dir/match.cpp.o
bin/match: src/test/CMakeFiles/match.dir/build.make
bin/match: src/test/CMakeFiles/match.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/match"
	cd /home/dongxiang/Project/entity/src/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/match.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test/CMakeFiles/match.dir/build: bin/match
.PHONY : src/test/CMakeFiles/match.dir/build

src/test/CMakeFiles/match.dir/requires: src/test/CMakeFiles/match.dir/match.cpp.o.requires
.PHONY : src/test/CMakeFiles/match.dir/requires

src/test/CMakeFiles/match.dir/clean:
	cd /home/dongxiang/Project/entity/src/test && $(CMAKE_COMMAND) -P CMakeFiles/match.dir/cmake_clean.cmake
.PHONY : src/test/CMakeFiles/match.dir/clean

src/test/CMakeFiles/match.dir/depend:
	cd /home/dongxiang/Project/entity && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dongxiang/Project/entity /home/dongxiang/Project/entity/src/test /home/dongxiang/Project/entity /home/dongxiang/Project/entity/src/test /home/dongxiang/Project/entity/src/test/CMakeFiles/match.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/test/CMakeFiles/match.dir/depend
