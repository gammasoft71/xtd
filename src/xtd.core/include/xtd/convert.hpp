/// @file
/// @brief Contains xtd::convert class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
    [[nodiscard]] static auto from_base64_string(const xtd::string& s) -> xtd::array<xtd::byte>;
    
    /// @brief Convert xtd::any to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = true;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(xtd::any value) noexcept -> xtd::any;
    /// @brief Convert bool to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(bool value) noexcept -> xtd::any;
    /// @brief Convert xtd::byte to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(xtd::byte value) noexcept -> xtd::any;
    /// @brief Convert char to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(char value) noexcept -> xtd::any;
    /// @brief Convert char8 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(char8 value) -> xtd::any;
    /// @brief Convert char16 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(char16 value) noexcept -> xtd::any;
    /// @brief Convert char32 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(char32 value) noexcept -> xtd::any;
    /// @brief Convert wchar to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(wchar value) noexcept -> xtd::any;
    /// @brief Convert decimal to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(decimal value) noexcept -> xtd::any;
    /// @brief Convert double to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(double value) noexcept -> xtd::any;
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
    [[nodiscard]] static auto to_any(float value) noexcept -> xtd::any;
    /// @brief Convert int16 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(int16 value) noexcept -> xtd::any;
    /// @brief Convert int32 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(int32 value) noexcept -> xtd::any;
    /// @brief Convert int64 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// int6_4t value = 42l;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(int64 value) noexcept -> xtd::any;
    /// @brief Convert slong to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(slong value) noexcept -> xtd::any;
    /// @brief Convert sbyte to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(sbyte value) noexcept -> xtd::any;
    /// @brief Convert uint16 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(uint16 value) noexcept -> xtd::any;
    /// @brief Convert uint32 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(uint32 value) noexcept -> xtd::any;
    /// @brief Convert uint64 to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64 value = 42ul;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(uint64 value) noexcept -> xtd::any;
    /// @brief Convert slong to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(xtd::ulong value) noexcept -> xtd::any;
    /// @brief Convert string to xtd::any.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// any result = convert::to_any(value);
    /// ```
    [[nodiscard]] static auto to_any(const xtd::string& value) noexcept -> xtd::any;
    /// @cond
    [[nodiscard]] static auto to_any(const std::string& value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(const std::u8string& value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(const std::u16string& value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(const std::u32string& value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(const std::wstring& value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(const char* value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(char* value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(const char8* value) -> xtd::any;
    [[nodiscard]] static auto to_any(char8* value) -> xtd::any;
    [[nodiscard]] static auto to_any(const char16* value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(char16* value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(const char32* value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(char32* value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(const wchar* value) noexcept -> xtd::any;
    [[nodiscard]] static auto to_any(wchar* value) noexcept -> xtd::any;
    /// @endcond
    /// @brief Convert type_t to bool.
    /// @param value object to convert.
    /// @return A new xtd::any object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// any result = convert::to_any(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_any(type_t value) -> xtd::any {
      try {
        return xtd::any(value);
      } catch (...) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
    }
    
    /// @brief Converts an array of 8-bit unsigned integers to its equivalent string representation that is encoded with base-64 digits.
    /// @param in_array An array of 8-bit unsigned integers.
    /// @return The string representation, in base 64, of the contents of `in_array`.
    [[nodiscard]] static auto to_base64_string(const xtd::array<xtd::byte>& in_array) -> xtd::string;
    /// @brief Converts a read only span of 8-bit unsigned integers to its equivalent string representation that is encoded with base-64 digits.
    /// @param bytes An read only span of 8-bit unsigned integers.
    /// @return The string representation, in base 64, of the contents of `in_array`.
    [[nodiscard]] static auto to_base64_string(const xtd::read_only_span<xtd::byte>& bytes) -> xtd::string;
    
    /// @brief Convert xtd::any to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception the parameters is bad cast.
    /// @par Examples
    /// ```cpp
    /// xtd::any value = true;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(xtd::any value) -> bool;
    /// @brief Convert bool to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(bool value) noexcept -> bool;
    /// @brief Convert xtd::byte to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(xtd::byte value) noexcept -> bool;
    /// @brief Convert char to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(char value) -> bool;
    /// @brief Convert char8 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(char8 value) -> bool;
    /// @brief Convert char16 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(char16 value) -> bool;
    /// @brief Convert char32 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(char32 value) -> bool;
    /// @brief Convert wchar to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(wchar value) -> bool;
    /// @brief Convert decimal to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(decimal value) noexcept -> bool;
    /// @brief Convert double to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(double value) noexcept -> bool;
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
    [[nodiscard]] static auto to_boolean(float value) noexcept -> bool;
    /// @brief Convert int16 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(int16 value) noexcept -> bool;
    /// @brief Convert int32 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(int32 value) noexcept -> bool;
    /// @brief Convert int64 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// int6_4t value = 42l;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(int64 value) noexcept -> bool;
    /// @brief Convert slong to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(slong value) noexcept -> bool;
    /// @brief Convert sbyte to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(sbyte value) noexcept -> bool;
    /// @brief Convert uint16 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(uint16 value) noexcept -> bool;
    /// @brief Convert uint32 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(uint32 value) noexcept -> bool;
    /// @brief Convert uint64 to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64 value = 42ul;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(uint64 value) noexcept -> bool;
    /// @brief Convert slong to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(xtd::ulong value) noexcept -> bool;
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// bool result = convert::to_boolean(value);
    /// ```
    [[nodiscard]] static auto to_boolean(const xtd::string& value) -> bool;
    /// @cond
    [[nodiscard]] static auto to_boolean(const std::string& value) -> bool;
    [[nodiscard]] static auto to_boolean(const std::u8string& value) -> bool;
    [[nodiscard]] static auto to_boolean(const std::u16string& value) -> bool;
    [[nodiscard]] static auto to_boolean(const std::u32string& value) -> bool;
    [[nodiscard]] static auto to_boolean(const std::wstring& value) -> bool;
    [[nodiscard]] static auto to_boolean(const char* value) -> bool;
    [[nodiscard]] static auto to_boolean(char* value) -> bool;
    [[nodiscard]] static auto to_boolean(const char8* value) -> bool;
    [[nodiscard]] static auto to_boolean(char8* value) -> bool;
    [[nodiscard]] static auto to_boolean(const char16* value) -> bool;
    [[nodiscard]] static auto to_boolean(char16* value) -> bool;
    [[nodiscard]] static auto to_boolean(const char32* value) -> bool;
    [[nodiscard]] static auto to_boolean(char32* value) -> bool;
    [[nodiscard]] static auto to_boolean(const wchar* value) -> bool;
    [[nodiscard]] static auto to_boolean(wchar* value) -> bool;
    /// @endcond
    /// @brief Convert type_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// bool result = convert::to_boolean(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_boolean(type_t value) noexcept -> bool {
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
    [[nodiscard]] static auto to_byte(xtd::any value) -> xtd::byte;
    /// @brief Convert bool to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(bool value) noexcept -> xtd::byte;
    /// @brief Convert xtd::byte to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(xtd::byte value) noexcept -> xtd::byte;
    /// @brief Convert char to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(char value) noexcept -> xtd::byte;
    /// @brief Convert char8 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(char8 value) noexcept -> xtd::byte;
    /// @brief Convert char16 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(char16 value) -> xtd::byte;
    /// @brief Convert char32 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(char32 value) -> xtd::byte;
    /// @brief Convert char32 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(wchar value) -> xtd::byte;
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
    [[nodiscard]] static auto to_byte(decimal value) -> xtd::byte;
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
    [[nodiscard]] static auto to_byte(double value) -> xtd::byte;
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
    [[nodiscard]] static auto to_byte(float value) -> xtd::byte;
    /// @brief Convert int16 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(int16 value) -> xtd::byte;
    /// @brief Convert int32 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(int32 value) -> xtd::byte;
    /// @brief Convert int64 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(int64 value) -> xtd::byte;
    /// @brief Convert slong to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(slong value) -> xtd::byte;
    /// @brief Convert sbyte to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(sbyte value) -> xtd::byte;
    /// @brief Convert uint16 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(uint16 value) -> xtd::byte;
    /// @brief Convert uint32 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(uint32 value) -> xtd::byte;
    /// @brief Convert uint64 to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(uint64 value) -> xtd::byte;
    /// @brief Convert slong to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(xtd::ulong value) -> xtd::byte;
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    [[nodiscard]] static auto to_byte(const xtd::string& value) -> xtd::byte;
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
    [[nodiscard]] static auto to_byte(const xtd::string& value, xtd::byte from_base) -> xtd::byte;
    /// @cond
    [[nodiscard]] static auto to_byte(const std::string& value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const std::u8string& value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const std::u16string& value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const std::u32string& value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const std::wstring& value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const char* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(char* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const char8* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(char8* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const char16* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(char16* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const char32* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(char32* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(const wchar* value) -> xtd::byte;
    [[nodiscard]] static auto to_byte(wchar* value) -> xtd::byte;
    /// @endcond
    /// @brief Convert type_t to byte.
    /// @param value object to convert.
    /// @return A new xtd::byte object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// xtd::byte result = convert::to_byte(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_byte(type_t value) noexcept -> xtd::byte {
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
    [[nodiscard]] static auto to_char(xtd::any value) -> char;
    /// @brief Convert bool to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(bool value) -> char;
    /// @brief Convert xtd::byte to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(xtd::byte value) noexcept -> char;
    /// @brief Convert char to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(char value) noexcept -> char;
    /// @brief Convert char8 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(char8 value) noexcept -> char;
    /// @brief Convert char16 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(char16 value) -> char;
    /// @brief Convert char32 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(char32 value) -> char;
    /// @brief Convert char32 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(wchar value) -> char;
    /// @brief Convert decimal to char.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(decimal value) -> char;
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
    [[nodiscard]] static auto to_char(double value) -> char;
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
    [[nodiscard]] static auto to_char(float value) -> char;
    /// @brief Convert int16 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(int16 value) -> char;
    /// @brief Convert int32 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(int32 value) -> char;
    /// @brief Convert int64 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(int64 value) -> char;
    /// @brief Convert slong to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(slong value) -> char;
    /// @brief Convert sbyte to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(sbyte value) -> char;
    /// @brief Convert uint16 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(uint16 value) -> char;
    /// @brief Convert uint32 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(uint32 value) -> char;
    /// @brief Convert uint64 to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(uint64 value) -> char;
    /// @brief Convert slong to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(xtd::ulong value) -> char;
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// char result = convert::to_char(value);
    /// ```
    [[nodiscard]] static auto to_char(const xtd::string& value) -> char;
    /// @cond
    [[nodiscard]] static auto to_char(const std::string& value) -> char;
    [[nodiscard]] static auto to_char(const std::u8string& value) -> char;
    [[nodiscard]] static auto to_char(const std::u16string& value) -> char;
    [[nodiscard]] static auto to_char(const std::u32string& value) -> char;
    [[nodiscard]] static auto to_char(const std::wstring& value) -> char;
    [[nodiscard]] static auto to_char(const char* value) -> char;
    [[nodiscard]] static auto to_char(char* value) -> char;
    [[nodiscard]] static auto to_char(const char8* value) -> char;
    [[nodiscard]] static auto to_char(char8* value) -> char;
    [[nodiscard]] static auto to_char(const char16* value) -> char;
    [[nodiscard]] static auto to_char(char16* value) -> char;
    [[nodiscard]] static auto to_char(const char32* value) -> char;
    [[nodiscard]] static auto to_char(char32* value) -> char;
    [[nodiscard]] static auto to_char(const wchar* value) -> char;
    [[nodiscard]] static auto to_char(wchar* value) -> char;
    /// @endcond
    /// @brief Convert type_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// char result = convert::to_char(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_char(type_t value) noexcept -> char {
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
    [[nodiscard]] static auto to_char8(xtd::any value) -> xtd::char8;
    /// @brief Convert bool to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(bool value) -> xtd::char8;
    /// @brief Convert xtd::byte to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(xtd::byte value) noexcept -> xtd::char8;
    /// @brief Convert char to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(char value) noexcept -> xtd::char8;
    /// @brief Convert char8 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(char8 value) noexcept -> xtd::char8;
    /// @brief Convert char16 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(char16 value) -> xtd::char8;
    /// @brief Convert char32 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(char32 value) -> xtd::char8;
    /// @brief Convert char32 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(wchar value) -> xtd::char8;
    /// @brief Convert decimal to char8.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(decimal value) -> xtd::char8;
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
    [[nodiscard]] static auto to_char8(double value) -> xtd::char8;
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
    [[nodiscard]] static auto to_char8(float value) -> xtd::char8;
    /// @brief Convert int16 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(int16 value) -> xtd::char8;
    /// @brief Convert int32 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(int32 value) -> xtd::char8;
    /// @brief Convert int64 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(int64 value) -> xtd::char8;
    /// @brief Convert slong to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(slong value) -> xtd::char8;
    /// @brief Convert sbyte to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(sbyte value) -> xtd::char8;
    /// @brief Convert uint16 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(uint16 value) -> xtd::char8;
    /// @brief Convert uint32 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(uint32 value) -> xtd::char8;
    /// @brief Convert uint64 to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(uint64 value) -> xtd::char8;
    /// @brief Convert slong to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(xtd::ulong value) -> xtd::char8;
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// char8 result = convert::to_char8(value);
    /// ```
    [[nodiscard]] static auto to_char8(const xtd::string& value) -> xtd::char8;
    /// @cond
    [[nodiscard]] static auto to_char8(const std::string& value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const std::u8string& value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const std::u16string& value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const std::u32string& value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const std::wstring& value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const char* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(char* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const char8* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(char8* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const char16* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(char16* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const char32* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(char32* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(const wchar* value) -> xtd::char8;
    [[nodiscard]] static auto to_char8(wchar* value) -> xtd::char8;
    /// @endcond
    /// @brief Convert type_t to char8.
    /// @param value object to convert.
    /// @return A new char8 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// char8 result = convert::to_char8(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_char8(type_t value) noexcept -> xtd::char8 {
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
    [[nodiscard]] static auto to_char16(xtd::any value) -> xtd::char16;
    /// @brief Convert bool to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(bool value) -> xtd::char16;
    /// @brief Convert xtd::byte to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(xtd::byte value) noexcept -> xtd::char16;
    /// @brief Convert char to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(char value) noexcept -> xtd::char16;
    /// @brief Convert char8 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(char8 value) noexcept -> xtd::char16;
    /// @brief Convert char16 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(char16 value) noexcept -> xtd::char16;
    /// @brief Convert char32 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(char32 value) -> xtd::char16;
    /// @brief Convert char32 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(wchar value) noexcept -> xtd::char16;
    /// @brief Convert decimal to char16.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(decimal value) -> xtd::char16;
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
    [[nodiscard]] static auto to_char16(double value) -> xtd::char16;
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
    [[nodiscard]] static auto to_char16(float value) -> xtd::char16;
    /// @brief Convert int16 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(int16 value) -> xtd::char16;
    /// @brief Convert int32 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(int32 value) -> xtd::char16;
    /// @brief Convert int64 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(int64 value) -> xtd::char16;
    /// @brief Convert slong to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(slong value) -> xtd::char16;
    /// @brief Convert sbyte to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(sbyte value) -> xtd::char16;
    /// @brief Convert uint16 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(uint16 value) noexcept -> xtd::char16;
    /// @brief Convert uint32 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(uint32 value) -> xtd::char16;
    /// @brief Convert uint64 to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(uint64 value) -> xtd::char16;
    /// @brief Convert slong to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(xtd::ulong value) -> xtd::char16;
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// char16 result = convert::to_char16(value);
    /// ```
    [[nodiscard]] static auto to_char16(const xtd::string& value) -> xtd::char16;
    /// @cond
    [[nodiscard]] static auto to_char16(const std::string& value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const std::u8string& value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const std::u16string& value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const std::u32string& value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const std::wstring& value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const char* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(char* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const char8* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(char8* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const char16* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(char16* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const char32* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(char32* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(const wchar* value) -> xtd::char16;
    [[nodiscard]] static auto to_char16(wchar* value) -> xtd::char16;
    /// @endcond
    /// @brief Convert type_t to char16.
    /// @param value object to convert.
    /// @return A new char16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// char16 result = convert::to_char16(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_char16(type_t value) noexcept -> xtd::char16 {
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
    [[nodiscard]] static auto to_char32(xtd::any value) -> xtd::char32;
    /// @brief Convert bool to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(bool value) -> xtd::char32;
    /// @brief Convert xtd::byte to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(xtd::byte value) noexcept -> xtd::char32;
    /// @brief Convert char to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(char value) noexcept -> xtd::char32;
    /// @brief Convert char8 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(char8 value) noexcept -> xtd::char32;
    /// @brief Convert char16 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(char16 value) noexcept -> xtd::char32;
    /// @brief Convert char32 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(char32 value) noexcept -> xtd::char32;
    /// @brief Convert char32 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(wchar value) noexcept -> xtd::char32;
    /// @brief Convert decimal to char32.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(decimal value) -> xtd::char32;
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
    [[nodiscard]] static auto to_char32(double value) -> xtd::char32;
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
    [[nodiscard]] static auto to_char32(float value) -> xtd::char32;
    /// @brief Convert int16 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(int16 value) -> xtd::char32;
    /// @brief Convert int32 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(int32 value) -> xtd::char32;
    /// @brief Convert int64 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(int64 value) -> xtd::char32;
    /// @brief Convert slong to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(slong value) -> xtd::char32;
    /// @brief Convert sbyte to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(sbyte value) -> xtd::char32;
    /// @brief Convert uint16 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(uint16 value) noexcept -> xtd::char32;
    /// @brief Convert uint32 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(uint32 value) noexcept -> xtd::char32;
    /// @brief Convert uint64 to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(uint64 value) -> xtd::char32;
    /// @brief Convert slong to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(xtd::ulong value) -> xtd::char32;
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// char32 result = convert::to_char32(value);
    /// ```
    [[nodiscard]] static auto to_char32(const xtd::string& value) -> xtd::char32;
    /// @cond
    [[nodiscard]] static auto to_char32(const std::string& value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const std::u8string& value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const std::u16string& value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const std::u32string& value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const std::wstring& value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const char* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(char* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const char8* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(char8* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const char16* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(char16* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const char32* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(char32* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(const wchar* value) -> xtd::char32;
    [[nodiscard]] static auto to_char32(wchar* value) -> xtd::char32;
    /// @endcond
    /// @brief Convert type_t to char32.
    /// @param value object to convert.
    /// @return A new char32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// char32 result = convert::to_char32(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_char32(type_t value) noexcept -> xtd::char32 {
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
    [[nodiscard]] static auto to_wchar(xtd::any value) -> xtd::wchar;
    /// @brief Convert bool to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(bool value) -> xtd::wchar;
    /// @brief Convert xtd::byte to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(xtd::byte value) noexcept -> xtd::wchar;
    /// @brief Convert char to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(char value) noexcept -> xtd::wchar;
    /// @brief Convert char8 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(char8 value) noexcept -> xtd::wchar;
    /// @brief Convert char16 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(char16 value) noexcept -> xtd::wchar;
    /// @brief Convert char32 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(char32 value) -> xtd::wchar;
    /// @brief Convert char32 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(wchar value) noexcept -> xtd::wchar;
    /// @brief Convert decimal to wchar.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(decimal value) -> xtd::wchar;
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
    [[nodiscard]] static auto to_wchar(double value) -> xtd::wchar;
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
    [[nodiscard]] static auto to_wchar(float value) -> xtd::wchar;
    /// @brief Convert int16 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(int16 value) -> xtd::wchar;
    /// @brief Convert int32 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(int32 value) -> xtd::wchar;
    /// @brief Convert int64 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(int64 value) -> xtd::wchar;
    /// @brief Convert slong to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(slong value) -> xtd::wchar;
    /// @brief Convert sbyte to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(sbyte value) -> xtd::wchar;
    /// @brief Convert uint16 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(uint16 value) noexcept -> xtd::wchar;
    /// @brief Convert uint32 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(uint32 value) -> xtd::wchar;
    /// @brief Convert uint64 to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(uint64 value) -> xtd::wchar;
    /// @brief Convert slong to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(xtd::ulong value) -> xtd::wchar;
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// wchar result = convert::to_wchar(value);
    /// ```
    [[nodiscard]] static auto to_wchar(const xtd::string& value) -> xtd::wchar;
    /// @cond
    [[nodiscard]] static auto to_wchar(const std::string& value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const std::u8string& value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const std::u16string& value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const std::u32string& value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const std::wstring& value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const char* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(char* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const char8* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(char8* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const char16* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(char16* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const char32* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(char32* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(const wchar* value) -> xtd::wchar;
    [[nodiscard]] static auto to_wchar(wchar* value) -> xtd::wchar;
    /// @endcond
    /// @brief Convert type_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// wchar result = convert::to_wchar(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_wchar(type_t value) noexcept -> xtd::wchar {
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
    [[nodiscard]] static auto to_decimal(xtd::any value) -> xtd::decimal;
    /// @brief Convert bool to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(bool value) noexcept -> xtd::decimal;
    /// @brief Convert xtd::byte to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(xtd::byte value) noexcept -> xtd::decimal;
    /// @brief Convert char to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(char value) noexcept -> xtd::decimal;
    /// @brief Convert char8 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(char8 value) noexcept -> xtd::decimal;
    /// @brief Convert char16 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(char16 value) noexcept -> xtd::decimal;
    /// @brief Convert char32 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(char32 value) noexcept -> xtd::decimal;
    /// @brief Convert char32 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(wchar value) noexcept -> xtd::decimal;
    /// @brief Convert decimal to decimal.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(decimal value) noexcept -> xtd::decimal;
    /// @brief Convert double to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(double value) noexcept -> xtd::decimal;
    /// @brief Convert float to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(float value) noexcept -> xtd::decimal;
    /// @brief Convert int16 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(int16 value) noexcept -> xtd::decimal;
    /// @brief Convert int32 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(int32 value) noexcept -> xtd::decimal;
    /// @brief Convert int64 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(int64 value) noexcept -> xtd::decimal;
    /// @brief Convert slong to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(slong value) noexcept -> xtd::decimal;
    /// @brief Convert sbyte to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(sbyte value) noexcept -> xtd::decimal;
    /// @brief Convert uint16 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(uint16 value) noexcept -> xtd::decimal;
    /// @brief Convert uint32 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(uint32 value) noexcept -> xtd::decimal;
    /// @brief Convert uint64 to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(uint64 value) noexcept -> xtd::decimal;
    /// @brief Convert slong to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(xtd::ulong value) noexcept -> xtd::decimal;
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// decimal result = convert::to_decimal(value);
    /// ```
    [[nodiscard]] static auto to_decimal(const xtd::string& value) -> xtd::decimal;
    /// @cond
    [[nodiscard]] static auto to_decimal(const std::string& value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const std::u8string& value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const std::u16string& value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const std::u32string& value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const std::wstring& value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const char* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(char* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const char8* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(char8* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const char16* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(char16* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const char32* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(char32* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(const wchar* value) -> xtd::decimal;
    [[nodiscard]] static auto to_decimal(wchar* value) -> xtd::decimal;
    /// @endcond
    /// @brief Convert type_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// decimal result = convert::to_decimal(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_decimal(type_t value) noexcept -> xtd::decimal {
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
    [[nodiscard]] static auto to_double(xtd::any value) -> double;
    /// @brief Convert bool to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(bool value) noexcept -> double;
    /// @brief Convert xtd::byte to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(xtd::byte value) noexcept -> double;
    /// @brief Convert char to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(char value) noexcept -> double;
    /// @brief Convert char8 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(char8 value) noexcept -> double;
    /// @brief Convert char16 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(char16 value) noexcept -> double;
    /// @brief Convert char32 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(char32 value) noexcept -> double;
    /// @brief Convert char32 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(wchar value) noexcept -> double;
    /// @brief Convert decimal to double.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(decimal value) noexcept -> double;
    /// @brief Convert double to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(double value) noexcept -> double;
    /// @brief Convert float to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(float value) noexcept -> double;
    /// @brief Convert int16 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(int16 value) noexcept -> double;
    /// @brief Convert int32 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(int32 value) noexcept -> double;
    /// @brief Convert int64 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(int64 value) noexcept -> double;
    /// @brief Convert slong to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(slong value) noexcept -> double;
    /// @brief Convert sbyte to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(sbyte value) noexcept -> double;
    /// @brief Convert uint16 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(uint16 value) noexcept -> double;
    /// @brief Convert uint32 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(uint32 value) noexcept -> double;
    /// @brief Convert uint64 to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(uint64 value) noexcept -> double;
    /// @brief Convert slong to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(xtd::ulong value) noexcept -> double;
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// double result = convert::to_double(value);
    /// ```
    [[nodiscard]] static auto to_double(const xtd::string& value) -> double;
    /// @cond
    [[nodiscard]] static auto to_double(const std::string& value) -> double;
    [[nodiscard]] static auto to_double(const std::u8string& value) -> double;
    [[nodiscard]] static auto to_double(const std::u16string& value) -> double;
    [[nodiscard]] static auto to_double(const std::u32string& value) -> double;
    [[nodiscard]] static auto to_double(const std::wstring& value) -> double;
    [[nodiscard]] static auto to_double(const char* value) -> double;
    [[nodiscard]] static auto to_double(char* value) -> double;
    [[nodiscard]] static auto to_double(const char8* value) -> double;
    [[nodiscard]] static auto to_double(char8* value) -> double;
    [[nodiscard]] static auto to_double(const char16* value) -> double;
    [[nodiscard]] static auto to_double(char16* value) -> double;
    [[nodiscard]] static auto to_double(const char32* value) -> double;
    [[nodiscard]] static auto to_double(char32* value) -> double;
    [[nodiscard]] static auto to_double(const wchar* value) -> double;
    [[nodiscard]] static auto to_double(wchar* value) -> double;
    /// @endcond
    /// @brief Convert type_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// double result = convert::to_double(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_double(type_t value) noexcept -> double {
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
    [[nodiscard]] static auto to_single(xtd::any value) -> float;
    /// @brief Convert bool to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(bool value) noexcept -> float;
    /// @brief Convert xtd::byte to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(xtd::byte value) noexcept -> float;
    /// @brief Convert char to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(char value) noexcept -> float;
    /// @brief Convert char8 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(char8 value) noexcept -> float;
    /// @brief Convert char16 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(char16 value) noexcept -> float;
    /// @brief Convert char32 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(char32 value) noexcept -> float;
    /// @brief Convert char32 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(wchar value) noexcept -> float;
    /// @brief Convert decimal to single.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(decimal value) noexcept -> float;
    /// @brief Convert double to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(double value) noexcept -> float;
    /// @brief Convert float to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(float value) noexcept -> float;
    /// @brief Convert int16 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(int16 value) noexcept -> float;
    /// @brief Convert int32 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(int32 value) noexcept -> float;
    /// @brief Convert int64 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(int64 value) noexcept -> float;
    /// @brief Convert slong to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(slong value) noexcept -> float;
    /// @brief Convert sbyte to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(sbyte value) noexcept -> float;
    /// @brief Convert uint16 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(uint16 value) noexcept -> float;
    /// @brief Convert uint32 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(uint32 value) noexcept -> float;
    /// @brief Convert uint64 to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(uint64 value) noexcept -> float;
    /// @brief Convert slong to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(xtd::ulong value) noexcept -> float;
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// float result = convert::to_single(value);
    /// ```
    [[nodiscard]] static auto to_single(const xtd::string& value) -> float;
    /// @cond
    [[nodiscard]] static auto to_single(const std::string& value) -> float;
    [[nodiscard]] static auto to_single(const std::u8string& value) -> float;
    [[nodiscard]] static auto to_single(const std::u16string& value) -> float;
    [[nodiscard]] static auto to_single(const std::u32string& value) -> float;
    [[nodiscard]] static auto to_single(const std::wstring& value) -> float;
    [[nodiscard]] static auto to_single(const char* value) -> float;
    [[nodiscard]] static auto to_single(char* value) -> float;
    [[nodiscard]] static auto to_single(const char8* value) -> float;
    [[nodiscard]] static auto to_single(char8* value) -> float;
    [[nodiscard]] static auto to_single(const char16* value) -> float;
    [[nodiscard]] static auto to_single(char16* value) -> float;
    [[nodiscard]] static auto to_single(const char32* value) -> float;
    [[nodiscard]] static auto to_single(char32* value) -> float;
    [[nodiscard]] static auto to_single(const wchar* value) -> float;
    [[nodiscard]] static auto to_single(wchar* value) -> float;
    /// @endcond
    /// @brief Convert type_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// float result = convert::to_single(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_single(type_t value) noexcept -> float {
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
    [[nodiscard]] static auto to_int16(xtd::any value) -> xtd::int16;
    /// @brief Convert bool to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(bool value) noexcept -> xtd::int16;
    /// @brief Convert xtd::byte to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(xtd::byte value) noexcept -> xtd::int16;
    /// @brief Convert char to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(char value) noexcept -> xtd::int16;
    /// @brief Convert char8 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(char8 value) noexcept -> xtd::int16;
    /// @brief Convert char16 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(char16 value) noexcept -> xtd::int16;
    /// @brief Convert char32 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(char32 value) -> xtd::int16;
    /// @brief Convert char32 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(wchar value) noexcept -> xtd::int16;
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
    [[nodiscard]] static auto to_int16(decimal value) -> xtd::int16;
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
    [[nodiscard]] static auto to_int16(double value) -> xtd::int16;
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
    [[nodiscard]] static auto to_int16(float value) -> xtd::int16;
    /// @brief Convert int16 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(int16 value) noexcept -> xtd::int16;
    /// @brief Convert int32 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(int32 value) -> xtd::int16;
    /// @brief Convert int64 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(int64 value) -> xtd::int16;
    /// @brief Convert slong to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(slong value) -> xtd::int16;
    /// @brief Convert sbyte to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(sbyte value) noexcept -> xtd::int16;
    /// @brief Convert uint16 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(uint16 value) -> xtd::int16;
    /// @brief Convert uint32 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(uint32 value) -> xtd::int16;
    /// @brief Convert uint64 to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(uint64 value) -> xtd::int16;
    /// @brief Convert slong to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(xtd::ulong value) -> xtd::int16;
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int16 result = convert::to_int16(value);
    /// ```
    [[nodiscard]] static auto to_int16(const xtd::string& value) -> xtd::int16;
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
    [[nodiscard]] static auto to_int16(const xtd::string& value, xtd::byte from_base) -> xtd::int16;
    /// @cond
    [[nodiscard]] static auto to_int16(const std::string& value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const std::u8string& value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const std::u16string& value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const std::u32string& value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const std::wstring& value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const char* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(char* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const char8* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(char8* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const char16* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(char16* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const char32* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(char32* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(const wchar* value) -> xtd::int16;
    [[nodiscard]] static auto to_int16(wchar* value) -> xtd::int16;
    /// @endcond
    /// @brief Convert type_t to int16.
    /// @param value object to convert.
    /// @return A new int16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// int16 result = convert::to_int16(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_int16(type_t value) noexcept -> xtd::int16 {
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
    [[nodiscard]] static auto to_int32(xtd::any value) -> xtd::int32;
    /// @brief Convert bool to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(bool value) noexcept -> xtd::int32;
    /// @brief Convert xtd::byte to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(xtd::byte value) noexcept -> xtd::int32;
    /// @brief Convert char to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(char value) noexcept -> xtd::int32;
    /// @brief Convert char8 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(char8 value) noexcept -> xtd::int32;
    /// @brief Convert char16 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(char16 value) noexcept -> xtd::int32;
    /// @brief Convert char32 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(char32 value) noexcept -> xtd::int32;
    /// @brief Convert char32 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(wchar value) noexcept -> xtd::int32;
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
    [[nodiscard]] static auto to_int32(decimal value) -> xtd::int32;
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
    [[nodiscard]] static auto to_int32(double value) -> xtd::int32;
    /// @brief Convert float to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(float value) noexcept -> xtd::int32;
    /// @brief Convert int16 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(int16 value) noexcept -> xtd::int32;
    /// @brief Convert int32 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(int32 value) noexcept -> xtd::int32;
    /// @brief Convert int64 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(int64 value) -> xtd::int32;
    /// @brief Convert slong to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(slong value) -> xtd::int32;
    /// @brief Convert sbyte to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(sbyte value) noexcept -> xtd::int32;
    /// @brief Convert uint16 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(uint16 value) noexcept -> xtd::int32;
    /// @brief Convert uint32 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(uint32 value) -> xtd::int32;
    /// @brief Convert uint64 to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(uint64 value) -> xtd::int32;
    /// @brief Convert slong to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(xtd::ulong value) -> xtd::int32;
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int32 result = convert::to_int32(value);
    /// ```
    [[nodiscard]] static auto to_int32(const xtd::string& value) -> xtd::int32;
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
    [[nodiscard]] static auto to_int32(const xtd::string& value, xtd::byte from_base) -> xtd::int32;
    /// @cond
    [[nodiscard]] static auto to_int32(const std::string& value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const std::u8string& value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const std::u16string& value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const std::u32string& value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const std::wstring& value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const char* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(char* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const char8* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(char8* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const char16* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(char16* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const char32* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(char32* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(const wchar* value) -> xtd::int32;
    [[nodiscard]] static auto to_int32(wchar* value) -> xtd::int32;
    /// @endcond
    /// @brief Convert type_t to int32.
    /// @param value object to convert.
    /// @return A new int32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// int32 result = convert::to_int32(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_int32(type_t value) noexcept -> xtd::int32 {
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
    [[nodiscard]] static auto to_int64(xtd::any value) -> xtd::int64;
    /// @brief Convert bool to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(bool value) noexcept -> xtd::int64;
    /// @brief Convert xtd::byte to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(xtd::byte value) noexcept -> xtd::int64;
    /// @brief Convert char to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(char value) noexcept -> xtd::int64;
    /// @brief Convert char8 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(char8 value) noexcept -> xtd::int64;
    /// @brief Convert char16 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(char16 value) noexcept -> xtd::int64;
    /// @brief Convert char32 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(char32 value) noexcept -> xtd::int64;
    /// @brief Convert char32 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(wchar value) noexcept -> xtd::int64;
    /// @brief Convert decimal to int64.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(decimal value) noexcept -> xtd::int64;
    /// @brief Convert double to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(double value) noexcept -> xtd::int64;
    /// @brief Convert float to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(float value) noexcept -> xtd::int64;
    /// @brief Convert int16 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(int16 value) noexcept -> xtd::int64;
    /// @brief Convert int32 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(int32 value) noexcept -> xtd::int64;
    /// @brief Convert int64 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(int64 value) noexcept -> xtd::int64;
    /// @brief Convert slong to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(slong value) noexcept -> xtd::int64;
    /// @brief Convert sbyte to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(sbyte value) noexcept -> xtd::int64;
    /// @brief Convert uint16 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(uint16 value) noexcept -> xtd::int64;
    /// @brief Convert uint32 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(uint32 value) noexcept -> xtd::int64;
    /// @brief Convert uint64 to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(uint64 value) -> xtd::int64;
    /// @brief Convert slong to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(xtd::ulong value) -> xtd::int64;
    /// @brief Convert string to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// int64 result = convert::to_int64(value);
    /// ```
    [[nodiscard]] static auto to_int64(const xtd::string& value) -> xtd::int64;
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
    [[nodiscard]] static auto to_int64(const xtd::string& value, xtd::byte from_base) -> xtd::int64;
    /// @cond
    [[nodiscard]] static auto to_int64(const std::string& value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const std::u8string& value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const std::u16string& value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const std::u32string& value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const std::wstring& value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const char* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(char* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const char8* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(char8* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const char16* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(char16* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const char32* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(char32* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(const wchar* value) -> xtd::int64;
    [[nodiscard]] static auto to_int64(wchar* value) -> xtd::int64;
    /// @endcond
    /// @brief Convert type_t to int64.
    /// @param value object to convert.
    /// @return A new int64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// int64 result = convert::to_int64(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_int64(type_t value) noexcept -> xtd::int64 {
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
    [[nodiscard]] static auto to_llong(xtd::any value) -> xtd::slong;
    /// @brief Convert bool to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(bool value) noexcept -> xtd::slong;
    /// @brief Convert xtd::byte to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(xtd::byte value) noexcept -> xtd::slong;
    /// @brief Convert char to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(char value) noexcept -> xtd::slong;
    /// @brief Convert char8 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(char8 value) noexcept -> xtd::slong;
    /// @brief Convert char16 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(char16 value) noexcept -> xtd::slong;
    /// @brief Convert char32 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(char32 value) noexcept -> xtd::slong;
    /// @brief Convert char32 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(wchar value) noexcept -> xtd::slong;
    /// @brief Convert decimal to slong.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// decimal value = 42.50l;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(decimal value) noexcept -> xtd::slong;
    /// @brief Convert double to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// double value = 42.50;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(double value) noexcept -> xtd::slong;
    /// @brief Convert float to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// ```cpp
    /// float value = 42.50f;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(float value) noexcept -> xtd::slong;
    /// @brief Convert int16 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(int16 value) noexcept -> xtd::slong;
    /// @brief Convert int32 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(int32 value) noexcept -> xtd::slong;
    /// @brief Convert int64 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(int64 value) noexcept -> xtd::slong;
    /// @brief Convert slong to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(slong value) noexcept -> xtd::slong;
    /// @brief Convert sbyte to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(sbyte value) noexcept -> xtd::slong;
    /// @brief Convert uint16 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(uint16 value) noexcept -> xtd::slong;
    /// @brief Convert uint32 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(uint32 value) noexcept -> xtd::slong;
    /// @brief Convert uint64 to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(uint64 value) -> xtd::slong;
    /// @brief Convert slong to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(xtd::ulong value) -> xtd::slong;
    /// @brief Convert string to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// slong result = convert::to_llong(value);
    /// ```
    [[nodiscard]] static auto to_llong(const xtd::string& value) -> xtd::slong;
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
    [[nodiscard]] static auto to_llong(const xtd::string& value, xtd::byte from_base) -> xtd::slong;
    /// @cond
    [[nodiscard]] static auto to_llong(const std::string& value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const std::u8string& value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const std::u16string& value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const std::u32string& value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const std::wstring& value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const char* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(char* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const char8* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(char8* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const char16* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(char16* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const char32* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(char32* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(const wchar* value) -> xtd::slong;
    [[nodiscard]] static auto to_llong(wchar* value) -> xtd::slong;
    /// @endcond
    /// @brief Convert type_t to slong.
    /// @param value object to convert.
    /// @return A new slong object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// slong result = convert::to_llong(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_llong(type_t value) noexcept -> xtd::slong {
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
    [[nodiscard]] static auto to_sbyte(xtd::any value) -> xtd::sbyte;
    /// @brief Convert bool to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(bool value) noexcept -> xtd::sbyte;
    /// @brief Convert xtd::byte to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(xtd::byte value) noexcept -> xtd::sbyte;
    /// @brief Convert char to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(char value) noexcept -> xtd::sbyte;
    /// @brief Convert char8 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(char8 value) noexcept -> xtd::sbyte;
    /// @brief Convert char16 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(char16 value) -> xtd::sbyte;
    /// @brief Convert char32 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(char32 value) -> xtd::sbyte;
    /// @brief Convert char32 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(wchar value) -> xtd::sbyte;
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
    [[nodiscard]] static auto to_sbyte(decimal value) -> xtd::sbyte;
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
    [[nodiscard]] static auto to_sbyte(double value) -> xtd::sbyte;
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
    [[nodiscard]] static auto to_sbyte(float value) -> xtd::sbyte;
    /// @brief Convert int16 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(int16 value) -> xtd::sbyte;
    /// @brief Convert int32 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(int32 value) -> xtd::sbyte;
    /// @brief Convert int64 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(int64 value) -> xtd::sbyte;
    /// @brief Convert slong to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(slong value) -> xtd::sbyte;
    /// @brief Convert sbyte to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(sbyte value) -> xtd::sbyte;
    /// @brief Convert uint16 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(uint16 value) -> xtd::sbyte;
    /// @brief Convert uint32 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(uint32 value) -> xtd::sbyte;
    /// @brief Convert uint64 to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(uint64 value) -> xtd::sbyte;
    /// @brief Convert slong to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(xtd::ulong value) -> xtd::sbyte;
    /// @brief Convert string to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    [[nodiscard]] static auto to_sbyte(const xtd::string& value) -> xtd::sbyte;
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
    [[nodiscard]] static auto to_sbyte(const xtd::string& value, xtd::byte from_base) -> xtd::sbyte;
    /// @cond
    [[nodiscard]] static auto to_sbyte(const std::string& value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const std::u8string& value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const std::u16string& value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const std::u32string& value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const std::wstring& value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const char* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(char* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const char8* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(char8* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const char16* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(char16* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const char32* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(char32* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(const wchar* value) -> xtd::sbyte;
    [[nodiscard]] static auto to_sbyte(wchar* value) -> xtd::sbyte;
    /// @endcond
    /// @brief Convert type_t to sbyte.
    /// @param value object to convert.
    /// @return A new sbyte object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// sbyte result = convert::to_sbyte(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_sbyte(type_t value) noexcept -> xtd::sbyte {
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
    [[nodiscard]] static auto to_uint16(xtd::any value) -> xtd::uint16;
    /// @brief Convert bool to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(bool value) noexcept -> xtd::uint16;
    /// @brief Convert xtd::byte to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(xtd::byte value) noexcept -> xtd::uint16;
    /// @brief Convert char to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(char value) noexcept -> xtd::uint16;
    /// @brief Convert char8 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(char8 value) noexcept -> xtd::uint16;
    /// @brief Convert char16 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(char16 value) noexcept -> xtd::uint16;
    /// @brief Convert char32 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(char32 value) -> xtd::uint16;
    /// @brief Convert char32 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(wchar value) noexcept -> xtd::uint16;
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
    [[nodiscard]] static auto to_uint16(decimal value) -> xtd::uint16;
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
    [[nodiscard]] static auto to_uint16(double value) -> xtd::uint16;
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
    [[nodiscard]] static auto to_uint16(float value) -> xtd::uint16;
    /// @brief Convert int16 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(int16 value) -> xtd::uint16;
    /// @brief Convert int32 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(int32 value) -> xtd::uint16;
    /// @brief Convert int64 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(int64 value) -> xtd::uint16;
    /// @brief Convert slong to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(slong value) -> xtd::uint16;
    /// @brief Convert sbyte to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(sbyte value) -> xtd::uint16;
    /// @brief Convert uint16 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(uint16 value) noexcept -> xtd::uint16;
    /// @brief Convert uint32 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(uint32 value) -> xtd::uint16;
    /// @brief Convert uint64 to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(uint64 value) -> xtd::uint16;
    /// @brief Convert slong to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(xtd::ulong value) -> xtd::uint16;
    /// @brief Convert string to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uint16 result = convert::to_uint16(value);
    /// ```
    [[nodiscard]] static auto to_uint16(const xtd::string& value) -> xtd::uint16;
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
    [[nodiscard]] static auto to_uint16(const xtd::string& value, xtd::byte from_base) -> xtd::uint16;
    /// @cond
    [[nodiscard]] static auto to_uint16(const std::string& value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const std::u8string& value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const std::u16string& value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const std::u32string& value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const std::wstring& value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const char* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(char* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const char8* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(char8* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const char16* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(char16* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const char32* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(char32* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(const wchar* value) -> xtd::uint16;
    [[nodiscard]] static auto to_uint16(wchar* value) -> xtd::uint16;
    /// @endcond
    /// @brief Convert type_t to uint16.
    /// @param value object to convert.
    /// @return A new uint16 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// uint16 result = convert::to_uint16(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_uint16(type_t value) noexcept -> xtd::uint16 {
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
    [[nodiscard]] static auto to_uint32(xtd::any value) -> xtd::uint32;
    /// @brief Convert bool to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(bool value) noexcept -> xtd::uint32;
    /// @brief Convert xtd::byte to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(xtd::byte value) noexcept -> xtd::uint32;
    /// @brief Convert char to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(char value) noexcept -> xtd::uint32;
    /// @brief Convert char8 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(char8 value) noexcept -> xtd::uint32;
    /// @brief Convert char16 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(char16 value) noexcept -> xtd::uint32;
    /// @brief Convert char32 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(char32 value) noexcept -> xtd::uint32;
    /// @brief Convert char32 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(wchar value) noexcept -> xtd::uint32;
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
    [[nodiscard]] static auto to_uint32(decimal value) -> xtd::uint32;
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
    [[nodiscard]] static auto to_uint32(double value) -> xtd::uint32;
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
    [[nodiscard]] static auto to_uint32(float value) -> xtd::uint32;
    /// @brief Convert int16 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(int16 value) -> xtd::uint32;
    /// @brief Convert int32 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(int32 value) -> xtd::uint32;
    /// @brief Convert int64 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(int64 value) -> xtd::uint32;
    /// @brief Convert slong to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(slong value) -> xtd::uint32;
    /// @brief Convert sbyte to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(sbyte value) -> xtd::uint32;
    /// @brief Convert uint16 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(uint16 value) noexcept -> xtd::uint32;
    /// @brief Convert uint32 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(uint32 value) noexcept -> xtd::uint32;
    /// @brief Convert uint64 to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(uint64 value) -> xtd::uint32;
    /// @brief Convert slong to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(xtd::ulong value) -> xtd::uint32;
    /// @brief Convert string to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uint32 result = convert::to_uint32(value);
    /// ```
    [[nodiscard]] static auto to_uint32(const xtd::string& value) -> xtd::uint32;
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
    [[nodiscard]] static auto to_uint32(const xtd::string& value, xtd::byte from_base) -> xtd::uint32;
    /// @cond
    [[nodiscard]] static auto to_uint32(const std::string& value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const std::u8string& value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const std::u16string& value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const std::u32string& value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const std::wstring& value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const char* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(char* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const char8* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(char8* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const char16* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(char16* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const char32* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(char32* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(const wchar* value) -> xtd::uint32;
    [[nodiscard]] static auto to_uint32(wchar* value) -> xtd::uint32;
    /// @endcond
    /// @brief Convert type_t to uint32.
    /// @param value object to convert.
    /// @return A new uint32 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// uint32 result = convert::to_uint32(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_uint32(type_t value) noexcept -> xtd::uint32 {
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
    [[nodiscard]] static auto to_uint64(xtd::any value) -> xtd::uint64;
    /// @brief Convert bool to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(bool value) noexcept -> xtd::uint64;
    /// @brief Convert xtd::byte to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(xtd::byte value) noexcept -> xtd::uint64;
    /// @brief Convert char to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(char value) noexcept -> xtd::uint64;
    /// @brief Convert char8 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(char8 value) noexcept -> xtd::uint64;
    /// @brief Convert char16 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(char16 value) noexcept -> xtd::uint64;
    /// @brief Convert char32 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(char32 value) noexcept -> xtd::uint64;
    /// @brief Convert char32 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(wchar value) noexcept -> xtd::uint64;
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
    [[nodiscard]] static auto to_uint64(decimal value) -> xtd::uint64;
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
    [[nodiscard]] static auto to_uint64(double value) -> xtd::uint64;
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
    [[nodiscard]] static auto to_uint64(float value) -> xtd::uint64;
    /// @brief Convert int16 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(int16 value) -> xtd::uint64;
    /// @brief Convert int32 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(int32 value) -> xtd::uint64;
    /// @brief Convert int64 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(int64 value) -> xtd::uint64;
    /// @brief Convert slong to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(slong value) -> xtd::uint64;
    /// @brief Convert sbyte to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(sbyte value) -> xtd::uint64;
    /// @brief Convert uint16 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(uint16 value) noexcept -> xtd::uint64;
    /// @brief Convert uint32 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(uint32 value) noexcept -> xtd::uint64;
    /// @brief Convert uint64 to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(uint64 value) noexcept -> xtd::uint64;
    /// @brief Convert slong to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(xtd::ulong value) noexcept -> xtd::uint64;
    /// @brief Convert string to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// uint64 result = convert::to_uint64(value);
    /// ```
    [[nodiscard]] static auto to_uint64(const xtd::string& value) -> xtd::uint64;
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
    [[nodiscard]] static auto to_uint64(const xtd::string& value, xtd::byte from_base) -> xtd::uint64;
    /// @cond
    [[nodiscard]] static auto to_uint64(const std::string& value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const std::u8string& value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const std::u16string& value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const std::u32string& value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const std::wstring& value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const char* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(char* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const char8* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(char8* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const char16* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(char16* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const char32* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(char32* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(const wchar* value) -> xtd::uint64;
    [[nodiscard]] static auto to_uint64(wchar* value) -> xtd::uint64;
    /// @endcond
    /// @brief Convert type_t to uint64.
    /// @param value object to convert.
    /// @return A new uint64 object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// uint64 result = convert::to_uint64(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_uint64(type_t value) noexcept -> xtd::uint64 {
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
    [[nodiscard]] static auto to_ullong(xtd::any value) -> xtd::ulong;
    /// @brief Convert bool to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(bool value) noexcept -> xtd::ulong;
    /// @brief Convert xtd::byte to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(xtd::byte value) noexcept -> xtd::ulong;
    /// @brief Convert char to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(char value) noexcept -> xtd::ulong;
    /// @brief Convert char8 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(char8 value) noexcept -> xtd::ulong;
    /// @brief Convert char16 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(char16 value) noexcept -> xtd::ulong;
    /// @brief Convert char32 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(char32 value) noexcept -> xtd::ulong;
    /// @brief Convert char32 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(wchar value) noexcept -> xtd::ulong;
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
    [[nodiscard]] static auto to_ullong(decimal value) -> xtd::ulong;
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
    [[nodiscard]] static auto to_ullong(double value) -> xtd::ulong;
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
    [[nodiscard]] static auto to_ullong(float value) -> xtd::ulong;
    /// @brief Convert int16 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(int16 value) -> xtd::ulong;
    /// @brief Convert int32 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(int32 value) -> xtd::ulong;
    /// @brief Convert int64 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(int64 value) -> xtd::ulong;
    /// @brief Convert slong to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(slong value) -> xtd::ulong;
    /// @brief Convert sbyte to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(sbyte value) -> xtd::ulong;
    /// @brief Convert uint16 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(uint16 value) noexcept -> xtd::ulong;
    /// @brief Convert uint32 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(uint32 value) noexcept -> xtd::ulong;
    /// @brief Convert uint64 to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42ul;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(uint64 value) noexcept -> xtd::ulong;
    /// @brief Convert slong to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(xtd::ulong value) noexcept -> xtd::ulong;
    /// @brief Convert string to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    [[nodiscard]] static auto to_ullong(const xtd::string& value) -> xtd::ulong;
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
    [[nodiscard]] static auto to_ullong(const xtd::string& value, xtd::byte from_base) -> xtd::ulong;
    /// @cond
    [[nodiscard]] static auto to_ullong(const std::string& value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const std::u8string& value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const std::u16string& value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const std::u32string& value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const std::wstring& value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const char* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(char* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const char8* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(char8* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const char16* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(char16* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const char32* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(char32* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(const wchar* value) -> xtd::ulong;
    [[nodiscard]] static auto to_ullong(wchar* value) -> xtd::ulong;
    /// @endcond
    /// @brief Convert type_t to xtd::ulong.
    /// @param value object to convert.
    /// @return A new xtd::ulong object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// xtd::ulong result = convert::to_ullong(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_ullong(type_t value) noexcept -> xtd::ulong {
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
    [[nodiscard]] static auto to_string(xtd::any value) -> xtd::string;
    /// @brief Convert bool to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// bool value = true;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(bool value) noexcept -> xtd::string;
    /// @brief Convert xtd::byte to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::byte value = 42;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(xtd::byte value) noexcept -> xtd::string;
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
    [[nodiscard]] static auto to_string(xtd::byte value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert char to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// char value = 'a';
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(char value) noexcept -> xtd::string;
    /// @brief Convert char8 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// char8 value = u8'a';
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(char8 value) noexcept -> xtd::string;
    /// @brief Convert char16 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// char16 value = u'a';
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(char16 value) noexcept -> xtd::string;
    /// @brief Convert char32 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// char32 value = U'a';
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(char32 value) noexcept -> xtd::string;
    /// @brief Convert char32 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// wchar value = L'a';
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(wchar value) noexcept -> xtd::string;
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
    [[nodiscard]] static auto to_string(decimal value) -> xtd::string;
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
    [[nodiscard]] static auto to_string(double value) -> xtd::string;
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
    [[nodiscard]] static auto to_string(float value) -> xtd::string;
    /// @brief Convert int16 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// int16 value = 42;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(int16 value) -> xtd::string;
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
    [[nodiscard]] static auto to_string(int16 value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert int32 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int32 value = 42;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(int32 value) -> xtd::string;
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
    [[nodiscard]] static auto to_string(int32 value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert int64 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// int64 value = 42l;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(int64 value) -> xtd::string;
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
    [[nodiscard]] static auto to_string(int64 value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert slong to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max() or is less than 0.
    /// @par Examples
    /// ```cpp
    /// slong value = 42ll;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(slong value) -> xtd::string;
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
    [[nodiscard]] static auto to_string(slong value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert sbyte to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// sbyte value = 42;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(sbyte value) -> xtd::string;
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
    [[nodiscard]] static auto to_string(sbyte value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert uint16 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint16 value = 42u;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(uint16 value) noexcept -> xtd::string;
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
    [[nodiscard]] static auto to_string(uint16 value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert uint32 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// uint32 value = 42u;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(uint32 value) noexcept -> xtd::string;
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
    [[nodiscard]] static auto to_string(uint32 value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert uint64 to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<xtd::byte>::max().
    /// @par Examples
    /// ```cpp
    /// uint64t value = 42u;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(uint64 value) noexcept -> xtd::string;
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
    [[nodiscard]] static auto to_string(uint64 value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert slong to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// xtd::ulong value = 42ull;
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(xtd::ulong value) noexcept -> xtd::string;
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
    [[nodiscard]] static auto to_string(xtd::ulong value, xtd::byte from_base) -> xtd::string;
    /// @brief Convert string to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// string value = "42";
    /// string result = convert::to_string(value);
    /// ```
    [[nodiscard]] static auto to_string(const xtd::string& value) -> xtd::string;
    /// @cond
    [[nodiscard]] static auto to_string(const std::string& value) -> xtd::string;
    [[nodiscard]] static auto to_string(const std::u8string& value) -> xtd::string;
    [[nodiscard]] static auto to_string(const std::u16string& value) -> xtd::string;
    [[nodiscard]] static auto to_string(const std::u32string& value) -> xtd::string;
    [[nodiscard]] static auto to_string(const std::wstring& value) -> xtd::string;
    [[nodiscard]] static auto to_string(const char* value) -> xtd::string;
    [[nodiscard]] static auto to_string(char* value) -> xtd::string;
    [[nodiscard]] static auto to_string(const char8* value) -> xtd::string;
    [[nodiscard]] static auto to_string(char8* value) -> xtd::string;
    [[nodiscard]] static auto to_string(const char16* value) -> xtd::string;
    [[nodiscard]] static auto to_string(char16* value) -> xtd::string;
    [[nodiscard]] static auto to_string(const char32* value) -> xtd::string;
    [[nodiscard]] static auto to_string(char32* value) -> xtd::string;
    [[nodiscard]] static auto to_string(const wchar* value) -> xtd::string;
    [[nodiscard]] static auto to_string(wchar* value) -> xtd::string;
    /// @endcond
    /// @brief Convert type_t to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @par Examples
    /// ```cpp
    /// address_family value = address_family::inter_network;
    /// string result = convert::to_string(value);
    /// ```
    template<typename type_t>
    [[nodiscard]] static auto to_string(type_t value) noexcept -> xtd::string {
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
    template<typename type_t>
    [[deprecated("Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.")]] [[nodiscard]] static auto to_ustring(type_t value, xtd::byte from_base) -> xtd::string {return to_string(value, from_base);}
    /// @brief Convert string_t to string.
    /// @param value object to convert.
    /// @return A new string object converted from value.
    /// @deprecated Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.
    template<typename string_t>
    [[deprecated("Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.")]] [[nodiscard]] static auto to_ustring(const string_t& value) -> xtd::string {return to_string(value);}
    /// @}
    
    /// @cond
    template<typename char_t>
    [[deprecated("Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.")]] [[nodiscard]] static auto to_ustring(const char_t* value) -> xtd::string {return to_string(value);}
    template<typename char_t>
    [[deprecated("Replaced by xtd::convert::to_string - Will be removed in version 0.4.0.")]] [[nodiscard]] static auto to_ustring(char_t* value) -> xtd::string {return to_string(value);}
    /// @endcond
  };
}
