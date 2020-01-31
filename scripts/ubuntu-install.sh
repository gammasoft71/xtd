#!/usr/bin/env sh

# from https://www.binarytides.com/install-wxwidgets-ubuntu/

# install build tools and libs
sudo apt-get update
sudo apt-get install libgtk-3-dev build-essential checkinstall git cmake

# updates submodule projects
git submodule update --init

# build and install wxWidgets
cd wxWidgets
mkdir gtk-build
cd gtk-build
../configure --disable-shared --enable-unicode
make -j 4
sudo checkinstall -y
cd ../..

# build   nd install xtd.forms
mkdir cmake-build
cd cmake-build
cmake -DENABLE_TESTS=ON ..
cmake --build . --target install -- -j 4
