| [Home](home.md) | [Downloads](downloads.md) | [Examples](examples.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd_forms) | [Project](https://sourceforge.net/projects/tunitpro/) | [Contact](contact.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |

# Note

xtd.forms is under development.
For now, the following procedure is the only way to download and install:
 
1. Install wxWidgets backend :
  
   The only [xtd.form.native.wxwidgets](../src/xtd_forms_native_wxwidgets/README.md) backend is supported now.
   See [wxWidgets downloads](https://www.wxwidgets.org/downloads/) to install [wxWidgets](https://www.wxwidgets.org/)  on your system.

2. Clone github repository :

   ```shell
   git clone https://github.com/gammasoft71/xtd_forms.git
   ```

3. Update submodule :

   ```shell
   git submodule update
   ```

4. Generate cmake project (See [cmake](https://www.cmake.com) to generate your project)

  * On Windows:
    ```shell
    mkdir build
    cd build
    cmake -G "Visual Studio 16 2019" ..
    ```

  * On linux:
    ```shell
    mkdir build
    cd build
    cmake -G "Unix Makefiles" ..
    ```

  * On macOS:
    ```shell
    mkdir build
    cd build
    cmake -G "Xcode" ..
    ```

5. build source and install it with your favorite ide (on windows you must launch visual studio as administrator to install xtd.form) or with command line :
  
  * On Windows
    ```
    cmake --build . --config Debug --target install
    ```
  
  * On linux and macos
    ```
    cmake --build . --target install -- -j 8
    ```

6. See [examples](https://github.com/gammasoft71/xtd_forms/blob/master/examples/README.md), [documentation](https://github.com/gammasoft71/xtd_forms/blob/master/docs/home.md) and [Reference guide](https://codedocs.xyz/gammasoft71/xtd.forms/).
    

# Download the latest stable xtd.forms version

You can download latest stable version on [SourceForge](https://sourceforge.net/projects/formspro/)

[![Downloadxtd.forms](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/formspro/files/latest/download)

# Clone the latest xtd.forms commit

Or clone latest development version on [GitHub](https://github.com/gammasoft71/xtd.forms).

```shell
git clone https://github.com/gammasoft71/xtd_forms.git
```

# Libraries dependency

xtd.forms is currently in development mode and the only [xtd.form.native.wxwidgets](../src/xtd_forms_native_wxwidgets/README.md) backend is supported.
See [wxWidgets downloads](https://www.wxwidgets.org/downloads/) to install [wxWidgets](https://www.wxwidgets.org/)  on your system.

In the future xtd.forms will use [xtd.form.native.win32](../xtd.forms.native.win32/README.md) on Windows, [xtd.form.native.cocoa](../src/xtd_forms_native_cocoa/README.md) on macOS and [xtd.form.native.gtk3](../src/xtd_forms_native_gtk3/README.md) on linux. Other backend like [xtd.form.native.qt5](../src/xtd_forms_native_qt5/README.md) will be ported too.

# Installation

## Windows 7 SP1 or later

1. Install Microsoft Visual Studio 2017 Community
  
   In order to build xtd.forms, you first need download and install Microsoft Visual Studio 2017 community from [https://www.visualstudio.com](https://www.visualstudio.com).

2. Install CMake 3.3 or later
  
   After Microsoft Visual Studio, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/)
   
   *Remarks: Verify if you can execute 'cmake --version' in "Command Prompt", if it's no, add cmake install directory to your path.*

3. After installing Microsoft Visual Studio and CMake, do the following in "Command Prompt" to build and install xtd.forms :

```shell
cd C:\Users\YourName\xtd.forms\
install.cmd
```

4. Create as many unit tests as you want with xtd.forms.


## macOS 10.14 (OS X Mojave) or later

1. Install Xcode 10 or later
  
   In order to build xtd.forms, you first need download and install Xcode from App Store and install "Commands line tools".

   *Remarks: Verify if you can execute 'clang --version' in "Terminal".*

2. Install Homebrew
  
   After Xcode, to build Switch, you need to install package manager Homebrew ([http://brew.sh](http://brew.sh)).
   
```shell
/usr/bin/ruby -e "$(curl -fsSL ttps://raw.githubusercontent.com/Homebrew/install/master/install)"
```

3. After installing Xcode and Homebrew, do the following in "Terminal" to Build and install :

```shell
cd /Users/YourName/YourProject/
./install.sh
```

4. Create as many unit tests as you want with xtd.forms.

## CentOS 7, Debian 9.7, Elementary OS 5.0, Fedora 29, LinuxMint 19.1, RedHat 7.5 and Ubuntu 18.04 (or later)

1. Do the following in "Terminal" to Build and install :

```shell
cd /home/YourName/YourProject
./install.sh
```

2. Create as many unit tests as you want with xtd.forms.


## Other linux Distribution

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

4. Create as many applications as you want with xtd.forms.

______________________________________________________________________________________________

© 2019 Gammasoft.
