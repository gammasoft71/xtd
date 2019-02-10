#!/bin/bash

mkdir -p build/examples

# generate and build console with coverage
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DENABLE_COVERAGE=ON
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
cd ..
