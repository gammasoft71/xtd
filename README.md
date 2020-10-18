[![environment](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-environment)

[![Build Status](https://travis-ci.org/gammasoft71/xtd_diagnostics.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd_diagnostics)
[![Build status](https://ci.appveyor.com/api/projects/status/2nlokdfs0w3c3jdx?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-diagnostics)
[![Reference Guide](https://img.shields.io/badge/code-Reference_Guide-brightgreen.svg)](https://codedocs.xyz/gammasoft71/xtd_diagnostics/)
[![Documentation](https://img.shields.io/badge/wiki-Documentaions-brightgreen.svg)](./README.md)
[![Website](https://img.shields.io/badge/web-gammasoft-brightgreen.svg)](https://gammasoft71.wixsite.com/gammasoft)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.environment.svg)](LICENSE.md)
<!--- [![Download diagnostics](https://img.shields.io/sourceforge/dt/environmentpro.svg)](https://sourceforge.net/projects/environmentpro//files/latest/download) --->
<!--- [![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.environment.svg)](README.md) --->
<!--- [![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md) --->
<!--- [![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md) --->
<!--- [![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md) --->
<!--- [![codecov](https://codecov.io/gh/gammasoft71/xtd.environment/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.environment) --->

# Features

For more information see [Documentation](docs).

# Examples

The classic first application 'Hello World'.

src/ctrace_hello_world.cpp:

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

project(ctrace_hello_world)
find_package(xtd.diagnostics REQUIRED)
add_executable(${PROJECT_NAME} src/ctrace_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.diagnostics)
```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install environment. To download and install it read Downloads file.

