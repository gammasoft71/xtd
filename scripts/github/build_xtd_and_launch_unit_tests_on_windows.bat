:: cmd

:: clone, generate and build wxwidgets 3.2.2.1
mkdir build\thirdparty
cd build\thirdparty
git clone https://github.com/wxwidgets/wxwidgets.git -b v3.2.2.1 --depth 1
cd wxwidgets
git submodule update --init
mkdir build_cmake 
cd build_cmake
cmake .. -G "Visual Studio 17 2022" -A %BUILD_OPTION% -DwxBUILD_SHARED=OFF -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
cmake --build . --config %BUILD_TYPE% --target install
cd ..
rmdir /s /q build_cmake
cd ../../..

:: generate and build lib
git submodule update --init
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A %BUILD_OPTION% -DXTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM=ON -DXTD_BUILD_TESTS_XTD_CORE=ON -DXTD_BUILD_TESTS_XTD_DRAWING=ON -DXTD_BUILD_TESTS_XTD_FORMS=OFF -DXTD_BUILD_TESTS_XTD_TUNIT=ON -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
if %ERRORLEVEL% NEQ 0 exit 1
cmake --build . --config %BUILD_TYPE% --target install
if %ERRORLEVEL% NEQ 0 exit 1
cd ..

:: run registered unit tests
cd build
ctest --output-on-failure --build-config %BUILD_TYPE%
if %ERRORLEVEL% NEQ 0 exit 1
cd ..

:: generate and build examples
::mkdir build\examples
::cd examples
::cmake ../../examples -G "Visual Studio 17 2022" -A %BUILD_OPTION% -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
::if %ERRORLEVEL% NEQ 0 exit 1
::cmake --build . --config %BUILD_TYPE%
::if %ERRORLEVEL% NEQ 0 exit 1
::cd ..\..
