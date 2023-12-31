/// @file
/// @brief Contains xtd::forms::visual_styles::radio_button_state enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::visual_styles namespace contains classes for rendering controls and other windows user interface (UI) elements with visual styles in operating systems that support them.
    namespace visual_styles {
      /// @brief Specifies the visual state of a radio button that is drawn with visual styles.
      /// @par Header
      /// @code #include <xtd/forms/visual_styles/radio_button_state> @endcode
      /// @par Namespace
      /// xtd::forms::visual_style
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      /// @remarks The xtd::forms::visual_styles::radio_button_state values correspond to the states of the visual style element objects exposed by the xtd::forms::radio_button class. The xtd::forms::visual_styles::radio_button_state values are also used as an argument in the xtd::forms::radio_button_renderer::draw_radio_button method.
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
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::visual_styles::radio_button_state> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::visual_styles::radio_button_state> {{xtd::forms::visual_styles::radio_button_state::unchecked_normal, "unchecked_normal"}, {xtd::forms::visual_styles::radio_button_state::unchecked_hot, "unchecked_hot"}, {xtd::forms::visual_styles::radio_button_state::unchecked_pressed, "unchecked_pressed"}, {xtd::forms::visual_styles::radio_button_state::unchecked_disabled, "unchecked_disabled"}, {xtd::forms::visual_styles::radio_button_state::checked_normal, "checked_normal"}, {xtd::forms::visual_styles::radio_button_state::checked_hot, "checked_hot"}, {xtd::forms::visual_styles::radio_button_state::checked_pressed, "checked_pressed"}, {xtd::forms::visual_styles::radio_button_state::checked_disabled, "checked_disabled"}};}
};
/// @endcond
