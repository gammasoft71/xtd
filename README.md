[![tunit](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-tunit)

[![Build Status](https://travis-ci.org/gammasoft71/xtd.tunit.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd.tunit)
[![Build status](https://ci.appveyor.com/api/projects/status/1h8y1d4lodnk1wbb?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-tunit)
[![codecov](https://codecov.io/gh/gammasoft71/xtd.tunit/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.tunit)
[![Documentation](https://codedocs.xyz/gammasoft71/xtd.tunit.svg)](https://codedocs.xyz/gammasoft71/xtd.tunit/)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-tunit%20website)](https://gammasoft71.wixsite.com/xtd-tunit)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.tunit.svg)](LICENSE.md)
[![SourceForge Download tunit](https://img.shields.io/sourceforge/dt/tunitpro.svg)](https://sourceforge.net/projects/tunitpro/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.tunit.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)

Modern c++17 unit testing library on Windows, macOS, Linux, iOS and android.

# Features

* An [xUnit](https://en.wikipedia.org/wiki/XUnit) test framework.
* Modern c++17.
* Auto registration of class and method based tests.
* Rich set of assertions.
* std::ostream output event listener.
* You can create your own event listener (see [create_your_own_event_listener example](examples/create_your_own_event_listener)).
* Gets duration for each test, and for each class test.
* CMake build script.
* Very easy to use.
* ...

# Platforms

* Windowd
* macOS X
* Linux
* iOS
* android

# Examples

The classic first application 'Hello World'.

src/tunit_hello_world.cpp:

```c++
#include <xtd/tunit>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(hello_world_test) {
  public:
    void test_method_(create_string_from_literal) {
      string s = "Hello, World!";
      assert::are_equal_("Hello, World!", s);
    }
    
    void test_method_(create_string_from_chars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      assert::are_equal_("Hello, World!", s);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(tunit_hello_world)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/tunit_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
```

Output:
```
Start 2 tests from 1 test case
  Start 2 tests from hello_world_test
    PASSED create_string_from_literal (0 ms total)
    PASSED create_string_from_chars (0 ms total)
  End 2 tests from hello_world_test (0 ms total) 

  Summary :
    PASSED 2 tests.
End 2 tests from 1 test case ran. (0 ms total)
```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install tunit. To download and install it read [downloads](docs/downloads.md) file.

______________________________________________________________________________________________

© 2019 Gammasoft.
