[![forms](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-forms)

[![Build Status](https://travis-ci.org/gammasoft71/xtd_forms.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd_forms)
[![Build status](https://ci.appveyor.com/api/projects/status/ok6m6omcftt8qque?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-forms)
[![Reference Guide](https://img.shields.io/badge/code-Reference_Guide-brightgreen.svg)](https://codedocs.xyz/gammasoft71/xtd_forms/)
[![Documentation](https://img.shields.io/badge/wiki-Documentaions-brightgreen.svg)](./docs/home.md)
[![Website](https://img.shields.io/badge/web-xtd--forms-brightgreen.svg)](https://gammasoft71.wixsite.com/gammasoft)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.forms.svg)](LICENSE.md)
<!--- [![SourceForge Download forms](https://img.shields.io/sourceforge/dt/formspro.svg)](https://sourceforge.net/projects/formspro/files/latest/download) --->
<!--- [![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.forms.svg)](README.md) --->
<!--- [![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md) --->
<!--- [![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md) --->
<!--- [![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md) --->
<!--- [![codecov](https://codecov.io/gh/gammasoft71/xtd_forms/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd_forms) --->

# Features

* Contains common controls, containers, menu, toolbar, components, various dialogs, ...
* Easy catch control events by using event and delegates classes.
* All controls are natives (win32 on windows, cocoa on macOS, gtk+3 on linux).
* ...

For more information see [documentations](docs/home.md) ([website](https://gammasoft71.wixsite.com/gammasoft)) and [Reference Guide](https://codedocs.xyz/gammasoft71/xtd_forms/).

# Examples

The following examples "Hello, world!" show how use form and button control, catch event click and show a message box.

hello_world_message_box.cpp

```c++
#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  button button1;
  button1.text("Click me");
  button1.location({10, 10});
  button1.click += [] {
    message_box::show("Hello, World!");
  };

  form form1;
  form1.text("Hello world (message_box)");
  form1.controls().push_back(button1);

  application::run(form1);
}

```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_message_box)
find_package(xtd.forms REQUIRED)
add_sources(hello_world_message_box.cpp)
target_type(GUI_APPLICATION)
```

For more examples see [examples](examples/README.md)

# Tutorial

[Tutorial](docs/tutorial.md) provide a tutorial to cover the basics needed to create xtd_forms applications.

# Download and install

Before running examples you must download and install xtd.forms. To download and install it read [downloads](docs/downloads.md) file.
