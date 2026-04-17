/// @file
/// @brief Contains xtd::usize suffixes.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../usize.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Size suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] constexpr auto operator""_uz(long double n) -> xtd::usize {return static_cast<xtd::usize>(n);}
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] constexpr auto operator""_uz(unsigned long long n) -> xtd::usize {return static_cast<xtd::usize>(n);}
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_uz(const char* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_uz(const char8_t* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_uz(const char16_t* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_uz(const char32_t* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_uz << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_uz(const wchar_t* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into signed xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 1.6_z << xtd::environment::new_line;
    /// ```
    [[nodiscard]] constexpr auto operator""_z(long double n) -> xtd::usize {return static_cast<xtd::usize>(n);}
    
    /// @brief Used to convert specified value into signed xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << 54_z << xtd::environment::new_line;
    /// ```
    [[nodiscard]] constexpr auto operator""_z(unsigned long long n) -> xtd::usize {return static_cast<xtd::usize>(n);}
    
    /// @brief Used to convert specified value into signed xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << "125"_z << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_z(const char* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into signed xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u8"125"_z << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_z(const char8_t* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into signed xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << u"125"_z << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_z(const char16_t* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into signed xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << U"125"_z << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_z(const char32_t* s, xtd::usize n) -> xtd::usize;
    
    /// @brief Used to convert specified value into signed xtd::usize.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::console::out << L"125"_z << xtd::environment::new_line;
    /// ```
    [[nodiscard]] auto operator""_z(const wchar_t* s, xtd::usize n) -> xtd::usize;
    /// @}
  }
}
