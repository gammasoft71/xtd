/// @file
/// @brief Contains xtd::forms::visual_styles::radio_button_state enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::visual_styles namespace contains classes for rendering controls and other windows user interface (UI) elements with visual styles in operating systems that support them.
    namespace visual_styles {
      /// @brief Specifies the visual state of a radio button that is drawn with visual styles.
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      /// @remarks The radio_button_state values correspond to the states of the visual_style_element objects exposed by the visual_style_element::radio_button::radio_button class. The radio_button_state values are also used as an argument in the radio_button_renderer.draw_radio_button method.
      enum class radio_button_state {
        /// @brief The radio button is unchecked.
        unchecked_normal = 1,
        /// @brief The radio button is unchecked and hot.
        unchecked_hot,
        /// @brief The radio button is unchecked and pressed.
        unchecked_pressed,
        /// @brief The radio button is unchecked and disabled.
        unchecked_disabled,
        /// @brief The radio button is checked.
        checked_normal,
        /// @brief The radio button is checked and hot.
        checked_hot,
        /// @brief The radio button is checked and pressed.
        checked_pressed,
        /// @brief The radio button is checked and disabled.
        checked_disabled,
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, radio_button_state value) {return os << to_string(value, {{radio_button_state::unchecked_normal, "unchecked_normal"}, {radio_button_state::unchecked_hot, "unchecked_hot"}, {radio_button_state::unchecked_pressed, "unchecked_pressed"}, {radio_button_state::unchecked_disabled, "unchecked_disabled"}, {radio_button_state::checked_normal, "checked_normal"}, {radio_button_state::checked_hot, "checked_hot"}, {radio_button_state::checked_pressed, "checked_pressed"}, {radio_button_state::checked_disabled, "checked_disabled"}});}
      inline std::wostream& operator<<(std::wostream& os, radio_button_state value) {return os << to_string(value, {{radio_button_state::unchecked_normal, L"unchecked_normal"}, {radio_button_state::unchecked_hot, L"unchecked_hot"}, {radio_button_state::unchecked_pressed, L"unchecked_pressed"}, {radio_button_state::unchecked_disabled, L"unchecked_disabled"}, {radio_button_state::checked_normal, L"checked_normal"}, {radio_button_state::checked_hot, L"checked_hot"}, {radio_button_state::checked_pressed, L"checked_pressed"}, {radio_button_state::checked_disabled, L"checked_disabled"}});}
      /// @endcond
    }
  }
}
