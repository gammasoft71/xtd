/// @file
/// @brief Contains xtd::usize suffixes.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../index.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Index suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::index.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[0_i] = {}", items[0_i]); // 1
    /// println("items[2_i] = {}", items[2_i]); // 3
    /// println("items[~1_i] = {}", items[~1_i]); // 5
    /// println("items[~3_i] = {}", items[~3_i]); // 3
    /// ```
    [[nodiscard]] constexpr auto operator""_i(long double n) -> xtd::index {return xtd::index {static_cast<xtd::usize>(n)};}
    
    /// @brief Used to convert specified value into xtd::index.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[0_i] = {}", items[0_i]); // 1
    /// println("items[2_i] = {}", items[2_i]); // 3
    /// println("items[~1_i] = {}", items[~1_i]); // 5
    /// println("items[~3_i] = {}", items[~3_i]); // 3
    /// ```
    [[nodiscard]] constexpr auto operator""_i(unsigned long long n) -> xtd::index {return xtd::index {static_cast<xtd::usize>(n)};}
    
    /// @brief Used to convert specified value into xtd::index.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items["0"_i] = {}", items[0_i]); // 1
    /// println("items["2"_i] = {}", items[2_i]); // 3
    /// println("items["~1"_i] = {}", items[~1_i]); // 5
    /// println("items["~3"_i] = {}", items[~3_i]); // 3
    /// ```
    [[nodiscard]] auto operator""_i(const char* s, xtd::usize n) -> xtd::index;
    
    /// @brief Used to convert specified value into xtd::index.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[u8"0"_i] = {}", items[0_i]); // 1
    /// println("items[u8"2"_i] = {}", items[2_i]); // 3
    /// println("items[u8"~1"_i] = {}", items[~1_i]); // 5
    /// println("items[u8"~3"_i] = {}", items[~3_i]); // 3
    /// ```
    [[nodiscard]] auto operator""_i(const char8_t* s, xtd::usize n) -> xtd::index;
    
    /// @brief Used to convert specified value into xtd::index.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[u"0"_i] = {}", items[0_i]); // 1
    /// println("items[u"2"_i] = {}", items[2_i]); // 3
    /// println("items[u"~1"_i] = {}", items[~1_i]); // 5
    /// println("items[u"~3"_i] = {}", items[~3_i]); // 3
    /// ```
    [[nodiscard]] auto operator""_i(const char16_t* s, xtd::usize n) -> xtd::index;
    
    /// @brief Used to convert specified value into xtd::index.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[U"0"_i] = {}", items[0_i]); // 1
    /// println("items[U"2"_i] = {}", items[2_i]); // 3
    /// println("items[U"~1"_i] = {}", items[~1_i]); // 5
    /// println("items[U"~3"_i] = {}", items[~3_i]); // 3
    /// ```
    [[nodiscard]] auto operator""_i(const char32_t* s, xtd::usize n) -> xtd::index;
    
    /// @brief Used to convert specified value into xtd::index.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// auto items = array {1, 2, 3, 4, 5};
    /// println("items[L"0"_i] = {}", items[0_i]); // 1
    /// println("items[L"2"_i] = {}", items[2_i]); // 3
    /// println("items[L"~1"_i] = {}", items[~1_i]); // 5
    /// println("items[L"~3"_i] = {}", items[~3_i]); // 3
    /// ```
    [[nodiscard]] auto operator""_i(const wchar_t* s, xtd::usize n) -> xtd::index;
    /// @}
  }
}
