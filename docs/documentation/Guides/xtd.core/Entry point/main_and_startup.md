---
sidebar_position: 16
---

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

auto main() -> int {
  // Write the command line to the console output
  console::write_line(environment::command_line());

  console::write_line();

  // Write command line arguments to the console output
  for (auto arg : environment::get_command_line_args())
    console::write_line(arg);
}
```

As you can see, even if the `main` function is called without arguments and if `one two "three four" five` are entered on the command line, you can still retrieve them.

## startup::safe_run methods

xtd introduce the [xtd::startup::safe_run](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1startup.html#a9301437f9e6012fa2a487878639e7d23) methods which allows to have a main static method in any class with different parameters with or without return value.

### startup::safe_run methods and exceptions

Even if[xtd::startup::safe_run](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1startup.html#a9301437f9e6012fa2a487878639e7d23) method catch exceptions, it's preferable that you catch yourself exception. Indeed [startup_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gac9b8e6f22fb2fdc1bb915ee01aef848c) generate a generic fallback message to the output console for a console application and a generic falbback [xtd::forms::dialog_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1exception__dialog.html) for a GUI application.

Your code should look like this :

```cpp
#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static auto main() -> void {
      try {
        // your code
      } catch(const std::exception& e) {
        // Your catch handler
      }
    }
  };
}

auto main() -> int {
  return xtd::startup::safe_run(examples::program::main);
}
```

See [try-block](https://en.cppreference.com/w/cpp/language/try_catch) for more information.

### startup::safe_run methods usage

* Static `main` member function without argument and without return value.

```cpp
#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static auto main() -> void {
      // Write arguments to the console output
      for (auto arg : environment::get_command_line_args())
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

auto main() -> int {
  return xtd::startup::safe_run(examples::program::main);
}
```

* Static `main` member function without argument and with int return value.

```cpp
#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static auto main() -> int {
      // Write arguments to the console output
      for (auto arg : environment::get_command_line_args())
        console::write_line(arg);
        
      return 42;
    }
  };
}

auto main() -> int {
  return xtd::startup::safe_run(examples::program::main);
}
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

auto main() -> int {
  return xtd::startup::safe_run(examples::program::main);
}
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

auto main() -> int {
  return xtd::startup::safe_run(examples::program::main);
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
    static auto main(int argc, char* argv[]) -> void {
      // Write arguments to the console output
      for (auto arg : {argv, argv + argc})
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

auto main() -> int {
  return xtd::startup::safe_run(examples::program::main);
}
```

* Static `main` member function with int and char*[] arguments and with int return value.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static auto main(int argc, char* argv[]) -> int {
      // Write arguments to the console output
      for (auto arg : {argv, argv + argc})
        console::write_line(arg);
        
      return 42;
    }
  };
}

auto main() -> int {
  return xtd::startup::safe_run(examples::program::main);
}
```

## startup_ keyword

xtd introduces the keyword [startup_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gac9b8e6f22fb2fdc1bb915ee01aef848c) which allows to have a main static method in any class with different parameters with or without return value.

Behind this keyword there is a `main` global function that call `main` static method in the specified class parameter with `try` and `catch`.

## startup_ definition

```cpp
#define startup_(main_class) \
  auto main(int argc, char* argv[]) -> int {\
    return xtd::startup::safe_run(main_method, argc, argv);\
  }\
  intptr_t __opaque_sftews__ = 0
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
    static auto main() -> void {
      try {
        // your code
      } catch(const std::exception& e) {
        // Your catch handler
      }
    }
  };
}

startup_(examples::program::main);
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
    static auto main() -> void {
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
    static auto main() -> int {
      // Write arguments to the console output
      for (auto arg : environment::get_command_line_args())
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(examples::program::main);
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

startup_(examples::program::main);
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

startup_(examples::program::main);
```

* Static `main` member function with int and char*[] arguments and without return value.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static auto main(int argc, char* argv[]) -> void {
      // Write arguments to the console output
      for (auto arg : {argv, argv + argc})
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(examples::program::main);
```

* Static `main` member function with int and char*[] arguments and with int return value.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static auto main(int argc, char* argv[]) -> int {
      // Write arguments to the console output
      for (auto arg : {argv, argv + argc})
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(examples::program::main);
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
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)
