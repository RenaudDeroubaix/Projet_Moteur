# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build

# Include any dependencies generated for this target.
include CMakeFiles/TP4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP4.dir/flags.make

CMakeFiles/TP4.dir/main.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP4.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/main.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/main.cpp

CMakeFiles/TP4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/main.cpp > CMakeFiles/TP4.dir/main.cpp.i

CMakeFiles/TP4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/main.cpp -o CMakeFiles/TP4.dir/main.cpp.s

CMakeFiles/TP4.dir/common/shader.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/shader.cpp.o: ../common/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TP4.dir/common/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/shader.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/shader.cpp

CMakeFiles/TP4.dir/common/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/shader.cpp > CMakeFiles/TP4.dir/common/shader.cpp.i

CMakeFiles/TP4.dir/common/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/shader.cpp -o CMakeFiles/TP4.dir/common/shader.cpp.s

CMakeFiles/TP4.dir/common/texture.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/texture.cpp.o: ../common/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TP4.dir/common/texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/texture.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/texture.cpp

CMakeFiles/TP4.dir/common/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/texture.cpp > CMakeFiles/TP4.dir/common/texture.cpp.i

CMakeFiles/TP4.dir/common/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/texture.cpp -o CMakeFiles/TP4.dir/common/texture.cpp.s

CMakeFiles/TP4.dir/common/vboindexer.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/vboindexer.cpp.o: ../common/vboindexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TP4.dir/common/vboindexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/vboindexer.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/vboindexer.cpp

CMakeFiles/TP4.dir/common/vboindexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/vboindexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/vboindexer.cpp > CMakeFiles/TP4.dir/common/vboindexer.cpp.i

CMakeFiles/TP4.dir/common/vboindexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/vboindexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/vboindexer.cpp -o CMakeFiles/TP4.dir/common/vboindexer.cpp.s

CMakeFiles/TP4.dir/common/Renderer.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/Renderer.cpp.o: ../common/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TP4.dir/common/Renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/Renderer.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Renderer.cpp

CMakeFiles/TP4.dir/common/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Renderer.cpp > CMakeFiles/TP4.dir/common/Renderer.cpp.i

CMakeFiles/TP4.dir/common/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Renderer.cpp -o CMakeFiles/TP4.dir/common/Renderer.cpp.s

CMakeFiles/TP4.dir/common/Graph.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/Graph.cpp.o: ../common/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TP4.dir/common/Graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/Graph.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Graph.cpp

CMakeFiles/TP4.dir/common/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Graph.cpp > CMakeFiles/TP4.dir/common/Graph.cpp.i

CMakeFiles/TP4.dir/common/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Graph.cpp -o CMakeFiles/TP4.dir/common/Graph.cpp.s

CMakeFiles/TP4.dir/common/Scene.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/Scene.cpp.o: ../common/Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TP4.dir/common/Scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/Scene.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Scene.cpp

CMakeFiles/TP4.dir/common/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Scene.cpp > CMakeFiles/TP4.dir/common/Scene.cpp.i

CMakeFiles/TP4.dir/common/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Scene.cpp -o CMakeFiles/TP4.dir/common/Scene.cpp.s

CMakeFiles/TP4.dir/common/GameObject.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/GameObject.cpp.o: ../common/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TP4.dir/common/GameObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/GameObject.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/GameObject.cpp

CMakeFiles/TP4.dir/common/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/GameObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/GameObject.cpp > CMakeFiles/TP4.dir/common/GameObject.cpp.i

CMakeFiles/TP4.dir/common/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/GameObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/GameObject.cpp -o CMakeFiles/TP4.dir/common/GameObject.cpp.s

CMakeFiles/TP4.dir/common/Plan.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/Plan.cpp.o: ../common/Plan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TP4.dir/common/Plan.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/Plan.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Plan.cpp

CMakeFiles/TP4.dir/common/Plan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/Plan.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Plan.cpp > CMakeFiles/TP4.dir/common/Plan.cpp.i

CMakeFiles/TP4.dir/common/Plan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/Plan.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Plan.cpp -o CMakeFiles/TP4.dir/common/Plan.cpp.s

CMakeFiles/TP4.dir/common/Mesh.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/Mesh.cpp.o: ../common/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TP4.dir/common/Mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/Mesh.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Mesh.cpp

CMakeFiles/TP4.dir/common/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Mesh.cpp > CMakeFiles/TP4.dir/common/Mesh.cpp.i

CMakeFiles/TP4.dir/common/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Mesh.cpp -o CMakeFiles/TP4.dir/common/Mesh.cpp.s

CMakeFiles/TP4.dir/common/Camera.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/Camera.cpp.o: ../common/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/TP4.dir/common/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/Camera.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Camera.cpp

CMakeFiles/TP4.dir/common/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Camera.cpp > CMakeFiles/TP4.dir/common/Camera.cpp.i

CMakeFiles/TP4.dir/common/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/Camera.cpp -o CMakeFiles/TP4.dir/common/Camera.cpp.s

CMakeFiles/TP4.dir/common/InputManager.cpp.o: CMakeFiles/TP4.dir/flags.make
CMakeFiles/TP4.dir/common/InputManager.cpp.o: ../common/InputManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/TP4.dir/common/InputManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4.dir/common/InputManager.cpp.o -c /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/InputManager.cpp

CMakeFiles/TP4.dir/common/InputManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4.dir/common/InputManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/InputManager.cpp > CMakeFiles/TP4.dir/common/InputManager.cpp.i

CMakeFiles/TP4.dir/common/InputManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4.dir/common/InputManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/common/InputManager.cpp -o CMakeFiles/TP4.dir/common/InputManager.cpp.s

# Object files for target TP4
TP4_OBJECTS = \
"CMakeFiles/TP4.dir/main.cpp.o" \
"CMakeFiles/TP4.dir/common/shader.cpp.o" \
"CMakeFiles/TP4.dir/common/texture.cpp.o" \
"CMakeFiles/TP4.dir/common/vboindexer.cpp.o" \
"CMakeFiles/TP4.dir/common/Renderer.cpp.o" \
"CMakeFiles/TP4.dir/common/Graph.cpp.o" \
"CMakeFiles/TP4.dir/common/Scene.cpp.o" \
"CMakeFiles/TP4.dir/common/GameObject.cpp.o" \
"CMakeFiles/TP4.dir/common/Plan.cpp.o" \
"CMakeFiles/TP4.dir/common/Mesh.cpp.o" \
"CMakeFiles/TP4.dir/common/Camera.cpp.o" \
"CMakeFiles/TP4.dir/common/InputManager.cpp.o"

# External object files for target TP4
TP4_EXTERNAL_OBJECTS =

TP4: CMakeFiles/TP4.dir/main.cpp.o
TP4: CMakeFiles/TP4.dir/common/shader.cpp.o
TP4: CMakeFiles/TP4.dir/common/texture.cpp.o
TP4: CMakeFiles/TP4.dir/common/vboindexer.cpp.o
TP4: CMakeFiles/TP4.dir/common/Renderer.cpp.o
TP4: CMakeFiles/TP4.dir/common/Graph.cpp.o
TP4: CMakeFiles/TP4.dir/common/Scene.cpp.o
TP4: CMakeFiles/TP4.dir/common/GameObject.cpp.o
TP4: CMakeFiles/TP4.dir/common/Plan.cpp.o
TP4: CMakeFiles/TP4.dir/common/Mesh.cpp.o
TP4: CMakeFiles/TP4.dir/common/Camera.cpp.o
TP4: CMakeFiles/TP4.dir/common/InputManager.cpp.o
TP4: CMakeFiles/TP4.dir/build.make
TP4: /usr/lib/x86_64-linux-gnu/libGL.so
TP4: /usr/lib/x86_64-linux-gnu/libGLU.so
TP4: external/glfw-3.1.2/src/libglfw3.a
TP4: external/libGLEW_1130.a
TP4: /usr/lib/x86_64-linux-gnu/librt.so
TP4: /usr/lib/x86_64-linux-gnu/libm.so
TP4: /usr/lib/x86_64-linux-gnu/libX11.so
TP4: /usr/lib/x86_64-linux-gnu/libXrandr.so
TP4: /usr/lib/x86_64-linux-gnu/libXinerama.so
TP4: /usr/lib/x86_64-linux-gnu/libXi.so
TP4: /usr/lib/x86_64-linux-gnu/libXcursor.so
TP4: /usr/lib/x86_64-linux-gnu/librt.so
TP4: /usr/lib/x86_64-linux-gnu/libm.so
TP4: /usr/lib/x86_64-linux-gnu/libX11.so
TP4: /usr/lib/x86_64-linux-gnu/libXrandr.so
TP4: /usr/lib/x86_64-linux-gnu/libXinerama.so
TP4: /usr/lib/x86_64-linux-gnu/libXi.so
TP4: /usr/lib/x86_64-linux-gnu/libXcursor.so
TP4: /usr/lib/x86_64-linux-gnu/libGL.so
TP4: /usr/lib/x86_64-linux-gnu/libGLU.so
TP4: CMakeFiles/TP4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable TP4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP4.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/. /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code

# Rule to build all files generated by this target.
CMakeFiles/TP4.dir/build: TP4

.PHONY : CMakeFiles/TP4.dir/build

CMakeFiles/TP4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP4.dir/clean

CMakeFiles/TP4.dir/depend:
	cd /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build /home/orenu/Documents/Cours/OpenGl/TPs/TP4_code/build/CMakeFiles/TP4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP4.dir/depend

