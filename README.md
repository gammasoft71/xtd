[![environment](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-environment)

[![Build Status](https://travis-ci.org/gammasoft71/xtd_diagnostics.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd_diagnostics)
[![Build status](https://ci.appveyor.com/api/projects/status/2nlokdfs0w3c3jdx?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-diagnostics)
[![codecov](https://codecov.io/gh/gammasoft71/xtd.environment/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.environment)
[![Documentation](https://codedocs.xyz/gammasoft71/xtd.environment.svg)](https://codedocs.xyz/gammasoft71/xtd.environment/)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-environment%20website)](https://gammasoft71.wixsite.com/xtd-environment)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.environment.svg)](LICENSE.md)
[![SourceForge Download environment](https://img.shields.io/sourceforge/dt/environmentpro.svg)](https://sourceforge.net/projects/environmentpro//files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.environment.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)

# Features

For more information see [Documentation](docs).

# Examples

The classic first application 'Hello World'.

src/environment_hello_world.cpp:

```c++
#define TRACE
#include <xtd/xtd.diagnostics>
#include <iostream>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  ctrace << "Hello, World!" << endl;
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(string_hello_world)
find_package(xtd.environment REQUIRED)
add_executable(${PROJECT_NAME} src/environment_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.environment)
```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install environment. To download and install it read Downloads file.

