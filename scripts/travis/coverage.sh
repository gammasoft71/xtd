#!/bin/bash

mkdir -p build
cd build

# generate and build lib with coverage
cmake .. -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi

# Create lcov report
lcov --capture --directory . --output-file coverage.info
lcov --remove coverage.info '/usr/*' --output-file coverage.info
lcov --list coverage.info

# publish result to codecov
bash <(curl -s https://codecov.io/bash) -f coverage.info -t "8dfddc0a-d627-4211-b69b-f82557d3145a"

cd ..
