| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Download

## In this section

* [Download the latest stable xtd version](#download-the-latest-stable-xtd-version)
* [Clone the latest xtd commit](#clone-the-latest-xtd-commit)
* [Libraries dependency](#libraries-dependency)
* [Installation](#installation)
  * [Windows 10 or later](#windows-10-or-later)
  * [macOS 10.15 or later](#macos-10%2E15-or-later)
  * [Linux distribution fully supported by xtd install](#Linux-distribution-fully-supported-by-xtd-install)
  * [Other linux distribution](#other-linux-distribution)
* [Build and run your first xtd application](#build-and-run-your-first-xtd-application)
  * [xtdc-gui (gui)](#xtdc-gui-gui)
  * [xtdc (console)](#xtdc-console)
  * [Remarks](#remarks)
* [Uninstall](#uninstall)
  * [Windows](#windows)
  * [macOS or linux](#macos-or-linux)
* [Download logo](#download-logo)
  * [xtd](#xtd)
  * [Gammasoft](#gammasoft)

## Download the latest stable xtd version

You can download latest stable version on [SourceForge](https://sourceforge.net/projects/xtdpro/).

[![Downloadxtd](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/xtdpro/files/latest/download)

See [release notes](release_notes.md) to know the latest xtd version.

## Clone the latest xtd commit

Or clone latest development version on [GitHub](https://github.com/gammasoft71/xtd).

```shell
git clone https://github.com/gammasoft71/xtd.git
```

## Libraries dependency

xtd is currently in development mode and the only [xtd.forms.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/README.md) backend is supported.

**wxWidgets 3.1.5 will be automatically installed with xtd.**

In the future xtd.forms will use [xtd.forms.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.win32/README.md) on Windows, [xtd.forms.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.cocoa/README.md) on macOS and [xtd.forms.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.gtk4/README.md) on linux. Other backend like [xtd.forms.native.qt5](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.qt5/README.md) will be ported too.

## Installation

### Windows 10 or later

1. Install Microsoft Visual Studio 2019 Community or later
  
   In order to build xtd, you first need download and install Microsoft Visual Studio 2019 community from [https://www.visualstudio.com](https://www.visualstudio.com).

2. Install CMake 3.3 or later
  
   After Microsoft Visual Studio, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/)
   
   *Remarks: Verify if you can execute 'cmake --version' in "Command Prompt", if it's no, add cmake install directory to your path.*

3. After installing Microsoft Visual Studio and CMake, do the following in "Command Prompt" to build and install xtd :

```shell
cd xtd_path_name
install
```

4. Create as many applications as you want with xtd.

### macOS 10.15 or later

1. Install Xcode 11.6 or later
  
   In order to build xtd, you first need download and install Xcode from App Store and install "Commands line tools".

   *Remarks: Verify if you can execute 'clang --version' in "Terminal".*

2. Install Homebrew
  
   After Xcode, to build xtd, you need to install package manager [Homebrew](https://brew.sh).
   
```shell
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```

3. After installing Xcode and Homebrew, do the following in "Terminal" to Build and install xtd :

```shell
cd xtd_path_name
./install
```

4. Create as many applications as you want with xtd.

### Linux distribution fully supported by xtd install 

The following list contains the Linux distributions fully supported by the xtd installation:
* [CentOS 7 or later](https://www.centos.org/);
* [Debian 9.7 or later](https://www.debian.org/);
* [Elementary OS 5.0 or later](https://elementary.io/);
* [Fedora 29 or later](https://getfedora.org/);
* [LinuxMint 19.1 or later](https://www.linuxmint.com/);
* [openSUSE Tumbleweed](https://get.opensuse.org/tumbleweed/);
* [RedHat 7.5 or later](https://www.redhat.com/);
* [Rocky 9 or later](https://rockylinux.org/);
* [Ubuntu 19.04 or later](https://ubuntu.com/);

1. Do the following in "Terminal" to Build and install xtd :

```shell
cd xtd_path_name
./install
```

*Remarks : Do not launch ./install with sudo or as su.* 

2. Create as many applications as you want with xtd.

### Other linux distribution

1. Install g++ 9 or later
  
   In order to build , you first need download and install g++ 9 or later.

   *Remarks: Verify if you can execute 'g++ --version' in "Terminal".*

2. Install gsound
  
   After g++, you need to install the [gsound](https://wiki.gnome.org/Projects/GSound).

3. Install gtk3
  
   After gsound, you need to install the [gtk3](https://www.gtk.org).

4. Install CMake 3.3 or later
  
   After g++, gsound and gtk3, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/).

   *Remarks: Verify if you can execute 'cmake --version' in "Terminal", if it's no, add cmake install directory to your path.*

5. After installing g++, gsound, gtk3 and CMake, do the following in "Terminal" to Build and install xtd :

```shell
cd xtd_path_name
./install
```

*Remarks : Do not launch ./install with sudo or as su.* 

4. Create as many applications as you want with xtd.

## Build and run your first xtd application

Use internal tools installed with xtd.

### xtdc-gui (gui)

Let the gui tool drive you for create your new project.

* First step choose "Create a new project" button.
* Choose your project template then click to "Next" button
* Choose the name for your new project and the path where the project will be create, and finally click "Create button" to create it.

![xtdc-gui](pictures/xtdc-gui.gif)

### xtdc (console)

Create your new project with a simple command line tools.

For example, you can type :

```shell
xtdc new gui hello_world
cd hello_world
xtdc open
```
"xtdc" command line tool for creating hello_world gui application, generate Visual Studio solution if you running it on Windows, Xcode project if you are on macOS or Code::Blocks project if you are on Linux. If you are on Windows, Visual Studio will be running with your new project. If you are on macOS, Xcode will be running with your new project. If you are on Linux, Code::Blocks will be running with your project.

### Remarks

See [xtdc-gui](../tools/xtdc-gui/README.md) for more info.

See [xtdc](../tools/xtdc/README.md) for more info.

## Uninstall

Since the version 0.2.0 you can easily uninstall xtd with one command.

### Windows

* Do the following in "Command Prompt" to uninstall xtd :

```shell
cd xtd_path_name
uninstall
```

### macOS or linux

* Do the following in "Terminal" to uninstall xtd :

```shell
cd xtd_path_name
./uninstall
```

## Download logo

### xtd

[xtd](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo/xtd.logo.png)

[xtd.core](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo/xtd.core.logo.png)

[xtd.drawing](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo/xtd.drawing.logo.png)

[xtd.forms](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo/xtd.forms.logo.png)

[xtd.tunit](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo/xtd.tunit.logo.png)

### gammasoft

[gammasoft](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo/gammasoft.logo.png)

______________________________________________________________________________________________

© 2024 Gammasoft.
