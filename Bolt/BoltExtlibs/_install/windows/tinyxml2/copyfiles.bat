@echo off
echo /////////%0 start

@echo on
cd %BUILD_ROOT%/tinyxml2
rmdir /s /q tmp
mkdir tmp

xcopy /s /e /h /y "%SRC_ROOT%/tinyxml2/_build" "%BUILD_ROOT%/tinyxml2/tmp"
@echo off

cd %BUILD_ROOT%/tinyxml2
call clean.bat

copy "%BUILD_ROOT%\tinyxml2\tmp\Debug\tinyxml2d.dll" "%SRC_ROOT%\_build\windows\bin\debug64\tinyxml2d.dll"
copy "%BUILD_ROOT%\tinyxml2\tmp\Release\tinyxml2.dll" "%SRC_ROOT%\_build\windows\bin\release64\tinyxml2.dll"
copy "%BUILD_ROOT%\tinyxml2\tmp\Debug\tinyxml2d.lib" "%SRC_ROOT%\_build\windows\lib\debug64\tinyxml2d.lib"
copy "%BUILD_ROOT%\tinyxml2\tmp\Release\tinyxml2.lib" "%SRC_ROOT%\_build\windows\lib\release64\tinyxml2.lib"
copy "%SRC_ROOT%\tinyxml2\tinyxml2.h" "%SRC_ROOT%\_build\include\tinyxml2.h"

cd %BUILD_ROOT%/tinyxml2
rmdir /s /q tmp

echo /////////%0 done