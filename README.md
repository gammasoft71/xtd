[![strings](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-strings)

[![Build Status](https://travis-ci.org/gammasoft71/xtd_strings.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd_strings)
[![Build status](https://ci.appveyor.com/api/projects/status/tark5puo8mou967a?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-strings)
[![codecov](https://codecov.io/gh/gammasoft71/xtd.strings/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.strings)
[![Documented](https://codedocs.xyz/gammasoft71/xtd.strings.svg)](https://codedocs.xyz/gammasoft71/xtd.strings/)
[![Documentation](https://img.shields.io/badge/wiki-Documentation-brightgreen.svg)](./docs/documentation.md)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-strings%20website)](https://gammasoft71.wixsite.com/xtd-strings)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.strings.svg)](LICENSE.md)
[![SourceForge Download strings](https://img.shields.io/sourceforge/dt/stringspro.svg)](https://sourceforge.net/projects/stringspro//files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.strings.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)

# Features

* New istring, iu16string, iu32string, iwstring immutable string types and immutable_string_base immutable string class.
* Immutable string litteral operators _is.
* String format helper.
* String concat helper.
* String padding helper.
* Join strings helper.
* Split strings helper.
* and more...

For more information see [Documentation](docs).

# Examples

The classic first application 'Hello World'.

src/string_hello_world.cpp:

```c++
#include <xtd/xtd.strings>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << format("{}, {}!", "Hello", "World"s) << endl;
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(string_hello_world)
find_package(xtd.strings REQUIRED)
add_executable(${PROJECT_NAME} src/string_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.strings)
```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install strings. To download and install it read Downloads file.

