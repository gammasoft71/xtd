| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Overview: How to format numbers, dates, enums, and other types in xtd

Formatting is the process of converting an instance of a class or structure, or an enumeration value, to a string representation.
The purpose is to display the resulting string to users or to deserialize it later to restore the original data type.
This article introduces the formatting mechanisms that xtd provides.

## Notes

  Parsing is the inverse of formatting. 
  A parsing operation creates an instance of a data type from its string representation. 
  For more information, see [Parsing Strings](parse_overview.md). 

The basic mechanism for formatting is the default implementation of the [xtd::object::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html#a5682215ee76ab97c48580ab162c49507) method, which is discussed in the [Default Formatting Using the to_string Method](default-formatting-using-the-to-strin-method) section later in this topic. 
However, xtd provides several ways to modify and extend its default formatting support. 
These include the following:
* Overriding the [xtd::object::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html#a5682215ee76ab97c48580ab162c49507) method to define a custom string representation of an object's value. For more information, see the [Override the to_string Method](override-the-to-string-method) section later in this topic.
* Defining format specifiers that enable the string representation of an object's value to take multiple forms. For example, the "X" format specifier in the following statement converts an integer to the string representation of a hexadecimal value.

```cpp
int integer_value = 60312;
xtd::console::write_line(xtd::to_string(integer_value, "X"));   // Displays EB98.
```

For more information about format specifiers, see the [to_string Method and Format Strings](to_string-method-and-format-strings) section.

* Using format providers to implement the formatting conventions of a specific culture. For example, the following statement displays a currency value by using the formatting conventions of the en-US culture.

```cpp
double cost = 1632.54;
xtd::console::write_line(xtd::to_string(cost, "C", std::locale("en_US.UTF-8")));
// The example displays the following output:
//
// $1,632.54
```

* Implementing the IFormattable interface to support both string conversion with the Convert class and composite formatting. For more information, see the IFormattable Interface section.
* Using composite formatting to embed the string representation of a value in a larger string. For more information, see the Composite Formatting section.
* Using string interpolation, a more readable syntax to embed the string representation of a value in a larger string. For more information, see String interpolation.
* Implementing ICustomFormatter and IFormatProvider to provide a complete custom formatting solution. For more information, see the Custom Formatting with ICustomFormatter section.

The following sections examine these methods for converting an object to its string representation.


# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/formatting-types)
