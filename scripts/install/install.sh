#!/usr/bin/env bash

if [ -z ${xtd_version+x} ]; then
  echo "ERROR : Use ./install from root folder"
  exit 1
fi

WXWIDGETS_VERSION=v3.1.6

echo "Install xtd libraries version $xtd_version, copyright Gammasoft, 2022"
echo ""

# detecting linux distribution
echo "Detecting operating system..."
OSTYPE=`uname -a`
if [[ "$OSTYPE" == *"Linux"* ]]; then
  OSTYPE=`lsb_release -si`;
fi

if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
  echo "  Operating System is Windows"
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  echo "  Operating System is macOS"
else
  echo "  Operating System is linux"
fi

# install needed packages and libraries for known distribution
echo "install needed packages and libraries..."
case "$OSTYPE" in
  *"Darwin"*) brew update; brew install cmake;;
  *"Debian"* | *"elementary"* | *"LinuxMint"* | *"Ubuntu"*) sudo apt update; sudo apt install build-essential codeblocks doxygen libgsound-dev libgtk-3-dev cmake -y;;
  *"openSUSE"*) sudo zypper update; sudo zypper install -y -t pattern devel_basis; sudo zypper install -y doxygen gsound-devel gtk3-devel cmake;;
  *"CentOS"* | *"Fedora"* | *"RedHat"*) sudo yum update; sudo yum install cmake gsound-devel gtk3-devel -y;;
esac

echo "dowload and install wxwidgets..."
mkdir -p build/3rdparty/
pushd build/3rdparty
git clone https://github.com/wxwidgets/wxwidgets.git -b $WXWIDGETS_VERSION --depth 1
pushd wxwidgets
git submodule update --init
popd
mkdir -p wxwidgets/build_cmake
pushd wxwidgets/build_cmake
mkdir Debug && mkdir Release
pushd Release
cmake ../.. -DCMAKE_BUILD_TYPE=Release -DwxBUILD_SHARED=OFF
cmake --build . -- -j8
sudo cmake --build . --target install
popd
pushd Debug
cmake ../.. -DCMAKE_BUILD_TYPE=Debug -DwxBUILD_SHARED=OFF
cmake --build . -- -j8
sudo cmake --build . --target install
popd
popd
popd

# generate, build and install xtd
echo "install xtd..."
mkdir build
pushd build
mkdir Release && mkdir Debug
pushd Release
cmake ../..  -DCMAKE_BUILD_TYPE=Release "$@"
cmake --build . -- -j8
sudo cmake --build . --target install
popd
pushd Debug
cmake ../.. -DCMAKE_BUILD_TYPE=Debug "$@"
cmake --build . -- -j8
sudo cmake --build . --target install
popd
popd

# create gui tools shortcut in system operating applications
if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then 
  xtd_program_path="$USERPROFILE/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/xtd"
  if [ ! -d "$xtd_program_path" ]; then mkdir -p "$xtd_program_path"; fi
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\keycode.lnk" "C:\Program Files (x86)\xtd\bin\keycode.exe"  
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\xtdc-gui.lnk" "C:\Program Files (x86)\xtd\bin\xtdc-gui.exe"  
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\xguidgen-gui.lnk" "C:\Program Files (x86)\xtd\bin\guidgen-gui.exe"  
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  if [ -d "/Applications/keycode" ]; then rm "/Applications/keycode"; fi
  ln -s "/usr/local/bin/keycode.app" "/Applications/keycode"
  if [ -d "/Applications/xtdc-gui" ]; then rm "/Applications/xtdc-gui"; fi
  ln -s "/usr/local/bin/xtdc-gui.app" "/Applications/xtdc-gui"
  if [ -d "/Applications/guidgen-gui" ]; then rm "/Applications/guidgen-gui"; fi
  ln -s "/usr/local/bin/guidgen-gui.app" "/Applications/guidgen-gui"
fi

# copy install manifest files to xtd share directory
sudo cp build/3rdparty/wxwidgets/build_cmake/Release/install_manifest.txt /usr/local/share/xtd/wxwidgets_release_install_manifest.txt
sudo cp build/3rdparty/wxwidgets/build_cmake/Debug/install_manifest.txt /usr/local/share/xtd/wxwidgets_debug_install_manifest.txt
sudo cp build/Release/install_manifest.txt /usr/local/share/xtd/xtd_release_install_manifest.txt
sudo cp build/Debug/install_manifest.txt /usr/local/share/xtd/xtd_debug_install_manifest.txt

# launch xtd-gui
echo "launch xtdc-gui..."
if [[ "$OSTYPE" == *"MSYS"* ]] || [[ "$OSTYPE" == *"MINGW64"* ]]; then
  start "C:\Program Files (x86)\xtd\bin\xtdc-gui.exe"
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  open /usr/local/bin/xtdc-gui.app
else
  /usr/local/bin/xtdc-gui &>/dev/null &
fi
