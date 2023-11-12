@echo off
setlocal enabledelayedexpansion




:: Select Option Based on Given Argument 
if "%1"=="-v" (
	echo Copyright ^(c^) Anri17
	echo All Rights Reserved
	echo Build Script - v0.1.0
	goto quit
)
if "%1"=="?" goto help
if "%1"=="help" goto help
if /i "%1"=="release" (	
	goto build_release
)
if /i "%1"=="debug" (
	goto build_debug
)
if /i "%1"=="clear" (
	goto clear
)
echo WARNING: Unknown Argument "%1".
echo Type "build ?" or "build help" for help.
goto quit


:: Display a help message
:help
echo Accepted Arguments:
echo help, ?         Display this help message
echo -v              Display copyright information and the script version
echo release         Builds a optimizsed executable for release (NOT IMPLEMENTED YET. DOES NOTHING AT THE MOMENT)
echo debug           Builds an executable with '-g3' flag for debugging purposes with dgb
echo clear           Clear the project folder
goto quit


:: Clear the project folder
:clear
echo 0) CLEARING PROJECT FOLDER ...
if exist bin echo Y|rmdir /s bin
if exist obj echo Y|rmdir /s obj
echo 0) [SUCCESS] CLEARING COMPLETE!
goto quit


:: Create output directory
:build_debug
echo 1) CREATING DIRECTORIES...
if not exist obj\debug\ (
	echo creating directory: obj\debug\
	mkdir obj\debug\
)
for /f "tokens=* usebackq delims=" %%x in ("srcdirs.txt") do (
	if not exist obj\debug\%%x (
		echo creating directory: obj\debug\%%x
		mkdir obj\debug\%%x
	)	
)
if not exist bin\debug\ (
	echo creating directory: bin\debug\
	mkdir bin\debug\
)
echo 1) [SUCCESS] CREATING DIRECTORIES COMPLETE!


:: Compile each source file into object files
echo 2) COMPILING...
for /f "tokens=* usebackq delims=" %%x in ("srcfiles.txt") do (
	if not exist "obj\debug\%%x.o" (
		echo compiling: %%x.c
		gcc -c -g3 "src\%%x.c" -o "obj\debug\%%x.o"
	)
)
echo 2) [SUCCESS] COMPILING COMPLETE!


:: Link object files and libraries
echo 3) LINKING...
set objs=
for /f "tokens=* usebackq delims=" %%x in ("srcfiles.txt") do (
	set objs=!objs! "obj\debug\%%x.o"
)
gcc -g3 %objs% -o "bin\debug\Programacao e Algoritmia.exe"
echo 3) [SUCCESS] LINKING COMPLETE!


:: Copy dependencies files
echo 4) COPYING DEPENDENCIES...
for /r %%x in (dependencies\*) do (
	if exist dependencies\%%~nx (
		if not exist bin\debug\%%~nx (
			copy %%x bin\debug\	
		)
	)
)
echo 4) [SUCCESS] COPYING DEPENDENCIES COMPLETE!
echo ----- DONE -----
GOTO quit


:build_release
GOTO quit


:quit