# Type conversion in xtd

## In this article

* [Implicit conversion with the implicit operator](#implicit-conversion-with-the-implicit-operator)
* [Explicit conversion with the explicit operator](#explicit-conversion-with-the-explicit-operator)
* [The convert class](#the-convert-class)
* [The convert_pointer class](#the-convert_pointer-class)
* [The convert_string class](#the-convert_string-class)
* [The as operators](#the-as-operators)
* [See also](#see-also)

Every value has an associated type, which defines attributes such as the amount of space allocated to the value, the range of possible values it can have, and the members that it makes available. Many values can be expressed as more than one type. For example, the value 4 can be expressed as an integer or a floating-point value. Type conversion creates a value in a new type that is equivalent to the value of an old type, but does not necessarily preserve the identity (or exact value) of the original object.

The xtd automatically supports the following conversions:

* Conversion from a derived class to a base class. This means, for example, that an instance of any class or structure of xtd can be converted to an [xtd::object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html) instance. This conversion does not require a casting or conversion operator.
* Conversion from a base class back to the original derived class. In xtd, this conversion requires a casting operator. (see [static_cast](https://en.cppreference.com/w/cpp/language/static_cast), [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast), [reinterpret_cast](https://en.cppreference.com/w/cpp/language/explicit_cast), and [as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga09e01287b655c20807cdb73d993ba13d) for more informations)
* Conversion from a type that implements an interface to an interface object that represents that interface. This conversion does not require a casting or conversion operator.
* Conversion from an interface object back to the original type that implements that interface. In xtd, this conversion requires a casting operator. (see [static_cast](https://en.cppreference.com/w/cpp/language/static_cast), [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast), [reinterpret_cast](https://en.cppreference.com/w/cpp/language/explicit_cast), and [as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga09e01287b655c20807cdb73d993ba13d) for more informations)
* Conversion from a const object to the same non const object. In xtd, this conversion requires a casting operator. (see [const_cast](https://en.cppreference.com/w/cpp/language/const_cast) for more informations)

> **Warning**
> C-style casts should be avoided. C++ style casts are checked by the compiler, whereas C style casts are not, and may fail at runtime.

In addition to these automatic conversions, C++ and xtd provide several features that support custom type conversion. These include the following:

* The `Implicit` operator, which defines the available widening conversions between types. For more information, see the [Implicit Conversion with the Implicit Operator](#) section.
* The `Explicit` operator, which defines the available narrowing conversions between types. For more information, see the [Explicit Conversion with the Explicit Operator](#) section.
* The [convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class, which provides a set of methods for converting types. For more information, see [The convert Class](#) section.
* The [convert_pointer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__pointer.html) class, which provides a set of methods for converting pointers. For more information, see [The convert_pointer Class](#) section.
* The [convert_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__string.html) class, which provides a set of methods for converting strings. For more information, see [The convert_string Class](#) section.
* The [as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga09e01287b655c20807cdb73d993ba13d) operators, which provides a set of methods for converting types, pointers or strings. For more information, see [The as Operator](#) section.

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

## Explicit conversion with the explicit operator

Narrowing conversions involve the creation of a new value from the value of an existing type that has either a greater range or a larger member list than the target type. Because a narrowing conversion can result in a loss of data, compilers often require that the conversion be made explicit through a call to a conversion method or a casting operator. That is, the conversion must be handled explicitly in developer code.

> **Notes**
> The major purpose of requiring a conversion method or casting operator for narrowing conversions is to make the developer aware of the possibility of data loss or an [overflow_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1overflow__exception.html) so that it can be handled in code. However, some compilers can relax this requirement.

For example, the [uint32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gae7af83eab478757e17f0eb7af57571df), [int64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga7ab879ebcae19d6021222f00537cfdce), and [uint64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gae1d338ada567eb17107e17cbffea5320) data types have ranges that exceed that the [int32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga92bf6d527cbcada4a30faa2efd0d6a91) data type, as the following table shows.

| Type                                                                                                                     |	Comparison with range of int32                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| ------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| [int64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga7ab879ebcae19d6021222f00537cfdce)  | [int64_object::max_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#a21847edbb248c1b0d07a35e2a8c08232) is greater than [int32_object::max_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#a21847edbb248c1b0d07a35e2a8c08232), and [int64_object::min_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#abacf9950b09d5d214dcfa6205559785d) is less than (has a greater negative range than) [int32_object::min_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#abacf9950b09d5d214dcfa6205559785d). |
| [uint32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gae7af83eab478757e17f0eb7af57571df) | [uint32_object::max_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#a21847edbb248c1b0d07a35e2a8c08232) is greater than [int32_object::max_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#a21847edbb248c1b0d07a35e2a8c08232).                                                                                                                                                                                                                                                                                                                                                                |
| [uint64](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gae1d338ada567eb17107e17cbffea5320) | [uint64_object::max_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#a21847edbb248c1b0d07a35e2a8c08232) is greater than [int32_object::max_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#a21847edbb248c1b0d07a35e2a8c08232).                                                                                                                                                                                                                                                                                                                                                                |

To handle these restrictive conversions, xtd allows types to define an explicit operator. A member of the [convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class can be called to perform the conversion. (For more information on the [convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class, see [The Convert class](#) later in this section). The following example illustrates the use of language features to manage the explicit conversion of these potentially out-of-range integer values into [int32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga92bf6d527cbcada4a30faa2efd0d6a91) values.

```cpp
long number1 = int32_object::max_value + 20L;
uint number2 = int32_object::max_value - 1000;
ulong number3 = int32_object::max_value;

int int_number;

try {
  int_number = as<int>(number1);
  console::write_line("After assigning a {0} value, the Integer value is {1}.",
                      typeof_(number1).name(), int_number);
} catch (const overflow_exception& e) {
  if (number1 > int32_object::max_value)
    console::write_line("Conversion failed: {0} exceeds {1}.",
                        number1, int32_object::max_value);
  else
    console::write_line("Conversion failed: {0} is less than {1}.",
                        number1, int32_object::min_value);
}

try {
  int_number = as<int>(number2);
  console::write_line("After assigning a {0} value, the Integer value is {1}.",
                      typeof_(number2).name(), int_number);
} catch (const overflow_exception& e) {
  console::write_line("Conversion failed: {0} exceeds {1}.",
                      number2, int32_object::max_value);
}

try {
  int_number = as<int>(number3);
  console::write_line("After assigning a {0} value, the Integer value is {1}.",
                      typeof_(number3).name(), int_number);
} catch (const overflow_exception& e) {
  console::write_line("Conversion failed: {0} exceeds {1}.",
                      number1, int32_object::max_value);
}

// The example displays the following output:
//    Conversion failed: 2147483667 exceeds 2147483647.
//    After assigning a unsigned int value, the Integer value is 2147482647.
//    After assigning a unsigned long value, the Integer value is 2147483647.
```

> **Notes**
> The explicit [as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga09e01287b655c20807cdb73d993ba13d) cast of xtd, unlike the [static_cast](https://en.cppreference.com/w/cpp/language/static_cast) of std, generates an [overflow_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1overflow__exception.html) exception in the event of overflow.

The following example uses the  [as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga09e01287b655c20807cdb73d993ba13d) and [static_cast](https://en.cppreference.com/w/cpp/language/static_cast) cast operators to illustrate the difference in behavior when a value outside the range of a [byte](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gabb9d3031d62e3725b4265c7e5d2a98e1) is converted to a [byte](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gabb9d3031d62e3725b4265c7e5d2a98e1). The [as](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga09e01287b655c20807cdb73d993ba13d) conversion throws an exception, but the [static_cast](https://en.cppreference.com/w/cpp/language/static_cast) conversion assigns [byte_object::max_value](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box__integer.html#a21847edbb248c1b0d07a35e2a8c08232) to the [byte](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gabb9d3031d62e3725b4265c7e5d2a98e1) variable.

```cpp
int large_value = int32_object::max_value;
byte new_value;

try {
  new_value = static_cast<byte>(large_value);
  console::write_line("Converted the {0} value {1} to the {2} value {3}.",
                      typeof_(large_value).name(), large_value,
                      typeof_(new_value).name(), new_value);
} catch (const overflow_exception& e) {
  console::write_line("{0} is outside the range of the byte data type.",
                      large_value);
}

try {
  new_value = as<byte>(large_value);
  console::write_line("Converted the {0} value {1} to the {2} value {3}.",
                      typeof_(large_value).name(), large_value,
                      typeof_(new_value).name(), new_value);
} catch (const overflow_exception& e) {
  console::write_line("{0} is outside the range of the byte data type.",
                      large_value);
}
// The example displays the following output:
//    Converted the int value 2147483647 to the unsigned char value 255.
//    2147483647 is outside the range of the byte data type.
```

## The convert class

Although each base type's can be called to perform a type conversion, calling the methods of the [xtd::convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class is the recommended way to convert from one base type to another.

### Conversions between base types

The [convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class provides a way to perform conversions between base types. It provides a complete set of methods for both widening and narrowing conversions, and throws an [invalid_cast_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__cast__exception.html) for conversions that are not supported (such as the conversion of a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value to an integer value). Narrowing conversions are performed in a checked context, and an [overflow_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1overflow__exception.html) is thrown if the conversion fails.

The following example illustrates the use of the [xtd::convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class to perform several widening and narrowing conversions between base types.

```cpp
// Convert an int32 value to a decimal (a widening conversion).
int integral_value = 12534;
decimal decimal_value = convert::to_decimal(integral_value);
console::write_line("Converted the {0} value {1} to "
                    "the {2} value {3:N2}.",
                    typeof_(integral_value).name(),
                    integral_value,
                    typeof_(decimal_value).name(),
                    decimal_value);
// Convert a byte value to an int32 value (a widening conversion).
byte byte_value = byte_object::max_value;
int integral_value2 = convert::to_int32(byte_value);
console::write_line("Converted the {0} value {1} to "
                    "the {2} value {3:G}.",
                    typeof_(byte_value).name(),
                    byte_value,
                    typeof_(integral_value2).name(),
                    integral_value2);

// Convert a Double value to an Int32 value (a narrowing conversion).
double double_value = 16.32513e12;
try {
  long long_value = convert::to_int64(double_value);
  console::write_line("Converted the {0} value {1:E} to "
                      "the {2} value {3:N0}.",
                      typeof_(double_value).name(),
                      double_value,
                      typeof_(long_value).name(),
                      long_value);
} catch (const overflow_exception& e) {
  console::write_line("Unable to convert the {0:E} value {1}.",
                      typeof_(double_value).name(), double_value);
}

// Convert a signed byte to a byte (a narrowing conversion).
sbyte sbyte_value = -16;
try {
  byte byte_value2 = convert::to_byte(sbyte_value);
  console::write_line("Converted the {0} value {1} to "
                      "the {2} value {3:G}.",
                      typeof_(sbyte_value).name(),
                      sbyte_value,
                      typeof_(byte_value2).name(),
                      byte_value2);
} catch (const overflow_exception& e) {
  console::write_line("Unable to convert the {0} value {1}.",
                      typeof_(sbyte_value).name(), sbyte_value);
}
// The example displays the following output:
//       Converted the int value 12534 to the long double value 12534.00.
//       Converted the unsigned char value 255 to the int value 255.
//       Converted the double value 1.632513E+13 to the long value 16325130000000.
//       Unable to convert the signed char value -16.
```

In some cases, particularly when converting to and from floating-point values, a conversion may involve a loss of precision, even though it does not throw an [overflow_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1overflow__exception.html). The following example illustrates this loss of precision. In the first case, a [decimal](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga255b88769d29fe91661cacc7720f265a) value has less precision (fewer significant digits) when it is converted to a [double](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gac9b7afa2262ed23eae6787dea92d733e). In the second case, a [double]https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gac9b7afa2262ed23eae6787dea92d733e) value is rounded from 42.72 to 43 in order to complete the conversion.

```cpp
  double double_value;
  
  // Convert a Double to a Decimal.
  decimal decimal_value = 13956810.96702888123451471211;
  double_value = convert::to_double(decimal_value);
  console::write_line("{0} converted to {1}.", decimal_value, double_value);
  
  double_value = 42.72;
  try {
    int integerValue = convert::to_int32(double_value);
    console::write_line("{0} converted to {1}.",
                        double_value, integerValue);
  } catch (const overflow_exception& e) {
    console::write_line("Unable to convert {0} to an integer.",
                        double_value);
  }
  // The example displays the following output:
  //       13956810.9670289 converted to 13956810.9670289.
  //       42.72 converted to 43.
```

For a table that lists both the widening and narrowing conversions supported by the [convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class, see [Type conversion tables](/docs/documentation/Guides/xtd.core/Types%20overview/Type%20conversion/type_conversion_tables).

## The convert_pointer class

Although the [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast), [static_cast](https://en.cppreference.com/w/cpp/language/static_cast) ou [reinterpret_cast](https://en.cppreference.com/w/cpp/language/explicit_cast) can be called to perform pointer conversion, calling the methods of the [xtd::convert_pointer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class is the recommended method for converting one pointer into another.

The following example illustrates the use of the [xtd::convert_pointer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__pointer.html) class to perform several widening and narrowing conversions between [shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr).

```cpp
shared_ptr<object> object_ptr = make_shared<ustring>("string");

shared_ptr<ustring> string_ptr = convert_pointer::to_shared_ptr<ustring>(object_ptr);
console::write_line("Converted the {0} value \"{1}\" to "
                    "the {2} value \"{3}\".",
                    typeof_(object_ptr).name(),
                    *object_ptr,
                    typeof_(string_ptr).name(),
                    *string_ptr);

try {
  shared_ptr<date_time> date_time_ptr = convert_pointer::to_shared_ptr<date_time>(object_ptr);
  console::write_line("Converted the {0} value \"{1}\" to "
                      "the {2} value \"{3}\".",
                      typeof_(object_ptr).name(),
                      *object_ptr,
                      typeof_(date_time_ptr).name(),
                      *date_time_ptr);
} catch (const invalid_cast_exception& e) {
  console::write_line("Unable to convert the {0} value \"{1}\".",
                      typeof_(object_ptr).name(), *object_ptr);
}

// The example displays the following output:
//       Converted the shared_ptr<xtd::object> value "string" to the shared_ptr<xtd::ustring> value "string".
//       Unable to convert the shared_ptr<xtd::object> value "string".
```

The following example illustrates the use of the [xtd::convert_pointer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__pointer.html) class to perform several widening and narrowing conversions between [unqiue_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr).

```cpp
unique_ptr<object> object_ptr = make_unique<ustring>("string");

unique_ptr<ustring> string_ptr = convert_pointer::to_unique_ptr<ustring>(object_ptr);
console::write_line("Converted the {0} value \"{1}\" to "
                    "the {2} value \"{3}\".",
                    typeof_(object_ptr).name(),
                    "(null)",
                    typeof_(string_ptr).name(),
                    *string_ptr);

try {
  object_ptr = make_unique<ustring>("string");
  unique_ptr<date_time> date_time_ptr = convert_pointer::to_unique_ptr<date_time>(object_ptr);
  console::write_line("Converted the {0} value \"{1}\" to "
                      "the {2} value \"{3}\".",
                      typeof_(object_ptr).name(),
                      "(null)",
                      typeof_(date_time_ptr).name(),
                      *date_time_ptr);
} catch (const invalid_cast_exception& e) {
  console::write_line("Unable to convert the {0} value \"{1}\".",
                      typeof_(object_ptr).name(), *object_ptr);
}

// The example displays the following output:
//       Converted the unique_ptr<xtd::object> value "(null)" to the unique_ptr<xtd::ustring> value "string".
//       Unable to convert the unique_ptr<xtd::object> value "string".
```

The following example illustrates the use of the [xtd::convert_pointer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__pointer.html) class to perform several widening and narrowing conversions between pointers.

```cpp
object* object_ptr = new ustring("string");

ustring* string_ptr = convert_pointer::to_ptr<ustring>(object_ptr);
console::write_line("Converted the {0} to "
                    "the {1} value \"{2}\".",
                    typeof_(object_ptr).name(),
                    typeof_(string_ptr).name(),
                    *string_ptr);

delete string_ptr;

try {
  object_ptr =  new ustring("string");
  date_time* date_time_ptr = convert_pointer::to_ptr<date_time>(object_ptr);
  console::write_line("Converted the {0} to "
                      "the {1} value \"{2}\".",
                      typeof_(object_ptr).name(),
                      typeof_(date_time_ptr).name(),
                      *date_time_ptr);
} catch (const invalid_cast_exception& e) {
  console::write_line("Unable to convert the {0} value \"{1}\".",
                      typeof_(object_ptr).name(), *object_ptr);
}

delete object_ptr;

// The example displays the following output:
//       Converted the object* to the ustring* value "string".
//       Unable to convert the object* value "string".
```

The following example illustrates the use of the [xtd::convert_pointer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert__pointer.html) class to perform several widening and narrowing conversions between references.

```cpp
ustring value = "string";
object& object_ref = value;

ustring& string_ref = convert_pointer::to_ref<ustring>(object_ref);
console::write_line("Converted the {0} to "
                    "the {1} value \"{2}\".",
                    typeof_(object_ref).name(),
                    typeof_(string_ref).name(),
                    string_ref);

try {
  date_time& date_time_ref = convert_pointer::to_ref<date_time>(object_ref);
  console::write_line("Converted the {0} to "
                      "the {1} value \"{2}\".",
                      typeof_(object_ref).name(),
                      typeof_(date_time_ref).name(),
                      date_time_ref);
} catch (const invalid_cast_exception& e) {
  console::write_line("Unable to convert the {0} value \"{1}\".",
                      typeof_(object_ref).name(), object_ref);
}

// The example displays the following output:
//       Converted the ustring to the ustring value "string".
//       Unable to convert the ustring value "string".
```

## The convert_string class

## The as operators

## See also

* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
