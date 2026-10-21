# xtd

**Write Once, Run Everywhere!**

[![logo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo.png)](https://gammasoft71.github.io/xtd)

<br/>

**xtd (pronounced "extend") is a modern C++20/23 framework to create console (CLI), forms (GUI) and unit test (xUnit) multiplatform applications and libraries.**

<br/>
<div style={{ display: 'flex', justifyContent: 'left', flexWrap: 'wrap', gap: '30px', marginTop: '10px' }}>
  <a href="https://gammasoft71.github.io/xtd/docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/Windows_h100.png"/></a>
  <a href="https://gammasoft71.github.io/xtd/docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/macOS_h100.png"/></a>
  <a href="https://gammasoft71.github.io/xtd/docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/Linux_h100.png"/></a>
  <a href="https://gammasoft71.github.io/xtd/docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/iOS_h100.png"/></a>
  <a href="https://gammasoft71.github.io/xtd/docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/Android_h100.png"/></a>
  <a href="https://gammasoft71.github.io/xtd/docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/FreeBSD_h100.png"/></a>
  <a href="https://gammasoft71.github.io/xtd/docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/Haiku_h100.png"/></a>
  <a href="https://gammasoft71.github.io/xtd/docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/SerenityOS_h100.png"/></a>
</div>
<br/>
<br/>

[![codecov](https://codecov.io/gh/gammasoft71/xtd/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd) [![web](https://img.shields.io/badge/website-xtd-004080.svg)](https://gammasoft71.github.io/xtd) [![Reference Guide](https://img.shields.io/badge/code-reference%20guide-004080.svg)](https://gammasoft71.github.io/xtd/reference_guides/latest/index.html) [![wiki](https://img.shields.io/badge/wiki-xtd-004080.svg)](https://github.com/gammasoft71/xtd/wiki) [![discord](https://img.shields.io/badge/discord-gammasoft-7289DA.svg)](https://discordapp.com/users/gammasoft#9288) [![Download xtd](https://img.shields.io/sourceforge/dt/xtdpro.svg)](https://sourceforge.net/projects/xtdpro/files/latest/download) [![OctoCounts](https://api.octocounts.com/badge/gammasoft71/xtd/branch/master?type=code)](https://octocounts.com/github/gammasoft71/xtd/tree/master)
 
# Latest news

* [xtd 1.0.0 will require C++20 as the minimum standard](https://gammasoft71.github.io/xtd/docs/news/20250615) - Posted on June 15, 2025
* [Release xtd 0.1.2 (beta)](https://gammasoft71.github.io/xtd/docs/news/20240312) - Posted on March 12, 2024
* [The xtd 1.0.0 is growing](https://gammasoft71.github.io/xtd/docs/news/20231112) - Posted on November 12, 2023
* [Release xtd 0.1.1 (beta)](https://gammasoft71.github.io/xtd/docs/news/20230717) - Posted on July 17, 2023
* [All news](https://gammasoft71.github.io/xtd/docs/news)

## Features

* Free and open-source ([MIT License](https://gammasoft71.github.io/xtd/docs/documentation/license));
* a collection of native C++ classes libraries, to **extend** std;
* API close to the .net API with a modern C++ approach and full integration with the std standard;
* xtd is designed to manage GUI controls and dialogs in pure [native mode](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Overview/control_appearance) or with [CSS styles](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
* written in efficient, modern [C++20/23](https://en.cppreference.com/w/) with [RAII](https://en.cppreference.com/w/cpp/language/raii) programming idiom;
* and [highly portable](https://gammasoft71.github.io/xtd/docs/documentation/portability) and available on [many different platforms](https://gammasoft71.github.io/xtd/docs/documentation/portability);
* See [features](https://gammasoft71.github.io/xtd/docs/documentation/features) for more information.

## xtd libraries architecture

[![architecture_logo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/block_diagram_onion.png)](https://gammasoft71.github.io/xtd/docs/documentation/guides/Overview/Libraries/hierarchy)

xtd consists of several libraries.

### xtd.core

[![core](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd.core.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html)
The [xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html) library is modern C++20/23 libraries of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.

### xtd.drawing

[![drawing](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd.drawing.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html)
The [xtd.drawing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html) library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.

### xtd.forms

[![forms](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd.forms.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html)
The [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows, Apple macOS and linux-based operating system.

### xtd.tunit

[![tunit](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd.tunit.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html)
The [xtd.tunit](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html) library is a unit-testing framework for modern C++20, inspired by [Microsoft.VisualStudio.TestTools.Cpp](https://docs.microsoft.com/en-us/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference).

## Getting Started

* [Installation](https://gammasoft71.github.io/xtd/docs/downloads) provides download, install and uninstall documentation.
* [Guides](https://gammasoft71.github.io/xtd/docs/documentation/guides) provides xtd guides and tutorials.
* [Examples](https://github.com/gammasoft71/xtd/blob/master/examples/README.md) provides 1k examples to help you use xtd, grouped by libraries and topics.

## Development status

* [Release notes](https://gammasoft71.github.io/xtd/docs/documentation/release_notes) provides release notes information.
* [Roadmap](https://gammasoft71.github.io/xtd/docs/documentation/roadmap) provides a view of the xtd roadmap.
* [Kanban board](https://github.com/users/gammasoft71/projects/3) provides a Kanban view for all tasks (enhancements, pull requests, bugs, questions,...).
* [Development status]([https://gammasoft71.github.io/xtd/docs/documentation/Development%20status](https://gammasoft71.github.io/xtd/docs/documentation/development_status)) provides information about classes and libraries development status.
* [Translation status](https://gammasoft71.github.io/xtd/docs/documentation/translation_status) provides information about translations status.

## Current release status

[![GitHub milestone](https://img.shields.io/github/milestones/progress/gammasoft71/xtd/1?color=004080&style=for-the-badge)](https://github.com/gammasoft71/xtd/milestone/1) [![GitHub milestone](https://img.shields.io/github/milestones/progress-percent/gammasoft71/xtd/1?color=004080&label=complete%20&style=for-the-badge)](https://github.com/gammasoft71/xtd/milestone/1)
  
This project is an open source project. The developers who participate do so on their own time. It is therefore difficult to set release dates. 

But you can follow the evolution of the development. We keep the status up to date.

## Continuous Integration build status

At each commit, a build and unit tests are performed for the following configurations

| Operating system | Architecture            | Compiler      | Build Type      | Status                                                                                                                                                                                      |
| -----------------| ----------------------- | ------------- | --------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Linux (Ubuntu)   | x86 / x64               | Clang / GCC   | Debug / Release | [![Ubuntu](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/ubuntu.yml?branch=master&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/ubuntu.yml)    |
| macOS            | x64 / arm64             | Apple Clang   | Debug / Release | [![macOS](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/macos.yml?branch=master&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/macos.yml)       |
| Windows          | x86 / x64               | MSVC (VS2022) | Debug / Release | [![Windows](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/windows.yml?branch=master&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/windows.yml) |
| Windows (MSYS2)  | x64                     | Clang / GCC   | Debug / Release | [![Manually](https://img.shields.io/badge/build-manually-004080?branch=master&logo=gitHub&.svg)]()                                                                                          |
| Android _(*)_    | arm64-v8a / armeabi-v7a | Clang (NDK)   | Release         | [![Coming soon](https://img.shields.io/badge/build-coming%20soon...-808080?branch=master&logo=gitHub&.svg)]()                                                                               |
| iOS _(*)_        | arm64 / x86_64 sim      | Apple Clang   | Release         | [![Coming soon](https://img.shields.io/badge/build-coming%20soon...-808080?branch=master&logo=gitHub&.svg)]()                                                                               |
| FreeBSD          | x64                     | Clang / GCC   | Debug / Release | [![Manually](https://img.shields.io/badge/build-manually-004080?branch=master&logo=gitHub&.svg)]()                                                                                          |
| Haiku _(*)_      | x86                     | GCC           | Debug           | [![Manually](https://img.shields.io/badge/build-manually-004080?branch=master&logo=gitHub&.svg)]()                                                                                          |

 _(*) [xtd.core and xtd.tunit only](https://gammasoft71.github.io/xtd/docs/documentation/portability)._

| Deploy to GitHub Pages                   | status                                                                                                                                                                                                           |
| ---------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Deployment of the website                | [![Ubuntu Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/deploy.yml?branch=docs&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/deploy.yml)                     |
| Deployment of the latest reference guide | [![Ubuntu Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/reference_guide.yml?branch=master&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/reference_guide.yml) |

## Issues status

As xtd is managed by a [Kanban project](https://github.com/users/gammasoft71/projects/3), the number of open issues can be quite large. The table below gives a clearer view on the number of open bugs/questions and enhancements.

| Issues                                          | Open                                                                                                                                                                                                                                                                                                       | Closed                                                                                                                                                                                                                                                                                                                                |
| ----------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bugs / Questions from users                     | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=red&label=query&query=is%3Aopen%20is%3Aissue+-label%3Aenhancement)](https://github.com/gammasoft71/xtd/issues?q=is%3Aopen+is%3Aissue+-label%3Aenhancement)                                        | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20-label%3Aenhancement)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+-label%3Aenhancement+is%3Aclosed)                                   |
| xtd 0.1.0 - Enhancements / Developments _(**)_  | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A0.1.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A0.1.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A0.1.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A0.1.0) |
| xtd 0.1.1 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A0.1.1)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A0.1.1) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A0.1.1)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A0.1.1) |
| xtd 1.0.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A1.0.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A1.0.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A1.0.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A1.0.0) |
| xtd 1.1.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A1.1.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A1.1.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A1.1.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A1.1.0) |
| xtd 1.2.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A1.2.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A1.2.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A1.2.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A1.2.0) |
| xtd 1.3.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A1.3.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A1.3.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A1.3.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A1.3.0) |
| xtd 2.0.0 - Enhancements / Developments         | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=004080&label=query&query=is%3Aopen%20is%3Aissue%20label%3Aenhancement+milestone%3A2.0.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aissue+label%3Aenhancement+is%3Aopen+milestone%3A2.0.0) | [![GitHub issue custom search in repo](https://img.shields.io/github/issues-search/gammasoft71/xtd?color=lighgreen&label=query&query=is%3Aclosed%20is%3Aissue%20label%3Aenhancement+milestone%3A2.0.0)](https://github.com/gammasoft71/xtd/issues?q=is%3Aclosed+is%3Aissue+label%3Aenhancement+milestone%3A2.0.0) |

_(**) There is only one enhancement for xtd 0.1.0, as project management was not yet available._

## Examples

The classic first application 'Hello World'.

### Console (CLI)

> This example demonstrates how to display a simple message in the console using [xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html).

#### hello_world_console.cpp

```cpp
#include <xtd/xtd>

class example {
public:
  static auto main() {
    console::background_color(console_color::blue);
    console::foreground_color(console_color::white);
    console::write_line("Hello, World!");
  }
};

startup_(example::main);
```

**or simply**

```cpp
#include <xtd/xtd>

auto main() -> int {
  console::out << background_color(console_color::blue) << foreground_color(console_color::white) << "Hello, World!" << environment::new_line;
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

### Coroutines C++20 with xtd::threading::tasks

> This example asynchronously prints a greeting for each world in parallel, then waits for all greetings to be printed using [xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html).

#### hello_world_coroutine.cpp

```cpp
#include <xtd/xtd>

class program {
public:
  static auto main() async_ {
    auto worlds = {u8"World"_s, u8"Mundo"_s, u8"Monde"_s, u8"Mondo"_s, u8"モンド"_s, u8"世界"_s, u8"Welt"_s, u8"Мир"_s};
    co_await parallel::for_each_async(worlds, [](auto world) async_ {
      co_await task<>::delay(100_ms);
      println("Hello, {}!", world);
    });
  }
};

startup_(program::main);
```

**or simply**

```cpp
#include <xtd/xtd>

auto main_async() -> task<> {
  auto worlds = {u8"World"_s, u8"Mundo"_s, u8"Monde"_s, u8"Mondo"_s, u8"モンド"_s, u8"世界"_s, u8"Welt"_s, u8"Мир"_s};
  co_await parallel::for_each_async(worlds, [](auto world) -> task<> {
    co_await task<>::delay(100_ms);
    println("Hello, {}!", world);
  });
}

auto main() -> int {
  return startup::run(main_async);
}
```

#### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)

project(hello_world_coroutine)
find_package(xtd REQUIRED)
add_sources(hello_world_coroutine.cpp)
target_type(CONSOLE_APPLICATION)
```

#### Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

#### Output

```
Hello, 世界!
Hello, Мир!
Hello, World!
Hello, Welt!
Hello, Mondo!
Hello, Monde!
Hello, モンド!
Hello, Mundo!
```

### Forms (GUI like WinForms)

> This example demonstrates how to create a simple graphical application using [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html).

#### hello_world_forms.cpp

```cpp
#include <xtd/xtd>

class main_form : public form {
public:
  static auto main() {
    application::run(main_form {});
  }
  
  main_form() {
    text("Hello world (message_box)");

    button1.location({10, 10});
    button1.parent(self_);
    button1.text("&Click me");
    button1.click += delegate_ {
      message_box::show("Hello, World!");
    };
  }
  
private:
  button button1;
};

startup_(main_form::main);
```

**or simply**

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto main_form = form::create("Hello world (message_box)");
  auto button1 = button::create(main_form, "&Click me", {10, 10});
  button1.click += [] {message_box::show("Hello, World!");};
  application::run(main_form);
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

> This example demonstrates how to write and run unit tests using [xtd.tunit](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html).

#### hello_world_test.cpp

```cpp
#include <xtd/xtd>

namespace unit_tests {
  class test_class_(hello_world_test) {
    auto test_method_(create_string_from_literal) {
      auto s = string {"Hello, World!"};
      valid_that(s.length()).is().equal_to(13_z);
      assert_that(s).is().equal_to("Hello, World!");
    }
    
    auto test_method_(create_string_from_chars) {
      auto s = string {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid_that(s.length()).is().equal_to(13_z);
      assert_that(s).does().start_with("Hello,").and_().does().end_with(" World!");
    }
    
    static auto main() {
      console_unit_test {}.run();
    }
  };
}

startup_(unit_tests::hello_world_test::main);
```

**or without constraints**

```cpp
#include <xtd/xtd>

namespace unit_tests {
  class test_class_(hello_world_test) {
    auto test_method_(create_string_from_literal) {
      auto s = string {"Hello, World!"};
      valid::are_equal(13_z, s.length());
      assert::are_equal("Hello, World!", s);
    }
    
    auto test_method_(create_string_from_chars) {
      auto s = string {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid::are_equal(13_z, s.length());
      string_assert::starts_with("Hello,", s);
      string_assert::does_end_with(" World!", s);
    }
    
    static auto main() {
      console_unit_test {}.run();
    }
  };
}

startup_(unit_tests::hello_world_test::main);
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

#### Visual Studio Output

![Screenshot](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/examples/hello_world_tunit_vs.png)

## Gallery

### Minesweeper

[![minesweeper](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/minesweeper.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/minesweeper/README.md)

[minesweeper (on Windows)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/minesweeper/README.md)

______________________________________________________________________________________________

### Game of Life

[![game_of_life](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/game_of_life.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/game_of_life/README.md)

[game_of_life (on macOS)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/games/game_of_life/README.md)

______________________________________________________________________________________________

### xtdc-gui

[![xtdc-gui](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtdc-gui.png)](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc-gui/README.md)

[xtdc-gui - Create a new project (on macOS)](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc-gui/README.md)

______________________________________________________________________________________________

### Calculator

[![calculator](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/calculator.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/calculator/README.md)

[calculator (on Ubuntu)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/calculator/README.md)

______________________________________________________________________________________________

### Stopwatch

[![stopwatch](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/stopwatch.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/stopwatch_form/README.md)

[stopwatch (on Windows)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/stopwatch_form/README.md)

______________________________________________________________________________________________

### Painting

[![painting](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/painting.png)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/painting/README.md)

[painting (on Ubuntu)](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/others/painting/README.md)

## Contributing

The [authors file](https://github.com/gammasoft71/xtd/blob/master/AUTHORS.md) lists contributors together with contact information. If you make a contribution, please add yourself to the list.

**Your contributions are welcome.**

* First read [Code of conduct](https://github.com/gammasoft71/xtd/blob/master/CODE_OF_CONDUCT.md) and the [design guidelines](https://gammasoft71.github.io/xtd/docs/documentation/design_guidelines) to make sure your contribution follows the rules.
* [Fork](https://github.com/gammasoft71/xtd/fork) the project and use a pull request for adding your contribution.
* If you encounter any problems, feel free to open an issue in the [issues tracker](https://github.com/gammasoft71/xtd/issues). If you feel like there is a missing feature, please raise a ticket on Github. Pull requests are also welcome.

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

© 2026 Gammasoft.
