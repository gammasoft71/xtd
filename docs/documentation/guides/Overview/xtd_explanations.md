---
sidebar_position: 7
---

# About xtd

## Table of contents

* [Motivations](#motivations)
* [What is xtd Framework ?](#What-is-xtd-framework)
* [xtd API](#xtd-api)
* [xtd libraries](#xtd-libraries)
* [xtd architecture](#xtd-architecture)
  * [Dependency](#dependency)
  * [xtd.core](#xtdcore)
  * [xtd.core.native](#xtdcorenative)
  * [xtd.core.native.unix](#xtdcorenativeunix)
  * [xtd.core.native.win32](#xtdcorenativewin32)
  * [xtd.drawing](#xtddrawing)
  * [xtd.drawing.native](#xtddrawingnative)
  * [xtd.drawing.native.wxwidgets](#xtddrawingnativewxwidgets)
  * [xtd.forms](#xtdforms)
  * [xtd.forms.native](#xtdformsnative)
  * [xtd.forms.native.wxwidgets](#xtdformsnativewxwidgets)
* [xtd tools](#xtd-tools)
  * [Command line tools](#command-line-tools)
  * [GUI tools](#gui-tools)
* [xtd tests](#xtd-tests)
  * [Unit tests](#unit-tests)
  * [Manual tests](#manual-tests)
* [xtd themes](#xtd-themes)
  * [Current Operating System / Desktop Environment](#current-operating-system-desktop-environment)
  * [Generic](#generic)
  * [Colors only](#colors-only)
  * [Owner themes](#owner-themes)
* [Build](#build)
  * [CMake](#cmake)
  * [Specific CMake commands](#specific-cmake-commands)
  * [xtd build CMake options for xtd developers](#xtd-build-cmake-options-for-xtd-developers)
* [xtd guidelines](#xtd-guidelines)
* [Unit tests](#unit-tests)
* [Continuous integration builds](#continuous-integration-builds)
* [Test coverage](#test-coverage)
* [xtd documentation](#xtd-documentation)

## Motivations

What are the criteria for a modern C++ framework in 2019 :

* C++17/20 modern
* [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming idiom.
* Use of namespace and no prefix
* No defines for constants and no macros for functions or event logging.
* All classes must be in namespaces.
* No global but rather static classes.
* No functions outside of classes except for extend std.
* Native controls if no theme defined. However, controls must be able to support predefined CSS themes or CSS themes created by the developer himself.
* Controls can be drawing by the user.
* Close to the std.
* Denomination of classes and functions according to std and boost standard.
* Modern events based on std::functional.
* Clear and unambiguous API. With a consistent style throughout the evolution of the framework.

After looking and trying (more or less in depth) many known or unknown C++ GUI libraries/frameworks. 
I never found one that matched these criteria.

Just take all the existing C++ GUI libraries and frameworks and you can see that none of them fit the above criteria. 
This does not mean that they are not good or that they do not work. Far from it, some of them are excellent, like Qt, wxWidgets, JUCE to name only these three.
Some others are excellent too, some are less good and unfortunately many are mediocre or even abandoned.

Here is a [paper](https://philippegroarke.com/posts/2018/c++_ui_solutions/) written by Philippe M. Groarke that summarizes the advantages and disadvantages of each C++ library/framework.

So the decision to create a new GUI in modern C++ was made.

## What is xtd Framework ?

xtd is a framework based on an OS abstraction via the xtd.core.native API and a graphical abstraction via the xtd.drawing.native API and the xtd.forms.native API.

At the moment there are two implementations of the xtd.core.native API:
* xtd.core.native.win32 : Windows platform.
* xtd.core.native.unix : linux, Android, ios and macOS.

But other operating systems can be added in the future or earlier if needed by implementing the xtd.core.native API like :
* xtd.core.native.chromeos : Chrome OS.
* xtd.core.native.haiku : Haiku.
* xtd.core.native.xxx : xxx being any OS.

For the moment there is an implementation of the APIs xtd.drawing.native and xtd.forms.native :
* xtd.drawing.native.wxwidgets and xtd.forms.native.wxwidgets : wxWidgets toolkit.

But in the futur, other graphical interfaces can be added by implementing the xtd.drawing.native and xtd.forms.native APIs as per rexamples :
* xtd.drawing.native.cocoa and xtd.forms.native.cocoa : macOS appkit. (macOS native API)
* xtd.drawing.native.gtk and xtd.forms.native.gtk : linux Gtk API. (native linux Gnome API)
* xtd.drawing.native.qt6 and xtd.forms.native.qt6 : Qt toolkit. (API "native" Kde linux)
* xtd.drawing.native.win32 and xtd.forms.native.win32 : Microsoft win32 API. (native Windows API)
* xtd.drawing.native.x11 and xtd.forms.native.x11 : X11 API. (generic linux API)
* xtd.drawing.native.x11 and xtd.forms.native.fltk : Fltk API. (generic API)
* xtd.drawing.native.sdl2 and xtd.forms.native.sdl2 : sdl2 media layer. ()
* xtd.drawing.native.sfml and xtd.forms.native.sfml : SFML media library.
* xtd.drawing.native.xxx and xtd.forms.native.xxx : xxx being any other high level or low level graphic API.

In summary the goal of xtd framework is to provide a high level interface with its own functionalities while being extremely portable with the simplest possible abstraction layer on the OS and on the GUI.

## xtd API

When I created xtd, I had the choice of creating my own API or using an existing API. 
I chose to use an existing API because it is difficult to have a consistent API.

I also wanted to have an API close to the Win32 API and events because this API and events are known by many developers.

Which one to choose? It had to be the one that I knew best, that was consistent and that was complete.

In the company I work for, a little more than 12 years ago, we had a project that had to run on the desktop, on an embedded system and on Android (the backend could not be written in Java because the embedded system could not run a JVM).
The modern C++11 didn't exist yet, it was the beginning and it wasn't present on all compilers. 
So I had to create a framework (threads, diagnostics, sockets, web sockets, io, unicode, ... RAII programming idiom, but no GUI) to implement the shortcomings of C++ and I based myself on the .Net framewrok. 

* The Win32 API is too low level and is in pure C.
* The MFC API is not consistant and old.
* The .Net Framework is consistant and close to WIn32 API and events but is CSharp or managed C++ with garbage collector.
* JavaFX is not close to Win32 API and events but is Java with garbage collector.
* Qt's API is old C++ and doesn't match the modern C++ canon and I don't like that.
* wxWidgets API is convoluted and old c++.
* FLTK is closer to C than to modern C++. Even if I find it attractive for its lightness and its ease of use.
* JUCE is close to a modern c++ API as we would like but unfortunately has a paid license if we don't want to have a splash screen.
* ...

My choice was naturally for the .Net Framework API.

### Notes

* All classes and methods are adapted to xtd and modern C++.

## xtd libraries

* xtd API is close to the .net API with a modern C++ approach and full integration with the std standard.
* [xtd.core](https://github.com/gammasoft71/xtd/blob/master/src/xtd.core) contains some components from mscorelib, System, System.Core libraries of the .Net Framework and of Mono.
* [xtd.drawing](https://github.com/gammasoft71/xtd/blob/master/src/xtd.drawing) contains some components from System.Drawing library of the .Net Framework and of Mono.
* [xtd.forms](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms) contains some components from System.Windows.Forms library of the .Net Framework and of Mono.
* [xtd.tunit](https://github.com/gammasoft71/xtd/blob/master/src/xtd.tunit) contains some components from Microsoft.VisualStudio.TestTools.Cpp and support [xUnit](https://en.wikipedia.org/wiki/XUnit) standard.

## xtd architecture

See [architecture diagram](https://github.com/gammasoft71/xtd/blob/master/docs/hierarchy.md).

xtd is composed of several libraries.

* xtd.core : The xtd.core library is modern C++20 libraries of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.
* xtd.drawing : The xtd.drawing library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
* xtd.forms : The xtd.forms library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows, Apple macOS and linux base operating system.
* xtd.tunit : The xtd.tunit library is a unit-testing framework for modern C++20 inspired by [Microsoft.VisualStudio.TestTools.Cpp](https://docs.microsoft.com/en-us/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference).

### Dependency

* xtd.core.native : no dependency
* xtd.core.native.unix : xtd.core.native
* xtd.core.native.win32 : xtd.core.native
* xtd.core : xtd.core.native, xtd.core.native.unix or xtd.core.native.win32 or other in the future.
* xtd.drawing.native : xtd.core
* xtd.drawing.native.wxwidgets : xtd.drawing.native
* xtd.drawing : xtd.drawing.native, xtd.drawing.native.wxwidgets or other in the future.
* xtd.form.native : xtd.drawing
* xtd.form.native.wxwidgets : xtd.forms.native
* xtd.forms : xtd.forms.native, xtd.forms.native.wxwidgets or other in the future.
* xtd.tunit : xtd.core (not for tests as such, but only used by xtd::tunit::console_unit_test to print the result on the console and for the very partial use of xtd::diagnostics::stack_frame to know the test line).

#### Remarks

All libraries use the std.

### xtd.core

This library is high level API that has access only to the std and xtd.core.native.xxx (xxx = win32, unix, ...) via xtd.core.native interface.

#### Some Rules

* Under no circumstances should xtd.core, xtd.drawing, xtd.forms or xtd.tunit do any precompilation tests (#if defined ... #endif) on the compiler or the OS.
Some cases like debug or release (NDEBUG) for diagnostic components. But otherwise that's all. 
If there is a possible difference between OS or compilers, you have to use the xtd.core.native interface. 
* In the same way, if you use an external library, you have to use the xtd.core.native interface. 
This allows you to isolate yourself from the thridparty library and to replace it if necessary without having to rewrite all the code that calls it.

##### Remarks

There are still some cases that are not yet fully compliant with these rules but this should be fixed before the 1.0.0 release.

### xtd.core.native

This library is a low-level API that has access to the operating system and third-party libraries.

The role of is API is the same que l'API de le JVM of Java ou Common Language Runtime (CLR) of .Net Framework.

### xtd.core.native.unix

It is a low-level library that implements the xtd.core.native interface for linux, macOS, iOs and Android.

### xtd.core.native.win32

It is a low-level library that implements the xtd.core.native interface for Windows.

### xtd.drawing

This library is high level API that has access only to xtd.core and xtd.drawing.native.xxx (xxx = wxwidgets or other in the future) via xtd.drawing.native interface.

#### Rule

* In no case xtd.drawing should do precompilation tests (#if defined ... #endif) on the GDI+ graphics.
If there is a possible difference between GDI+ graphics, you have to use the xtd.ddrawing.native interface. 

### xtd.drawing.native

This library is a low-level API that has access to the GDI+ graphics.

The role of is API is the same que l'API de le JVM of Java ou Common Language Runtime (CLR) of .Net Framework.

### xtd.drawing.native.wxwidgets

It is a low-level library that implements the xtd.drawing.native interface for wxWidgets.

### xtd.forms

This library is high level API that has access only to xtd.ddrawing and xtd.forms.native.xxx (xxx = wxwidgets or other in the future) via xtd.forms.native interface.

#### Rule

* In no case xtd.forms should do precompilation tests (#if defined ... #endif) on the GUI.
If there is a possible difference between GUI, you have to use the xtd.forms.native interface. 

### xtd.forms.native

This library is a low-level API that has access to the GUI.

The role of this API is the same as that of the Java JVM API or the Common Language Runtime (CLR) of the .Net Framework.

### xtd.forms.native.wxwidgets

It is a low-level library that implements the xtd.forms.native interface for wxWidgets.

## xtd tools

### Command line tools

* [xtdc](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc/README.md) is project management command line tool.
* [guidgen](https://github.com/gammasoft71/xtd/blob/master/tools/guidgen/README.md) is a guid generator command line tool.
* [sleepfor](https://github.com/gammasoft71/xtd/blob/master/tools/sleepfor/README.md) is a sleep for duration command line tool.

### GUI tools

* [guidgen-gui](https://github.com/gammasoft71/xtd/blob/master/tools/guidgen-gui/README.md) is a guid generator GUI application.
* [xtdc-gui](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc-gui/README.md) is project management GUI application.

## xtd tests

### Unit tests

* [xtd.core.unit_tests](https://github.com/gammasoft71/xtd/blob/master/tests/xtd.core.unit_tests) contains unit tests for [xtd.core](https://github.com/gammasoft71/xtd/blob/master/src/xtd.core) library.
* [xtd.drawing.unit_tests](https://github.com/gammasoft71/xtd/blob/master/tests/xtd.drawing.unit_tests) contains unit tests for [xtd.drawing](https://github.com/gammasoft71/xtd/blob/master/src/xtd.drawing) library.
* [xtd.forms.unit_tests](https://github.com/gammasoft71/xtd/blob/master/tests/xtd.forms.unit_tests) contains unit tests for [xtd.forms](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms) library.
* [xtd.tunit.unit_tests](https://github.com/gammasoft71/xtd/blob/master/tests/xtd.tunit.unit_tests) contains unit tests for [xtd.tunit](https://github.com/gammasoft71/xtd/blob/master/src/xtd.tunit) library.

### Manual tests

* [xtd.core.manual_tests](https://github.com/gammasoft71/xtd/blob/master/tests/xtd.core.manual_tests) contains manual tests for [xtd.core](https://github.com/gammasoft71/xtd/blob/master/src/xtd.core) library.
* [xtd.drawing.manual_tests](https://github.com/gammasoft71/xtd/blob/master/tests/xtd.drawing.manual_tests) contains manual tests for [xtd.drawing](https://github.com/gammasoft71/xtd/blob/master/src/xtd.drawing) library.
* [xtd.forms.manual_tests](https://github.com/gammasoft71/xtd/blob/master/tests/xtd.forms.manual_tests) contains unit manual for [xtd.forms](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms) library.
* [xtd.tunit.manual_tests](https://github.com/gammasoft71/xtd/blob/master/tests/xtd.tunit.manual_tests) contains unit manual for [xtd.tunit](https://github.com/gammasoft71/xtd/blob/master/src/xtd.tunit) library.

## xtd themes

A control can have several style modes ([xtd::forms::flat_style](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#ga7cc15a089c6b538cb469caa2e9aba1a1)):
  * [xtd::forms::flat_style::system](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#ga7cc15a089c6b538cb469caa2e9aba1a1) : The control is native and therefore cannot adapt to the theme defined in the application ([xtd::forms::application::style_sheet](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a1f6e9deecce51a698af2bab30d31f600))).
  * [xtd::forms::flat_style::standard](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#ga7cc15a089c6b538cb469caa2e9aba1a1) : The control will adapt to the theme defined in the application ([xtd::forms::application::style_sheet](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a1f6e9deecce51a698af2bab30d31f600))) with the standard style.
  * [xtd::forms::flat_style::flat](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#ga7cc15a089c6b538cb469caa2e9aba1a1) : The control will adapt to the theme defined in the application ([xtd::forms::application::style_sheet](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a1f6e9deecce51a698af2bab30d31f600))) but with the flat style.
  * [xtd::forms::flat_style::popup](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#ga7cc15a089c6b538cb469caa2e9aba1a1) : The control will adapt to the theme defined in the application ([xtd::forms::application::style_sheet](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a1f6e9deecce51a698af2bab30d31f600))) but with the popup style.
  
### Current Operating System / Desktop Environment

* [gnome_dark](https://github.com/gammasoft71/xtd/blob/master/themes/gnome_dark) contains GNOME dark theme.
* [gnome_light](https://github.com/gammasoft71/xtd/blob/master/themes/gnome_light) contains GNOME dark theme.
* [kde_dark](https://github.com/gammasoft71/xtd/blob/master/themes/kde_dark) contains KDE dark theme.
* [kde_light](https://github.com/gammasoft71/xtd/blob/master/themes/kde_light) contains KDE dark theme.
* [macos_dark](https://github.com/gammasoft71/xtd/blob/master/themes/macos_dark) contains macOS dark theme.
* [macos_light](https://github.com/gammasoft71/xtd/blob/master/themes/macos_dark) contains macOS light theme.
* [windows_dark](https://github.com/gammasoft71/xtd/blob/master/themes/windows_dark) contains Windows dark theme.
* [windows_light](https://github.com/gammasoft71/xtd/blob/master/themes/windows_light) contains Windows light theme.

### Generic

* [symbolic_dark](https://github.com/gammasoft71/xtd/blob/master/themes/symbolic_dark) contains Symbolic dark theme.
* [symbolic_light](https://github.com/gammasoft71/xtd/blob/master/themes/symbolic_light) contains Symbolic light theme.
* [xtd_dark](https://github.com/gammasoft71/xtd/blob/master/themes/xtd_dark) contains xtd dark theme.
* [xtd_light](https://github.com/gammasoft71/xtd/blob/master/themes/xtd_light) contains xtd light theme.

### Colors only

* [black](https://github.com/gammasoft71/xtd/blob/master/themes/black) contains black color theme.
* [blue](https://github.com/gammasoft71/xtd/blob/master/themes/blue) contains blue color theme.
* [dark](https://github.com/gammasoft71/xtd/blob/master/themes/dark) contains dark color theme.
* [green](https://github.com/gammasoft71/xtd/blob/master/themes/green) contains green color theme.
* [light](https://github.com/gammasoft71/xtd/blob/master/themes/light) contains light color theme.
* [red](https://github.com/gammasoft71/xtd/blob/master/themes/red) contains red color theme.
* [white](https://github.com/gammasoft71/xtd/blob/master/themes/white) contains white color theme.

### Owner themes

In the future, developers will be able to create their own themes.

## Build

### CMake

xtd uses [CMake](https://cmake.org) as build script generator.

Commands to generate xtd build project.

* On Windows :
```shell
cd xtd
mkdir build
cd build
cmake ..
start xtd.sln
```

* On macOS :
```shell
cd xtd
mkdir build && cd build
cmake .. -G "Xcode"
open xtd.xcoddeproj
```

* On Linux :
```shell
cd xtd
mkdir build && cd build
cmake ..
cmake all
```

#### Notes for Windows developer

When you use the install of xtd, you are in admin mode to be able to install it in the folder "C:\Program Files\xtd".

When you are in Visual, you are in user mode and you cannot write in the folder "C:\Program Files\xtd".

CMake generates the xtd project and adds different targets like :

- xtd.core lib
- xtd.drawing.lib
- ...

It also generates special targets like:
 - Install : which is the install of the projects
 - RUN_TEST : which executes the unit tests
 - ...

It is thus necessary to modify the rights of permission of "C:\Program Files\xtd" so that the user can install the project.

### Specific CMake commands

xtd adds a set of [specific CMake commands](https://github.com/gammasoft71/xtd/blob/master/scripts/cmake/xtd_commands.cmake) for simplifying CMakeLists.txt.

You can see the reference guide for documentation.

### xtd build CMake options for xtd developers

Use the default options except for the following:

* XTD_BUILD_TESTS_XTD_CORE=ON
* XTD_BUILD_TESTS_XTD_DRAWING=ON
* XTD_BUILD_TESTS_XTD_FORMS=ON
* XTD_BUILD_TESTS_XTD_TUNIT=ON

These options respectively enable unit tests for each xtd library.

Simply add "-DXTD_BUILD_TESTS_XTD_CORE=ON -DXTD_BUILD_TESTS_XTD_DRAWING=ON -DXTD_BUILD_TESTS_XTD_FORMS=ON -DXTD_BUILD_TESTS_XTD_TUNIT=ON" to the cmake command line.
Or enable options in CMake-gui.

## xtd guidelines

* See [Designe Guidelines](https://github.com/gammasoft71/xtd/blob/master/docs/design_guidelines.md) (for coding conventions, naming, type, ...)

### Notes

* Don't forget to replace the tab with 2 spaces in your IDE.

## Unit tests

* For each development add unit tests. See unit tests for each xtd library.
* Unit tests must be simple and fast.
* In general, each method must be validated (e.g. limits, exceptions, ...).
* xtd.tunit is use for all libraries except xtd.tunit wish has its has own test units.

#### Notes

* Currently, there are +/- 11000 unit tests executed successfullly and 0 failed.
* There are many missing. But the goal is to complete them as much as possible to have a complete coverage.

## Continuous integration builds

* [Appveyor](https://ci.appveyor.com/project/gammasoft71/xtd) for Windows 32 and d64 bits.
* [Travis-CI](https://travis-ci.com/gammasoft71/xtd) for macOS.
* [CircleCI](https://circleci.com/gh/gammasoft71/xtd) for Linux.

## Test coverage

* Not present for the moment. But planned in the future with [Codecov](https://about.codecov.io)

## xtd documentation

* xtd is documented with [doxygen](https://www.doxygen.nl/index.html), see tags and commands.
* The documentation is only present in the .h file. (Some IDEs use these documentations to help you develop).
* Most of the documentation is based on [MSDN](https://docs.microsoft.com/en-us/dotnet/api/?view=windowsdesktop-5.0) and adapted to xtd and C++.

There are two guides:
* Reference Guide : [On line](https://gammasoft71.github.io/xtd/reference_guides/latest/index.html) and offline [documentation](https://github.com/gammasoft71/xtd/blob/master/docs/doxygen/doxygen.txt). This guide contains high level documentation.
* Developer Guide : Only offline [documentation](https://github.com/gammasoft71/xtd/blob/master/docs/doxygen/doxygen_developer.txt). This guide contains high and low level documentation.

### Notes

For the offline documentation use doxygen command or doxygen gui.
