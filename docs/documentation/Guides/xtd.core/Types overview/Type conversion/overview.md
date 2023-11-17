# Type conversion in xtd

## In this article

* [Implicit conversion with the implicit operator](#)
* [Explicit conversion with the explicit operator](#)
* [The IConvertible interface](#)
* [The Convert class](#)
* [The TypeConverter class](#)
* [See also](#see-also)

Every value has an associated type, which defines attributes such as the amount of space allocated to the value, the range of possible values it can have, and the members that it makes available. Many values can be expressed as more than one type. For example, the value 4 can be expressed as an integer or a floating-point value. Type conversion creates a value in a new type that is equivalent to the value of an old type, but does not necessarily preserve the identity (or exact value) of the original object.

The C++ automatically supports the following conversions:

* Conversion from a derived class to a base class. This means, for example, that an instance of any class or structure of xtd can be converted to an [xtd::object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html) instance. This conversion does not require a casting or conversion operator.
* Conversion from a base class back to the original derived class. In C++, this conversion requires a casting operator. (see [static_cast](https://en.cppreference.com/w/cpp/language/static_cast), [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast) and [reinterpret_cast](https://en.cppreference.com/w/cpp/language/explicit_cast) for more informations)
* Conversion from a type that implements an interface to an interface object that represents that interface. This conversion does not require a casting or conversion operator.
* Conversion from an interface object back to the original type that implements that interface. In C++, this conversion requires a casting operator. (see [static_cast](https://en.cppreference.com/w/cpp/language/static_cast), [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast) and [reinterpret_cast](https://en.cppreference.com/w/cpp/language/explicit_cast) for more informations)
* Conversion from a const object to the same non const object. In C++, this conversion requires a casting operator. (see [const_cast](https://en.cppreference.com/w/cpp/language/const_cast) for more informations)

> **Warning**
> C-style casts should be avoided. C++ style casts are checked by the compiler, whereas C style casts are not, and may fail at runtime.

In addition to these automatic conversions, C++ and xtd provide several features that support custom type conversion. These include the following:

* The `Implicit` operator, which defines the available widening conversions between types. For more information, see the [Implicit Conversion with the Implicit Operator](#) section.
* The `Explicit` operator, which defines the available narrowing conversions between types. For more information, see the [Explicit Conversion with the Explicit Operator](#) section.
* The [convert]() class, which provides a set of methods for converting types. For more information, see [The convert Class](#) section.
* The [convert_pointer]() class, which provides a set of methods for converting pointers. For more information, see [The convert_pointer Class](#) section.
* The [convert_string]() class, which provides a set of methods for converting strings. For more information, see [The convert_string Class](#) section.
* The [as]() operators, which provides a set of methods for converting types, pointers or strings. For more information, see [The as Operator](#) section.

## Implicit conversion with the implicit operator

Widening conversions involve the creation of a new value from the value of an existing type that has either a more restrictive range or a more restricted member list than the target type. Widening conversions cannot result in data loss (although they may result in a loss of precision). Because data cannot be lost, compilers can handle the conversion implicitly or transparently, without requiring the use of an explicit conversion method or a casting operator.

> **Notes**
> Although code that performs an implicit conversion can call a conversion method or use a casting operator, their use is not required by compilers that support implicit conversions.

For example, the [decimal](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga255b88769d29fe91661cacc7720f265a) type supports implicit conversions from [byte](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gaf8d0aa5786861bead085592c31c09849), [char](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga025f760e2ae1e3355f64174f10671484), [int16](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga159b2a409f2b3da8165af7a5e32eccf8), [int32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga92bf6d527cbcada4a30faa2efd0d6a91), [int64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga7ab879ebcae19d6021222f00537cfdce), [sbyte](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga3d6cac730aeed730136cd058c136edee), [uint16](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga7f48d085fbe8abdb92329be2bc04a236),[uint32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gae7af83eab478757e17f0eb7af57571df), and [uint64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gae1d338ada567eb17107e17cbffea5320) values. The following example illustrates some of these implicit conversions in assigning values to a [decimal](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga255b88769d29fe91661cacc7720f265a) variable.

```cpp
byte byte_value = 16;
short short_value = -1024;
int int_value = -1034000;
long long_value = 1152921504606846976;
ulong ulong_value = uint64_object::max_value;

decimal decimal_value;

decimal_value = byte_value;
console::write_line("After assigning a {} value, the decimal value is {}.",
                    typeof_(byte_value).name(), decimal_value);

decimal_value = short_value;
console::write_line("After assigning a {} value, the decimal value is {}.",
                    typeof_(short_value).name(), decimal_value);

decimal_value = int_value;
console::write_line("After assigning a {} value, the decimal value is {}.",
                    typeof_(int_value).name(), decimal_value);

decimal_value = long_value;
console::write_line("After assigning a {} value, the decimal value is {}.",
                    typeof_(long_value).name(), decimal_value);

decimal_value = ulong_value;
console::write_line("After assigning a {} value, the decimal value is {}.",
                    typeof_(ulong_value).name(), decimal_value);
// The example displays the following output:
//    After assigning a unsigned char value, the decimal value is 16.
//    After assigning a short value, the decimal value is -1024.
//    After assigning a int value, the decimal value is -1034000.
//    After assigning a long value, the decimal value is 1.15292150460685E+18.
//    After assigning a unsigned long value, the decimal value is 1.84467440737096E+19.
```


## See also

* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
