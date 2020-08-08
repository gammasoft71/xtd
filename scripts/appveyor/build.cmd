:: cmd

:: generate, build and install wxwdigets
mkdir build\3rdparty
cd build\3rdparty
git clone https://github.com/wxWidgets/wxWidgets.git -b v3.1.4 --depth 1
cd wxwidgets
git submodule update --init
cd..
mkdir wxwidgets\build_cmake
cd wxwidgets\build_cmake
cmake .. -DwxBUILD_SHARED=OFF
cmake --build . --target install --config Debug
cd ..\..\..\..

:: create build directory
mkdir build\examples
cd build

:: generate and build lib
git submodule update --init
cmake .. -G "%BUILD_OPTION%" -DENABLE_TESTS=ON
if %ERRORLEVEL% NEQ 0 exit 1
cmake --build . --config Debug --target install
if %ERRORLEVEL% NEQ 0 exit 1

:: generate and build examples
cd examples
cmake ../../examples -G "%BUILD_OPTION%"
if %ERRORLEVEL% NEQ 0 exit 1
cmake --build . --config Debug
if %ERRORLEVEL% NEQ 0 exit 1
cd ..

cd ..
