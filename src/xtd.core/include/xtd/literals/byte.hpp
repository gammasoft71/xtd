/// @file
/// @brief Contains xtd::byte suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../byte.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include <cstddef>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Byte suffixes
    
    /// @{
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_b << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_b(long double n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_b << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_b(unsigned long long n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_b << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_b(const char* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_b << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_b(const char8_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_b << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_b(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_b << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_b(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_b << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_b(const wchar_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_u8 << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_u8(long double n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_u8 << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_u8(unsigned long long n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_u8 << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_u8(const char* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_u8 << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_u8(const char8_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_u8 << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_u8(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_u8 << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_u8(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_u8 << xtd::environment::new_line;
    /// ```
    xtd::byte operator""_u8(const wchar_t* s, std::size_t n);
    /// @}
  }
}
