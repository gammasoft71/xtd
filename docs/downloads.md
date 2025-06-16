---
sidebar_position: 4
---

# Download, install and uninstall

## Download the latest stable xtd version

You can download latest stable version on [SourceForge](https://sourceforge.net/projects/xtdpro/).

[![Downloadxtd](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/xtdpro/files/latest/download)

See [release notes](/docs/documentation/release_notes) to know the latest xtd version.

## Clone the latest xtd commit

Or clone latest development version on [GitHub](https://github.com/gammasoft71/xtd).

```shell
git clone https://github.com/gammasoft71/xtd.git
```

## Libraries dependency

xtd is currently in development mode and the only [xtd.forms.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/README.md) backend is supported.

**wxWidgets 3.2.2.1 will be automatically installed with xtd.**

In the future xtd.forms will use [xtd.forms.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.win32/README.md) on Windows, [xtd.forms.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.cocoa/README.md) on macOS and [xtd.forms.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.gtk4/README.md) on linux. Other backend like [xtd.forms.native.qt5](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.qt5/README.md) will be ported too.

## Installation

### Windows

1. Install Microsoft Visual Studio 2022 Community or later
  
   In order to build xtd, you first need download and install Microsoft Visual Studio 2022 community from [https://www.visualstudio.com](https://www.visualstudio.com).

2. Install CMake 3.20 or later
  
   After Microsoft Visual Studio, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/)

   *Remarks: Verify if you can execute 'cmake --version' in "Command Prompt", if it's no, add cmake install directory to your path.*

> :warning: The "Command prompt" must be open in ADMINISTRATOR MODE.

3. After installing Microsoft Visual Studio and CMake, do the following in "Command Prompt" to build and install xtd :

```shell
cd xtd_path_name
install
```

4. Create as many applications as you want with xtd.

### macOS

1. Install Xcode 14.2 or later
  
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

The following list contains the Linux distributions with g++ 11 or later fully supported by the xtd installation:

* [CentOS](https://www.centos.org/);
* [Debian](https://www.debian.org/);
* [Elementary](https://elementary.io/);
* [Fedora](https://getfedora.org/);
* [LinuxMint](https://www.linuxmint.com/);
* [openSUSE Tumbleweed](https://get.opensuse.org/tumbleweed/);
* [RedHat](https://www.redhat.com/);
* [Rocky](https://rockylinux.org/);
* [Ubuntu](https://ubuntu.com/);

1. Do the following in "Terminal" to Build and install xtd :

```shell
cd xtd_path_name
./install
```

*Remarks : Do not launch ./install with sudo or as su.* 

2. Create as many applications as you want with xtd.

### Other linux distribution

1. Install g++ 11 or later
  
   In order to build , you first need download and install g++ 9 or later.

   *Remarks: Verify if you can execute 'g++ --version' in "Terminal".*

2. Install gsound
  
   After g++, you need to install the [gsound](https://wiki.gnome.org/Projects/GSound).

3. Install gtk3
  
   After gsound, you need to install the [gtk3](https://www.gtk.org).

4. Install CMake 3.20 or later
  
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

![xtdc-gui](/pictures/xtdc-gui.gif)

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

See [xtdc-gui](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc-gui/README.md) for more info.

See [xtdc](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc/README.md) for more info.

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
