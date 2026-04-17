/// @file
/// @brief Contains xtd::int32 suffixes.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include "../int32.hpp"
#include "../usize.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
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
    [[nodiscard]] auto operator""_i32(long double n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_i32(unsigned long long n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_i32(const char* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_i32(const char8_t* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_i32(const char16_t* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_i32(const char32_t* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_i32(const wchar_t* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_s32(long double n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_s32(unsigned long long n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_s32(const char* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_s32(const char8_t* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_s32(const char16_t* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_s32(const char32_t* s, xtd::usize n) -> xtd::int32;
    
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
    [[nodiscard]] auto operator""_s32(const wchar_t* s, xtd::usize n) -> xtd::int32;
    /// @}
  }
}
