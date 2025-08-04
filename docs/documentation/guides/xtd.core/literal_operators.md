# Literal operators in xtd


**Namespace**: `xtd::literals`  
**Library**: `xtd.core` (with extensions from other modules)

## Overview

The `xtd::literals` namespace provides user-defined literal operators that simplify the creation of commonly used `xtd` types.

These literals improve readability and consistency in code, allowing developers to express values in a concise and natural way.

## Design Principle

All literals are defined under the `xtd::literals` namespace, even if the related types belong to other namespaces such as `xtd::drawing` or `xtd::net`.

This allows a unified `using` directive:

```cpp
using namespace xtd::literals;
```

Without the need to import module-specific namespaces like `xtd::net::literals` or `xtd::drawing::literals`.

## Organization

Even though the operators are grouped under `xtd::literals`, their implementations follow a modular layout that respects the logical ownership of types:

```
xtd.core
├── xtd
│   └── literals
│       ├── byte.hpp
│       ├── char32.hpp
│       ├── version.hpp
│       └── ...

xtd.drawing
├── xtd
│   └── literals
│       └── color.hpp

xtd.net
├── xtd
│   └── literals
│       └── ip.hpp
```

Each header only includes what it needs and keeps responsibility localized.

## Available Literal Operators

| Literal                               | Target Type                    | Example                                                  |
|---------------------------------------|--------------------------------|----------------------------------------------------------|
| `_b`, `_s8`                           | `xtd::byte`                    | `42_b` or `"255"_b`                                      |
| `_c`                                  | `xtd::char32`                  | `'A'_c`                                                  |
| `_s`                                  | `xtd::ustring` or `time_span`  | `"text"_s` or `1.5_s`                                    |
| `_h`, `_m`, `_ms`, `_us`, `_ns`, `_d` | `xtd::time_span`               | `1_h`, `500_ms`, etc.                                    |
| `_vers`                               | `xtd::version`                 | `"1.2.3"_vers`                                           |
| `_color`                              | `xtd::drawing::color`          | `"dodger blue"_color` or `"FF0000"_color`                |
| `_country`                            | `xtd::forms::country`          | `"Belgium"_country` or `"BE"_country` or `"BEL"_country` |
| `_ip`                                 | `xtd::net::ip_address`         | `"127.0.0.1"_ip` or `"::1"_ip`   |

The following [literal operators page](https://gammasoft71.github.io/xtd/reference_guides/latest/group__literals.html) shows all xtd literal operators.

## Safety and Error Handling

All string-based literal operators use their respective `parse` methods internally:

```cpp
"1.2.3"_vers → version::parse("1.2.3")
"FF0000"_color → color::parse("FF0000")
```

Exceptions such as `xtd::format_exception` or `xtd::argument_exception` will be thrown if parsing fails.

## Example

```cpp
#include <xtd/xtd>

using namespace xtd::literals;

auto main() -> int {
  auto version = "1.2.3"_vers;
  auto color = "dodger blue"_color;
  auto ip = "192.168.1.1"_ip;
  auto delay = 2.5_s;

  console::write_line("version: {}", version);
  console::write_line("color: {}", color);
  console::write_line("ip: {}", ip);
  console::write_line("delay: {}", delay.total_milliseconds());
}
```

## Notes

- All literals are optional. If you don’t include the `xtd::literals` namespace, you can still construct the values manually.
- You are free to include only the headers you need:
  ```cpp
  #include <xtd/literals/version.hpp>
  #include <xtd/literals/color.hpp>
  ```

# See also
​​​
* [Tutorials](/docs/documentation/guides/Overview/Tutorials)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/custom-date-and-time-format-strings)
