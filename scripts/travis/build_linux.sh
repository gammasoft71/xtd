#!/bin/bash

# clone, generate and build wxwidgets 3.1.4
mkdir -p build/thirdparty/ && cd build/thirdparty
git clone https://github.com/wxwidgets/wxwidgets.git -b v3.1.4 --depth 1
cd wxwidgets
git submodule update --init
mkdir build_cmake && cd build_cmake
cmake .. -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DwxBUILD_SHARED=OFF -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j $(nproc) -- -quiet
if [ $? -ne 0 ]; then exit -1; fi
cd ../../../..

# generate and build lib
git submodule update --init
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -DENABLE_XTD_COMMAND_LINE=OFF -DCMAKE_CXX_COMPILER=g++-9 -DCMAKE_INSTALL_PREFIX=~/local ..
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
#cmake --build . --target install -- -quiet
#if [ $? -ne 0 ]; then exit -1; fi
cd ..

# generate and build examples
#mkdir -p build/examples
#cd examples
#cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-9 -DCMAKE_INSTALL_PREFIX=~/local ../../examples
#if [ $? -ne 0 ]; then exit -1; fi
#cmake --build . -- -j $(nproc)
#if [ $? -ne 0 ]; then exit -1; fi
#cd ../..

# run registered unit tests
#cd build
#ctest -j $(nproc) --output-on-failure --build-config Debug
#if [ $? -ne 0 ]; then exit -1; fi
#cd ..
