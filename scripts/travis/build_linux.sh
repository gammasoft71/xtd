#!/usr/bin/env sh

# generate and build console
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
popd

# run registered unit tests
pushd build
#ctest --output-on-failure --build-config Debug
#if [ $? -ne 0 ]; then exit -1; fi
popd
