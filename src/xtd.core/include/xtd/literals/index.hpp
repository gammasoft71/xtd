/// @file
/// @brief Contains xtd::usize suffixes.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../index.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Size suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] constexpr auto operator""_i(long double n) -> xtd::index {return xtd::index {static_cast<xtd::usize>(n)};}
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] constexpr auto operator""_i(unsigned long long n) -> xtd::index {return xtd::index {static_cast<xtd::usize>(n)};}
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_i << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_i(const char* s, xtd::usize n) -> xtd::index;
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_i << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_i(const char8_t* s, xtd::usize n) -> xtd::index;
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_i << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_i(const char16_t* s, xtd::usize n) -> xtd::index;
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_i << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_i(const char32_t* s, xtd::usize n) -> xtd::index;
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_i << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_i(const wchar_t* s, xtd::usize n) -> xtd::index;
    /// @}
  }
}
