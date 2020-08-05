#!/usr/bin/env sh

WXWIDGETS_VERSION=v3.1.4

echo "Install xtd libraries version $xtd_version, copyright Gammasoft, 2020"
echo ""

# detecting linux distribution
echo "Detecting operating system..."
OSTYPE=`uname -a`
if [ "$OSTYPE" == *"Linux"* ]; then
  OSTYPE=`lsb_release -si`;
fi

if [ "$OSTYPE" == *"MSYS"* ] || [ "$OSTYPE" == *"MINGW64"* ]; then
  echo "  Operating System is Windows"
elif [ "$OSTYPE" == *"Darwin"* ]; then
  echo "  Operating System is macOS"
else
  echo "  Operating System is linux"
fi

# install needed packages and libraries for known distribution
echo "install needed packages and libraries..."
case "$OSTYPE" in
  *"Darwin"*) brew update; brew install cmake;;
  *"Debian"* | *"elementary"* | *"LinuxMint"* | *"Ubuntu"*) sudo apt update; sudo apt install build-essential libgtk-3-dev cmake -y;;
  *"CentOS"* | *"Fedora"* | *"RedHat"*) sudo yum update; sudo yum install cmake3 gtk3-devel -y;;
esac

# detecting, generate, build and install wxwdigets
#echo "Detecting if wxwidgets is installed..."
#mkdir -p build/test_wxwidgets
#pushd build/test_wxwidgets
#cmake ../../scripts/install/test_wxwidgets
#popd

#if [ ! -f "scripts/install/test_wxwidgets/wxwidgets.lck" ]; then
#  echo "  wxwidgets is not found"
#else
#  echo "  wxwidgets is found"
#  rm "scripts/install/test_wxwidgets/wxwidgets.lck"
#fi

#if [ ! -f "scripts/install/test_wxwidgets/wxwidgets.lck" ]; then
  echo "dowload and install wxwidgets..."
  mkdir -p build/thirdparty/
  pushd build/thirdparty
  git clone https://github.com/wxwidgets/wxwidgets.git -b $WXWIDGETS_VERSION --depth 1
  pushd wxwidgets
  git submodule update --init
  popd
  mkdir -p wxwidgets/build_cmake
  pushd wxwidgets/build_cmake
  if [ "$OSTYPE" == *"MSYS"* ] || [ "$OSTYPE" == *"MINGW64"* ]; then
    cmake .. -DwxBUILD_SHARED=OFF
    cmake --build . --target install --config Debug
    cmake --build . --target install --config Release
  elif [ "$OSTYPE" == *"Darwin"* ]; then
    cmake .. -G "Xcode" -DwxBUILD_SHARED=OFF
    cmake --build . --config Debug
    cmake --build . --target install --config Debug
    cmake --build . --config Release
    cmake --build . --target install --config Release
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
#fi

# generate, build and install xtd
echo "install xtd..."
git submodule update --init
mkdir build
pushd build
if [ "$OSTYPE" == *"MSYS"* ] || [ "$OSTYPE" == *"MINGW64"* ]; then
  cmake .. "$@"
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
elif [ "$OSTYPE" == *"Darwin"* ]; then
  cmake .. -G "Xcode" "$@"
  cmake --build . --config Debug
  cmake --build . --target install --config Debug
  cmake --build . --config Release
  cmake --build . --target install --config Release
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

# create xtdc-gui shortcut in system operating applications
if [ "$OSTYPE" == *"MSYS"* ] || [ "$OSTYPE" == *"MINGW64"* ]; then 
  xtd_program_path="$USERPROFILE/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/xtd"
  if [ ! -d "$xtd_program_path" ]; then mkdir -p "$xtd_program_path"; fi
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\xtdc-gui.lnk" "C:\Program Files (x86)\xtd\bin\xtdc-gui.exe"  
elif [ "$OSTYPE" == *"Darwin"* ]; then
  if [ -d "/Applications/xtdc-gui" ]; then rm "/Applications/xtdc-gui"; fi
  ln -s "/usr/local/bin/xtdc-gui.app" "/Applications/xtdc-gui"
fi


# launch xtd-gui
echo "launch xtdc-gui..."
if [ "$OSTYPE" == *"MSYS"* ] || [ "$OSTYPE" == *"MINGW64"* ]; then
  start "C:\Program Files (x86)\xtd\bin\xtdc-gui.exe"
elif [ "$OSTYPE" == *"Darwin"* ]; then
  open /usr/local/bin/xtdc-gui.app
else
  xdg-open /usr/local/bin/xtdc-gui
fi
