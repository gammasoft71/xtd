#!/usr/bin/env sh

WXWIDGETS_VERSION=v3.1.4

echo "Install xtd_forms library version $xtd_forms_version, copyright Gammasoft, 2020"
echo ""

# detecting linux distribution
OSTYPE=`uname -a`
if [[ "$OSTYPE" == *"Linux"* ]]; then
  OSTYPE=`lsb_release -si`;
fi

# install needed packages and libraries for known distribution
case "$OSTYPE" in
  *"Darwin"*) brew update; brew install cmake -y;;
  *"Debian"* | *"elementary"* | *"LinuxMint"* | *"Ubuntu"*) sudo apt update; sudo apt install build-essential libgtk-3-dev cmake -y;;
  *"CentOS"* | *"Fedora"* | *"RedHat"*) sudo yum update; sudo yum install cmake3 gtk3-devel -y;;
esac

# detecting, generate, build and install wxwdigets
mkdir -p test_wxwidgets/build
pushd test_wxwidgets/build
cmake ..
popd

if [! -f "test_wxwidgets/wxwidgets.lck" ]; then
  mkdir -p build/thirdparty/wxwidgets/build
  pushd build/thirdparty/wxwidgets
  git clone https://github.com/wxWidgets/wxWidgets.git -b $WXWIDGETS_VERSION
  pushd build
  if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
    cmake .. -DwxBUILD_SHARED=OFF
    cmake --build . --target install --config Debug
    cmake --build . --target install --config Release
  elif [[ "$OSTYPE" == *"Darwin"* ]]; then
    cmake .. -G "Xcode" -DwxBUILD_SHARED=OFF
    cmake --build . --config Debug -- -j8
    sudo  cmake --build . --target install --config Debug
    cmake --build . --config Release -- -j8
    sudo cmake --build . --target install --config Release
  else
    mkdir Release && mkdir Debug
    pushd Release
    cmake ../.. -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DwxBUILD_SHARED=OFF
    cmake --build . -- -j8
    sudo cmake --build . --target install
    popd
    pushd Debug
    cmake ../.. -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DwxBUILD_SHARED=OFF
    cmake --build . -- -j8
    sudo cmake --build . --target install
    popd
  fi
  popd
  popd
fi

# generate, build and install xtd_forms
mkdir -p build/examples
pushd build
if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
  cmake .. "$@"
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  cmake .. -G "Xcode" "$@"
  cmake --build . --config Debug -- -j8
  sudo  cmake --build . --target install --config Debug
  cmake --build . --config Release -- -j8
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

# launch xtd-gui
if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
  start "C:\Program Files (x86)\xtd_forms\bin\xtdc-gui.exe"
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  open /usr/local/bin/xtdc-gui.app
else
fi
  xdg-open /usr/local/bin/xtdc-gui
popd
