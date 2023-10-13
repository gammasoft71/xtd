/// @file
/// @brief Contains xtd::forms::loading_indicator_style enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a loading indicator control.
    /// @par Header
    /// @code #include <xtd/forms/loading_indicator_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks If the system style is used, the appearance of the control is determined by the user's operating system and the following property values will be ignored: control_background_image, image_align, image, image_index, image_list, and text_align. In addition, the control.back_color property will be ignored for button controls. If supported, users can change the appearance of controls by adjusting the appearance settings of their operating system.
    enum class loading_indicator_style {
      /// @brief The control appears with circle blinks style.
      circle_blinks = 0,
      /// @brief The control appears with five lines style.
      five_lines,
      /// @brief The control appears with five lines center style.
      five_lines_center,
      /// @brief The control appears with five lines chronological style.
      five_lines_chronological,
      /// @brief The control appears with five lines pulse style.
      five_lines_pulse,
      /// @brief The control appears with five lines wave style.
      five_lines_wave,
      /// @brief The control appears with standard style.
      standard,
      /// @brief The appearance of the control is determined by the user's operating system.
      system,
      /// @brief The control appears with three balls style.
      three_balls,
      /// @brief The control appears with three balls bouncing style.
      three_balls_bouncing,
      /// @brief The control appears with three balls rotation style.
      three_balls_rotation,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::loading_indicator_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::loading_indicator_style> {{xtd::forms::loading_indicator_style::circle_blinks, "circle_blinks"}, {xtd::forms::loading_indicator_style::five_lines_center, "five_lines_center"}, {xtd::forms::loading_indicator_style::five_lines_chronological, "five_lines_chronological"}, {xtd::forms::loading_indicator_style::five_lines_pulse, "five_lines_pulse"}, {xtd::forms::loading_indicator_style::five_lines_wave, "five_lines_wave"}, {xtd::forms::loading_indicator_style::five_lines, "five_lines"}, {xtd::forms::loading_indicator_style::standard, "standard"}, {xtd::forms::loading_indicator_style::system, "system"}, {xtd::forms::loading_indicator_style::three_balls, "three_balls"}, {xtd::forms::loading_indicator_style::three_balls_bouncing, "three_balls_bouncing"}, {xtd::forms::loading_indicator_style::three_balls_rotation, "three_balls_rotation"}};}
};
/// @endcond
