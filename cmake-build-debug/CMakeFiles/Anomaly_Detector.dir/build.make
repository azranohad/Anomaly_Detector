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
CMAKE_COMMAND = /cygdrive/c/Users/azran/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/azran/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Anomaly_Detector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Anomaly_Detector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Anomaly_Detector.dir/flags.make

CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.o: CMakeFiles/Anomaly_Detector.dir/flags.make
CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.o: ../MainTrain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.o -c "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/MainTrain.cpp"

CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/MainTrain.cpp" > CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.i

CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/MainTrain.cpp" -o CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.s

CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.o: CMakeFiles/Anomaly_Detector.dir/flags.make
CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.o: ../anomaly_detection_util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.o -c "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/anomaly_detection_util.cpp"

CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/anomaly_detection_util.cpp" > CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.i

CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/anomaly_detection_util.cpp" -o CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.s

CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.o: CMakeFiles/Anomaly_Detector.dir/flags.make
CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.o: ../SimpleAnomalyDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.o -c "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/SimpleAnomalyDetector.cpp"

CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/SimpleAnomalyDetector.cpp" > CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.i

CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/SimpleAnomalyDetector.cpp" -o CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.s

CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.o: CMakeFiles/Anomaly_Detector.dir/flags.make
CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.o: ../HybridAnomalyDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.o -c "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/HybridAnomalyDetector.cpp"

CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/HybridAnomalyDetector.cpp" > CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.i

CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/HybridAnomalyDetector.cpp" -o CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.s

CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.o: CMakeFiles/Anomaly_Detector.dir/flags.make
CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.o: ../timeseries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.o -c "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/timeseries.cpp"

CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/timeseries.cpp" > CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.i

CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/timeseries.cpp" -o CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.s

CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.o: CMakeFiles/Anomaly_Detector.dir/flags.make
CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.o: ../minCircle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.o -c "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/minCircle.cpp"

CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/minCircle.cpp" > CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.i

CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/minCircle.cpp" -o CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.s

CMakeFiles/Anomaly_Detector.dir/CLI.cpp.o: CMakeFiles/Anomaly_Detector.dir/flags.make
CMakeFiles/Anomaly_Detector.dir/CLI.cpp.o: ../CLI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Anomaly_Detector.dir/CLI.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Anomaly_Detector.dir/CLI.cpp.o -c "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/CLI.cpp"

CMakeFiles/Anomaly_Detector.dir/CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Anomaly_Detector.dir/CLI.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/CLI.cpp" > CMakeFiles/Anomaly_Detector.dir/CLI.cpp.i

CMakeFiles/Anomaly_Detector.dir/CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Anomaly_Detector.dir/CLI.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/CLI.cpp" -o CMakeFiles/Anomaly_Detector.dir/CLI.cpp.s

# Object files for target Anomaly_Detector
Anomaly_Detector_OBJECTS = \
"CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.o" \
"CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.o" \
"CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.o" \
"CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.o" \
"CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.o" \
"CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.o" \
"CMakeFiles/Anomaly_Detector.dir/CLI.cpp.o"

# External object files for target Anomaly_Detector
Anomaly_Detector_EXTERNAL_OBJECTS =

Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/MainTrain.cpp.o
Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/anomaly_detection_util.cpp.o
Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/SimpleAnomalyDetector.cpp.o
Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/HybridAnomalyDetector.cpp.o
Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/timeseries.cpp.o
Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/minCircle.cpp.o
Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/CLI.cpp.o
Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/build.make
Anomaly_Detector.exe: CMakeFiles/Anomaly_Detector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Anomaly_Detector.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Anomaly_Detector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Anomaly_Detector.dir/build: Anomaly_Detector.exe

.PHONY : CMakeFiles/Anomaly_Detector.dir/build

CMakeFiles/Anomaly_Detector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Anomaly_Detector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Anomaly_Detector.dir/clean

CMakeFiles/Anomaly_Detector.dir/depend:
	cd "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector" "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector" "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug" "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug" "/cygdrive/c/Users/azran/CLionProjects/Anomaly Detector/cmake-build-debug/CMakeFiles/Anomaly_Detector.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Anomaly_Detector.dir/depend

