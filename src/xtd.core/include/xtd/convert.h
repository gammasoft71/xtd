/// @file
/// @brief Contains xtd::convert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include "invalid_cast_exception.h"
#include "static.h"
#include "types.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents API to convert base type code.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  class convert static_ {
  public:
    /// @brief Convert std::any to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = true;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(std::any value) noexcept;
    /// @brief Convert bool to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @code
    /// bool value = true;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(bool value) noexcept;
    /// @brief Convert byte_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @code
    /// byte_t value = 42;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(byte_t value) noexcept;
    /// @brief Convert char to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @code
    /// char value = 'a';
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(char value) noexcept;
    /// @brief Convert char8_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @code
    /// char8_t value = u8'a';
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(char8_t value);
    /// @brief Convert char16_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @code
    /// char16_t value = u'a';
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(char16_t value) noexcept;
    /// @brief Convert char32_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @code
    /// char32_t value = U'a';
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(char32_t value) noexcept;
    /// @brief Convert wchar_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @code
    /// wchar_t value = L'a';
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(wchar_t value) noexcept;
    /// @brief Convert decimal_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @code
    /// decimal_t value = 42.50l;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(decimal_t value) noexcept;
    /// @brief Convert double to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(double value) noexcept;
    /// @brief Convert float to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @brief Convert double to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(float value) noexcept;
    /// @brief Convert int16_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(int16_t value) noexcept;
    /// @brief Convert int32_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(int32_t value) noexcept;
    /// @brief Convert int64_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// int6_4t value = 42l;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(int64_t value) noexcept;
    /// @brief Convert llong_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(llong_t value) noexcept;
    /// @brief Convert sbyte_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(uint16_t value) noexcept;
    /// @brief Convert uint32_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(uint32_t value) noexcept;
    /// @brief Convert uint64_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// uint64_t value = 42ul;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(uint64_t value) noexcept;
    /// @brief Convert llong_t to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(ullong_t value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const xtd::ustring& value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const std::string& value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const std::u8string& value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const std::u16string& value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const std::u32string& value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const std::wstring& value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const char* value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(char* value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const char8_t* value);
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(char8_t* value);
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const char16_t* value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(char16_t* value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const char32_t* value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(char32_t* value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(const wchar_t* value) noexcept;
    /// @brief Convert string to std::any.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// any result = convert::to_any(value);
    /// @endcode
    static std::any to_any(wchar_t* value) noexcept;
    /// @brief Convert type_t to bool.
    /// @param value object to convert.
    /// @return A new std::any object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// any result = convert::to_any(value);
    /// @endcode
    template<typename type_t>
    static std::any to_any(type_t value) {
      try {
        return std::any(value);
      } catch(...) {
        throw xtd::invalid_cast_exception(csf_);
      }
    }

    /// @brief Convert std::any to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception the parameters is bad cast.
    /// @par Examples
    /// @code
    /// std::any value = true;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(std::any value);
    /// @brief Convert bool to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @code
    /// bool value = true;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(bool value) noexcept;
    /// @brief Convert byte_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @code
    /// byte_t value = 42;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(byte_t value) noexcept;
    /// @brief Convert char to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @code
    /// char value = 'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(char value);
    /// @brief Convert char8_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @code
    /// char8_t value = u8'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(char8_t value);
    /// @brief Convert char16_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @code
    /// char16_t value = u'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(char16_t value);
    /// @brief Convert char32_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @code
    /// char32_t value = U'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(char32_t value);
    /// @brief Convert wchar_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::invalid_cast_exception throws always exception.
    /// @code
    /// wchar_t value = L'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(wchar_t value);
    /// @brief Convert decimal_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @code
    /// decimal_t value = 42.50l;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(decimal_t value) noexcept;
    /// @brief Convert double to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(double value) noexcept;
    /// @brief Convert float to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @brief Convert double to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(float value) noexcept;
    /// @brief Convert int16_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(int16_t value) noexcept;
    /// @brief Convert int32_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(int32_t value) noexcept;
    /// @brief Convert int64_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// int6_4t value = 42l;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(int64_t value) noexcept;
    /// @brief Convert llong_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(llong_t value) noexcept;
    /// @brief Convert sbyte_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(uint16_t value) noexcept;
    /// @brief Convert uint32_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(uint32_t value) noexcept;
    /// @brief Convert uint64_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// uint64_t value = 42ul;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(uint64_t value) noexcept;
    /// @brief Convert llong_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(ullong_t value) noexcept;
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const xtd::ustring& value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const std::string& value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const std::u8string& value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const std::u16string& value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const std::u32string& value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const std::wstring& value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const char* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(char* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const char8_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(char8_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const char16_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(char16_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const char32_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(char32_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(const wchar_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @exception xtd::atgument_exception value does not represent a bool.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(wchar_t* value);
    /// @brief Convert type_t to bool.
    /// @param value object to convert.
    /// @return A new bool object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    template<typename type_t>
    static bool to_boolean(type_t value) noexcept {
      return static_cast<bool>(value);
    }
    
    /// @brief Convert std::any to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(std::any value);
    /// @brief Convert bool to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(bool value) noexcept;
    /// @brief Convert byte_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(byte_t value) noexcept;
    /// @brief Convert char to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(char value) noexcept;
    /// @brief Convert char8_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(char8_t value) noexcept;
    /// @brief Convert char16_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(char16_t value);
    /// @brief Convert char32_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(char32_t value);
    /// @brief Convert char32_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(wchar_t value);
    /// @brief Convert decimal_t to byte.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @return A new byte_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(decimal_t value);
    /// @brief Convert double to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(double value);
    /// @brief Convert float to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(float value);
    /// @brief Convert int16_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(int16_t value);
    /// @brief Convert int32_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(int32_t value);
    /// @brief Convert int64_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(int64_t value);
    /// @brief Convert llong_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(llong_t value);
    /// @brief Convert sbyte_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(sbyte_t value);
    /// @brief Convert uint16_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(uint16_t value);
    /// @brief Convert uint32_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(uint32_t value);
    /// @brief Convert uint64_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(uint64_t value);
    /// @brief Convert llong_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(ullong_t value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const xtd::ustring& value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const std::string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const std::u8string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const std::u16string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const std::u32string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const std::wstring& value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const char* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(char* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const char8_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(char8_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const char16_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(char16_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const char32_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(char32_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(const wchar_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    static byte_t to_byte(wchar_t* value);
    /// @brief Convert type_t to byte.
    /// @param value object to convert.
    /// @return A new byte_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// byte_t result = convert::to_byte(value);
    /// @endcode
    template<typename type_t>
    static byte_t to_byte(type_t value) noexcept {
      return static_cast<byte_t>(value);
    }
    
    /// @brief Convert std::any to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(std::any value);
    /// @brief Convert bool to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(bool value);
    /// @brief Convert byte_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(byte_t value) noexcept;
    /// @brief Convert char to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(char value) noexcept;
    /// @brief Convert char8_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(char8_t value) noexcept;
    /// @brief Convert char16_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(char16_t value);
    /// @brief Convert char32_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(char32_t value);
    /// @brief Convert char32_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(wchar_t value);
    /// @brief Convert decimal_t to char.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(decimal_t value);
    /// @brief Convert double to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(double value);
    /// @brief Convert float to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(float value);
    /// @brief Convert int16_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(int16_t value);
    /// @brief Convert int32_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(int32_t value);
    /// @brief Convert int64_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(int64_t value);
    /// @brief Convert llong_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(llong_t value);
    /// @brief Convert sbyte_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(sbyte_t value);
    /// @brief Convert uint16_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(uint16_t value);
    /// @brief Convert uint32_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(uint32_t value);
    /// @brief Convert uint64_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(uint64_t value);
    /// @brief Convert llong_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(ullong_t value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const xtd::ustring& value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const std::string& value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const std::u8string& value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const std::u16string& value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const std::u32string& value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const std::wstring& value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const char* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(char* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const char8_t* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(char8_t* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const char16_t* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(char16_t* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const char32_t* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(char32_t* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(const wchar_t* value);
    /// @brief Convert string to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// char result = convert::to_char(value);
    /// @endcode
    static char to_char(wchar_t* value);
    /// @brief Convert type_t to char.
    /// @param value object to convert.
    /// @return A new char object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// char result = convert::to_char(value);
    /// @endcode
    template<typename type_t>
    static char to_char(type_t value) noexcept {
      return static_cast<char>(value);
    }
    
    /// @brief Convert std::any to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(std::any value);
    /// @brief Convert bool to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(bool value);
    /// @brief Convert byte_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(byte_t value) noexcept;
    /// @brief Convert char to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(char value) noexcept;
    /// @brief Convert char8_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(char8_t value) noexcept;
    /// @brief Convert char16_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(char16_t value);
    /// @brief Convert char32_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(char32_t value);
    /// @brief Convert char32_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(wchar_t value);
    /// @brief Convert decimal_t to char8.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char8_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(decimal_t value);
    /// @brief Convert double to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(double value);
    /// @brief Convert float to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(float value);
    /// @brief Convert int16_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(int16_t value);
    /// @brief Convert int32_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(int32_t value);
    /// @brief Convert int64_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(int64_t value);
    /// @brief Convert llong_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(llong_t value);
    /// @brief Convert sbyte_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(sbyte_t value);
    /// @brief Convert uint16_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(uint16_t value);
    /// @brief Convert uint32_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(uint32_t value);
    /// @brief Convert uint64_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(uint64_t value);
    /// @brief Convert llong_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(ullong_t value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const xtd::ustring& value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const std::string& value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const std::u8string& value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const std::u16string& value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const std::u32string& value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const std::wstring& value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const char* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(char* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const char8_t* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(char8_t* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const char16_t* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(char16_t* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const char32_t* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(char32_t* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(const wchar_t* value);
    /// @brief Convert string to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    static char8_t to_char8(wchar_t* value);
    /// @brief Convert type_t to char8.
    /// @param value object to convert.
    /// @return A new char8_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// char8_t result = convert::to_char8(value);
    /// @endcode
    template<typename type_t>
    static char8_t to_char8(type_t value) noexcept {
      return static_cast<char8_t>(value);
    }
    
    /// @brief Convert std::any to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(std::any value);
    /// @brief Convert bool to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(bool value);
    /// @brief Convert byte_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(byte_t value) noexcept;
    /// @brief Convert char to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(char value) noexcept;
    /// @brief Convert char8_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(char8_t value) noexcept;
    /// @brief Convert char16_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(char16_t value) noexcept;
    /// @brief Convert char32_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(char32_t value);
    /// @brief Convert char32_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(wchar_t value) noexcept;
    /// @brief Convert decimal_t to char16.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(decimal_t value);
    /// @brief Convert double to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(double value);
    /// @brief Convert float to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(float value);
    /// @brief Convert int16_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(int16_t value);
    /// @brief Convert int32_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(int32_t value);
    /// @brief Convert int64_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(int64_t value);
    /// @brief Convert llong_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(llong_t value);
    /// @brief Convert sbyte_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(sbyte_t value);
    /// @brief Convert uint16_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(uint16_t value) noexcept;
    /// @brief Convert uint32_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(uint32_t value);
    /// @brief Convert uint64_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(uint64_t value);
    /// @brief Convert llong_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(ullong_t value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const xtd::ustring& value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const std::string& value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const std::u8string& value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const std::u16string& value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const std::u32string& value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const std::wstring& value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const char* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(char* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const char8_t* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(char8_t* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const char16_t* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(char16_t* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const char32_t* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(char32_t* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(const wchar_t* value);
    /// @brief Convert string to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    static char16_t to_char16(wchar_t* value);
    /// @brief Convert type_t to char16.
    /// @param value object to convert.
    /// @return A new char16_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// char16_t result = convert::to_char16(value);
    /// @endcode
    template<typename type_t>
    static char16_t to_char16(type_t value) noexcept {
      return static_cast<char16_t>(value);
    }
    
    /// @brief Convert std::any to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(std::any value);
    /// @brief Convert bool to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(bool value);
    /// @brief Convert byte_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(byte_t value) noexcept;
    /// @brief Convert char to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(char value) noexcept;
    /// @brief Convert char8_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(char8_t value) noexcept;
    /// @brief Convert char16_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(char16_t value) noexcept;
    /// @brief Convert char32_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(char32_t value) noexcept;
    /// @brief Convert char32_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(wchar_t value) noexcept;
    /// @brief Convert decimal_t to char32.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(decimal_t value);
    /// @brief Convert double to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(double value);
    /// @brief Convert float to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(float value);
    /// @brief Convert int16_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(int16_t value);
    /// @brief Convert int32_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(int32_t value);
    /// @brief Convert int64_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(int64_t value);
    /// @brief Convert llong_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(llong_t value);
    /// @brief Convert sbyte_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(sbyte_t value);
    /// @brief Convert uint16_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(uint16_t value) noexcept;
    /// @brief Convert uint32_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(uint32_t value) noexcept;
    /// @brief Convert uint64_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(uint64_t value);
    /// @brief Convert llong_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(ullong_t value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const xtd::ustring& value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const std::string& value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const std::u8string& value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const std::u16string& value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const std::u32string& value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const std::wstring& value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const char* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(char* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const char8_t* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(char8_t* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const char16_t* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(char16_t* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const char32_t* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(char32_t* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(const wchar_t* value);
    /// @brief Convert string to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    static char32_t to_char32(wchar_t* value);
    /// @brief Convert type_t to char32.
    /// @param value object to convert.
    /// @return A new char32_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// char32_t result = convert::to_char32(value);
    /// @endcode
    template<typename type_t>
    static char32_t to_char32(type_t value) noexcept {
      return static_cast<char32_t>(value);
    }
    
    /// @brief Convert std::any to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(std::any value);
    /// @brief Convert bool to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(bool value);
    /// @brief Convert byte_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(byte_t value) noexcept;
    /// @brief Convert char to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(char value) noexcept;
    /// @brief Convert char8_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(char8_t value) noexcept;
    /// @brief Convert char16_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(char16_t value) noexcept;
    /// @brief Convert char32_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(char32_t value);
    /// @brief Convert char32_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(wchar_t value) noexcept;
    /// @brief Convert decimal_t to wchar.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(decimal_t value);
    /// @brief Convert double to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(double value);
    /// @brief Convert float to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(float value);
    /// @brief Convert int16_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(int16_t value);
    /// @brief Convert int32_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(int32_t value);
    /// @brief Convert int64_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(int64_t value);
    /// @brief Convert llong_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(llong_t value);
    /// @brief Convert sbyte_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is less than 0.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(sbyte_t value);
    /// @brief Convert uint16_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(uint16_t value) noexcept;
    /// @brief Convert uint32_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(uint32_t value);
    /// @brief Convert uint64_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(uint64_t value);
    /// @brief Convert llong_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(ullong_t value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const xtd::ustring& value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const std::string& value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const std::u8string& value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const std::u16string& value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const std::u32string& value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const std::wstring& value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const char* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(char* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const char8_t* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(char8_t* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const char16_t* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(char16_t* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const char32_t* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(char32_t* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(const wchar_t* value);
    /// @brief Convert string to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    static wchar_t to_wchar(wchar_t* value);
    /// @brief Convert type_t to wchar.
    /// @param value object to convert.
    /// @return A new wchar_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// wchar_t result = convert::to_wchar(value);
    /// @endcode
    template<typename type_t>
    static wchar_t to_wchar(type_t value) noexcept {
      return static_cast<wchar_t>(value);
    }
    
    /// @brief Convert std::any to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(std::any value);
    /// @brief Convert bool to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(bool value) noexcept;
    /// @brief Convert byte_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(byte_t value) noexcept;
    /// @brief Convert char to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(char value) noexcept;
    /// @brief Convert char8_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(char8_t value) noexcept;
    /// @brief Convert char16_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(char16_t value) noexcept;
    /// @brief Convert char32_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(char32_t value) noexcept;
    /// @brief Convert char32_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(wchar_t value) noexcept;
    /// @brief Convert decimal_t to decimal.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(decimal_t value) noexcept;
    /// @brief Convert double to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(double value) noexcept;
    /// @brief Convert float to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(float value) noexcept;
    /// @brief Convert int16_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(int16_t value) noexcept;
    /// @brief Convert int32_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(int32_t value) noexcept;
    /// @brief Convert int64_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(int64_t value) noexcept;
    /// @brief Convert llong_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(llong_t value) noexcept;
    /// @brief Convert sbyte_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(uint16_t value) noexcept;
    /// @brief Convert uint32_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(uint32_t value) noexcept;
    /// @brief Convert uint64_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(uint64_t value) noexcept;
    /// @brief Convert llong_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(ullong_t value) noexcept;
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const xtd::ustring& value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const std::string& value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const std::u8string& value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const std::u16string& value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const std::u32string& value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const std::wstring& value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const char* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(char* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const char8_t* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(char8_t* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const char16_t* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(char16_t* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const char32_t* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(char32_t* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(const wchar_t* value);
    /// @brief Convert string to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    static decimal_t to_decimal(wchar_t* value);
    /// @brief Convert type_t to decimal.
    /// @param value object to convert.
    /// @return A new decimal_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// decimal_t result = convert::to_decimal(value);
    /// @endcode
    template<typename type_t>
    static decimal_t to_decimal(type_t value) noexcept {
      return static_cast<decimal_t>(value);
    }
    
    /// @brief Convert std::any to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(std::any value);
    /// @brief Convert bool to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(bool value) noexcept;
    /// @brief Convert byte_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(byte_t value) noexcept;
    /// @brief Convert char to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(char value) noexcept;
    /// @brief Convert char8_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(char8_t value) noexcept;
    /// @brief Convert char16_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(char16_t value) noexcept;
    /// @brief Convert char32_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(char32_t value) noexcept;
    /// @brief Convert char32_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(wchar_t value) noexcept;
    /// @brief Convert decimal_t to double.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(decimal_t value) noexcept;
    /// @brief Convert double to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(double value) noexcept;
    /// @brief Convert float to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(float value) noexcept;
    /// @brief Convert int16_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(int16_t value) noexcept;
    /// @brief Convert int32_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(int32_t value) noexcept;
    /// @brief Convert int64_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(int64_t value) noexcept;
    /// @brief Convert llong_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(llong_t value) noexcept;
    /// @brief Convert sbyte_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(uint16_t value) noexcept;
    /// @brief Convert uint32_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(uint32_t value) noexcept;
    /// @brief Convert uint64_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(uint64_t value) noexcept;
    /// @brief Convert llong_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(ullong_t value) noexcept;
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const xtd::ustring& value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const std::string& value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const std::u8string& value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const std::u16string& value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const std::u32string& value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const std::wstring& value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const char* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(char* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const char8_t* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(char8_t* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const char16_t* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(char16_t* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const char32_t* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(char32_t* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(const wchar_t* value);
    /// @brief Convert string to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// double result = convert::to_double(value);
    /// @endcode
    static double to_double(wchar_t* value);
    /// @brief Convert type_t to double.
    /// @param value object to convert.
    /// @return A new double object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// double result = convert::to_double(value);
    /// @endcode
    template<typename type_t>
    static double to_double(type_t value) noexcept {
      return static_cast<double>(value);
    }
    
    /// @brief Convert std::any to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(std::any value);
    /// @brief Convert bool to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(bool value) noexcept;
    /// @brief Convert byte_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(byte_t value) noexcept;
    /// @brief Convert char to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(char value) noexcept;
    /// @brief Convert char8_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(char8_t value) noexcept;
    /// @brief Convert char16_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(char16_t value) noexcept;
    /// @brief Convert char32_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(char32_t value) noexcept;
    /// @brief Convert char32_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(wchar_t value) noexcept;
    /// @brief Convert decimal_t to single.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(decimal_t value) noexcept;
    /// @brief Convert double to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(double value) noexcept;
    /// @brief Convert float to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(float value) noexcept;
    /// @brief Convert int16_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(int16_t value) noexcept;
    /// @brief Convert int32_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(int32_t value) noexcept;
    /// @brief Convert int64_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(int64_t value) noexcept;
    /// @brief Convert llong_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(llong_t value) noexcept;
    /// @brief Convert sbyte_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(uint16_t value) noexcept;
    /// @brief Convert uint32_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(uint32_t value) noexcept;
    /// @brief Convert uint64_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(uint64_t value) noexcept;
    /// @brief Convert llong_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(ullong_t value) noexcept;
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const xtd::ustring& value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const std::string& value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const std::u8string& value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const std::u16string& value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const std::u32string& value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const std::wstring& value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const char* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(char* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const char8_t* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(char8_t* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const char16_t* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(char16_t* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const char32_t* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(char32_t* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(const wchar_t* value);
    /// @brief Convert string to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// float result = convert::to_single(value);
    /// @endcode
    static float to_single(wchar_t* value);
    /// @brief Convert type_t to single.
    /// @param value object to convert.
    /// @return A new float object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// float result = convert::to_single(value);
    /// @endcode
    template<typename type_t>
    static float to_single(type_t value) noexcept {
      return static_cast<float>(value);
    }
    
    /// @brief Convert std::any to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(std::any value);
    /// @brief Convert bool to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(bool value) noexcept;
    /// @brief Convert byte_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(byte_t value) noexcept;
    /// @brief Convert char to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(char value) noexcept;
    /// @brief Convert char8_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(char8_t value) noexcept;
    /// @brief Convert char16_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(char16_t value) noexcept;
    /// @brief Convert char32_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(char32_t value);
    /// @brief Convert char32_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(wchar_t value) noexcept;
    /// @brief Convert decimal_t to int16.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(decimal_t value);
    /// @brief Convert double to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(double value);
    /// @brief Convert float to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(float value);
    /// @brief Convert int16_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(int16_t value) noexcept;
    /// @brief Convert int32_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(int32_t value);
    /// @brief Convert int64_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(int64_t value);
    /// @brief Convert llong_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(llong_t value);
    /// @brief Convert sbyte_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(uint16_t value);
    /// @brief Convert uint32_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(uint32_t value);
    /// @brief Convert uint64_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(uint64_t value);
    /// @brief Convert llong_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(ullong_t value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const xtd::ustring& value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const std::string& value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const std::u8string& value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const std::u16string& value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const std::u32string& value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const std::wstring& value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const char* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(char* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const char8_t* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(char8_t* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const char16_t* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(char16_t* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const char32_t* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(char32_t* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(const wchar_t* value);
    /// @brief Convert string to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    static int16_t to_int16(wchar_t* value);
    /// @brief Convert type_t to int16.
    /// @param value object to convert.
    /// @return A new int16_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// int16_t result = convert::to_int16(value);
    /// @endcode
    template<typename type_t>
    static int16_t to_int16(type_t value) noexcept {
      return static_cast<int16_t>(value);
    }
    
    /// @brief Convert std::any to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(std::any value);
    /// @brief Convert bool to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(bool value) noexcept;
    /// @brief Convert byte_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(byte_t value) noexcept;
    /// @brief Convert char to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(char value) noexcept;
    /// @brief Convert char8_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(char8_t value) noexcept;
    /// @brief Convert char16_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(char16_t value) noexcept;
    /// @brief Convert char32_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(char32_t value) noexcept;
    /// @brief Convert char32_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(wchar_t value) noexcept;
    /// @brief Convert decimal_t to int32.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(decimal_t value);
    /// @brief Convert double to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(double value);
    /// @brief Convert float to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(float value) noexcept;
    /// @brief Convert int16_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(int16_t value) noexcept;
    /// @brief Convert int32_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(int32_t value) noexcept;
    /// @brief Convert int64_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(int64_t value);
    /// @brief Convert llong_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(llong_t value);
    /// @brief Convert sbyte_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(uint16_t value) noexcept;
    /// @brief Convert uint32_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(uint32_t value);
    /// @brief Convert uint64_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(uint64_t value);
    /// @brief Convert llong_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(ullong_t value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const xtd::ustring& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const std::string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const std::u8string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const std::u16string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const std::u32string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const std::wstring& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const char* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(char* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const char8_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(char8_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const char16_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(char16_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const char32_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(char32_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(const wchar_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    static int32_t to_int32(wchar_t* value);
    /// @brief Convert type_t to int32.
    /// @param value object to convert.
    /// @return A new int32_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// int32_t result = convert::to_int32(value);
    /// @endcode
    template<typename type_t>
    static int32_t to_int32(type_t value) noexcept {
      return static_cast<int32_t>(value);
    }
    
    /// @brief Convert std::any to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(std::any value);
    /// @brief Convert bool to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(bool value) noexcept;
    /// @brief Convert byte_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(byte_t value) noexcept;
    /// @brief Convert char to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(char value) noexcept;
    /// @brief Convert char8_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(char8_t value) noexcept;
    /// @brief Convert char16_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(char16_t value) noexcept;
    /// @brief Convert char32_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(char32_t value) noexcept;
    /// @brief Convert char32_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(wchar_t value) noexcept;
    /// @brief Convert decimal_t to int32.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(decimal_t value) noexcept;
    /// @brief Convert double to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(double value) noexcept;
    /// @brief Convert float to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(float value) noexcept;
    /// @brief Convert int16_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(int16_t value) noexcept;
    /// @brief Convert int32_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(int32_t value) noexcept;
    /// @brief Convert int64_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(int64_t value) noexcept;
    /// @brief Convert llong_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(llong_t value) noexcept;
    /// @brief Convert sbyte_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(uint16_t value) noexcept;
    /// @brief Convert uint32_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(uint32_t value) noexcept;
    /// @brief Convert uint64_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(uint64_t value);
    /// @brief Convert llong_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(ullong_t value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const xtd::ustring& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const std::string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const std::u8string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const std::u16string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const std::u32string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const std::wstring& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const char* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(char* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const char8_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(char8_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const char16_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(char16_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const char32_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(char32_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(const wchar_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    static int64_t to_int64(wchar_t* value);
    /// @brief Convert type_t to int32.
    /// @param value object to convert.
    /// @return A new int64_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// int64_t result = convert::to_int64(value);
    /// @endcode
    template<typename type_t>
    static int64_t to_int64(type_t value) noexcept {
      return static_cast<int64_t>(value);
    }
    
    /// @brief Convert std::any to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// std::any value = 42;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(std::any value);
    /// @brief Convert bool to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// bool value = true;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(bool value) noexcept;
    /// @brief Convert byte_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// byte_t value = 42;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(byte_t value) noexcept;
    /// @brief Convert char to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// char value = 'a';
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(char value) noexcept;
    /// @brief Convert char8_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// char8_t value = u8'a';
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(char8_t value) noexcept;
    /// @brief Convert char16_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// char16_t value = u'a';
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(char16_t value) noexcept;
    /// @brief Convert char32_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// char32_t value = U'a';
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(char32_t value) noexcept;
    /// @brief Convert char32_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// wchar_t value = L'a';
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(wchar_t value) noexcept;
    /// @brief Convert decimal_t to int32.
    /// @param value object to convert.
    /// @remarks The result is rounded.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// decimal_t value = 42.50l;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(decimal_t value) noexcept;
    /// @brief Convert double to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// double value = 42.50;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(double value) noexcept;
    /// @brief Convert float to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @remarks The result is rounded.
    /// @par Examples
    /// @code
    /// float value = 42.50f;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(float value) noexcept;
    /// @brief Convert int16_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// int16_t value = 42;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(int16_t value) noexcept;
    /// @brief Convert int32_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// int32_t value = 42;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(int32_t value) noexcept;
    /// @brief Convert int64_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// int64_t value = 42l;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(int64_t value) noexcept;
    /// @brief Convert llong_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// llong_t value = 42ll;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(llong_t value) noexcept;
    /// @brief Convert sbyte_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// sbyte_t value = 42;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// uint16_t value = 42u;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(uint16_t value) noexcept;
    /// @brief Convert uint32_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// uint32_t value = 42u;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(uint32_t value) noexcept;
    /// @brief Convert uint64_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// uint64t value = 42ul;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(uint64_t value);
    /// @brief Convert llong_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max().
    /// @par Examples
    /// @code
    /// ullong_t value = 42ull;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(ullong_t value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// ustring value = "42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const xtd::ustring& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// string value = "42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const std::string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u8string value = u8"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const std::u8string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u16string value = u"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const std::u16string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// u32string value = U"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const std::u32string& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wstring value = L"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const std::wstring& value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char* value = "42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const char* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char* value = "42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(char* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char8_t* value = u8"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const char8_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char8_t* value = u8"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(char8_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char16_t* value = u"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const char16_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char16_t* value = u"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(char16_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const char32_t* value = U"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const char32_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// char32_t* value = U"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(char32_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// const wchar_t* value = L"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(const wchar_t* value);
    /// @brief Convert string to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @exception xtd::atgument_exception value does not represent a byte.
    /// @par Examples
    /// @code
    /// wchar_t* value = L"42";
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    static llong_t to_llong(wchar_t* value);
    /// @brief Convert type_t to int32.
    /// @param value object to convert.
    /// @return A new llong_t object converted from value.
    /// @par Examples
    /// @code
    /// address_family value = address_family::inter_network;
    /// llong_t result = convert::to_llong(value);
    /// @endcode
    template<typename type_t>
    static llong_t to_llong(type_t value) noexcept {
      return static_cast<llong_t>(value);
    }
  };
}
