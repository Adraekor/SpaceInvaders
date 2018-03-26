@echo off
echo /////////%0 start

@echo on
cd %BUILD_ROOT%/SFML
rmdir /s /q tmp
mkdir tmp

xcopy /s /e /h /y "%SRC_ROOT%/SFML/_build" "%BUILD_ROOT%/SFML/tmp"
@echo off

cd %BUILD_ROOT%/SFML
call clean.bat

copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-audio-d-2.dll" 		"%SRC_ROOT%\_build\windows\bin\debug64\sfml-audio-d-2.dll"
copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-graphics-d-2.dll" 	"%SRC_ROOT%\_build\windows\bin\debug64\sfml-graphics-d-2.dll"
copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-network-d-2.dll" 	"%SRC_ROOT%\_build\windows\bin\debug64\sfml-network-d-2.dll"
copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-system-d-2.dll" 		"%SRC_ROOT%\_build\windows\bin\debug64\sfml-system-d-2.dll"
copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-window-d-2.dll" 		"%SRC_ROOT%\_build\windows\bin\debug64\sfml-window-d-2.dll"

copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-audio-d.lib" 		"%SRC_ROOT%\_build\windows\lib\debug64\sfml-audio-d.lib"
copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-graphics-d.lib" 		"%SRC_ROOT%\_build\windows\lib\debug64\sfml-graphics-d.lib"
copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-network-d.lib" 		"%SRC_ROOT%\_build\windows\lib\debug64\sfml-network-d.lib"
copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-system-d.lib" 		"%SRC_ROOT%\_build\windows\lib\debug64\sfml-system-d.lib"
copy "%BUILD_ROOT%\SFML\tmp\lib\Debug\sfml-window-d.lib" 		"%SRC_ROOT%\_build\windows\lib\debug64\sfml-window-d.lib"

copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-audio-2.dll" 		"%SRC_ROOT%\_build\windows\bin\release64\sfml-audio-2.dll"
copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-graphics-2.dll" 	"%SRC_ROOT%\_build\windows\bin\release64\sfml-graphics-2.dll"
copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-network-2.dll" 	"%SRC_ROOT%\_build\windows\bin\release64\sfml-network-2.dll"
copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-system-2.dll" 		"%SRC_ROOT%\_build\windows\bin\release64\sfml-system-2.dll"
copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-window-2.dll" 		"%SRC_ROOT%\_build\windows\bin\release64\sfml-window-2.dll"

copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-audio.lib" 		"%SRC_ROOT%\_build\windows\lib\release64\sfml-audio.lib"
copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-graphics.lib" 		"%SRC_ROOT%\_build\windows\lib\release64\sfml-graphics.lib"
copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-network.lib" 		"%SRC_ROOT%\_build\windows\lib\release64\sfml-network.lib"
copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-system.lib" 		"%SRC_ROOT%\_build\windows\lib\release64\sfml-system.lib"
copy "%BUILD_ROOT%\SFML\tmp\lib\Release\sfml-window.lib" 		"%SRC_ROOT%\_build\windows\lib\release64\sfml-window.lib"

xcopy /s /e /h /y "%SRC_ROOT%\SFML\include" "%SRC_ROOT%\_build\include\"

cd %BUILD_ROOT%/SFML
rmdir /s /q tmp

echo /////////%0 done