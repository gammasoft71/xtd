---
sidebar_position: 13
---

# Writing GUI application

## In this section

* [Create GUI](#create-gui)
* [Adding a Control and Handling an Event](#adding-a-control-and-handling-an-event)
* [Example](#example)

This tutorial describes the basic steps that you must complete to create and run a GUI application from the command line.

## Create GUI

The following procedures describe the basic steps that you must complete to create and run a GUI application from the command line.

### To create the form

1. Create form1.cpp file in your project folder and type the following include file and using statements:

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;
```

2. Declare a class named **form1** that inherits from the [form](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html) class.

```cpp
class form1 : public form
```

3. Create a default constructor for **form1**.

You will add more code to the constructor in a subsequent procedure.

```cpp
  public:
    form1() {}
```

4. Add a main method.

Create an instance of the **form1** and run it.

```cpp
auto main() -> int {
  application::run(form1 {});
}
```

### To create the CMakeLists.txt

1. Create CMakeLists.txt file in your project folder and add the cmake minimum version required.

```cmake
cmake_minimum_required(VERSION 3.20)
```

2. Set the project name and add xtd package.

```cmake
Project(form1)
find_package(xtd REQUIRED)
```

3. Add build rules for the project.

```cmake
add_sources(form1.cpp)
target_type(GUI_APPLICATION)
```

### To compile and run the application

1. At the Terminal, navigate to the directory you created the form1.cpp class and CMakeLists.txt file.

2. Compile the form.

```shell
xtdc build
```

3. At the command prompt, type:

```shell
xtdc run
```

## Adding a Control and Handling an Event

The previous procedure steps demonstrated how to just create a basic GUI that compiles and runs. 
The next procedure will show you how to create and add a [control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html) to the [form](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html), and handle an event for the [control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html).

In addition to understanding how to create GUI applications, you should understand event-based programming and how to handle user input.

### To declare a button control and handle its click event

1. Declare a [button](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1button.html) control named button1.
2. In the constructor, create the [button](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1button.html) and set its [size](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a2a9c3b512b6748c8330fe2231839c4cb), [location](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a704049ab20aa16e25dca51911b0ba13b) and [text](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a3f3bc021d22dff6f3a32a8dae0e7bbe9) properties.
3. Add the [button](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1button.html) to the [form](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html).

The following code example demonstrates how to declare the [button](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1button.html) control.

```cpp
  private:
    button button1;

  public:
    Form1() {
      button1.size(drawing::size {40, 40});
      button1.location(drawing::point {30, 30});
      button1.text("Click\nme");
      controls().push_back(button1);
      button1.click += event_handler {*this, &form1::button1_click};
    }
```

4. Create a method to handle the [click](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga651752ad0a3ec381983aa0b367291a68) event for the [button](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1button.html).
5. In the [click](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga651752ad0a3ec381983aa0b367291a68) event handler, display a [message_box](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1message__box.html) with the message, "Hello World".

The following code example demonstrates how to handle the [button](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1button.html) control's click event.

```cpp
  private:
    void button1_click(object& sender, const event_args& e) {
      message_box::show("Hello World");
    }
```

6. Associate the [click](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga651752ad0a3ec381983aa0b367291a68) event with the method you created.

The following code example demonstrates how to associate the event with the method.

```cpp
button1.click += event_handler {*this, &form1::button1_click};
```

7. Compile and run the application.

```shell
xtdc run
```

## Example

Following code example is the complete example from the previous tutorial.

form1.cpp:

```cpp
#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {  
public:
  form1() {
    button1.size(drawing::size {40, 40});
    button1.location(drawing::point {30, 30});
    button1.text("Click\nme");
    controls().push_back(button1);
    button1.click += event_handler {*this, &form1::button1_click};
  }

private:
  button button1;

  void button1_click(object& sender, const event_args& e) {
    message_box::show("Hello World");
  }
};

auto main() -> int {
  application::run(form1 {});
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.20)

project(form1)
find_package(xtd REQUIRED)
add_sources(form1.cpp)
target_type(GUI_APPLICATION)
```

## See also

* [tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)
