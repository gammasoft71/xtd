/// @file
/// @brief Contains xtd::int32 type.
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
  /// @brief Represents a 32-bit signed integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/int32>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  using int32 = int32_t;
  /// @}
  
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Int32 suffixes
    
    /// @{
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_i32 << xtd::environment::new_line;
    /// ```
    int32 operator""_i32(long double n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_i32 << xtd::environment::new_line;
    /// ```
    int32 operator""_i32(unsigned long long n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_i32 << xtd::environment::new_line;
    /// ```
    int32 operator""_i32(const char* s, std::size_t n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_i32 << xtd::environment::new_line;
    /// ```
    int32 operator""_i32(const char8_t* s, std::size_t n);
#endif
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_i32 << xtd::environment::new_line;
    /// ```
    int32 operator""_i32(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_i32 << xtd::environment::new_line;
    /// ```
    int32 operator""_i32(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_i32 << xtd::environment::new_line;
    /// ```
    int32 operator""_i32(const wchar_t* s, std::size_t n);

    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_s32 << xtd::environment::new_line;
    /// ```
    int32 operator""_s32(long double n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_s32 << xtd::environment::new_line;
    /// ```
    int32 operator""_s32(unsigned long long n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_s32 << xtd::environment::new_line;
    /// ```
    int32 operator""_s32(const char* s, std::size_t n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_s32 << xtd::environment::new_line;
    /// ```
    int32 operator""_s32(const char8_t* s, std::size_t n);
#endif
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_s32 << xtd::environment::new_line;
    /// ```
    int32 operator""_s32(const char16_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_s32 << xtd::environment::new_line;
    /// ```
    int32 operator""_s32(const char32_t* s, std::size_t n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_s32 << xtd::environment::new_line;
    /// ```
    int32 operator""_s32(const wchar_t* s, std::size_t n);
    /// @}
  }
}
