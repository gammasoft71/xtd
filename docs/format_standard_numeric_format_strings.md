| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Format

Contains formatting converting documentation.

## Formatting Types

Formatting is the process of converting an instance of a class, structure, or enumeration value to its string representation, often so that the resulting string can be displayed to users or deserialized to restore the original data type. This conversion can pose a number of challenges:

* The way that values are stored internally does not necessarily reflect the way that users want to view them. For example, a telephone number might be stored in the form 8009999999, which is not user-friendly. It should instead be displayed as 800-999-9999. See the [Custom Format Strings](Custom-format-strings) section for an example that formats a number in this way.
* Sometimes the conversion of an object to its string representation is not intuitive. For example, it is not clear how the string representation of a Temperature object or a Person object should appear. For an example that formats a Temperature object in a variety of ways, see the [Standard Format Strings(standard-format-strings)] section.
* Values often require culture-sensitive formatting. For example, in an application that uses numbers to reflect monetary values, numeric strings should include the current culture’s currency symbol, group separator (which, in most cultures, is the thousands separator), and decimal symbol.
* An application may have to display the same value in different ways. For example, an application may represent an enumeration member by displaying a string representation of its name or by displaying its underlying value. For an example that formats a member of the day_of_week enumeration in different ways, see the [Standard Format Strings](standard-format-strings) section.

### Notes

Formatting converts the value of a type into a string representation. Parsing is the inverse of formatting. A parsing operation creates an instance of a data type from its string representation.


xtd provides rich formatting support that enables developers to address these requirements.

This overview contains the following sections:

* [Formatting](formatting)
* [Default Formatting Using Operator Shift Left](defaultf-formatting-using-operator-shift-left)
* [Overriding Shift Left operator Method](overriding-shift-left-operator-method)
* [to_string Method And Format Strings](to_string-method-and-format-strings)
  * [Standard Format Strings](standard-format-strings)
  * [Custom Format Strings](custom-format-strings)
  * [Format Strings And Types](format-strings-and-types)
* [Culture Sensitive Formatting](culture-sensitive-formatting)
  * [Culture Sensitive Formatting Of Numeric Values](culture-sensitive-formatting-of-numeric-values)
  * [Culture Sensitive Formatting Of Date And Time Values](culture-sensitive-formatting-of-date-and-time-values)
* [Culture Sensitive Formatting](culture-sensitive-formatting)
* [Composite Formatting](composite-formatting)
* [Custom Formatting](custom-formatting)
* [Related Topics](related-topics)
* [Reference](reference)

## Formating

The basic mechanism for formatting is the default implementation of the operator `<<` object method, which is discussed in the [Default Formatting Using Operator Shift Left](default-formatting-using-operator-shift-left) section later in this topic. xtd.Strings provides several ways to modify and extend its default formatting support. These include the following:

* Overriding the operator `<<` object method to define a custom string representation of an object’s value. For more information, see the [Overriding Shift Left Operator Method](overriding-shift-left-operator-method]) section later in this topic.
* Defining format specifiers that enable the string representation of an object’s value to take multiple forms. For example, the "X" format specifier in the following statement converts an integer to the string representation of a hexadecimal value.

```cpp
int integer_value = 60312;
xtd::console::write_line(xtd::to_string(integer_value, "X"));   // Displays EB98.
```

For more information about format specifiers, see the [to_string Method And Format Strings](to_string-method-and-format-strings) section.

* Using format providers to take advantage of the formatting conventions of a specific culture. For example, the following statement displays a currency value by using the formatting conventions of the en-US culture.

```cpp
double cost = 1632.54;
xtd::console::write_line(xtd::to_string(cost, "C", std::locale("en_US.UTF-8")));
// The example displays the following output:
//
// $1,632.54
```

For more information about formatting with format providers, see the [Culture Sensitive Formatting](culture-sensitive-formatting) section.

Using composite formatting to embed the string representation of a value in a larger string. For more information, see the [Composite Formatting](composite-formatting) section.

The following sections examine these methods for converting an object to its string representation.

## Composite Formatting

The composite formatting feature takes a list of objects and a composite format string as input. A composite format string consists of fixed text intermixed with indexed placeholders, called format items, that correspond to the objects in the list. The formatting operation yields a result string that consists of the original fixed text intermixed with the string representation of the objects in the list.

The composite formatting feature is supported by methods such as the following:

* [xtd::ustring::format](https://gammasoft71.github.io/xtd/reference_guides/latest/group__format__parse.html#ga3afd6d163bc6391a48a1f84f28a68ffd), which returns a formatted result string (xtd library).
* Some overloads of the [xtd::console::write_line](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#aa9fbf20d808213c547163d5e7101bcda) method, which display a formatted result string to the console ([xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html) library).
* [xtd::diagnostics::debug::write_line](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1debug.html#a2656cc128804128258ecad60ecf1cbd1) method, which outputs a formatted message to trace listeners ([xtd.core](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html) library).
* The [xtd::diagnostics::trace::trace_error](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1trace.html#a961460d0f10e5a3a36cfa2ecc222687a), [xtd::diagnostics::trace::trace_information](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1trace.html#ae6444d92dadb5325844ed01313384335), and [xtd::diagnostics::trace::trace_warning](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1trace.html#a8500d77e87bea7e8b021d1530e403850) methods, which output formatted messages to trace listeners (xtd.core library).

## Composite Format String

A composite format string and object list are used as arguments of methods that support the composite formatting feature. A composite format string consists of zero or more runs of fixed text intermixed with one or more format items. The fixed text is any string that you choose, and each format item corresponds to an object or boxed structure in the list. The composite formatting feature returns a new result string where each format item is replaced by the string representation of the corresponding object in the list.

Consider the following [xtd::ustring::format](https://gammasoft71.github.io/xtd/reference_guides/latest/group__format__parse.html#ga3afd6d163bc6391a48a1f84f28a68ffd) code fragment.

```cpp
string name = "Fred";
xtd::ustring::format("Name = {0}, age = {1:D3}", name, 42);
```

The fixed text is `name = ` and `, age = `. The format items are "{0}", whose index is 0, which corresponds to the object name, and "{1:D3}", whose index is 1, which corresponds to the integer 42.

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
