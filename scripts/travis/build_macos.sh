#!/bin/bash

brew update
brew install doxygen

# generate and build lib
git submodule update --init
mkdir -p build & cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -DCMAKE_INSTALL_PREFIX=~/local ..
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j 8
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# generate and build examples
#mkdir -p build/examples & cd build/examples
#cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local ../../examples
#if [ $? -ne 0 ]; then exit -1; fi
#cmake --build . -- -j 8
#if [ $? -ne 0 ]; then exit -1; fi
#cd ../..

# run registered unit tests
#cd build
#ctest -j $(nproc) --output-on-failure --build-config Debug
#if [ $? -ne 0 ]; then exit -1; fi
#cd..
