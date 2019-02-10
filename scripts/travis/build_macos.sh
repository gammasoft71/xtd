#!/bin/bash

mkdir -p build/examples

# generate and build lib
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install
if [ $? -ne 0 ]; then exit -1; fi
popd

# generate and build examples
pushd build/examples
cmake ../../examples -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
popd

# run registered unit tests
pushd build
ctest --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi
popd
