@echo off
echo /////////%0 start

echo Init msvc env

IF EXIST vcpath.txt (
set /p VCVARS_PATH=<vcpath.txt
echo vcpath.txt
IF EXIST "%VCVARS_PATH%" (
echo Red VCVARS_PATH vars path from vcpath.txt
call "%VCVARS_PATH%"
) ELSE (
echo invalid VCVARS_PATH in vcpath.txt
echo "%VCVARS_PATH%"
echo %VCVARS_PATH%
call ask_msvc.bat
)
) ELSE (
echo Cannot find vcpath.txt
call ask_msvc.bat
)

echo /////////%0 done