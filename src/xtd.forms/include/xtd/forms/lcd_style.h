/// @file
/// @brief Contains xtd::forms::lcd_style enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent lcd label style used by lcd_label control.
    /// @par Header
    /// @code #include <xtd/forms/lcd_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class lcd_style {
      /// @brief Seven segment display style.
      seven_segment_display,
      /// @brief Nine segment display style.
      nine_segment_display,
      /// @brief Fourteen segment display style.
      fourteen_segment_display,
      /// @brief Sixteen segment display style.
      sixteen_segment_display,
      /// @brief Dot matrix display style.
      dot_matrix_display,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::lcd_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::lcd_style> {{xtd::forms::lcd_style::seven_segment_display, "seven_segment_display"}, {xtd::forms::lcd_style::nine_segment_display, "nine_segment_display"}, {xtd::forms::lcd_style::fourteen_segment_display, "fourteen_segment_display"}, {xtd::forms::lcd_style::sixteen_segment_display, "sixteen_segment_display"}, {xtd::forms::lcd_style::dot_matrix_display, "dot_matrix_display"}};}
};
/// @endcond
