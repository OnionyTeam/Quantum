# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/momo/workspace/Quantum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/momo/workspace/Quantum

# Include any dependencies generated for this target.
include src/quantum/CMakeFiles/Quantum.dir/depend.make

# Include the progress variables for this target.
include src/quantum/CMakeFiles/Quantum.dir/progress.make

# Include the compile flags for this target's objects.
include src/quantum/CMakeFiles/Quantum.dir/flags.make

src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o: src/quantum/buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/buffer.cpp.o -c /home/momo/workspace/Quantum/src/quantum/buffer.cpp

src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/buffer.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/buffer.cpp > CMakeFiles/Quantum.dir/buffer.cpp.i

src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/buffer.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/buffer.cpp -o CMakeFiles/Quantum.dir/buffer.cpp.s

src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o


src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o: src/quantum/command/command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/command/command.cpp.o -c /home/momo/workspace/Quantum/src/quantum/command/command.cpp

src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/command/command.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/command/command.cpp > CMakeFiles/Quantum.dir/command/command.cpp.i

src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/command/command.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/command/command.cpp -o CMakeFiles/Quantum.dir/command/command.cpp.s

src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o


src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o: src/quantum/components/status_line.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/components/status_line.cpp.o -c /home/momo/workspace/Quantum/src/quantum/components/status_line.cpp

src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/components/status_line.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/components/status_line.cpp > CMakeFiles/Quantum.dir/components/status_line.cpp.i

src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/components/status_line.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/components/status_line.cpp -o CMakeFiles/Quantum.dir/components/status_line.cpp.s

src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o


src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o: src/quantum/draw/draw_helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o -c /home/momo/workspace/Quantum/src/quantum/draw/draw_helper.cpp

src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/draw/draw_helper.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/draw/draw_helper.cpp > CMakeFiles/Quantum.dir/draw/draw_helper.cpp.i

src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/draw/draw_helper.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/draw/draw_helper.cpp -o CMakeFiles/Quantum.dir/draw/draw_helper.cpp.s

src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o


src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o: src/quantum/editor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/editor.cpp.o -c /home/momo/workspace/Quantum/src/quantum/editor.cpp

src/quantum/CMakeFiles/Quantum.dir/editor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/editor.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/editor.cpp > CMakeFiles/Quantum.dir/editor.cpp.i

src/quantum/CMakeFiles/Quantum.dir/editor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/editor.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/editor.cpp -o CMakeFiles/Quantum.dir/editor.cpp.s

src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o


src/quantum/CMakeFiles/Quantum.dir/main.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/main.cpp.o: src/quantum/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/main.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/main.cpp.o -c /home/momo/workspace/Quantum/src/quantum/main.cpp

src/quantum/CMakeFiles/Quantum.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/main.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/main.cpp > CMakeFiles/Quantum.dir/main.cpp.i

src/quantum/CMakeFiles/Quantum.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/main.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/main.cpp -o CMakeFiles/Quantum.dir/main.cpp.s

src/quantum/CMakeFiles/Quantum.dir/main.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/main.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/main.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/main.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/main.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/main.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/main.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/main.cpp.o


src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o: src/quantum/quantum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/quantum.cpp.o -c /home/momo/workspace/Quantum/src/quantum/quantum.cpp

src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/quantum.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/quantum.cpp > CMakeFiles/Quantum.dir/quantum.cpp.i

src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/quantum.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/quantum.cpp -o CMakeFiles/Quantum.dir/quantum.cpp.s

src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o


src/quantum/CMakeFiles/Quantum.dir/view.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/view.cpp.o: src/quantum/view.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/view.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/view.cpp.o -c /home/momo/workspace/Quantum/src/quantum/view.cpp

src/quantum/CMakeFiles/Quantum.dir/view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/view.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/view.cpp > CMakeFiles/Quantum.dir/view.cpp.i

src/quantum/CMakeFiles/Quantum.dir/view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/view.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/view.cpp -o CMakeFiles/Quantum.dir/view.cpp.s

src/quantum/CMakeFiles/Quantum.dir/view.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/view.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/view.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/view.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/view.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/view.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/view.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/view.cpp.o


src/quantum/CMakeFiles/Quantum.dir/window.cpp.o: src/quantum/CMakeFiles/Quantum.dir/flags.make
src/quantum/CMakeFiles/Quantum.dir/window.cpp.o: src/quantum/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/quantum/CMakeFiles/Quantum.dir/window.cpp.o"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantum.dir/window.cpp.o -c /home/momo/workspace/Quantum/src/quantum/window.cpp

src/quantum/CMakeFiles/Quantum.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantum.dir/window.cpp.i"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/momo/workspace/Quantum/src/quantum/window.cpp > CMakeFiles/Quantum.dir/window.cpp.i

src/quantum/CMakeFiles/Quantum.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantum.dir/window.cpp.s"
	cd /home/momo/workspace/Quantum/src/quantum && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/momo/workspace/Quantum/src/quantum/window.cpp -o CMakeFiles/Quantum.dir/window.cpp.s

src/quantum/CMakeFiles/Quantum.dir/window.cpp.o.requires:

.PHONY : src/quantum/CMakeFiles/Quantum.dir/window.cpp.o.requires

src/quantum/CMakeFiles/Quantum.dir/window.cpp.o.provides: src/quantum/CMakeFiles/Quantum.dir/window.cpp.o.requires
	$(MAKE) -f src/quantum/CMakeFiles/Quantum.dir/build.make src/quantum/CMakeFiles/Quantum.dir/window.cpp.o.provides.build
.PHONY : src/quantum/CMakeFiles/Quantum.dir/window.cpp.o.provides

src/quantum/CMakeFiles/Quantum.dir/window.cpp.o.provides.build: src/quantum/CMakeFiles/Quantum.dir/window.cpp.o


# Object files for target Quantum
Quantum_OBJECTS = \
"CMakeFiles/Quantum.dir/buffer.cpp.o" \
"CMakeFiles/Quantum.dir/command/command.cpp.o" \
"CMakeFiles/Quantum.dir/components/status_line.cpp.o" \
"CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o" \
"CMakeFiles/Quantum.dir/editor.cpp.o" \
"CMakeFiles/Quantum.dir/main.cpp.o" \
"CMakeFiles/Quantum.dir/quantum.cpp.o" \
"CMakeFiles/Quantum.dir/view.cpp.o" \
"CMakeFiles/Quantum.dir/window.cpp.o"

# External object files for target Quantum
Quantum_EXTERNAL_OBJECTS =

src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/main.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/view.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/window.cpp.o
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/build.make
src/quantum/Quantum: src/quantum/CMakeFiles/Quantum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/momo/workspace/Quantum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Quantum"
	cd /home/momo/workspace/Quantum/src/quantum && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Quantum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/quantum/CMakeFiles/Quantum.dir/build: src/quantum/Quantum

.PHONY : src/quantum/CMakeFiles/Quantum.dir/build

src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/buffer.cpp.o.requires
src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/command/command.cpp.o.requires
src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/components/status_line.cpp.o.requires
src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/draw/draw_helper.cpp.o.requires
src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/editor.cpp.o.requires
src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/main.cpp.o.requires
src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/quantum.cpp.o.requires
src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/view.cpp.o.requires
src/quantum/CMakeFiles/Quantum.dir/requires: src/quantum/CMakeFiles/Quantum.dir/window.cpp.o.requires

.PHONY : src/quantum/CMakeFiles/Quantum.dir/requires

src/quantum/CMakeFiles/Quantum.dir/clean:
	cd /home/momo/workspace/Quantum/src/quantum && $(CMAKE_COMMAND) -P CMakeFiles/Quantum.dir/cmake_clean.cmake
.PHONY : src/quantum/CMakeFiles/Quantum.dir/clean

src/quantum/CMakeFiles/Quantum.dir/depend:
	cd /home/momo/workspace/Quantum && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/momo/workspace/Quantum /home/momo/workspace/Quantum/src/quantum /home/momo/workspace/Quantum /home/momo/workspace/Quantum/src/quantum /home/momo/workspace/Quantum/src/quantum/CMakeFiles/Quantum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/quantum/CMakeFiles/Quantum.dir/depend

