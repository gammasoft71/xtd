| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Examples

The classic first applications 'Hello World'.

## Console

### hello_world_console.cpp:

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  console::background_color(console_color::blue);
  console::foreground_color(console_color::white);
  console::write_line("Hello, World!");
}
```

### CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.20)

project(hello_world_console)
find_package(xtd REQUIRED)
add_sources(hello_world_console.cpp)
target_type(CONSOLE_APPLICATION)
```

### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

### Output

```
Hello, World!
```

## Gui

### hello_world_form.cpp

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    text("Hello world (message_box)");

    button1.location({10, 10});
    button1.parent(*this);
    button1.text("&Click me");
    button1.click += [] {
      message_box::show("Hello, World!");
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(main_form());
}
```

### CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.20)

project(hello_world_form)
find_package(xtd REQUIRED)
add_sources(hello_world_form.cpp)
target_type(GUI_APPLICATION)
```

### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

### Output

#### Windows :

![Screenshot](pictures/examples/hello_world_message_box_w.png)

![Screenshot](pictures/examples/hello_world_message_box_wd.png)

#### macOS :

![Screenshot](pictures/examples/hello_world_message_box_m.png)

![Screenshot](pictures/examples/hello_world_message_box_md.png)

#### Linux Gnome :

![Screenshot](pictures/examples/hello_world_message_box_g.png)

![Screenshot](pictures/examples/hello_world_message_box_gd.png)

## Unit tests

### hello_world_test.cpp:

```cpp
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

auto main() -> int {
  return console_unit_test().run();
}
```

### CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.20)

project(hello_world_test)
find_package(xtd REQUIRED)
add_sources(hello_world_test.cpp)
target_type(TEST_APPLICATION)
```

### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

### Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED hello_world_test.create_string_from_literal (0 ms total)
  SUCCEED hello_world_test.create_string_from_chars (0 ms total)

Test results:
  SUCCEED 2 tests.
End 2 tests from 1 test case ran. (0 ms total)
```

## More examples

[Example](../examples/README.md) provides over 750 examples to help you use xtd, grouped by libraries and topics.

# Support

If you face any problems feel free to open an issue at the [issues tracker](https://github.com/gammasoft71/xtd/issues), If you feel like there is a missing feature, please raise a ticket on Github. Pull request are also welcome.

______________________________________________________________________________________________

© 2024 Gammasoft.
