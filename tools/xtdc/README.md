# xtdc

xtdc is project management command line tool.

xtdc can create a new project on many templates.

xtdc can build, open, run, install, test or uninstall an existing project.

# Templates project

xtdc contains many project template. All project listed below are created with CMake and target your system (Visual Studio on Windows, Xcode on macOS and Code::Blocks or makefile on Linux).

## GUI Application sdk :

* xtd (C++)
* xtd_c (c)
* cocoa (objective-c)
* fltk (C++)
* Gtk+ 2 (c)
* Gtk+ 3 (c)
* Gtk+ 4 (c)
* Gtkmm (C++)
* wxWidgets (C++)
* Qt 5 (C++)
* Win32 (c)
* Winforms (C#)
* WPF (C#)

## Console Application SDK/language :

* xtd (C++)
* xtd_c (c)
* C++
* c
* C#
* objective-c

## Shared or static library SDK/language :

* xtd (C++)
* xtd_c (c)
* C++
* c
* C#
* objective-c

## Unit Test project SDK/language :

* xtd (C++)
* xtd_c (c)
* gtest (C++)
* catch2 (C++)

# Usage

```
xtdc [<options> | command [<command-argument>] [<command-options>]]
```

The options are:

```
-i, --info       Display information.
-v, --version    Display version in use.
-h, --help       Display help.
```

The commands are:

```
new              Initializes project.
generate         Generate project from existing source files.
add              Adds new project to project.
update           Regenerates a project.
run              Compiles and immediately executes a project.
build            Builds a project.
install          Install a project.
clean            Clean build output(s).
open             Open a project in default ide.
targets          List project targets.
test             Runs unit tests using the test runner specified in the project.
uninstall        Uninstall a project.
documentation    Open xtd documentation.
examples         Open xtd examples.
guide            Open xtd reference guide.
web              Open xtd website.
help             Show help.
```

Run `xtdc command --help` for more information on a command.

# Some examples

## Create and run a xtd GUI application project

Open "Command Prompt" or "Terminal", and type the following:

```bash
xtdc new gui my_xtd_project
cd my_xtd_project
xtdc run
```

or

```bash
mkdir my_xtd_project
cd my_xtd_project
xtdc new gui
xtdc run
```

## Create and open an objective-c console application project

Open "Command Prompt" or "Terminal", and type the following:

```bash
xtdc new console --sdk objective-c my_objective_c_project
cd my_objective_c_project
xtdc open
```

## Create and test a xtd unit test application project

Open "Command Prompt" or "Terminal", and type the following:

```bash
xtdc new test my_xtd_unit_test_project
cd my_xtd_unit_test_project
xtdc test
```

# For more info about xtdc

Open "Command Prompt" or "Terminal", and type the following:

```bash
xtdc --help
```

For each command type xtdc 'command' --help to view specific command help.

For example to view help on open command :
```bash
xtdc open --help
```

# Projects    

The following tables (organized by project) show the availability of SDKs and languages for creating a project.

* Default SDK : **xtd**
* Default language : **C++**

## Console Application

* short name : **console**

| SDK      | C++ |  C  |  C# | Objective-C | Objective-C++ |
|----------|-----|-----|-----|-------------|---------------|
| **xtd**  |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| none     |  ✔️  |  ✔️  |  ✔️  |  ✔️          |  ✔️            |
| catch2   |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| cocoa    |  ✔️  |  ❌  |  ❌  |  ✔️          |  ✔️            |
| fltk     |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtest    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+2    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtk+3    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtk+4    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtkmm    |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt5      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt6      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| win32    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| winforms |  ❌  |  ❌  |  ✔️  |  ❌          |  ❌            |
| wpf      |  ❌  |  ❌  |  ✔️  |  ❌          |  ❌            |

## GUI Application

* short name : **gui**

| SDK      | C++ |  C  |  C# | Objective-C | Objective-C++ |
|----------|-----|-----|-----|-------------|---------------|
| **xtd**  |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| none     |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| catch2   |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| cocoa    |  ✔️  |  ❌  |  ❌  |  ✔️          |  ✔️            |
| fltk     |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtest    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+2    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtk+3    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtk+4    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtkmm    |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt5      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt6      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| win32    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| winforms |  ✔️  |  ❌  |  ✔️  |  ❌          |  ❌            |
| wpf      |  ❌  |  ❌  |  ✔️  |  ❌          |  ❌            |

## Unit Test Project

* short name : **test**

| SDK      | C++ |  C  |  C# | Objective-C | Objective-C++ |
|----------|-----|-----|-----|-------------|---------------|
| **xtd**  |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| none     |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| catch2   |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| cocoa    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| fltk     |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtest    |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+2    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+3    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+4    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtkmm    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt5      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt6      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| win32    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| winforms |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| wpf      |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |

## Shared library

* short name : **sharelib**

| SDK      | C++ |  C  |  C# | Objective-C | Objective-C++ |
|----------|-----|-----|-----|-------------|---------------|
| **xtd**  |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| none     |  ✔️  |  ✔️  |  ✔️  |  ✔️          |  ✔️            |
| catch2   |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| cocoa    |  ✔️  |  ❌  |  ❌  |  ✔️          |  ✔️            |
| fltk     |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtest    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+2    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtk+3    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtk+4    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtkmm    |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt5      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt6      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| win32    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| winforms |  ✔️  |  ❌  |  ✔️  |  ❌          |  ❌            |
| wpf      |  ❌  |  ❌  |  ✔️  |  ❌          |  ❌            |

## Static library

* short name : **staticlib**

| SDK      | C++ |  C  |  C# | Objective-C | Objective-C++ |
|----------|-----|-----|-----|-------------|---------------|
| **xtd**  |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| none     |  ✔️  |  ✔️  |  ✔️  |  ✔️          |  ✔️            |
| catch2   |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| cocoa    |  ✔️  |  ❌  |  ❌  |  ✔️          |  ✔️            |
| fltk     |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtest    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+2    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtk+3    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtk+4    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| gtkmm    |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt5      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt6      |  ✔️  |  ❌  |  ❌  |  ❌          |  ❌            |
| win32    |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| winforms |  ✔️  |  ❌  |  ✔️  |  ❌          |  ❌            |
| wpf      |  ❌  |  ❌  |  ✔️  |  ❌          |  ❌            |

## Solution file

* short name : **sln**

| SDK      | C++ |  C  |  C# | Objective-C | Objective-C++ |
|----------|-----|-----|-----|-------------|---------------|
| **xtd**  |  ✔️  |  ✔️  |  ❌  |  ❌          |  ❌            |
| none     |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| catch2   |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| cocoa    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| fltk     |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtest    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+2    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+3    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtk+4    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| gtkmm    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt5      |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| qt6      |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| win32    |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| winforms |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |
| wpf      |  ❌  |  ❌  |  ❌  |  ❌          |  ❌            |

______________________________________________________________________________________________

© 2024 Gammasoft.
