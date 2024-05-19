## A simple application

First we create the very basic [xtd_forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__gui.html) program.

```cpp
#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace tutorial {
  class simple : public form {
  public:
    simple() {
      text("Simple");
      start_position(form_start_position::center_screen);
    }

    static auto main() {
      xtd::forms::application::run(simple());
    }
  };
}

startup_(tutorial::simple::main);
```

This very basic example shows a small window on the screen. The window is centered.

```cpp
start_position(form_start_position::center_screen);
```

This method centers the form on the screen, both horizontally and vertically.

```cpp
startup_(tutorial::simple::main);
```

The code behind startup_ macro can be replaced by :

```cpp
auto main(int argc, char* argv[]) -> int {
  tutorial::simple::main();
  return xtd::environment::exit_code();
}
```

This example can be build on Windows, macOS or Linux operating system with CMake.

```cmake
cmake_minimum_required(VERSION 3.5)

project(simple)
find_package(xtd.forms REQUIRED)
add_sources(src/simple.cpp)
target_type(GUI_APPLICATION)
```

See [cmake](https://cmake.org) for more information.

![Screenshot](../../../../docs/pictures/examples/tutorial/simple.png)

Figure: simple
