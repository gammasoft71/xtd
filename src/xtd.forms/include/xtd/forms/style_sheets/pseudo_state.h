/// @file
/// @brief Contains xtd::forms::style_sheets::pseudo_state enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The pseudo_state enum class flag specifies the pseudo state of an element.
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/pseudo_state> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      enum class pseudo_state {
        /// @brief The item is in standard state.
        standard,
        /// @brief The item is hover (mouse is on the item).
        hover = 0b1,
        /// @brief The irem is pressed, mouse is down on the item.
        pressed = 0b10,
        /// @brief The irem is disabled, generally the item is grayed.
        disabled = 0b100,
        /// @brief The item is focused.
        focused = 0b1000,
        /// @brief The item is the default (see ibutton_control).
        default_state = 0b10000,
        /// @brief The item is unchecked.
        unchecked = standard,
        /// @brief The item is checked.
        checked = 0b100000,
        /// @brief The item is mixed. For the three-state ittem.
        mixed = 0b1000000,
        /// @brief The item is link text.
        /// @remarks The link text color is the text color of an html link text.
        link = 0b10000000,
        /// @brief The item is visited text.
        /// @remarks The visited text color is the text color of an html visited link text.
        visited = 0b100000000,
        /// @brief The item is ative text.
        /// @remarks The active text color is the text color of an html link text when mouse down.
        active = 0b1000000000,
      };
    }
  }
}

/// @cond
flags_attribute_(xtd::forms, style_sheets::pseudo_state);

template<> struct xtd::enum_register<xtd::forms::style_sheets::pseudo_state> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::style_sheets::pseudo_state> {{xtd::forms::style_sheets::pseudo_state::standard, "standard"}, {xtd::forms::style_sheets::pseudo_state::hover, "hover"}, {xtd::forms::style_sheets::pseudo_state::pressed, "pressed"}, {xtd::forms::style_sheets::pseudo_state::disabled, "disabled"}, {xtd::forms::style_sheets::pseudo_state::focused, "focused"}, {xtd::forms::style_sheets::pseudo_state::default_state, "default_state"}, {xtd::forms::style_sheets::pseudo_state::unchecked, "unchecked"}, {xtd::forms::style_sheets::pseudo_state::checked, "checked"}, {xtd::forms::style_sheets::pseudo_state::mixed, "mixed"}};}
};
/// @endcond
