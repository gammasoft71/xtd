---
sidebar_position: 12
---

# Writing console application

## In this section

* [Create console](#create-console)
* [Adding a write line and read line](#adding-a-write-line-and-read-line)
* [Example](#example)

This tutorial describes the basic steps that you must complete to create and run a console application from the command line.

## Create console

The following procedures describe the basic steps that you must complete to create and run a console application from the command line.

### To create the console

1. Create console1.cpp file in your project folder and type the following include file and using statements:

```cpp
#include <xtd/xtd>

using namespace xtd;
```

2. Declare a class named **console1**.

```cpp
class console1
```

3. Create a default constructor for **console1**.

You will add more code to the constructor in a subsequent procedure.

```cpp
  public:
    console1() {}
```

4. Add a main method.

Create an instance of the **console1**.

```cpp
auto main() -> int {
  console1 {};
}
```

### To create the CMakeLists.txt

1. Create CMakeLists.txt file in your project folder and add the cmake minimum version required.

```cmake
cmake_minimum_required(VERSION 3.20)
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

The previous procedure steps demonstrated how to just create a basic console that compiles and runs.

### To change background and foreground colors and write and read line with the console

1. Change background color
2. Change foreground color
3. Write desired text to the console.
4. Ask user and write result in **name**.
5. Write formatted result to the console.

The following code example demonstrates how to write and read with the [console](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html).

```cpp
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

```cpp
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

auto main() -> int {
  console1 {};
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.20)

project(console1)
find_package(xtd REQUIRED)
add_sources(console1.cpp)
target_type(CONSOLE_APPLICATION)
```

## See also

* [tutorials](/docs/documentation/guides/Overview/Tutorials)
* [Documentation](/docs/documentation)
