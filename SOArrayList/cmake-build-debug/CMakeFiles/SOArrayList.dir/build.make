# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\IDE\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\IDE\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\istil\Desktop\gg\DataStructures\SOArrayList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SOArrayList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SOArrayList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SOArrayList.dir/flags.make

CMakeFiles/SOArrayList.dir/SOArrayList.cpp.obj: CMakeFiles/SOArrayList.dir/flags.make
CMakeFiles/SOArrayList.dir/SOArrayList.cpp.obj: ../SOArrayList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SOArrayList.dir/SOArrayList.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SOArrayList.dir\SOArrayList.cpp.obj -c C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\SOArrayList.cpp

CMakeFiles/SOArrayList.dir/SOArrayList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SOArrayList.dir/SOArrayList.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\SOArrayList.cpp > CMakeFiles\SOArrayList.dir\SOArrayList.cpp.i

CMakeFiles/SOArrayList.dir/SOArrayList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SOArrayList.dir/SOArrayList.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\SOArrayList.cpp -o CMakeFiles\SOArrayList.dir\SOArrayList.cpp.s

CMakeFiles/SOArrayList.dir/main.cpp.obj: CMakeFiles/SOArrayList.dir/flags.make
CMakeFiles/SOArrayList.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SOArrayList.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SOArrayList.dir\main.cpp.obj -c C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\main.cpp

CMakeFiles/SOArrayList.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SOArrayList.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\main.cpp > CMakeFiles\SOArrayList.dir\main.cpp.i

CMakeFiles/SOArrayList.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SOArrayList.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\main.cpp -o CMakeFiles\SOArrayList.dir\main.cpp.s

# Object files for target SOArrayList
SOArrayList_OBJECTS = \
"CMakeFiles/SOArrayList.dir/SOArrayList.cpp.obj" \
"CMakeFiles/SOArrayList.dir/main.cpp.obj"

# External object files for target SOArrayList
SOArrayList_EXTERNAL_OBJECTS =

SOArrayList.exe: CMakeFiles/SOArrayList.dir/SOArrayList.cpp.obj
SOArrayList.exe: CMakeFiles/SOArrayList.dir/main.cpp.obj
SOArrayList.exe: CMakeFiles/SOArrayList.dir/build.make
SOArrayList.exe: CMakeFiles/SOArrayList.dir/linklibs.rsp
SOArrayList.exe: CMakeFiles/SOArrayList.dir/objects1.rsp
SOArrayList.exe: CMakeFiles/SOArrayList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SOArrayList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SOArrayList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SOArrayList.dir/build: SOArrayList.exe

.PHONY : CMakeFiles/SOArrayList.dir/build

CMakeFiles/SOArrayList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SOArrayList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SOArrayList.dir/clean

CMakeFiles/SOArrayList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\istil\Desktop\gg\DataStructures\SOArrayList C:\Users\istil\Desktop\gg\DataStructures\SOArrayList C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\cmake-build-debug C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\cmake-build-debug C:\Users\istil\Desktop\gg\DataStructures\SOArrayList\cmake-build-debug\CMakeFiles\SOArrayList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SOArrayList.dir/depend

