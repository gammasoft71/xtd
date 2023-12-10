# Preprocessor Symbols

## Table of content

* [Operating Systems](#operating-ystems)
* [Architectures](#architectures)
* [Compilers](#compilers)
* [Standards](#standards)
* [Build types](#build-types)
* [xtd targets](#xtd-targets)
* [xtd paths](#xtd-paths)

First of all, the following definitions of preprocessor symbols (with the exception of [xtd targets](#xtd-targets) and [xtd paths](#xtd-paths)) are not defined by xtd, but are standard definitions.
Normally, you won't need to use these definitions in your programs to use xtd. 
However, you may need to use them for specific purposes outside xtd.

## Operating Systems

The following table represents the different preprocessor symbols for the operating systems supported by xtd:

| Symbols          | OS                                                                      |
| ---------------- | ----------------------------------------------------------------------- |
| `__ANDROID__`    | [Android](https://en.wikipedia.org/wiki/Android_%28operating_system%29) |
| `__APPLE__`      | [macOS](https://en.wikipedia.org/wiki/Mac_OS)                           |
| `__FreeBSD__`    | [FreeBSD](https://fr.wikipedia.org/wiki/FreeBSD)                        |
| `__linux__`      | [Linux](https://en.wikipedia.org/wiki/Linux_kernel)                     |
| `__unix__`       | [Unix](https://en.wikipedia.org/wiki/unix)                              |
| `_POSIX_VERSION` | [Posix](https://en.wikipedia.org/wiki/posix)                            |
| `_WIN32`         | [Windows](https://en.wikipedia.org/wiki/Category:Microsoft_Windows)     |

To detect the different Apple platforms, it is necessary to include the `TargetConditionals.h` file which contains the different target definitions.

For a more complete list of platforms see [Pre-defined Compiler Macros Wiki - Operating systems](https://sourceforge.net/p/predef/wiki/OperatingSystems/).

### Examples

The following code shows how to detect the operating system with the preprocessor symbols:

```cpp
#ifdef HAVE_UNISTD_H // needed for _POSIX_VERSION (see https://www.gnu.org/software/autoconf/manual/autoconf-2.64/html_node/Particular-Headers.html#index-g_t_005fPOSIX_005fVERSION-585)
#  include <unistd.h>
#endif

#if defined(_WIN32)
#  define __platform_name__ "Microsoft Windows"
#elif defined(__APPLE__)
#  include <TargetConditionals.h>
#  if TARGET_OS_WIN32 != 0
#    define __platform_name__ "WIN32 API"
#  elif TARGET_OS_WINDOWS != 0
#    define __platform_name__ "Windows"
#  elif TARGET_OS_UNIX != 0
#    define __platform_name__ "Unix"
#  elif TARGET_OS_LINUX != 0
#    define __platform_name__ "Linux"
#  elif TARGET_OS_MAC != 0
#    if TARGET_OS_OSX != 0
#      define __platform_name__ "macOS"
#    elif TARGET_OS_IPHONE != 0
#      if TARGET_OS_IOS
#        define __platform_name__ "iOS"
#      elif TARGET_OS_TV != 0
#        define __platform_name__ "tvOS"
#      elif TARGET_OS_WATCH != 0
#        define __platform_name__ "watchOS"
#      elif TARGET_OS_BRIDGE != 0
#        define __platform_name__ "Bridge device"
#      elif TARGET_OS_MACCATALYST != 0
#        define __platform_name__ "Catalyst macOS"
#      else
#        error "Unknown iPhone platform"
#      endif
#    elif TARGET_OS_DRIVERKIT != 0
#      define __platform_name__ "macOS, iOS, tvOS, or watchOS"
#    elif TARGET_IPHONE_SIMULATOR != 0
#      define __platform_name__ "iPhone Simulator"
#    else
#      error "Unknown Apple platform"
#    endif
#  else
#    error "Unknown target"
#  endif
#elif defined(__ANDROID__)
#  define __platform_name__ "Android"
#elif defined(__FreeBDSD__)
#  define __platform_name__ "FreeBSD"
#elif defined(__linux__)
#  define __platform_name__ "Linux"
#elif defined(__unix__)
#  define __platform_name__ "Unix"
#elif defined(_POSIX_VERSION)
#  define __platform_name__ "Posix"
#else
#  error "Unknown platform"
#endif

#include <xtd/xtd.core>

using namespace xtd;

int main() {
  console::write_line("platform_name=\"{}\"", __platform_name__);
  console::write_line("platform_name=\"{}\"", environment::os_version().name());
}

// This code produces the following output if under macOS :
//
// platform_name="macOS"
// platform_name="macOS"
```

### Remarks

When using xtd, you do not need to use these preprocessor symbols.

It is better to use [xtd::environment::os_version](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#a7eb460253deb58efb3bfdfbb71904119).

But it can be useful for your own developments.

## Architectures

The following table represents the different preprocessor symbols for the architectures supported by xtd:

| Symbols       | Architectures                                                  |
| ------------- | -------------------------------------------------------------- |
| `__amd64__`   | [AMD64](https://en.wikipedia.org/wiki/Amd64)                   |
| `__arm__`     | [ARM](https://en.wikipedia.org/wiki/ARM_architecture)          |
| `__aarch64__` | [ARM64](https://en.wikipedia.org/wiki/ARM64)                   |
| `__i386__`    | [Intel x86](https://en.wikipedia.org/wiki/X86)                 |
| `__ia64__`    | [Intel Itanium (IA-64)](https://en.wikipedia.org/wiki/Itanium) |

For a more complete list of compiler see [Pre-defined Compiler Macros Wiki - Architectures](https://sourceforge.net/p/predef/wiki/Architectures/).

### Examples

The following code shows how to detect the architecture with the preprocessor symbols:

```cpp
#if defined(__amd64__)
#  define __architecture_name__ "amd64"
#elif defined(__arm__)
#  define __architecture_name__ "arm"
#elif defined(__aarch64__)
#  define __architecture_name__ "arm64"
#elif defined(__i386__)
#  define __architecture_name__ "intel x86"
#elif defined(__ia64__)
#  define __architecture_name__ "intel itanium (IA-64)"
#else
#  error "Unknown compiler"
#endif

#include <xtd/xtd.core>

using namespace xtd;

int main() {
  console::write_line("architecture_name=\"{}\"", __architecture_name__);
  console::write_line("architecture_name=\"{}\"", environment::processor_information().architecture_string());
}

// This code produces the following output if architecture is ARM64:
//
// architecture_name="arm64"
// architecture_name="arm64"
```

### Remarks

When using xtd, you do not need to use these preprocessor symbols.

It is better to use [xtd::environment::processor_information](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#aece4cd0bcb92930816937b8c7b45a7a1).

But it can be useful for your own developments.

## Compilers

The following table represents the different preprocessor symbols for the compilers supported by xtd:

| Symbols     | Compiler                                                            |
| ----------- | ------------------------------------------------------------------- |
| `__clang__` | [Clang](https://en.wikipedia.org/wiki/Clang)                        |
| `__GNUC__`  | [GCC C/C++](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)  |
| `_MSC_VER`  | [Microsoft Visual C++](https://en.wikipedia.org/wiki/Visual_studio) |

For a more complete list of compiler see [Pre-defined Compiler Macros Wiki - Compilers](https://sourceforge.net/p/predef/wiki/Compilers/).

### Examples

The following code shows how to detect the compiler with the preprocessor symbols:

```cpp
#if defined(_MSC_VER)
#  define __comiler_name__ "Microsoft Visual Studio"
#elif defined(__clang__)
#  define __comiler_name__ "clang"
#elif defined(__GNUC__)
#  define __comiler_name__ "gcc"
#else
#  error "Unknown compiler"
#endif

#include <xtd/xtd.core>

using namespace xtd;

int main() {
  console::write_line("compiler_name=\"{}\"", __comiler_name__);
  console::write_line("compiler_name=\"{}\"", environment::compiler_version().name());
}

// This code produces the following output if compiler is Clang:
//
// compiler_name="clang"
// compiler_name="clang"
```

### Remarks

When using xtd, you do not need to use these preprocessor symbols.

It is better to use [xtd::environment::compiler_version](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#a86156ba949fd043f918a879faed73d86).

But it can be useful for your own developments.

## Standards

The following table represents the different preprocessor symbols for the C++ standard supported by xtd:

| Symbols                | Standard                                                          |
| ---------------------- | ----------------------------------------------------------------- |
| `__cplusplus = 199711L`| [C++98](https://www.open-std.org/jtc1/sc22/wg21/) (not supported) |
| `__cplusplus = 201103L`| [C++11](https://en.wikipedia.org/wiki/C%2B%2B11) (not supported)  |
| `__cplusplus = 201402L`| [C++14](https://en.wikipedia.org/wiki/C%2B%2B14) (not supported)  |
| `__cplusplus = 201703L`| [C++17](https://en.wikipedia.org/wiki/C%2B%2B17)                  |
| `__cplusplus = 202002L`| [C++20](https://en.wikipedia.org/wiki/C%2B%2B20)                  |

For a more complete list of compiler see [Pre-defined Compiler Macros Wiki - Standards](https://sourceforge.net/p/predef/wiki/Standards/).

### Examples

The following code shows how to detect the C++ standard with the preprocessor symbols:

```cpp
#if defined(__cplusplus)
#  if __cplusplus == 202002L
#    define __standard_name__ "C++ 20"
#  elif __cplusplus == 201703L
#    define __standard_name__ "C++ 17"
#  elif __cplusplus == 201402L
#    define __standard_name__ "C++ 14 (not supported)"
#  elif __cplusplus == 201103L
#    define __standard_name__ "C++ 11 (not supported)"
#  elif __cplusplus == 199711L
#    define __standard_name__ "C++ 98 (not supported)"
#  else
#    define __standard_name__ "Unknown C++ standard"
#  endif
#else
#  error "Not C++ standard"
#endif

#include <xtd/xtd.core>

using namespace xtd;

int main() {
  console::write_line("standard_name=\"{}\"", __standard_name__);
  console::write_line("standard_name=\"{}\"", environment::cpp_version().name());
}

// This code produces the following output if C++20:
//
// platform_name="C++ 20"
// platform_name="C++ 20"
```

### Remarks

When using xtd, you do not need to use these preprocessor symbols.

It is better to use [xtd::environment::cpp_version](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#a605f670a384617410e0e52765765b167).

But it can be useful for your own developments.

## Build types

The following table represents the different preprocessor symbols for the build type by xtd:

| Symbols  | Build type                |
| -------- | ------------------------- |
| `NDBUG`  | The build type is release |

`NDEBUG` is the only definition in the C++ standard for whether the build type is debug or release.

### Examples

The following code shows how to detect the buil type with the preprocessor symbols:

```cpp
#if defined(NDEBUG)
#  define __build_type__ "release"
#else
#  define __build_type__ "debug"
#endif

#include <xtd/xtd.core>

using namespace xtd;

int main() {
  console::write_line("build_type=\"{}\"", __build_type__);
  console::write_line("build_type=\"{}\"", environment::compiler_version().build_type());
}

// This code produces the following output if build type debug:
//
// build_type="debug"
// build_type="debug"
```

### Remarks

When using xtd, you do not need to use these preprocessor symbols.

It is better to use [xtd::environment::compiler_version().build_type](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1compiler.html#a26e8527d072bb9417298a60a27046ad5).

But it can be useful for your own developments.

## xtd targets

The following table represents the different preprocessor symbols for the xtd targets:

| Symbols                                 | Target                            | Value   |
| --------------------------------------- | --------------------------------- | ------- |
| `__XTD_CURRENT_TARGET_ID__`             | The current target id             | [0...8] |
| `__XTD_TARGET_ID_UNKNOWN__`             | The target is unknown             | 0       |
| `__XTD_TARGET_ID_CONSOLE_APPLICATION__` | The target is console application | 1       |
| `__XTD_TARGET_ID_GUI_APPLICATION__`     | The target is gui application     | 2       |
| `__XTD_TARGET_ID_TEST_APPLICATION__`    | The target is test application    | 3       |
| `__XTD_TARGET_ID_INTERFACE_LIBRARY__`   | The target is interface library   | 4       |
| `__XTD_TARGET_ID_MODULE_LIBRARY__`      | The target is interface library   | 5       |
| `__XTD_TARGET_ID_SHARED_LIBRARY__`      | The target is shared library      | 6       |
| `__XTD_TARGET_ID_STATIC_LIBRARY__`      | The target is static library      | 7       |
| `__XTD_TARGET_ID_CUSTOM_TARGET__`       | The target is custom target       | 8       |

If you are not using CMake to generate your project, you must define them. See the [xtd.cmake overview](/docs/documentation/Guides/xtd.cmake/Overview) section for more information.

### Examples

The following code shows how to detect the xtd folder with the folder symbols:

```cpp
#include <xtd/xtd.core>

#if defined(__XTD_CURRENT_TARGET_ID__)
#  if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_UNKNOWN__
#    define __TARGET_ID_NAME__ "unknown"
#  elif __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_CONSOLE_APPLICATION__
#    define __TARGET_ID_NAME__ "console application"
#  elif __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__
#    define __TARGET_ID_NAME__ "gui application"
#  elif __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_TEST_APPLICATION__
#    define __TARGET_ID_NAME__ "test application"
#  elif __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_INTERFACE_LIBRARY__
#    define __TARGET_ID_NAME__ "interface library"
#  elif __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_MODULE_LIBRARY__
#    define __TARGET_ID_NAME__ "module library"
#  elif __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_SHARED_LIBRARY__
#    define __TARGET_ID_NAME__ "shared library"
#  elif __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_STATIC_LIBRARY__
#    define __TARGET_ID_NAME__ "static library"
#  elif __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_CUSTOM_TARGET__
#    define __TARGET_ID_NAME__ "custom target"
#  else
#    error "Current target id invalid"
#  endif
#else
# error "Current target id not defined"
#endif

using namespace xtd;

int main() {
  console::write_line("target_type=\"{}\"", __TARGET_ID_NAME__);
  console::write_line("target_type=\"{}\"", environment::target_type().name());
}

// This code produces the following output for a consome application:
//
// target_type="console application"
// target_type="console application"
```

### Remarks

When using xtd, you do not need to use these preprocessor symbols.

It is better to use [xtd::environment::target_type](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#a48fc0632092489172357d69eb5bbccd4).

## xtd paths

The following table represents the different preprocessor symbols for the xtd paths:

| Symbols                          | Path                               | Value                                            |
| -------------------------------- | ---------------------------------- | ------------------------------------------------ |
| `__XTD_INSTALL_PATH__`           | The installation folder of xtd     | ${XTD_INSTALL_PATH}/include"                     |
| `__XTD_LOCALE_PATH__`            | The xtd locale folder              | ${XTD_INSTALL_PATH}/include"                     |
| `__XTD_REFERENCE_GUIDE_PATH__`   | The xtd reference guide folder     | ${XTD_INSTALL_PATH}/include"                     |
| `__XTD_THEMES_PATH__`            | The xtd themes folder              | ${XTD_INSTALL_PATH}/include"                     |
| `__XTD_INCLUDE_PATH__`           | The xtd inlude folder              | ${XTD_INSTALL_PATH}/include"                     |
| `__XTD_LIB_PATH__`               | The xtd libraries folder           | ${XTD_INSTALL_PATH}/lib"                         |
| `__XTD_REOURCES_PATH__`          | The xtd resources folder           | ${XTD_INSTALL_PATH}/lib"                         |
| `__XTD_CONSOLE_INCLUDE_PATH__`   | The xtd::console inlude folder     | ${XTD_CONSOLE_INSTALL_PATH}/include"             |
| `__XTD_CONSOLE_LIB_PATH__`       | The xtd::console libraries folder  | ${XTD_CONSOLE_INSTALL_PATH}/lib"                 |
| `__XTD_DRAWING_INCLUDE_PATH__`   | The xtd::drawing inlude folder     | ${XTD_DRAWING_INSTALL_PATH}/include"             |
| `__XTD_DRAWING_LIB_PATH__`       | The xtd::drawing libraries folder  | ${XTD_DRAWING_INSTALL_PATH}/lib"                 |
| `__XTD_DRAWING_RESOURCES_PATH__` | The xtd::drawing resources folder  | ${XTD_DRAWING_INSTALL_PATH}/share/xtd/resources" |
| `__XTD_FORMS_INCLUDE_PATH__`     | The xtd::forms inlude folder       | ${XTD_FORMS_INSTALL_PATH}/include"               |
| `__XTD_FORMS_LIB_PATH__`         | The xtd::forms libraries folder    | ${XTD_FORMS_INSTALL_PATH}/lib"                   |
| `__XTD_FORMS_RESOURCES_PATH__`   | The xtd::forms resources folder    | ${XTD_FORMS_INSTALL_PATH}/share/xtd/resources"   |
| `__XTD_TUNIT_INCLUDE_PATH__`     | The xtd::tunit inlude folder       | ${XTD_TUNIT_INSTALL_PATH}/include"               |
| `__XTD_TUNIT_LIB_PATH__`         | The xtd::tunit libraries folder    | ${XTD_TUNIT_INSTALL_PATH}/lib"                   |

If you are not using CMake to generate your project, you must define them. See the [xtd.cmake overview](/docs/documentation/Guides/xtd.cmake/Overview) section for more information.

### Examples

The following code shows how to detect the xtd folder with the folder symbols:

```cpp
#include <xtd/xtd.core>

using namespace xtd;

int main() {
  console::write_line("xtd_themes=\"{}\"", __XTD_THEMES_PATH__);
  console::write_line("xtd_themes=\"{}\"", environment::get_folder_path(environment::special_folder::xtd_themes));
}

// This code produces the following output if under unix like system:
//
// xtd_themes="/usr/local/share/xtd/themes"
// xtd_themes="/usr/local/share/xtd/themes"
```

### Remarks

When using xtd, you do not need to use these preprocessor symbols.

It is better to use [xtd::environment::get_folder_path](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#a0bcc0c727357a767874cfc4970df1414).

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)
