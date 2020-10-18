[![drawing](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-drawing)

[![Build Status](https://travis-ci.org/gammasoft71/xtd_drawing.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd_drawing)
[![Build status](https://ci.appveyor.com/api/projects/status/mj2nrfvudaa9u4uu?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-drawing)
[![Reference Guide](https://img.shields.io/badge/code-Reference_Guide-brightgreen.svg)](https://codedocs.xyz/gammasoft71/xtd_drawing/)
[![Documentation](https://img.shields.io/badge/wiki-Documentaions-brightgreen.svg)](./README.md)
[![Website](https://img.shields.io/badge/web-gammasoft-brightgreen.svg)](https://gammasoft71.wixsite.com/gammasoft)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.drawing.svg)](LICENSE.md)
<!--- 
[![Download drawing](https://img.shields.io/sourceforge/dt/drawingpro.svg)](https://sourceforge.net/projects/drawingpro/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.drawing.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)
[![codecov](https://codecov.io/gh/gammasoft71/xtd.drawing/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.drawing)
 --->


# Features

* Contains utility classes : point, size, color, ...
* Contains font management classes : font, font family, ...
* Contains system information classes : system font, system color, ...
* Contains painting classes : pen, brush, graphics, ...
* Contains imaging classes . image, bitmap, ...
* ...

For more information see [Documentation](docs).

# Examples

The following example shows how to print system color control informations on ctrace output.

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

Before running examples you must download and install xtd.drawing. To download and install it read Downloads file.

