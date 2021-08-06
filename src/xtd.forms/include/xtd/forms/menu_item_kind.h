/// @file
/// @brief Contains xtd::forms::menu_item_kind enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent menu item kind used by xtd::forms::menu_item component.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class menu_item_kind {
      /// Normal menu item.
      normal = 0,
      /// Check menu item.
      check = 1,
      /// Radio menu item.
      radio = 2,
      /// Drop down menu item.
      drop_down = 3,
      /// Seprator menu item.
      separator = 4,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, menu_item_kind value) {return os << to_string(value, {{menu_item_kind::normal, "normal"}, {menu_item_kind::check, "check"}, {menu_item_kind::radio, "radio"}, {menu_item_kind::drop_down, "drop_down"}, {menu_item_kind::separator, "separator"}});}
    inline std::wostream& operator<<(std::wostream& os, menu_item_kind value) {return os << to_string(value, {{menu_item_kind::normal, L"normal"}, {menu_item_kind::check, L"check"}, {menu_item_kind::radio, L"radio"}, {menu_item_kind::drop_down, L"drop_down"}, {menu_item_kind::separator, L"separator"}});}
    /// @endcond
  }
}
