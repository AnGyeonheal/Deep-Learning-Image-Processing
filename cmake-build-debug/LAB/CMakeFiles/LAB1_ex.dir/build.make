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
include LAB\CMakeFiles\LAB1_ex.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include LAB\CMakeFiles\LAB1_ex.dir\compiler_depend.make

# Include the progress variables for this target.
include LAB\CMakeFiles\LAB1_ex.dir\progress.make

# Include the compile flags for this target's objects.
include LAB\CMakeFiles\LAB1_ex.dir\flags.make

LAB\CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.obj: LAB\CMakeFiles\LAB1_ex.dir\flags.make
LAB\CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.obj: C:\Users\heal\source\repos\DLIP_GH\LAB\LAB1_ex.cpp
LAB\CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.obj: LAB\CMakeFiles\LAB1_ex.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object LAB/CMakeFiles/LAB1_ex.dir/LAB1_ex.cpp.obj"
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.obj.d --working-dir=C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB --filter-prefix="����: ���� ����: " -- C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.obj /FdCMakeFiles\LAB1_ex.dir\ /FS -c C:\Users\heal\source\repos\DLIP_GH\LAB\LAB1_ex.cpp
<<
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

LAB\CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB1_ex.dir/LAB1_ex.cpp.i"
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe > CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\heal\source\repos\DLIP_GH\LAB\LAB1_ex.cpp
<<
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

LAB\CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB1_ex.dir/LAB1_ex.cpp.s"
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.s /c C:\Users\heal\source\repos\DLIP_GH\LAB\LAB1_ex.cpp
<<
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

# Object files for target LAB1_ex
LAB1_ex_OBJECTS = \
"CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.obj"

# External object files for target LAB1_ex
LAB1_ex_EXTERNAL_OBJECTS =

LAB\LAB1_ex.exe: LAB\CMakeFiles\LAB1_ex.dir\LAB1_ex.cpp.obj
LAB\LAB1_ex.exe: LAB\CMakeFiles\LAB1_ex.dir\build.make
LAB\LAB1_ex.exe: OpenCV.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: C:\opencv\build\x64\vc16\lib\opencv_world490d.lib
LAB\LAB1_ex.exe: LAB\CMakeFiles\LAB1_ex.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LAB1_ex.exe"
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB
	C:\Users\heal\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\LAB1_ex.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\mt.exe --manifests -- C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\LAB1_ex.dir\objects1.rsp @<<
 /out:LAB1_ex.exe /implib:LAB1_ex.lib /pdb:C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB\LAB1_ex.pdb /version:0.0 /machine:x64 /debug /INCREMENTAL /subsystem:console  ..\OpenCV.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib C:\opencv\build\x64\vc16\lib\opencv_world490d.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

# Rule to build all files generated by this target.
LAB\CMakeFiles\LAB1_ex.dir\build: LAB\LAB1_ex.exe
.PHONY : LAB\CMakeFiles\LAB1_ex.dir\build

LAB\CMakeFiles\LAB1_ex.dir\clean:
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB
	$(CMAKE_COMMAND) -P CMakeFiles\LAB1_ex.dir\cmake_clean.cmake
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug
.PHONY : LAB\CMakeFiles\LAB1_ex.dir\clean

LAB\CMakeFiles\LAB1_ex.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\heal\source\repos\DLIP_GH C:\Users\heal\source\repos\DLIP_GH\LAB C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB\CMakeFiles\LAB1_ex.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : LAB\CMakeFiles\LAB1_ex.dir\depend
