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

> [!WARNING]  
> C-style casts should be avoided. C++ style casts are checked by the compiler, whereas C style casts are not, and may fail at runtime.

## See also

* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
