:: cmd

:: clone, generate and build wxwidgets 3.1.5
mkdir build\thirdparty
cd build\thirdparty
git clone https://github.com/wxwidgets/wxwidgets.git -b v3.1.5 --depth 1
cd wxwidgets
git submodule update --init
mkdir build_cmake 
cd build_cmake
cmake .. -G "Visual Studio 16 2019" -A %BUILD_OPTION% -DwxBUILD_SHARED=OFF -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
cmake --build . --config Debug --target install
cd ../../../..

:: generate and build lib
git submodule update --init
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A %BUILD_OPTION% -DXTD_BUILD_TESTS_XTD_CORE=OFF -DXTD_BUILD_TESTS_XTD_DRAWING=OFF -DXTD_BUILD_TESTS_XTD_FORMS=OFF -DXTD_BUILD_TESTS_XTD_TUNIT=OFF -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
if %ERRORLEVEL% NEQ 0 exit 1
cmake --build . --config Debug --target install
if %ERRORLEVEL% NEQ 0 exit 1
cd ..

:: generate and build examples
::mkdir build\examples
::cd examples
::cmake ../../examples -G "Visual Studio 16 2019" -A %BUILD_OPTION% -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
::if %ERRORLEVEL% NEQ 0 exit 1
::cmake --build . --config Debug
::if %ERRORLEVEL% NEQ 0 exit 1
::cd ..\..
