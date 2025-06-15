/// @file
/// @brief Contains xtd::uri suffix.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../uri.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name URI suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::uri.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::uri u = "https://https://gammasoft71.github.io/xtd/"_uri;
    /// xtd::console::out << u << xtd::environment::new_line;
    /// ```
    xtd::uri operator""_uri(const char* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::uri.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::uri u = u8"https://https://gammasoft71.github.io/xtd/"_uri;
    /// xtd::console::out << u << xtd::environment::new_line;
    /// ```
    xtd::uri operator""_uri(const char8* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::uri.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::uri u = u"https://https://gammasoft71.github.io/xtd/"_uri;
    /// xtd::console::out << u << xtd::environment::new_line;
    /// ```
    xtd::uri operator""_uri(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::uri.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::uri u = U"https://https://gammasoft71.github.io/xtd/"_uri;
    /// xtd::console::out << u << xtd::environment::new_line;
    /// ```
    xtd::uri operator""_uri(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::uri.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::uri u = L"https://https://gammasoft71.github.io/xtd/"_uri;
    /// xtd::console::out << u << xtd::environment::new_line;
    /// ```
    xtd::uri operator""_uri(const wchar* s, xtd::size n);
    /// @}
  }
}
