@echo off

if "%xtd_version%"== "" (
  echo ---------------------------------------------------------------
  echo.
  echo ERROR : Use install.cmd from root folder!
  echo.
  echo ---------------------------------------------------------------
  echo.
  exit /B 1
)

echo Install xtd libraries version %xtd_version%, copyright Gammasoft, 2023
echo.
echo   Operating System is Windows

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
::                                                      Get cmake_install_prefix
echo "Get cmake_install_prefix..."
if exist "build" rd /S /Q "build"
mkdir build
cd build
mkdir cmake_install_prefix
cd cmake_install_prefix
cmake ..\..\scripts\install\cmake_install_prefix %*
cd ..
cd ..
set /p cmake_install_prefix=<build\cmake_install_prefix\cmake_install_prefix.txt
echo cmake_install_prefix="%cmake_install_prefix%"

::______________________________________________________________________________
::                                                   Check and install wxWidgets
echo "Checks wxWidgets..."
mkdir build
cd build
mkdir test_wxwidgets
cd test_wxwidgets
cmake ..\..\scripts\install\test_wxwidgets %*
cd ..
cd ..
if not exist "build\test_wxwidgets\wxwidgets.lck" (
  echo.
  echo ---------------------------------------------------------------
  echo.
  echo WARNING : wxWidgets is not already installed!
  echo.
  echo If you continue wxWidgets will be downloaded, built and installed automatically.
  echo.
  echo ---------------------------------------------------------------
  echo.
  echo Press ENTER to continue or CTRL-C to stop and install wxWidgets manually...
  pause > nul 2>&1
  call scripts\install\install_wxwidgets.cmd %*
)

::______________________________________________________________________________
::                                               Generate, build and install xtd
echo Installing xtd...
mkdir build
cd build
cmake .. -DXTD_BUILD_CPP_STANDARD="17" %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

::______________________________________________________________________________
::                    create gui tools shortcut in system operating applications
set xtd_program_path=%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd
if not exist "%xtd_program_path%" mkdir "%xtd_program_path%"
call scripts\install\shortcut.cmd "%xtd_program_path%\keycodes.lnk" "%cmake_install_prefix%\xtd\bin\keycodes.exe"
call scripts\install\shortcut.cmd "%xtd_program_path%\xtdc-gui.lnk" "%cmake_install_prefix%\xtd\bin\xtdc-gui.exe"
call scripts\install\shortcut.cmd "%xtd_program_path%\guidgen-gui.lnk" "%cmake_install_prefix%\xtd\bin\guidgen-gui.exe"

::______________________________________________________________________________
::                                                             Add xtdc-gui path

::______________________________________________________________________________
::                                                             Add xtdc-gui path
build\tools\set_path\Release\set_path "%cmake_install_prefix%\xtd\bin"
set Path=%cmake_install_prefix%\xtd\bin;%Path%

::______________________________________________________________________________
::                                                               launch xtdc-gui
echo Launching xtdc-gui...
::start "xtdc-gui" "%cmake_install_prefix%\xtd\bin\xtdc-gui.exe"
start "xtdc-gui" "xtdc-gui"
