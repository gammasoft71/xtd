@echo off
echo Install xtd.strings library version %xtd_strings_version%, copyright Gammasoft, 2019
echo.

:: init and update submodule
git submodule init
git submodule update

:: generate, build and install
mkdir build\examples
cd build
cmake .. %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

:: generate and launch examples
cd examples\build
cmake ../../../examples/build %*
start xtd.strings.examples.sln
cd ..
