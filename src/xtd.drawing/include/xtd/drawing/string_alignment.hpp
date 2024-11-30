/// @file
/// @brief Contains xtd::drawing::string_alignment enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @cond
#undef far
#undef near
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the alignment of a text string relative to its layout rectangle.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing texts
    /// @remarks When used with the line_alignment property, this enumeration sets the vertical alignment for a drawn string. When used with the alignment property, this enumeration sets the horizontal alignment.
    enum class string_alignment {
      /// @brief Specifies the text be aligned near the layout. In a left-to-right layout, the near position is left. In a right-to-left layout, the near position is right.
      near = 0,
      /// @brief Specifies that text is aligned in the center of the layout rectangle.
      center = 1,
      /// @brief Specifies that text is aligned far from the origin position of the layout rectangle. In a left-to-right layout, the far position is right. In a right-to-left layout, the far position is left.
      far = 2
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::string_alignment> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::string_alignment> {{xtd::drawing::string_alignment::near, "near"}, {xtd::drawing::string_alignment::center, "center"}, {xtd::drawing::string_alignment::far, "far"}};}
};
/// @endcond
