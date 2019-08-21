[![console](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-console)

[![Build Status](https://travis-ci.org/gammasoft71/xtd.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd)
[![Build status](https://ci.appveyor.com/api/projects/status/uqn1xbctwy88eghu?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd)
[![codecov](https://codecov.io/gh/gammasoft71/xtd/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd)
[![Documentation](https://codedocs.xyz/gammasoft71/xtd.svg)](https://codedocs.xyz/gammasoft71/xtd/)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-console%20website)](https://gammasoft71.wixsite.com/xtd-console)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.svg)](LICENSE.md)
[![Download xtd](https://img.shields.io/sourceforge/dt/xtdpro.svg)](https://sourceforge.net/projects/xtdpro/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)

# Features

For more information see [Documentation](docs).

# Libraries

|                                                                                                               | Libraries                                                          | Github sources                                            | Reference guide                                          |
|---------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------|-----------------------------------------------------------|----------------------------------------------------------|
| [![xtd_console_logo](docs/pictures/xtd.console.png)](https://gammasoft71.wixsite.com/xtd-console)             | [xtd.console](https://gammasoft71.wixsite.com/xtd-console)         | [sources](https://github.com/gammasoft71/xtd.console)     | [ref](https://codedocs.xyz/gammasoft71/xtd.console/)     |
| [![xtd_delegates_logo](docs/pictures/xtd.delegates.png)](https://gammasoft71.wixsite.com/xtd-delegates)       | [xtd.delegates](https://gammasoft71.wixsite.com/xtd-delegates)     | [sources](https://github.com/gammasoft71/xtd.delegates)   | [ref](https://codedocs.xyz/gammasoft71/xtd.delegates/)   |
| [![xtd_diagnostics_logo](docs/pictures/xtd.diagnostics.png)](https://gammasoft71.wixsite.com/xtd-diagnostics) | [xtd.diagnostics](https://gammasoft71.wixsite.com/xtd-diagnostics) | [sources](https://github.com/gammasoft71/xtd.diagnostics) | [ref](https://codedocs.xyz/gammasoft71/xtd.diagnostics/) |
| [![xtd_drawing_logo](docs/pictures/xtd.drawing.png)](https://gammasoft71.wixsite.com/xtd-drawing)             | [xtd.drawing](https://gammasoft71.wixsite.com/xtd-drawing)         | [sources](https://github.com/gammasoft71/xtd.drawing)     | [ref](https://codedocs.xyz/gammasoft71/xtd.drawing/)     |
| [![xtd_environment_logo](docs/pictures/xtd.environment.png)](https://gammasoft71.wixsite.com/xtd-environment) | [xtd.environment](https://gammasoft71.wixsite.com/xtd-environment) | [sources](https://github.com/gammasoft71/xtd.environment) | [ref](https://codedocs.xyz/gammasoft71/xtd.environment/) |
| [![xtd_forms_logo](docs/pictures/xtd.forms.png)](https://gammasoft71.wixsite.com/xtd-forms)                   | [xtd.forms](https://gammasoft71.wixsite.com/xtd-forms)             | [sources](https://github.com/gammasoft71/xtd.forms)       | [ref](https://codedocs.xyz/gammasoft71/xtd.forms/)       |
| [![xtd_io_logo](docs/pictures/xtd.io.png)](https://gammasoft71.wixsite.com/xtd-io)                            | [xtd.io](https://gammasoft71.wixsite.com/xtd-io)                   | [sources](https://github.com/gammasoft71/xtd.io)          | [ref](https://codedocs.xyz/gammasoft71/xtd.io/)          |
| [![xtd_properties_logo](docs/pictures/xtd.properties.png)](https://gammasoft71.wixsite.com/xtd-properties)    | [xtd.properties](https://gammasoft71.wixsite.com/xtd-properties)   | [sources](https://github.com/gammasoft71/xtd.properties)  | [ref](https://codedocs.xyz/gammasoft71/xtd.properties/)  |
| [![xtd_strings_logo](docs/pictures/xtd.strings.png)](https://gammasoft71.wixsite.com/xtd-strings)             | [xtd.strings](https://gammasoft71.wixsite.com/xtd-strings)         | [sources](https://github.com/gammasoft71/xtd.strings)     | [ref](https://codedocs.xyz/gammasoft71/xtd.strings/)     |
| [![xtd_tunit_logo](docs/pictures/xtd.tunit.png)](https://gammasoft71.wixsite.com/xtd-tunit)                   | [xtd.tunit](https://gammasoft71.wixsite.com/xtd-tunit)             | [sources](https://github.com/gammasoft71/xtd.tunit)       | [ref](https://codedocs.xyz/gammasoft71/xtd.tunit/)       |

# Examples

The classic first application 'Hello World'.

## Console

src/hello_world_console.cpp:

```c++
#include <xtd/xtd>
#include <string>

using namespace std;
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
find_package(xtd REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_console.cpp)
target_link_libraries(${PROJECT_NAME} xtd)
```

## Forms

src/hello_world_forms.cpp:

```c++
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

int main() {
  button button;
  button.text("Click me");
  button.location({10, 10});
  button.click += [&](const control& sender, const event_args& e) {
    message_box::show("Hello, World!");
  };
  
  form form;
  form.text("Hello World Form");
  form.controls().push_back(button);
  
  application::run(form);
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_forms)
find_package(xtd REQUIRED)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE src/hello_world_forms.cpp)
target_link_libraries(${PROJECT_NAME} xtd)
```

## Unit tests

src/hello_world_tunit.cpp:

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

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_tunit)
find_package(xtd REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_tunit.cpp)
target_link_libraries(${PROJECT_NAME} xtd)
```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install xtd. To download and install it read Downloads file.

