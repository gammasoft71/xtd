# xtd

[![xtd](docs/pictures/xtd_header.png)](https://gammasoft71.wixsite.com/xtdpro)

Modern c++17 / c++20 framework to create console, gui and unit test applications on Microsoft Windows, Apple macOS and Linux.

[![Build Status](https://travis-ci.com/gammasoft71/xtd.svg?branch=master)](https://travis-ci.com/gammasoft71/xtd)
[![Build status](https://ci.appveyor.com/api/projects/status/uqn1xbctwy88eghu?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd)
[![Reference Guide](https://img.shields.io/badge/code-Reference_Guide-brightgreen.svg)](https://codedocs.xyz/gammasoft71/xtd/)
[![Website](https://img.shields.io/badge/web-xtdpro-brightgreen.svg)](https://gammasoft71.wixsite.com/xtdpro)
[![MD](https://img.shields.io/badge/markdown-documentations-brightgreen.svg)](./docs/home.md)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.svg)](LICENSE.md)

## Features

* a collection of native C++ classes libraries, to complete std;
* written in efficient, modern C++17 / C++20;
* and highly portable and available on many different platforms (Windows, macOS, Linux, iOS and android);

For more information see [website](https://gammasoft71.wixsite.com/xtdpro) (or [markdown documentations](https://github.com/gammasoft71/xtd/blob/master/docs/home.md)), [sources](https://github.com/gammasoft71/xtd) and [Reference Guide](https://codedocs.xyz/gammasoft71/xtd/).

## Examples

The classic first application 'Hello World'.

### Console

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

#### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

#### Output

```
Hello, World!
```

### GUI

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

#### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

#### Output

##### Windows :

![Screenshot](docs/pictures/examples/hello_world_message_box_w.png)

![Screenshot](docs/pictures/examples/hello_world_message_box_wd.png)

##### macOS :

![Screenshot](docs/pictures/examples/hello_world_message_box_m.png)

![Screenshot](docs/pictures/examples/hello_world_message_box_md.png)

##### Linux Gnome :

![Screenshot](docs/pictures/examples/hello_world_message_box_g.png)

![Screenshot](docs/pictures/examples/hello_world_message_box_gd.png)

### Unit tests

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

#### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

#### Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED hello_world_test.create_string_from_literal (0 ms total)
  SUCCEED hello_world_test.create_string_from_chars (0 ms total)

Test results:
  SUCCEED 2 tests.
End 2 tests from 1 test case ran. (0 ms total)
```

## Getting Started

* [Installation](docs/downloads.md) provides download and install documentation.
* [Portability](docs/portability.md) provides information about C++, libraries dependency, Operating System suported, Compilators and Devepment Environment tools.
* [Examples](examples/README.md) provides some examples.
