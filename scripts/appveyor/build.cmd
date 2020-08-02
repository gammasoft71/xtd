:: cmd

:: init and update submodule
git submodule update --init

:: create build directory
mkdir build\examples
cd build

:: generate and build lib
cmake .. -G "%BUILD_OPTION%" -DENABLE_TESTS=ON -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
if %ERRORLEVEL% NEQ 0 exit 1
cmake --build . --config Debug --target install
if %ERRORLEVEL% NEQ 0 exit 1

:: generate and build examples
cd examples
cmake ../../examples -G "%BUILD_OPTION%" -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
if %ERRORLEVEL% NEQ 0 exit 1
cmake --build . --config Debug
if %ERRORLEVEL% NEQ 0 exit 1
cd ..

cd ..
