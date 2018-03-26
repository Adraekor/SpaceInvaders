@echo off
echo /////////%0 start

cd %BUILD_ROOT%/SFML
call clean.bat

cd %SRC_ROOT%/SFML

mkdir _build
cd _build

REM cmake -G"NMake Makefiles" ../
REM cmake -G"Visual Studio 15 2017" ../ -DCMAKE_GENERATOR_PLATFORM=Win32
cmake -G"Visual Studio 15 2017" ../ -DCMAKE_GENERATOR_PLATFORM=x64
cmake --build ./ --config Release
cmake --build ./ --config Debug

cd %BUILD_ROOT%/SFML
call copyfiles.bat

echo /////////%0 done