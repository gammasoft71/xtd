# src

Contains xtd sources.

## System

* [xtd.core](xtd.core) library contains all fundamental classes to access Hardware, Os, System, and more.
* [xtd.core.native](xtd.core.native) library contains internal native API definitions to access underlying operating system used by xtd.core library.
* [xtd.core.native.android](xtd.core.native.android) library is based on [Android](https://android.com) operating system.
* [xtd.core.native.freebsd](xtd.core.native.freebsd) library is based on [FreeBSD](https://freebsd.org) operating system.
* [xtd.core.native.haiku](xtd.core.native.haiku) library is based on [Haiku](https://haiku-os.org) operating system.
* [xtd.core.native.ios](xtd.core.native.ios) library is based on [iOS](https://apple.com/ios) operating system.
* [xtd.core.native.linux](xtd.core.native.linux) library is based on [Linux](https://kernel.org/doc/html/latest/) operating system.
* [xtd.core.native.macos](xtd.core.native.macos) library is based on [macOS](https://apple.com/macos) operating system.
* [xtd.core.native.posix](xtd.core.native.posix) library is based on generic [Posix](https://posix.opengroup.org) operating system.
* [xtd.core.native.serenityos](xtd.core.native.serenityos) library is based on [SerenityOS](https://serenityos.org) operating system.
* [xtd.core.native.unix](xtd.core.native.unix) library is based on generic [Unix](https://opengroup.org/membership/forums/platform/unix) operating system.
* [xtd.core.native.windows](xtd.core.native.windows) library is based on [Windows](https://microsoft.com/en-gb/windows) operating system.

## Drawing

* [xtd.drawing](xtd.drawing) library provides access to GDI+ basic graphics functionality.
* [xtd.drawing.native](xtd.drawing.native) library contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
* [xtd.drawing.native.cocoa](xtd.drawing.native.cocoa) library is based on Apple [AppKit](https://developer.apple.com/documentation/appkit/) toolkit.
* [xtd.drawing.native.fltk](xtd.drawing.native.fltk) library is based on [FLTK](https://fltk.org) toolkit.
* [xtd.drawing.native.gtk3](xtd.drawing.native.gtk3) library is based on [GTK+ 3](https://developer.gnome.org/gtk3/stable/index.html) toolkit.
* [xtd.drawing.native.gtk4](xtd.drawing.native.gtk4) library is based on [GTK+ 4](https://developer.gnome.org/gtk4/stable/index.html) toolkit.
* [xtd.drawing.native.qt5](xtd.drawing.native.qt5) library is based on [Qt](https://qt.io) toolkit.
* [xtd.drawing.native.win32](xtd.drawing.native.win32) library is based on Microsoft [Win32](https://docs.microsoft.com/en-us/windows/apps/desktop/) toolkit.
* [xtd.drawing.native.wxwidgets](xtd.drawing.native.wxwidgets) library is based on [wxWidgets](https://wxwidgets.org/) toolkit.

## Forms

* [xtd.forms](xtd.forms) library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
* [xtd.forms.native](xtd.forms.native) library contains internal native API definitions to access underlying toolkits used by xtd.forms library.
* [xtd.forms.native.cocoa](xtd.forms.native.cocoa) library is based on Apple [AppKit](https://developer.apple.com/documentation/appkit/) toolkit.
* [xtd.forms.native.fltk](xtd.forms.native.fltk) library is based on [FLTK](https://www.fltk.org) toolkit.
* [xtd.forms.native.gtk3](xtd.forms.native.gtk3) library is based on [GTK+ 3](https://developer.gnome.org/gtk3/stable/index.html) toolkit.
* [xtd.forms.native.gtk4](xtd.forms.native.gtk4) library is based on [GTK+ 4](https://developer.gnome.org/gtk4/stable/index.html) toolkit.
* [xtd.forms.native.qt5](xtd.forms.native.qt5) library is based on [Qt](https://www.qt.io) toolkit.
* [xtd.forms.native.win32](xtd.forms.native.win32) library is based on Microsoft [Win32](https://docs.microsoft.com/en-us/windows/apps/desktop/) toolkit.
* [xtd.forms.native.wxwidgets](xtd.forms.native.wxwidgets) library is based on [wxWidgets](https://www.wxwidgets.org/) toolkit.

## Test

* [xtd.tunit](xtd.tunit) library contains components needed for unit testing.

## Third parties

* [xtd.3rdparty.StackWalker](xtd.3rdparty.StackWalker) provides information about the call stack for Windows only.

## The xtd libraries hierarchy

![libraries_img](../docs/pictures/hierarchy.png)

## Note on the current native backend

To enable fast, stable, and cross-platform development, the [xtd.drawing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html) and [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) libraries currently use wxWidgets as their single native backend, via [xtd.drawing.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native.wxwidgets) and [xtd.forms.native.wxwidgets](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets).
This decision allows xtd’s public API to evolve rapidly, without being slowed down by the overhead of maintaining multiple native backends simultaneously (Win32, Cocoa, Gtk4, etc.).

This is a transitional design: in future versions, each platform will have its own native backend to leverage its specific features and performance, while preserving a unified API for end users.

* [xtd 2.0.0](https://gammasoft71.github.io/xtd/docs/documentation/roadmap#release-200-release): Implementation of the Win32 backend via [xtd.drawing.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native.win32) and [xtd.forms.native.win32](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.win32).
* [xtd 3.0.0](https://gammasoft71.github.io/xtd/docs/documentation/roadmap#release-300-release): Implementation of the Gtk4 backend via [xtd.drawing.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native.gtk4) and [xtd.forms.native.gtk4](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.gtk4).
* [xtd 4.0.0](https://gammasoft71.github.io/xtd/docs/documentation/roadmap#release-400-release): Implementation of the Cocoa backend via [xtd.drawing.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing.native.cocoa) and [xtd.forms.native.cocoa](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.cocoa).

See the full [xtd roadmap](https://gammasoft71.github.io/xtd/docs/documentation/roadmap) for more details.
