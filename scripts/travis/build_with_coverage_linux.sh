#!/usr/bin/env sh

# generate and build console
mkdir -p build/examples
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DENABLE_COVERAGE=ON
cmake --build . -- -j8

if [ $? -ne 0 ]; then exit -1; fi
cd ..
