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
include tests/CMakeFiles/test_strerror.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_strerror.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_strerror.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_strerror.dir/flags.make

tests/CMakeFiles/test_strerror.dir/test_strerror.c.o: tests/CMakeFiles/test_strerror.dir/flags.make
tests/CMakeFiles/test_strerror.dir/test_strerror.c.o: /home/rocky8usr/project/u-tudy/lib/json-c/tests/test_strerror.c
tests/CMakeFiles/test_strerror.dir/test_strerror.c.o: tests/CMakeFiles/test_strerror.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rocky8usr/project/u-tudy/lib/json-c-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/test_strerror.dir/test_strerror.c.o"
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/test_strerror.dir/test_strerror.c.o -MF CMakeFiles/test_strerror.dir/test_strerror.c.o.d -o CMakeFiles/test_strerror.dir/test_strerror.c.o -c /home/rocky8usr/project/u-tudy/lib/json-c/tests/test_strerror.c

tests/CMakeFiles/test_strerror.dir/test_strerror.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_strerror.dir/test_strerror.c.i"
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rocky8usr/project/u-tudy/lib/json-c/tests/test_strerror.c > CMakeFiles/test_strerror.dir/test_strerror.c.i

tests/CMakeFiles/test_strerror.dir/test_strerror.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_strerror.dir/test_strerror.c.s"
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rocky8usr/project/u-tudy/lib/json-c/tests/test_strerror.c -o CMakeFiles/test_strerror.dir/test_strerror.c.s

# Object files for target test_strerror
test_strerror_OBJECTS = \
"CMakeFiles/test_strerror.dir/test_strerror.c.o"

# External object files for target test_strerror
test_strerror_EXTERNAL_OBJECTS =

tests/test_strerror: tests/CMakeFiles/test_strerror.dir/test_strerror.c.o
tests/test_strerror: tests/CMakeFiles/test_strerror.dir/build.make
tests/test_strerror: libjson-c.so.5.4.0
tests/test_strerror: tests/CMakeFiles/test_strerror.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rocky8usr/project/u-tudy/lib/json-c-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_strerror"
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_strerror.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_strerror.dir/build: tests/test_strerror
.PHONY : tests/CMakeFiles/test_strerror.dir/build

tests/CMakeFiles/test_strerror.dir/clean:
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_strerror.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_strerror.dir/clean

tests/CMakeFiles/test_strerror.dir/depend:
	cd /home/rocky8usr/project/u-tudy/lib/json-c-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rocky8usr/project/u-tudy/lib/json-c /home/rocky8usr/project/u-tudy/lib/json-c/tests /home/rocky8usr/project/u-tudy/lib/json-c-build /home/rocky8usr/project/u-tudy/lib/json-c-build/tests /home/rocky8usr/project/u-tudy/lib/json-c-build/tests/CMakeFiles/test_strerror.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_strerror.dir/depend

