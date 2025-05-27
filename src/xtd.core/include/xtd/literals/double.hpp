/// @file
/// @brief Contains xtd::double_ suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include "../double.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Double suffixes
    
    /// @{
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_d << xtd::environment::new_line;
    /// ```
    double operator""_d(long double n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_d << xtd::environment::new_line;
    /// ```
    double operator""_d(unsigned long long n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_d << xtd::environment::new_line;
    /// ```
    double operator""_d(const char* s, std::size_t n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_d << xtd::environment::new_line;
    /// ```
    double operator""_d(const char8_t* s, std::size_t n);
#endif
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_d << xtd::environment::new_line;
    /// ```
    double operator""_d(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_d << xtd::environment::new_line;
    /// ```
    double operator""_d(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_d << xtd::environment::new_line;
    /// ```
    double operator""_d(const wchar_t* s, std::size_t n);
    /// @}
  }
}
