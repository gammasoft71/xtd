#!/usr/bin/env sh

# generate and build Switch
mkdir -p build/examples
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local
cmake --build . -- -j8
cmake --build . --target install
if [ $? -ne 0 ]; then exit -1; fi
popd

pushd build/examples
cmake ../../examples -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
popd

# run registered unit tests
pushd build
#ctest --output-on-failure --build-config Debug
#if [ $? -ne 0 ]; then exit -1; fi
popd
