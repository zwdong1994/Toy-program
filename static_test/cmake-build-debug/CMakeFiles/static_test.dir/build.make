# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/victor/Downloads/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/victor/Downloads/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/victor/zwd/lit_test/static_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/victor/zwd/lit_test/static_test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/static_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/static_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/static_test.dir/flags.make

CMakeFiles/static_test.dir/main.cpp.o: CMakeFiles/static_test.dir/flags.make
CMakeFiles/static_test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/lit_test/static_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/static_test.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/static_test.dir/main.cpp.o -c /home/victor/zwd/lit_test/static_test/main.cpp

CMakeFiles/static_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static_test.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/zwd/lit_test/static_test/main.cpp > CMakeFiles/static_test.dir/main.cpp.i

CMakeFiles/static_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static_test.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/zwd/lit_test/static_test/main.cpp -o CMakeFiles/static_test.dir/main.cpp.s

CMakeFiles/static_test.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/static_test.dir/main.cpp.o.requires

CMakeFiles/static_test.dir/main.cpp.o.provides: CMakeFiles/static_test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/static_test.dir/build.make CMakeFiles/static_test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/static_test.dir/main.cpp.o.provides

CMakeFiles/static_test.dir/main.cpp.o.provides.build: CMakeFiles/static_test.dir/main.cpp.o


CMakeFiles/static_test.dir/file1.c.o: CMakeFiles/static_test.dir/flags.make
CMakeFiles/static_test.dir/file1.c.o: ../file1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/lit_test/static_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/static_test.dir/file1.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/static_test.dir/file1.c.o   -c /home/victor/zwd/lit_test/static_test/file1.c

CMakeFiles/static_test.dir/file1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/static_test.dir/file1.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/victor/zwd/lit_test/static_test/file1.c > CMakeFiles/static_test.dir/file1.c.i

CMakeFiles/static_test.dir/file1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/static_test.dir/file1.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/victor/zwd/lit_test/static_test/file1.c -o CMakeFiles/static_test.dir/file1.c.s

CMakeFiles/static_test.dir/file1.c.o.requires:

.PHONY : CMakeFiles/static_test.dir/file1.c.o.requires

CMakeFiles/static_test.dir/file1.c.o.provides: CMakeFiles/static_test.dir/file1.c.o.requires
	$(MAKE) -f CMakeFiles/static_test.dir/build.make CMakeFiles/static_test.dir/file1.c.o.provides.build
.PHONY : CMakeFiles/static_test.dir/file1.c.o.provides

CMakeFiles/static_test.dir/file1.c.o.provides.build: CMakeFiles/static_test.dir/file1.c.o


# Object files for target static_test
static_test_OBJECTS = \
"CMakeFiles/static_test.dir/main.cpp.o" \
"CMakeFiles/static_test.dir/file1.c.o"

# External object files for target static_test
static_test_EXTERNAL_OBJECTS =

static_test: CMakeFiles/static_test.dir/main.cpp.o
static_test: CMakeFiles/static_test.dir/file1.c.o
static_test: CMakeFiles/static_test.dir/build.make
static_test: CMakeFiles/static_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/victor/zwd/lit_test/static_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable static_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/static_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/static_test.dir/build: static_test

.PHONY : CMakeFiles/static_test.dir/build

CMakeFiles/static_test.dir/requires: CMakeFiles/static_test.dir/main.cpp.o.requires
CMakeFiles/static_test.dir/requires: CMakeFiles/static_test.dir/file1.c.o.requires

.PHONY : CMakeFiles/static_test.dir/requires

CMakeFiles/static_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/static_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/static_test.dir/clean

CMakeFiles/static_test.dir/depend:
	cd /home/victor/zwd/lit_test/static_test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/victor/zwd/lit_test/static_test /home/victor/zwd/lit_test/static_test /home/victor/zwd/lit_test/static_test/cmake-build-debug /home/victor/zwd/lit_test/static_test/cmake-build-debug /home/victor/zwd/lit_test/static_test/cmake-build-debug/CMakeFiles/static_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/static_test.dir/depend

