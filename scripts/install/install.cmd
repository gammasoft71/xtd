@echo off

set WXWIDGETS_VERSION=v3.1.4

echo Install xtd libraries version %xtd_version%, copyright Gammasoft, 2020
echo.

echo   Operating System is Windows

::detecting, generate, build and install wxwdigets
::echo Detecting if wxwidgets is installed...
::mkdir build\test_wxwidgets
::cd build\test_wxwidgets
::cmake ..\..\scripts\install\test_wxwidgets
::cd..\..

::if not exist "scripts/install/test_wxwidgets/wxwidgets.lck" (
::  echo   wxwidgets is not found
::) else (
::  echo   wxwidgets is found
::)

::if not exist "scripts/install/test_wxwidgets/wxwidgets.lck" (
  echo dowload and install wxwidgets...
  mkdir build\3rdparty
  cd build\3rdparty
  git clone https://github.com/wxWidgets/wxWidgets.git -b %WXWIDGETS_VERSION% --depth 1
  cd wxwidgets
  git submodule update --init
  cd..
  mkdir -p wxwidgets\build_cmake
  cd wxwidgets\build_cmake
  cmake .. -DwxBUILD_SHARED=OFF
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
  cd ..\..\..\..
::)

:: generate, build and install xtd
mkdir build
cd build
cmake .. %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

:: create xtdc-gui shortcut in system operating applications
set xtd_program_path=%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd
if not exist "%xtd_program_path%" mkdir "%xtd_program_path%"
rem call shortcut.bat "%xtd_program_path%\xtdc-gui.lnk" "%USERPROFILE%\local\xtd\bin\xtdc-gui.exe"
call scripts\install\shortcut.cmd "%xtd_program_path%\xtdc-gui.lnk" "%ProgramFiles(x86)%\xtd\bin\xtdc-gui.exe"

:: launch xtdc-gui
echo launch xtdc-gui...
start "xtdc-gui" "%ProgramFiles(x86)%\xtd\bin\xtdc-gui.exe"
