| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# ustring

The [xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html) class represents text as a sequence of UTF-8 code units.

A string is a sequential collection of characters that's used to represent text. 
An [xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html) object is a sequential collection of `char` that represent a string;
a `char` corresponds to a UTF-8 code unit. 
The value of the [xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html) object is the content of the sequential collection of `char`, and unlike [std::string](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).

## xtd::ustring vs std::string

[xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html) is an immutable [std::string](https://en.cppreference.com/w/cpp/string/basic_string).

* [std::string](https://en.cppreference.com/w/cpp/string/basic_string) is inherited from [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string).
* [xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html) is inherited from [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) too and thus offers the immutable API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string) with some functions missing from std::string.

## Additional methods

* [xtd::ustring::concat](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html#a9d492d6b9ce2f2e38661a5062009a32f) concatenates two, three or four specified instances of string or string array.
* [xtd::ustring::format](https://gammasoft71.github.io/xtd/reference_guides/latest/group__format__parse.html#ga3afd6d163bc6391a48a1f84f28a68ffd) writes the text representation of the specified arguments list, to string using the specified format information. See [format](format.md) for more information.
* [xtd::ustring::join](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html#a95694998a854ba65dde682b879eec355) concatenates a specified separator string between each element of a specified object array, yielding a single concatenated string.
* [xtd::ustring::parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html#a90aeac5b1761195838734b45d1268dd3) converts a string into a value_t type.
* [xtd::ustring::split](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html#a96a729c2b591760cb0971d43418b3804) splits this string into a maximum number of substrings based on the characters in an array.
* [xtd::ustring::try_parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html#a0975a450a98f2c65f5649d2144a0bf0e) Try to convert a string into a value_t type.
* End more, see [xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html) reference guide for a complete list of methods.

## String conversions

### xtd::convert_string

The [xtd::convert_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__string.html) class represents API to convert string containers.

The [xtd::convert_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__string.html) class is used to convert string container to another.

#### Remarks 

The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.

#### Examples

The following code shows how to convert [xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html) to [std::u32string](https://en.cppreference.com/w/cpp/string/basic_string) and writes the converted string to the console output.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

auto main() -> int {
  ustring s1 = "UTF-8 (65001) string value";
  
  auto s2 = convert_string::to_u32string(s1);
  console::write_line(s2);
}
```

This example is one of N. You can convert any string container to any other string container.

See [type convertion](type_conversion_overview.md) for more information and [xtd::convert_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__string.html) class for a complete list of conversion methods.

### as operator

The [xtd::as<...>](ahtml#ga19379a1158ccd320e208b362f11295b7) operators cast a type into another type.

#### Remarks 

The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.

#### Examples

The following code shows how to convert [std::u16string](https://en.cppreference.com/w/cpp/string/basic_string) to [xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html) and writes the converted string to the console output.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;

auto main() -> int {
  u16string s1 = u"UTF-8 (65001) string value";
  
  auto s2 = as<ustring>(s1);
  console::write_line(s2);
}
```

This example is one of N. You can convert any string container to any other string container.

See [type convertion](type_conversion_overview.md) for more information and [xtd::as<...>](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga19379a1158ccd320e208b362f11295b7) operators for a complete list of conversion operators.

## xtd::ustring literal operators

There are some literals operators for xtd::ustring:

* [_s](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga3159a02c625a6b416d84cc09109fa1bb) literal operator is used to convert specified value into xtd::ustring.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = "This is a "_s + "simple string"_s;
  console::write_line(s);
}
// output: This is a simple string
```

* [_sb](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga43c09451f4b809ab7efd4fc5bdaeda84) literal operator is used to convert the specified value to xtd::ustring with a binary format.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sb;
  console::write_line("0b{}", s);
}
// output: 0b101010
```

* [_sb2](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga7eaf7f69ff2304bf1bab94827e109610) literal operator is used to convert the specified value to xtd::ustring with a binary format with two digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 1_sb2;
  console::write_line("0b{}", s);
}
// output: 0b01
```

* [_sb4](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga856739797e253190afd27ba2dadcd713) literal operator is used to convert the specified value to xtd::ustring with a binary format with four digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 3_sb4;
  console::write_line("0b{}", s);
}
// output: 0b0011
```

* [_sb8](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga27bc00f6bf6ca69c610a2dab13115a82) literal operator is used to convert the specified value to xtd::ustring with a binary format with eight digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sb8;
  console::write_line("0b{}", s);
}
// output: 0b00101010
```

* [_sb16](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gaf72922be81431716b63f621451dca9fc) literal operator is used to convert the specified value to xtd::ustring with a binary format with sixteen digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sb16;
  console::write_line("0b{}", s);
}
// output: 0b0000000000101010
```

* [_sb32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga2722ffae5eaa8668ce66ae53309d7cf9) literal operator is used to convert the specified value to xtd::ustring with a binary format with thirty two digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sb32;
  console::write_line("0b{}", s);
}
// output: 0b00000000000000000000000000101010
```

* [_sb64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga3d69af37baeea27aba64561e5aa7411a) literal operator is used to convert the specified value to xtd::ustring with a binary format with sixty four digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sb64;
  console::write_line("0b{}", s);
}
// output: 0b0000000000000000000000000000000000000000000000000000000000101010
```

* [_sd](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gac756c19a09319ef9a70df4405f70fcd8) literal operator is used to convert specified value into xtd::ustring with a decimal format.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sd;
  console::write_line(s);
}
// output: 42
```

* [_sd](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga599899d6e78170e7a369e83378d14a1a) literal operator is used to convert specified value into xtd::ustring with a decimal format.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 4.2_sd;
  console::write_line(s);
}
// output: 4.2
```

* [_sx](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gae46364777b448e80daadf66ae77f1fbf) literal operator is used to convert the specified value to xtd::ustring with a hexa format.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sx;
  console::write_line("0x{}", s);
}
// output: 0x2a
```

* [_sx2](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gae9616d36a82e9e5b5600328ca76a5471) literal operator is used to convert the specified value to xtd::ustring with a hexa format with two digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 10_sx2;
  console::write_line("0x{}", s);
}
// output: 0x0a
```

* [_sx4](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gaf288cd786089a9f4ec3d02466707e3c5) literal operator is used to convert the specified value to xtd::ustring with a hexa format with four digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sx4;
  console::write_line("0x{}", s);
}
// output: 0x002a
```

* [_sx8](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gaa4acf7c9bbc764e2254c67196630c434) literal operator is used to convert the specified value to xtd::ustring with a hexa format with eight digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sx8;
  console::write_line("0x{}", s);
}
// output: 0x0000002a
```

* [_sX](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga47c03a571d078d7dfeed1af05baa0fe2) literal operator is used to convert the specified value to xtd::ustring with a hexa format.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sX;
  console::write_line("0x{}", s);
}
// output: 0x2A
```

* [_sX2](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga246c6f5fcf4b5f23fd4f54512d1e25dd) literal operator is used to convert the specified value to xtd::ustring with a hexa format with two digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 10_sX2;
  console::write_line("0x{}", s);
}
// output: 0x0A
```

* [_sX4](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga7f98753adb927ff671f9b7c0f505ce95) literal operator is used to convert the specified value to xtd::ustring with a hexa format with four digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sX4;
  console::write_line("0x{}", s);
}
// output: 0x002A
```

* [_sX8](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gaca78174d0fd95202301f20582ab3c19a) literal operator is used to convert the specified value to xtd::ustring with a hexa format with eight digits.

```cpp
#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  ustring s = 42_sX8;
  console::write_line("0x{}", s);
}
// output: 0x0000002A
```

See [lietarl operators](literal_operators.md) for more information.

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
