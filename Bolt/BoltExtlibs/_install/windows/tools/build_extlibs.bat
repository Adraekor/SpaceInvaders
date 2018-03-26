@echo off
echo /////////%0 start

call init_build_root.bat
call init_msvc.bat


cd %SRC_ROOT%
rmdir /s /q _build
mkdir "_build"
mkdir "_build/windows"
mkdir "_build/windows/bin"
mkdir "_build/windows/bin/release64"
mkdir "_build/windows/bin/debug64"
mkdir "_build/windows/bin/release32"
mkdir "_build/windows/bin/debug32"
mkdir "_build/windows/lib"
mkdir "_build/windows/lib/release64"
mkdir "_build/windows/lib/debug64"
mkdir "_build/windows/lib/release32"
mkdir "_build/windows/lib/debug32"
mkdir "_build/include"

cd %BUILD_ROOT%/SFML
call build.bat

cd %BUILD_ROOT%/cpython
call build.bat

cd %BUILD_ROOT%/tinyxml2
call build.bat

cd "%TOOLS_ROOT%"

echo /////////%0 done