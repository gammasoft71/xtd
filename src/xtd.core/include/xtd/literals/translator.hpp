/// @file
/// @brief Contains xtd::globalization::translator suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../string.hpp"
#include "../types.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Translator suffixes
    
    /// @{
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = "Belgium"_t;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    const char* operator""_t(const char* s, xtd::size n) noexcept;
    
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = u8"Belgium"_t;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_t(const char8* s, xtd::size n) noexcept;
    
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = u"Belgium"_t;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_t(const char16* s, xtd::size n) noexcept;
    
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = U"Belgium"_t;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_t(const char32* s, xtd::size n) noexcept;
    
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = L"Belgium"_t;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_t(const wchar* s, xtd::size n) noexcept;
    /// @}
  }
}
