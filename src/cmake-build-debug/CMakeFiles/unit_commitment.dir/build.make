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
CMAKE_SOURCE_DIR = /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/unit_commitment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unit_commitment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit_commitment.dir/flags.make

CMakeFiles/unit_commitment.dir/main.cpp.o: CMakeFiles/unit_commitment.dir/flags.make
CMakeFiles/unit_commitment.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unit_commitment.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_commitment.dir/main.cpp.o -c /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/main.cpp

CMakeFiles/unit_commitment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_commitment.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/main.cpp > CMakeFiles/unit_commitment.dir/main.cpp.i

CMakeFiles/unit_commitment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_commitment.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/main.cpp -o CMakeFiles/unit_commitment.dir/main.cpp.s

CMakeFiles/unit_commitment.dir/parser.cpp.o: CMakeFiles/unit_commitment.dir/flags.make
CMakeFiles/unit_commitment.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/unit_commitment.dir/parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_commitment.dir/parser.cpp.o -c /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/parser.cpp

CMakeFiles/unit_commitment.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_commitment.dir/parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/parser.cpp > CMakeFiles/unit_commitment.dir/parser.cpp.i

CMakeFiles/unit_commitment.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_commitment.dir/parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/parser.cpp -o CMakeFiles/unit_commitment.dir/parser.cpp.s

CMakeFiles/unit_commitment.dir/matrix.cpp.o: CMakeFiles/unit_commitment.dir/flags.make
CMakeFiles/unit_commitment.dir/matrix.cpp.o: ../matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/unit_commitment.dir/matrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_commitment.dir/matrix.cpp.o -c /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/matrix.cpp

CMakeFiles/unit_commitment.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_commitment.dir/matrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/matrix.cpp > CMakeFiles/unit_commitment.dir/matrix.cpp.i

CMakeFiles/unit_commitment.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_commitment.dir/matrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/matrix.cpp -o CMakeFiles/unit_commitment.dir/matrix.cpp.s

CMakeFiles/unit_commitment.dir/generator.cpp.o: CMakeFiles/unit_commitment.dir/flags.make
CMakeFiles/unit_commitment.dir/generator.cpp.o: ../generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/unit_commitment.dir/generator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_commitment.dir/generator.cpp.o -c /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/generator.cpp

CMakeFiles/unit_commitment.dir/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_commitment.dir/generator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/generator.cpp > CMakeFiles/unit_commitment.dir/generator.cpp.i

CMakeFiles/unit_commitment.dir/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_commitment.dir/generator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/generator.cpp -o CMakeFiles/unit_commitment.dir/generator.cpp.s

CMakeFiles/unit_commitment.dir/ranking.cpp.o: CMakeFiles/unit_commitment.dir/flags.make
CMakeFiles/unit_commitment.dir/ranking.cpp.o: ../ranking.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/unit_commitment.dir/ranking.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_commitment.dir/ranking.cpp.o -c /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/ranking.cpp

CMakeFiles/unit_commitment.dir/ranking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_commitment.dir/ranking.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/ranking.cpp > CMakeFiles/unit_commitment.dir/ranking.cpp.i

CMakeFiles/unit_commitment.dir/ranking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_commitment.dir/ranking.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/ranking.cpp -o CMakeFiles/unit_commitment.dir/ranking.cpp.s

# Object files for target unit_commitment
unit_commitment_OBJECTS = \
"CMakeFiles/unit_commitment.dir/main.cpp.o" \
"CMakeFiles/unit_commitment.dir/parser.cpp.o" \
"CMakeFiles/unit_commitment.dir/matrix.cpp.o" \
"CMakeFiles/unit_commitment.dir/generator.cpp.o" \
"CMakeFiles/unit_commitment.dir/ranking.cpp.o"

# External object files for target unit_commitment
unit_commitment_EXTERNAL_OBJECTS =

unit_commitment: CMakeFiles/unit_commitment.dir/main.cpp.o
unit_commitment: CMakeFiles/unit_commitment.dir/parser.cpp.o
unit_commitment: CMakeFiles/unit_commitment.dir/matrix.cpp.o
unit_commitment: CMakeFiles/unit_commitment.dir/generator.cpp.o
unit_commitment: CMakeFiles/unit_commitment.dir/ranking.cpp.o
unit_commitment: CMakeFiles/unit_commitment.dir/build.make
unit_commitment: CMakeFiles/unit_commitment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable unit_commitment"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_commitment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit_commitment.dir/build: unit_commitment

.PHONY : CMakeFiles/unit_commitment.dir/build

CMakeFiles/unit_commitment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unit_commitment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unit_commitment.dir/clean

CMakeFiles/unit_commitment.dir/depend:
	cd /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug /Users/deepsonkhadka/Desktop/Capstone-Project-develop/src/cmake-build-debug/CMakeFiles/unit_commitment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit_commitment.dir/depend

