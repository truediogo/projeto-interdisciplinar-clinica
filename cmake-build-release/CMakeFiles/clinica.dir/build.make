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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\diogo\projeto-interdisciplinar-clinica

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/clinica.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/clinica.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clinica.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clinica.dir/flags.make

CMakeFiles/clinica.dir/main.c.obj: CMakeFiles/clinica.dir/flags.make
CMakeFiles/clinica.dir/main.c.obj: C:/Users/diogo/projeto-interdisciplinar-clinica/main.c
CMakeFiles/clinica.dir/main.c.obj: CMakeFiles/clinica.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/clinica.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/clinica.dir/main.c.obj -MF CMakeFiles\clinica.dir\main.c.obj.d -o CMakeFiles\clinica.dir\main.c.obj -c C:\Users\diogo\projeto-interdisciplinar-clinica\main.c

CMakeFiles/clinica.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/clinica.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\diogo\projeto-interdisciplinar-clinica\main.c > CMakeFiles\clinica.dir\main.c.i

CMakeFiles/clinica.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/clinica.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\diogo\projeto-interdisciplinar-clinica\main.c -o CMakeFiles\clinica.dir\main.c.s

CMakeFiles/clinica.dir/lib/validacoes.c.obj: CMakeFiles/clinica.dir/flags.make
CMakeFiles/clinica.dir/lib/validacoes.c.obj: C:/Users/diogo/projeto-interdisciplinar-clinica/lib/validacoes.c
CMakeFiles/clinica.dir/lib/validacoes.c.obj: CMakeFiles/clinica.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/clinica.dir/lib/validacoes.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/clinica.dir/lib/validacoes.c.obj -MF CMakeFiles\clinica.dir\lib\validacoes.c.obj.d -o CMakeFiles\clinica.dir\lib\validacoes.c.obj -c C:\Users\diogo\projeto-interdisciplinar-clinica\lib\validacoes.c

CMakeFiles/clinica.dir/lib/validacoes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/clinica.dir/lib/validacoes.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\diogo\projeto-interdisciplinar-clinica\lib\validacoes.c > CMakeFiles\clinica.dir\lib\validacoes.c.i

CMakeFiles/clinica.dir/lib/validacoes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/clinica.dir/lib/validacoes.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\diogo\projeto-interdisciplinar-clinica\lib\validacoes.c -o CMakeFiles\clinica.dir\lib\validacoes.c.s

CMakeFiles/clinica.dir/lib/estrutura.c.obj: CMakeFiles/clinica.dir/flags.make
CMakeFiles/clinica.dir/lib/estrutura.c.obj: C:/Users/diogo/projeto-interdisciplinar-clinica/lib/estrutura.c
CMakeFiles/clinica.dir/lib/estrutura.c.obj: CMakeFiles/clinica.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/clinica.dir/lib/estrutura.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/clinica.dir/lib/estrutura.c.obj -MF CMakeFiles\clinica.dir\lib\estrutura.c.obj.d -o CMakeFiles\clinica.dir\lib\estrutura.c.obj -c C:\Users\diogo\projeto-interdisciplinar-clinica\lib\estrutura.c

CMakeFiles/clinica.dir/lib/estrutura.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/clinica.dir/lib/estrutura.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\diogo\projeto-interdisciplinar-clinica\lib\estrutura.c > CMakeFiles\clinica.dir\lib\estrutura.c.i

CMakeFiles/clinica.dir/lib/estrutura.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/clinica.dir/lib/estrutura.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\diogo\projeto-interdisciplinar-clinica\lib\estrutura.c -o CMakeFiles\clinica.dir\lib\estrutura.c.s

CMakeFiles/clinica.dir/aplicacao.c.obj: CMakeFiles/clinica.dir/flags.make
CMakeFiles/clinica.dir/aplicacao.c.obj: C:/Users/diogo/projeto-interdisciplinar-clinica/aplicacao.c
CMakeFiles/clinica.dir/aplicacao.c.obj: CMakeFiles/clinica.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/clinica.dir/aplicacao.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/clinica.dir/aplicacao.c.obj -MF CMakeFiles\clinica.dir\aplicacao.c.obj.d -o CMakeFiles\clinica.dir\aplicacao.c.obj -c C:\Users\diogo\projeto-interdisciplinar-clinica\aplicacao.c

CMakeFiles/clinica.dir/aplicacao.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/clinica.dir/aplicacao.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\diogo\projeto-interdisciplinar-clinica\aplicacao.c > CMakeFiles\clinica.dir\aplicacao.c.i

CMakeFiles/clinica.dir/aplicacao.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/clinica.dir/aplicacao.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\diogo\projeto-interdisciplinar-clinica\aplicacao.c -o CMakeFiles\clinica.dir\aplicacao.c.s

# Object files for target clinica
clinica_OBJECTS = \
"CMakeFiles/clinica.dir/main.c.obj" \
"CMakeFiles/clinica.dir/lib/validacoes.c.obj" \
"CMakeFiles/clinica.dir/lib/estrutura.c.obj" \
"CMakeFiles/clinica.dir/aplicacao.c.obj"

# External object files for target clinica
clinica_EXTERNAL_OBJECTS =

clinica.exe: CMakeFiles/clinica.dir/main.c.obj
clinica.exe: CMakeFiles/clinica.dir/lib/validacoes.c.obj
clinica.exe: CMakeFiles/clinica.dir/lib/estrutura.c.obj
clinica.exe: CMakeFiles/clinica.dir/aplicacao.c.obj
clinica.exe: CMakeFiles/clinica.dir/build.make
clinica.exe: CMakeFiles/clinica.dir/linkLibs.rsp
clinica.exe: CMakeFiles/clinica.dir/objects1.rsp
clinica.exe: CMakeFiles/clinica.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable clinica.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\clinica.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clinica.dir/build: clinica.exe
.PHONY : CMakeFiles/clinica.dir/build

CMakeFiles/clinica.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\clinica.dir\cmake_clean.cmake
.PHONY : CMakeFiles/clinica.dir/clean

CMakeFiles/clinica.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\diogo\projeto-interdisciplinar-clinica C:\Users\diogo\projeto-interdisciplinar-clinica C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release C:\Users\diogo\projeto-interdisciplinar-clinica\cmake-build-release\CMakeFiles\clinica.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/clinica.dir/depend

