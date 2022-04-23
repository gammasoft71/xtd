/// @file
/// @brief Contains xtd::forms::search_direction enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the search direction for xtd::forms::find_dialog dialog.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class search_direction {
      /// @brief Search direction down.
      down = 0,
      /// @brief Search direction up.
      up = 1,
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, search_direction value) {return os << to_string(value, {{search_direction::down, "down"}, {search_direction::up, "up"}});}
    inline std::wostream& operator<<(std::wostream& os, search_direction value) {return os << to_string(value, {{search_direction::down, L"down"}, {search_direction::up, L"up"}});}
    /// @endcond
  }
}
