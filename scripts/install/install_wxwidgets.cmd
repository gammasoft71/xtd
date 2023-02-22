@echo off

set wxwidgets_version=v3.2.2.1

echo Install wxWidgets version %wxwidgets_version%...
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
::                               Download, generate, build and install wxWidgets
echo Downloading and installing wxwidgets...
mkdir build\3rdparty
cd build\3rdparty
git clone https://github.com/wxWidgets/wxWidgets.git -b %wxwidgets_version% --depth 1
cd wxwidgets
git submodule update --init
cd..
mkdir wxwidgets\build_cmake
cd wxwidgets\build_cmake
cmake .. -DwxBUILD_SHARED=OFF %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..\..\..\..
