:: cmd

:: generate, build and install wxwdigets
mkdir build\3rdparty
cd build\3rdparty
git clone https://github.com/wxWidgets/wxWidgets.git -b v3.1.4 --depth 1
cd wxwidgets
git submodule update --init
mkdir build_cmake
cd build_cmake
cmake .. -G "%BUILD_OPTION%" -DwxBUILD_SHARED=OFF -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
cmake --build . --target install --config Debug
cd ..\..\..\..

:: generate and build lib
mkdir build
cd build
git submodule update --init
cmake .. -G "%BUILD_OPTION%" -DENABLE_TESTS=ON -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
if %ERRORLEVEL% NEQ 0 exit 1
cmake --build . --config Debug --target install
if %ERRORLEVEL% NEQ 0 exit 1
cd ..

:: generate and build examples
::mkdir build\examples
::cd build\examples
::cmake ../../examples -G "%BUILD_OPTION%" -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
::if %ERRORLEVEL% NEQ 0 exit 1
::cmake --build . --config Debug
::if %ERRORLEVEL% NEQ 0 exit 1
::cd ..\..
