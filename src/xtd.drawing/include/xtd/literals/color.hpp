/// @file
/// @brief Contains xtd::drawing::color suffixex.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../drawing/color.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Color suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::drawing::color.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::color c1 = "dodger blue"_color;
    /// xtd::console::out << c1 << xtd::environment::new_line;
    /// xtd::drawing::color c2 = "80FF0000"_color;
    /// xtd::console::out << c2 << xtd::environment::new_line;
    /// xtd::drawing::color c3 = "0x00ff00"_color;
    /// xtd::console::out << c3 << xtd::environment::new_line;
    /// ```
    xtd::drawing::color operator""_color(const char* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::drawing::color.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::color c1 = u8"dodger blue"_color;
    /// xtd::console::out << c1 << xtd::environment::new_line;
    /// xtd::drawing::color c2 = u8"80FF0000"_color;
    /// xtd::console::out << c2 << xtd::environment::new_line;
    /// xtd::drawing::color c3 = u8"0x00ff00"_color;
    /// xtd::console::out << c3 << xtd::environment::new_line;
    /// ```
    xtd::drawing::color operator""_color(const char8* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::drawing::color.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::color c1 = u"dodger blue"_color;
    /// xtd::console::out << c1 << xtd::environment::new_line;
    /// xtd::drawing::color c2 = u"80FF0000"_color;
    /// xtd::console::out << c2 << xtd::environment::new_line;
    /// xtd::drawing::color c3 = u"0x00ff00"_color;
    /// xtd::console::out << c3 << xtd::environment::new_line;
    /// ```
    xtd::drawing::color operator""_color(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::drawing::color.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::color c1 = U"dodger blue"_color;
    /// xtd::console::out << c1 << xtd::environment::new_line;
    /// xtd::drawing::color c2 = U"80FF0000"_color;
    /// xtd::console::out << c2 << xtd::environment::new_line;
    /// xtd::drawing::color c3 = U"0x00ff00"_color;
    /// xtd::console::out << c3 << xtd::environment::new_line;
    /// ```
    xtd::drawing::color operator""_color(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::drawing::color.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::color c1 = L"dodger blue"_color;
    /// xtd::console::out << c1 << xtd::environment::new_line;
    /// xtd::drawing::color c2 = L"80FF0000"_color;
    /// xtd::console::out << c2 << xtd::environment::new_line;
    /// xtd::drawing::color c3 = L"0x00ff00"_color;
    /// xtd::console::out << c3 << xtd::environment::new_line;
    /// ```
    xtd::drawing::color operator""_color(const wchar* s, xtd::size n);
    /// @}
  }
}
