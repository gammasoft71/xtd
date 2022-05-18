/// @file
/// @brief Contains xtd::forms::tool_bar_button_style enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the button style within a toolbar.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by members such as xtd::forms::tool_bar_button::style.
    /// @remarks The toolbar button appearance is determined by the xtd::forms::tool_bar::appearance property of the toolbar. Setting the xtd::forms::tool_bar::appearance property to xtd::forms::tool_bar_appearance::flat will give the toolbar and its buttons a flat appearance. As the mouse pointer moves over the buttons, they take on a three-dimensional appearance. Also, when the toolbar has a flat appearance, button separators appear as a line rather than as a space between the buttons.
    enum class tool_bar_button_style {
      push_button = 1,
      toggle_button = 2,
      separator = 3,
      drop_down_button = 4,
      stretchable_separator = 5,
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, tool_bar_button_style value) {return os << to_string(value, {{tool_bar_button_style::push_button, "push_button"}, {tool_bar_button_style::toggle_button, "toggle_button"}, {tool_bar_button_style::separator, "separator"}, {tool_bar_button_style::drop_down_button, "drop_down_button"}, {tool_bar_button_style::stretchable_separator, "stretchable_separator"}});}
    inline std::wostream& operator<<(std::wostream& os, tool_bar_button_style value) {return os << to_string(value, {{tool_bar_button_style::push_button, L"push_button"},{tool_bar_button_style::toggle_button, L"toggle_button"}, {tool_bar_button_style::separator, L"separator"}, {tool_bar_button_style::drop_down_button, L"drop_down_button"}, {tool_bar_button_style::stretchable_separator, L"stretchable_separator"}});}
    /// @endcond
  }
}
