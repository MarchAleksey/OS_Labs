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
CMAKE_SOURCE_DIR = /home/ggame/hubs/newos/l5/8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ggame/hubs/newos/l5/8/build

# Include any dependencies generated for this target.
include CMakeFiles/main2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main2.dir/flags.make

CMakeFiles/main2.dir/src/main2.c.o: CMakeFiles/main2.dir/flags.make
CMakeFiles/main2.dir/src/main2.c.o: ../src/main2.c
CMakeFiles/main2.dir/src/main2.c.o: CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggame/hubs/newos/l5/8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main2.dir/src/main2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main2.dir/src/main2.c.o -MF CMakeFiles/main2.dir/src/main2.c.o.d -o CMakeFiles/main2.dir/src/main2.c.o -c /home/ggame/hubs/newos/l5/8/src/main2.c

CMakeFiles/main2.dir/src/main2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main2.dir/src/main2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggame/hubs/newos/l5/8/src/main2.c > CMakeFiles/main2.dir/src/main2.c.i

CMakeFiles/main2.dir/src/main2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main2.dir/src/main2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggame/hubs/newos/l5/8/src/main2.c -o CMakeFiles/main2.dir/src/main2.c.s

# Object files for target main2
main2_OBJECTS = \
"CMakeFiles/main2.dir/src/main2.c.o"

# External object files for target main2
main2_EXTERNAL_OBJECTS =

main2: CMakeFiles/main2.dir/src/main2.c.o
main2: CMakeFiles/main2.dir/build.make
main2: liblib2.so
main2: CMakeFiles/main2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ggame/hubs/newos/l5/8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main2.dir/build: main2
.PHONY : CMakeFiles/main2.dir/build

CMakeFiles/main2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main2.dir/clean

CMakeFiles/main2.dir/depend:
	cd /home/ggame/hubs/newos/l5/8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ggame/hubs/newos/l5/8 /home/ggame/hubs/newos/l5/8 /home/ggame/hubs/newos/l5/8/build /home/ggame/hubs/newos/l5/8/build /home/ggame/hubs/newos/l5/8/build/CMakeFiles/main2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main2.dir/depend
