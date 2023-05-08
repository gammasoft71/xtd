# xtdc

xtdc is project management command line tool.

xtdc can create a new project on many templates.

xtdc can build, open, run, install, test or uninstall an existing project.

# Templates project

xtdc contains many project template. All project listed below are created with CMake and target your system (Visual Studio on Windows, Xcode on macOS and Code::Blocks or makefile on Linux).

## GUI Application sdk :

* xtd (c++)
* xtd_c (c)
* cocoa (objective-c)
* fltk (c++)
* Gtk+ 2 (c)
* Gtk+ 3 (c)
* Gtk+ 4 (c)
* Gtkmm (c++)
* wxWidgets (c++)
* Qt 5 (c++)
* Win32 (c)
* Winforms (c#)
* WPF (c#)

## Console Application SDK/language :

* xtd (c++)
* xtd_c (c)
* c++
* c
* c#
* objective-c

## Shared or static library SDK/language :

* xtd (c++)
* xtd_c (c)
* c++
* c
* c#
* objective-c

## Unit Test project SDK/language :

* xtd (c++)
* xtd_c (c)
* gtest (c++)
* catch2 (c++)

# Usage

```bash
xtdc [<options> | command [<command-argument>] [<command-options>]]
```

The options are:

```bash
-i, --info       Display information.
-v, --version    Display version in use.
-h, --help       Display help.
```

The commands are:

```bash
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

The following tables, organized by project, show the availability of SDKs and languages.

* Default SDK : xtd

## Console Application

* short name : **console**

| SDK      | c++ | c | c# | objective-c | Default language |
|----------|-----|---|----|-------------|------------------|
| none     | ✔️  | ✔️ | ✔️  | ✔️           | c++              |
| catch2   | ❌  | ❌ | ❌  | ❌           | NA               |
| cocoa    | ✔️  | ❌ | ❌  | ✔️           | objective-c      |
| fltk     | ✔️  | ❌ | ❌  | ❌           | c++              |
| gtest    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+2    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtk+3    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtk+4    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtkmm    | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt5      | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt6      | ✔️  | ❌ | ❌  | ❌           | c++              |
| win32    | ✔️  | ✔️ | ❌  | ❌           | c                |
| winforms | ❌  | ❌ | ✔️  | ❌           | c#               |
| wpf      | ❌  | ❌ | ✔️  | ❌           | c#               |
| xtd      | ✔️  | ✔️ | ❌  | ❌           | c++              |

## GUI Application

* short name : **gui**

| SDK      | c++ | c | c# | objective-c | Default language |
|----------|-----|---|----|-------------|------------------|
| none     | ❌  | ❌ | ❌  | ❌           | c++              |
| catch2   | ❌  | ❌ | ❌  | ❌           | NA               |
| cocoa    | ✔️  | ❌ | ❌  | ✔️           | objective-c      |
| fltk     | ✔️  | ❌ | ❌  | ❌           | c++              |
| gtest    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+2    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtk+3    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtk+4    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtkmm    | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt5      | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt6      | ✔️  | ❌ | ❌  | ❌           | c++              |
| win32    | ✔️  | ✔️ | ❌  | ❌           | c                |
| winforms | ❌  | ❌ | ✔️  | ❌           | c#               |
| wpf      | ❌  | ❌ | ✔️  | ❌           | c#               |
| xtd      | ✔️  | ✔️ | ❌  | ❌           | c++              |

## Shared library

* short name : **sharelib**

| SDK      | c++ | c | c# | objective-c | Default language |
|----------|-----|---|----|-------------|------------------|
| none     | ✔️  | ✔️ | ✔️  | ✔️           | c++              |
| catch2   | ❌  | ❌ | ❌  | ❌           | NA               |
| cocoa    | ✔️  | ❌ | ❌  | ✔️           | cobjective-c     |
| fltk     | ✔️  | ❌ | ❌  | ❌           | c++              |
| gtest    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+2    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtk+3    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtk+4    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtkmm    | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt5      | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt6      | ✔️  | ❌ | ❌  | ❌           | c++              |
| win32    | ✔️  | ✔️ | ❌  | ❌           | c                |
| winforms | ❌  | ❌ | ✔️  | ❌           | c#               |
| wpf      | ❌  | ❌ | ✔️  | ❌           | c#               |
| xtd      | ✔️  | ✔️ | ❌  | ❌           | c++              |

## Solution file

* short name : **sln**

| SDK      | c++ | c | c# | objective-c | Default language |
|----------|-----|---|----|-------------|------------------|
| none     | ❌  | ❌ | ❌  | ❌           | NA               |
| catch2   | ❌  | ❌ | ❌  | ❌           | NA               |
| cocoa    | ❌  | ❌ | ❌  | ❌           | NA               |
| fltk     | ❌  | ❌ | ❌  | ❌           | NA               |
| gtest    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+2    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+3    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+4    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtkmm    | ❌  | ❌ | ❌  | ❌           | NA               |
| qt5      | ❌  | ❌ | ❌  | ❌           | NA               |
| qt6      | ❌  | ❌ | ❌  | ❌           | NA               |
| win32    | ❌  | ❌ | ❌  | ❌           | NA               |
| winforms | ❌  | ❌ | ❌  | ❌           | NA               |
| wpf      | ❌  | ❌ | ❌  | ❌           | NA               |
| xtd      | ✔️  | ✔️ | ❌  | ❌           | c++              |

## Static library

* short name : **staticlib**

| SDK      | c++ | c | c# | objective-c | Default language |
|----------|-----|---|----|-------------|------------------|
| none     | ✔️  | ✔️ | ✔️  | ✔️           | c++              |
| catch2   | ❌  | ❌ | ❌  | ❌           | NA               |
| cocoa    | ✔️  | ❌ | ❌  | ✔️           | objective-c      |
| fltk     | ✔️  | ❌ | ❌  | ❌           | c++              |
| gtest    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+2    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtk+3    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtk+4    | ✔️  | ✔️ | ❌  | ❌           | c                |
| gtkmm    | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt5      | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt6      | ✔️  | ❌ | ❌  | ❌           | c++              |
| win32    | ✔️  | ✔️ | ❌  | ❌           | c                |
| winforms | ❌  | ❌ | ✔️  | ❌           | c#               |
| wpf      | ❌  | ❌ | ✔️  | ❌           | c#               |
| xtd      | ✔️  | ✔️ | ❌  | ❌           | c++              |

## Unit Test Project

* short name : **test**

| SDK      | c++ | c | c# | objective-c | Default language |
|----------|-----|---|----|-------------|------------------|
| none     | ❌  | ❌ | ❌  | ❌           | NA               |
| catch2   | ✔️  | ❌ | ❌  | ❌           | c++              |
| cocoa    | ❌  | ❌ | ❌  | ❌           | NA               |
| fltk     | ❌  | ❌ | ❌  | ❌           | NA               |
| gtest    | ✔️  | ❌ | ❌  | ❌           | c++              |
| gtk+2    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+3    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtk+4    | ❌  | ❌ | ❌  | ❌           | NA               |
| gtkmm    | ❌  | ❌ | ❌  | ❌           | NA               |
| qt5      | ✔️  | ❌ | ❌  | ❌           | c++              |
| qt6      | ✔️  | ❌ | ❌  | ❌           | c++              |
| win32    | ✔️  | ✔️ | ❌  | ❌           | c                |
| winforms | ❌  | ❌ | ❌  | ❌           | NA               |
| wpf      | ❌  | ❌ | ❌  | ❌           | NA               |
| xtd      | ✔️  | ✔️ | ❌  | ❌           | c++              |

______________________________________________________________________________________________

© 2022 Gammasoft.
