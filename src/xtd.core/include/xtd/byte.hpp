/// @file
/// @brief Contains xtd::byte type.
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
  /// @brief Represents a 8-bit unsigned integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/byte>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  using byte = uint8_t;
  /// @}
  
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
    
#if defined(__xtd__cpp_lib_char8_t)
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
#endif
    
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
    
#if defined(__xtd__cpp_lib_char8_t)
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
#endif
    
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
