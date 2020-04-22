#!/bin/bash

brew update
brew install doxygen

mkdir -p build/examples
pushd build

# generate and build lib
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -DCMAKE_INSTALL_PREFIX=~/local ..
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j 8
if [ $? -ne 0 ]; then exit -1; fi

# generate and build examples
pushd examples
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local ../../examples
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j 8
if [ $? -ne 0 ]; then exit -1; fi
popd

# run registered unit tests
ctest -j $(nproc) --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi

popd
