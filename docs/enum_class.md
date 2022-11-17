| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Enum class

Enums and enum classes in c++11 have two problems:
* Displaying in a string the name of the enum value either for debugging or simply to qualify some values as for example in [xtd::drawing::color::name]().
* There is no flags attribute. You have to add the bitwise operators for each enum class. Additional problem to display in a string the names of the value.

## External libraries

Several external libraries solve theses problems with elegance. Here is a non-exhaustive list:

* [better_enums](https://github.com/aantron/better-enums)
* [enum.hpp](https://github.com/BlackMATov/enum.hpp)
* [magic_enum](https://github.com/Neargye/magic_enum)
* [nav](https://github.com/codeinred/nav)
* [wise_enum](https://github.com/quicknir/wise_enum)
* And probably still others...

But in the context of xtd, after testing these different external libraries, none of them have been retained for different reasons such as limitations, macros for the declaration of enums and others.

This does not prevent you, of course, from using them in your own projects. As xtd is non-intrusive, you can easily combine them with xtd and with some xtd enum class definitions (if the limitations of the library do not prevent this).

### Examples

* [magic_enum](https://github.com/Neargye/magic_enum)

The following code shows how to use `enum class` with magic_enum and xtd:

```c++
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

int main() {
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

```c++
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

int main() {
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

## xtd

Unlike some external libraries, xtd does not yet have enum class introspection. So you have to register the enum class with the class [xtd::enum_register](). 
The advantage is that it has no limitation and the disadvantage is that it is more verbose.

### Note

If in your own project you do not register your enum classes, there is no problem you can use them normally. 
But when you want to display the value of the enum class it will always be displayed as an integer and you can't do any parsing on it.

### Examples

The following code shows how to use `enum class` with xtd:

```c++
#include <xtd/xtd>

using namespace xtd;

enum class enum_test {
  value_one,
  value_two,
  value_three,
  value_four
};

template<> struct xtd::enum_register<enum_test> {
  void operator()(xtd::enum_collection<enum_test>& values) {values = {{enum_test::value_one,  "value_one"}, {enum_test::value_two,  "value_two"}, {enum_test::value_three,  "value_three"}, {enum_test::value_four,  "value_four"}};}
};

int main() {
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

### Format enum class

You can use the [xtd::enum_object::to_string](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1enum__object.html#a7e0bc388bc8f4ec019e586fb2e5ad998) method to create a new string object that represents the numeric, hexadecimal, or string value of an enumeration member. This method takes one of the enumeration formatting strings to specify the value that you want returned.

See [Enumeraton format strings](https://github.com/gammasoft71/xtd/blob/master/docs/format_enumeration_format_strings.md) for more information about enum class format.

#### Note
  xtd can display a string representing a member of an enum class as long as it is registered. If it is not registered then the numeric value will be displayed.

### Parse

**coming soon...**

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.

[comment]: <> (https://learn.microsoft.com/en-us/dotnet/standard/base-types/custom-timespan-format-strings)
