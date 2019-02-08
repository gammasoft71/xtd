[![console](docs/pictures/consoleHeader.png)](README.md)

[![Build Status](https://travis-ci.org/gammasoft71/console.svg?branch=master)](https://travis-ci.org/gammasoft71/console)
[![Build status](https://ci.appveyor.com/api/projects/status/29f73qcp4e205549?svg=true)](https://ci.appveyor.com/project/gammasoft71/console)
[![codecov](https://codecov.io/gh/gammasoft71/console/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/console)
[![Documentation](https://codedocs.xyz/gammasoft71/console.svg)](https://codedocs.xyz/gammasoft71/console/)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=console%20website)](https://gammasoft71.wixsite.com/console)
[![license](https://img.shields.io/github/license/gammasoft71/console.svg)](LICENSE.md)
[![SourceForge Download console](https://img.shields.io/sourceforge/dt/console.svg)](https://sourceforge.net/projects/console/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/console.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)


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

## Using xtd::console::WriteLine

hello_world_console.cpp

```c++
#include <console/console>

using namespace xtd;

// The main entry point for the application.
int main() {
  console::foreground_color(console_color::blue);
  console::write_line("Hello, World!");
  console::reset_color();
}

```

## Using xtd::console::out character ostream

hello_world_console_out.cpp

```c++
#include <console/console>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  console::out << foreground_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
}

```

## Using std::cout character ostream

hello_world_cout.cpp

```c++
#include <console/console>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << foreground_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
}

```

Replace console class by wconsole class to use wide character wostream and wistream.

For more examples see [examples](examples)

# Download and install console

Before running examples you must download and install console. To download and install it read Downloads file.

