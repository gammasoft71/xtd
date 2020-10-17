#!/bin/bash


# clone, generate and build wxwidgets 3.1.4
mkdir -p build/thirdparty/ && cd build/thirdparty
git clone https://github.com/wxwidgets/wxwidgets.git -b v3.1.4 --depth 1
cd wxwidgets
git submodule update --init
mkdir build_cmake && cd build_cmake
cmake .. -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DwxBUILD_SHARED=OFF -DCMAKE_INSTALL_PREFIX=~/local
cmake --build . -- -j8
cmake --build . --target install
cd ../../../..

# generate and build lib with coverage
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -DENABLE_XTD_COMMAND_LINE=OFF -DCMAKE_CXX_COMPILER=g++-9 -DENABLE_COVERAGE=ON -DCMAKE_INSTALL_PREFIX=~/local ..
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
