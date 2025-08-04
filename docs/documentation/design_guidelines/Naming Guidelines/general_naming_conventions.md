# General Naming Conventions

This section describes general naming conventions that relate to word choice, guidelines on using abbreviations and acronyms, and recommendations on how to avoid using c++ names.
 
## Word Choice
 
**✔️ DO** choose easily readable identifier names.
 
For example, a property named horizontal_alignment is more English-readable than alignment_horizontal.
 
**✔️ DO** favour readability over brevity.
 
The property name can_scroll_horizontally is better than scrollable_x (an obscure reference to the X-axis).
 
**❌ DO NOT** use hyphens, or any other non-alphanumeric characters except underscores.
 
**❌ DO NOT** use Hungarian notation.
 
**❌ AVOID** using identifiers that conflict with keywords of widely used programming languages.
 
## Using Abbreviations and Acronyms
 
**❌ DO NOT** use abbreviations or contractions as part of identifier names.
 
For example, use get_window rather than get_win.
 
**❌ DO NOT** use any acronyms that are not widely accepted, and even if they are, only when necessary.
 
## Avoiding C++ Names
 
**✔️ DO** use semantically interesting names rather than language-specific keywords for type names.
 
For example, get_length is a better name than get_int.
 
**✔️ DO** use a generic **cstdint** type name, rather than a C++ name, in the rare cases when an identifier has no semantic meaning beyond its type.
 
For example, a method converting to int64_t should be named to_int64, not to_long (because int64_t is a **cstdint** name for the c++ alias long long).

The following table presents several base data types using the **cstdint** type names (as well as the corresponding type names for all platform).

| C++                | cstdint     | xtd     | Size in bytes |
| ------------------ | ----------- | ------- | ------------- |
| char               | uint8_t     | sbyte   | 1             |
| unsigned char      | int8_t      | byte    | 1             |
| short              | int16_t     | int16   | 2             |
| unsigned short     | uint16_t    | uint16  | 2             |
| int                | int32_t     | int32   | 4             |
| unsigned int       | uint32_t    | uint32  | 4             |
| long long          | int64_t     | int64   | 8             |
| unsigned long long | uint64_t    | uint64  | 8             |
| float              | float       | float   | 4             |
| double             | double      | double  | 8             |
| long double        | long double | decimal | 16            |
| bool               | bool        | bool    | 1             |
| wchar_t            | wchar_t     | wcchar  | 4             |
| char*              | string      | string  | variable      |

**✔️ DO** use a common name, such as value or item, rather than repeating the type name, in the rare cases when an identifier has no semantic meaning and the type of the parameter is not important.

## Naming New Versions of Existing APIs

**✔️ DO** use a name similar to the old API when creating new versions of an existing API.

This helps to highlight the relationship between the APIs.

**✔️ DO** prefer adding a suffix rather than a prefix to indicate a new version of an existing API.

This will assist discovery when browsing documentation, or using Intellisense. The old version of the API will be organised close to the new APIs, because most browsers and Intellisense show identifiers in alphabetical order.

**✔️ CONSIDER** using a brand new, but meaningful identifier, instead of adding a suffix or a prefix.

**✔️ DO** use a numeric suffix to indicate a new version of an existing API, particularly if the existing name of the API is the only name that makes sense (i.e., if it is an industry standard) and if adding any meaningful suffix (or changing the name) is not an appropriate option.

**❌ DO NOT** use the "ex" (or a similar) suffix for an identifier to distinguish it from an earlier version of the same API.

**✔️ DO** use the "64" suffix when introducing versions of APIs that operate on a 64-bit integer (a long integer) instead of a 32-bit integer. You only need to take this approach when the existing 32-bit API exists; don’t do it for brand new APIs with only a 64-bit version.

## See also

* [Naming Guidelines](/docs/documentation/design_guidelines/Naming%20Guidelines)
* [Design Guidelines](/docs/documentation/design_guidelines)
* [Documentation](/docs/documentation)
