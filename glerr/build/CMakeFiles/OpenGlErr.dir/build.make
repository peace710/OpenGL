# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "D:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\vsproject\workspace\opengl\glerr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\vsproject\workspace\opengl\glerr\build

# Include any dependencies generated for this target.
include CMakeFiles/OpenGlErr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGlErr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGlErr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGlErr.dir/flags.make

CMakeFiles/OpenGlErr.dir/src/glad.c.obj: CMakeFiles/OpenGlErr.dir/flags.make
CMakeFiles/OpenGlErr.dir/src/glad.c.obj: CMakeFiles/OpenGlErr.dir/includes_C.rsp
CMakeFiles/OpenGlErr.dir/src/glad.c.obj: E:/vsproject/workspace/opengl/glerr/src/glad.c
CMakeFiles/OpenGlErr.dir/src/glad.c.obj: CMakeFiles/OpenGlErr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\vsproject\workspace\opengl\glerr\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/OpenGlErr.dir/src/glad.c.obj"
	E:\vsproject\vs\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/OpenGlErr.dir/src/glad.c.obj -MF CMakeFiles\OpenGlErr.dir\src\glad.c.obj.d -o CMakeFiles\OpenGlErr.dir\src\glad.c.obj -c E:\vsproject\workspace\opengl\glerr\src\glad.c

CMakeFiles/OpenGlErr.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/OpenGlErr.dir/src/glad.c.i"
	E:\vsproject\vs\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\vsproject\workspace\opengl\glerr\src\glad.c > CMakeFiles\OpenGlErr.dir\src\glad.c.i

CMakeFiles/OpenGlErr.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/OpenGlErr.dir/src/glad.c.s"
	E:\vsproject\vs\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\vsproject\workspace\opengl\glerr\src\glad.c -o CMakeFiles\OpenGlErr.dir\src\glad.c.s

CMakeFiles/OpenGlErr.dir/src/opengl.cpp.obj: CMakeFiles/OpenGlErr.dir/flags.make
CMakeFiles/OpenGlErr.dir/src/opengl.cpp.obj: CMakeFiles/OpenGlErr.dir/includes_CXX.rsp
CMakeFiles/OpenGlErr.dir/src/opengl.cpp.obj: E:/vsproject/workspace/opengl/glerr/src/opengl.cpp
CMakeFiles/OpenGlErr.dir/src/opengl.cpp.obj: CMakeFiles/OpenGlErr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\vsproject\workspace\opengl\glerr\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGlErr.dir/src/opengl.cpp.obj"
	E:\vsproject\vs\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGlErr.dir/src/opengl.cpp.obj -MF CMakeFiles\OpenGlErr.dir\src\opengl.cpp.obj.d -o CMakeFiles\OpenGlErr.dir\src\opengl.cpp.obj -c E:\vsproject\workspace\opengl\glerr\src\opengl.cpp

CMakeFiles/OpenGlErr.dir/src/opengl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OpenGlErr.dir/src/opengl.cpp.i"
	E:\vsproject\vs\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\vsproject\workspace\opengl\glerr\src\opengl.cpp > CMakeFiles\OpenGlErr.dir\src\opengl.cpp.i

CMakeFiles/OpenGlErr.dir/src/opengl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OpenGlErr.dir/src/opengl.cpp.s"
	E:\vsproject\vs\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\vsproject\workspace\opengl\glerr\src\opengl.cpp -o CMakeFiles\OpenGlErr.dir\src\opengl.cpp.s

# Object files for target OpenGlErr
OpenGlErr_OBJECTS = \
"CMakeFiles/OpenGlErr.dir/src/glad.c.obj" \
"CMakeFiles/OpenGlErr.dir/src/opengl.cpp.obj"

# External object files for target OpenGlErr
OpenGlErr_EXTERNAL_OBJECTS =

OpenGlErr.exe: CMakeFiles/OpenGlErr.dir/src/glad.c.obj
OpenGlErr.exe: CMakeFiles/OpenGlErr.dir/src/opengl.cpp.obj
OpenGlErr.exe: CMakeFiles/OpenGlErr.dir/build.make
OpenGlErr.exe: include/wrapper/libwrapper.a
OpenGlErr.exe: CMakeFiles/OpenGlErr.dir/linkLibs.rsp
OpenGlErr.exe: CMakeFiles/OpenGlErr.dir/objects1.rsp
OpenGlErr.exe: CMakeFiles/OpenGlErr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\vsproject\workspace\opengl\glerr\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OpenGlErr.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OpenGlErr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGlErr.dir/build: OpenGlErr.exe
.PHONY : CMakeFiles/OpenGlErr.dir/build

CMakeFiles/OpenGlErr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OpenGlErr.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OpenGlErr.dir/clean

CMakeFiles/OpenGlErr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\vsproject\workspace\opengl\glerr E:\vsproject\workspace\opengl\glerr E:\vsproject\workspace\opengl\glerr\build E:\vsproject\workspace\opengl\glerr\build E:\vsproject\workspace\opengl\glerr\build\CMakeFiles\OpenGlErr.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OpenGlErr.dir/depend
