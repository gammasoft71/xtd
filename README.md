[![tunit](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-tunit)

[![Build Status](https://travis-ci.org/gammasoft71/xtd.tunit.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd.tunit)
[![Build status](https://ci.appveyor.com/api/projects/status/tark5puo8mou967a?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-tunit)
[![codecov](https://codecov.io/gh/gammasoft71/xtd.tunit/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.tunit)
[![Documentation](https://codedocs.xyz/gammasoft71/xtd.tunit.svg)](https://codedocs.xyz/gammasoft71/xtd.tunit/)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-tunit%20website)](https://gammasoft71.wixsite.com/xtd-tunit)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.tunit.svg)](LICENSE.md)
[![SourceForge Download tunit](https://img.shields.io/sourceforge/dt/tunitpro.svg)](https://sourceforge.net/projects/tunitpro//files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.tunit.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)

# Features

For more information see [Documentation](docs).

# Examples

The classic first application 'Hello World'.

src/tunit_hello_world.cpp:

```c++
#include <xtd/tunit>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << "Hello, World !) << endl;
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(string_hello_world)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/tunit_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install tunit. To download and install it read Downloads file.

