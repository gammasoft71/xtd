/// @file
/// @brief Contains xtd::ssize suffixes.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../ssize.hpp"
#include "../usize.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Size suffixes
    
    /// @{
    /// @brief Used to convert specified value into signed xtd::ssize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_sz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] constexpr auto operator""_sz(long double n) -> xtd::ssize {return static_cast<xtd::ssize>(n);}
    
    /// @brief Used to convert specified value into signed xtd::ssize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_sz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] constexpr auto operator""_sz(unsigned long long n) -> xtd::ssize {return static_cast<xtd::ssize>(n);}
    
    /// @brief Used to convert specified value into signed xtd::ssize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_sz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_sz(const char* s, xtd::usize n) -> xtd::ssize;
    
    /// @brief Used to convert specified value into signed xtd::ssize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_sz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_sz(const char8_t* s, xtd::usize n) -> xtd::ssize;
    
    /// @brief Used to convert specified value into signed xtd::ssize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_sz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_sz(const char16_t* s, xtd::usize n) -> xtd::ssize;
    
    /// @brief Used to convert specified value into signed xtd::ssize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_sz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_sz(const char32_t* s, xtd::usize n) -> xtd::ssize;
    
    /// @brief Used to convert specified value into signed xtd::ssize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_sz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_sz(const wchar_t* s, xtd::usize n) -> xtd::ssize;
    /// @}
  }
}
