| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Download the latest stable xtd version

You can download latest stable version on [SourceForge](https://sourceforge.net/projects/xtdpro/).

[![Downloadxtd](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/xtdpro/files/latest/download)

# Clone the latest xtd commit

Or clone latest development version on [GitHub](https://github.com/gammasoft71/xtd).

```shell
git clone https://github.com/gammasoft71/xtd.git
```

# Libraries dependency

xtd is currently in development mode and the only [xtd.forms.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/README.md) backend is supported.

**wxWidgets 3.1.5 will be automatically installed with xtd.**

In the future xtd.forms will use [xtd.forms.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.win32/README.md) on Windows, [xtd.forms.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.cocoa/README.md) on macOS and [xtd.forms.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.gtk4/README.md) on linux. Other backend like [xtd.forms.native.qt5](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.qt5/README.md) will be ported too.

# Installation

## Windows 10 or later

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


## macOS 10.15 (OS X Catalina) or later

1. Install Xcode 11.6 or later
  
   In order to build xtd, you first need download and install Xcode from App Store and install "Commands line tools".

   *Remarks: Verify if you can execute 'clang --version' in "Terminal".*

2. Install Homebrew
  
   After Xcode, to build xtd, you need to install package manager [Homebrew](https://brew.sh)).
   
```shell
/usr/bin/ruby -e "$(curl -fsSL ttps://raw.githubusercontent.com/Homebrew/install/master/install)"
```

3. After installing Xcode and Homebrew, do the following in "Terminal" to Build and install :

```shell
cd xtd_path_name
./install
```

4. Create as many applications as you want with xtd.

## CentOS 7, Debian 9.7, Elementary OS 5.0, Fedora 29, LinuxMint 19.1, RedHat 7.5 and Ubuntu 19.04 (or later)

1. Do the following in "Terminal" to Build and install :

```shell
cd xtd_path_name
./install
```

2. Create as many applications as you want with xtd.


## Other linux Distribution

1. Install g++ 9 or later
  
   In order to build , you first need download and install g++ 9 or later.

   *Remarks: Verify if you can execute 'g++ --version' in "Terminal".*

2. Install gsound
  
   After g++, you need to install the [gsound](https://wiki.gnome.org/Projects/GSound).

3. Install gtk3
  
   After gsound, you need to install the [gtk3](https://www.gtk.org).

4. Install CMake 3.3 or later
  
   After g++ and gtk3, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/).

   *Remarks: Verify if you can execute 'cmake --version' in "Terminal", if it's no, add cmake install directory to your path.*

5. After installing g++, gtk3 and CMake, do the following in "Terminal" to Build and install :

```shell
cd xtd_path_name
./install
```

4. Create as many applications as you want with xtd.

# Build and run your first xtd application

Use internal tools installed with xtd.

## xtdc-gui (gui)

Let the gui tool drive you for create your new project.

* First step choose "Create a new project" button.
* Choose your project template then click to "Next" button
* Choose the name for your new project and the path where the project will be create, and finaly click "Create button" to create it.

![xtdc-gui](pictures/xtdc-gui.gif)

## xtdc (console)

Create your new project with a simple command line tools.

For example, you can type :

```bash
xtdc new gui hello_world
cd hello_world
xtdc open
```
"xtdc" command line tool will creating hello_world gui application, generate Visual Studio sultion if you running it on Windows, Xcode project if you are on macOS or Code::Blocks project if you are on Linux. If you are on Windows, Visual Studio will running with your new project. If you are on macOS, Xcode will running with your new project. If you are on Linux, Code::Blocks will running with your project.

## Remarks

See [xtdc-gui](../tools/xtdc-gui/README.md) for more info.

See [xtdc](../tools/xtdc/README.md) for more info.

______________________________________________________________________________________________

© 2021 Gammasoft.
