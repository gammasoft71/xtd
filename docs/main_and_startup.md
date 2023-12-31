| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# main function and startup_ keyword

## main function

A program shall contain a global function named `main`, which is the designated start of the program in hosted environment. 

It shall have one of the following forms:
* `int main () { /*body*/ }`
* `int main (int argc, char* argv[]) { /*body*/ }`

See [Main function](https://en.cppreference.com/w/cpp/language/main_function) for more information.

## main function arguments

You can get command line arguments event if you use `main`function without argument. 

The [xtd::environment](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html) class grabs and keeps for you the command line arguments :
* [xtd::environment::command_line](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html#ad79abc5dbbaf65805f8a84c33a622fbd) property gets the command line for this process.
* [xtd::environment::get_command_line_args](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html#a67b0e929793847d994dce7b741dc2ad3) method returns a string array containing the command-line arguments for the current process.

### xtd::environment::command_line and xtd::environment::get_command_line_args usage

```cpp
#include <xtd/xtd>

using namespace xtd;

int main() {
  // Write the command line to the console output
  console::write_line(environment::command_line());

  console::write_line();

  // Write command line arguments to the console output
  for (auto arg : environment::get_command_line_args())
    console::write_line(arg);
}
```

As you can see, even if the `main` function is called without arguments and if `one two "three four" five` are entered on the command line, you can still retrieve them.

## startup_ keyword

xtd introduces the keyword [startup_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gac9b8e6f22fb2fdc1bb915ee01aef848c) which allows to have a main static method in any class with different parameters with or without return value.

Behind this keyword there is a `main` global function that call `main` static method in the specified class parameter with `try` and `catch`.

## startup_ definition

```cpp
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

Even if [startup_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gac9b8e6f22fb2fdc1bb915ee01aef848c) keyword catch exceptions, it's preferable that you catch yourself exception. Indeed [startup_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gac9b8e6f22fb2fdc1bb915ee01aef848c) generate a generic fallback message to the output console for a console application and a generic falbback [xtd::forms::dialog_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1exception__dialog.html) for a GUI application.

Your code should look like this :

```cpp
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

```cpp
#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static void main() {
      // Write arguments to the console output
      for (auto arg : environment::get_command_line_args())
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(examples::program);
```

* Static `main` member function without argument and with int return value.

```cpp
#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static int main() {
      // Write arguments to the console output
      for (auto arg : environment::get_command_line_args())
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(examples::program);
```

* Static `main` member function with string array argument and without return value.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static void main(const vector<ustring>& args) {
      // Write arguments to the console output
      for (auto arg : args)
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(examples::program);
```

* Static `main` member function with string array argument and with int return value.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static int main(const vector<ustring>& args) {
      // Write arguments to the console output
      for (auto arg : args)
        console::write_line(arg);
        
      return 42;
    }
  };
}
```

* Static `main` member function with int and char*[] arguments and without return value.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static void main(int argc, char* argv[]) {
      // Write arguments to the console output
      for (auto arg : {argv, argv + argc})
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(examples::program);
```

* Static `main` member function with int and char*[] arguments and with int return value.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static int main(int argc, char* argv[]) {
      // Write arguments to the console output
      for (auto arg : {argv, argv + argc})
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(examples::program);
```

## Windows main definitions

In Windows, there are different definitions for main in addition to the c++ standard :

main definitions in the standard c++ :
* `int main () { /*body*/ }`
* `int main (int argc, char* argv[]) { /*body*/ }`
* `int main (int argc, wchar_t* argv[], char* envp[ ]) { /*body*/ }`

main definitions specific Windows :
* `int wmain () { /*body*/ }`
* `int wmain (int argc, wchar_t* argv[]) { /*body*/ }`
* `int wmain (int argc, wchar_t* argv[], wchar_t* envp[ ]) { /*body*/ }`
* `int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow);`
* `int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);`

See [Using wmain](https://learn.microsoft.com/en-us/cpp/c-language/using-wmain?view=msvc-170) and [WinMain: The Application Entry Point](https://learn.microsoft.com/en-us/windows/win32/learnwin32/winmain--the-application-entry-point) for more information

For xtd portability, the `/ENTRY:mainCRTStartup` flag is added automatically when you add the xtd library in your CMakeLists.txt to the linker flags. So even for a GUI application you can call the main functions of the c++ standard in the Windows development environment.

If you are not using CMake for your project creation, it is advisable to add this flag manually.

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
