| [Home](home.md) | [Downloads](downloads.md) | [Examples](examples.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd_forms) | [Project](https://sourceforge.net/projects/formspro/) | [Contact](contact.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |

# Example

The following examples "Hello, world!" show how use form and button control, catch event click and show a message box.

## forms_hello_world.cpp

```c++
#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  button button1;
  button1.text("Click me");
  button1.location({10, 10});
  button1.click += [] {
    message_box::show("Hello, World!");
  };

  form form1;
  form1.text("Hello world (message_box)");
  form1.controls().push_back(button1);

  application::run(form1);
}

```

## CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_message_box)
find_package(xtd.forms REQUIRED)
add_sources(hello_world_message_box.cpp)
target_type(GUI_APPLICATION)
```

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtd run
```

## Output

### Windows :

![Screenshot](pictures/examples/hello_world_message_box_w.png)

### macOS :

![Screenshot](pictures/examples/hello_world_message_box_m.png)

![Screenshot](pictures/examples/hello_world_message_box_md.png)

### Linux Gnome :

![Screenshot](pictures/examples/hello_world_message_box_g.png)

![Screenshot](pictures/examples/hello_world_message_box_gd.png)

[Click here to see more examples](../examples/README.md)

______________________________________________________________________________________________

© 2020 Gammasoft.
