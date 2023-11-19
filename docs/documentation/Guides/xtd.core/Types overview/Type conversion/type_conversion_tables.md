# Type Conversion Tables in xtd

## In this article

* [Widening Conversions](#widening-conversions)
* [Narrowing Conversions](#narrowing-conversions)
* [See also](#see-also)

Widening conversion occurs when a value of one type is converted to another type that is of equal or greater size. A narrowing conversion occurs when a value of one type is converted to a value of another type that is of a smaller size. The tables in this topic illustrate the behaviors exhibited by both types of conversions.

## Widening Conversions

The following table describes the widening conversions that can be performed without the loss of information.

| Type   | Can be converted without data loss to                                |
| ------ | -------------------------------------------------------------------- |
| byte   | uint16, int16, uint32, int32, uint64, int64, single, double, decimal |
| sbyte  | int16, int32, int64, single, double, decimal                         |
| int16  | int32, int64, single, double, decimal                                |
| uint16 | uint32, int32, uint64, int64, single, double, decimal                |
| char   | uint16, uint32, int32, uint64, int64, single, double, decimal        |
| int32  | int64, double, decimal                                               |
| uint32 | int64, uint64, double, decimal                                       |
| int64  | decimal                                                              |
| uint64 | decimal                                                              |
| single | double                                                               |

Some widening conversions to single or double can cause a loss of precision. The following table describes the widening conversions that sometimes result in a loss of information.

| Type    | Can be converted to |
| ------- | ------------------- |
| int32   | single              |
| uint32  | single              |
| int64   | single, double      |
| uint64  | single, double      |
| decimal | single, double      |

## Narrowing Conversions

A narrowing conversion to single or double can cause a loss of information. If the target type cannot properly express the magnitude of the source, the resulting type is set to the constant `positive_infinity` or `negative_infinity`. `positive_infinity` results from dividing a positive number by zero and is also returned when the value of a single or double exceeds the value of the `max_value` field. `negative_infinity` results from dividing a negative number by zero and is also returned when the value of a single or double falls below the value of the `min_value` field. A conversion from a double to a single might result in `positive_infinity` or `negative_infinity`.
A narrowing conversion can also result in a loss of information for other data types. However, an OverflowException is thrown if the value of a type that is being converted falls outside of the range specified by the target type's `max_value` and `min_value` fields, and the conversion is checked by the runtime to ensure that the value of the target type does not exceed its `max_value` or `min_value`. Conversions that are performed with the [xtd::convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) class are always checked in this manner.
The following table lists conversions that throw an [overflow_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1overflow__exception.html) using [xtd::convert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1convert.html) or any checked conversion if the value of the type being converted is outside the defined range of the resulting type.

| Type    | Can be converted to                                      |
| ------- | -------------------------------------------------------- |
| Byte    | SByte                                                    |
| SByte   | Byte, UInt16, UInt32, UInt64                             |
| Int16   | Byte, SByte, UInt16                                      |
| UInt16  | Byte, SByte, Int16                                       |
| Int32   | Byte, SByte, Int16, UInt16,UInt32                        |
| UInt32  | Byte, SByte, Int16, UInt16, Int32                        |
| Int64   | Byte, SByte, Int16, UInt16, Int32,UInt32,UInt64          |
| UInt64  | Byte, SByte, Int16, UInt16, Int32, UInt32, Int64         |
| Decimal | Byte, SByte, Int16, UInt16, Int32, UInt32, Int64, UInt64 |
| single  | Byte, SByte, Int16, UInt16, Int32, UInt32, Int64, UInt64 |
| double  | Byte, SByte, Int16, UInt16, Int32, UInt32, Int64, UInt64 |

## See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/conversion-tables)
