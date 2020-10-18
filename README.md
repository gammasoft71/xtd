[![tunit](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-tunit)

[![Build Status](https://travis-ci.org/gammasoft71/xtd_io.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd_io)
[![Build status](https://ci.appveyor.com/api/projects/status/qverymyu0fopqnt4?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-io)
[![Reference Guide](https://img.shields.io/badge/code-Reference_Guide-brightgreen.svg)](https://codedocs.xyz/gammasoft71/xtd_io/)
[![Documentation](https://img.shields.io/badge/wiki-Documentaions-brightgreen.svg)](./README.md)
[![Website](https://img.shields.io/badge/web-gammasoft-brightgreen.svg)](https://gammasoft71.wixsite.com/gammasoft)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.io.svg)](LICENSE.md)
<!--- 
[![Download xtd.io](https://img.shields.io/sourceforge/dt/iopro.svg)](https://sourceforge.net/projects/iopro/files/latest/download)
[![c++17](https://img.shields.io/badge/c++-17-004080.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](https://en.wikipedia.org/wiki/Microsoft_Windows)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](https://en.wikipedia.org/wiki/MacOS)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](https://en.wikipedia.org/wiki/Linux)
[![iOS](https://img.shields.io/badge/os-iOS-004080.svg)](https://en.wikipedia.org/wiki/IOS)
[![android](https://img.shields.io/badge/os-android-004080.svg)](https://en.wikipedia.org/wiki/Android_(operating_system))
[![codecov](https://codecov.io/gh/gammasoft71/xtd.io/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.io) 
--->

xtd.io is a modern c++17 library, that allow reading and writing to files and data streams, and that provide basic file and directory support, for Windows, macOS, Linux, iOS and android.

# Features

* File : Provides methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::basic_fstream objects.
* Path : Performs operations on std::basic_string instances that contain file or directory path information. These operations are performed in a cross-platform manner.
For more information see [xtd.io website](https://gammasoft71.wixsite.com/xtd-io) (or [markdown documentations](docs/home.md)) and [Reference Guide](https://codedocs.xyz/gammasoft71/xtd.io/).

# Examples

The classic first application 'Hello World'.

src/tunit_hello_world.cpp:

```c++
#include <xtd/xtd.io>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd::io;

// The main entry point for the application.
int main(int argc, char* argv[]) {
  string file_name = path::combine(path::get_temp_path(), "file.txt");
  
  file::write_all_text(file_name, "Hello, World!");
  cout << file::read_all_text(file_name) << endl;
  
  file::remove(file_name);
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(io_hello_world)
find_package(xtd.io REQUIRED)
add_executable(${PROJECT_NAME} src/io_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.io)
```

Output:
```
Hello, World!
```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install tunit. To download and install it read [downloads](docs/downloads.md) file.

______________________________________________________________________________________________

© 2019 Gammasoft.
