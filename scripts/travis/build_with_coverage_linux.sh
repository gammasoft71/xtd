#!/bin/bash

mkdir -p build/examples

# generate and build lib with coverage
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DENABLE_COVERAGE=ON
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# publish result to codecov
export CODECOV_TOKEN="8dfddc0a-d627-4211-b69b-f82557d3145a"
bash <(curl -s https://codecov.io/bash)
