#!/usr/bin/env bash

wxwidgets_version=v3.2.2.1

echo "Install wxWidgets $wxwidgets_version..."
echo ""

#_______________________________________________________________________________
#                                                   Detecting linux distribution
echo "Detecting operating system..."
OSTYPE=`uname -a`
if [[ "$OSTYPE" == *"Linux"* ]]; then
  OSTYPE=`lsb_release -si`;
fi

if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
  echo "  Operating System is Windows"
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  echo "  Operating System is macOS"; else
  echo "  Operating System is linux"
fi

#_______________________________________________________________________________
#                                                      Check the number of cores
if [[ "$OSTYPE" == *"Darwin"* ]]; then
  build_cores=$(sysctl -n hw.ncpu); else
  build_cores=$(nproc)
fi
if [[ $build_cores -ne 1 ]]; then
  build_cores=$((build_cores - 1))
fi
echo  "Using up to ${build_cores} build cores"

#_______________________________________________________________________________
#                                Download, generate, build and install wxWidgets
echo "Downloading and installing wxwidgets..."
mkdir -p build/3rdparty/
pushd build/3rdparty
git clone https://github.com/wxwidgets/wxwidgets.git -b $wxwidgets_version --depth 1
pushd wxwidgets
git submodule update --init
popd
mkdir -p wxwidgets/build_cmake
pushd wxwidgets/build_cmake
mkdir Debug && mkdir Release
pushd Release
cmake ../.. -DCMAKE_BUILD_TYPE=Release -DwxBUILD_SHARED=OFF "$@"
cmake --build . -- -j$build_cores
sudo cmake --build . --target install
popd
pushd Debug
cmake ../.. -DCMAKE_BUILD_TYPE=Debug -DwxBUILD_SHARED=OFF "$@"
cmake --build . -- -j$build_cores
sudo cmake --build . --target install
popd
popd
popd
