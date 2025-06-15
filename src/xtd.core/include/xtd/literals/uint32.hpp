/// @file
/// @brief Contains xtd::uint32 suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include "../uint32.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name UInt32 suffixes
    
    /// @{
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_u32 << xtd::environment::new_line;
    /// ```
    uint32 operator""_u32(long double n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_u32 << xtd::environment::new_line;
    /// ```
    uint32 operator""_u32(unsigned long long n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_u32 << xtd::environment::new_line;
    /// ```
    uint32 operator""_u32(const char* s, std::size_t n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_u32 << xtd::environment::new_line;
    /// ```
    uint32 operator""_u32(const char8_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_u32 << xtd::environment::new_line;
    /// ```
    uint32 operator""_u32(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_u32 << xtd::environment::new_line;
    /// ```
    uint32 operator""_u32(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_u32 << xtd::environment::new_line;
    /// ```
    uint32 operator""_u32(const wchar_t* s, std::size_t n);
    /// @}
  }
}
