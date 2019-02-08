#!/usr/bin/env sh

# generate and build console
mkdir -p build/examples
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DCMAKE_INSTALL_PREFIX=~/local
cmake --build . -- -j8
cmake --build . --target install

if [ $? -ne 0 ]; then exit -1; fi
cd ..

cd build/examples
cmake ../../examples -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DCMAKE_INSTALL_PREFIX=~/local
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# run registered unit tests
cd build
ctest --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi
cd ..
