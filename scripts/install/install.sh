#!/usr/bin/env bash

if [ -z ${xtd_version+x} ]; then
  echo ""
  echo "---------------------------------------------------------------"
  echo ""
  echo "ERROR : Use ./install from root folder!"
  echo ""
  echo "---------------------------------------------------------------"
  echo ""
  exit 1
fi
# Check if the system is SerenityOS
if [[ "$(uname -s)" == "SerenityOS" ]]; then
  # SerenityOS does not require sudo or root privileges
  echo "Running on SerenityOS, no sudo required."
else
    if [[ "$(id -u)" -ne 0 && -z "$(command -v sudo)" ]]; then
      echo "---------------------------------------------------------------"
      echo ""
      echo "ERROR : Impossible to install: no root or 'sudo' available."
      echo ""
      echo "---------------------------------------------------------------"
      echo ""
      exit 1
    fi
fi

echo "Install xtd libraries version $xtd_version, copyright © 2025 Gammasoft"
echo ""

#_______________________________________________________________________________
#                                                   Detecting linux distribution
echo "Detecting operating system..."
OS_NAME=`uname`
if [[ "$OS_NAME" == "Linux" ]]; then
  OS_NAME=`cat /etc/*-release | grep -w 'NAME='`;
fi

if [[ "$OS_NAME" == *"MSYS"* ]] || [[ "$OS_NAME" == *"MINGW64"* ]]; then
  OS_NAME="$MSYSTEM"
  echo "  Operating System is" $OS_NAME;
elif [[ "$OS_NAME" == *"Darwin"* ]]; then
  echo "  Operating System is macOS";
elif [[ "$OS_NAME" == *"FreeBSD"* ]]; then
  echo "  Operating System is FreeBSD"; 
elif [[ "$OS_NAME" == *"Linux"* ]]; then
  echo "  Operating System is Linux"; 
elif [[ "$OS_NAME" == *"Haiku"* ]]; then
  echo "  Operating System is Haiku"; 
elif [[ "$OS_NAME" == *"SerenityOS"* ]]; then
  echo "  Operating System is SerenityOS"; 
else
  echo "  Operating System is Unknown"
fi

#_______________________________________________________________________________
#                                                      Check the number of cores
if [[ "$OS_NAME" == *"Darwin"* ]]; then
  build_cores=$(sysctl -n hw.ncpu); 
elif [[ "$OS_NAME" == *"SerenityOS"* ]]; then
  build_cores=""; # SerenityOS does not support nproc or sysctl
else
  build_cores=$(nproc)
fi
if [[ $build_cores -ne 1 ]]; then
  build_cores=$((build_cores - 1))
fi
echo  "Using up to ${build_cores} build cores"

#_______________________________________________________________________________
#                   Install needed packages and libraries for known distribution

# Add wxWdigets 3.2 or above in MINGW64 and MSYS (see https://packages.msys2.org/package/mingw-w64-x86_64-wxwidgets3.2-gtk3-libs?repo=mingw64 for more info).

echo "Installing needed packages and libraries..."
case "$OS_NAME" in
  *"CentOS"* | *"Fedora"* | *"RedHat"*) sudo yum update; sudo yum install alsa-lib-devel cmake gtk3-devel gsound-devel gtk3-devel libuuid-devel -y;;
  "CLANGARM64") pacman -S -yy --noconfirm base-devel git mingw-w64-clang-aarch64-cmake mingw-w64-clang-aarch64-doxygen mingw-w64-clang-aarch64-gcc-compat mingw-w64-clang-aarch64-gtk3 mingw-w64-clang-aarch64-make mingw-w64-clang-aarch64-wxwidgets3.2-msw;;
  "CLANG32") pacman -S -yy --noconfirm base-devel git mingw-w64-clang-i686-cmake mingw-w64-clang-i686-doxygen mingw-w64-clang-i686-gcc-compat mingw-w64-clang-i686-gtk3 mingw-w64-clang-i686-make mingw-w64-clang-i686-wxwidgets3.2-msw;;
  "CLANG64") pacman -S -yy --noconfirm base-devel git mingw-w64-clang-x86_64-cmake mingw-w64-clang-x86_64-doxygen mingw-w64-clang-x86_64-gcc-compat mingw-w64-clang-x86_64-gtk3 mingw-w64-clang-x86_64-make mingw-w64-clang-x86_64-wxwidgets3.2-msw;;
  "Darwin") brew update; brew install cmake;;
  *"Debian"* | *"elementary"* | *"LinuxMint"* | *"Ubuntu"*) sudo apt update; sudo apt install build-essential doxygen libasound2-dev libgsound-dev libgtk-3-dev cmake -y;;
  "FreeBSD") sudo pkg update; sudo pkg install -y cmake doxygen gtk3 gsound alsa-plugins wx32-gtk3 libsysinfo pkgconf;;
  *"openSUSE"*) sudo zypper update; sudo zypper install -y -t pattern devel_basis; sudo zypper install -y alsa-devel doxygen gsound-devel gtk3-devel cmake;;
  "MINGW32") pacman -S -yy --noconfirm base-devel git mingw-w64-i686-cmake mingw-w64-i686-doxygen mingw-w64-i686-gcc mingw-w64-i686-gtk3 mingw-w64-i686-make mingw-w64-i686-wxwidgets3.2-msw;;
  "MINGW64") pacman -S -yy --noconfirm base-devel git mingw-w64-x86_64-cmake mingw-w64-x86_64-doxygen mingw-w64-x86_64-gcc mingw-w64-x86_64-gtk3 mingw-w64-x86_64-make mingw-w64-x86_64-wxwidgets3.2-msw;;
  "MSYS") pacman -S -yy --noconfirm base-devel git cmake doxygen gcc make ;; #gtk3 make wxwidgets3.2-msw;;
  *"Rocky"*) sudo yum update; sudo yum groupinstall 'Development Tools' -y; sudo yum install alsa-lib-devel cmake libuiid-devel gsound gtk3-devel -y;;
  "UCRT64") pacman -S -yy --noconfirm base-devel git mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-doxygen mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gtk3 mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-wxwidgets3.2-msw;;
esac

if [[ "$OS_NAME" == *"MSYS"* ]]; then
  echo ""
  echo "---------------------------------------------------------------"
  echo ""
  echo "ERROR : The MSYS Shell is not supported : use : CLANGARM64,"
  echo "        CLANG32, CLANG64, MINGW32, MINGW64 or UCRT64 Shell."
  echo ""
  echo "---------------------------------------------------------------"
  echo ""
  exit 1
fi

#_______________________________________________________________________________
#                                                       Get cmake_install_prefix
echo "Get cmake_install_prefix..."
mkdir build
pushd build
mkdir cmake_install_prefix
pushd cmake_install_prefix
cmake ../../scripts/install/cmake_install_prefix "$@"
popd
popd
cmake_install_prefix=`cat build/cmake_install_prefix/cmake_install_prefix.txt`
echo "cmake_install_prefix=\"$cmake_install_prefix\""

#_______________________________________________________________________________
#                                                    Check and install wxWidgets
if [ "$OS_NAME" != "Haiku"] && [“$OS_NAME” != "SerenityOS"] && [“$(uname -s)” != "SerenityOS"]; then
  echo "Checks wxWidgets..."
  if [ -d "build" ]; then rm -rf "build"; fi
  mkdir build
  pushd build
  mkdir test_wxwidgets
  pushd test_wxwidgets
  cmake ../../scripts/install/test_wxwidgets "$@"
  popd
  popd
  if [ ! -f "build/test_wxwidgets/wxwidgets.lck" ]; then
    echo ""
    echo "---------------------------------------------------------------"
    echo ""
    echo "WARNING : wxWidgets is not already installed!"
    echo ""
    echo "If you continue wxWidgets will be downloaded, built and installed automatically."
    echo ""
    echo "---------------------------------------------------------------"
    echo ""
    read -p "Press ENTER to continue or CTRL-C to stop and install wxWidgets manually..."
    scripts/install/install_wxwidgets.sh "$@" || exit 1
  fi
fi

#_______________________________________________________________________________
#                                                Generate, build and install xtd
echo "Installing xtd $xtd_version..."
mkdir build
pushd build
mkdir Release && mkdir Debug
pushd Release
cmake ../.. -DCMAKE_BUILD_TYPE=Release "$@" || exit 1
if [[ "$OS_NAME" == *"SerenityOS"* ]]; then
    cmake --build . || exit 1
else
    cmake --build . -- -j$build_cores || exit 1
fi
if [[ "$OS_NAME" == *"CLANGARM64"* ]] || [[ "$OS_NAME" == *"CLANG32"* ]] || [[ "$OS_NAME" == *"CLANG64"* ]] || [[ "$OS_NAME" == *"MINGW32"* ]] || [[ "$OS_NAME" == *"MINGW64"* ]] || [[ "$OS_NAME" == *"UCRT64"* ]]; then
  cmake --build . --target install || exit 1
elif [[ "$OS_NAME" == *"SerenityOS"* ]]; then
  su -c "cmake --build . --target install || exit 1"
else
  sudo cmake --build . --target install || exit 1
fi
popd
pushd Debug
cmake ../.. -DCMAKE_BUILD_TYPE=Debug "$@" || exit 1
if [[ "$OS_NAME" == *"SerenityOS"* ]]; then
    cmake --build . || exit 1
else
    cmake --build . -- -j$build_cores || exit 1
fi
if [[ "$OS_NAME" == *"CLANGARM64"* ]] || [[ "$OS_NAME" == *"CLANG32"* ]] || [[ "$OS_NAME" == *"CLANG64"* ]] || [[ "$OS_NAME" == *"MINGW32"* ]] || [[ "$OS_NAME" == *"MINGW64"* ]] || [[ "$OS_NAME" == *"UCRT64"* ]]; then
  cmake --build . --target install || exit 1
elif [[ "$OS_NAME" == *"SerenityOS"* ]]; then
  su -c "cmake --build . --target install || exit 1"
else
  sudo cmake --build . --target install || exit 1
fi
popd
popd

#_______________________________________________________________________________
#                     Create gui tools shortcut in system operating applications
if [[ "$OS_NAME" == *"MSYS"* ]] || [[ "$OS_NAME" == *"MINGW64"* ]]; then 
  xtd_program_path="$USERPROFILE/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/xtd"
  if [ ! -d "$xtd_program_path" ]; then mkdir -p "$xtd_program_path"; fi
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\keycode.lnk" "$cmake_install_prefix\xtd\bin\keycode.exe"
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\xtdc-gui.lnk" "$cmake_install_prefix\xtd\bin\xtdc-gui.exe"
  scripts/install/shortcut.sh "$USERPROFILE\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd\xguidgen-gui.lnk" "$cmake_install_prefix\xtd\bin\guidgen-gui.exe"
elif [[ "$OS_NAME" == *"Darwin"* ]]; then
  if [ -d "/Applications/keycode" ]; then rm "/Applications/keycode"; fi
  ln -s "$cmake_install_prefix/bin/keycode.app" "/Applications/keycode"
  if [ -d "/Applications/xtdc-gui" ]; then rm "/Applications/xtdc-gui"; fi
  ln -s "$cmake_install_prefix/bin/xtdc-gui.app" "/Applications/xtdc-gui"
  if [ -d "/Applications/guidgen-gui" ]; then rm "/Applications/guidgen-gui"; fi
  ln -s "$cmake_install_prefix/bin/guidgen-gui.app" "/Applications/guidgen-gui"
fi

#_______________________________________________________________________________
#                                      Create xtd root path environment variable

if [[ "$OS_NAME" == *"Darwin"* ]]; then
  echo "export XTD_ROOT_PATH=\"$cmake_install_prefix\"" >> ~/.bash_profile
  echo "export XTD_ROOT_PATH=\"$cmake_install_prefix\"" >> ~/.zprofile
elif [[ "$OS_NAME" == *"FreeBSD"* ]]; then
  echo "export XTD_ROOT_PATH=\"$cmake_install_prefix\"" >> ~/.cshrc
else
  echo "export XTD_ROOT_PATH=\"$cmake_install_prefix\"" >> ~/.bashrc
fi
export XTD_ROOT_PATH=\"$cmake_install_prefix\"

if [[ "$OS_NAME" == *"Darwin"* ]]; then
  echo "export XTD_TOOLKIT_PATH=\"$cmake_install_prefix\"" >> ~/.bash_profile
  echo "export XTD_TOOLKIT_PATH=\"$cmake_install_prefix\"" >> ~/.zprofile
elif [[ "$OS_NAME" == *"FreeBSD"* ]]; then
  echo "export XTD_TOOLKIT_PATH=\"$cmake_install_prefix\"" >> ~/.cshrc
else
  echo "export XTD_TOOLKIT_PATH=\"$cmake_install_prefix\"" >> ~/.bashrc
fi
export XTD_TOOLKIT_PATH=\"$cmake_install_prefix\"

#_______________________________________________________________________________
#                             Copy install manifest files to xtd share directory
if [[ "$OS_NAME" == *"CLANGARM64"* ]] || [[ "$OS_NAME" == *"CLANG32"* ]] || [[ "$OS_NAME" == *"CLANG64"* ]] || [[ "$OS_NAME" == *"MINGW32"* ]] || [[ "$OS_NAME" == *"MINGW64"* ]] || [[ "$OS_NAME" == *"UCRT64"* ]]; then
  if test -f build/3rdparty/wxwidgets/build_cmake/Release/install_manifest.txt; then
    cp build/3rdparty/wxwidgets/build_cmake/Release/install_manifest.txt "$cmake_install_prefix/share/xtd/wxwidgets_release_install_manifest.txt"
  fi
  if test -f build/3rdparty/wxwidgets/build_cmake/Debug/install_manifest.txt; then
    cp build/3rdparty/wxwidgets/build_cmake/Debug/install_manifest.txt "$cmake_install_prefix/share/xtd/wxwidgets_debug_install_manifest.txt"
  fi
  if test -f build/Release/install_manifest.txt; then
    cp build/Release/install_manifest.txt "$cmake_install_prefix/share/xtd/xtd_release_install_manifest.txt"
  fi
  if test -f build/Debug/install_manifest.txt; then
    cp build/Debug/install_manifest.txt "$cmake_install_prefix/share/xtd/xtd_debug_install_manifest.txt"
  fi
else
  if test -f build/3rdparty/wxwidgets/build_cmake/Release/install_manifest.txt; then
    sudo cp build/3rdparty/wxwidgets/build_cmake/Release/install_manifest.txt $cmake_install_prefix/share/xtd/wxwidgets_release_install_manifest.txt
  fi
  if test -f build/3rdparty/wxwidgets/build_cmake/Debug/install_manifest.txt; then
    sudo cp build/3rdparty/wxwidgets/build_cmake/Debug/install_manifest.txt $cmake_install_prefix/share/xtd/wxwidgets_debug_install_manifest.txt
  fi
  if test -f build/Release/install_manifest.txt; then
    sudo cp build/Release/install_manifest.txt $cmake_install_prefix/share/xtd/xtd_release_install_manifest.txt
  fi
  if test -f build/Debug/install_manifest.txt; then
    if [[ "$OS_NAME" == *"SerenityOS"* ]]; then
      su -c "cp build/Debug/install_manifest.txt $cmake_install_prefix/share/xtd/xtd_debug_install_manifest.txt"
    else
    sudo cp build/Debug/install_manifest.txt $cmake_install_prefix/share/xtd/xtd_debug_install_manifest.txt
    fi
  fi
fi

#_______________________________________________________________________________
#                                                                 Launch xtd-gui
echo "Launching xtdc-gui..."
if [[ "$OS_NAME" == *"CLANGARM64"* ]] || [[ "$OS_NAME" == *"CLANG32"* ]] || [[ "$OS_NAME" == *"CLANG64"* ]] || [[ "$OS_NAME" == *"MINGW32"* ]] || [[ "$OS_NAME" == *"MINGW64"* ]] || [[ "$OS_NAME" == *"UCRT64"* ]]; then
  "$cmake_install_prefix/xtd/bin/xtdc-gui.exe"
elif [[ "$OS_NAME" == *"Darwin"* ]]; then
  open $cmake_install_prefix/bin/xtdc-gui.app; 
elif [[ "$OS_NAME" == *"SerenityOS"* ]]; then
  echo "SerenityOS does not support xtdc-gui now."
else
  $cmake_install_prefix/bin/xtdc-gui &>/dev/null &
fi

#_______________________________________________________________________________
#                                                                  Final message
echo ""
echo "---------------------------------------------------------------"
echo "xtd version $xtd_version installed successfully."
echo "Root path      : $cmake_install_prefix"
echo "For more information, see :"
echo "   https://gammasoft71.github.io/xtd/"
echo "---------------------------------------------------------------"
