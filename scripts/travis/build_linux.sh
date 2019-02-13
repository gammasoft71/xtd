#!/bin/bash

mkdir -p build/examples
cd build

# install external xtd.strings package
#mkdir xtd.strings && cd xtd.strings
#git clone https://github.com/gammasoft71/xtd.strings .
#cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DENABLE_TESTS=OFF -DCMAKE_INSTALL_PREFIX=~/local .
#cmake --build . --target install -- -j $(nproc)
#cd ..

# generate and build lib
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DCMAKE_INSTALL_PREFIX=~/local ..
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi

# generate and build examples
cd examples
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DCMAKE_INSTALL_PREFIX=~/local ../../examples
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# run registered unit tests
ctest -j $(nproc) --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi

cd ..
