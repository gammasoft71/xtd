#!/bin/bash

# clone, generate and build wxwidgets 3.1.5
mkdir -p build/thirdparty/ && cd build/thirdparty
git clone https://github.com/wxwidgets/wxwidgets.git -b v3.1.5 --depth 1
cd wxwidgets
git submodule update --init
mkdir build_cmake && cd build_cmake
cmake .. -DCMAKE_BUILD_TYPE=Debug -DwxBUILD_SHARED=OFF -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
cd ../../../..

# generate and build lib
git submodule update --init
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# generate and build examples
mkdir -p build/examples
cd build/examples
cmake ../../examples -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local 
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
cd ../..
