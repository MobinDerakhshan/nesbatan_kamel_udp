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
CMAKE_SOURCE_DIR = /home/mobin/Desktop/ha/tanin/left

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mobin/Desktop/ha/tanin/left/build

# Include any dependencies generated for this target.
include CMakeFiles/left.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/left.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/left.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/left.dir/flags.make

CMakeFiles/left.dir/main.cpp.o: CMakeFiles/left.dir/flags.make
CMakeFiles/left.dir/main.cpp.o: ../main.cpp
CMakeFiles/left.dir/main.cpp.o: CMakeFiles/left.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mobin/Desktop/ha/tanin/left/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/left.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/left.dir/main.cpp.o -MF CMakeFiles/left.dir/main.cpp.o.d -o CMakeFiles/left.dir/main.cpp.o -c /home/mobin/Desktop/ha/tanin/left/main.cpp

CMakeFiles/left.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/left.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mobin/Desktop/ha/tanin/left/main.cpp > CMakeFiles/left.dir/main.cpp.i

CMakeFiles/left.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/left.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mobin/Desktop/ha/tanin/left/main.cpp -o CMakeFiles/left.dir/main.cpp.s

# Object files for target left
left_OBJECTS = \
"CMakeFiles/left.dir/main.cpp.o"

# External object files for target left
left_EXTERNAL_OBJECTS =

left: CMakeFiles/left.dir/main.cpp.o
left: CMakeFiles/left.dir/build.make
left: CMakeFiles/left.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mobin/Desktop/ha/tanin/left/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable left"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/left.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/left.dir/build: left
.PHONY : CMakeFiles/left.dir/build

CMakeFiles/left.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/left.dir/cmake_clean.cmake
.PHONY : CMakeFiles/left.dir/clean

CMakeFiles/left.dir/depend:
	cd /home/mobin/Desktop/ha/tanin/left/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mobin/Desktop/ha/tanin/left /home/mobin/Desktop/ha/tanin/left /home/mobin/Desktop/ha/tanin/left/build /home/mobin/Desktop/ha/tanin/left/build /home/mobin/Desktop/ha/tanin/left/build/CMakeFiles/left.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/left.dir/depend

