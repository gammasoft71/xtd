#!/bin/bash
set -e
set -o pipefail

echo "🔧 Configuring CMake..."
mkdir -p build && cd build
cmake .. \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -DXTD_BUILD_CPP_STANDARD=23 \
  -DXTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM=ON \
  -DXTD_BUILD_TESTS_XTD_CORE=ON \
  -DXTD_BUILD_TESTS_XTD_DRAWING=OFF \
  -DXTD_BUILD_TESTS_XTD_FORMS=OFF \
  -DXTD_BUILD_TESTS_XTD_TUNIT=OFF \
  -DCMAKE_INSTALL_PREFIX=~/local

echo "🛠 Building..."
cmake --build . -- -j8

echo "📦 Installing..."
cmake --build . --target install

echo "🧪 Running tests..."
ctest -j8 --output-on-failure --build-config $BUILD_TYPE
