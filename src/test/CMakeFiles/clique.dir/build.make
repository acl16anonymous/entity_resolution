# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dongxiang/Project/entity

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dongxiang/Project/entity

# Include any dependencies generated for this target.
include src/test/CMakeFiles/clique.dir/depend.make

# Include the progress variables for this target.
include src/test/CMakeFiles/clique.dir/progress.make

# Include the compile flags for this target's objects.
include src/test/CMakeFiles/clique.dir/flags.make

src/test/CMakeFiles/clique.dir/clique.cpp.o: src/test/CMakeFiles/clique.dir/flags.make
src/test/CMakeFiles/clique.dir/clique.cpp.o: src/test/clique.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dongxiang/Project/entity/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/test/CMakeFiles/clique.dir/clique.cpp.o"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clique.dir/clique.cpp.o -c /home/dongxiang/Project/entity/src/test/clique.cpp

src/test/CMakeFiles/clique.dir/clique.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clique.dir/clique.cpp.i"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dongxiang/Project/entity/src/test/clique.cpp > CMakeFiles/clique.dir/clique.cpp.i

src/test/CMakeFiles/clique.dir/clique.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clique.dir/clique.cpp.s"
	cd /home/dongxiang/Project/entity/src/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dongxiang/Project/entity/src/test/clique.cpp -o CMakeFiles/clique.dir/clique.cpp.s

src/test/CMakeFiles/clique.dir/clique.cpp.o.requires:

.PHONY : src/test/CMakeFiles/clique.dir/clique.cpp.o.requires

src/test/CMakeFiles/clique.dir/clique.cpp.o.provides: src/test/CMakeFiles/clique.dir/clique.cpp.o.requires
	$(MAKE) -f src/test/CMakeFiles/clique.dir/build.make src/test/CMakeFiles/clique.dir/clique.cpp.o.provides.build
.PHONY : src/test/CMakeFiles/clique.dir/clique.cpp.o.provides

src/test/CMakeFiles/clique.dir/clique.cpp.o.provides.build: src/test/CMakeFiles/clique.dir/clique.cpp.o


# Object files for target clique
clique_OBJECTS = \
"CMakeFiles/clique.dir/clique.cpp.o"

# External object files for target clique
clique_EXTERNAL_OBJECTS =

bin/clique: src/test/CMakeFiles/clique.dir/clique.cpp.o
bin/clique: src/test/CMakeFiles/clique.dir/build.make
bin/clique: src/test/CMakeFiles/clique.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dongxiang/Project/entity/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/clique"
	cd /home/dongxiang/Project/entity/src/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clique.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test/CMakeFiles/clique.dir/build: bin/clique

.PHONY : src/test/CMakeFiles/clique.dir/build

src/test/CMakeFiles/clique.dir/requires: src/test/CMakeFiles/clique.dir/clique.cpp.o.requires

.PHONY : src/test/CMakeFiles/clique.dir/requires

src/test/CMakeFiles/clique.dir/clean:
	cd /home/dongxiang/Project/entity/src/test && $(CMAKE_COMMAND) -P CMakeFiles/clique.dir/cmake_clean.cmake
.PHONY : src/test/CMakeFiles/clique.dir/clean

src/test/CMakeFiles/clique.dir/depend:
	cd /home/dongxiang/Project/entity && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dongxiang/Project/entity /home/dongxiang/Project/entity/src/test /home/dongxiang/Project/entity /home/dongxiang/Project/entity/src/test /home/dongxiang/Project/entity/src/test/CMakeFiles/clique.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/test/CMakeFiles/clique.dir/depend
