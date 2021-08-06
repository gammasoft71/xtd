/// @file
/// @brief Contains xtd::forms::color_box_styles enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which color_box styles is used.
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

    /// @cond
    inline color_box_styles& operator +=(color_box_styles& lhs, color_box_styles rhs) {lhs = static_cast<color_box_styles>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline color_box_styles& operator -=(color_box_styles& lhs, color_box_styles rhs) {lhs = static_cast<color_box_styles>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline color_box_styles& operator &=(color_box_styles& lhs, color_box_styles rhs) {lhs = static_cast<color_box_styles>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline color_box_styles& operator |=(color_box_styles& lhs, color_box_styles rhs) {lhs = static_cast<color_box_styles>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline color_box_styles& operator ^=(color_box_styles& lhs, color_box_styles rhs) {lhs = static_cast<color_box_styles>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline color_box_styles operator +(color_box_styles lhs, color_box_styles rhs) {return static_cast<color_box_styles>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline color_box_styles operator -(color_box_styles lhs, color_box_styles rhs) {return static_cast<color_box_styles>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline color_box_styles operator ~(color_box_styles rhs) {return static_cast<color_box_styles>(~static_cast<long long>(rhs));}
    inline color_box_styles operator &(color_box_styles lhs, color_box_styles rhs) {return static_cast<color_box_styles>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline color_box_styles operator |(color_box_styles lhs, color_box_styles rhs) {return static_cast<color_box_styles>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline color_box_styles operator ^(color_box_styles lhs, color_box_styles rhs) {return static_cast<color_box_styles>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, color_box_styles value) {return os << to_string(value, {{color_box_styles::none, "none"}, {color_box_styles::alpha_color, "alpha_color"}, {color_box_styles::allow_full_open, "allow_full_open"}, {color_box_styles::any_color, "any_color"}, {color_box_styles::full_open, "full_open"}, {color_box_styles::show_help, "show_help"}, {color_box_styles::solid_color_only, "solid_color_only"}});}
    inline std::wostream& operator<<(std::wostream& os, color_box_styles value) {return os << to_string(value, {{color_box_styles::none, L"none"}, {color_box_styles::alpha_color, L"alpha_color"}, {color_box_styles::allow_full_open, L"allow_full_open"}, {color_box_styles::any_color, L"any_color"}, {color_box_styles::full_open, L"full_open"}, {color_box_styles::show_help, L"show_help"}, {color_box_styles::solid_color_only, L"solid_color_only"}});}
    /// @endcond
  }
}
