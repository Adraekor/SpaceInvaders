@echo off
echo /////////%0 start

echo Enter path to VS2017 install root
echo Example: C:\Program Files\Visual Studio 2017\
echo Don't forget the backslash \ at the end and don't quote the input

set /p VS_ROOT=":"

set "VC_BUILD_PATH=%VS_ROOT%VC\Auxiliary\Build\"
set "VCVARS_PATH=%VC_BUILD_PATH%vcvars64.bat"
REM set "VCVARS_PATH=%VC_BUILD_PATH%vcvars32.bat"

IF EXIST "%VC_BUILD_PATH%" (
REM call "%VCVARS_PATH%"
echo Valid VCVARS_PATH input redirected to vcpath.txt for future reuse
echo %VCVARS_PATH%>vcpath.txt
call "%VCVARS_PATH%"
) ELSE (
echo Error:Invalid input path
)

echo /////////%0 done