/// @file
/// @brief Contains xtd::guid suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../guid.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Guid suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::guid.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::guid g = "1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
    /// xtd::console::out << g << xtd::environment::new_line;
    /// ```
    xtd::guid operator""_guid(const char* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::guid.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::guid g = u8"1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
    /// xtd::console::out << g << xtd::environment::new_line;
    /// ```
    xtd::guid operator""_guid(const char8* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::guid.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::guid g = u"1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
    /// xtd::console::out << g << xtd::environment::new_line;
    /// ```
    xtd::guid operator""_guid(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::guid.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::guid g = U"1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
    /// xtd::console::out << g << xtd::environment::new_line;
    /// ```
    xtd::guid operator""_guid(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::guid.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::guid g = L"1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
    /// xtd::console::out << g << xtd::environment::new_line;
    /// ```
    xtd::guid operator""_guid(const wchar* s, xtd::size n);
    /// @}
  }
}
