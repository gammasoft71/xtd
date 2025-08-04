---
sidebar_position: 8
---

# xtd libraries architecture

[![libraries_img](/pictures/block_diagram_onion.png)](/docs/documentation/Guides/Overview/Libraries/hierarchy)

xtd is composed of several libraries.

## xtd.core

[![core](/pictures/xtd.core.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html)
The [xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html) library is modern C++20 libraries of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.

## xtd.drawing

[![drawing](/pictures/xtd.drawing.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html)
The [xtd.drawing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html) library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.

## xtd.forms

[![forms](/pictures/xtd.forms.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html)
The [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows, Apple macOS and linux base operating system.

## xtd.tunit

[![tunit](/pictures/xtd.tunit.png)](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html)
The [xtd.tunit](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html) library is a unit-testing framework for modern C++20, inspired by [Microsoft.VisualStudio.TestTools.Cpp](https://docs.microsoft.com/en-us/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference).

## Note on the current native backend

To enable fast, stable, and cross-platform development, the [xtd.drawing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html) and [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) libraries currently use wxWidgets as their single native backend, via [xtd.drawing.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native.wxwidgets) and [xtd.forms.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets).
This decision allows xtd’s public API to evolve rapidly, without being slowed down by the overhead of maintaining multiple native backends simultaneously (Win32, Cocoa, Gtk4, etc.).

This is a transitional design: in future versions, each platform will have its own native backend to leverage its specific features and performance, while preserving a unified API for end users.

* [xtd 2.0.0](/docs/documentation/roadmap#release-200-release): Implementation of the Win32 backend via [xtd.drawing.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native.win32) and [xtd.forms.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.win32).
* [xtd 3.0.0](/docs/documentation/roadmap#release-300-release): Implementation of the Gtk4 backend via [xtd.drawing.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native.gtk4) and [xtd.forms.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.gtk4).
* [xtd 4.0.0](/docs/documentation/roadmap#release-400-release): Implementation of the Cocoa backend via [xtd.drawing.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native.cocoa) and [xtd.forms.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.cocoa).

See the full [xtd roadmap](/docs/documentation/roadmap) for more details.

## See also

* [xtd libraries hierarchy](/docs/documentation/Guides/Overview/Libraries/hierarchy)
* [Documentation](/docs/documentation)
