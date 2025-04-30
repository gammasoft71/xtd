---
sidebar_position: 10
---

# Portability

The Portability section provide informations about Operating System supported, Compilers and Development Environment tools.

## C++17

xtd support C++17 or above.

As of 2018, C++17 is the name for the most recent revision of the [ISO/IEC 14882](https://en.wikipedia.org/wiki/ISO/IEC_14882) standard for the [C++](https://en.wikipedia.org/wiki/C%2B%2B) programming language.

For more information see [wikipedia](https://en.wikipedia.org/wiki/C%2B%2B17) and [cppreference](https://en.cppreference.com/).

## Libraries dependency

xtd is currently in development mode and the only [xtd.forms.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/README.md) backend is supported.

wxWidgets 3.2.2.1 will be automatically installed with xtd.

In the future xtd.forms will use [xtd.forms.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.win32/README.md) on Windows, [xtd.forms.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.cocoa/README.md) on macOS and [xtd.forms.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.gtk4/README.md) on linux. Other backend like [xtd.forms.native.qt5](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.qt5/README.md) will be ported too.

## Operating System Supported

Actually xtd run on Windows, macOS, Linux, iOS and Android Operating System.

### Windows 10 - 32 and 64 bits or later

[![Windows](/pictures/os/Windows.png)](https://microsoft.com/windows)

### macOS 10.15 (OS X Catalina) - 64 bits or later

[![macOS](/pictures/os/macOS.png)](https://apple.com/macos/)

### Linux - 32 and 64 bits

#### CentOS 7 or later

[![CentOS](/pictures/os/CentOS.png)](https://centos.org)

#### Debian 9.2.1 or later

[![Debian](/pictures/os/Debian.png)](https://debian.org)

#### Elementary OS 0.4 or later

[![Elementary OS](/pictures/os/ElementaryOS.png)](https://elementary.io)

#### Fedora 26 or later

[![Fedora](/pictures/os/Fedora.png)](https://getfedora.org)

#### LinuxMint 18.2 or later

[![LinuxMint](/pictures/os/LinuxMint.png)](https://linuxmint.com)

#### Redhat 7.4 or later

[![Redhat](/pictures/os/Redhat.png)](https://redhat.com)

#### Ubuntu 18.04 or later

[![Ubuntu](/pictures/os/Ubuntu.png)](https://ubuntu.com)

#### Other distribution [manual installation]

[![Linux](/pictures/os/Linux.png)](https://linux.org)

### Unix - 32 and 64 bits

#### FreeBSD 13 or later

[![FreeBSD](/pictures/os/FreeBSD.png)](https://freebsd.org)

#### Haiku R1/beta5 or later

[![Haiku](/pictures/os/Haiku.png)](https://haiku-os.org)

### iOS 14 - 64 bits or later [manual installation]

[![iOS](/pictures/os/iOS.png)](https://apple.com/ios)

### android 10 64 bits or later [manual installation]

[![android](/pictures/os/Android.png)](https://android.com)

## The xtd libraries portability list

| OS / Library                             | [xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html) | [xtd.drawing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html) | [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) | [xtd.tunit](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html) |
| ---------------------------------------- | ------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| [Windows](https://microsoft.com/windows) | ✔️                                                                                           | ✔️                                                                                                 | ✔️                                                                                             | ✔️                                                                                             |
| [macOS](https://apple.com/macos/)        | ✔️                                                                                           | ✔️                                                                                                 | ✔️                                                                                             | ✔️                                                                                             |
| [Linux](https://linux.org)               | ✔️                                                                                           | ✔️                                                                                                 | ✔️                                                                                             | ✔️                                                                                             |
| [FreeBSD](https://freebsd.org)           | ✔️                                                                                           | ✔️                                                                                                 | ✔️                                                                                             | ✔️                                                                                             |
| [Haiku](https://haiku-os.org)            | ✔️                                                                                           | ❌                                                                                                 | ❌                                                                                             | ✔️                                                                                             |
| [iOS](https://apple.com/ios)             | ✔️                                                                                           | ❌                                                                                                 | ❌                                                                                             | ✔️                                                                                             |
| [android](https://android.com)           | ✔️                                                                                           | ❌                                                                                                 | ❌                                                                                             | ✔️                                                                                             |

## Tests and coverage

xtd is every time tested with Continuous Integration tools.

### AppVeyor

[![AppVeyor](/pictures/ci/AppVeyor.png)](https://ci.appveyor.com)

Configurations :

* Visual Studio 2019 Win32
* Visual Studio 2019 Win64

### Travis CI

[![TravisCI](/pictures/ci/TravisCI.png)](https://travis-ci.com)

Configurations :

* macOS Xcode 11.6
* linux g++ 9

### Codecov

[![Codecov](/pictures/ci/Codecov.png)](https://codecov.io)

## Development Environment Tools

With CMake, xtd support many Development Environment Tools.

### Microsoft Visual Studio 2019 or later

[![VisualStudio](/pictures/dev_tools/VisualStudio.png)](https://visualstudio.com)

### Xcode 11.6 or later

[![Xcode](/pictures/dev_tools/Xcode.png)](https://developer.apple.com/xcode)

### Microsoft Visual Studio Code

[![VisualStudioCode](/pictures/dev_tools/VisualStudioCode.png)](https://visualstudio.com)

### CLion 2017.2 or later

[![CLion](/pictures/dev_tools/CLion.png)](https://jetbrains.com/clion)

### Eclipse CDT 8.0 or later

[![EclipseCDT](/pictures/dev_tools/EclipseCDT.png)](https://eclipse.org/cdt)

### Code::Blocks 13.12 or later

[![CodeBlocks](/pictures/dev_tools/CodeBlocks.png)](http://codeblocks.org)

### KDevelop 3 or later

[![KDevelop](/pictures/dev_tools/KDevelop.png)](https://kdevelop.org)

### CodeLite 11 or later

[![CodeLite](/pictures/dev_tools/CodeLite.png)](https://codelite.org)

### Qt Creator

[![Qt](/pictures/dev_tools/QtCreator.png)](https://qt.io)

### Standard Unix makefile

[![LinuxMakefile](/pictures/dev_tools/LinuxMakefile.png)](https://www.gnu.org/software/make/)

## Compilers

The compilers listed below are supported with xtd :

* Xcode 11.6 - Apple clang version 11.0.3 or later
* clang 10 or later
* GCC 10 or later
* Visual Studio 2019 RTW 16.0 or later

## Native

xtd has a thin layer by library if needed to abstract operating system. This layer is called naturally **native**.

For add a new Operating System, you juste have to implement native api for the new target Operating System.

### Native API by library

* [xtd.core](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core.native)
* [xtd.drawing](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native)
* [xtd.forms](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native)

## See also

* [Documentation](/docs/documentation)
