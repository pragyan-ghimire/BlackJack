# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\c++(blackjack)

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\c++(blackjack)\build

# Include any dependencies generated for this target.
include CMakeFiles/CMakeSFMLProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CMakeSFMLProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CMakeSFMLProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CMakeSFMLProject.dir/flags.make

CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/flags.make
CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/includes_CXX.rsp
CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.obj: E:/c++(blackjack)/src/dealScreen.cpp
CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c++(blackjack)\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.obj -MF CMakeFiles\CMakeSFMLProject.dir\src\dealScreen.cpp.obj.d -o CMakeFiles\CMakeSFMLProject.dir\src\dealScreen.cpp.obj -c E:\c++(blackjack)\src\dealScreen.cpp

CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c++(blackjack)\src\dealScreen.cpp > CMakeFiles\CMakeSFMLProject.dir\src\dealScreen.cpp.i

CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c++(blackjack)\src\dealScreen.cpp -o CMakeFiles\CMakeSFMLProject.dir\src\dealScreen.cpp.s

CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/flags.make
CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/includes_CXX.rsp
CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.obj: E:/c++(blackjack)/src/Menu.cpp
CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c++(blackjack)\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.obj -MF CMakeFiles\CMakeSFMLProject.dir\src\Menu.cpp.obj.d -o CMakeFiles\CMakeSFMLProject.dir\src\Menu.cpp.obj -c E:\c++(blackjack)\src\Menu.cpp

CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c++(blackjack)\src\Menu.cpp > CMakeFiles\CMakeSFMLProject.dir\src\Menu.cpp.i

CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c++(blackjack)\src\Menu.cpp -o CMakeFiles\CMakeSFMLProject.dir\src\Menu.cpp.s

CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/flags.make
CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/includes_CXX.rsp
CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj: E:/c++(blackjack)/src/main.cpp
CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c++(blackjack)\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj -MF CMakeFiles\CMakeSFMLProject.dir\src\main.cpp.obj.d -o CMakeFiles\CMakeSFMLProject.dir\src\main.cpp.obj -c E:\c++(blackjack)\src\main.cpp

CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c++(blackjack)\src\main.cpp > CMakeFiles\CMakeSFMLProject.dir\src\main.cpp.i

CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c++(blackjack)\src\main.cpp -o CMakeFiles\CMakeSFMLProject.dir\src\main.cpp.s

CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/flags.make
CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/includes_CXX.rsp
CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.obj: E:/c++(blackjack)/src/login.cpp
CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c++(blackjack)\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.obj -MF CMakeFiles\CMakeSFMLProject.dir\src\login.cpp.obj.d -o CMakeFiles\CMakeSFMLProject.dir\src\login.cpp.obj -c E:\c++(blackjack)\src\login.cpp

CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c++(blackjack)\src\login.cpp > CMakeFiles\CMakeSFMLProject.dir\src\login.cpp.i

CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c++(blackjack)\src\login.cpp -o CMakeFiles\CMakeSFMLProject.dir\src\login.cpp.s

# Object files for target CMakeSFMLProject
CMakeSFMLProject_OBJECTS = \
"CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.obj" \
"CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.obj" \
"CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj" \
"CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.obj"

# External object files for target CMakeSFMLProject
CMakeSFMLProject_EXTERNAL_OBJECTS =

bin/CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/src/dealScreen.cpp.obj
bin/CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/src/Menu.cpp.obj
bin/CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj
bin/CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/src/login.cpp.obj
bin/CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/build.make
bin/CMakeSFMLProject.exe: _deps/sfml-build/lib/libsfml-graphics-s-d.a
bin/CMakeSFMLProject.exe: _deps/sfml-build/lib/libsfml-window-s-d.a
bin/CMakeSFMLProject.exe: _deps/sfml-build/lib/libsfml-system-s-d.a
bin/CMakeSFMLProject.exe: _deps/sfml-src/extlibs/libs-mingw/x86/libfreetype.a
bin/CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/linkLibs.rsp
bin/CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/objects1.rsp
bin/CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\c++(blackjack)\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin\CMakeSFMLProject.exe"
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copy OpenAL DLL"
	"C:\Program Files (x86)\CMake\bin\cmake.exe" -E copy E:/c++(blackjack)/build/_deps/sfml-src/extlibs/bin/x86/openal32.dll E:/c++(blackjack)/build/bin
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CMakeSFMLProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CMakeSFMLProject.dir/build: bin/CMakeSFMLProject.exe
.PHONY : CMakeFiles/CMakeSFMLProject.dir/build

CMakeFiles/CMakeSFMLProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CMakeSFMLProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CMakeSFMLProject.dir/clean

CMakeFiles/CMakeSFMLProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\c++(blackjack) E:\c++(blackjack) E:\c++(blackjack)\build E:\c++(blackjack)\build E:\c++(blackjack)\build\CMakeFiles\CMakeSFMLProject.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CMakeSFMLProject.dir/depend

