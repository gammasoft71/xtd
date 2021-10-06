| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Folders and files organization

## Folders hierarchy

**✔️ DO** Respect the project hierarchy

```
root
  +- build
  +- docs
  |   +- diagrams
  |   |   +- uml
  |   +- pictures
  |   +- tutorials
  |   +- movies
  +- examples
  |   +- xtd.forms
  |   |   +- appplication
  |   |   +- common_dialogs
  |   |   +- components
  |   |   +- ...
  |   +- ...
  +- locale
  |   +- af
  |   +- am
  |   +- ...
  +- resources
  |   + countries
  |   + cursors
  |   + ...
  +- scripts
  |   +- cmake
  |   +- install
  |   +- ...
  +- src
  |   +- xtd.forms
  |   |   +- include
  |   |   |   +- xtd
  |   |   |       +- forms
  |   |   |       |   +- layout
  |   |   |       |   +- ...
  |   |   |       +- ...
  |   |   +- src
  |   |       +- xtd
  |   |           +- forms
  |   |           |   +- layout
  |   |           |   +- ...
  |   |           +- ...
  |   +- ...
  +- tests
  |   +- xtd.forms.manual_tests
  |   +- xtd.forms.unit_tests
  |   |   +- xtd
  |   |       +- forms
  |   |       |   +- ...
  |   |       +- ...
  |   +- ...
  +- themes
  +- tools
      +- guidgen
      +- guidgen-gui
      +- ...
```

**root** folder is the project folder where xtd project was extracted or cloned.

**root/build** folder contains the build result. This folder is automaticaly create by the install.

**root/docs** folder contains markdown documentations.

**root/docs/diagrams** folder contains the diagrams used to illustrate the markdown documentation and website.

**root/docs/diagrams/uml** folder contains the UML diagrams used to illustrate the markdown documentation and website.

**root/docs/pictures** folder contains the pictures used to illustrate the markdown documentation and website.

**root/docs/tutorials** folder contains the xtd tutorials.

**root/docs/movies** folder contains the movies used to demonstrate how to use xtd.

**root/examples** folder contains examples to show how to used xtd libraries organized by library and example theme.

**root/locale** folder contains rlocale files organized by language.

**root/resources** folder contains resource files organized by theme.

**root/scripts** folder contains developper helper scripts.

**root/scripts/appveyor** folder contains scripts needed by appveyor CI.

**root/scripts/cmake** folder contains scripts needed by cmake.

**root/scripts/install** folder contains installation scripts.

**root/scripts/travis** folder contains scripts needed by travis CI.

**root/src** folder contains source files organized by library.

For each library the hierarchy is identical :

**root/xtd.library.name/include** folder contains include files for xtd.library_name library.

**root/xtd.library.name/include/namespace1/namespace2/...** folder contains include files for xtd.library.name library organized by namespace.

**root/xtd.library.name/src** folder contains source files for xtd.library.name library.

**root/xtd.library.name/src/namespace1/namespace2/...** folder contains source files for xtd.library.name library organized by namespace.

**root/tests** folder contains tests organized by library and namespaces.

**root/themes** folder contains default css theme files.

**root/tools** folder contains xtd tools.

For example, the **root/src/xtd.forms** folder contains xtd library source files and the **root/src/xtd.forms.native.win32** folder contains xtd.forms.native.win32 library source files.

For exemple, the **root/tests/xtd.forms.unit_tests** contains xtd.forms library unit tests.

For example, if a xtd.forms library header file contains :

```c++
#pragma once

#include <xtd/event_args.h>
#include "close_reason.h"

namespace xtd {
  namespace forms {
    class form_closed_event_args : public event_args {
    public:
      form_closed_event_args() = default;
      form_closed_event_args(forms::close_reason close_reason) : close_reason_(close_reason) {};

      /// @cond
      form_closed_event_args(const form_closed_event_args& form_closed_event_args) = default;
      form_closed_event_args& operator=(const form_closed_event_args& form_closed_event_args) = default;
      /// @endcond

      forms::close_reason close_reason() const {return close_reason_;}

    private:
      forms::close_reason close_reason_ = forms::close_reason::none;
    };
  }
}
```

The file will be in root/src/xtd.forms/include/xtd/forms/ path

## File names

**✔️ DO** Name file with same name of the class, struct, enum, delegate or event that contains.

For example, if file contains :

```c++
#pragma once

#include <xtd/event_handler.h>
#include "form_closed_event_args.h"

namespace xtd {
  namespace forms {
    template<typename type_t>
    using form_closed_event_handler = delegate<void(const type_t& sender, const form_closed_event_args& e)>;
  }
}
```

The file will be named to *form_closed_event_handler.h*.

## File extensions

**✔️ DO** Use .h for header files.

**✔️ DO** Use .cpp for source files.

# Diagrams

**✔️ DO** Diagrams are generate by [Draw.IO Desktop](https://chrome.google.com/webstore/detail/drawio-desktop/pebppomjfocnoigkeepgbmcifnnlndla?hl=en-GB). Draw.IO Desktop is a Google Chrome extension.

# UML diagrams

**✔️ DO** UML diuagrams are generate by [plantUML](http://plantuml.com).

# Editor

**✔️ DO** Replace tab character with double spaces in your editor or IDE properties.
 
**✔️ DO** Use two space for indentation. 

```c++
class my_control : public xtd::form::control {
public:
  my_control() = default;
  my_control(const my_control&) = default;
};
```

# Order of parts in a class or struct declarations

## First order is on protection type : 

**✔️ DO** Put public members in first.

**✔️ DO** Put protected members in second.

**✔️ DO** And finaly put private members at least.

## Second order for each protection type :

**✔️ DO** Put inner classes and structs in first.

**✔️ DO** Put constructors / Destructor / Copy operator in seconds.

**✔️ DO** Put properties in third.

**✔️ DO** Put events in fourth.

**✔️ DO** Put methods in fifth.

**✔️ DO** And put members in last.

**✔️ DO** Organize properties, events, methods and member in alphabetic order.

```c++
class my_control : public xtd::form::control {
public:
  my_control() = default;
  my_control(const my_control&) = default;
  my_control& my_control& operator=(const my_control& my_control);
  
  const std::string base_name() const {return base_name_;;}
  intptr_t handle() const {return handle_;}
  
  xtd::event<my_control, event_handler<xtd::forms::control>> name_changed;
  
  std::string to_string() const override {return name_generator();}

protected:
  virtual std::string name_generator() const {return base_name_;}

  intptr_t handle_ = 0;
  
private:
  my_control(intptr_t handle);

  std::string base_name_ = "BaseName";
};
```

# #define

**❌ DO NOT** Use #define for any good or bad reason.

**✔️ DO** But instead use *static constexpr* or *static const* for constantes.

### header file :
```c++
class my_class {
public:
  static constexpr int max_value = std::numeric_limits<int>::max();
  static const xtd::version min_version;
};
```

### source file :
```c++
const xtd::version my_class::min_version(2, 1, 0);
```

**✔️ Do** All macro can be replaced by template method.

```c++
class math {
pubmic:
math() = delete;
  // equivalent : #define max(value1, value2) (value1 >= value2 ? value1 : value2)
  template<typename T>
  static T max(T value1, T value2) {return value1 >= value2 ? value1 : value2;}
};
```

# Globals

## Global methods

**❌ DO NOT** Use global methods. All methods are in class. If necessary creates container class like xtd::forms:cursors to group static methods.

## global variables

**❌ DO NOT** Use global variables. All variables are in class. If necessary a global or static variable can create in a source files (.cpp) but it can't visible in the header file (.h).

**✔️ DO** Uses [factory_method](factory_method.md), [builder](builder.md) or [singleton](singleton.md) patterns to create unique object.

# Comments

**✔️ DO** Using always simple line comment **//** instead block comment /* */

```c++
// This is my
// multiline comment
int x = 3;
```

# Documentation

The documentation is generate by Doxygen.

**✔️ DO** Write Doxygen documentation only in header file (**.h**).

**✔️ DO** All documentation comment must start by triple slash **///**

```c++
/// @brief my_class do something
class my_class {
};
```

**✔️ DO** Doxygen command start with at-sign **@**

```c++
/// @brief my_func do something
/// @param name A string that contains the name.
/// @remarks The name must be begin by a uppercase; otherwise std::invalid_argument throws.
/// @exception std::invalid_argument name not started by uppercase.
void my_func(const std::string& name) {
};
```

This example of doxygen documented class (application_context.h) shows somes doxygen commands:

```c++
#pragma once
#include "form.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class application;
    /// @endcond
    
    /// @brief Specifies the contextual information about an application thread.
    /// @remarks You can use the application_context class to redefine the circumstances that cause a message loop to exit. By default, the application_context listens to the closed event on the application's main form, then exits the thread's message loop.
    /// @par Example
    /// The following code example demonstrate the use of application and application_context classes.
    /// @include application_context.cpp
    class application_context {
    public:
      /// @brief Initializes a new instance of the application_context class with no context.
      application_context() = default;
      /// @brief Initializes a new instance of the application_context class with the specified Form.
      /// @param main_form The main form of the application to use for context.
      /// @remarks If on_main_form_closed is not overridden, the message loop of the thread terminates when main_form is closed.
      explicit application_context(const form& main_form) {this->main_form(main_form);}

      /// @cond
      virtual ~application_context() {
        if (main_form_ != nullptr) main_form_->handle_destroyed -= {*this, &application_context::on_main_form_closed};
      }
      /// @endcond
      
      /// @brief Gets the form to use as context.
      /// @return The form to use as context.
      /// @remarks This property determines the main form for this context. This property can change at any time. If on_main_form_closed is not overridden, the message loop of the thread terminates when the main_form parameter closes.
      const form& main_form() const {return *main_form_;}
      /// @brief Gets or sets the Form to use as context.
      /// @return The form to use as context.
      /// @remarks This property determines the main form for this context. This property can change at any time. If on_main_form_closed is not overridden, the message loop of the thread terminates when the main_form parameter closes.
      form& main_form() {return *main_form_;}
      /// @brief Sets the Form to use as context.
      /// @param main_form The form to use as context.
      /// @remarks This property determines the main form for this context. This property can change at any time. If on_main_form_closed is not overridden, the message loop of the thread terminates when the main_form parameter closes.
      void main_form(const form& main_form) {
        if (main_form_ != nullptr) main_form_->handle_destroyed -= {*this, &application_context::on_main_form_closed};
        main_form_ = const_cast<form*>(&main_form);
        main_form_->handle_destroyed += {*this, &application_context::on_main_form_closed};
      }

      /// @brief Gets an object that contains data about the control.
      /// @return A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      std::any tag() const {return tag_;}
      /// @brief Sets an object that contains data about the control.
      /// @param tag A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      void tag(std::any tag) {tag_ = tag;}

      /// @brief Occurs when the message loop of the thread should be terminated, by calling exit_thread().
      event<application_context, event_handler<const application_context&>> thread_exit;
      
      /// @brief Terminates the message loop of the thread.
      /// @remarks This method calls exit_thread_core.
      /// @note exit_thread and exit_thread_core do not actually cause the thread to terminate. These methods raise the thread_exit event to which the Application object listens. The Application object then terminates the thread.
      void exit_thread() {exit_thread_core();}
      
    protected:
      /// @brief Terminates the message loop of the thread.
      /// @remarks This method is called from exit_thread.
      /// @note exit_thread and exit_thread_core do not actually cause the thread to terminate. These methods raise the thread_exit event to which the Application object listens. The Application object then terminates the thread.
      virtual void exit_thread_core() {thread_exit(*this, event_args::empty);}
      
      /// @brief Calls ExitThreadCore(), which raises the ThreadExit event.
      /// @param sender The object that raised the event.
      /// @param e The event_args that contains the event data.
      /// @remarks The default implementation of this method calls exit_thread_core.
      virtual void on_main_form_closed(const control& sender, const event_args& e) {
        if (!main_form_->recreating_handle()) {
          main_form_->handle_destroyed -= {*this, &application_context::on_main_form_closed};
          exit_thread_core();
        }
      }
      
    private:
      /// @cond
      friend class application;
      /// @endcond
      form* main_form_ = nullptr;
      std::any tag_;
    };
  }
}
```

For more commands see [Doxygen Special commands](http://www.stack.nl/~dimitri/doxygen/manual/commands.html) and for more informations see [Doxygen Manual](http://www.stack.nl/~dimitri/doxygen/manual/index.html).

# Indentation

**✔️ DO** Indent block contents

```c++
namespace test {
  class aclass {
    void method() {
      int x;
      int y;
    }
  };
}
```

**❌ DO NOT** Indent open and close braces

```c++
class aclass {
  int afield;

  void method() {
  }
};
```

**❌ DO NOT** Indent switch sections

```c++
class aclass {
  void method(int x) {
    switch (x) {
    case 1:
      break;
    }
  }
};
```

**✔️ DO** Indent case sections

```c++
class aclass {
  void method(int x) {
    switch (x) {
    case 1:
      break;
    }
  }
};
```

**❌ DO NOT** Indent label

```c++
class test {
  void method() {
  label:
    console::write_line("Hello World");
  }
};
```

# New lines

## New line options for braces

**❌ DO NOT** Place open brace on new line for types

```c++
class example {
};
```

**❌ DO NOT** Place open brace on new line for methods

```c++
void example() {
}
```

**❌ DO NOT** Place open brace on new line for lambda expressions

```c++
void example() {
  auto del = [](int i, int j) {
  };
}
```

**❌ DO NOT** Place open brace on new line for control blocks

```c++
void example() {
  if (true) {
  }
}
```

**❌ DO NOT** Place open brace on new line for object initializers

```c++
void example() {
  std::vector<int> array_list {
    42, 24, 84
  };
}
```

## New line options for keywords

**❌ DO NOT** Place "else" on new line

```c++
void example() {
  if (true) {
    // ...
  } else {
    // ...
  }
}
```

**❌ DO NOT** Place "catch" on new line

```c++
void example() {
  try {
    // ...
  } catch(...) {
    // ...
  }
}
```

## New line options for expressions

**❌ DO NOT** Place memberin object initializers on new line

```c++
void example() {
  xtd::drawing::point p {
    10, 24
  };
}
```

# Spacing

## Set spacing for method declarations

**❌ DO NOT** Insert space between method name and its opening parenthesis

```c++
void example() {
}
```

**❌ DO NOT** Insert space within argument list parentheses

```c++
void example(int i, int j) {
}
```


**❌ DO NOT** Insert space within empty argument list parentheses

```c++
void example() {
}
```

## Set spacing for method calls

**❌ DO NOT** Insert space between method name and its opening parenthesis

```c++
void example() {
  test();
}
```

**❌ DO NOT** Insert space within argument list parentheses

```c++
void example() {
  test(int i, int j);
}
```


**❌ DO NOT** Insert space within empty argument list parentheses

```c++
void example() {
  test();
}
```

## Set other spacing options

**✔️ DO** Insert space after keywords in control flow statements

```c++
void example() {
  if (condition) {
  }
}
```

**❌ DO NOT** Insert space within parentheses of expressions

```c++
void example() {
  i = (5 + 3) * 2;
}
```

**❌ DO NOT** Insert space within parentheses of type casts

```c++
void example() {
  test = (const itest&)o;
}
```
**❌ DO NOT** Insert space within parentheses of control flow statements

```c++
void example() {
  if (condition) {
  }
}
```

**❌ DO NOT** Insert space after casts

```c++
void example() {
  test = (const itest&)o;
}
```

**✔️ DO** Insert space in declaration statements

```c++
void example() {
  int x = 5;
}
```

## Set spacing for square brackets

**❌ DO NOT** Insert space before open square bracket

```c++
void example() {
  i[5] = 3;
}
```

**❌ DO NOT** Insert space within empty square brackets

```c++
void example() {
  test(int[] {1, 2});
}
```

**❌ DO NOT** Insert space within square brackets

```c++
void example() {
  i[5] = 3;
}
```

## Set spacing for brackets

**✔️ DO** Insert space after colon for base or interface in type declaration

```c++
class foo : public bar {
}
```

**✔️ DO** Insert space after comma

```c++
void example() {
  int i = 0, j = 15;
}
```

**❌ DO NOT** Insert space after dot

```c++
void example() {
  foo.bar().test();
}
```

**❌ DO NOT** Insert space after structure or class dereference

```c++
void example() {
  foo->bar()->test();
}
```

**✔️ DO** Insert space after semicolon in "for" statement

```c++
void example() {
  for (int i = 0; i < 10; i++) {
  }
}
```

**✔️ DO** Insert space before colon for base or interface in type declaration

```c++
class foo : public bar {
}
```

**❌ DO NOT** Insert space before dot

```c++
void example() {
  foo.bar().test();
}
```

**❌ DO NOT** Insert space before structure or class dereference

```c++
void example() {
  foo->bar()->test();
}
```

**❌ DO NOT** Insert space before semicolon in "for" statement

```c++
void example() {
  for (int i = 0; i < 10; i++) {
  }
}
```

**✔️ DO** Set spacing for operators

```c++
void example() {
  i = (5 + 3) * 2;
}
```

# See also
​
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
