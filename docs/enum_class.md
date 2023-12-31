| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# enum, enum class and enum struct

## In This section

* [Overview](#overview)
* [External libraries](#external-libraries)
* [xtd::enum_register](#xtd-enum-register)
* [xtd::enum_set_attribute](#xtd-enum_set-attribute)
* [Format](#format)
* [Parse](#parse)
* [Introspection](#introspection)

## Overview

An enumeration is a distinct type whose value is restricted to a range of values (see below for details), which may include several explicitly named constants ("enumerators"). The values of the constants are values of an integral type known as the underlying type of the enumeration.
For more information about c++ enumeration see [Enumeration declaration](https://en.cppreference.com/w/cpp/language/enum).

`enum`, `enum class` and `enum struct` in c++11 have two problems:
* Displaying in a string the name of the enum value either for debugging or simply to qualify some values as for example in [xtd::drawing::color::name](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1drawing_1_1color.html#a0b74e93ea5582716bde7104b84177a77).
* There is no flags attribute. You have to add the bitwise operators for each `enum`, `enum class` or `enum struct`. Enum flags pose an additional problem for displaying the value names in a string due to bitwise flags.

## External libraries

Several external libraries solve theses problems with elegance. Here is a non-exhaustive list:

* [better_enums](https://github.com/aantron/better-enums)
* [enum.hpp](https://github.com/BlackMATov/enum.hpp)
* [magic_enum](https://github.com/Neargye/magic_enum)
* [nav](https://github.com/codeinred/nav)
* [wise_enum](https://github.com/quicknir/wise_enum)
* And probably still others...

In the context of xtd, after testing these different external libraries, none of them was chosen for various reasons such as limitations and others.

xtd has therefore its own enumeration management

This does not prevent you, of course, from using them in your own projects. As xtd is non-intrusive, you can easily combine them with xtd and with some xtd enum class definitions (if the limitations of the library do not prevent this).

### Examples

* [magic_enum](https://github.com/Neargye/magic_enum)

The following code shows how to use `enum class` with magic_enum and xtd:

```cpp
#include <magic_enum/magic_enum.hpp>
#include <xtd/xtd>

using namespace magic_enum;
using namespace xtd;

enum class enum_test {
  value_one,
  value_two,
  value_three,
  value_four
};

auto main()->int {
  console::write_line("name = {}", enum_name<enum_test>(enum_test::value_four));
  console::write_line("value = {}", enum_integer<enum_test>(enum_test::value_four));
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = [{}]", ustring::join(", ", enum_values<enum_test>()));
  console::write_line("names = {}", enum_names<enum_test>());
  console::write("entries = [");
  for (auto entry : enum_entries<enum_test>()) {
    static auto index = 0;
    console::write("{}({}, {})", index++ == 0 ? "" : ", ", as<int>(entry.first), entry.second);
  }
  console::write_line("]");
}
```

Output :

```
name = value_four
value = 3
as<int> = 3
values = [0, 1, 2, 3]
names = [value_one, value_two, value_three, value_four]
entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

* [nav](https://github.com/codeinred/nav) with xtd

The following code shows how to use `enum class` with nav and xtd:

```cpp
#include <nav/nav_core.hpp>
#include <xtd/xtd>

using namespace nav;
using namespace xtd;

nav_declare_enum(enum_test, int,
  value_one,
  value_two,
  value_three,
  value_four
);

auto main()->int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = {}", ustring::join(", ", enum_values<enum_test>));
  console::write_line("names = {}", ustring::join(", ", enum_names<enum_test>));
  console::write("entries = [");
  for (size_t num_state = 0; num_state < num_states<enum_test>; ++num_state)
    console::write("{}({}, {})", num_state == 0 ? "" : ", ", enum_values<enum_test>[num_state], enum_names<enum_test>[num_state]);
  console::write_line("]");
}
```

Output :

```
name = 3
as<int> = 3
values = 0, 1, 2, 3
names = value_one, value_two, value_three, value_four
entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

## xtd::enum_register

xtd can introspect `enum`, `enum class` and `enum struct` with [introspection helper macros](#introspection) or simply register the `enum` class with the [xtd::enum_register](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1enum__register.html) class. 
The advantage is that it has no limitation and the disadvantage is that it is more verbose.

### Note

  If in your own project you do not register your `enum class`, there is no problem you can use it normally. 
  But when you want to display the value of the `enum class`, it will always be displayed as an integer value and you can't do any parsing on it.

### Examples

The following code shows how to use `enum class` with [xtd::enum_register](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1enum__register.html):

```cpp
#include <xtd/xtd>

using namespace xtd;

enum class enum_test {
  value_one,
  value_two,
  value_three,
  value_four
};

template<> struct xtd::enum_register<enum_test> {
  explicit operator auto() const noexcept {return xtd::enum_collection<enum_test> {{enum_test::value_one,  "value_one"}, {enum_test::value_two,  "value_two"}, {enum_test::value_three,  "value_three"}, {enum_test::value_four,  "value_four"}};}
};

auto main()->int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_int32());
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write("entries = [");
  for (auto entry : enum_object<>::get_entries<enum_test>()) {
    static auto index = 0;
    console::write("{}({}, {})", index++ == 0 ? "" : ", ", as<int>(entry.first), entry.second);
  }
  console::write_line("]");
}
```

Output :

```
name = value_four
value = 3
as<int> = 3
values = [0, 1, 2, 3]
names = [value_one, value_two, value_three, value_four]
entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

## xtd::enum_set_attribute

The [xtd::enum_set_attribute](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1enum__set__attribute.html) class is used to qualify an enum class attribute. 

There are two types of attributes:

* [xtd::enum_attribute::standard](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga21077f4832fc4718f7095d1a560a89cd) : Enum standard attribute. The default value.
* [xtd::enum_attribute::fmagts](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gga21077f4832fc4718f7095d1a560a89cda4e5868d676cb634aa75b125a0f741abf) : Enum flags attribute.

The class [xtd::enum_set_attribute](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1enum__set__attribute.html) is only used when we want to qualify the enumeration with the attribute flags.

Write the following code to set the attribute of an enum class :

```cpp
enum class enum_flags { /*...*/; }

template<> struct xtd::enum_set_attribute<enum_flags> {
  explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
};
```

This does not dispense with writing the operators necessary to perform bitwise operations, but is necessary to display the values of the enum class correctly.

Let's take the following example and see what happens with and without setting the attribute flag to [xtd::enum_attribute::flags](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga21077f4832fc4718f7095d1a560a89cd) :

```cpp
enum class test_enum {
  value_one = 0,
  value_two = 1,
  value_three = 2,
  value_four = 4
};

test_enum operator|(test_enum lhs, test_enum rhs) {return static_cast<test_enum>(static_cast<std::underlying_type<test_enum>::type>(lhs) | static_cast<std::underlying_type<test_enum>::type>(rhs));}
```

* With setting the attribute flag to [xtd::enum_attribute::flags](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga21077f4832fc4718f7095d1a560a89cd) :

```cpp
#include <xtd/xtd.core.h>

using namespace xtd;

enum class test_enum {
  value_one = 0,
  value_two = 1,
  value_three = 2,
  value_four = 4
};

test_enum operator |(test_enum lhs, test_enum rhs) {return static_cast<test_enum>(static_cast<std::underlying_type<test_enum>::type>(lhs) | static_cast<std::underlying_type<test_enum>::type>(rhs));}

template<> struct xtd::enum_set_attribute<test_enum> {
  explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
};

template<> struct xtd::enum_register<test_enum> {
  explicit operator auto() const noexcept {return xtd::enum_collection<test_enum> {{test_enum::value_one, "value_one"}, {test_enum::value_two, "value_two"}, {test_enum::value_three, "value_three"}, {test_enum::value_four, "value_four"}};}
};

auto main()->int {
  auto value = test_enum::value_two | test_enum::value_three;
  console::write_line("value = {}", value);
}
```

output:

```
value = value_two, value_three
```

Ok, this is the expected value.

* Without setting the attribute flag to [xtd::enum_attribute::flags](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga21077f4832fc4718f7095d1a560a89cd) :

```cpp
#include <xtd/xtd.core.h>

using namespace xtd;

enum class test_enum {
  value_one = 0,
  value_two = 1,
  value_three = 2,
  value_four = 4
};

test_enum operator |(test_enum lhs, test_enum rhs) {return static_cast<test_enum>(static_cast<std::underlying_type<test_enum>::type>(lhs) | static_cast<std::underlying_type<test_enum>::type>(rhs));}

template<> struct xtd::enum_register<test_enum> {
  explicit operator auto() const noexcept {return xtd::enum_collection<test_enum> {{test_enum::value_one, "value_one"}, {test_enum::value_two, "value_two"}, {test_enum::value_three, "value_three"}, {test_enum::value_four, "value_four"}};}
};

auto main()->int {
  auto value = test_enum::value_two | test_enum::value_three;
  console::write_line("value = {}", value);
}
```

output:

```
value = 3
```

Error, this is not the expected value.
Indeed, when the `value` is displayed, there is no member variable in `enum_test` that corresponds to `3`.


### flags_attribute_

To facilitate the writing of the flags attribute, there is the [flags_attribute helper](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gaea49fae71107df8769685efb159c181a).

The [flags_attribute helper](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gaea49fae71107df8769685efb159c181a) helper sets the [xtd::enum_set_attribute](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1enum__set__attribute.html) with the [xtd::enum_attribute::flags](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gga21077f4832fc4718f7095d1a560a89cda4e5868d676cb634aa75b125a0f741abf) atribute and implements the following operators for enum flags:

| Operator | Name                   |
| -------- | ---------------------- |
| ^=       | Bitwise XOR assignment |
| &=       | Bitwise AND assignment |
| \|=      | Bitwise OR assignment  |
| +=       | Addition assignment    |
| -=       | Subtraction assignment |
| ^        | Bitwise XOR            |
| &        | Bitwise AND            |
| \|       | Bitwise OR             |
| +        | Addition               |
| -        | Subtraction            |
| ~        | Bitwise NOT            |

See [operators](https://en.cppreference.com/w/cpp/language/operators) for more information about operators.

The following code shows how to use [flags_attribute_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gaea49fae71107df8769685efb159c181a) helper.

```cpp
#include <xtd/xtd.core.h>

using namespace xtd;

enum class test_enum {
  value_one = 0,
  value_two = 1,
  value_three = 2,
  value_four = 4
};

flags_attribute(, test_enum);

template<> struct xtd::enum_register<test_enum> {
  explicit operator auto() const noexcept {return xtd::enum_collection<test_enum> {{test_enum::value_one, "value_one"}, {test_enum::value_two, "value_two"}, {test_enum::value_three, "value_three"}, {test_enum::value_four, "value_four"}};}
};

auto main()->int {
  auto value = test_enum::value_two | test_enum::value_three;
  console::write_line("value = {}", value);
}
```

output:

```
value = value_two, value_three
```

#### Warning

The [flags_attribute_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gaea49fae71107df8769685efb159c181a) helper has one limitiation :

* The enum's flags cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enum flags is in a class or struct, add operators manually and use [xtd::enum_set_attribute](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga21077f4832fc4718f7095d1a560a89cd) to register the [xtd::enum_attribute::flags](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#gga21077f4832fc4718f7095d1a560a89cda4e5868d676cb634aa75b125a0f741abf) attribute.

## Format

You can use the [xtd::enum_object::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1enum__object.html#a7e0bc388bc8f4ec019e586fb2e5ad998) method to create a new string object that represents the numeric, hexadecimal, or string value of an enumeration member. This method takes one of the enumeration formatting strings to specify the value that you want returned.

See [Enumeraton format strings](https://github.com/gammasoft71/xtd/blob/master/docs/format_enumeration_format_strings.md) for more information about enum class format.

The following code shows how to use `enum class` with format.

```cpp
#include <xtd/xtd>

using namespace xtd;

enum class week_day {
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday,
  sunday
};

template<> struct xtd::enum_register<week_day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<week_day> {{week_day::monday, "monday"}, {week_day::tuesday, "tuesday"}, {week_day::wednesday, "wednesday"}, {week_day::thursday, "thursday"}, {week_day::friday, "friday"}, {week_day::saturday, "saturday"}, {week_day::sunday, "sunday"}};}
};

auto main()->int {
  console::write_line("{}", week_day::saturday);
  console::write_line("0b{:b}", week_day::saturday);
  console::write_line("0b{:B}", week_day::saturday);
  console::write_line("{:d}", week_day::saturday);
  console::write_line("{:D}", week_day::saturday);
  console::write_line("{:g}", week_day::saturday);
  console::write_line("{:G}", week_day::saturday);
  console::write_line("0{:o}", week_day::saturday);
  console::write_line("0{:O}", week_day::saturday);
  console::write_line("0x{:x}", week_day::saturday);
  console::write_line("0x{:X}", week_day::saturday);
}
```

output:

```
saturday
0b101
0b101
5
5
saturday
saturday
05
05
0x5
0x5
```

### Note
  xtd can display a string representing a member of an `enum class` as long as it is registered. If it is not registered then the numeric value will be displayed.

## Parse

To parse an `enum class` with xtd, the enum class must be registered.

The folowwing example shows how to parse an `enum class` with [xtd::enum_object::parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1enum__object_3_01std_1_1nullptr__t_01_4.html#a159422352085070f5d77c6f814e68693) method.

```cpp
#include <xtd/xtd>

using namespace xtd;

enum class enum_test {
  value_one,
  value_two,
  value_three,
  value_four
};

template<> struct xtd::enum_register<enum_test> {
  explicit operator auto() const noexcept {return xtd::enum_collection<enum_test> {{enum_test::value_one,  "value_one"}, {enum_test::value_two,  "value_two"}, {enum_test::value_three,  "value_three"}, {enum_test::value_four,  "value_four"}};}
};

auto main()->int {
  console::write_line("result = {}", enum_object<>::parse<enum_test>("value_two"));
  console::write_line("result = {}", enum_object<>::parse<enum_test>("VaLuE_fOuR", true));
  try {
    console::write_line("result = {}", enum_object<>::parse<enum_test>("value_five"));
  } catch(const xtd::system_exception& e) {
    console::write_line("enum_test::value_five does not exists!");
  }

  enum_test result;
  if (enum_object<>::try_parse<enum_test>("value_three", result)) console::write_line("result = {}", result);
  if (enum_object<>::try_parse<enum_test>("vAlUe_OnE", true, result)) console::write_line("result = {}", result);
  if (enum_object<>::try_parse<enum_test>("value_six", result)) console::write_line("result = {}", result);
  else console::write_line("enum_test::value_six does not exists!");
}
```

Output :

```
result = value_two
result = value_four
enum_test::value_five does not exists!
result = value_three
result = value_one
enum_test::value_six does not exists!
```

## Introspection

Registering an `enum`, `enum class` or an `enum struct` is unfortunately verbose. 

There are some introspection helpers in xtd to facilitate the work:

* [enum_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga6c6a896cbec833fa1fac13b700cf8691)
* [enum_ut_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gabe13d52c924723772f27878f606210cd)
* [enum_class_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gade4794e2743558ee1eb5bbad10c7f6d4)
* [enum_class_ut_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga6918e267c2970d28460e6c42a3b03f4a)
* [enum_struct_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga85a4f5366ae461ca1e20872d39a0b440)
* [enum_struct_ut_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga341342381ae697a142233d256948df84)

### Warning

The introspection helpers have one limitiation :

* The enumeration cannot be in a class or struct. The enumeration must be in the global namespace or in a namespace hierarchy. If the enumumeration is in a class or struct, add operators manually and use [xtd::enum_register](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1enum__register.html) to register the enumeration.

### enum_

This helper provides the registration struct for `enum`.

Thr following example shows how to use [enum_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga6c6a896cbec833fa1fac13b700cf8691) helper.

```cpp
#include <xtd/xtd>

using namespace xtd;

enum_(, enum_test,
  value_one,
  value_two,
  value_three,
  value_four
);

auto main()->int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_int32());
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<enum_test>());
}

// This code produces the following output :
//
// name = value_four
// value = 3
// as<int> = 3
// values = [0, 1, 2, 3]
// names = [value_one, value_two, value_three, value_four]
// entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

### enum_ut_

This helper provides the registration struct for `enum` with specified underlying type.

Thr following example shows how to use [enum_ut_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gabe13d52c924723772f27878f606210cd) helper.

```cpp
#include <xtd/xtd>

using namespace xtd;

enum_ut_(, enum_test, byte,
  value_one,
  value_two,
  value_three,
  value_four
);

auto main()->int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_byte());
  console::write_line("as<byte> = {}", as<byte>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<enum_test>());
}

// This code produces the following output :
//
// name = value_four
// value = 3
// as<byte> = 3
// values = [0, 1, 2, 3]
// names = [value_one, value_two, value_three, value_four]
// entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

### enum_class_

This helper provides the registration struct for `enum class`.

Thr following example shows how to use [enum_class_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gade4794e2743558ee1eb5bbad10c7f6d4) helper.

```cpp
#include <xtd/xtd>

using namespace xtd;

enum_class_(, enum_test,
  value_one,
  value_two,
  value_three,
  value_four
);

auto main()->int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_int32());
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<enum_test>());
}

// This code produces the following output :
//
// name = value_four
// value = 3
// as<int> = 3
// values = [0, 1, 2, 3]
// names = [value_one, value_two, value_three, value_four]
// entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

### enum_class_ut_

This helper provides the registration struct for `enum class` with specified underlying type.

Thr following example shows how to use [enum_class_ut_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga6918e267c2970d28460e6c42a3b03f4a) helper.

```cpp
#include <xtd/xtd>

using namespace xtd;

enum_class_ut_(, enum_test, byte,
  value_one,
  value_two,
  value_three,
  value_four
);

auto main()->int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_byte());
  console::write_line("as<byte> = {}", as<byte>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<enum_test>());
}

// This code produces the following output :
//
// name = value_four
// value = 3
// as<byte> = 3
// values = [0, 1, 2, 3]
// names = [value_one, value_two, value_three, value_four]
// entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

### enum_struct_

This helper provides the registration struct for `enum struct`.

Thr following example shows how to use [enum_struct_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga85a4f5366ae461ca1e20872d39a0b440) helper.

```cpp
#include <xtd/xtd>

using namespace xtd;

enum_class_(, enum_test,
  value_one,
  value_two,
  value_three,
  value_four
);

auto main()->int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_int32());
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<enum_test>());
}

// This code produces the following output :
//
// name = value_four
// value = 3
// as<int> = 3
// values = [0, 1, 2, 3]
// names = [value_one, value_two, value_three, value_four]
// entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

### enum_struct_ut_

This helper provides the registration struct for `enum struct` with specified underlying type.

Thr following example shows how to use [enum_struct_ut_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga341342381ae697a142233d256948df84) helper.

```cpp
#include <xtd/xtd>

using namespace xtd;

enum_struct_ut_(, enum_test, byte,
  value_one,
  value_two,
  value_three,
  value_four
);

auto main()->int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_byte());
  console::write_line("as<byte> = {}", as<byte>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<enum_test>());
}

// This code produces the following output :
//
// name = value_four
// value = 3
// as<byte> = 3
// values = [0, 1, 2, 3]
// names = [value_one, value_two, value_three, value_four]
// entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/custom-timespan-format-strings)
