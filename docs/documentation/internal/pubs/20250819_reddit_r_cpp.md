# xtd – A modern, cross-platform C++ framework inspired by .NET

## Intro

I’ve been developing xtd, an open source C++ framework that aims to bring a modern, .NET-like development experience to C++ while staying fully native and cross-platform.

The goal is to provide a rich, consistent API that works out of the box for building console, GUI, and unit test applications.

## Highlights

-	Cross-platform: Windows, macOS, Linux, FreeBSD, Haiku, Android, iOS
-	Rich standard-like library: core, collections, LINQ-like queries, drawing, GUI
-	Modern C++ API: works well with stack objects, no need for dynamic allocation everywhere
-	GUI support without boilerplate code
-	Built-in image effects and drawing tools
-	LINQ-style extensions (xtd::linq) for expressive data queries
-	Fully documented with examples

## Example

Simple **"Hello, World"** GUI application :

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto main_form = form::create("Hello world (message_box)");
  auto button1 = button::create(main_form, "&Click me", {10, 10});
  button1.click += [] {message_box::show("Hello, World!");};
  application::run(main_form);
}
```

![screenshot](https://github.com/gammasoft71/xtd/blob/docs/static/pictures/hello_world_message_box_wgm.png)

## Links

- [GitHub](https://github.com/gammasoft71/xtd)
- [Documentation](https://gammasoft71.github.io/xtd)
- [Reference guide](https://gammasoft71.github.io/xtd/reference_guides/latest/index.html)

Feedback and contributions are welcome.

## Published

Published on Reddit r/cpp on August 19, 2025.
