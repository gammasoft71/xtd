/// @file
/// @brief Contains xtd::forms::menu_item_kind enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent menu item kind used by xtd::forms::menu_item component.
    /// @par Header
    /// @code #include <xtd/forms/menu_item_kind> @endcode
    /// @par Namespace
    /// xtd::forms
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
      /// Separator menu item.
      separator = 4,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::menu_item_kind> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::menu_item_kind> {{xtd::forms::menu_item_kind::normal, "normal"}, {xtd::forms::menu_item_kind::check, "check"}, {xtd::forms::menu_item_kind::radio, "radio"}, {xtd::forms::menu_item_kind::drop_down, "drop_down"}, {xtd::forms::menu_item_kind::separator, "separator"}};}
};
/// @endcond
