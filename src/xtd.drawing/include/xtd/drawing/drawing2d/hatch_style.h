/// @file
/// @brief Contains xtd::drawing::drawing2d::hatch_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/strings.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies the different patterns available for xtd::drawing::drawing2d::hatch_brush objects.
      enum class hatch_style {
        /// @brief A pattern of horizontal lines.
        horizontal = 0,
        /// @brief A pattern of vertical lines.
        vertical = 1,
        /// @brief A pattern of lines on a diagonal from upper left to lower right.
        forward_diagonal = 2,
        /// @brief A pattern of lines on a diagonal from upper right to lower left.
        backward_diagonal = 3,
        /// @brief Specifies horizontal and vertical lines that cross.
        cross = 4,
        /// @brief A pattern of crisscross diagonal lines.
        diagonal_cross = 5,
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, hatch_style value) {return os << to_string(value, {{hatch_style::horizontal, "horizontal"}, {hatch_style::vertical, "vertical"}, {hatch_style::forward_diagonal, "forward_diagonal"}, {hatch_style::backward_diagonal, "backward_diagonal"}});}
      inline std::wostream& operator<<(std::wostream& os, hatch_style value) {return os << to_string(value, {{hatch_style::horizontal, L"horizontal"}, {hatch_style::vertical, L"vertical"}, {hatch_style::forward_diagonal, L"forward_diagonal"}, {hatch_style::backward_diagonal, L"backward_diagonal"}});}
      /// @endcond
    }
  }
}
