---
sidebar_position: 13
---

# Features

[![features](/pictures/xtd_bento_dark.png)](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/xtd_bento_dark.png)

* Free and open-source ([MIT License](/docs/documentation/license));
* a collection of native C++ classes libraries, to complete std;
* API close to the .net API with a modern C++ approach and full integration with the std standard;
* written in efficient, modern [C++17/20](https://en.cppreference.com/w/) with [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming idiom;
* and highly portable and available on many different platforms;

## classes / components

xtd contains various classes and components to help you create your applications. These classes and components complement the standard C++ library.
The following is a non-exhaustive list of the components present in the xtd framework:

* [cmake](https://gammasoft71.github.io/xtd/reference_guides/latest/_c_make_commands.html) : xtd is based on CMake and contains numerous functions to help and simplify the configuration of the CMakelists.txt file construction.
* [delegate](/docs/documentation/Guides/xtd.core/Types%20overview/delegates) : xtd implements delegate and event classes to respond easily to system events, GUI events and programming events.
* [diagnostics](https://gammasoft71.github.io/xtd/reference_guides/latest/group__diagnostics.html) : xtd contains numerous diagnostic classes (such as debug, trace, debugger, ...) to help you monitor your application.
* [drawing](/docs/documentation/Guides/xtd.drawing/drawing) : xtd contains pens, solid brushes and various gradients, images, bitmaps, icons and other useful classes for drawing what you want and need.
* [io](/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks) : The xtd.io namespace provides several classes that allow for various actions, such as reading and writing, to be performed on files, directories, and streams. For more information, see File and Stream I/O.
* [media](https://gammasoft71.github.io/xtd/reference_guides/latest/group__media.html) : 
* [network](/docs/documentation/Guides/xtd.core/Networking/network_programming) : 
* [threading](https://gammasoft71.github.io/xtd/reference_guides/latest/group__threading.html) :
* [timers](https://gammasoft71.github.io/xtd/reference_guides/latest/group__timers.html) :

xtd contains a wide variety of classes in different libraries. 
You can find more information in the [xtd programming guide](/docs/documentation/Guides) and in the [xtd reference guide](https://gammasoft71.github.io/xtd/reference_guides/latest/index.html).

## Applications

With xtd you can create differents targets :

* [console application](/docs/documentation/Guides/Overview/Tutorials/writing_applicaion_console) to run your own application in CLI mode.
* [Gui application](/docs/documentation/Guides/Overview/Tutorials/writing_applicaion_gui) to run your own application in a graphical mode with rich controls and drawings.
* [test application](/docs/documentation/Guides/Overview/Tutorials/writing_applicaion_test) to run your own unit tests.
* [static and dynamic libraries](https://gammasoft71.github.io/xtd/reference_guides/latest/_c_make_commands.html#TargetTypeSubSection) to contain your own code to share between your applications.

You can use [xtdc](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc/README.md) and [xtdc-gui](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc-gui/README.md) to help you create these different targets.


## See also

- [Documentation](/docs/documentation)
