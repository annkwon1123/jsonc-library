# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/rocky8usr/project/u-tudy/lib/json-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rocky8usr/project/u-tudy/lib/json-c-build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_float.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_float.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_float.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_float.dir/flags.make

tests/CMakeFiles/test_float.dir/test_float.c.o: tests/CMakeFiles/test_float.dir/flags.make
tests/CMakeFiles/test_float.dir/test_float.c.o: /home/rocky8usr/project/u-tudy/lib/json-c/tests/test_float.c
tests/CMakeFiles/test_float.dir/test_float.c.o: tests/CMakeFiles/test_float.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rocky8usr/project/u-tudy/lib/json-c-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/test_float.dir/test_float.c.o"
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/test_float.dir/test_float.c.o -MF CMakeFiles/test_float.dir/test_float.c.o.d -o CMakeFiles/test_float.dir/test_float.c.o -c /home/rocky8usr/project/u-tudy/lib/json-c/tests/test_float.c

tests/CMakeFiles/test_float.dir/test_float.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_float.dir/test_float.c.i"
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rocky8usr/project/u-tudy/lib/json-c/tests/test_float.c > CMakeFiles/test_float.dir/test_float.c.i

tests/CMakeFiles/test_float.dir/test_float.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_float.dir/test_float.c.s"
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rocky8usr/project/u-tudy/lib/json-c/tests/test_float.c -o CMakeFiles/test_float.dir/test_float.c.s

# Object files for target test_float
test_float_OBJECTS = \
"CMakeFiles/test_float.dir/test_float.c.o"

# External object files for target test_float
test_float_EXTERNAL_OBJECTS =

tests/test_float: tests/CMakeFiles/test_float.dir/test_float.c.o
tests/test_float: tests/CMakeFiles/test_float.dir/build.make
tests/test_float: libjson-c.so.5.4.0
tests/test_float: tests/CMakeFiles/test_float.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rocky8usr/project/u-tudy/lib/json-c-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_float"
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_float.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_float.dir/build: tests/test_float
.PHONY : tests/CMakeFiles/test_float.dir/build

tests/CMakeFiles/test_float.dir/clean:
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_float.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_float.dir/clean

tests/CMakeFiles/test_float.dir/depend:
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rocky8usr/project/u-tudy/lib/json-c /home/rocky8usr/project/u-tudy/lib/json-c/tests /home/rocky8usr/project/u-tudy/lib/json-c-build /home/rocky8usr/project/u-tudy/lib/json-c-build/tests /home/rocky8usr/project/u-tudy/lib/json-c-build/tests/CMakeFiles/test_float.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_float.dir/depend

