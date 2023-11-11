# xtd

**xtd (pronounced "extend") is a modern C++17/20 framework to create console, GUI (forms like WinForms) and unit test applications on Microsoft Windows, Apple macOS, Linux, iOS and android (*).**

[![logo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo.png)](https://gammasoft71.github.io/xtd)

(*) See [portability](https://gammasoft71.github.io/xtd/docs/documentation/portability#the-xtd-libraries-portability-list) for more information.

[![License](https://img.shields.io/github/license/gammasoft71/xtd)](https://gammasoft71.github.io/xtd/docs/documentation/license) [![Language](https://img.shields.io/badge/language-C++17/20-004080.svg)](https://gammasoft71.github.io/xtd/docs/documentation/portability) [![web](https://img.shields.io/badge/website-xtd-004080.svg)](https://gammasoft71.github.io/xtd) [![Reference Guide](https://img.shields.io/badge/code-reference%20guide-004080.svg)](https://gammasoft71.github.io/xtd/reference_guides/latest/index.html) [![wiki](https://img.shields.io/badge/wiki-xtd-004080.svg)](https://github.com/gammasoft71/xtd/wiki) [![discord](https://img.shields.io/badge/discord-gammasoft-7289DA.svg)](https://discordapp.com/users/gammasoft#9288) [![Download xtd](https://img.shields.io/sourceforge/dt/xtdpro.svg)](https://sourceforge.net/projects/xtdpro/files/latest/download)
 
# Latest news

* [Release xtd 0.1.1 (beta) - Jully 17, 2023](https://gammasoft71.github.io/xtd/docs/news#release-xtd-011-beta-jully-17-2023)
* [The new xtd website is online - February 9, 2023](https://gammasoft71.github.io/xtd/docs/news#the-new-xtd-website-is-online-february-9-2023)
* [xtd.tunit is compatible with Test Explorer window of Visual Studio 2019 or later - November 18, 2022](https://gammasoft71.github.io/xtd/docs/news#xtdtunit-is-compatible-with-test-explorer-window-of-visual-studio-2019-or-later-november-18-2022)
* [Release xtd 0.1.0 (beta) - October 10, 2021](https://gammasoft71.github.io/xtd/docs/news#release-xtd-010-beta-october-10-2021)

## Features

* Free and open-source ([MIT License](https://gammasoft71.github.io/xtd/docs/documentation/license));
* a collection of native C++ classes libraries, to **extend** std;
* API close to the .net API with a modern C++ approach and full integration with the std standard;
* xtd is designed to manage GUI controls and dialogs in pure [native mode](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/control_appearance) or with [CSS styles](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview).
* written in efficient, modern C++17 / C++20 with [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming idiom;
* and [highly portable](https://gammasoft71.github.io/xtd/docs/documentation/portability) and available on [many different platforms](https://gammasoft71.github.io/xtd/docs/documentation/portability);
* See [features](https://gammasoft71.github.io/xtd/docs/documentation/features) for more informations.

## xtd libraries architecture

[![architecture_logo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/block_diagram_onion.png)](https://gammasoft71.github.io/xtd/docs/documentation/Guides/Overview/Libraries/hierarchy)

xtd is composed of several libraries.

### xtd.core

[![core](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd.core.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html)
The [xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html) library is modern C++17/20 libraries of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.

### xtd.drawing

[![drawing](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd.drawing.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html)
The [xtd.drawing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html) library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.

### xtd.forms

[![forms](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd.forms.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html)
The [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows, Apple macOS and linux base operating system.

### xtd.tunit

[![tunit](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd.tunit.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html)
The [xtd.tunit](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html) library is a unit-testing framework for modern C++17/20, inspired by [Microsoft.VisualStudio.TestTools.Cpp](https://docs.microsoft.com/en-us/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference).

## Getting Started

* [Installation](https://gammasoft71.github.io/xtd/docs/downloads) provides download, install and uninstall documentation.
* [Guides](https://gammasoft71.github.io/xtd/docs/documentation/Guides) provides xtd guides and tutorials.
* [Examples](https://github.com/gammasoft71/xtd/blob/master/examples/README.md) provides over 700 examples to help you use xtd, grouped by libraries and topics.

## Development status

* [Release notes](https://gammasoft71.github.io/xtd/docs/documentation/release_notes) provides release notes information.
* [Roadmap](https://gammasoft71.github.io/xtd/docs/documentation/roadmap) provides a view of the xtd roadmap.
* [Kanban board](https://github.com/users/gammasoft71/projects/3) provides a Kanban view for all tasks (enhancements, pull requests, bugs, questions,...).
* [Development status](https://gammasoft71.github.io/xtd/docs/documentation/Development%20status) provides information about classes and libraries development status.
* [Translation status](https://gammasoft71.github.io/xtd/docs/documentation/translation_status) provides information about translations status.

## Current release status

[![GitHub milestone](https://img.shields.io/github/milestones/progress/gammasoft71/xtd/1?color=004080&style=for-the-badge)](https://github.com/gammasoft71/xtd/milestone/1) [![GitHub milestone](https://img.shields.io/github/milestones/progress-percent/gammasoft71/xtd/1?color=004080&label=complete%20&style=for-the-badge)](https://github.com/gammasoft71/xtd/milestone/1)
  
This project is an open source project. The developers who participate do so on their own time. It is therefore difficult to fix realese dates. 

But you can follow the evolution of the development. We keep the status up to date.

## Continuous Integration build status

At each commit, a build and unit tests are performed for the following configurations :

| Operating system | Debug                                                                                                                                                                                                   | Release                                                                                                                                                                                                                   |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Windows (x64)    | [![Windows (x64) Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/windows.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/windows.yml)             | [![Windows (x64) Release](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/windows_release.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/windows_release.yml)             |
| Windows (x86)    | [![Windows (x86) Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/windows_win32.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/windows_win32.yml) | [![Windows (x86) Release](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/windows_win32_release.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/windows_win32_release.yml) |
| macOS            | [![macOS Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/macos.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/macos.yml)                         | [![macOS Release](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/macos_release.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/macos_release.yml)                         |
| Ubuntu           | [![Ubuntu Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/ubuntu.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/ubuntu.yml)                      | [![Ubuntu Release](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/ubuntu_release.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/ubuntu_release.yml)                      |
| iOS (**)         | Coming soon...                                                                                                                                                                                          | Coming soon...                                                                                                                                                                                                            |
| Android (**)     | Coming soon...                                                                                                                                                                                          | Coming soon...                                                                                                                                                                                                            |

 (**) [xtd.core and xtd.tunit only](https://gammasoft71.github.io/xtd/docs/documentation/portability).

| Deploy to GitHub Pages                   | status                                                                                                                                                                                               |
| ---------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Deployment of the website                | [![Ubuntu Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/deploy.yml?branch=docs)](https://github.com/gammasoft71/xtd/actions/workflows/deploy.yml)                     |
| Deployment of the latest reference guide | [![Ubuntu Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/reference_guide.yml?branch=master)](https://github.com/gammasoft71/xtd/actions/workflows/reference_guide.yml) |

## Issues status

As xtd is managed by a [Kanban project](https://github.com/users/gammasoft71/projects/3), the number of open issues can be quite large. The table below gives a clearer view on the number of open bugs/questions and enhancements.

| Issues                                          | Open                                                                                                                                                                                                                                                                                                       | Closed                                                                                                                                                                                                                                                                                                            |
| ----------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bugs / Questions from users                     | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=red&label=query&query=is%3Aopen%20is%3Aissue+-label%3Aenhancement)](https://github.com/gammasoft71/xtd/issues?q=is%3Aopen+is%3Aissue+-label%3Aenhancement)                                        | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20-label%3Aenhancement)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+-label%3Aenhancement+is%3Aclosed)                                   |
| xtd 0.1.0 - Enhancements / Developments _(*)_ | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A0.1.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A0.1.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A0.1.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A0.1.0) |
| xtd 0.1.1 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A0.1.1)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A0.1.1) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A0.1.1)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A0.1.1) |
| xtd 0.2.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A0.2.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A0.2.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A0.2.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A0.2.0) |
| xtd 0.3.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A0.3.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A0.3.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A0.3.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A0.3.0) |
| xtd 0.4.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A0.4.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A0.4.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A0.4.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A0.4.0) |
| xtd 1.0.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A1.0.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A1.0.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A1.0.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A1.0.0) |

_(*) There is only one enhancement for xtd 0.1.0, as project management was not yet available._

## Examples

The classic first application 'Hello World'.

### Console (CLI)

#### hello_world_console.cpp

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main()->int {
  console::background_color(console_color::blue);
  console::foreground_color(console_color::white);
  console::write_line("Hello, World!");
}
```

**or simply**

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main()->int {
  console::out << background_color(console_color::blue) << foreground_color(console_color::white) << "Hello, World!" << environment::new_line();
}
```

#### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)

project(hello_world_console)
find_package(xtd REQUIRED)
add_sources(hello_world_console.cpp)
target_type(CONSOLE_APPLICATION)
```

#### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

#### Output

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/examples/hello_world_console.png)

### Forms (GUI like WinForms)

#### hello_world_forms.cpp

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    text("Hello world (message_box)");

    button1.location({10, 10});
    button1.parent(*this);
    button1.text("&Click me");
    button1.click += [] {
      message_box::show("Hello, World!");
    };
  }
  
private:
  button button1;
};

auto main()->int {
  application::run(main_form {});
}
```

**or simply**

```cpp
#include <xtd/xtd>

auto main()->int {
  auto main_form = xtd::forms::form::create("Hello world (message_box)");
  auto button1 = xtd::forms::button::create(main_form, "&Click me", {10, 10});
  button1.click += [] {xtd::forms::message_box::show("Hello, World!");};
  xtd::forms::application::run(main_form);
}
```

#### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)

project(hello_world_forms)
find_package(xtd REQUIRED)
add_sources(hello_world_forms.cpp)
target_type(GUI_APPLICATION)
```

#### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

#### Output

##### Windows

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/hello_world_w.png)

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/hello_world_wd.png)

##### macOS

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/hello_world_m.png)

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/hello_world_md.png)

##### Linux Gnome

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/hello_world_g.png)

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/hello_world_gd.png)

### tunit (Unit tests like Microsoft Unit Testing Framework)

#### hello_world_test.cpp

```cpp
#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(hello_world_test) {
  public:
    void test_method_(create_string_from_literal) {
      auto s = string {"Hello, World!"};
      valid::are_equal(13, s.size());
      assert::are_equal("Hello, World!", s);
    }
    
    void test_method_(create_string_from_chars) {
      auto s = string {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid::are_equal(13, s.size());
      string_assert::starts_with("Hello,", s);
      string_assert::ends_with(" World!", s);
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}
```

**or without helpers**

```cpp
#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class hello_world_test;
  
  auto hello_world_test_class_attr = test_class_attribute<hello_world_test> {"hello_world_test"};
  class hello_world_test : public test_class {
  public:
    test_method_attribute create_string_from_literal_attr {"create_string_from_literal", *this, &hello_world_test::create_string_from_literal};
    void create_string_from_literal() {
      auto s = string {"Hello, World!"};
      valid::are_equal(13, s.size());
      assert::are_equal("Hello, World!", s);
    }
    
    test_method_attribute create_string_from_chars_attr {"create_string_from_chars", *this, &hello_world_test::create_string_from_chars};
    void create_string_from_chars() {
      auto s = string {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid::are_equal(13, s.size());
      string_assert::starts_with("Hello,", s);
      string_assert::ends_with(" World!", s);
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}
```

#### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)

project(hello_world_test)
find_package(xtd REQUIRED)
add_sources(hello_world_test.cpp)
target_type(TEST_APPLICATION)
```

#### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

#### Output

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/examples/hello_world_tunit.png)

## Gallery

[![minesweeper](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/minesweeper.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/minesweeper/README.md)

[minesweeper (on Windows)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/minesweeper/README.md)

______________________________________________________________________________________________

[![game_of_life](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/game_of_life.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/game_of_life/README.md)

[game_of_life (on macOS)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/game_of_life/README.md)

______________________________________________________________________________________________

[![xtdc-gui](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtdc-gui.png)](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc-gui/README.md)

[xtdc-gui - Create a new project (on macOS)](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc-gui/README.md)

______________________________________________________________________________________________

[![calculator](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/calculator.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/calculator/README.md)

[calculator (on Ubuntu)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/calculator/README.md)

______________________________________________________________________________________________

[![stopwatch](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/stopwatch.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/stopwatch_form/README.md)

[stopwatch (on Windows)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/stopwatch_form/README.md)

______________________________________________________________________________________________

[![painting](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/painting.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/painting/README.md)

[painting (on Ubuntu)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/painting/README.md)

## Contributing

The [authors file](https://github.com/gammasoft71/xtd/blob/master/AUTHORS.md) lists contributors together with contact information. If you make a contribution, please add yourself to the list.

**Your contributions are welcome.**

* First read [Code of conduct](https://github.com/gammasoft71/xtd/blob/master/CODE_OF_CONDUCT.md) and the [design guidelines](https://gammasoft71.github.io/xtd/docs/documentation/Design%20Guidelines) to make sure your contribution follows the rules.
* [Fork](https://github.com/gammasoft71/xtd/fork) the project and use a pull request for adding your contribution.
* If you face any problems feel free to open an issue at the [issues tracker](https://github.com/gammasoft71/xtd/issues), If you feel like there is a missing feature, please raise a ticket on Github. Pull request are also welcome.

**Your feedback is important for the evolution of the project.**

### Beginners

The following project aims to simplify and guide the way beginners make their first contribution. If you are looking to make your first contribution, check out the project below.

[First Contributions](https://github.com/firstcontributions/first-contributions)

Now you are ready to make your first contribution to xtd.

## See also

* [website](https://gammasoft71.github.io/xtd)
* [wiki](https://github.com/gammasoft71/xtd/wiki)
* [github](https://github.com/gammasoft71/xtd) 
* [project](https://sourceforge.net/projects/xtdpro/) 
* [Reference Guide](https://gammasoft71.github.io/xtd/reference_guides/latest/index.html)
* [Support](https://gammasoft71.github.io/xtd/docs/Support)

______________________________________________________________________________________________

© 2023 Gammasoft.
