/// @file
/// @brief Contains xtd::forms::status_bar_panel_border_style enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of the border for a xtd::forms::status_bar_panel on a xtd::forms::status_bar control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::forms::status_bar_panel::border_style property of the xtd::forms::status_bar_panel class. The xtd::forms::status_bar_panelborder_style property enables you to specify the style of border to display on a xtd::forms::status_bar_panel within a xtd::forms::status_bar.
    enum class status_bar_panel_border_style {
      /// @brief No border is displayed.
      none = 1,
      /// @brief The xtd::forms::status_bar_panel is displayed with a three-dimensional outset border.
      outset = 2,
      /// @brief The xtd::forms::status_bar_panel is displayed with a three-dimensional inset border.
      inset = 3,
      /// @brief Defines a raised border. Same as xtd::forms::status_bar_panel_border_style::outset.
      raised = outset,
      /// @brief Defines a sunken border. Same as xtd::forms::status_bar_panel_border_style::inset.
      sunken = inset,
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, const status_bar_panel_border_style value) {return os << to_string(value, {{status_bar_panel_border_style::none, "none"}, {status_bar_panel_border_style::outset, "outset"}, {status_bar_panel_border_style::inset, "inset"}});}
    inline std::wostream& operator<<(std::wostream& os, const status_bar_panel_border_style value) {return os << to_string(value, {{status_bar_panel_border_style::none, L"none"}, {status_bar_panel_border_style::outset, L"outset"}, {status_bar_panel_border_style::inset, L"inset"}});}
    /// @endcond
  }
}
