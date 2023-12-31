/// @file
/// @brief Contains xtd::forms::font_box_options control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies options on a xtd::forms::font_box.
    /// @par Header
    /// @code #include <xtd/forms/font_box_options> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::forms::font_box class.
    enum class font_box_options {
      /// @brief No options.
      none = 0b0,
      /// @brief Whether the dialog box allows graphics device interface (GDI) font simulations.
      allow_simulations = 0b1,
      /// @brief Whether the dialog box allows vector font selections.
      allow_vector_fonts = 0b10,
      /// @brief Whether the dialog box displays both vertical and horizontal fonts or only horizontal fonts.
      allow_vertical_fonts = 0b100,
      /// @brief Whether the user can change the character set specified in the Script combo box to display a character set other than the one currently displayed.
      allow_script_change = 0b1000,
      /// @brief Whether the dialog box allows only the selection of fixed-pitch fonts.
      fixed_pitch_only = 0b10000,
      /// @brief Whether the dialog box allows selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set.
      scripts_only = 0b100000,
      /// @brief Whether the dialog box contains an Apply button.
      show_apply = 0b1000000,
      /// @brief Whether the dialog box displays the color choice.
      show_color = 0b10000000,
      /// @brief Whether the dialog box contains controls that allow the user to specify strikethrough, underline, and text color options.
      show_effects = 0b100000000,
      /// @brief Whether the dialog box displays a Help button.
      show_help = 0b1000000000,
      /// @brief All flags except none.
      all = allow_simulations | allow_vector_fonts | allow_vertical_fonts | allow_script_change | fixed_pitch_only | scripts_only | show_apply | show_color | show_effects | show_help
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, font_box_options);

template<> struct xtd::enum_register<xtd::forms::font_box_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::font_box_options> {{xtd::forms::font_box_options::none, "none"}, {xtd::forms::font_box_options::allow_simulations, "allow_simulations"}, {xtd::forms::font_box_options::allow_vector_fonts, "allow_vector_fonts"}, {xtd::forms::font_box_options::allow_vertical_fonts, "allow_vertical_fonts"}, {xtd::forms::font_box_options::allow_script_change, "allow_script_change"}, {xtd::forms::font_box_options::fixed_pitch_only, "fixed_pitch_only"}, {xtd::forms::font_box_options::scripts_only, "scripts_only"}, {xtd::forms::font_box_options::show_apply, "show_apply"}, {xtd::forms::font_box_options::show_color, "show_color"}, {xtd::forms::font_box_options::show_effects, "show_effects"}, {xtd::forms::font_box_options::show_help, "show_help"}, {xtd::forms::font_box_options::all, "all"}};}
};
/// @endcond
