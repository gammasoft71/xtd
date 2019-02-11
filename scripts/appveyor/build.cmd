:: cmd

mkdir build\examples
cd build

:: install external std.strings package
mkdir xtd.strings & cd xtd.strings
git clone https://github.com/gammasoft71/xtd.strings .
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=OFF -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local .
cmake --build . --target install
cd ..

:: generate and build lib
cmake .. -G "%BUILD_OPTION%" -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
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
