#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief SSpecifies the alignment of a xtd::drawing::pen object in relation to the theoretical, zero-width line.
      /// @remarks A xtd::drawing::pen object has width. The center point of this pen width is aligned relative to the line being drawn depending on the alignment value. A xtd::draing::pen object can be positioned to draw inside of a line or centered over the line.
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @see xtd::drawing::pen
      enum class pen_alignment {
        center = 0,
        inset = 1,
        outset = 2,
        left = 3,
        right = 4,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, pen_alignment value) {return os << to_string(value, {{pen_alignment::center, "center"}, {pen_alignment::inset, "inset"}, {pen_alignment::outset, "outset"}, {pen_alignment::left, "left"}, {pen_alignment::right, "right"}});}
      inline std::wostream& operator<<(std::wostream& os, pen_alignment value) {return os << to_string(value, {{pen_alignment::center, L"center"}, {pen_alignment::inset, L"inset"}, {pen_alignment::outset, L"outset"}, {pen_alignment::left, L"left"}, {pen_alignment::right, L"right"}});}
      /// @endcond
    }
  }
}
