[![Switch](docs/pictures/consoleHeader.png)](README.md)

[![Build Status](https://travis-ci.org/gammasoft71/console.svg?branch=master)](https://travis-ci.org/gammasoft71/console) [![Build status](https://ci.appveyor.com/api/projects/status/29f73qcp4e205549?svg=true)](https://ci.appveyor.com/project/gammasoft71/console) [![Documentation](https://codedocs.xyz/gammasoft71/console.svg)](https://codedocs.xyz/gammasoft71/console/)

# Features

* Console I/O charecters and wide charercters Streams.
* Full Utf-8 support.
* Get or set the size of the console window.
* Get or set the position of the console window relative to the screen buffer.
* Get or set the size of the screen buffer.
* Get or set the position of the cursor.
* Get or set the size of the cursor.
* Play the sound of a beep through the console speaker.
* Get or set the foreground and background colors

For more information see Documentation.

# Examples

## gammasoft::console

hello_world_console.cpp

```c++
#include <console/console>

using namespace gammasoft;

// The main entry point for the application.
int main() {
  console::fore_color(console_color::blue);
  console::write_line("Hello, World!");
  console::reset_color();
}

```

## gammasoft::console::out

hello_world_console_out.cpp

```c++
#include <console/console>

using namespace gammasoft;
using namespace cout;

// The main entry point for the application.
int main() {
  console::out << fore_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
}

```

## std::cout

hello_world_cout.cpp

```c++
#include <console/console>

using namespace gammasoft;
using namespace cout;

// The main entry point for the application.
int main() {
  cout << fore_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
}

```

For more examples see Examples

# Download and install console

Before running examples you must download and install console. To download and install it read Downloads file.

