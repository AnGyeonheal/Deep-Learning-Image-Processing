# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\heal\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\heal\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\heal\source\repos\DLIP_GH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

# Include any dependencies generated for this target.
include Tutorial\CMakeFiles\HIST_1D.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include Tutorial\CMakeFiles\HIST_1D.dir\compiler_depend.make

# Include the progress variables for this target.
include Tutorial\CMakeFiles\HIST_1D.dir\progress.make

# Include the compile flags for this target's objects.
include Tutorial\CMakeFiles\HIST_1D.dir\flags.make

Tutorial\CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.obj: Tutorial\CMakeFiles\HIST_1D.dir\flags.make
Tutorial\CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.obj: C:\Users\heal\source\repos\DLIP_GH\Tutorial\DLIP_Tutorial_Histogram_1D_demo_image.cpp
Tutorial\CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.obj: Tutorial\CMakeFiles\HIST_1D.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tutorial/CMakeFiles/HIST_1D.dir/DLIP_Tutorial_Histogram_1D_demo_image.cpp.obj"
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.obj.d --working-dir=C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial --filter-prefix="참고: 포함 파일: " -- C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.obj /FdCMakeFiles\HIST_1D.dir\ /FS -c C:\Users\heal\source\repos\DLIP_GH\Tutorial\DLIP_Tutorial_Histogram_1D_demo_image.cpp
<<
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

Tutorial\CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HIST_1D.dir/DLIP_Tutorial_Histogram_1D_demo_image.cpp.i"
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe > CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\heal\source\repos\DLIP_GH\Tutorial\DLIP_Tutorial_Histogram_1D_demo_image.cpp
<<
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

Tutorial\CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HIST_1D.dir/DLIP_Tutorial_Histogram_1D_demo_image.cpp.s"
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.s /c C:\Users\heal\source\repos\DLIP_GH\Tutorial\DLIP_Tutorial_Histogram_1D_demo_image.cpp
<<
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

# Object files for target HIST_1D
HIST_1D_OBJECTS = \
"CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.obj"

# External object files for target HIST_1D
HIST_1D_EXTERNAL_OBJECTS =

Tutorial\HIST_1D.exe: Tutorial\CMakeFiles\HIST_1D.dir\DLIP_Tutorial_Histogram_1D_demo_image.cpp.obj
Tutorial\HIST_1D.exe: Tutorial\CMakeFiles\HIST_1D.dir\build.make
Tutorial\HIST_1D.exe: OpenCV.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
Tutorial\HIST_1D.exe: Tutorial\CMakeFiles\HIST_1D.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HIST_1D.exe"
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial
	C:\Users\heal\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\HIST_1D.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\mt.exe --manifests -- C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\HIST_1D.dir\objects1.rsp @<<
 /out:HIST_1D.exe /implib:HIST_1D.lib /pdb:C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial\HIST_1D.pdb /version:0.0 /machine:x64 /debug /INCREMENTAL /subsystem:console  ..\OpenCV.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

# Rule to build all files generated by this target.
Tutorial\CMakeFiles\HIST_1D.dir\build: Tutorial\HIST_1D.exe
.PHONY : Tutorial\CMakeFiles\HIST_1D.dir\build

Tutorial\CMakeFiles\HIST_1D.dir\clean:
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial
	$(CMAKE_COMMAND) -P CMakeFiles\HIST_1D.dir\cmake_clean.cmake
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug
.PHONY : Tutorial\CMakeFiles\HIST_1D.dir\clean

Tutorial\CMakeFiles\HIST_1D.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\heal\source\repos\DLIP_GH C:\Users\heal\source\repos\DLIP_GH\Tutorial C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\Tutorial\CMakeFiles\HIST_1D.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Tutorial\CMakeFiles\HIST_1D.dir\depend

