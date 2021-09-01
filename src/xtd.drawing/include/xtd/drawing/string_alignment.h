/// @file
/// @brief Contains xtd::drawing::string_alignment enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

#if defined(_WIN32)
#undef far
#undef near
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the alignment of a text string relative to its layout rectangle.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    /// @remarks When used with the line_alignment property, this enumeration sets the vertical alignment for a drawn string. When used with the alignment property, this enumeration sets the horizontal alignment.
    enum class string_alignment {
      /// @brief Specifies the text be aligned near the layout. In a left-to-right layout, the near position is left. In a right-to-left layout, the near position is right.
      near = 0,
      /// @brief Specifies that text is aligned in the center of the layout rectangle.
      center = 1,
      /// @brief Specifies that text is aligned far from the origin position of the layout rectangle. In a left-to-right layout, the far position is right. In a right-to-left layout, the far position is left.
      far = 2
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, string_alignment value) {return os << xtd::to_string(value, {{string_alignment::near, "near"}, {string_alignment::center, "center"}, {string_alignment::far, "far"}});}
    inline std::wostream& operator<<(std::wostream& os, string_alignment value) {return os << xtd::to_string(value, {{string_alignment::near, L"near"}, {string_alignment::center, L"center"}, {string_alignment::far, L"far"}});}
    /// @endcond
  }
}
