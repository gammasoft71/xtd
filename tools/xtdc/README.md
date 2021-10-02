# xtdc

xtdc is project management command line tool.

xtdc can create a new project on many templates.

xtdc can build, open, run, install, test or uninstall an existing project.

# Templates project

xtdc contains many project template. All project listed below are created with CMake and target your system (Visual Studio on Windows, Xcode on macOS and Code::Blocks or makefile on Linux).

## GUI Application sdk :

* xtd (c++)
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
* c++
* c
* c#
* objective-c

## Shared or static library SDK/language :

* xtd (c++)
* c++
* c
* c#
* objective-c

## Unit Test project SDK/language :

* xtd (c++)
* gtest (c++)
* catch2 (c++)

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
xtdc new gui .
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

______________________________________________________________________________________________

© 2021 Gammasoft.
