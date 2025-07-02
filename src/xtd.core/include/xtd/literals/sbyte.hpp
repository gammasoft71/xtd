/// @file
/// @brief Contains xtd::sbyte suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include "../sbyte.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name SByte suffixes
    
    /// @{
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_i8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_i8(long double n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_i8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_i8(unsigned long long n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_i8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_i8(const char* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_i8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_i8(const char8_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_i8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_i8(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_i8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_i8(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_i8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_i8(const wchar_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_s8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_s8(long double n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_s8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_s8(unsigned long long n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_s8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_s8(const char* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_s8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_s8(const char8_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_s8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_s8(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_s8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_s8(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_s8 << xtd::environment::new_line;
    /// ```
    sbyte operator""_s8(const wchar_t* s, std::size_t n);
    /// @}
  }
}
