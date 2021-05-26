@echo off

set WXWIDGETS_VERSION=v3.1.5

echo Install xtd libraries version %xtd_version%, copyright Gammasoft, 2020
echo.

echo   Operating System is Windows

:: check if administrator mode
WHOAMI /Groups | FIND "12288" > nul 2>&1
IF %ERRORLEVEL% neq 0 (
  echo You are not in administrator mode!
  echo Run cmd as administrator before execute install.
  exit /B 1
)

echo dowload and install wxwidgets...
mkdir build\3rdparty
cd build\3rdparty
git clone https://github.com/wxWidgets/wxWidgets.git -b %WXWIDGETS_VERSION% --depth 1
cd wxwidgets
git submodule update --init
cd..
mkdir wxwidgets\build_cmake
cd wxwidgets\build_cmake
cmake .. -DwxBUILD_SHARED=OFF
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..\..\..\..

:: generate, build and install xtd
echo install xtd...
mkdir build
cd build
cmake .. %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

:: create gui tools shortcut in system operating applications
set xtd_program_path=%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd
if not exist "%xtd_program_path%" mkdir "%xtd_program_path%"
call scripts\install\shortcut.cmd "%xtd_program_path%\xtdc-gui.lnk" "%ProgramFiles(x86)%\xtd\bin\xtdc-gui.exe"
call scripts\install\shortcut.cmd "%xtd_program_path%\guidgen-gui.lnk" "%ProgramFiles(x86)%\xtd\bin\guidgen-gui.exe"

:: add xtdc-gui path
#set path=%ProgramFiles(x86)%\xtd\bin;%ProgramFiles(x86)%\wxWidgets\lib\vc_x64_dll;%path%
set path=%ProgramFiles(x86)%\xtd\bin;%path%
setx path "%path%"

:: launch xtdc-gui
echo launch xtdc-gui...
start "xtdc-gui" "%ProgramFiles(x86)%\xtd\bin\xtdc-gui.exe"
