# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Abmcar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Abmcar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Abmcar\OneDrive\ACM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Abmcar\OneDrive\ACM\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/template.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/template.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/template.dir/flags.make

CMakeFiles/template.dir/template.cpp.obj: CMakeFiles/template.dir/flags.make
CMakeFiles/template.dir/template.cpp.obj: ../template.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Abmcar\OneDrive\ACM\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/template.dir/template.cpp.obj"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\template.dir\template.cpp.obj -c C:\Users\Abmcar\OneDrive\ACM\template.cpp

CMakeFiles/template.dir/template.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template.dir/template.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Abmcar\OneDrive\ACM\template.cpp > CMakeFiles\template.dir\template.cpp.i

CMakeFiles/template.dir/template.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template.dir/template.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Abmcar\OneDrive\ACM\template.cpp -o CMakeFiles\template.dir\template.cpp.s

# Object files for target template
template_OBJECTS = \
"CMakeFiles/template.dir/template.cpp.obj"

# External object files for target template
template_EXTERNAL_OBJECTS =

template.exe: CMakeFiles/template.dir/template.cpp.obj
template.exe: CMakeFiles/template.dir/build.make
template.exe: CMakeFiles/template.dir/linklibs.rsp
template.exe: CMakeFiles/template.dir/objects1.rsp
template.exe: CMakeFiles/template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Abmcar\OneDrive\ACM\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable template.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\template.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/template.dir/build: template.exe
.PHONY : CMakeFiles/template.dir/build

CMakeFiles/template.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\template.dir\cmake_clean.cmake
.PHONY : CMakeFiles/template.dir/clean

CMakeFiles/template.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Abmcar\OneDrive\ACM C:\Users\Abmcar\OneDrive\ACM C:\Users\Abmcar\OneDrive\ACM\cmake-build-debug C:\Users\Abmcar\OneDrive\ACM\cmake-build-debug C:\Users\Abmcar\OneDrive\ACM\cmake-build-debug\CMakeFiles\template.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/template.dir/depend

