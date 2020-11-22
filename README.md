[![console](docs/pictures/header.png)](https://gammasoft71.wixsite.com/gammasoft)

[![Build Status](https://travis-ci.org/gammasoft71/xtd.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd)
[![Build status](https://ci.appveyor.com/api/projects/status/uqn1xbctwy88eghu?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd)
[![Reference Guide](https://img.shields.io/badge/code-Reference_Guide-brightgreen.svg)](https://codedocs.xyz/gammasoft71/xtd/)
[![Wiki](https://img.shields.io/badge/wiki-Home-brightgreen.svg)](./docs/home.md)
[![Website](https://img.shields.io/badge/web-gammasoft-brightgreen.svg)](https://gammasoft71.wixsite.com/gammasoft)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.svg)](LICENSE.md)
<!--- 
[![Download xtd](https://img.shields.io/sourceforge/dt/xtdpro.svg)](https://sourceforge.net/projects/xtdpro/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)
[![codecov](https://codecov.io/gh/gammasoft71/xtd/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd)
 --->

# Features

* a collection of native C++ classes libraries, to complete std;
* written in efficient, modern C++17;
* and highly portable and available on many different platforms (Windows, macOS, Linux, iOS and android);

For more information see [documentations](docs/home.md) ([website](https://gammasoft71.wixsite.com/gammasoft)) and [Reference Guide](https://codedocs.xyz/gammasoft71/xtd/).

# Examples

The classic first application 'Hello World'.

## Console

hello_world_console.cpp:

```c++
#include <xtd/xtd>

using namespace xtd;

int main() {
  console::background_color(console_color::blue);
  console::foreground_color(console_color::white);
  console::write_line("Hello, World!");
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_console)
find_package(xtd.forms REQUIRED)
add_sources(hello_world_console.cpp)
target_type(CONSOLE_APPLICATION)
```

## Forms

hello_world_forms.cpp:

```c++
#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  button button;
  button.text("Click me");
  button.location({10, 10});
  button.click += [] {
    message_box::show("Hello, World!");
  };
  
  form form;
  form.text("Hello world (message_box)");
  form.controls().push_back(button);
  
  application::run(form);
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_message_box)
find_package(xtd.forms REQUIRED)
add_sources(hello_world_message_box.cpp)
target_type(GUI_APPLICATION)
```

## Unit tests

hello_world_tunit.cpp:

```c++
#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(hello_world_test) {
  public:
    void test_method_(create_string_from_literal) {
      string s = "Hello, World!";
      valid::are_equal(13, s.size());
      assert::are_equal("Hello, World!", s);
    }
    
    void test_method_(create_string_from_chars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid::are_equal(13, s.size());
      string_assert::starts_with("Hello,", s);
      string_assert::ends_with(" World!", s);
    }
  };
}

int main() {
  return console_unit_test().run();
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_tunit)
find_package(xtd.forms REQUIRED)
add_sources(hello_world_tunit.cpp)
target_type(TEST_APPLICATION)
```

For more examples see [examples](examples/README.md)

# Download and install

Before running examples you must download and install xtd. To download and install it read [downloads](docs/downloads.md) file.

<!---
# Motivations

## All xtd libraries

* Modern C++17 only
* std c++ design guidelines.
* Multiplatform (Windows, macOS, Android and ios and linux base oprating system).

## xtd.tunit

* Create a full [xunit](https://en.wikipedia.org/wiki/XUnit) unit testing library in C++17 with an api closely to [NUnit](https://nunit.org) for C# and [Microsoft.VisualStudio.TestTools.CppUnitTestFramework](https://docs.microsoft.com/en-us/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference?view=vs-2019) for C++ on Windows.

## xtd.system

* Basic extend of std c++. The objectevie is not to replace [boost](https://www.boost.org) but get acces to a basic and simple api. For more complex development, it recommanded to use [boost](https://www.boost.org).
* Basic string formater and parser. The objectevie is not to replace [fmtlib ](https://github.com/fmtlib/fmt) but get a basic and simple api to wait C++20 string format and string parse.
* Implement Multicast delegates with easy registration (+= operator) and unregistration (-= operator) with event safe invocation by creator only.

## xtd.console

* Create a simple and light multiplatform console api compatible with std::stream (with an easy way redirection like std) with cursor visibility, background and forground color, position and size of console and more.

## xtd.forms

* Create a modern api for gui application (like Winforms in .Net).
* If during development you are wondering about the allocated object, should you or should you not delete the pointer? Should you destroy it or not? Or in some cases do nothing. Or if a control must obligatorily be created with the operator new and not on the stack. I think it's all too complex and it can create memory leaks or even crashes.  That's why a simple and unequivocal RAI api is preferable.
* A gui must follow the de operating system design guidelines. And sometimes if you want customize your application, not.
* After reading [List of widget toolkits](https://en.wikipedia.org/wiki/List_of_widget_toolkits) and the [Philippe Groarke C++ UI Libraries post](https://philippegroarke.com/posts/2018/c++_ui_solutions/). I don't find a gui api more simple as Winforms C# or Borland C++ builder.
* 
--->
