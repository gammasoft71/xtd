/// @file
/// @brief Contains xtd::size suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../size.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
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
    constexpr xtd::size operator""_uz(long double n) {return static_cast<xtd::size>(n);}
    
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
    constexpr xtd::size operator""_uz(unsigned long long n) {return static_cast<xtd::size>(n);}
    
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
    constexpr xtd::size operator""_z(long double n) {return static_cast<xtd::size>(n);}
    
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
    constexpr xtd::size operator""_z(unsigned long long n) {return static_cast<xtd::size>(n);}
    
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
