/// @file
/// @brief Contains xtd::forms::visual_styles::push_button_state enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::visual_styles namespace contains classes for rendering controls and other windows user interface (UI) elements with visual styles in operating systems that support them.
    namespace visual_styles {
      /// @brief Specifies the visual state of a button that is drawn with visual styles.
      /// @par Namespace
      /// xtd::forms::visual_style
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      /// @remarks The push_button_state values correspond to the states of the visual_style_element objects exposed by the visual_style_element:button::push_button class. The push_button_state values are also used as an argument in the button_renderer.draw_button method.
      enum class push_button_state {
        /// @brief The button has the normal appearance.
        normal = 1,
        /// @brief The button is hot.
        hot,
        /// @brief The button is pressed.
        pressed,
        /// @brief The button is checked.
        checked,
        /// @brief The button is disabled.
        disabled,
        /// @brief The button has the default appearance.
        default_state,
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, push_button_state value) {return os << to_string(value, {{push_button_state::normal, "normal"}, {push_button_state::hot, "hot"}, {push_button_state::pressed, "pressed"}, {push_button_state::disabled, "disabled"}, {push_button_state::default_state, "default_state"}});}
      inline std::wostream& operator<<(std::wostream& os, push_button_state value) {return os << to_string(value, {{push_button_state::normal, L"normal"}, {push_button_state::hot, L"hot"}, {push_button_state::pressed, L"pressed"}, {push_button_state::disabled, L"disabled"}, {push_button_state::default_state, L"default_state"}});}
      /// @endcond
    }
  }
}
