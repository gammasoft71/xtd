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
* [xtd::ustring](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html) is inherited from [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) too and therefore offers the full (immutable) API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string) with some functions missing from std::string.

## Additional methods

* [xtd::ustring::class_name](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a5bf26167d0f67d103c069fb005063234) gets the class name of the specified object or type.
* [xtd::ustring::compare](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#aade21fb4cb80096fd2a2fd981e6a3c1e) compares two specified string objects and returns an integer that indicates their relative position in the sort order.
* [xtd::ustring::compare](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#af5bdabe5dfc8e2160af379447a671778) compares substrings of two specified string objects and returns an integer that indicates their relative position in the sort order.
* [xtd::ustring::concat](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a9d492d6b9ce2f2e38661a5062009a32f) concatenates two, three or four specified instances of string or string array.
* [xtd::ustring::format](https://codedocs.xyz/gammasoft71/xtd/group__format__parse.html#ga3afd6d163bc6391a48a1f84f28a68ffd) writes the text representation of the specified arguments list, to string using the specified format information. See [format](format.md) for more information.
* [xtd::ustring::full_class_name](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a81a0eee00e7f757562565f8e19c7747d) gets the fully qualified class name of the specified object, including the namespace of the specified object.
* [xtd::ustring::join](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1ustring.html#a95694998a854ba65dde682b879eec355) concatenates a specified separator string between each element of a specified object array, yielding a single concatenated string.
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()
* [xtd::ustring::]()

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.
