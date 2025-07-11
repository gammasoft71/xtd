#!/bin/bash

# generate and build lib
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DXTD_BUILD_CPP_STANDARD=23 -DXTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM=ON -DXTD_BUILD_TESTS_XTD_CORE=OFF -DXTD_BUILD_TESTS_XTD_DRAWING=OFF -DXTD_BUILD_TESTS_XTD_FORMS=OFF -DXTD_BUILD_TESTS_XTD_TUNIT=OFF -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
#cmake --build . --target install
#if [ $? -ne 0 ]; then exit -1; fi
cd ..

# run registered unit tests
cd build
ctest -j $(nproc) --output-on-failure --build-config $BUILD_TYPE
if [ $? -ne 0 ]; then exit -1; fi
cd ..
