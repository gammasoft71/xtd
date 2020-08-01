#!/bin/bash

# init and update submodule
git submodule update --init

# create build directory
mkdir -p build/examples
cd build

# generate and build lib
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -DCMAKE_CXX_COMPILER=g++-8 -DCMAKE_INSTALL_PREFIX=~/local ..
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi

# generate and build examples
cd examples
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-8 -DCMAKE_INSTALL_PREFIX=~/local ../../examples
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# run registered unit tests
ctest -j $(nproc) --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi

cd ..
