/// @file
/// @brief Contains xtd::bit_converter class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <vector>

#include "core_export.h"
#include "static.h"
#include "types.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Converts base data types to an std::vector of bytes, and an std::vector of bytes to base data types.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The xtd::bit_converter class helps manipulate value types in their fundamental form, as a series of bytes. A byte_t is defined as an 8-bit unsigned integer. The xtd::bit_converter class includes static methods to convert each of the primitive types to and from an std::vector of bytes, as the following table illustrates.
  /// | Type     | To byte_t conversion                                                      | From byte_t conversion                                                                                    |
  /// |----------|---------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|
  /// | bool     | xtd::bit_converter::get_bytes(bool)                                       | xtd::bit_converter::to_boolean(const std::vector< byte_t >&, int32_t)                                     |
  /// | char32_t | xtd::bit_converter::get_bytes(char32_t)                                   | xtd::bit_converter::to_char(const std::vector< byte_t >&, int32_t)                                        |
  /// | double   | xtd::bit_converter::get_bytes(double) - or - double_to_int64_bits(double) | xtd::bit_converter::to_double(const std::vector< byte_t >&, int32_t) - or - int64_bits_to_double(int64_t) |
  /// | int16_t  | xtd::bit_converter::get_bytes(int16_t)                                    | xtd::bit_converter::to_int16(const std::vector< byte_t >&, int32_t)                                       |
  /// | int32_t  | xtd::bit_converter::get_bytes(int32_t)                                    | xtd::bit_converter::to_int32(const std::vector< byte_t >&, int32_t)                                       |
  /// | int64_t  | xtd::bit_converter::get_bytes(int64_t)                                    | xtd::bit_converter::to_int64(const std::vector< byte_t >&, int32_t)                                       |
  /// | float    | xtd::bit_converter::get_bytes(float) - or - single_to_int32_bits(float)   | xtd::bit_converter::to_single(const std::vector< byte_t >&, int32_t) - or - int32_bits_to_single(int32_t) |
  /// | uint16_t | xtd::bit_converter::get_bytes(uint16_t)                                   | xtd::bit_converter::to_uint16(const std::vector< byte_t >&, int32_t)                                      |
  /// | uint32_t | xtd::bit_converter::get_bytes(uint32_t)                                   | xtd::bit_converter::to_uint32(const std::vector< byte_t >&, int32_t)                                      |
  /// | uint64_t | xtd::bit_converter::get_bytes(uint64_t)                                   | xtd::bit_converter::to_uint64(const std::vector< byte_t >&, int32_t)                                      |
  /// If you use bit_converter methods to round-trip data, make sure that the xtd::bit_converter::get_bytes overload and the to_<type> method specify the same type. As the following example illustrates, restoring an std::vector that represents a signed integer by calling the xtd::bit_converter::to_uint32 method can result in a value that is different from the original.
  /// @include bit_converter_round_trips.cpp
  /// The order of bytes in the std::vector returned by the xtd::bit_converter::get_bytes method overloads (as well as the order of bits in the integer returned by the xtd::bit_converter:double_to_int64_bits method and the order of hexadecimal strings returned by the to_string(byte_t[]) method) depends on whether the computer architecture is little-endian or big-endian. Similarly, the order of bytes in the std::vector and returned by the ToIntegerValue methods and the to_char method depends on whether the computer architecture is little-endian or big-endian. The endianness of an architecture is indicated by the is_little_endian property, which returns true on little-endian systems and false on big-endian systems. On little-endian systems, lower-order bytes precede higher-order bytes. On big-endian system, higher-order bytes precede lower-order bytes. The following table illustrates the difference in the byte_t std::vectors that result from passing the integer 1,234,567,890 (0x499602D2) to the get_bytes(int32_t) method. The bytes are listed in order from the byte_t at index 0 to the byte_t at index 3.
  /// |               |             |
  /// |---------------|-------------|
  /// | Little-endian | D2-02-96-49 |
  /// | Big-endian    | 49-96-02-D2 |
  /// Because the return value of some methods depends on system architecture, be careful when transmitting byte_t data beyond machine boundaries:
  /// * If all systems sending and receiving data are guaranteed to have the same endianness, nothing has be done to the data.
  /// * If systems sending and receiving data can have different endianness, always transmit data in a particular order. This means that the order of bytes in the std::vector may have to be reversed either before sending them or after receiving them. A common convention is to transmit data in network byte_t order (big-endian order). The following example provides an implementation for sending an integer value in network byte_t order.
  /// @include bit_converterEndianess.cpp
  /// * If systems sending and receiving data can have different endianness and the data to be transmitted consists of signed integers, call the IPAddress.HostToNetworkOrder method to convert the data to network byte_t order and the IPAddress.NetworkToHostOrder method to convert it to the order required by the recipient.
  /// @par Examples
  /// The following code example illustrates the use of several bit_converter class methods.
  /// @include bit_converter.cpp
  class core_export_ bit_converter final static_ {
  public:
    /// @cond
#if defined(__linux__) && defined(_LP64)
    using llong = long long int;
    using ullong = unsigned long long int;
#else
    using llong = long;
    using ullong = unsigned long;
#endif
    /// @endcond

    /// @brief Indicates the byte_t order ("endianness") in which data is stored in this computer architecture.
    /// @return Returns true if the architecture is little-endian; false if it is big-endian.
    /// @remarks Different computer architectures store data using different byte_t orders. "Big-endian" means the most significant byte_t is on the left end of a word. "Little-endian" means the most significant byte_t is on the right end of a word.
    /// @par Examples
    /// The following code example illustrates the use of the is_little_endian field.
    /// @include bit_converteris_little_endian.cpp
    static const bool is_little_endian;

    /// @brief Converts the specified double-precision floating point number to a 64-bit signed integer.
    /// @param value The number to convert.
    /// @return A 64-bit signed integer whose value is equivalent to value.
    /// @remarks The order of bits in the integer returned by the double_to_int64_bits method depends on whether the computer architecture is little-endian or big-endian.
    /// @par Examples
    /// The following code example converts the bit patterns of several Double values to int64_t values with the double_to_int64_bits method.
    /// @include bit_converterdouble_to_int64_bits.cpp
    static int64_t double_to_int64_bits(double value);

    /// @brief Returns the specified Boolean value as an std::vector of bytes.
    /// @param value A Boolean value.
    /// @return An std::vector of bytes with length 1.
    /// @par Examples
    /// The following code example converts the bit patterns of Boolean values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesBoolean.cpp
    static std::vector<byte_t> get_bytes(bool value);

    /// @brief Returns the specified Char value as an std::vector of bytes.
    /// @param value A Char value.
    /// @return An std::vector of bytes with length 4.
    /// @par Examples
    /// The following code example converts the bit patterns of Char values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesChar.cpp
    static std::vector<byte_t> get_bytes(char value);

    /// @brief Returns the specified Char value as an std::vector of bytes.
    /// @param value A Char value.
    /// @return An std::vector of bytes with length 4.
    /// @par Examples
    /// The following code example converts the bit patterns of Char values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesChar.cpp
    static std::vector<byte_t> get_bytes(char16_t value);

    /// @brief Returns the specified Char value as an std::vector of bytes.
    /// @param value A Char value.
    /// @return An std::vector of bytes with length 4.
    /// @par Examples
    /// The following code example converts the bit patterns of Char values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesChar.cpp
    static std::vector<byte_t> get_bytes(char32_t value);

    /// @brief Returns the specified Char value as an std::vector of bytes.
    /// @param value A Char value.
    /// @return An std::vector of bytes with length 4.
    /// @par Examples
    /// The following code example converts the bit patterns of Char values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesChar.cpp
    static std::vector<byte_t> get_bytes(wchar_t value);

    /// @brief Returns the specified double value as an std::vector of bytes.
    /// @param value A double value.
    /// @return An std::vector of bytes with length 8.
    /// @par Examples
    /// The following code example converts the bit patterns of double values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesDouble.cpp
    static std::vector<byte_t> get_bytes(double value);

    /// @brief Returns the specified int16_t value as an std::vector of bytes.
    /// @param value A int16_t value.
    /// @return An std::vector of bytes with length 2.
    /// @par Examples
    /// The following code example converts the bit patterns of int16_t values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesint16_t.cpp
    static std::vector<byte_t> get_bytes(int16_t value);

    /// @brief Returns the specified int32_t value as an std::vector of bytes.
    /// @param value A int32_t value.
    /// @return An std::vector of bytes with length 4.
    /// @par Examples
    /// The following code example converts the bit patterns of int32_t values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesint32_t.cpp
    static std::vector<byte_t> get_bytes(int32_t value);

    /// @brief Returns the specified int64_t value as an std::vector of bytes.
    /// @param value A int64_t value.
    /// @return An std::vector of bytes with length 8.
    /// @par Examples
    /// The following code example converts the bit patterns of int64_t values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesint64_t.cpp
    static std::vector<byte_t> get_bytes(int64_t value);

    /// @brief Returns the specified single value as an std::vector of bytes.
    /// @param value A single value.
    /// @return An std::vector of bytes with length 4.
    /// @par Examples
    /// The following code example converts the bit patterns of single values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesSingle.cpp
    static std::vector<byte_t> get_bytes(float value);

    /// @brief Returns the specified uint16_t value as an std::vector of bytes.
    /// @param value A uint16_t value.
    /// @return An std::vector of bytes with length 2.
    /// @par Examples
    /// The following code example converts the bit patterns of uint16_t values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesUint16_t.cpp
    static std::vector<byte_t> get_bytes(uint16_t value);

    /// @brief Returns the specified uint32_t value as an std::vector of bytes.
    /// @param value A uint32_t value.
    /// @return An std::vector of bytes with length 4.
    /// @par Examples
    /// The following code example converts the bit patterns of uint32_t values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesUint32_t.cpp;
    static std::vector<byte_t> get_bytes(uint32_t value);

    /// @brief Returns the specified uint64_t value as an std::vector of bytes.
    /// @param value A uint64_t value.
    /// @return An std::vector of bytes with length 8.
    /// @par Examples
    /// The following code example converts the bit patterns of uint64_t values to byte_t std::vectors with the get_bytes method.
    /// @include bit_converterget_bytesUint64_t.cpp
    static std::vector<byte_t> get_bytes(uint64_t value);

    /// @cond
    static std::vector<byte_t> get_bytes(llong value);
    static std::vector<byte_t> get_bytes(ullong value);
    /// @endcond

    /// @brief Converts the specified 32-bit signed integer to a single-precision floating point number.
    /// @param value The number to convert.
    /// @return A single-precision floating point number whose value is equivalent to value.
    /// @remarks Typically, value is an integer that is returned by the single_to_int32_bits method.
    static float int32_bits_to_single(int32_t value);

    /// @brief Converts the specified 64-bit signed integer to a double-precision floating point number.
    /// @param value The number to convert.
    /// @return A double-precision floating point number whose value is equivalent to value.
    /// @remarks Typically, value is an integer that is returned by the double_to_int64_bits method.
    static double int64_bits_to_double(int64_t value);

    /// @brief Converts the specified single-precision floating point number to a 32-bit signed integer.
    /// @param value The number to convert.
    /// @return A 32-bit signed integer whose value is equivalent to value.
    /// @remarks The order of bits in the integer returned by the double_to_int64_bits method depends on whether the computer architecture is little-endian or big-endian.
    static int32_t single_to_int32_bits(float value);

    /// @brief Returns a Boolean value converted from one byte_t at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return bool true if the byte_t at start_index in value is nonzero; otherwise, false.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @par Examples
    /// The following code example converts elements of byte_t std::vectors to Boolean values with the to_boolean method.
    /// @include bit_converterto_boolean.cpp
    static bool to_boolean(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a char32_t converted from two bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A char32_t formed by four bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_char method converts the bytes from index start_index to start_index + 3 to an int32_t value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static char32_t to_char(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a double-precision floating point number converted from eight bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A double precision floating point number formed by eight bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_double method converts the bytes from index start_index to start_index + 7 to a Double value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static double to_double(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a 16-bit signed integer converted from two bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A 16-bit signed integer formed by two bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_int16 method converts the bytes from index start_index to start_index + 1 to an int16_t value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static int16_t to_int16(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a 32-bit signed integer converted from two bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A 32-bit signed integer formed by four bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_int32 method converts the bytes from index start_index to start_index + 3 to an int32_t value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static int32_t to_int32(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a 64-bit signed integer converted from two bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A 64-bit signed integer formed by eight bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_int64 method converts the bytes from index start_index to start_index + 7 to an int64_t value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static int64_t to_int64(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a single-precision floating point number converted from eight bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A single precision floating point number formed by eight bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_single method converts the bytes from index start_index to start_index + 3 to a Double value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static float to_single(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a 16-bit unsigned integer converted from two bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A 16-bit unsigned integer formed by two bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_uint16 method converts the bytes from index start_index to start_index + 1 to an Uint16_t value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static uint16_t to_uint16(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a 32-bit signed integer converted from two bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A 32-bit signed integer formed by four bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_uint32 method converts the bytes from index start_index to start_index + 3 to an Uint32_t value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static uint32_t to_uint32(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Returns a 64-bit unsigned integer converted from two bytes at a specified position in a byte_t std::vector.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return A 64-bit unsigned integer formed by eight bytes beginning at start_index.
    /// @exception argument_exception start_index equals the length of value minus 1.
    /// @exception argument_null_exception value is null
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The to_uint64 method converts the bytes from index start_index to start_index + 7 to an Uint64_t value. The order of bytes in the std::vector must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the bit_converter class topic.
    static uint64_t to_uint64(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Converts the numeric value of each element of a specified std::vector of bytes to its equivalent hexadecimal xtd::ustring representation.
    /// @param value An std::vector of bytes.
    /// @return xtd::ustring A xtd::ustring of hexadecimal pairs separated by hyphens, where each pair represents the corresponding element in value; for example, "7F-2C-4A-00".
    /// @exception argument_null_exception value is null.
    /// @remarks All the elements of value are converted. The order of hexadecimal strings returned by the to_string method depends on whether the computer architecture is little-endian or big-endian.
    /// @par Examples
    /// The following code example converts byte_t std::vectors to xtd::ustring objects with the to_string method.
    /// @include bit_converterto_string.cpp
    static xtd::ustring to_string(const std::vector<byte_t>& value);

    /// @brief Converts the numeric value of each element of a specified substd::vector of bytes to its equivalent hexadecimal xtd::ustring representation.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @return xtd::ustring A xtd::ustring of hexadecimal pairs separated by hyphens, where each pair represents the corresponding element in value; for example, "7F-2C-4A-00".
    /// @exception argument_null_exception value is null.
    /// @exception argument_out_of_range_exception start_index is less than zero or greater than the length of value minus 1.
    /// @remarks The elements from std::vector position start_index to the end of the std::vector are converted. The order of hexadecimal strings returned by the to_string method depends on whether the computer architecture is little-endian or big-endian.
    /// @par Examples
    /// The following code example converts byte_t std::vectors to xtd::ustring objects with the to_string method.
    /// @include bit_converterto_string2.cpp
    static xtd::ustring to_string(const std::vector<byte_t>& value, size_t start_index);

    /// @brief Converts the numeric value of each element of a specified substd::vector of bytes to its equivalent hexadecimal xtd::ustring representation.
    /// @param value An std::vector of bytes.
    /// @param start_index The starting position within value.
    /// @param length The number of std::vector elements in value to convert.
    /// @return xtd::ustring A xtd::ustring of hexadecimal pairs separated by hyphens, where each pair represents the corresponding element in value; for example, "7F-2C-4A-00".
    /// @exception argument_null_exception value is null.
    /// @exception argument_out_of_range_exception start_index or length is less than zero. -or- start_index is greater than zero and is greater than or equal to the length of value.
    /// @exception argument_exception The combination of start_index and length does not specify a position within value; that is, the start_index parameter is greater than the length of value minus the length parameter.
    /// @remarks AThe length elements from std::vector position start_index are converted. If length equals zero, the method returns xtd::ustring.Empty.
    /// @remarks The order of hexadecimal strings returned by the to_string method depends on whether the computer architecture is little-endian or big-endian.
    /// @par Examples
    /// The following code example converts byte_t std::vectors to xtd::ustring objects with the to_string method.
    /// @include bit_converterto_string3.cpp
    static xtd::ustring to_string(const std::vector<byte_t>& value, size_t start_index, size_t length);
  };
}

