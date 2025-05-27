/// @file
/// @brief Contains xtd::uint64 type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include <cstdint>
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represents a 64-bit unsigned integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/uint64>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  using uint64 = uint64_t;
  /// @}
  
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name UInt64 suffixes
    
    /// @{
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_u64 << xtd::environment::new_line;
    /// ```
    uint64 operator""_u64(long double n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_u64 << xtd::environment::new_line;
    /// ```
    uint64 operator""_u64(unsigned long long n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_u64 << xtd::environment::new_line;
    /// ```
    uint64 operator""_u64(const char* s, std::size_t n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_u64 << xtd::environment::new_line;
    /// ```
    uint64 operator""_u64(const char8_t* s, std::size_t n);
#endif
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_u64 << xtd::environment::new_line;
    /// ```
    uint64 operator""_u64(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_u64 << xtd::environment::new_line;
    /// ```
    uint64 operator""_u64(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_u64 << xtd::environment::new_line;
    /// ```
    uint64 operator""_u64(const wchar_t* s, std::size_t n);
    /// @}
  }
}
