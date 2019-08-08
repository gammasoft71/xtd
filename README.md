[![console](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-console)

[![Build Status](https://travis-ci.org/gammasoft71/xtd.console.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd.console)
[![Build status](https://ci.appveyor.com/api/projects/status/7i6t0xilki708d2s?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-console)
[![codecov](https://codecov.io/gh/gammasoft71/xtd.console/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.console)
[![Documentation](https://codedocs.xyz/gammasoft71/xtd.console.svg)](https://codedocs.xyz/gammasoft71/xtd.console/)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-console%20website)](https://gammasoft71.wixsite.com/xtd-console)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.console.svg)](LICENSE.md)
[![SourceForge Download console](https://img.shields.io/sourceforge/dt/console-cpp.svg)](https://sourceforge.net/projects/console-cpp/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.console.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)


# Features

* Contains utility classes : point, size, color, ...
* Contains font management classes : font, font family, ...
* Contains system information classes : system font, system color, ...
* Contains painting classes : pen, brush, graphics, ...
* Contains imaging classes . image, bitmap, ...
* ...

For more information see [Documentation](docs).

# Examples

The following examples "Hello, world!" show how to print system color control informations on ctrace output.

src/drawing_hello_world.cpp

```c++
#define TRACE
#include <xtd/xtd.drawing>

usin€ namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  color color = system_colors::control;
  ctrace << format("color = {}", color) << endl;
  ctrace << format("Argb = 0x{:X}", color.to_argb()) << endl;
  ctrace << format("Alpha = {}", color.a() << endl);
  ctrace << format("Red = {}", color.r() << endl);
  ctrace << format("Green = {}", color.g() << endl);
  ctrace << format("Blue = {}", color.b() << endl);
}

```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install xtd.console. To download and install it read Downloads file.

