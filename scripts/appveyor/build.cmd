:: generate and build
mkdir build
cd build
cmake -G "%BUILD_OPTION%" ..
cmake --build . --config Debug
if %ERRORLEVEL% NEQ 0 exit 1
cd ..
