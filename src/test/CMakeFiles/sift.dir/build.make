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
include src/test/CMakeFiles/sift.dir/depend.make

# Include the progress variables for this target.
include src/test/CMakeFiles/sift.dir/progress.make

# Include the compile flags for this target's objects.
include src/test/CMakeFiles/sift.dir/flags.make

src/test/CMakeFiles/sift.dir/sift.cpp.o: src/test/CMakeFiles/sift.dir/flags.make
src/test/CMakeFiles/sift.dir/sift.cpp.o: src/test/sift.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dongxiang/Project/entity/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/test/CMakeFiles/sift.dir/sift.cpp.o"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sift.dir/sift.cpp.o -c /home/dongxiang/Project/entity/src/test/sift.cpp

src/test/CMakeFiles/sift.dir/sift.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sift.dir/sift.cpp.i"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dongxiang/Project/entity/src/test/sift.cpp > CMakeFiles/sift.dir/sift.cpp.i

src/test/CMakeFiles/sift.dir/sift.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sift.dir/sift.cpp.s"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dongxiang/Project/entity/src/test/sift.cpp -o CMakeFiles/sift.dir/sift.cpp.s

src/test/CMakeFiles/sift.dir/sift.cpp.o.requires:
.PHONY : src/test/CMakeFiles/sift.dir/sift.cpp.o.requires

src/test/CMakeFiles/sift.dir/sift.cpp.o.provides: src/test/CMakeFiles/sift.dir/sift.cpp.o.requires
	$(MAKE) -f src/test/CMakeFiles/sift.dir/build.make src/test/CMakeFiles/sift.dir/sift.cpp.o.provides.build
.PHONY : src/test/CMakeFiles/sift.dir/sift.cpp.o.provides

src/test/CMakeFiles/sift.dir/sift.cpp.o.provides.build: src/test/CMakeFiles/sift.dir/sift.cpp.o
.PHONY : src/test/CMakeFiles/sift.dir/sift.cpp.o.provides.build

# Object files for target sift
sift_OBJECTS = \
"CMakeFiles/sift.dir/sift.cpp.o"

# External object files for target sift
sift_EXTERNAL_OBJECTS =

bin/sift: src/test/CMakeFiles/sift.dir/sift.cpp.o
bin/sift: lib/libutillib.a
bin/sift: src/test/CMakeFiles/sift.dir/build.make
bin/sift: src/test/CMakeFiles/sift.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/sift"
	cd /home/dongxiang/Project/entity/src/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sift.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test/CMakeFiles/sift.dir/build: bin/sift
.PHONY : src/test/CMakeFiles/sift.dir/build

src/test/CMakeFiles/sift.dir/requires: src/test/CMakeFiles/sift.dir/sift.cpp.o.requires
.PHONY : src/test/CMakeFiles/sift.dir/requires

src/test/CMakeFiles/sift.dir/clean:
	cd /home/dongxiang/Project/entity/src/test && $(CMAKE_COMMAND) -P CMakeFiles/sift.dir/cmake_clean.cmake
.PHONY : src/test/CMakeFiles/sift.dir/clean

src/test/CMakeFiles/sift.dir/depend:
	cd /home/dongxiang/Project/entity && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dongxiang/Project/entity /home/dongxiang/Project/entity/src/test /home/dongxiang/Project/entity /home/dongxiang/Project/entity/src/test /home/dongxiang/Project/entity/src/test/CMakeFiles/sift.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/test/CMakeFiles/sift.dir/depend

