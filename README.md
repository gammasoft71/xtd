[![console](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-console)

[![Build Status](https://travis-ci.org/gammasoft71/xtd_console.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd_console)
[![Build status](https://ci.appveyor.com/api/projects/status/7i6t0xilki708d2s?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-console)
[![Reference Guide](https://img.shields.io/badge/code-Reference_Guide-brightgreen.svg)](https://codedocs.xyz/gammasoft71/xtd_console/)
[![Documentation](https://img.shields.io/badge/wiki-Documentaions-brightgreen.svg)](./docs/home.md)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-console%20website)](https://gammasoft71.wixsite.com/xtd-console)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.console.svg)](LICENSE.md)
<!--- [![SourceForge Download console](https://img.shields.io/sourceforge/dt/console-cpp.svg)](https://sourceforge.net/projects/console-cpp/files/latest/download) --->
<!--- [![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.console.svg)](README.md) --->
<!--- [![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md) --->
<!--- [![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md) --->
<!--- [![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md) --->
<!--- [![codecov](https://codecov.io/gh/gammasoft71/xtd.console/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.console) --->

# Features

* Console I/O charecters and wide charercters Streams.
* Full utf-8 support.
* Writes the text representation of the specified list of arguments to the standard output stream using the specified format information.
* Get or set the size of the console window.
* Get or set the position of the console window relative to the screen buffer.
* Get or set the size of the screen buffer.
* Get or set the position of the cursor.
* Get or set the size of the cursor.
* Play the sound of a beep through the console speaker.
* Get or set the foreground and background colors.
* Intercept and send callback to the user when the Control modifier key (Ctrl) and either the C console key (C) or the Break key are pressed simultaneously (Ctrl+C or Ctrl+Break).
* ...

For more information see [Documentation](docs).

# Examples

The following examples "Hello, world!" show how to change the color of the text in three different ways.

## Using xtd::console::write_line

src/console_hello_world_console.cpp

```c++
#include <xtd/xtd.console>

using namespace xtd;

// The main entry point for the application.
int main() {
  console::foreground_color(console_color::blue);
  console::write_line("Hello, World!");
  console::reset_color();
}

```

## Using xtd::console::out character ostream

src/console_hello_world_console_out.cpp

```c++
#include <xtd/xtd.console>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  console::out << foreground_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
}

```

## Using std::cout character ostream

src/console_hello_world_cout.cpp

```c++
#include <xtd/xtd.console>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << foreground_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
}

```

Replace console class by wconsole class to use wide character wostream and wistream.

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install xtd.console. To download and install it read Downloads file.

