| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Preprocessor Symbols

## Operating Systems

The following table represents the different preprocessor symbols for the platforms supported by xtd.

| Defines          | OS                                                                     |
|------------------|------------------------------------------------------------------------|
| `__ANDROID__`    | [Android](http://en.wikipedia.org/wiki/Android_%28operating_system%29) |
| `__APPLE__`      | [macOS](http://en.wikipedia.org/wiki/Mac_OS)                           |
| `__linux__`      | [Linux](http://en.wikipedia.org/wiki/Linux_kernel)                     |
| `__unix__`       | [Unix](http://en.wikipedia.org/wiki/unix)                              |
| `_POSIX_VERSION` | [Posix](http://en.wikipedia.org/wiki/posix)                            |
| `_WIN32`         | [Windows](http://en.wikipedia.org/wiki/Category:Microsoft_Windows)     |

To detect the different Apple platforms, it is necessary to include the `TargetConditionals.h` file which contains the different target definitions.

For a more complete list of platforms see [Pre-defined Compiler Macros Wiki - Operating system](https://sourceforge.net/p/predef/wiki/OperatingSystems/).

### Examples

The following code shows how to detect the operating system with the preprocessor symbols:

```c++
#if defined(_WIN32)
#  ifdef _WIN64
#    define __platform_name__ "Windows 64 bits"
#  else
#    define __platform_name__ "Windows 32 bits"
#  endif
#elif defined(__APPLE__)
#  include <TargetConditionals.h>
#  if defined(TARGET_OS_MAC)
#    if defined (TARGET_OS_OSX)
#      define __platform_name__ "macOS"
#    elif TARGET_OS_IPHONE
#      if TARGET_OS_IOS
#        define __platform_name__ "iOS"
#      elif TARGET_OS_TV
#        define __platform_name__ "Apple TV OS"
#      elif TARGET_OS_WATCH
#        define __platform_name__ "Apple Watch OS"
#      elif TARGET_OS_BRIDGE
#        define __platform_name__ "Bridge device"
#      elif TARGET_OS_MACCATALYST
#        define __platform_name__ "iPhone Simulator"
#      else
#        error "Unknown iPhone platform"
#      endif
#    elif TARGET_OS_DRIVERKIT
#      define __platform_name__ "macOS, iOS, Apple TV OS, or Apple Watch OS"
#    elif TARGET_IPHONE_SIMULATOR
#      define __platform_name__ "iPhone Simulator"
#    else
#      error "Unknown Apple platform"
#    endif
#  elif defined(TARGET_OS_WIN32)
#    define __platform_name__ "WIN32 API"
#  elif defined(TARGET_OS_WINDOWS)
#    define __platform_name__ "Windows"
#  elif defined(TARGET_OS_UNIX)
#    define __platform_name__ "Unix"
#  elif defined(TARGET_OS_LINUX)
#    define __platform_name__ "Linux"
#  else
#    error "Unknown Target"
#  endif
#elif __ANDROID__
#  define __platform_name__ "Android"
#elif __linux__
#  define __platform_name__ "Linux"
#elif __unix__
#  define __platform_name__ "Unix"
#elif defined(_POSIX_VERSION)
#  define __platform_name__ "Posix"
#else
#  error "Unknown Platform"
#endif

#include <xtd/xtd.core>

int main() {
  xtd::console::write_line("platform_name=\"{}\"", __platform_name__);
}

// This code produces the following output if under Windows 64 bits :
//
// platform_name="Windows 64 bits"
```

### Remarks

When using xtd, you do not need to use these preprocessor symbols.
It is better to use [xtd::environment::os_version](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1environment.html#a7eb460253deb58efb3bfdfbb71904119).
But it can be useful for your own developments.

## Build types

## xtd paths

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.
