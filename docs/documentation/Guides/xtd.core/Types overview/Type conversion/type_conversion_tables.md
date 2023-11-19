# Type Conversion Tables in xtd

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

A narrowing conversion to Single or Double can cause a loss of information. If the target type cannot properly express the magnitude of the source, the resulting type is set to the constant PositiveInfinity or NegativeInfinity. PositiveInfinity results from dividing a positive number by zero and is also returned when the value of a Single or Double exceeds the value of the MaxValue field. NegativeInfinity results from dividing a negative number by zero and is also returned when the value of a Single or Double falls below the value of the MinValue field. A conversion from a Double to a Single might result in PositiveInfinity or NegativeInfinity.
A narrowing conversion can also result in a loss of information for other data types. However, an OverflowException is thrown if the value of a type that is being converted falls outside of the range specified by the target type's MaxValue and MinValue fields, and the conversion is checked by the runtime to ensure that the value of the target type does not exceed its MaxValue or MinValue. Conversions that are performed with the System.Convert class are always checked in this manner.
The following table lists conversions that throw an OverflowException using System.Convert or any checked conversion if the value of the type being converted is outside the defined range of the resulting type.

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
| Single  | Byte, SByte, Int16, UInt16, Int32, UInt32, Int64, UInt64 |
| Double  | Byte, SByte, Int16, UInt16, Int32, UInt32, Int64, UInt64 |

## See also
​
* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/conversion-tables)
