# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\programming\lab02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\programming\lab02

# Include any dependencies generated for this target.
include CMakeFiles/lab02_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab02_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab02_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab02_tests.dir/flags.make

CMakeFiles/lab02_tests.dir/gtests/tests.cpp.obj: CMakeFiles/lab02_tests.dir/flags.make
CMakeFiles/lab02_tests.dir/gtests/tests.cpp.obj: CMakeFiles/lab02_tests.dir/includes_CXX.rsp
CMakeFiles/lab02_tests.dir/gtests/tests.cpp.obj: gtests/tests.cpp
CMakeFiles/lab02_tests.dir/gtests/tests.cpp.obj: CMakeFiles/lab02_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\programming\lab02\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab02_tests.dir/gtests/tests.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab02_tests.dir/gtests/tests.cpp.obj -MF CMakeFiles\lab02_tests.dir\gtests\tests.cpp.obj.d -o CMakeFiles\lab02_tests.dir\gtests\tests.cpp.obj -c C:\programming\lab02\gtests\tests.cpp

CMakeFiles/lab02_tests.dir/gtests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab02_tests.dir/gtests/tests.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\programming\lab02\gtests\tests.cpp > CMakeFiles\lab02_tests.dir\gtests\tests.cpp.i

CMakeFiles/lab02_tests.dir/gtests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab02_tests.dir/gtests/tests.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\programming\lab02\gtests\tests.cpp -o CMakeFiles\lab02_tests.dir\gtests\tests.cpp.s

# Object files for target lab02_tests
lab02_tests_OBJECTS = \
"CMakeFiles/lab02_tests.dir/gtests/tests.cpp.obj"

# External object files for target lab02_tests
lab02_tests_EXTERNAL_OBJECTS =

lab02_tests.exe: CMakeFiles/lab02_tests.dir/gtests/tests.cpp.obj
lab02_tests.exe: CMakeFiles/lab02_tests.dir/build.make
lab02_tests.exe: CMakeFiles/lab02_tests.dir/linkLibs.rsp
lab02_tests.exe: CMakeFiles/lab02_tests.dir/objects1.rsp
lab02_tests.exe: CMakeFiles/lab02_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\programming\lab02\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab02_tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab02_tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab02_tests.dir/build: lab02_tests.exe
.PHONY : CMakeFiles/lab02_tests.dir/build

CMakeFiles/lab02_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab02_tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab02_tests.dir/clean

CMakeFiles/lab02_tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\programming\lab02 C:\programming\lab02 C:\programming\lab02 C:\programming\lab02 C:\programming\lab02\CMakeFiles\lab02_tests.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab02_tests.dir/depend

