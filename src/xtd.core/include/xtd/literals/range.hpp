/// @file
/// @brief Contains xtd::range suffixes.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../range.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Range suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::range.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[\"0..4\"_r] = {}", items["0..4"_r]); // [1, 2, 3, 4]
    /// println("items[\"2..5\"_r] = {}", items["2..5"_r]); // [3, 4, 5]
    /// println("items[\"~4..~2\"_r] = {}", items["0..~2"_r]); // [2, 3]
    /// println("items[\"~2..~0\"_r] = {}", items["2..~0"_r]); // [4, 5]
    /// ```
    [[nodiscard]] auto operator""_r(const char* s, xtd::usize n) -> xtd::range;
    
    /// @brief Used to convert specified value into xtd::range.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[u8\"0..4\"_r] = {}", items[u8"0..4"_r]); // [1, 2, 3, 4]
    /// println("items[u8\"2..5\"_r] = {}", items[u8"2..5"_r]); // [3, 4, 5]
    /// println("items[u8\"~4..~2\"_r] = {}", items[u8"0..~2"_r]); // [2, 3]
    /// println("items[u8\"~2..~0\"_r] = {}", items[u8"2..~0"_r]); // [4, 5]
    /// ```
    [[nodiscard]] auto operator""_r(const char8_t* s, xtd::usize n) -> xtd::range;
    
    /// @brief Used to convert specified value into xtd::range.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[u\"0..4\"_r] = {}", items[u"0..4"_r]); // [1, 2, 3, 4]
    /// println("items[u\"2..5\"_r] = {}", items[u"2..5"_r]); // [3, 4, 5]
    /// println("items[u\"~4..~2\"_r] = {}", items[u"0..~2"_r]); // [2, 3]
    /// println("items[u\"~2..~0\"_r] = {}", items[u"2..~0"_r]); // [4, 5]
    /// ```
    [[nodiscard]] auto operator""_r(const char16_t* s, xtd::usize n) -> xtd::range;
    
    /// @brief Used to convert specified value into xtd::range.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[U\"0..4\"_r] = {}", items[U"0..4"_r]); // [1, 2, 3, 4]
    /// println("items[U\"2..5\"_r] = {}", items[U"2..5"_r]); // [3, 4, 5]
    /// println("items[U\"~4..~2\"_r] = {}", items[U"0..~2"_r]); // [2, 3]
    /// println("items[U\"~2..~0\"_r] = {}", items[U"2..~0"_r]); // [4, 5]
    /// ```
    [[nodiscard]] auto operator""_r(const char32_t* s, xtd::usize n) -> xtd::range;
    
    /// @brief Used to convert specified value into xtd::range.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[L\"0..4\"_r] = {}", items[L"0..4"_r]); // [1, 2, 3, 4]
    /// println("items[L\"2..5\"_r] = {}", items[L"2..5"_r]); // [3, 4, 5]
    /// println("items[L\"~4..~2\"_r] = {}", items[L"0..~2"_r]); // [2, 3]
    /// println("items[L\"~2..~0\"_r] = {}", items[L"2..~0"_r]); // [4, 5]
    /// ```
    [[nodiscard]] auto operator""_r(const wchar_t* s, xtd::usize n) -> xtd::range;
    /// @}
  }
}
