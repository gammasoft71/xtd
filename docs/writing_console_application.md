| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Writing console application

## In this section

* [Create console](#create-console)
* [Adding a write line and read line](#adding-a-write-line-and-read-line)
* [Example](#example)

This tutorial describe the basic steps that you must complete to create and run a console application from the command line.

## Create console

The following procedures describe the basic steps that you must complete to create and run a console application from the command line.

### To create the console

1. Create console1.cpp file in your project folder and type the following include file and using statements:

```c++
#include <xtd/xtd>

using namespace xtd;
```

2. Declare a class named **console1**.

```c++
class console1
```

3. Create a default constructor for **console1**.

You will add more code to the constructor in a subsequent procedure.

```c++
  public:
    console1() {}
```

4. Add a main method.

Create an instance of the **console1**.

```c++
int main() {
  console1();
}
```

### To create the CMakeLists.txt

1. Create CMakeLists.txt file in your project folder and add the cmake minimum version required.

```cmake
cmake_minimum_required(VERSION 3.3)
```

2. Set the project name and add xtd.forms package.

```cmake
Project(console1)
find_package(xtd REQUIRED)
```

3. Add build rules for the he project.

```cmake
add_sources(console1.cpp)
target_type(CONSOLE_APPLICATION)
```

### To compile and run the application

1. At the Terminal, navigate to the directory you created the console1.cpp class and CMakeLists.txt file.

2. Compile the console.

```shell
xtdc build
```

3. At the command prompt, type:

```shell
xtdc run
```

## Adding a write line and read line

The previous procedure steps demonstrated how to just create a basic consolecthat compiles and runs.

### To change background and forground colors and write and read line with the console

1. Change background color
2. Change foreground color
3. Write desired text to the console.
4. Ask user and write result in **name**.
5. Write formated result to the console.

The following code example demonstrates how to write and read with the console.

```c++
  console1() {
    console::background_color(console_color::blue);
    console::foreground_color(console_color::white);
    console::write_line("What's your name ?");
    auto name = console::read_line();
    console::write_line("Hello, {}", name);
  }
```

6. Compile and run the application.

```shell
xtdc run
```

## Example

Following code example is the complete example from the previous tutorial.

console1.cpp:

```c++
#include <xtd/xtd>

using namespace xtd;

class console1 {
public:
  console1() {
    console::background_color(console_color::blue);
    console::foreground_color(console_color::white);
    console::write_line("What's your name ?");
    auto name = console::read_line();
    console::write_line("Hello, {}", name);
  }
};

int main() {
  console1();
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(console1)
find_package(xtd REQUIRED)
add_sources(console1.cpp)
target_type(CONSOLE_APPLICATION)
```

## See also

* [Writing applicattions](writing_applications.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
