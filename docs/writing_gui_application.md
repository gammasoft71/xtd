| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

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

```c++
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
```

2. Declare a class named **form1** that inherits from the **form** class.

```c++
class form1 : public form
```

3. Create a default constructor for **form1**.

You will add more code to the constructor in a subsequent procedure.

```c++
  public:
    form1() {}
```

4. Add a main method.

Create an instance of the **form1** and run it.

```c++
int main() {
  application::run(form1());
}
```

### To create the CMakeLists.txt

1. Create CMakeLists.txt file in your project folder and add the cmake minimum version required.

```cmake
cmake_minimum_required(VERSION 3.3)
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

The previous procedure steps demonstrated how to just create a basic GUI that compiles and runs. The next procedure will show you how to create and add a control to the form, and handle an event for the control.

In addition to understanding how to create GUI applications, you should understand event-based programming and how to handle user input.

### To declare a button control and handle its click event

1. Declare a button control named button1.
2. In the constructor, create the button and set its **size**, **location** and **text** properties.
3. Add the button to the form.

The following code example demonstrates how to declare the button control.

```c++
  private:
    button button1;

  public:
    Form1() {
      button1.size({40, 40});
      button1.location({30, 30});
      button1.text("Click\nme");
      controls().push_back(button1);
      button1.click += {*this, &form1::button1_click};
    }
```

4. Create a method to handle the Click event for the button.
5. In the click event handler, display a MessageBox with the message, "Hello World".

The following code example demonstrates how to handle the button control's click event.

```c++
  private:
    void button1_click(const control& sender, const event_args& e) {
      message_box::show("Hello World");
    }
```

6. Associate the Click event with the method you created.

The following code example demonstrates how to associate the event with the method.

```c++
button1.click += {*this, &form1::button1_click};
```

7. Compile and run the application.

```shell
xtdc run
```

## Example

Following code example is the complete example from the previous tutorial.

form1.cpp:

```c++
#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {  
public:
  form1() {
    button1.size({40, 40});
    button1.location({30, 30});
    button1.text("Click\nme");
    controls().push_back(button1);
    button1.click += {*this, &form1::button1_click};
  }

private:
  button button1;

  void button1_click(const control& sender, const event_args& e) {
    message_box::show("Hello World");
  }
};

int main() {
  application::run(form1());
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(form1)
find_package(xtd REQUIRED)
add_sources(form1.cpp)
target_type(GUI_APPLICATION)
```

## See also

* [Writing applications](writing_applications.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
