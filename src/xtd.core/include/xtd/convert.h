/// @file
/// @brief Contains xtd::convert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
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
    /// @brief Convert std::ny to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(std::any value);
    /// @brief Convert bool to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(bool value) noexcept;
    /// @brief Convert byte_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(byte_t value) noexcept;
    /// @brief Convert char to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(char value) noexcept;
    /// @brief Convert char8_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(char8_t value) noexcept;
    /// @brief Convert char16_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(char16_t value) noexcept;
    /// @brief Convert char32_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(char32_t value) noexcept;
    /// @brief Convert decimal_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(decimal_t value) noexcept;
    /// @brief Convert double to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(double value) noexcept;
    /// @brief Convert float to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(float value) noexcept;
    /// @brief Convert int16_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(int16_t value) noexcept;
    /// @brief Convert int32_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(int32_t value) noexcept;
    /// @brief Convert int64_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(int64_t value) noexcept;
    /// @brief Convert llong_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(llong_t value) noexcept;
    /// @brief Convert sbyte_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(uint16_t value) noexcept;
    /// @brief Convert uint32_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(uint32_t value) noexcept;
    /// @brief Convert uint64_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(uint64_t value) noexcept;
    /// @brief Convert llong_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(ullong_t value) noexcept;
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const xtd::ustring& value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::string& value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::u8string& value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::u16string& value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::u32string& value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::wstring& value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const char* value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const char8_t* value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const char16_t* value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const char32_t* value);
    /// @brief Convert string to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const wchar_t* value);
    /// @brief Convert type_t to bool
    /// @param value object to convert
    /// @return A new bool object converted from value
    template<typename type_t>
    static bool to_boolean(type_t value) {
      return static_cast<bool>(value);
    }
  };
}
