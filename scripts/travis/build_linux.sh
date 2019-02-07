#!/usr/bin/env sh

# generate and build console
mkdir -p build/examples
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
cd ..

cd build/example
cmake ../../examples -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
cd ..

# run registered unit tests
#cd build
#ctest --output-on-failure --build-config Debug
#if [ $? -ne 0 ]; then exit -1; fi
#cd ..
