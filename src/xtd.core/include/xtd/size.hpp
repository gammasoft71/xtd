/// @file
/// @brief Contains xtd::size type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represents a size of any object in bytes
  /// @par Header
  /// ```cpp
  /// #include <xtd/size>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  using size = size_t;
  /// @}
  
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Size suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_uz(long double n);
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_uz(unsigned long long n);
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_uz(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_uz(const char8_t* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_uz(const char16_t* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_uz(const char32_t* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_uz(const wchar_t* s, xtd::size n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_z(long double n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_z(unsigned long long n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_z(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_z(const char8_t* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_z(const char16_t* s, xtd::size n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_z(const char32_t* s, xtd::size n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_z << xtd::environment::new_line;
    /// ```
    xtd::size operator""_z(const wchar_t* s, xtd::size n);
    /// @}
  }
}
