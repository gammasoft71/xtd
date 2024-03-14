---
sidebar_position: 6
---

# What is xtd? Introduction and overview

`xtd` is a free, cross-platform, open source developer platform for building many kinds of applications.
`xtd` is built on the C++ Standard library a high-performance third-party libraries when needed.

## Desktop applications

* Console applications
* Desktop applications (GUI)
* Test Applications


## Features

* Free and open-source ([MIT License](/docs/documentation/license));
* a collection of native C++ classes libraries, to **extend** std;
* API close to the .net API with a modern C++ approach and full integration with the std standard;
* `xtd` is designed to manage GUI controls and dialogs in pure [native mode](https://github.com/gammasoft71/xtd/blob/master/docs/control_appearance.md) or with [CSS styles](https://github.com/gammasoft71/xtd/blob/master/docs/style_sheets_overview.md).
* written in efficient, modern C++17 / C++20 with [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming idiom;
* and [highly portable](https://gammasoft71.wixsite.com/xtdpro/portability) and available on [many different platforms](https://gammasoft71.wixsite.com/xtdpro/portability);

## Using xtd

`xtd` apps and libraries are built from source code and a CMake project file, using the `xtdc` CLI or an Integrated Development Environment (IDE) like Visual Studio, Xcode, ...

The following example is a minimal `xtd` app:

CMakeLists.txt file:

```cmake
cmake_minimum_required(VERSION 3.20)

project(app)
find_package(xtd REQUIRED)
add_sources(app.cpp)
target_type(CONSOLE_APPLICATION)
```

app.cpp file:

```cpp
#include <xtd/xtd>

auto main()->int {
  xtd::console::write_line("Hello, World!");
}
```

The app can be built and run with the [xtdc](https://github.com/gammasoft71/xtd/tree/master/tools/xtdc) CLI:

```shell
%xtdc run
Hello, World!
```

It can also be built and run as two separate steps. The following example is for an app that is named *app*:

```shell
% xtdc build
% ./build/Debug/app
Hello, World!
```

## Free and open source

* `xtd` is free, [open source](https://github.com/gammasoft71/xtd).
* `xtd` sources and binaries are licensed under the [MIT license](https://gammasoft71.wixsite.com/xtdpro/license).

## Languages

You can write `xtd` apps in modern **C++17** or above and **C** (For more info about c binding see [xtd_c project](https://github.com/gammasoft71/xtd_c).

* **C++17** is a simple, modern, object-oriented, and type-safe programming language (For more information about c++ see [cppreference](https://en.cppreference.com/w/cpp)).
* **C** is an approachable language with a simple syntax for building type-safe (For more information about c see [cppreference](https://en.cppreference.com/w/c)).

## Compilers

The compilers listed below are supported with xtd :

* Xcode 11.6 - Apple clang version 11.0.3 or later
* clang 10 or later
* GCC 10 or later
* Visual Studio 2019 RTW 16.0 or later

Other compilers can probably be used, but they have not been tested yet.

## Tools

The `xtd` product family provides a great `xtd` development experience on **macOS**, **Windows**, and **Linux**.

With CMake, `xtd` support many [Development Environment Tools](https://gammasoft71.wixsite.com/xtdpro/portability).

`xtd` has some [tools](https://github.com/gammasoft71/xtd/blob/master/docs/tools.md) to help you in your development.

## CI/CD

`xtd` can be used with various continuous integration tools and environments, such as:

* [GitHub Actions](https://github.com/features/actions)
* [Travis CI](https://www.travis-ci.com)
* [AppVeyor](https://www.appveyor.com)

## Next step

* [Choose a xtd tutorial](/docs/documentation/Guides/Overview/Tutorials)

[//]: # (https://dotnet.microsoft.com/en-us/learn/dotnet/what-is-dotnet)
