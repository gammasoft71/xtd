| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Types in xtd

* By design xtd has defined its own types which are only ever aliases to the [fixed integer types of c++](https://en.cppreference.com/w/cpp/types/integer).
* You are not obliged to use the xtd types, you are even encouraged to use the standard types or those you want.
* The xtd defines `unboxed` and `boxed` types listed below. The `unboxed` types is same as the native type. The `boxed` type is an [xtd::box](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box.html) inherited from [xtd::object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html).

## Remarks

For more performance prefere used `unboxed` type. Used `boxed` type when necessary, e.g., to parse, polymorphism, ...

## Types list

| Unboxed type                                                                                                    | Boxed type                                                                                                        | C++11 type        | C++ standard type                              | Size in bytes    | Value                                                                         |
| --------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------- | ----------------- | ---------------------------------------------- | ---------------- | ----------------------------------------------------------------------------- |
| bool                                                                                                            | [xtd::boolean_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga020fbeceaf011505de3ac30168375664) | bool              | bool                                           | 1                | Represents a boolean value.                                                   |
| char                                                                                                            | [xtd::char_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaa1de2ea24769d6024df6172bd9355575)    | char              | char                                           | 1                | Represents a characters.                                              |
| [xtd::char8](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga1259090c8918e75847a8cb2a64b8912a)         | [xtd::char8_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga7852d6b3b5f17dbe722a606cd06a1bce)   | char8_t           | char                                           | 1                | Represents a unicode characters.                                              |
| [xtd::char16](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga39d5c4947c807e5f78b8a9abe3692570)        | [xtd::char16_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga0ff1609eee070b97921316138e506ec9)  | char16_t          | short                                          | 2                | Represents a unicode characters.                                              |
| [xtd::char32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga989a1148b6ff15567dca430966b17c92)        | [xtd::char32_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga7f4267b36e2ac25a835ea91593bd0a2d)  | char32_t          | int                                            | 4                | Represents a unicode characters.                                              |
| [xtd::wchar](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga442d09ba9c8530e03cd30e729738e0fa)         | [xtd::wchar_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga60f9b7c5831e5f533c5f5a6b35e22478)   | wchar_t           | short - or - int *(1)*                         | 2 - or - 4 *(1)* | Represents a unicode characters.                                              |
| [xtd::byte](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gabb9d3031d62e3725b4265c7e5d2a98e1)          | [xtd::byte_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga3fc22386b24ad6ba85daeff85cb79661)    | uint_least8_t     | unsigned char                                  | 1                | Represents a 8-bit unsigned integer.                                          |
| [xtd::int16](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga09d26135a9af4f7a5f4cae382627d6d1)         | [xtd::int16_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga9b68e8829910e613dac8a6148477ad7c)   | int_least16_t     | short                                          | 2                | Represents a 16-bit signed integer.                                           |
| [xtd::int32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga205462e259a4eca1545511085c2c350e)         | [xtd::int32_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga4be46d51c646a03427dc92e2bf35cd38)   | int_least32_t     | int                                            | 4                | Represents a 32-bit signed integer.                                           |
| [xtd::int64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga2f2888f55e58cac4c07eb490db7868c4)         | [xtd::int64_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga6186e201158c8307f663ac4d00466b86)   | int_least64_t     | long long.                                     | 8                | Represents a 64-bit signed integer.                                           |
| [xtd::intptr](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga9afc9e1ad3e9f8aba95c76280be5e16e)        | [xtd::intptr_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga9745a7872319ad41c528993da735ad1f)  | intmax_t          | int* - or - long long* *(2)*                   | 4 - or - 8 *(2)* | Represent a pointer or a handle.                                              |
| [xtd::sbyte](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga37e983ceedf5a7f73bc4568eaeae0aa2)         | [xtd::sbyte_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaf42f67c02d59e5180de4a25c387c4ce7)   | int_least8_t      | char                                           | 1                | Represents a 8-bit signed integer.                                            |
| [xtd::uint16](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gad8523b51611f0fac793f78f16b155b21)        | [xtd::uint16_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gad2d2369e4e7ed6c9add6ed934441941b)  | uint_least16_t    | unsigned short                                 | 2                | Represents a 16-bit unsigned integer.                                         |
| [xtd::uint32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga41c5d8b5d999ac5a2ff06fe57f38d5f5)        | [xtd::uint32_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaf4dd9a26c2e1c77bc7ea42452ba0794f)  | uint_least32_t    | unsigned int                                   | 4                | Represents a 32-bit unsigned integer.                                         |
| [xtd::uint64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gab5833228ed21371660af349c9b1fe797)        | [xtd::uint64_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gae01c8c184846ba16e80a4c5af471be3b)  | uint_least64_t    | unsigned long long                             | 8                | Represents a 64-bit unsigned integer.                                         |
| [xtd::uintptr](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga4393f509bf08c7e4ad25357e80f3ffff)       | [xtd::uintptr_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga35c697da631eefc57a902da5ccc07e68) | uintmax_t         | unsigned int* - or - unsigned long long* *(2)* | 4 - or - 8 *(2)* | Represent an unsigned pointer or a handle.                                    |
| float                                                                                                           | [xtd::single_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga84ac56442074e9ba86390626d8f83b7b)  | float             | float                                          | 4                | Represents a single-precision floating-point number.                          |
| double                                                                                                          | [xtd::double_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga9c0f11ebf71e3121a21e785a0c97c99d)  | double            | double                                         | 8                | Represents a double-precision floating-point number.                          |
| [xtd::decimal](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga1f5ab1e551070e04d6450399622c6f29) *(3)* | [xtd::decimal_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga19d2fddd55b417489b4cf929a40a293e) | long double *(3)* | long double *(3)*                              | 8 - or -16 *(3)* | Represents a double-precision floating-point number.                          |
| [xtd::size](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga92c4f59ae39104d31ce9c0c20810001d)          | [xtd::size_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga38c2e723413a561059a0c53c07f167af)    | size_t            | result of the sizeof operator *(2)*            | 4 - or - 8 *(2)* | Represent an unsigned pointer or a handle.                                    |
| [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html)                              | [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html)                                | /                 | /                                              | 8                | Represents an instant in time, typically expressed as a date and time of day. |
| const char*                                                                                                     | [xtd::ustring](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1ustring.html)                                     | std::string       | std::string *(4)*                              | variable         | Represents text as a series of unicode characters.                            |

*(1) Depend of OS : if build on Windows is 2 bytes, if build on Linux or many other non-Windows systems is 4 bytes.*

*(2) Depend of build : if build in 32 bits the size is 4 bytes, if build in 64 bits the size is 8 bytes.*

*(3) [xtd::decimal](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga1f5ab1e551070e04d6450399622c6f29) is an extended precision floating-point type. 
Matches [IEEE-754 binary128 format](https://en.wikipedia.org/wiki/Extended_precision) if supported, otherwise matches IEEE-754 binary64-extended format if supported, 
otherwise matches some non-IEEE-754 extended floating-point format as long as its precision is better than binary64 and range is at least as good as binary64,
otherwise matches IEEE-754 binary64 format.*
  
* *binary128 format is used by some HP-UX, SPARC, MIPS, ARM64, and z/OS implementations.*
* *The most well known IEEE-754 binary64-extended format is 80-bit x87 extended precision format. It is used by many x86 and x86-64 implementations (a notable exception is MSVC, which implements `long double` in the same format as `double`, i.e. binary64).*

*(4) The std::string type is the main string datatype in standard C++ since 1998, but it was not always part of C++98.*

For more information about c++ type see [cppreference language type](https://en.cppreference.com/w/cpp/language/types) section.

For the complete list of xtd types see [xtd - Referecne Guide - types](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html) section.

## Limits

xtd define the minimum and maximum constant value for each types.

|Type                                                                                                               | Minimum Value                      | Maximum Value                       | Minimum Value             | Maximum Value               |
| ----------------------------------------------------------------------------------------------------------------- | ---------------------------------- | ----------------------------------- | ------------------------- | --------------------------- |
| [xtd::boolean_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga020fbeceaf011505de3ac30168375664) | [xtd::boolean_object::min_value]() | [xtd::boolean_object::man_value]()  | false                     | true                        |
| [xtd::byte_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga3fc22386b24ad6ba85daeff85cb79661)    | [xtd::byte_object::min_value]()    | [xtd::byte_object::max_value]()     | 0                         | 255                         |
| [xtd::int16_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga9b68e8829910e613dac8a6148477ad7c)   | [xtd::int16_object::min_value]()   | [xtd::int16_object::int16_object]() | -32768                    | 32767                       |
| [xtd::int32_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga4be46d51c646a03427dc92e2bf35cd38)   | [xtd::int32_object::min_value]()   | [xtd::int32_object::max_value]()    | -2147483648               | 2147483647                  |
| [xtd::int64_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga6186e201158c8307f663ac4d00466b86)   | [xtd::int64_object::min_value]()   | [xtd::int64_object::max_value]()    | -9223372036854775808      | 9223372036854775807         |
| [xtd::sbyte_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaf42f67c02d59e5180de4a25c387c4ce7)   | [xtd::sbyte_object::min_value]()   | [xtd::sbyte_object::max_value]()    | -128                      | 127                         |
| [xtd::uint16_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gad2d2369e4e7ed6c9add6ed934441941b)  | [xtd::uint16_object::min_value]()  | [xtd::uint16_object::max_value]()   | 0                         | 65535                       |
| [xtd::uint32_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaf4dd9a26c2e1c77bc7ea42452ba0794f)  | [xtd::uint32_object::min_value]()  | [xtd::uint32_object::max_value]()   | 0                         | 4294967295                  |
| [xtd::uint64_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gae01c8c184846ba16e80a4c5af471be3b)  | [xtd::uint64_object::min_value]()  | [xtd::uint64_object::max_value]()   | 0                         | 18446744073709551615        |
| [xtd::single_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga84ac56442074e9ba86390626d8f83b7b)  | [xtd::single_object::min_value]()  | [xtd::single_object::max_value]()   | -3.40282e+038f            | 3.40282e+038f               |
| [xtd::double_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga9c0f11ebf71e3121a21e785a0c97c99d)  | [xtd::double_object::min_value]()  | [xtd::double_object::max_value]()   | -1.79769e+308             | 1.79769e+308                |
| [xtd::decimal_object](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga19d2fddd55b417489b4cf929a40a293e) | [xtd::decimal_object::min_value]() | [xtd::decimal_object::max_value]()  | -1.79769e+308             | 1.79769e+308                |
| [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html)                                | [xtd::date_time::min_value]()      | [xtd::date_time::max_value]()       | 00:00:00, January 1, 0001 | 23:59:59, December 31, 9999 |

### Remarks

Of course, [std::numeric_limits](https://en.cppreference.com/w/cpp/types/numeric_limits) works for the types described above except for [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html).

## Boxing

For explicit boxing a type into corresponding object class use [xtd::boxing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga7352fcff0da12feb0aff421fc8c41d15) method. 
By default, the boxing implicit in the corresponding object is used.

```cpp
bool value_unboxed = true;
xtd::boolean_object value_boxed1 = value_unboxed;               // implicit
xtd::boolean_object value_boxed2 = xtd::boxing(value_unboxed);  // explicit
auto ready_boxed3 = xtd::boxing(value_unboxed);                 // explicit with auto is xtd::boolean_object type
```

## Unboxing

For explicit unboxing a object class into corresponding type use [xtd::unboxing](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#ga5aa911c016af5795d0482eefb481fcc9) method.
By default, the unboxing implicit in the corresponding type is used.

```cpp
xtd::boolean_object value_boxed = true;
bool value_unboxed1 = value_boxed;                 // implicit
bool value_unboxed2 = xtd::unboxing(value_boxed);  // explict
auto value_unboxed3 = xtd::unboxing(value_boxed);  // explict with auto is bool
```

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
