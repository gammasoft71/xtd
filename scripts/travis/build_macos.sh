#!/bin/bash

mkdir -p build/examples
pushd build

# generate and build lib
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi

# generate and build examples
pushd examples
cmake ../../examples -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
popd

# run registered unit tests
ctest -j $(nproc) --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi

popd
