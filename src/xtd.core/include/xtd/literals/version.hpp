/// @file
/// @brief Contains xtd::version suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../version.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Version suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::version.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::version v = "1.2.3"_vers;
    /// xtd::console::out << v << xtd::environment::new_line;
    /// ```
    xtd::version operator""_vers(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::version.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::version v = u8"1.2.3"_vers;
    /// xtd::console::out << v << xtd::environment::new_line;
    /// ```
    xtd::version operator""_vers(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::version.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::version v = u"1.2.3"_vers;
    /// xtd::console::out << v << xtd::environment::new_line;
    /// ```
    xtd::version operator""_vers(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::version.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::version v = U"1.2.3"_vers;
    /// xtd::console::out << v << xtd::environment::new_line;
    /// ```
    xtd::version operator""_vers(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::version.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::version v = L"1.2.3"_vers;
    /// xtd::console::out << v << xtd::environment::new_line;
    /// ```
    xtd::version operator""_vers(const wchar* s, xtd::size n);
    /// @}
  }
}
