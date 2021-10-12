| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Names of Classes, Structs and Interfaces

The naming guidelines that follow apply to general type naming.

**✔️ DO** name classes and structs with nouns or noun phrases, using use lower case only and digits, separate words with underscores.

This distinguishes type names from methods, which are named with verb phrases.

**✔️ DO** name interfaces with adjective phrases, or occasionally with nouns or noun phrases.

Nouns and noun phrases should be used rarely and they might indicate that the type should be an abstract class, and not an interface.

**❌ DO NOT** give class names a prefix (e.g., "C", "c").

**✔️ CONSIDER** ending the name of derived classes with the name of the base class.

This is very readable and explains the relationship clearly. Some examples of this in code are: argument_out_of_range_exception, which is a kind of exception, and serializable_attribute, which is a kind of attribute. However, it is important to use reasonable judgment in applying this guideline; for example, the button class is a kind of control event, although control doesn't appear in its name.

**✔️ DO** prefix interface names with the letter "i", to indicate that the type is an interface.

For example, icomponent (descriptive noun), icustom_attribute_provider (noun phrase), and ipersistable (adjective) are appropriate interface names. As with other type names, avoid abbreviations.

**✔️ DO** ensure that the names differ only by the "i" prefix on the interface name when you are defining a class–interface pair where the class is a standard implementation of the interface.

# Names of Generic Type Parameters

Generics (template) has identifier called type parameter.

**✔️ DO** name generic type parameters with descriptive names unless a single-letter name is completely self-explanatory and a descriptive name would not add value.

**✔️ CONSIDER** using type_t as the type parameter name for types with generic type parameter.

```c++
template<typename type_t>
class predicate : public deletegate<bool(type_t)> {
  ...
};
```

```c++
template<typename type_t = object>
struct nullable : public type_t {
  ...
};
```

**✔️ DO** postfix descriptive type parameter names with _t.

```c++
template<typename session_t = isession>
class isession_channel interface_ {
  virtual session_t get_session() = 0;
};
```

**✔️ CONSIDER** indicating constraints placed on a type parameter in the name of the parameter.

For example, a parameter constrained to isession might be called session_t.

# Names of Common Types

**✔️ DO** follow the guidelines described in the following table when naming types derived from or implementing certain xtd Framework types.

| Base Type               | Derived/Implementing Type Guideline                                                                |
|-------------------------|----------------------------------------------------------------------------------------------------|
| xtd::delegate           | **✔️ DO** add the suffix "_event_handler" to names of delegates that are used in events.            |
| xtd::delegate           | **✔️ DO** add the suffix "_callback" to names of delegates other than those used as event handlers. |
| xtd::delegate           | **❌ DO NOT** add the suffix "_delegate" to a delegate.                                             |
| xtd::event_args         | **✔️ DO** add the suffix "_event_args".                                                             |
| xtd::event_handler      | **✔️ DO** add the suffix "_event_handler".                                                          |
| enum class              | **❌ DO NOT** add the suffix "_enum" or "_flag".                                                    |
| xtd::system_exception| **✔️ DO** add the suffix "_exception".                                                              |
| std::array              | **✔️ DO** add the suffix "_collection" for sequence container.                                     |
| std::vector             | **✔️ DO** add the suffix "_collection" for sequence container.                                     |
| std::deque              | **✔️ DO** add the suffix "_collection" for sequence container.                                     |
| std::forward_list       | **✔️ DO** add the suffix "_collection" for sequence container.                                     |
| std::list               | **✔️ DO** add the suffix "_collection" for sequence container.                                     |
| std::set                | **✔️ DO** add the suffix "_dictionary" for associative container.                                  |
| std::multiset           | **✔️ DO** add the suffix "_dictionary" for associative container.                                  |
| std::map                | **✔️ DO** add the suffix "_dictionary" for associative container.                                  |
| std::multimap           | **✔️ DO** add the suffix "_dictionary" for associative container.                                  |
| std::unordered_set      | **✔️ DO** add the suffix "_dictionary" for unordered associative container.                        |
| std::unordered_multiset | **✔️ DO** add the suffix "_dictionary" for unordered associative container.                        |
| std::unordered_map      | **✔️ DO** add the suffix "_dictionary" for unordered associative container.                        |
| std::unordered_multimap | **✔️ DO** add the suffix "_dictionary" for unordered associative container.                        |
| std::span               | **✔️ DO** add the suffix "_span".                                                                   |
| std::istream            | **✔️ DO** add the suffix "_stream".                                                                 |
| std::ostream            | **✔️ DO** add the suffix "_stream".                                                                 |
| std::iostream           | **✔️ DO** add the suffix "_stream".                                                                 |

# Naming Enumerations

Names of enumeration types (also called enums) in general should follow the standard type-naming rules (use lower case only and digits, separate words with underscores, etc.). However, there are additional guidelines that apply specifically to enums.

**✔️ DO** use a singular type name for an enumeration unless its values are bit fields.

**✔️ DO** use a plural type name for an enumeration with bit fields as values, also called flags enum.

**❌ DO NOT** use an "_enum" suffix in enum type names.

**❌ DO NOT** use "_flag" or "_flags" suffixes in enum type names.

**❌ DO NOT** use a prefix on enumeration value names (e.g., "ad" for ADO enums, "rtf" for rich text enums, etc.).

# See also
​
* [Naming Guidelines](naming_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
