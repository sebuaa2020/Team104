# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/wangm/Team104/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wangm/Team104/build

# Include any dependencies generated for this target.
include xfyun_kinetic/CMakeFiles/iat_file.dir/depend.make

# Include the progress variables for this target.
include xfyun_kinetic/CMakeFiles/iat_file.dir/progress.make

# Include the compile flags for this target's objects.
include xfyun_kinetic/CMakeFiles/iat_file.dir/flags.make

xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o: xfyun_kinetic/CMakeFiles/iat_file.dir/flags.make
xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o: /home/wangm/Team104/src/xfyun_kinetic/src/iat_file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangm/Team104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iat_file.dir/src/iat_file.cpp.o -c /home/wangm/Team104/src/xfyun_kinetic/src/iat_file.cpp

xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iat_file.dir/src/iat_file.cpp.i"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangm/Team104/src/xfyun_kinetic/src/iat_file.cpp > CMakeFiles/iat_file.dir/src/iat_file.cpp.i

xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iat_file.dir/src/iat_file.cpp.s"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangm/Team104/src/xfyun_kinetic/src/iat_file.cpp -o CMakeFiles/iat_file.dir/src/iat_file.cpp.s

xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o.requires:

.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o.requires

xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o.provides: xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o.requires
	$(MAKE) -f xfyun_kinetic/CMakeFiles/iat_file.dir/build.make xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o.provides.build
.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o.provides

xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o.provides.build: xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o


xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o: xfyun_kinetic/CMakeFiles/iat_file.dir/flags.make
xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o: /home/wangm/Team104/src/xfyun_kinetic/src/xfyun/speech_recognizer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangm/Team104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o   -c /home/wangm/Team104/src/xfyun_kinetic/src/xfyun/speech_recognizer.c

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.i"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wangm/Team104/src/xfyun_kinetic/src/xfyun/speech_recognizer.c > CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.i

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.s"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wangm/Team104/src/xfyun_kinetic/src/xfyun/speech_recognizer.c -o CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.s

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o.requires:

.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o.requires

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o.provides: xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o.requires
	$(MAKE) -f xfyun_kinetic/CMakeFiles/iat_file.dir/build.make xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o.provides.build
.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o.provides

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o.provides.build: xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o


xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o: xfyun_kinetic/CMakeFiles/iat_file.dir/flags.make
xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o: /home/wangm/Team104/src/xfyun_kinetic/src/xfyun/linuxrec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangm/Team104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o   -c /home/wangm/Team104/src/xfyun_kinetic/src/xfyun/linuxrec.c

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.i"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wangm/Team104/src/xfyun_kinetic/src/xfyun/linuxrec.c > CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.i

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.s"
	cd /home/wangm/Team104/build/xfyun_kinetic && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wangm/Team104/src/xfyun_kinetic/src/xfyun/linuxrec.c -o CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.s

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o.requires:

.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o.requires

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o.provides: xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o.requires
	$(MAKE) -f xfyun_kinetic/CMakeFiles/iat_file.dir/build.make xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o.provides.build
.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o.provides

xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o.provides.build: xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o


# Object files for target iat_file
iat_file_OBJECTS = \
"CMakeFiles/iat_file.dir/src/iat_file.cpp.o" \
"CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o" \
"CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o"

# External object files for target iat_file
iat_file_EXTERNAL_OBJECTS =

/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: xfyun_kinetic/CMakeFiles/iat_file.dir/build.make
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/libroscpp.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/librosconsole.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/librostime.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/libcpp_common.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/libroscpp.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/librosconsole.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/librostime.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /opt/ros/kinetic/lib/libcpp_common.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file: xfyun_kinetic/CMakeFiles/iat_file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wangm/Team104/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable /home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file"
	cd /home/wangm/Team104/build/xfyun_kinetic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iat_file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
xfyun_kinetic/CMakeFiles/iat_file.dir/build: /home/wangm/Team104/devel/lib/xfyun_waterplus/iat_file

.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/build

xfyun_kinetic/CMakeFiles/iat_file.dir/requires: xfyun_kinetic/CMakeFiles/iat_file.dir/src/iat_file.cpp.o.requires
xfyun_kinetic/CMakeFiles/iat_file.dir/requires: xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/speech_recognizer.c.o.requires
xfyun_kinetic/CMakeFiles/iat_file.dir/requires: xfyun_kinetic/CMakeFiles/iat_file.dir/src/xfyun/linuxrec.c.o.requires

.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/requires

xfyun_kinetic/CMakeFiles/iat_file.dir/clean:
	cd /home/wangm/Team104/build/xfyun_kinetic && $(CMAKE_COMMAND) -P CMakeFiles/iat_file.dir/cmake_clean.cmake
.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/clean

xfyun_kinetic/CMakeFiles/iat_file.dir/depend:
	cd /home/wangm/Team104/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wangm/Team104/src /home/wangm/Team104/src/xfyun_kinetic /home/wangm/Team104/build /home/wangm/Team104/build/xfyun_kinetic /home/wangm/Team104/build/xfyun_kinetic/CMakeFiles/iat_file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : xfyun_kinetic/CMakeFiles/iat_file.dir/depend

