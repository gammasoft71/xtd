# xtd: A modern cross-platform C++ framework inspired by .NET (Open Source)

Hi everyone,

I’ve been working for several years on xtd, a modern C++ open source framework designed to:

-	Offer a modern and consistent API, inspired by .NET,
-	Remain 100% C++ (no exotic dependencies or macros everywhere),
-	Be cross-platform: Windows, macOS, Linux, FreeBSD, Haiku, Android, iOS,
-	Cover both console and graphical applications (GUI), as well as unit testing.

## Simple example :

```
#include <xtd/xtd>

// simple GUI app
auto main() -> int {
  application::run(form::create("Hello, xtd!"));
}
```

I know there are already many libraries/frameworks (Qt, wxWidgets, etc.), but xtd aims to bring:

-	An API close to .NET (intuitive for developers coming from C#/Java),
-	A modern approach to C++ (RAII, STL-friendly containers, no need for new everywhere),
-	A clear and portable architecture (very few #ifdefs).

The goal is not to replace Qt, but to provide an alternative cross-platform C++ framework that is lightweight, easy to integrate, and extendable — especially for developers who want .NET-style APIs in C++.

The project is already quite advanced (several modules, ports, build tools, unit tests), and the roadmap is public.

I’d love to share this with the community — feedback is greatly appreciated, and if some of you are interested in contributing or testing it, that would be amazing.

## Links
	
- [GitHub](https://github.com/gammasoft71/xtd)
- [Documentation](https://gammasoft71.github.io/xtd)
- [Reference guide](https://gammasoft71.github.io/xtd/reference_guides/latest/index.html)

Thank you for your feedback!

## Published

To be published on Reddit r/opensource on September 2, 2025.
