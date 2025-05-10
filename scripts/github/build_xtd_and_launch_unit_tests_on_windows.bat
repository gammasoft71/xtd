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
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A %BUILD_OPTION% -DXTD_BUILD_CPP_STANDARD=23 -DXTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM=ON -DXTD_BUILD_TESTS_XTD_CORE=OFF -DXTD_BUILD_TESTS_XTD_DRAWING=OFF -DXTD_BUILD_TESTS_XTD_FORMS=OFF -DXTD_BUILD_TESTS_XTD_TUNIT=OFF -DCMAKE_INSTALL_PREFIX=%HOMEPATH%/local
if %ERRORLEVEL% NEQ 0 exit 1
cmake --build . --config %BUILD_TYPE% --target install
if %ERRORLEVEL% NEQ 0 exit 1
cd ..

:: run registered unit tests
cd build
ctest --output-on-failure --build-config %BUILD_TYPE%
if %ERRORLEVEL% NEQ 0 exit 1
cd ..
