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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Jim\OneDrive\Desktop\DnD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Jim\OneDrive\Desktop\DnD\build

# Include any dependencies generated for this target.
include src/D&D/CMakeFiles/glfw3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/D&D/CMakeFiles/glfw3.dir/compiler_depend.make

# Include the progress variables for this target.
include src/D&D/CMakeFiles/glfw3.dir/progress.make

# Include the compile flags for this target's objects.
include src/D&D/CMakeFiles/glfw3.dir/flags.make

# Object files for target glfw3
glfw3_OBJECTS =

# External object files for target glfw3
glfw3_EXTERNAL_OBJECTS =

src/D&D/libglfw3.a: src/D&D/CMakeFiles/glfw3.dir/build.make
src/D&D/libglfw3.a: src/D&D/CMakeFiles/glfw3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Jim\OneDrive\Desktop\DnD\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking C static library libglfw3.a"
	cd /d "C:\Users\Jim\OneDrive\Desktop\DnD\build\src\D&D" && $(CMAKE_COMMAND) -P CMakeFiles\glfw3.dir\cmake_clean_target.cmake
	cd /d "C:\Users\Jim\OneDrive\Desktop\DnD\build\src\D&D" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glfw3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/D&D/CMakeFiles/glfw3.dir/build: src/D&D/libglfw3.a
.PHONY : src/D&D/CMakeFiles/glfw3.dir/build

src/D&D/CMakeFiles/glfw3.dir/clean:
	cd /d "C:\Users\Jim\OneDrive\Desktop\DnD\build\src\D&D" && $(CMAKE_COMMAND) -P CMakeFiles\glfw3.dir\cmake_clean.cmake
.PHONY : src/D&D/CMakeFiles/glfw3.dir/clean

src/D&D/CMakeFiles/glfw3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Jim\OneDrive\Desktop\DnD "C:\Users\Jim\OneDrive\Desktop\DnD\src\D&D" C:\Users\Jim\OneDrive\Desktop\DnD\build "C:\Users\Jim\OneDrive\Desktop\DnD\build\src\D&D" "C:\Users\Jim\OneDrive\Desktop\DnD\build\src\D&D\CMakeFiles\glfw3.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/D&D/CMakeFiles/glfw3.dir/depend
