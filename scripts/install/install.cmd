@echo off
setlocal enabledelayedexpansion

::______________________________________________________________________________
::                                                       Check execution context
if "%xtd_version%"== "" (
  echo ---------------------------------------------------------------
  echo.
  echo ERROR : Use install.cmd from root folder!
  echo.
  echo ---------------------------------------------------------------
  echo.
  exit /B 1
)

echo Install xtd libraries version %xtd_version%, copyright © 2025 Gammasoft
echo.
echo   Operating System is Windows

::______________________________________________________________________________
::                                                     Check if CMake is present
where cmake > nul 2>&1
if %ERRORLEVEL% neq 0 (
  echo ---------------------------------------------------------------
  echo.
  echo ERROR : CMake not found in PATH.
  echo.
  echo Please install CMake and ensure it is accessible via PATH.
  echo.
  echo ---------------------------------------------------------------
  exit /B 1
)

::______________________________________________________________________________
::                                                   Check if administrator mode
whoami /Groups | find "12288" > nul 2>&1
if %ERRORLEVEL% neq 0 (
  echo.
  echo ---------------------------------------------------------------
  echo.
  echo ERROR : You are not in administrator mode!
  echo.
  echo Run cmd as administrator before executing install.
  echo.
  echo ---------------------------------------------------------------
  echo.
  exit /B 1
)

::______________________________________________________________________________
::                                                   Optional parameter --silent
set silent=
if /I "%1"=="--silent" (
  set silent=1
  shift
)

::______________________________________________________________________________
::                                                      Get cmake_install_prefix
echo "Get cmake_install_prefix..."
if exist "build" rd /S /Q "build"
if not exist "build" mkdir build
cd build
if not exist "cmake_install_prefix" mkdir cmake_install_prefix
cd cmake_install_prefix
cmake ..\..\scripts\install\cmake_install_prefix %*
cd ..
cd ..
set cmake_install_prefix_base=
set /p cmake_install_prefix_base=<"build\cmake_install_prefix\cmake_install_prefix.txt"
echo cmake_install_prefix_base="%cmake_install_prefix_base%"

::______________________________________________________________________________
::                                                   Check and install wxWidgets
echo "Check wxWidgets..."
if not exist "build" mkdir build
cd build
if not exist "test_wxwidgets" mkdir test_wxwidgets
cd test_wxwidgets
set cmake_install_prefix=%cmake_install_prefix_base%\wxwidgets
cmake ..\..\scripts\install\test_wxwidgets %*
cd ..
cd ..

if not exist "build\test_wxwidgets\wxwidgets.lck" (
  echo ---------------------------------------------------------------
  echo.
  echo WARNING : wxWidgets is not installed!
  echo.
  echo If you continue, wxWidgets will be downloaded, built and installed.
  echo.
  echo ---------------------------------------------------------------
  if not defined silent (
    echo Press ENTER to continue or CTRL-C to stop and install wxWidgets manually...
    pause > nul
  )
  call scripts\install\install_wxwidgets.cmd %*
)

::______________________________________________________________________________
::                                               Generate, build and install xtd
echo Installing xtd...
if not exist "build" mkdir build
cd build
set cmake_install_prefix=%cmake_install_prefix_base%\xtd
cmake .. %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

::______________________________________________________________________________
::                    create gui tools shortcut in system operating applications
set "xtd_program_path=%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd"
if not exist "%xtd_program_path%" mkdir "%xtd_program_path%"
call scripts\install\shortcut.cmd "%xtd_program_path%\keycodes.lnk" "%cmake_install_prefix%\bin\keycodes.exe"
call scripts\install\shortcut.cmd "%xtd_program_path%\xtdc-gui.lnk" "%cmake_install_prefix%\bin\xtdc-gui.exe"
call scripts\install\shortcut.cmd "%xtd_program_path%\guidgen-gui.lnk" "%cmake_install_prefix%\bin\guidgen-gui.exe"

::______________________________________________________________________________
::                                                             Add xtdc-gui path
build\tools\set_path\Release\set_path "%cmake_install_prefix%\bin"
set PATH=%cmake_install_prefix%\bin;%PATH%

::______________________________________________________________________________
::                                     Create xtd root path environment variable
build\tools\set_environment_variable\Release\set_environment_variable XTD_ROOT_PATH "%cmake_install_prefix%"
set XTD_ROOT_PATH="%cmake_install_prefix%"
set XTD_TOOLKIT_PATH="%cmake_install_prefix_base%\wxWidgets"

::______________________________________________________________________________
::                                               Create ktd version registry key
reg add "HKCU\Software\Gammasoft\xtd" /v Version /d "%xtd_version%" /f > nul 2>&1

::______________________________________________________________________________
::                                                               clear variables
set cmake_install_prefix=
set cmake_install_prefix_base=
set xtd_program_path=
set xtd_version=
set silent=

::______________________________________________________________________________
::                                                               launch xtdc-gui
echo Launching xtdc-gui...
start "" "%XTD_ROOT_PATH%\bin\xtdc-gui.exe"

::______________________________________________________________________________
::                                                                 final message
echo.
echo ---------------------------------------------------------------
echo xtd version %xtd_version% installed successfully!
echo Root path      : %XTD_ROOT_PATH%
echo Toolkit path   : %XTD_TOOLKIT_PATH%
echo Shortcuts added in Start Menu.
echo For more information, see :
echo    https://gammasoft71.github.io/xtd/
echo ---------------------------------------------------------------
