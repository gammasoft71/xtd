#!/usr/bin/env sh

echo "Install xtd.strings library version $xtd_strings_version, copyright Gammasoft, 2019"
echo ""

# Detecting linux distribution
OSTYPE=`uname -a`
if [[ "$OSTYPE" == *"Linux"* ]]; then
  OSTYPE=`lsb_release -si`;
fi

# install needed packages and libraries for known distribution
case "$OSTYPE" in
  *"Darwin"*) brew update; brew install cmake;;
  *"Debian"* | *"elementary"* | *"LinuxMint"* | *"Ubuntu"*) sudo apt update; sudo apt install build-essential cmake -y;;
  *"CentOS"* | *"Fedora"* | *"RedHat"*) sudo yum update; sudo yum groupinstall 'Development Tools'; sudo yum install cmake3 -y;;
esac

# init and update submodule
git submodule init
git submodule update

# generate, build and install
mkdir -p build/examples
pushd build
if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
  cmake .. "$@"
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  cmake .. -G "Xcode" "$@"
  cmake --build . --config Debug
  sudo  cmake --build . --target install --config Debug
  cmake --build . --config Release
  sudo cmake --build . --target install --config Release
else
  mkdir Release && mkdir Debug
  pushd Release
  cmake ../.. -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Release "$@"
  cmake --build . -- -j8
  sudo cmake --build . --target install
  popd
  pushd Debug
  cmake ../.. -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug "$@"
  cmake --build . -- -j8
  sudo cmake --build . --target install
  popd
fi
popd

# init and update submodule
git submodule init
git submodule update

# generate and launch examples
mkdir -p examples/build
pushd examples/build
if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW"* ]]; then
  cmake .. "$@"
  start xtd.tunit.examples.sln
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  cmake .. -G "Xcode" "$@"
  open xtd.tunit.examples.xcodeproj
else
  mkdir Debug && mkdir Release
  pushd Release
  cmake ../.. -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Release "$@"
  popd
  pushd Debug
  cmake ../.. -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug "$@"
  xdg-open xtd.tunit.examples.cbp
  popd
fi
popd
