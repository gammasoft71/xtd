/// @file
/// @brief Contains xtd::convert class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "any.hpp"
#include "argument_exception.hpp"
#include "format_exception.hpp"
#include "invalid_cast_exception.hpp"
#include "overflow_exception.hpp"
#include "read_only_span.hpp"
#include "static.hpp"
#include "types.hpp"
#include "string.hpp"
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents API to convert base type code.
  /// @par Header
  /// ```cpp
  /// #include <xtd/convert>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  class convert static_ {
  public:
    /// @name Public Static Methods
    
    /// @{
    /// @brief Converts the specified string, which encodes binary data as base-64 digits, to an equivalent 8-bit unsigned integer array.
    /// @param s The string to convert.
    /// @return An array of 8-bit unsigned integers that is equivalent to `s`.
    /// @exception xtd::format_exception The length of `s`, is not zero or a multiple of 4.
    /// @remarks `s` is composed of base-64 digits, white-space characters, and trailing padding characters. The base-64 digits in ascending order from zero are the uppercase characters "A" to "Z", lowercase characters "a" to "z", numerals "0" to "9", and the symbols "+" and "/".
    /// @remarks The white-space characters, and their Unicode names and hexadecimal code points, are tab (CHARACTER TABULATION, U+0009), newline (LINE FEED, U+000A), carriage return (CARRIAGE RETURN, U+000D), and blank (SPACE, U+0020). An arbitrary number of white-space characters can appear in s because all white-space characters are ignored.
    /// @remarks The valueless character, "=", is used for trailing padding. The end of s can consist of zero, one, or two padding characters.
    static xtd::array<xtd::byte> from_base64_string(const xtd::string& s);
    
    /// @brief Convert xtd::any to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = true;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(xtd::any value) noexcept;
    /// @brief Convert bool to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(bool value) noexcept;
    /// @brief Convert xtd::byte to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(xtd::byte value) noexcept;
    /// @brief Convert char to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(char value) noexcept;
    /// @brief Convert char8 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(char8 value);
    /// @brief Convert char16 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(char16 value) noexcept;
    /// @brief Convert char32 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(char32 value) noexcept;
    /// @brief Convert wchar to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(wchar value) noexcept;
    /// @brief Convert decimal to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(decimal value) noexcept;
    /// @brief Convert double to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(double value) noexcept;
    /// @brief Convert float to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @brief Convert double to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(float value) noexcept;
    /// @brief Convert int16 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(int16 value) noexcept;
    /// @brief Convert int32 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(int32 value) noexcept;
    /// @brief Convert int64 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// int6_4t value = 42l;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(int64 value) noexcept;
    /// @brief Convert slong to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(slong value) noexcept;
    /// @brief Convert sbyte to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(sbyte value) noexcept;
    /// @brief Convert uint16 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(uint16 value) noexcept;
    /// @brief Convert uint32 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(uint32 value) noexcept;
    /// @brief Convert uint64 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64 value = 42ul;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(uint64 value) noexcept;
    /// @brief Convert slong to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(xtd::ulong value) noexcept;
    /// @brief Convert string to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// any result = convert::to_any(value);
    /// ```
    static xtd::any to_any(const xtd::string& value) noexcept;
    /// @cond
    static xtd::any to_any(const std::string& value) noexcept;
    static xtd::any to_any(const std::u8string& value) noexcept;
    static xtd::any to_any(const std::u16string& value) noexcept;
    static xtd::any to_any(const std::u32string& value) noexcept;
    static xtd::any to_any(const std::wstring& value) noexcept;
    static xtd::any to_any(const char* value) noexcept;
    static xtd::any to_any(char* value) noexcept;
    static xtd::any to_any(const char8* value);
    static xtd::any to_any(char8* value);
    static xtd::any to_any(const char16* value) noexcept;
    static xtd::any to_any(char16* value) noexcept;
    static xtd::any to_any(const char32* value) noexcept;
    static xtd::any to_any(char32* value) noexcept;
    static xtd::any to_any(const wchar* value) noexcept;
    static xtd::any to_any(wchar* value) noexcept;
    /// @endcond
    /// @brief Convert type_t to bool.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// any result = convert::to_any(value);
    /// ```
    template<class type_t>
    static xtd::any to_any(type_t value) {
      try {
        return xtd::any(value);
      } catch (...) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
    }
    
    /// @brief Converts an array of 8-bit unsigned integers to its equivalent string representation that is encoded with base-64 digits.
    /// @param in_array An array of 8-bit unsigned integers.
    /// @return The string representation, in base 64, of the contents of `in_array`.
    static xtd::string to_base64_string(const xtd::array<xtd::byte>& in_array);
    /// @brief Converts a read only span of 8-bit unsigned integers to its equivalent string representation that is encoded with base-64 digits.
    /// @param bytes An read only span of 8-bit unsigned integers.
    /// @return The string representation, in base 64, of the contents of `in_array`.
    static xtd::string to_base64_string(const xtd::read_only_span<xtd::byte>& bytes);
    
    /// @brief Convert xtd::any to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception the parameters is bad cast.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = true;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(xtd::any value);
    /// @brief Convert bool to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(bool value) noexcept;
    /// @brief Convert xtd::byte to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(xtd::byte value) noexcept;
    /// @brief Convert char to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(char value);
    /// @brief Convert char8 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(char8 value);
    /// @brief Convert char16 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(char16 value);
    /// @brief Convert char32 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(char32 value);
    /// @brief Convert wchar to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(wchar value);
    /// @brief Convert decimal to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(decimal value) noexcept;
    /// @brief Convert double to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(double value) noexcept;
    /// @brief Convert float to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @brief Convert double to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(float value) noexcept;
    /// @brief Convert int16 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(int16 value) noexcept;
    /// @brief Convert int32 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(int32 value) noexcept;
    /// @brief Convert int64 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// int6_4t value = 42l;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(int64 value) noexcept;
    /// @brief Convert slong to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(slong value) noexcept;
    /// @brief Convert sbyte to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(sbyte value) noexcept;
    /// @brief Convert uint16 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(uint16 value) noexcept;
    /// @brief Convert uint32 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(uint32 value) noexcept;
    /// @brief Convert uint64 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64 value = 42ul;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(uint64 value) noexcept;
    /// @brief Convert slong to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(xtd::ulong value) noexcept;
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// bool result = convert::to_boolean(value);
    /// ```
    static bool to_boolean(const xtd::string& value);
    /// @cond
    static bool to_boolean(const std::string& value);
    static bool to_boolean(const std::u8string& value);
    static bool to_boolean(const std::u16string& value);
    static bool to_boolean(const std::u32string& value);
    static bool to_boolean(const std::wstring& value);
    static bool to_boolean(const char* value);
    static bool to_boolean(char* value);
    static bool to_boolean(const char8* value);
    static bool to_boolean(char8* value);
    static bool to_boolean(const char16* value);
    static bool to_boolean(char16* value);
    static bool to_boolean(const char32* value);
    static bool to_boolean(char32* value);
    static bool to_boolean(const wchar* value);
    static bool to_boolean(wchar* value);
    /// @endcond
    /// @brief Convert type_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// bool result = convert::to_boolean(value);
    /// ```
    template<class type_t>
    static bool to_boolean(type_t value) noexcept {
      return static_cast<bool>(value);
    }
    
    /// @brief Convert xtd::any to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(xtd::any value);
    /// @brief Convert bool to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(bool value) noexcept;
    /// @brief Convert xtd::byte to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(xtd::byte value) noexcept;
    /// @brief Convert char to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(char value) noexcept;
    /// @brief Convert char8 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(char8 value) noexcept;
    /// @brief Convert char16 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(char16 value);
    /// @brief Convert char32 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(char32 value);
    /// @brief Convert char32 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(wchar value);
    /// @brief Convert decimal to byte.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(decimal value);
    /// @brief Convert double to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(double value);
    /// @brief Convert float to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(float value);
    /// @brief Convert int16 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(int16 value);
    /// @brief Convert int32 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(int32 value);
    /// @brief Convert int64 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(int64 value);
    /// @brief Convert slong to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(slong value);
    /// @brief Convert sbyte to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(sbyte value);
    /// @brief Convert uint16 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(uint16 value);
    /// @brief Convert uint32 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(uint32 value);
    /// @brief Convert uint64 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(uint64 value);
    /// @brief Convert slong to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(xtd::ulong value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(const xtd::string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    static xtd::byte to_byte(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static xtd::byte to_byte(const std::string& value);
    static xtd::byte to_byte(const std::u8string& value);
    static xtd::byte to_byte(const std::u16string& value);
    static xtd::byte to_byte(const std::u32string& value);
    static xtd::byte to_byte(const std::wstring& value);
    static xtd::byte to_byte(const char* value);
    static xtd::byte to_byte(char* value);
    static xtd::byte to_byte(const char8* value);
    static xtd::byte to_byte(char8* value);
    static xtd::byte to_byte(const char16* value);
    static xtd::byte to_byte(char16* value);
    static xtd::byte to_byte(const char32* value);
    static xtd::byte to_byte(char32* value);
    static xtd::byte to_byte(const wchar* value);
    static xtd::byte to_byte(wchar* value);
    /// @endcond
    /// @brief Convert type_t to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    template<class type_t>
    static xtd::byte to_byte(type_t value) noexcept {
      return static_cast<xtd::byte>(value);
    }
    
    /// @brief Convert xtd::any to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(xtd::any value);
    /// @brief Convert bool to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(bool value);
    /// @brief Convert xtd::byte to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(xtd::byte value) noexcept;
    /// @brief Convert char to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(char value) noexcept;
    /// @brief Convert char8 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(char8 value) noexcept;
    /// @brief Convert char16 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(char16 value);
    /// @brief Convert char32 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(char32 value);
    /// @brief Convert char32 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(wchar value);
    /// @brief Convert decimal to char.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(decimal value);
    /// @brief Convert double to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(double value);
    /// @brief Convert float to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(float value);
    /// @brief Convert int16 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(int16 value);
    /// @brief Convert int32 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(int32 value);
    /// @brief Convert int64 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(int64 value);
    /// @brief Convert slong to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(slong value);
    /// @brief Convert sbyte to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(sbyte value);
    /// @brief Convert uint16 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(uint16 value);
    /// @brief Convert uint32 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(uint32 value);
    /// @brief Convert uint64 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(uint64 value);
    /// @brief Convert slong to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(xtd::ulong value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// char result = convert::to_char(value);
    /// ```
    static char to_char(const xtd::string& value);
    /// @cond
    static char to_char(const std::string& value);
    static char to_char(const std::u8string& value);
    static char to_char(const std::u16string& value);
    static char to_char(const std::u32string& value);
    static char to_char(const std::wstring& value);
    static char to_char(const char* value);
    static char to_char(char* value);
    static char to_char(const char8* value);
    static char to_char(char8* value);
    static char to_char(const char16* value);
    static char to_char(char16* value);
    static char to_char(const char32* value);
    static char to_char(char32* value);
    static char to_char(const wchar* value);
    static char to_char(wchar* value);
    /// @endcond
    /// @brief Convert type_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// char result = convert::to_char(value);
    /// ```
    template<class type_t>
    static char to_char(type_t value) noexcept {
      return static_cast<char>(value);
    }
    
    /// @brief Convert xtd::any to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(xtd::any value);
    /// @brief Convert bool to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(bool value);
    /// @brief Convert xtd::byte to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(xtd::byte value) noexcept;
    /// @brief Convert char to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(char value) noexcept;
    /// @brief Convert char8 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(char8 value) noexcept;
    /// @brief Convert char16 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(char16 value);
    /// @brief Convert char32 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(char32 value);
    /// @brief Convert char32 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(wchar value);
    /// @brief Convert decimal to char8.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(decimal value);
    /// @brief Convert double to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(double value);
    /// @brief Convert float to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(float value);
    /// @brief Convert int16 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(int16 value);
    /// @brief Convert int32 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(int32 value);
    /// @brief Convert int64 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(int64 value);
    /// @brief Convert slong to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(slong value);
    /// @brief Convert sbyte to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(sbyte value);
    /// @brief Convert uint16 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(uint16 value);
    /// @brief Convert uint32 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(uint32 value);
    /// @brief Convert uint64 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(uint64 value);
    /// @brief Convert slong to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(xtd::ulong value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// char8 result = convert::to_char8(value);
    /// ```
    static char8 to_char8(const xtd::string& value);
    /// @cond
    static char8 to_char8(const std::string& value);
    static char8 to_char8(const std::u8string& value);
    static char8 to_char8(const std::u16string& value);
    static char8 to_char8(const std::u32string& value);
    static char8 to_char8(const std::wstring& value);
    static char8 to_char8(const char* value);
    static char8 to_char8(char* value);
    static char8 to_char8(const char8* value);
    static char8 to_char8(char8* value);
    static char8 to_char8(const char16* value);
    static char8 to_char8(char16* value);
    static char8 to_char8(const char32* value);
    static char8 to_char8(char32* value);
    static char8 to_char8(const wchar* value);
    static char8 to_char8(wchar* value);
    /// @endcond
    /// @brief Convert type_t to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// char8 result = convert::to_char8(value);
    /// ```
    template<class type_t>
    static char8 to_char8(type_t value) noexcept {
      return static_cast<char8>(value);
    }
    
    /// @brief Convert xtd::any to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(xtd::any value);
    /// @brief Convert bool to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(bool value);
    /// @brief Convert xtd::byte to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(xtd::byte value) noexcept;
    /// @brief Convert char to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(char value) noexcept;
    /// @brief Convert char8 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(char8 value) noexcept;
    /// @brief Convert char16 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(char16 value) noexcept;
    /// @brief Convert char32 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(char32 value);
    /// @brief Convert char32 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(wchar value) noexcept;
    /// @brief Convert decimal to char16.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(decimal value);
    /// @brief Convert double to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(double value);
    /// @brief Convert float to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(float value);
    /// @brief Convert int16 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(int16 value);
    /// @brief Convert int32 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(int32 value);
    /// @brief Convert int64 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(int64 value);
    /// @brief Convert slong to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(slong value);
    /// @brief Convert sbyte to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(sbyte value);
    /// @brief Convert uint16 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(uint16 value) noexcept;
    /// @brief Convert uint32 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(uint32 value);
    /// @brief Convert uint64 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(uint64 value);
    /// @brief Convert slong to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(xtd::ulong value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// char16 result = convert::to_char16(value);
    /// ```
    static char16 to_char16(const xtd::string& value);
    /// @cond
    static char16 to_char16(const std::string& value);
    static char16 to_char16(const std::u8string& value);
    static char16 to_char16(const std::u16string& value);
    static char16 to_char16(const std::u32string& value);
    static char16 to_char16(const std::wstring& value);
    static char16 to_char16(const char* value);
    static char16 to_char16(char* value);
    static char16 to_char16(const char8* value);
    static char16 to_char16(char8* value);
    static char16 to_char16(const char16* value);
    static char16 to_char16(char16* value);
    static char16 to_char16(const char32* value);
    static char16 to_char16(char32* value);
    static char16 to_char16(const wchar* value);
    static char16 to_char16(wchar* value);
    /// @endcond
    /// @brief Convert type_t to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// char16 result = convert::to_char16(value);
    /// ```
    template<class type_t>
    static char16 to_char16(type_t value) noexcept {
      return static_cast<char16>(value);
    }
    
    /// @brief Convert xtd::any to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(xtd::any value);
    /// @brief Convert bool to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(bool value);
    /// @brief Convert xtd::byte to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(xtd::byte value) noexcept;
    /// @brief Convert char to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(char value) noexcept;
    /// @brief Convert char8 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(char8 value) noexcept;
    /// @brief Convert char16 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(char16 value) noexcept;
    /// @brief Convert char32 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(char32 value) noexcept;
    /// @brief Convert char32 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(wchar value) noexcept;
    /// @brief Convert decimal to char32.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(decimal value);
    /// @brief Convert double to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(double value);
    /// @brief Convert float to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(float value);
    /// @brief Convert int16 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(int16 value);
    /// @brief Convert int32 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(int32 value);
    /// @brief Convert int64 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(int64 value);
    /// @brief Convert slong to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(slong value);
    /// @brief Convert sbyte to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(sbyte value);
    /// @brief Convert uint16 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(uint16 value) noexcept;
    /// @brief Convert uint32 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(uint32 value) noexcept;
    /// @brief Convert uint64 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(uint64 value);
    /// @brief Convert slong to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(xtd::ulong value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// char32 result = convert::to_char32(value);
    /// ```
    static char32 to_char32(const xtd::string& value);
    /// @cond
    static char32 to_char32(const std::string& value);
    static char32 to_char32(const std::u8string& value);
    static char32 to_char32(const std::u16string& value);
    static char32 to_char32(const std::u32string& value);
    static char32 to_char32(const std::wstring& value);
    static char32 to_char32(const char* value);
    static char32 to_char32(char* value);
    static char32 to_char32(const char8* value);
    static char32 to_char32(char8* value);
    static char32 to_char32(const char16* value);
    static char32 to_char32(char16* value);
    static char32 to_char32(const char32* value);
    static char32 to_char32(char32* value);
    static char32 to_char32(const wchar* value);
    static char32 to_char32(wchar* value);
    /// @endcond
    /// @brief Convert type_t to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// char32 result = convert::to_char32(value);
    /// ```
    template<class type_t>
    static char32 to_char32(type_t value) noexcept {
      return static_cast<char32>(value);
    }
    
    /// @brief Convert xtd::any to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(xtd::any value);
    /// @brief Convert bool to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(bool value);
    /// @brief Convert xtd::byte to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(xtd::byte value) noexcept;
    /// @brief Convert char to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(char value) noexcept;
    /// @brief Convert char8 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(char8 value) noexcept;
    /// @brief Convert char16 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(char16 value) noexcept;
    /// @brief Convert char32 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(char32 value);
    /// @brief Convert char32 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(wchar value) noexcept;
    /// @brief Convert decimal to wchar.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(decimal value);
    /// @brief Convert double to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(double value);
    /// @brief Convert float to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(float value);
    /// @brief Convert int16 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(int16 value);
    /// @brief Convert int32 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(int32 value);
    /// @brief Convert int64 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(int64 value);
    /// @brief Convert slong to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(slong value);
    /// @brief Convert sbyte to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(sbyte value);
    /// @brief Convert uint16 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(uint16 value) noexcept;
    /// @brief Convert uint32 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(uint32 value);
    /// @brief Convert uint64 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(uint64 value);
    /// @brief Convert slong to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(xtd::ulong value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// wchar result = convert::to_wchar(value);
    /// ```
    static wchar to_wchar(const xtd::string& value);
    /// @cond
    static wchar to_wchar(const std::string& value);
    static wchar to_wchar(const std::u8string& value);
    static wchar to_wchar(const std::u16string& value);
    static wchar to_wchar(const std::u32string& value);
    static wchar to_wchar(const std::wstring& value);
    static wchar to_wchar(const char* value);
    static wchar to_wchar(char* value);
    static wchar to_wchar(const char8* value);
    static wchar to_wchar(char8* value);
    static wchar to_wchar(const char16* value);
    static wchar to_wchar(char16* value);
    static wchar to_wchar(const char32* value);
    static wchar to_wchar(char32* value);
    static wchar to_wchar(const wchar* value);
    static wchar to_wchar(wchar* value);
    /// @endcond
    /// @brief Convert type_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// wchar result = convert::to_wchar(value);
    /// ```
    template<class type_t>
    static wchar to_wchar(type_t value) noexcept {
      return static_cast<wchar>(value);
    }
    
    /// @brief Convert xtd::any to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(xtd::any value);
    /// @brief Convert bool to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(bool value) noexcept;
    /// @brief Convert xtd::byte to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(xtd::byte value) noexcept;
    /// @brief Convert char to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(char value) noexcept;
    /// @brief Convert char8 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(char8 value) noexcept;
    /// @brief Convert char16 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(char16 value) noexcept;
    /// @brief Convert char32 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(char32 value) noexcept;
    /// @brief Convert char32 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(wchar value) noexcept;
    /// @brief Convert decimal to decimal.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(decimal value) noexcept;
    /// @brief Convert double to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(double value) noexcept;
    /// @brief Convert float to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(float value) noexcept;
    /// @brief Convert int16 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(int16 value) noexcept;
    /// @brief Convert int32 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(int32 value) noexcept;
    /// @brief Convert int64 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(int64 value) noexcept;
    /// @brief Convert slong to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(slong value) noexcept;
    /// @brief Convert sbyte to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(sbyte value) noexcept;
    /// @brief Convert uint16 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(uint16 value) noexcept;
    /// @brief Convert uint32 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(uint32 value) noexcept;
    /// @brief Convert uint64 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(uint64 value) noexcept;
    /// @brief Convert slong to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(xtd::ulong value) noexcept;
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// decimal result = convert::to_decimal(value);
    /// ```
    static decimal to_decimal(const xtd::string& value);
    /// @cond
    static decimal to_decimal(const std::string& value);
    static decimal to_decimal(const std::u8string& value);
    static decimal to_decimal(const std::u16string& value);
    static decimal to_decimal(const std::u32string& value);
    static decimal to_decimal(const std::wstring& value);
    static decimal to_decimal(const char* value);
    static decimal to_decimal(char* value);
    static decimal to_decimal(const char8* value);
    static decimal to_decimal(char8* value);
    static decimal to_decimal(const char16* value);
    static decimal to_decimal(char16* value);
    static decimal to_decimal(const char32* value);
    static decimal to_decimal(char32* value);
    static decimal to_decimal(const wchar* value);
    static decimal to_decimal(wchar* value);
    /// @endcond
    /// @brief Convert type_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// decimal result = convert::to_decimal(value);
    /// ```
    template<class type_t>
    static decimal to_decimal(type_t value) noexcept {
      return static_cast<decimal>(value);
    }
    
    /// @brief Convert xtd::any to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(xtd::any value);
    /// @brief Convert bool to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(bool value) noexcept;
    /// @brief Convert xtd::byte to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(xtd::byte value) noexcept;
    /// @brief Convert char to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(char value) noexcept;
    /// @brief Convert char8 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(char8 value) noexcept;
    /// @brief Convert char16 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(char16 value) noexcept;
    /// @brief Convert char32 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(char32 value) noexcept;
    /// @brief Convert char32 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(wchar value) noexcept;
    /// @brief Convert decimal to double.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(decimal value) noexcept;
    /// @brief Convert double to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(double value) noexcept;
    /// @brief Convert float to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(float value) noexcept;
    /// @brief Convert int16 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(int16 value) noexcept;
    /// @brief Convert int32 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(int32 value) noexcept;
    /// @brief Convert int64 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(int64 value) noexcept;
    /// @brief Convert slong to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(slong value) noexcept;
    /// @brief Convert sbyte to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(sbyte value) noexcept;
    /// @brief Convert uint16 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(uint16 value) noexcept;
    /// @brief Convert uint32 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(uint32 value) noexcept;
    /// @brief Convert uint64 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(uint64 value) noexcept;
    /// @brief Convert slong to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(xtd::ulong value) noexcept;
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// double result = convert::to_double(value);
    /// ```
    static double to_double(const xtd::string& value);
    /// @cond
    static double to_double(const std::string& value);
    static double to_double(const std::u8string& value);
    static double to_double(const std::u16string& value);
    static double to_double(const std::u32string& value);
    static double to_double(const std::wstring& value);
    static double to_double(const char* value);
    static double to_double(char* value);
    static double to_double(const char8* value);
    static double to_double(char8* value);
    static double to_double(const char16* value);
    static double to_double(char16* value);
    static double to_double(const char32* value);
    static double to_double(char32* value);
    static double to_double(const wchar* value);
    static double to_double(wchar* value);
    /// @endcond
    /// @brief Convert type_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// double result = convert::to_double(value);
    /// ```
    template<class type_t>
    static double to_double(type_t value) noexcept {
      return static_cast<double>(value);
    }
    
    /// @brief Convert xtd::any to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(xtd::any value);
    /// @brief Convert bool to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(bool value) noexcept;
    /// @brief Convert xtd::byte to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(xtd::byte value) noexcept;
    /// @brief Convert char to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(char value) noexcept;
    /// @brief Convert char8 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(char8 value) noexcept;
    /// @brief Convert char16 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(char16 value) noexcept;
    /// @brief Convert char32 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(char32 value) noexcept;
    /// @brief Convert char32 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(wchar value) noexcept;
    /// @brief Convert decimal to single.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(decimal value) noexcept;
    /// @brief Convert double to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(double value) noexcept;
    /// @brief Convert float to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(float value) noexcept;
    /// @brief Convert int16 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(int16 value) noexcept;
    /// @brief Convert int32 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(int32 value) noexcept;
    /// @brief Convert int64 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(int64 value) noexcept;
    /// @brief Convert slong to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(slong value) noexcept;
    /// @brief Convert sbyte to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(sbyte value) noexcept;
    /// @brief Convert uint16 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(uint16 value) noexcept;
    /// @brief Convert uint32 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(uint32 value) noexcept;
    /// @brief Convert uint64 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(uint64 value) noexcept;
    /// @brief Convert slong to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(xtd::ulong value) noexcept;
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// float result = convert::to_single(value);
    /// ```
    static float to_single(const xtd::string& value);
    /// @cond
    static float to_single(const std::string& value);
    static float to_single(const std::u8string& value);
    static float to_single(const std::u16string& value);
    static float to_single(const std::u32string& value);
    static float to_single(const std::wstring& value);
    static float to_single(const char* value);
    static float to_single(char* value);
    static float to_single(const char8* value);
    static float to_single(char8* value);
    static float to_single(const char16* value);
    static float to_single(char16* value);
    static float to_single(const char32* value);
    static float to_single(char32* value);
    static float to_single(const wchar* value);
    static float to_single(wchar* value);
    /// @endcond
    /// @brief Convert type_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// float result = convert::to_single(value);
    /// ```
    template<class type_t>
    static float to_single(type_t value) noexcept {
      return static_cast<float>(value);
    }
    
    /// @brief Convert xtd::any to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(xtd::any value);
    /// @brief Convert bool to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(bool value) noexcept;
    /// @brief Convert xtd::byte to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(xtd::byte value) noexcept;
    /// @brief Convert char to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(char value) noexcept;
    /// @brief Convert char8 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(char8 value) noexcept;
    /// @brief Convert char16 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(char16 value) noexcept;
    /// @brief Convert char32 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(char32 value);
    /// @brief Convert char32 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(wchar value) noexcept;
    /// @brief Convert decimal to int16.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(decimal value);
    /// @brief Convert double to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(double value);
    /// @brief Convert float to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(float value);
    /// @brief Convert int16 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(int16 value) noexcept;
    /// @brief Convert int32 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(int32 value);
    /// @brief Convert int64 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(int64 value);
    /// @brief Convert slong to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(slong value);
    /// @brief Convert sbyte to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(sbyte value) noexcept;
    /// @brief Convert uint16 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(uint16 value);
    /// @brief Convert uint32 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(uint32 value);
    /// @brief Convert uint64 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(uint64 value);
    /// @brief Convert slong to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(xtd::ulong value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(const xtd::string& value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new intt16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a int16.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int16 result = convert::to_int16(value);
    /// ```
    static int16 to_int16(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static int16 to_int16(const std::string& value);
    static int16 to_int16(const std::u8string& value);
    static int16 to_int16(const std::u16string& value);
    static int16 to_int16(const std::u32string& value);
    static int16 to_int16(const std::wstring& value);
    static int16 to_int16(const char* value);
    static int16 to_int16(char* value);
    static int16 to_int16(const char8* value);
    static int16 to_int16(char8* value);
    static int16 to_int16(const char16* value);
    static int16 to_int16(char16* value);
    static int16 to_int16(const char32* value);
    static int16 to_int16(char32* value);
    static int16 to_int16(const wchar* value);
    static int16 to_int16(wchar* value);
    /// @endcond
    /// @brief Convert type_t to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// int16 result = convert::to_int16(value);
    /// ```
    template<class type_t>
    static int16 to_int16(type_t value) noexcept {
      return static_cast<int16>(value);
    }
    
    /// @brief Convert xtd::any to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(xtd::any value);
    /// @brief Convert bool to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(bool value) noexcept;
    /// @brief Convert xtd::byte to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(xtd::byte value) noexcept;
    /// @brief Convert char to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(char value) noexcept;
    /// @brief Convert char8 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(char8 value) noexcept;
    /// @brief Convert char16 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(char16 value) noexcept;
    /// @brief Convert char32 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(char32 value) noexcept;
    /// @brief Convert char32 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(wchar value) noexcept;
    /// @brief Convert decimal to int32.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(decimal value);
    /// @brief Convert double to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(double value);
    /// @brief Convert float to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(float value) noexcept;
    /// @brief Convert int16 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(int16 value) noexcept;
    /// @brief Convert int32 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(int32 value) noexcept;
    /// @brief Convert int64 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(int64 value);
    /// @brief Convert slong to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(slong value);
    /// @brief Convert sbyte to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(sbyte value) noexcept;
    /// @brief Convert uint16 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(uint16 value) noexcept;
    /// @brief Convert uint32 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(uint32 value);
    /// @brief Convert uint64 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(uint64 value);
    /// @brief Convert slong to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(xtd::ulong value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(const xtd::string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new intt32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a int32.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int32 result = convert::to_int32(value);
    /// ```
    static int32 to_int32(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static int32 to_int32(const std::string& value);
    static int32 to_int32(const std::u8string& value);
    static int32 to_int32(const std::u16string& value);
    static int32 to_int32(const std::u32string& value);
    static int32 to_int32(const std::wstring& value);
    static int32 to_int32(const char* value);
    static int32 to_int32(char* value);
    static int32 to_int32(const char8* value);
    static int32 to_int32(char8* value);
    static int32 to_int32(const char16* value);
    static int32 to_int32(char16* value);
    static int32 to_int32(const char32* value);
    static int32 to_int32(char32* value);
    static int32 to_int32(const wchar* value);
    static int32 to_int32(wchar* value);
    /// @endcond
    /// @brief Convert type_t to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// int32 result = convert::to_int32(value);
    /// ```
    template<class type_t>
    static int32 to_int32(type_t value) noexcept {
      return static_cast<int32>(value);
    }
    
    /// @brief Convert xtd::any to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(xtd::any value);
    /// @brief Convert bool to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(bool value) noexcept;
    /// @brief Convert xtd::byte to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(xtd::byte value) noexcept;
    /// @brief Convert char to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(char value) noexcept;
    /// @brief Convert char8 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(char8 value) noexcept;
    /// @brief Convert char16 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(char16 value) noexcept;
    /// @brief Convert char32 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(char32 value) noexcept;
    /// @brief Convert char32 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(wchar value) noexcept;
    /// @brief Convert decimal to int64.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(decimal value) noexcept;
    /// @brief Convert double to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(double value) noexcept;
    /// @brief Convert float to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(float value) noexcept;
    /// @brief Convert int16 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(int16 value) noexcept;
    /// @brief Convert int32 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(int32 value) noexcept;
    /// @brief Convert int64 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(int64 value) noexcept;
    /// @brief Convert slong to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(slong value) noexcept;
    /// @brief Convert sbyte to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(sbyte value) noexcept;
    /// @brief Convert uint16 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(uint16 value) noexcept;
    /// @brief Convert uint32 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(uint32 value) noexcept;
    /// @brief Convert uint64 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(uint64 value);
    /// @brief Convert slong to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(xtd::ulong value);
    /// @brief Convert string to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int64 result = convert::to_int64(value);
    /// ```
    static int64 to_int64(const xtd::string& value);
    /// @brief Convert string to int64.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new intt64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a int64.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int16 result = convert::to_int16(value);
    /// ```
    static int64 to_int64(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static int64 to_int64(const std::string& value);
    static int64 to_int64(const std::u8string& value);
    static int64 to_int64(const std::u16string& value);
    static int64 to_int64(const std::u32string& value);
    static int64 to_int64(const std::wstring& value);
    static int64 to_int64(const char* value);
    static int64 to_int64(char* value);
    static int64 to_int64(const char8* value);
    static int64 to_int64(char8* value);
    static int64 to_int64(const char16* value);
    static int64 to_int64(char16* value);
    static int64 to_int64(const char32* value);
    static int64 to_int64(char32* value);
    static int64 to_int64(const wchar* value);
    static int64 to_int64(wchar* value);
    /// @endcond
    /// @brief Convert type_t to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// int64 result = convert::to_int64(value);
    /// ```
    template<class type_t>
    static int64 to_int64(type_t value) noexcept {
      return static_cast<int64>(value);
    }
    
    /// @brief Convert xtd::any to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(xtd::any value);
    /// @brief Convert bool to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(bool value) noexcept;
    /// @brief Convert xtd::byte to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(xtd::byte value) noexcept;
    /// @brief Convert char to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(char value) noexcept;
    /// @brief Convert char8 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(char8 value) noexcept;
    /// @brief Convert char16 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(char16 value) noexcept;
    /// @brief Convert char32 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(char32 value) noexcept;
    /// @brief Convert char32 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(wchar value) noexcept;
    /// @brief Convert decimal to slong.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(decimal value) noexcept;
    /// @brief Convert double to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(double value) noexcept;
    /// @brief Convert float to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(float value) noexcept;
    /// @brief Convert int16 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(int16 value) noexcept;
    /// @brief Convert int32 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(int32 value) noexcept;
    /// @brief Convert int64 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(int64 value) noexcept;
    /// @brief Convert slong to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(slong value) noexcept;
    /// @brief Convert sbyte to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(sbyte value) noexcept;
    /// @brief Convert uint16 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(uint16 value) noexcept;
    /// @brief Convert uint32 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(uint32 value) noexcept;
    /// @brief Convert uint64 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(uint64 value);
    /// @brief Convert slong to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(xtd::ulong value);
    /// @brief Convert string to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(const xtd::string& value);
    /// @brief Convert string to slong.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new slong object converted from value.
    /// @exception xtd::atgument_exception value does not represent a slong.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// slong result = convert::to_llong(value);
    /// ```
    static slong to_llong(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static slong to_llong(const std::string& value);
    static slong to_llong(const std::u8string& value);
    static slong to_llong(const std::u16string& value);
    static slong to_llong(const std::u32string& value);
    static slong to_llong(const std::wstring& value);
    static slong to_llong(const char* value);
    static slong to_llong(char* value);
    static slong to_llong(const char8* value);
    static slong to_llong(char8* value);
    static slong to_llong(const char16* value);
    static slong to_llong(char16* value);
    static slong to_llong(const char32* value);
    static slong to_llong(char32* value);
    static slong to_llong(const wchar* value);
    static slong to_llong(wchar* value);
    /// @endcond
    /// @brief Convert type_t to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// slong result = convert::to_llong(value);
    /// ```
    template<class type_t>
    static slong to_llong(type_t value) noexcept {
      return static_cast<slong>(value);
    }
    
    /// @brief Convert xtd::any to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(xtd::any value);
    /// @brief Convert bool to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(bool value) noexcept;
    /// @brief Convert xtd::byte to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(xtd::byte value) noexcept;
    /// @brief Convert char to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(char value) noexcept;
    /// @brief Convert char8 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(char8 value) noexcept;
    /// @brief Convert char16 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(char16 value);
    /// @brief Convert char32 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(char32 value);
    /// @brief Convert char32 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(wchar value);
    /// @brief Convert decimal to sbyte.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(decimal value);
    /// @brief Convert double to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(double value);
    /// @brief Convert float to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(float value);
    /// @brief Convert int16 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(int16 value);
    /// @brief Convert int32 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(int32 value);
    /// @brief Convert int64 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(int64 value);
    /// @brief Convert slong to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(slong value);
    /// @brief Convert sbyte to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(sbyte value);
    /// @brief Convert uint16 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(uint16 value);
    /// @brief Convert uint32 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(uint32 value);
    /// @brief Convert uint64 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(uint64 value);
    /// @brief Convert slong to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(xtd::ulong value);
    /// @brief Convert string to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(const xtd::string& value);
    /// @brief Convert string to sbyte.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::atgument_exception value does not represent a sbyte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    static sbyte to_sbyte(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static sbyte to_sbyte(const std::string& value);
    static sbyte to_sbyte(const std::u8string& value);
    static sbyte to_sbyte(const std::u16string& value);
    static sbyte to_sbyte(const std::u32string& value);
    static sbyte to_sbyte(const std::wstring& value);
    static sbyte to_sbyte(const char* value);
    static sbyte to_sbyte(char* value);
    static sbyte to_sbyte(const char8* value);
    static sbyte to_sbyte(char8* value);
    static sbyte to_sbyte(const char16* value);
    static sbyte to_sbyte(char16* value);
    static sbyte to_sbyte(const char32* value);
    static sbyte to_sbyte(char32* value);
    static sbyte to_sbyte(const wchar* value);
    static sbyte to_sbyte(wchar* value);
    /// @endcond
    /// @brief Convert type_t to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    template<class type_t>
    static sbyte to_sbyte(type_t value) noexcept {
      return static_cast<sbyte>(value);
    }
    
    /// @brief Convert xtd::any to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(xtd::any value);
    /// @brief Convert bool to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(bool value) noexcept;
    /// @brief Convert xtd::byte to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(xtd::byte value) noexcept;
    /// @brief Convert char to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(char value) noexcept;
    /// @brief Convert char8 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(char8 value) noexcept;
    /// @brief Convert char16 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(char16 value) noexcept;
    /// @brief Convert char32 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(char32 value);
    /// @brief Convert char32 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(wchar value) noexcept;
    /// @brief Convert decimal to uint16.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(decimal value);
    /// @brief Convert double to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(double value);
    /// @brief Convert float to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(float value);
    /// @brief Convert int16 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(int16 value);
    /// @brief Convert int32 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(int32 value);
    /// @brief Convert int64 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(int64 value);
    /// @brief Convert slong to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(slong value);
    /// @brief Convert sbyte to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(sbyte value);
    /// @brief Convert uint16 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(uint16 value) noexcept;
    /// @brief Convert uint32 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(uint32 value);
    /// @brief Convert uint64 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(uint64 value);
    /// @brief Convert slong to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(xtd::ulong value);
    /// @brief Convert string to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uint16 result = convert::to_uint16(value);
    /// ```
    static uint16 to_uint16(const xtd::string& value);
    /// @brief Convert string to uint16.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new intt16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a uint16.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uint16 result = convert::to_uuint16(value);
    /// ```
    static uint16 to_uint16(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static uint16 to_uint16(const std::string& value);
    static uint16 to_uint16(const std::u8string& value);
    static uint16 to_uint16(const std::u16string& value);
    static uint16 to_uint16(const std::u32string& value);
    static uint16 to_uint16(const std::wstring& value);
    static uint16 to_uint16(const char* value);
    static uint16 to_uint16(char* value);
    static uint16 to_uint16(const char8* value);
    static uint16 to_uint16(char8* value);
    static uint16 to_uint16(const char16* value);
    static uint16 to_uint16(char16* value);
    static uint16 to_uint16(const char32* value);
    static uint16 to_uint16(char32* value);
    static uint16 to_uint16(const wchar* value);
    static uint16 to_uint16(wchar* value);
    /// @endcond
    /// @brief Convert type_t to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    template<class type_t>
    static uint16 to_uint16(type_t value) noexcept {
      return static_cast<uint16>(value);
    }
    
    /// @brief Convert xtd::any to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(xtd::any value);
    /// @brief Convert bool to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(bool value) noexcept;
    /// @brief Convert xtd::byte to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(xtd::byte value) noexcept;
    /// @brief Convert char to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(char value) noexcept;
    /// @brief Convert char8 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(char8 value) noexcept;
    /// @brief Convert char16 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(char16 value) noexcept;
    /// @brief Convert char32 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(char32 value) noexcept;
    /// @brief Convert char32 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(wchar value) noexcept;
    /// @brief Convert decimal to uint32.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(decimal value);
    /// @brief Convert double to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(double value);
    /// @brief Convert float to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(float value);
    /// @brief Convert int16 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(int16 value);
    /// @brief Convert int32 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(int32 value);
    /// @brief Convert int64 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(int64 value);
    /// @brief Convert slong to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(slong value);
    /// @brief Convert sbyte to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(sbyte value);
    /// @brief Convert uint16 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(uint16 value) noexcept;
    /// @brief Convert uint32 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(uint32 value) noexcept;
    /// @brief Convert uint64 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(uint64 value);
    /// @brief Convert slong to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(xtd::ulong value);
    /// @brief Convert string to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(const xtd::string& value);
    /// @brief Convert string to uint32.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new uintt32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uint32 result = convert::to_uint32(value);
    /// ```
    static uint32 to_uint32(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static uint32 to_uint32(const std::string& value);
    static uint32 to_uint32(const std::u8string& value);
    static uint32 to_uint32(const std::u16string& value);
    static uint32 to_uint32(const std::u32string& value);
    static uint32 to_uint32(const std::wstring& value);
    static uint32 to_uint32(const char* value);
    static uint32 to_uint32(char* value);
    static uint32 to_uint32(const char8* value);
    static uint32 to_uint32(char8* value);
    static uint32 to_uint32(const char16* value);
    static uint32 to_uint32(char16* value);
    static uint32 to_uint32(const char32* value);
    static uint32 to_uint32(char32* value);
    static uint32 to_uint32(const wchar* value);
    static uint32 to_uint32(wchar* value);
    /// @endcond
    /// @brief Convert type_t to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    template<class type_t>
    static uint32 to_uint32(type_t value) noexcept {
      return static_cast<uint32>(value);
    }
    
    /// @brief Convert xtd::any to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(xtd::any value);
    /// @brief Convert bool to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(bool value) noexcept;
    /// @brief Convert xtd::byte to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(xtd::byte value) noexcept;
    /// @brief Convert char to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(char value) noexcept;
    /// @brief Convert char8 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(char8 value) noexcept;
    /// @brief Convert char16 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(char16 value) noexcept;
    /// @brief Convert char32 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(char32 value) noexcept;
    /// @brief Convert char32 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(wchar value) noexcept;
    /// @brief Convert decimal to uint64.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(decimal value);
    /// @brief Convert double to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(double value);
    /// @brief Convert float to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(float value);
    /// @brief Convert int16 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(int16 value);
    /// @brief Convert int32 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(int32 value);
    /// @brief Convert int64 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(int64 value);
    /// @brief Convert slong to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(slong value);
    /// @brief Convert sbyte to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(sbyte value);
    /// @brief Convert uint16 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(uint16 value) noexcept;
    /// @brief Convert uint32 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(uint32 value) noexcept;
    /// @brief Convert uint64 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(uint64 value) noexcept;
    /// @brief Convert slong to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(xtd::ulong value) noexcept;
    /// @brief Convert string to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(const xtd::string& value);
    /// @brief Convert string to uint64.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new intt16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a uint64.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uuint64 result = convert::to_uint64(value);
    /// ```
    static uint64 to_uint64(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static uint64 to_uint64(const std::string& value);
    static uint64 to_uint64(const std::u8string& value);
    static uint64 to_uint64(const std::u16string& value);
    static uint64 to_uint64(const std::u32string& value);
    static uint64 to_uint64(const std::wstring& value);
    static uint64 to_uint64(const char* value);
    static uint64 to_uint64(char* value);
    static uint64 to_uint64(const char8* value);
    static uint64 to_uint64(char8* value);
    static uint64 to_uint64(const char16* value);
    static uint64 to_uint64(char16* value);
    static uint64 to_uint64(const char32* value);
    static uint64 to_uint64(char32* value);
    static uint64 to_uint64(const wchar* value);
    static uint64 to_uint64(wchar* value);
    /// @endcond
    /// @brief Convert type_t to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    template<class type_t>
    static uint64 to_uint64(type_t value) noexcept {
      return static_cast<uint64>(value);
    }
    
    /// @brief Convert xtd::any to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(xtd::any value);
    /// @brief Convert bool to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(bool value) noexcept;
    /// @brief Convert xtd::byte to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(xtd::byte value) noexcept;
    /// @brief Convert char to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(char value) noexcept;
    /// @brief Convert char8 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(char8 value) noexcept;
    /// @brief Convert char16 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(char16 value) noexcept;
    /// @brief Convert char32 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(char32 value) noexcept;
    /// @brief Convert char32 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(wchar value) noexcept;
    /// @brief Convert decimal to xtd::ulong.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(decimal value);
    /// @brief Convert double to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(double value);
    /// @brief Convert float to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(float value);
    /// @brief Convert int16 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(int16 value);
    /// @brief Convert int32 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(int32 value);
    /// @brief Convert int64 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(int64 value);
    /// @brief Convert slong to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(slong value);
    /// @brief Convert sbyte to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(sbyte value);
    /// @brief Convert uint16 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(uint16 value) noexcept;
    /// @brief Convert uint32 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(uint32 value) noexcept;
    /// @brief Convert uint64 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(uint64 value) noexcept;
    /// @brief Convert slong to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(xtd::ulong value) noexcept;
    /// @brief Convert string to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(const xtd::string& value);
    /// @brief Convert string to xtd::ulong.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::atgument_exception value does not represent a xtd::ulong.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    static xtd::ulong to_ullong(const xtd::string& value, xtd::byte from_base);
    /// @cond
    static xtd::ulong to_ullong(const std::string& value);
    static xtd::ulong to_ullong(const std::u8string& value);
    static xtd::ulong to_ullong(const std::u16string& value);
    static xtd::ulong to_ullong(const std::u32string& value);
    static xtd::ulong to_ullong(const std::wstring& value);
    static xtd::ulong to_ullong(const char* value);
    static xtd::ulong to_ullong(char* value);
    static xtd::ulong to_ullong(const char8* value);
    static xtd::ulong to_ullong(char8* value);
    static xtd::ulong to_ullong(const char16* value);
    static xtd::ulong to_ullong(char16* value);
    static xtd::ulong to_ullong(const char32* value);
    static xtd::ulong to_ullong(char32* value);
    static xtd::ulong to_ullong(const wchar* value);
    static xtd::ulong to_ullong(wchar* value);
    /// @endcond
    /// @brief Convert type_t to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    template<class type_t>
    static xtd::ulong to_ullong(type_t value) noexcept {
      return static_cast<xtd::ulong>(value);
    }
    
    /// @brief Convert xtd::any to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = 42;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(xtd::any value);
    /// @brief Convert bool to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(bool value) noexcept;
    /// @brief Convert xtd::byte to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(xtd::byte value) noexcept;
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(xtd::byte value, xtd::byte from_base);
    /// @brief Convert char to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(char value) noexcept;
    /// @brief Convert char8 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(char8 value) noexcept;
    /// @brief Convert char16 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(char16 value) noexcept;
    /// @brief Convert char32 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(char32 value) noexcept;
    /// @brief Convert char32 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(wchar value) noexcept;
    /// @brief Convert decimal to string.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(decimal value);
    /// @brief Convert double to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(double value);
    /// @brief Convert float to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(float value);
    /// @brief Convert int16 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(int16 value);
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(int16 value, xtd::byte from_base);
    /// @brief Convert int32 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(int32 value);
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(int32 value, xtd::byte from_base);
    /// @brief Convert int64 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(int64 value);
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(int64 value, xtd::byte from_base);
    /// @brief Convert slong to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(slong value);
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// slong value = 42;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(slong value, xtd::byte from_base);
    /// @brief Convert sbyte to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(sbyte value);
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(sbyte value, xtd::byte from_base);
    /// @brief Convert uint16 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(uint16 value) noexcept;
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(uint16 value, xtd::byte from_base);
    /// @brief Convert uint32 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(uint32 value) noexcept;
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(uint32 value, xtd::byte from_base);
    /// @brief Convert uint64 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42u;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(uint64 value) noexcept;
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// uint64 value = 42ul;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(uint64 value, xtd::byte from_base);
    /// @brief Convert slong to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(xtd::ulong value) noexcept;
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// string result = convert::to_string(value, 16);
    /// ```
    static string to_string(xtd::ulong value, xtd::byte from_base);
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// string result = convert::to_string(value);
    /// ```
    static string to_string(const xtd::string& value);
    /// @cond
    static string to_string(const std::string& value);
    static string to_string(const std::u8string& value);
    static string to_string(const std::u16string& value);
    static string to_string(const std::u32string& value);
    static string to_string(const std::wstring& value);
    static string to_string(const char* value);
    static string to_string(char* value);
    static string to_string(const char8* value);
    static string to_string(char8* value);
    static string to_string(const char16* value);
    static string to_string(char16* value);
    static string to_string(const char32* value);
    static string to_string(char32* value);
    static string to_string(const wchar* value);
    static string to_string(wchar* value);
    /// @endcond
    /// @brief Convert type_t to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// string result = convert::to_string(value);
    /// ```
    template<class type_t>
    static string to_string(type_t value) noexcept {
      return string::format("{}", value);
    }
    /// @}
    
    /// @name Public Deprecated Static Methods
    
    /// @{
    /// @brief Convert type_t to string.
    /// @param value object to convert.
    /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
    /// @return A new string object converted from value.
    /// @exception xtd::atgument_exception from_base is not 2 or 8 or 10 orr 16.
    /// @deprecated Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.
    template<class type_t>
    [[deprecated("Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.")]] static string to_ustring(type_t value, xtd::byte from_base) {return to_string(value, from_base);}
    /// @brief Convert string_t to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @deprecated Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.
    template<class string_t>
    [[deprecated("Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.")]] static string to_ustring(const string_t& value) {return to_string(value);}
    /// @}

    /// @cond
    template<class char_t>
    [[deprecated("Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.")]] static string to_ustring(const char_t* value) {return to_string(value);}
    template<class char_t>
    [[deprecated("Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.")]] static string to_ustring(char_t* value) {return to_string(value);}
    /// @endcond
  };
}
