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
include src/util/CMakeFiles/utillib.dir/depend.make

# Include the progress variables for this target.
include src/util/CMakeFiles/utillib.dir/progress.make

# Include the compile flags for this target's objects.
include src/util/CMakeFiles/utillib.dir/flags.make

src/util/CMakeFiles/utillib.dir/align.cpp.o: src/util/CMakeFiles/utillib.dir/flags.make
src/util/CMakeFiles/utillib.dir/align.cpp.o: src/util/align.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dongxiang/Project/entity/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/util/CMakeFiles/utillib.dir/align.cpp.o"
	cd /home/dongxiang/Project/entity/src/util && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utillib.dir/align.cpp.o -c /home/dongxiang/Project/entity/src/util/align.cpp

src/util/CMakeFiles/utillib.dir/align.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utillib.dir/align.cpp.i"
	cd /home/dongxiang/Project/entity/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dongxiang/Project/entity/src/util/align.cpp > CMakeFiles/utillib.dir/align.cpp.i

src/util/CMakeFiles/utillib.dir/align.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utillib.dir/align.cpp.s"
	cd /home/dongxiang/Project/entity/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dongxiang/Project/entity/src/util/align.cpp -o CMakeFiles/utillib.dir/align.cpp.s

src/util/CMakeFiles/utillib.dir/align.cpp.o.requires:
.PHONY : src/util/CMakeFiles/utillib.dir/align.cpp.o.requires

src/util/CMakeFiles/utillib.dir/align.cpp.o.provides: src/util/CMakeFiles/utillib.dir/align.cpp.o.requires
	$(MAKE) -f src/util/CMakeFiles/utillib.dir/build.make src/util/CMakeFiles/utillib.dir/align.cpp.o.provides.build
.PHONY : src/util/CMakeFiles/utillib.dir/align.cpp.o.provides

src/util/CMakeFiles/utillib.dir/align.cpp.o.provides.build: src/util/CMakeFiles/utillib.dir/align.cpp.o
.PHONY : src/util/CMakeFiles/utillib.dir/align.cpp.o.provides.build

src/util/CMakeFiles/utillib.dir/nw.cpp.o: src/util/CMakeFiles/utillib.dir/flags.make
src/util/CMakeFiles/utillib.dir/nw.cpp.o: src/util/nw.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dongxiang/Project/entity/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/util/CMakeFiles/utillib.dir/nw.cpp.o"
	cd /home/dongxiang/Project/entity/src/util && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utillib.dir/nw.cpp.o -c /home/dongxiang/Project/entity/src/util/nw.cpp

src/util/CMakeFiles/utillib.dir/nw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utillib.dir/nw.cpp.i"
	cd /home/dongxiang/Project/entity/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dongxiang/Project/entity/src/util/nw.cpp > CMakeFiles/utillib.dir/nw.cpp.i

src/util/CMakeFiles/utillib.dir/nw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utillib.dir/nw.cpp.s"
	cd /home/dongxiang/Project/entity/src/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dongxiang/Project/entity/src/util/nw.cpp -o CMakeFiles/utillib.dir/nw.cpp.s

src/util/CMakeFiles/utillib.dir/nw.cpp.o.requires:
.PHONY : src/util/CMakeFiles/utillib.dir/nw.cpp.o.requires

src/util/CMakeFiles/utillib.dir/nw.cpp.o.provides: src/util/CMakeFiles/utillib.dir/nw.cpp.o.requires
	$(MAKE) -f src/util/CMakeFiles/utillib.dir/build.make src/util/CMakeFiles/utillib.dir/nw.cpp.o.provides.build
.PHONY : src/util/CMakeFiles/utillib.dir/nw.cpp.o.provides

src/util/CMakeFiles/utillib.dir/nw.cpp.o.provides.build: src/util/CMakeFiles/utillib.dir/nw.cpp.o
.PHONY : src/util/CMakeFiles/utillib.dir/nw.cpp.o.provides.build

# Object files for target utillib
utillib_OBJECTS = \
"CMakeFiles/utillib.dir/align.cpp.o" \
"CMakeFiles/utillib.dir/nw.cpp.o"

# External object files for target utillib
utillib_EXTERNAL_OBJECTS =

lib/libutillib.a: src/util/CMakeFiles/utillib.dir/align.cpp.o
lib/libutillib.a: src/util/CMakeFiles/utillib.dir/nw.cpp.o
lib/libutillib.a: src/util/CMakeFiles/utillib.dir/build.make
lib/libutillib.a: src/util/CMakeFiles/utillib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libutillib.a"
	cd /home/dongxiang/Project/entity/src/util && $(CMAKE_COMMAND) -P CMakeFiles/utillib.dir/cmake_clean_target.cmake
	cd /home/dongxiang/Project/entity/src/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utillib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/util/CMakeFiles/utillib.dir/build: lib/libutillib.a
.PHONY : src/util/CMakeFiles/utillib.dir/build

src/util/CMakeFiles/utillib.dir/requires: src/util/CMakeFiles/utillib.dir/align.cpp.o.requires
src/util/CMakeFiles/utillib.dir/requires: src/util/CMakeFiles/utillib.dir/nw.cpp.o.requires
.PHONY : src/util/CMakeFiles/utillib.dir/requires

src/util/CMakeFiles/utillib.dir/clean:
	cd /home/dongxiang/Project/entity/src/util && $(CMAKE_COMMAND) -P CMakeFiles/utillib.dir/cmake_clean.cmake
.PHONY : src/util/CMakeFiles/utillib.dir/clean

src/util/CMakeFiles/utillib.dir/depend:
	cd /home/dongxiang/Project/entity && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dongxiang/Project/entity /home/dongxiang/Project/entity/src/util /home/dongxiang/Project/entity /home/dongxiang/Project/entity/src/util /home/dongxiang/Project/entity/src/util/CMakeFiles/utillib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/util/CMakeFiles/utillib.dir/depend

