| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# ustring

The [xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) class represents text as a sequence of UTF-8 code units.

A string is a sequential collection of characters that's used to represent text. 
An [xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) object is a sequential collection of `char` that represent a string;
a `char` corresponds to a UTF-8 code unit. 
The value of the [xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) object is the content of the sequential collection of `char`, and unlike [std::string](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).

## xtd::ustring vs std::string

[xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) is an immutable [std::string](https://en.cppreference.com/w/cpp/string/basic_string).

* [std::string](https://en.cppreference.com/w/cpp/string/basic_string) is inherited from [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string).
* [xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) is inherited from [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) too and thus offers the immutable API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string) with some functions missing from std::string.

## Additional methods

* [xtd::ustring::concat](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a9d492d6b9ce2f2e38661a5062009a32f) concatenates two, three or four specified instances of string or string array.
* [xtd::ustring::format](https://codedocs.xyz/gammasoft71/xtd/group__format__parse.html#ga3afd6d163bc6391a48a1f84f28a68ffd) writes the text representation of the specified arguments list, to string using the specified format information. See [format](format.md) for more information.
* [xtd::ustring::join](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a95694998a854ba65dde682b879eec355) concatenates a specified separator string between each element of a specified object array, yielding a single concatenated string.
* [xtd::ustring::parse](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a90aeac5b1761195838734b45d1268dd3) converts a string into a value_t type.
* [xtd::ustring::split](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a96a729c2b591760cb0971d43418b3804) splits this string into a maximum number of substrings based on the characters in an array.
* [xtd::ustring::try_parse](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a0975a450a98f2c65f5649d2144a0bf0e) Try to convert a string into a value_t type.
* End more, see [xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) reference guide for a complete list of methods.

## String conversions

### xtd::convert_string

The [xtd::convert_string](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1convert__string.html) class represents API to convert string containers.

The [xtd::convert_string](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1convert__string.html) class is used to convert string container to another.

#### Remarks 

The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.

#### Examples

The following code shows how to convert [xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) to [std::u32string](https://en.cppreference.com/w/cpp/string/basic_string) and writes the converted string to the console output.

```c++
#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  ustring s1 = "UTF-8 string value";
  
  auto s2 = convert_string::to_u32string(s1);
  console::write_line(s2);
}
```

This example is one of N. You can convert any string container to any other string container.

See [xtd::convert_string](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1convert__string.html) class for a complete list of conversion methods.

### as operator

The [xtd::as<...>](https://codedocs.xyz/gammasoft71/xtd/group__xtd__core.html#ga19379a1158ccd320e208b362f11295b7) operators cast a type into another type.

#### Remarks 

The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.

#### Examples

The following code shows how to convert [std::u16string](https://en.cppreference.com/w/cpp/string/basic_string) to [xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) and writes the converted string to the console output.

```c++
#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  u16string s1 = u"UTF-8 string value";
  
  auto s2 = as<ustring>(s1);
  console::write_line(s2);
}
```

This example is one of N. You can convert any string container to any other string container.

See [xtd::as<...>](https://codedocs.xyz/gammasoft71/xtd/group__xtd__core.html#ga19379a1158ccd320e208b362f11295b7) operators for a complete list of conversion operators.

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.
