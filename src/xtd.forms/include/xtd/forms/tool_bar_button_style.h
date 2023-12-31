/// @file
/// @brief Contains xtd::forms::tool_bar_button_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the button style within a toolbar.
    /// @par Header
    /// @code #include <xtd/forms/tool_bar_button_style> @endcode
    /// @par Namespace
    /// xtd::forms:
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by members such as xtd::forms::tool_bar_button::style.
    /// @remarks The toolbar button appearance is determined by the xtd::forms::tool_bar::appearance property of the toolbar. Setting the xtd::forms::tool_bar::appearance property to xtd::forms::tool_bar_appearance::flat will give the toolbar and its buttons a flat appearance. As the mouse pointer moves over the buttons, they take on a three-dimensional appearance. Also, when the toolbar has a flat appearance, button separators appear as a line rather than as a space between the buttons.
    enum class tool_bar_button_style {
      /// @brief A standard, three-dimensional button.
      push_button = 1,
      /// @brief A toggle button that appears sunken when clicked and retains the sunken appearance until clicked again.
      toggle_button = 2,
      /// @brief A space or line between toolbar buttons. The appearance depends on the value of the xtd::forms::tool_bar::appearance property.
      separator = 3,
      /// @brief A drop-down control that displays a menu or other window when clicked.
      drop_down_button = 4,
      /// @brief A stretchable space with or without line between toolbar buttons. The appearance depends on the value of the xtd::forms::tool_bar::appearance property.
      stretchable_separator = 5,
      /// @brief Use to add any control to the toolbar. Using with xtd::forms::tool_bar_button::control property.
      control = 6,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::tool_bar_button_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::tool_bar_button_style> {{xtd::forms::tool_bar_button_style::push_button, "push_button"}, {xtd::forms::tool_bar_button_style::toggle_button, "toggle_button"}, {xtd::forms::tool_bar_button_style::separator, "separator"}, {xtd::forms::tool_bar_button_style::drop_down_button, "drop_down_button"}, {xtd::forms::tool_bar_button_style::stretchable_separator, "stretchable_separator"}, {xtd::forms::tool_bar_button_style::control, "control"}};}
};
/// @endcond
