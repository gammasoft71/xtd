| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

As mentioned in [introduction](introduction.md) [xtd_forms](https://github.com/gammasoft71/xtd_forms) is a part of [xtd](https://github.com/gammasoft71/xtd).

[xtd](https://github.com/gammasoft71/xtd) and [xtd_forms](https://github.com/gammasoft71/xtd_forms) consist of a large group of helper classes that help programmers to do their job. These include classes for working with strings, files, streams, console, unit testing, or network. Here we will show only a tiny drop of the whole lake.

[xtd_console](https://github.com/gammasoft71/xtd_console) library can be used to create console applications. In this chapter, we will illustrate some of the helper classes in console based applications.

# xtd::console

This is a simple console application. The application puts some text into the console window.

## console.cpp

```cpp
#include <xtd/xtd.console>

auto main(int argc, char* argv[]) -> int {
  xtd::console::write_line("A xtd_console console application");
}
```

```
A xtd_console console application
```

This is the output.

## console_write_line.cpp

The application puts some formatted texts into the console window.

```cpp
#include <xtd/xtd.console>

auto main(int argc, char* argv[]) -> int {
  auto number = 1024;
  
  xtd::console::write_line("number '{}' :", number);
  xtd::console::write_line("  binary 0b{:B16}", number);
  xtd::console::write_line("  octal \\{:O}", number);
  xtd::console::write_line("  decimal {:D}", number);
  xtd::console::write_line("  hexa 0x{:X4}", number);
}
```

```
number '1024' :
  binary 0b0000010000000000
  octal \2000
  decimal 1024
  hexa 0x0400
```

This is the output

# xtd::environment

```cpp
#include <xtd/xtd.core>
#include <xtd/xtd.console>

auto main(int argc, char* argv[]) -> int {
  auto str1 = xtd::environment::os_version().desktop_environment();
  auto str2 = "desktop"_s;
  auto str3 = "environment"_s;

  xtd::console::write_line(xtd::strings::join(" ", {str1, str2, str3}));
}
```

# xtd::strings

```cpp
#include <xtd/xtd.core>
#include <xtd/xtd.console>

auto main(int argc, char* argv[]) -> int {
  auto str1 = xtd::environment::os_version().desktop_environment();
  auto str2 = "desktop"_s;
  auto str3 = "environment"_s;

  xtd::console::write_line(xtd::strings::join(" ", {str1, str2, str3}));
}
```

# See also
​
Other Resources

* [Tutorial](tutorial.md)

______________________________________________________________________________________________

© 2025 Gammasoft.
