@echo off
echo Install xtd libraries version %xtd_version%, copyright Gammasoft, 2020
echo.

echo   Operating System is Windows

:: detecting, generate, build and install wxwdigets
echo Detecting if wxwidgets is installed...
mkdir build\test_wxwidgets
cd build\test_wxwidgets
cmake ..\..\scripts\install\test_wxwidgets
cd..\..

if exist "scripts/install/test_wxwidgets/wxwidgets.lck" (
  echo   wxwidgets is not found
) else (
  echo   wxwidgets is found
)

if not exist "scripts/install/test_wxwidgets/wxwidgets.lck" (
  echo dowload and install wxwidgets...
  mkdir build\3rdparty
  cd build\3rdparty
  git clone https://github.com/wxWidgets/wxWidgets.git -b $WXWIDGETS_VERSION --depth 1
  cd wxwidgets
  git submodule update --init
  cd..
  mkdir -p wxwidgets\build_cmake
  cd wxwidgets\build_cmake
  cmake .. -DwxBUILD_SHARED=OFF
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
  cd ..\..\..\..
)

:: generate, build and install xtd
mkdir build
cd build
cmake .. %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

:: launch xtdc-gui
echo launch xtdc-gui...
start "C:\Program Files (x86)\xtd\bin\xtdc-gui.exe"
