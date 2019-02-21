| [Home](home.md) | [Downloads](downloads.md) | [Examples](examples.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd.tunit) | [Project](https://sourceforge.net/projects/tunitpro/) | [Contact](contact.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |

# Download the latest stable xtd.tunit version

You can download latest stable version on [SourceForge](https://sourceforge.net/projects/tunithpro)

[![Downloadxtd.tunit](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/tunitpro/files/latest/download)

# Clone the latest xtd.tunit commit

Or clone latest development version on [GitHub](https://github.com/gammasoft71/xtd.tunit).

```shell
git clone https://github.com/gammasoft71/xtd.tunit .
```

# Installation

## Windows 7 SP1 or later

1. Install Microsoft Visual Studio 2017 Community
   
   In order to build xtd.tunit, you first need download and install Microsoft Visual Studio 2017 community from [https://www.visualstudio.com](https://www.visualstudio.com).

2. Install CMake 3.3 or later
   
   After Microsoft Visual Studio, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/)
   
   *Remarks: Verify if you can execute 'cmake --version' in "Command Prompt", if it's no, add cmake install directory to your path.*

3. After installing Microsoft Visual Studio and CMake, do the following in "Command Prompt" to build and install xtd.tunit :

```shell
cd C:\Users\YourName\xtd.tunit\
install.cmd
```

4. Create as many unit tests as you want with xtd.tunit.


## macOS 10.14 (OS X Mojave) or later

1. Install Xcode 10 or later
   
   In order to build xtd.tunit, you first need download and install Xcode from App Store and install "Commands line tools".

   *Remarks: Verify if you can execute 'clang --version' in "Terminal".*

2. Install CMake 3.3 or later
   
   After Microsoft Visual Studio, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/)

   *Remarks: Verify if you can execute 'cmake --version' in "Terminal", if it's no, add cmake install directory to your path.*

3. After installing Xcode and CMake, do the following in "Terminal" to Build and install :

```shell
cd /Users/YourName/YourProject/
./install.sh
```

4. Create as many unit tests as you want with xtd.tunit.

## Linux

1. Install g++ 7 or later
   
   In order to build , you first need download and install g++ 7 or later.

   *Remarks: Verify if you can execute 'g++ --version' in "Terminal".*

2. Install CMake 3.3 or later
   
   After Microsoft Visual Studio, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/)

   *Remarks: Verify if you can execute 'cmake --version' in "Terminal", if it's no, add cmake install directory to your path.*

3. After installing g++ and CMake, do the following in "Terminal" to Build and install :

```shell
cd /home/YourName/YourProject
./install.sh
```

4. Create as many unit tests as you want with xtd.tunit.

______________________________________________________________________________________________

© 2019 Gammasoft.
