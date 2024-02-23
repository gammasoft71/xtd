/// @file
/// @brief Contains xtd::drawing::font_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies style information applied to text. This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing fonts
    enum class font_style {
      /// @brief Normal text.
      regular = 0,
      /// @brief Bold text.
      bold = 0b1,
      /// @brief Italic text.
      italic = 0b10,
      /// @brief Underline text.
      underline = 0b100,
      /// @brief Text with a line through the middle.
      strikeout = 0b1000
    };
  }
}

/// @cond
flags_attribute_(xtd::drawing, font_style);

template<> struct xtd::enum_register<xtd::drawing::font_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::font_style> {{xtd::drawing::font_style::regular, "regular"}, {xtd::drawing::font_style::bold, "bold"}, {xtd::drawing::font_style::italic, "italic"}, {xtd::drawing::font_style::underline, "underline"}, {xtd::drawing::font_style::strikeout, "strikeout"}};}
};
/// @endcond
