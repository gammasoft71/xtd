# Portability

The Portability section provides information about supported Operating Systems, compilers, and development environment tools.

## C++20

xtd 0.2.0 and later requires **C++20 or above**.

As of 2020, C++20 is the name for the most recent major revision of the [ISO/IEC 14882](https://en.wikipedia.org/wiki/ISO/IEC_14882) standard for the [C++](https://en.wikipedia.org/wiki/C%2B%2B) programming language.

For more information see [wikipedia](https://en.wikipedia.org/wiki/C%2B%2B20) and [cppreference](https://en.cppreference.com/w/cpp/20).

## Libraries dependency

xtd is currently in development mode and the only [xtd.forms.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/README.md) backend is supported.

wxWidgets 3.2.2.1 will be automatically installed with xtd.

In the future, xtd.forms will use [xtd.forms.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.win32/README.md) on Windows, [xtd.forms.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.cocoa/README.md) on macOS, and [xtd.forms.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.gtk4/README.md) on Linux. Other backends like [xtd.forms.native.qt5](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.qt5/README.md) may be ported too.

## Operating System Supported

xtd currently runs on Windows, macOS, Linux, iOS, and Android operating systems.

### Windows

[![Windows](/pictures/os/Windows.png)](https://microsoft.com/windows)

xtd is supported on Windows 10 or later, where Win32 APIs are used for native integration.

### macOS

[![macOS](/pictures/os/macOS.png)](https://apple.com/macos/)

### Linux

#### CentOS

[![CentOS](/pictures/os/CentOS.png)](https://centos.org)

#### Debian

[![Debian](/pictures/os/Debian.png)](https://debian.org)

#### Elementary

[![Elementary OS](/pictures/os/ElementaryOS.png)](https://elementary.io)

#### Fedora

[![Fedora](/pictures/os/Fedora.png)](https://getfedora.org)

#### LinuxMint

[![LinuxMint](/pictures/os/LinuxMint.png)](https://linuxmint.com)

#### Redhat

[![Redhat](/pictures/os/Redhat.png)](https://redhat.com)

#### Ubuntu

[![Ubuntu](/pictures/os/Ubuntu.png)](https://ubuntu.com)

#### Other distribution [manual installation]

[![Linux](/pictures/os/Linux.png)](https://linux.org)

### Unix - 32 and 64 bits

#### FreeBSD 13 or later

[![FreeBSD](/pictures/os/FreeBSD.png)](https://freebsd.org)

#### Haiku R1/beta5 or later

[![Haiku](/pictures/os/Haiku.png)](https://haiku-os.org)

#### SerenityOS

[![SerenityOS](/pictures/os/SerenityOS.png)](https://serenityos.org)

### iOS 64 bits [manual installation]

[![iOS](/pictures/os/iOS.png)](https://apple.com/ios)

### Android 64 bits [manual installation]

[![android](/pictures/os/Android.png)](https://android.com)

### Note
> ⚠️ **Note**  
> While xtd can be built and run on iOS and Android, full graphical support (`xtd.forms`) is currently not available on these platforms.

## The xtd libraries portability list

| OS / Library                             | [xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html) | [xtd.drawing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html) | [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) | [xtd.tunit](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html) |
| ---------------------------------------- | ------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| [Android](https://android.com)           | ✔️                                                                                           | ❌                                                                                                 | ❌                                                                                             | ✔️                                                                                             |
| [FreeBSD](https://freebsd.org)           | ✔️                                                                                           | ✔️                                                                                                 | ✔️                                                                                             | ✔️                                                                                             |
| [Haiku](https://haiku-os.org)            | ✔️                                                                                           | ❌                                                                                                 | ❌                                                                                             | ✔️                                                                                             |
| [iOS](https://apple.com/ios)             | ✔️                                                                                           | ❌                                                                                                 | ❌                                                                                             | ✔️                                                                                             |
| [Linux](https://linux.org)               | ✔️                                                                                           | ✔️                                                                                                 | ✔️                                                                                             | ✔️                                                                                             |
| [macOS](https://apple.com/macos/)        | ✔️                                                                                           | ✔️                                                                                                 | ✔️                                                                                             | ✔️                                                                                             |
| [SerenityOS](https://serenityos.org)     | ✔️                                                                                           | ❌                                                                                                 | ❌                                                                                             | ✔️                                                                                             |
| [Windows](https://microsoft.com/windows) | ✔️                                                                                           | ✔️                                                                                                 | ✔️                                                                                             | ✔️                                                                                             |

## Tests and coverage

xtd is continuously tested with CI tools.

### GitHub Actions

[![GitHubActions](/pictures/ci/GitHubActions.png)](https://github.com/gammasoft71/xtd/actions)

Configurations:

* **Windows**: Visual Studio 2022 (Win32 and Win64)
* **macOS**: Xcode 15.0
* **Linux**: GCC 11 and Clang 14

### Codecov

[![Codecov](/pictures/ci/Codecov.png)](https://codecov.io)

Test coverage reports are automatically uploaded to Codecov after each build.

## Development Environment Tools

With CMake, xtd supports many development environment tools.

### Microsoft Visual Studio

[![VisualStudio](/pictures/dev_tools/VisualStudio.png)](https://visualstudio.com)

### Xcode 14.2 or later

[![Xcode](/pictures/dev_tools/Xcode.png)](https://developer.apple.com/xcode)

### Microsoft Visual Studio Code

[![VisualStudioCode](/pictures/dev_tools/VisualStudioCode.png)](https://visualstudio.com)

### CLion

[![CLion](/pictures/dev_tools/CLion.png)](https://jetbrains.com/clion)

### Eclipse CDT

[![EclipseCDT](/pictures/dev_tools/EclipseCDT.png)](https://eclipse.org/cdt)

### Code::Blocks

[![CodeBlocks](/pictures/dev_tools/CodeBlocks.png)](http://codeblocks.org)

### KDevelop

[![KDevelop](/pictures/dev_tools/KDevelop.png)](https://kdevelop.org)

### CodeLite

[![CodeLite](/pictures/dev_tools/CodeLite.png)](https://codelite.org)

### Qt Creator

[![Qt](/pictures/dev_tools/QtCreator.png)](https://qt.io)

### Standard Unix makefile

[![LinuxMakefile](/pictures/dev_tools/LinuxMakefile.png)](https://www.gnu.org/software/make/)

## Compilers

The compilers listed below are supported with xtd :

* Apple Clang 14.0.0 (Xcode 14.2) or later  
* Clang 14.0.0 or later  
* GCC 11.0 or later  
* Microsoft Visual Studio 2022 (MSVC 14.30) or later

## Native

xtd has a thin layer by library if needed to abstract operating system. This layer is called naturally **native**.

To add support for a new operating system, you simply need to implement the corresponding native API for that target.

### Native API by library

* [xtd.core](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core.native)
* [xtd.drawing](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native)
* [xtd.forms](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native)

## See also

* [Documentation](/docs/documentation)
