/// @file
/// @brief Contains xtd::forms::country suffixex.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../forms/country.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Color suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::forms::country.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::forms::country c = "Belgium"_country;
    /// xtd::console::out << c << xtd::environment::new_line;
    /// ```
    xtd::forms::country operator""_country(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::forms::country.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::forms::country c = u8"Belgium"_country;
    /// xtd::console::out << c << xtd::environment::new_line;
    /// ```
    xtd::forms::country operator""_country(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::forms::country.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::forms::country c = u"Belgium"_country;
    /// xtd::console::out << c << xtd::environment::new_line;
    /// ```
    xtd::forms::country operator""_country(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::forms::country.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::forms::country c = U"Belgium"_country;
    /// xtd::console::out << c << xtd::environment::new_line;
    /// ```
    xtd::forms::country operator""_country(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::forms::country.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::forms::country c = L"Belgium"_country;
    /// xtd::console::out << c << xtd::environment::new_line;
    /// ```
    xtd::forms::country operator""_country(const wchar* s, xtd::size n);
    /// @}
  }
}
