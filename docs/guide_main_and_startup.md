| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# main function and startup_ keyword

## main function

A program shall contain a global function named `main`, which is the designated start of the program in hosted environment. 

It shall have one of the following forms:
* `int main () { /*body*/ }`
* `int main (int argc, char* argv[]) { /*body*/ }`

See [Main function](https://en.cppreference.com/w/cpp/language/main_function) for more information.

## main function arguments

You can get command line arguments event if you use `main`function without argument. 

The [xtd::environment](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html) class grabs and keeps for you the command line arguments :
* [xtd::environment::command_line](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#ad79abc5dbbaf65805f8a84c33a622fbd) property gets the command line for this process.
* [xtd::environment::get_command_line_args](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#a67b0e929793847d994dce7b741dc2ad3) method returns a string array containing the command-line arguments for the current process.

### xtd::environment::command_line and xtd::environment::get_command_line_args usage

```c++
#include <xtd/xtd>

using namespace xtd;

int main() {
  // Write the command line to the console output
  console::write_line(environment::command_line());

  console::write_line();

  // Write command line arguments to the console output
  for (ustring arg : environment::get_command_line_args())
    console::write_line(arg);
}
```

As you can see, even if the `main` function is called without arguments and if `one two "three four" five` are entered on the command line, you can still retrieve them.

## startup_ keyword

xtd introduces the keyword `startup_` which allows to have a main static method in any class with different parameters with or without return value. 
In the case 

Behind this keyword there is a `main` global function that call `main` static method in the cpecified class paramter with `try` and `catch`.

## startup_ definition

```c++
#define startup_(main_class) \
  auto main(int argc, char* argv[])->int {\
    try {\
      return __startup__::run(main_class::main, argc, argv);\
    } catch(const std::exception& e) {\
      __startup_catch_exception__(e);\
    } catch(...) {\
      __startup_catch_exception__();\
    }\
  }\
  auto __startup_force_to_end_with_semicolon__ = 0
```

### startup_ and exceptions

Even if `startup_` keyword catch exceptions, it's preferable that you catch yourself exception. Indeed `startup_` generate a generic fallback message to the output console for a console application and a generic falbback [xtd::forms::dialog_exception](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1exception__dialog.html) for a GUI application.

Your code should look like this :

```c++
#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static void main() {
      try {
        // your code
      } catch(const std::exception& e) {
        // Your catch handler
      }
    }
  };
}

startup_(examples::program);
```

See [try-block](https://en.cppreference.com/w/cpp/language/try_catch) for more information.

### statup_ keyword usage

* Static `main` member function without argument and without return value.

```c++
#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static void main() {
      // Write arguments to the console output
      for (ustring arg : environment::get_command_line_args())
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(examples::program);
```

* Static `main` member function without argument and with int return value.

```c++
#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static int main() {
      // Write arguments to the console output
      for (ustring arg : environment::get_command_line_args())
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(examples::program);
```

* Static `main` member function with string array argument and without return value.

```c++
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static void main(const vector<ustring>& args) {
      // Write arguments to the console output
      for (ustring arg : args)
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(examples::program);
```

* Static `main` member function with string array argument and with int return value.

```c++
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static int main(const vector<ustring>& args) {
      // Write arguments to the console output
      for (ustring arg : args)
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(examples::program);
```

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.
