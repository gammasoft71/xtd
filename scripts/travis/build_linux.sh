#!/bin/bash

mkdir -p build/examples

# generate and build lib
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# generate and build examples
cd build/examples
cmake ../../examples -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
cd ../..

# run registered unit tests
cd build
ctest -j $(nproc) --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi
cd ..
