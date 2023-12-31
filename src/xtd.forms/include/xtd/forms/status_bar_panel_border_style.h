/// @file
/// @brief Contains xtd::forms::status_bar_panel_border_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of the border for a xtd::forms::status_bar_panel on a xtd::forms::status_bar control.
    /// @par Header
    /// @code #include <xtd/forms/status_bar_panel_bo> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.formsrder_style
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::status_bar_panel_border_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::status_bar_panel_border_style> {{xtd::forms::status_bar_panel_border_style::none, "none"}, {xtd::forms::status_bar_panel_border_style::outset, "outset"}, {xtd::forms::status_bar_panel_border_style::inset, "inset"}};}
};
/// @endcond
