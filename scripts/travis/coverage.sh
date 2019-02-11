#!/bin/bash

mkdir -p build
cd build

# install external std.strings package
mkdir xtd.strings && cd xtd.strings
git clone https://github.com/gammasoft71/xtd.strings .
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DENABLE_TESTS=OFF -DCMAKE_INSTALL_PREFIX=~/local .
cmake --build . --target install -- -j $(nproc)
cd ..

# generate and build lib with coverage
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++-7 -DENABLE_COVERAGE=ON -DCMAKE_INSTALL_PREFIX=~/local ..
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi

# Create lcov report
lcov --capture --directory . --output-file coverage.info
#if [ $? -ne 0 ]; then exit -1; fi
lcov --remove coverage.info '/usr/*' --output-file coverage.info
#if [ $? -ne 0 ]; then exit -1; fi
lcov --list coverage.info
#if [ $? -ne 0 ]; then exit -1; fi

# publish result to codecov
bash <(curl -s https://codecov.io/bash) -f coverage.info -t "8dfddc0a-d627-4211-b69b-f82557d3145a"
#if [ $? -ne 0 ]; then exit -1; fi

cd ..
