/// @file
/// @brief Contains xtd::char32 suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../char32.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include <cstddef>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Character suffixes
    
    /// @{
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 42_c << xtd::environment::new_line;
    /// ```
    char32 operator""_c(unsigned long long c);
    
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 'a'_c << xtd::environment::new_line;
    /// ```
    char32 operator""_c(char c);
    
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 'a'_c << xtd::environment::new_line;
    /// ```
    char32 operator""_c(char8_t c);
    
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u'a'_c << xtd::environment::new_line;
    /// ```
    char32 operator""_c(char16_t c);
    
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U'a'_c << xtd::environment::new_line;
    /// ```
    char32 operator""_c(char32 c);
    
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L'a'_c << xtd::environment::new_line;
    /// ```
    char32 operator""_c(wchar_t c);
    /// @}
  }
}
