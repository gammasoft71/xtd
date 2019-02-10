#!/bin/bash

mkdir -p build/examples

# generate and build lib with coverage
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DENABLE_COVERAGE=ON
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# Create lcov report
lcov --capture --directory . --output-file coverage.info
lcov --remove coverage.info '/usr/*' --output-file coverage.info # filter system-files
lcov --list coverage.info

# publish result to codecov
export CODECOV_TOKEN="8dfddc0a-d627-4211-b69b-f82557d3145a"
bash <(curl -s https://codecov.io/bash) -f coverage.info || echo "Codecov did not collect coverage reports"