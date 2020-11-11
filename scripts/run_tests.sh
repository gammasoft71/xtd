#!/bin/bash

cd build
ctest --output-on-failure --build-config Debug $*
cd ..
