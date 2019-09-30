[![forms](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-forms)

[![Build Status](https://travis-ci.org/gammasoft71/xtd.forms.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd.forms)
[![Build status](https://ci.appveyor.com/api/projects/status/7i6t0xilki708d2s?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-forms)
[![codecov](https://codecov.io/gh/gammasoft71/xtd.forms/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.forms)
[![Documentation](https://codedocs.xyz/gammasoft71/xtd.forms.svg)](https://codedocs.xyz/gammasoft71/xtd.forms/)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-forms%20website)](https://gammasoft71.wixsite.com/xtd-forms)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.forms.svg)](LICENSE.md)
[![SourceForge Download forms](https://img.shields.io/sourceforge/dt/forms-cpp.svg)](https://sourceforge.net/projects/forms-cpp/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.forms.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)


# Features

* Contains common controls like label, button, check box, rich text box, tree view, ...
* Contains containers like form, group box, panel, tab control, ...
* Contains menu and toolbar.
* Contains components like timer, cursors, sounds, ..
* Contains various dialogs like message box, open file dialog, color dialog, font dialog, ...
* Easy catch control events by using event and delegates classes.
* You can create your own controls and add your own events.
* All controls are natives (win32 on windows, cocoa on macOS, gtk on linux).
* If target os does not exist you can create your own native library to support it.
* ...

For more information see [Documentation](docs).

# Examples

The following examples "Hello, world!" show how use form and button control, catch event click and show a message box.

src/forms_hello_world.cpp

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
  form1.text("Hello World Form");
  form1.controls().push_back(button1);

  application::run(form1);
}

```

For more examples see [examples](examples/README.md)

# Download and install

Before running examples you must download and install xtd.forms. To download and install it read Downloads file.

