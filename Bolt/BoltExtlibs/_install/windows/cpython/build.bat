@echo off
echo /////////%0 start

cd %SRC_ROOT%/cpython/PCBuild

@echo on
call build.bat -r -e -v -k -c Release 	-p x64 		-t Rebuild
call build.bat -r -e -v -k -c Debug 	-p x64 		-t Rebuild
REM call build.bat -r -e -v -k -c Release 	-p Win32 	-t Rebuild
REM call build.bat -r -e -v -k -c Debug		-p Win32 	-t Rebuild
@echo off

mkdir "%SRC_ROOT%/_build/include/cpython"

xcopy /s /e /h /y "%SRC_ROOT%/cpython/Include" "%SRC_ROOT%/_build/include/cpython"
copy "%SRC_ROOT%\cpython\PC\pyconfig.h" "%SRC_ROOT%\_build\include\cpython\pyconfig.h"

copy "%SRC_ROOT%\cpython\PCBuild\amd64\python38.lib" "%SRC_ROOT%\_build\windows\lib\release64\python38.lib"
copy "%SRC_ROOT%\cpython\PCBuild\amd64\python38_d.lib" "%SRC_ROOT%\_build\windows\lib\debug64\python38_d.lib"
copy "%SRC_ROOT%\cpython\PCBuild\amd64\python38.dll" "%SRC_ROOT%\_build\windows\bin\release64\python38.dll"
copy "%SRC_ROOT%\cpython\PCBuild\amd64\python38_d.dll" "%SRC_ROOT%\_build\windows\bin\debug64\python38_d.dll"

echo /////////%0 done