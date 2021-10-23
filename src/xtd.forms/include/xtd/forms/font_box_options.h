/// @file
/// @brief Contains xtd::forms::font_box_options control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies options on a xtd::forms::font_box.
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

    /// @cond
    inline font_box_options& operator +=(font_box_options& lhs, font_box_options rhs) noexcept { lhs = static_cast<font_box_options>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs; }
    inline font_box_options& operator -=(font_box_options& lhs, font_box_options rhs) noexcept { lhs = static_cast<font_box_options>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs; }
    inline font_box_options& operator &=(font_box_options& lhs, font_box_options rhs) noexcept { lhs = static_cast<font_box_options>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs; }
    inline font_box_options& operator |=(font_box_options& lhs, font_box_options rhs) noexcept { lhs = static_cast<font_box_options>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs; }
    inline font_box_options& operator ^=(font_box_options& lhs, font_box_options rhs) noexcept { lhs = static_cast<font_box_options>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs; }
    inline font_box_options operator +(font_box_options lhs, font_box_options rhs) noexcept { return static_cast<font_box_options>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); }
    inline font_box_options operator -(font_box_options lhs, font_box_options rhs) noexcept { return static_cast<font_box_options>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); }
    inline font_box_options operator ~(font_box_options rhs) noexcept { return static_cast<font_box_options>(~static_cast<long long>(rhs)); }
    inline bool operator &(font_box_options lhs, font_box_options rhs) noexcept { return static_cast<bool>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); }
    inline font_box_options operator |(font_box_options lhs, font_box_options rhs) noexcept { return static_cast<font_box_options>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); }
    inline font_box_options operator ^(font_box_options lhs, font_box_options rhs) noexcept { return static_cast<font_box_options>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); }

    inline std::ostream& operator<<(std::ostream& os, font_box_options value) { return os << to_string(value, { {font_box_options::none, "none"}, {font_box_options::allow_simulations, "allow_simulations"}, {font_box_options::allow_vector_fonts, "allow_vector_fonts"}, {font_box_options::allow_vertical_fonts, "allow_vertical_fonts"}, {font_box_options::allow_script_change, "allow_script_change"}, {font_box_options::fixed_pitch_only, "fixed_pitch_only"}, {font_box_options::scripts_only, "scripts_only"}, {font_box_options::show_apply, "show_apply"}, {font_box_options::show_color, "show_color"}, {font_box_options::show_effects, "show_effects"}, {font_box_options::show_help, "show_help"}, {font_box_options::all, "all"} }); }
    inline std::wostream& operator<<(std::wostream& os, font_box_options value) { return os << to_string(value, { {font_box_options::none, L"none"}, {font_box_options::allow_simulations, L"allow_simulations"}, {font_box_options::allow_vector_fonts, L"allow_vector_fonts"}, {font_box_options::allow_vertical_fonts, L"allow_vertical_fonts"}, {font_box_options::allow_script_change, L"allow_script_change"}, {font_box_options::fixed_pitch_only, L"fixed_pitch_only"}, {font_box_options::scripts_only, L"scripts_only"}, {font_box_options::show_apply, L"show_apply"}, {font_box_options::show_color, L"show_color"}, {font_box_options::show_effects, L"show_effects"}, {font_box_options::show_help, L"show_help"}, {font_box_options::all, L"all"} }); }
    /// @endcond
  }
}
