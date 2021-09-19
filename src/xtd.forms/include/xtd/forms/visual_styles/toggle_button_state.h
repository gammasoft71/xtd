/// @file
/// @brief Contains xtd::forms::visual_styles::toggle_button_state enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::visual_styles namespace contains classes for rendering controls and other windows user interface (UI) elements with visual styles in operating systems that support them.
    namespace visual_styles {
      /// @brief Specifies the visual state of a check box that is drawn with visual styles.
      /// @par Namespace
      /// xtd::forms::visual_style
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      /// @remarks The toggle_button_state values correspond to the states of the visual_style_element objects exposed by the visual_style_element::toggle_button class. The toggle_button_state values are also used as an argument in the toggle_button_renderer.toggle_button method.
      enum class toggle_button_state {
        /// @brief The check box is unchecked.
        unchecked_normal = 1,
        /// @brief The check box is unchecked and hot.
        unchecked_hot,
        /// @brief The check box is unchecked and pressed.
        unchecked_pressed,
        /// @brief The check box is unchecked and disabled.
        unchecked_disabled,
        /// @brief The check box is checked.
        checked_normal,
        /// @brief The check box is checked and hot.
        checked_hot,
        /// @brief The check box is checked and pressed.
        checked_pressed,
        /// @brief The check box is checked and disabled.
        checked_disabled,
        /// @brief The check box is three-state.
        mixed_normal,
        /// @brief The check box is three-state and hot.
        mixed_hot,
        /// @brief The check box is three-state and pressed.
        mixed_pressed,
        /// @brief The check box is three-state and disabled.
        mixed_disabled,
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, toggle_button_state value) {return os << to_string(value, {{toggle_button_state::unchecked_normal, "unchecked_normal"}, {toggle_button_state::unchecked_hot, "unchecked_hot"}, {toggle_button_state::unchecked_pressed, "unchecked_pressed"}, {toggle_button_state::unchecked_disabled, "unchecked_disabled"}, {toggle_button_state::checked_normal, "checked_normal"}, {toggle_button_state::checked_hot, "checked_hot"}, {toggle_button_state::checked_pressed, "checked_pressed"}, {toggle_button_state::checked_disabled, "checked_disabled"}, {toggle_button_state::mixed_normal, "mixed_normal"}, {toggle_button_state::mixed_hot, "mixed_hot"}, {toggle_button_state::mixed_pressed, "mixed_pressed"}, {toggle_button_state::mixed_disabled, "mixed_disabled"}});}
      inline std::wostream& operator<<(std::wostream& os, toggle_button_state value) {return os << to_string(value, {{toggle_button_state::unchecked_normal, L"unchecked_normal"}, {toggle_button_state::unchecked_hot, L"unchecked_hot"}, {toggle_button_state::unchecked_pressed, L"unchecked_pressed"}, {toggle_button_state::unchecked_disabled, L"unchecked_disabled"}, {toggle_button_state::checked_normal, L"checked_normal"}, {toggle_button_state::checked_hot, L"checked_hot"}, {toggle_button_state::checked_pressed, L"checked_pressed"}, {toggle_button_state::checked_disabled, L"checked_disabled"}, {toggle_button_state::mixed_normal, L"mixed_normal"}, {toggle_button_state::mixed_hot, L"mixed_hot"}, {toggle_button_state::mixed_pressed, L"mixed_pressed"}, {toggle_button_state::mixed_disabled, L"mixed_disabled"}});}
      /// @endcond
    }
  }
}
