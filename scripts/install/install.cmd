@echo off
echo Install xtd.io libraries version %xtd_tunit_version%, copyright Gammasoft, 2019
echo.

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
start xtd.io.examples.sln
cd ..
