/// @file
/// @brief Contains xtd::drawing::drawing2d::pen_type enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies the type of fill a xtd::drawing::pen object uses to fill lines.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks The pen type is determined by the brush property of the xtd::drawing::pen object.
      enum class pen_type {
        /// @brief Specifies a solid fill.
        solid_color = 0,
        /// @brief Specifies a hatch fill.
        hatch_fill = 1,
        /// @brief Specifies a bitmap texture fill.
        texture_fill = 2,
        /// @brief Specifies a path gradient fill.
        path_gradient = 3,
        /// @brief Specifies a linear gradient fill.
        linear_gradient = 4
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, pen_type value) {return os << to_string(value, {{pen_type::solid_color, "solid_color"}, {pen_type::hatch_fill, "hatch_fill"}, {pen_type::texture_fill, "texture_fill"}, {pen_type::path_gradient, "path_gradient"}, {pen_type::linear_gradient, "linear_gradient"}});}
      inline std::wostream& operator<<(std::wostream& os, pen_type value) {return os << to_string(value, {{pen_type::solid_color, L"solid_color"}, {pen_type::hatch_fill, L"hatch_fill"}, {pen_type::texture_fill, L"texture_fill"}, {pen_type::path_gradient, L"path_gradient"}, {pen_type::linear_gradient, L"linear_gradient"}});}
      /// @endcond
    }
  }
}
