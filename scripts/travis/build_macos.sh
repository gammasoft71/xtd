#!/bin/bash

mkdir -p build/examples
pushd build

# install external xtd.strings package
mkdir xtd.strings && cd xtd.strings
git clone https://github.com/gammasoft71/xtd.strings .
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=OFF -DCMAKE_INSTALL_PREFIX=~/local .
cmake --build . --target install -- -j $(nproc)
cd ..

# generate and build lib
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local ..
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . --target install -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi

# generate and build examples
pushd examples
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/local ../../examples
if [ $? -ne 0 ]; then exit -1; fi
cmake --build . -- -j $(nproc)
if [ $? -ne 0 ]; then exit -1; fi
popd

# run registered unit tests
ctest -j $(nproc) --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi

popd
