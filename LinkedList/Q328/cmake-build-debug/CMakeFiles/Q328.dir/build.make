# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/apple/Desktop/LeetCode/LinkedList/Q328

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/apple/Desktop/LeetCode/LinkedList/Q328/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Q328.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Q328.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Q328.dir/flags.make

CMakeFiles/Q328.dir/main.cpp.o: CMakeFiles/Q328.dir/flags.make
CMakeFiles/Q328.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/Desktop/LeetCode/LinkedList/Q328/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Q328.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Q328.dir/main.cpp.o -c /Users/apple/Desktop/LeetCode/LinkedList/Q328/main.cpp

CMakeFiles/Q328.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Q328.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/apple/Desktop/LeetCode/LinkedList/Q328/main.cpp > CMakeFiles/Q328.dir/main.cpp.i

CMakeFiles/Q328.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Q328.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/apple/Desktop/LeetCode/LinkedList/Q328/main.cpp -o CMakeFiles/Q328.dir/main.cpp.s

# Object files for target Q328
Q328_OBJECTS = \
"CMakeFiles/Q328.dir/main.cpp.o"

# External object files for target Q328
Q328_EXTERNAL_OBJECTS =

Q328: CMakeFiles/Q328.dir/main.cpp.o
Q328: CMakeFiles/Q328.dir/build.make
Q328: CMakeFiles/Q328.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/apple/Desktop/LeetCode/LinkedList/Q328/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Q328"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Q328.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Q328.dir/build: Q328

.PHONY : CMakeFiles/Q328.dir/build

CMakeFiles/Q328.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Q328.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Q328.dir/clean

CMakeFiles/Q328.dir/depend:
	cd /Users/apple/Desktop/LeetCode/LinkedList/Q328/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apple/Desktop/LeetCode/LinkedList/Q328 /Users/apple/Desktop/LeetCode/LinkedList/Q328 /Users/apple/Desktop/LeetCode/LinkedList/Q328/cmake-build-debug /Users/apple/Desktop/LeetCode/LinkedList/Q328/cmake-build-debug /Users/apple/Desktop/LeetCode/LinkedList/Q328/cmake-build-debug/CMakeFiles/Q328.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Q328.dir/depend

