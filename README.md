[![core](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-core)

[![Build Status](https://travis-ci.org/gammasoft71/xtd_core.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd_core)
[![Build status](https://ci.appveyor.com/api/projects/status/xyvw3hfkimvkyxr2?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-core)
[![Reference Guide](https://img.shields.io/badge/code-Reference_Guide-brightgreen.svg)](https://codedocs.xyz/gammasoft71/xtd-core/)
[![Website](https://img.shields.io/badge/web-xtd-brightgreen.svg)](https://gammasoft71.wixsite.com/gammasoft)
[![license](https://img.shields.io/github/license/gammasoft71/xtd_core.svg)](LICENSE.md)
<!--- [![Download core](https://img.shields.io/sourceforge/dt/corepro.svg)](https://sourceforge.net/projects/corepro//files/latest/download) --->
<!--- [![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.core.svg)](README.md) --->
<!--- [![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md) --->
<!--- [![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md) --->
<!--- [![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md) --->
<!--- [![codecov](https://codecov.io/gh/gammasoft71/xtd.core/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd-coret) --->

# Features

For more information see [Documentation](docs).

# Examples

The classic first application 'Hello World'.

src/core_hello_world.cpp:

```c++
#include <xtd/xtd.core>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << "Hello, " << core::user_name() << "!" << endl;
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(string_hello_world)
find_package(xtd.core REQUIRED)
add_executable(${PROJECT_NAME} src/core_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.coree)
```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install core. To download and install it read Downloads file.

