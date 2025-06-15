/// @file
/// @brief Contains xtd::int64 suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include "../int64.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Int64 suffixes
    
    /// @{
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_i64 << xtd::environment::new_line;
    /// ```
    int64 operator""_i64(long double n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_i64 << xtd::environment::new_line;
    /// ```
    int64 operator""_i64(unsigned long long n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_i64 << xtd::environment::new_line;
    /// ```
    int64 operator""_i64(const char* s, std::size_t n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_i64 << xtd::environment::new_line;
    /// ```
    int64 operator""_i64(const char8_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_i64 << xtd::environment::new_line;
    /// ```
    int64 operator""_i64(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_i64 << xtd::environment::new_line;
    /// ```
    int64 operator""_i64(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_i64 << xtd::environment::new_line;
    /// ```
    int64 operator""_i64(const wchar_t* s, std::size_t n);

    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_s64 << xtd::environment::new_line;
    /// ```
    int64 operator""_s64(long double n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_s64 << xtd::environment::new_line;
    /// ```
    int64 operator""_s64(unsigned long long n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_s64 << xtd::environment::new_line;
    /// ```
    int64 operator""_s64(const char* s, std::size_t n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_s64 << xtd::environment::new_line;
    /// ```
    int64 operator""_s64(const char8_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_s64 << xtd::environment::new_line;
    /// ```
    int64 operator""_s64(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_s64 << xtd::environment::new_line;
    /// ```
    int64 operator""_s64(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_s64 << xtd::environment::new_line;
    /// ```
    int64 operator""_s64(const wchar_t* s, std::size_t n);
    /// @}
  }
}
