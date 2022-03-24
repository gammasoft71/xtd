/// @file
/// @brief Contains xtd::forms::visual_styles::control_state enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::visual_styles namespace contains classes for rendering controls and other windows user interface (UI) elements with visual styles in operating systems that support them.
    namespace visual_styles {
      /// @brief Specifies the visual state of a control that is drawn with visual styles.
      /// @par Namespace
      /// xtd::forms::visual_style
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      /// @remarks The xtd::forms::visual_styles::control_state values correspond to the states of the visual style element objects exposed by the xtd::forms::control class. The xtd::forms::visual_styles::control_state values are also used as an argument in the xtd::forms::control_renderer::draw_control method.
      enum class control_state {
        /// @brief The control has the normal appearance.
        normal = 1,
        /// @brief The control is hot.
        hot,
        /// @brief The control is pressed.
        pressed,
        /// @brief The control is disabled.
        disabled,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, control_state value) {return os << to_string(value, {{control_state::normal, "normal"}, {control_state::hot, "hot"}, {control_state::pressed, "pressed"}, {control_state::disabled, "disabled"}});}
      inline std::wostream& operator<<(std::wostream& os, control_state value) {return os << to_string(value, {{control_state::normal, L"normal"}, {control_state::hot, L"hot"}, {control_state::pressed, L"pressed"}, {control_state::disabled, L"disabled"}});}
      /// @endcond
    }
  }
}
