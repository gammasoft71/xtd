/// @file
/// @brief Contains xtd::forms::color_box_styles enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which color_box styles is used.
    /// @par Header
    /// @code #include <xtd/forms/color_box_styles> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the color_box class.
    enum class color_box_styles {
      /// @brief The cause of the closure was not defined or could not be determined.
      none = 0,
      /// @brief The color box shows alpha values and an opacity selector (slider).
      alpha_color = 0b1,
      /// @brief The user can use the dialog box to define custom colors.
      allow_full_open = 0b10,
      /// @brief The dialog box displays all available colors in the set of basic colors.
      any_color = 0b100,
      /// @brief The controls used to create custom colors are visible when the dialog box is opened
      full_open = 0b1000,
      /// @brief A Help button appears in the color dialog box.
      show_help = 0b10000,
      /// @brief The dialog box will restrict users to selecting solid colors only.
      solid_color_only = 0b100000,
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, color_box_styles);

template<> struct xtd::enum_register<xtd::forms::color_box_styles> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::color_box_styles> {{xtd::forms::color_box_styles::none, "none"}, {xtd::forms::color_box_styles::alpha_color, "alpha_color"}, {xtd::forms::color_box_styles::allow_full_open, "allow_full_open"}, {xtd::forms::color_box_styles::any_color, "any_color"}, {xtd::forms::color_box_styles::full_open, "full_open"}, {xtd::forms::color_box_styles::show_help, "show_help"}, {xtd::forms::color_box_styles::solid_color_only, "solid_color_only"}};}
};
/// @endcond
