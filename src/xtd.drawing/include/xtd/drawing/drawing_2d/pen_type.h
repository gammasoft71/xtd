/// @file
/// @brief Contains xtd::drawing::drawing_2d::pen_type enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "drawing2d.h"
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Specifies the type of fill a xtd::drawing::pen object uses to fill lines.
      /// @par Namespace
      /// xtd::drawing::drawing_2d/
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
        linear_gradient = 4,
        /// @brief Specifies a conical gradient fill.
        conical_gradient = 5,
        /// @brief Specifies a radial gradient fill.
        radial_gradient = 6,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::pen_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::pen_type> {{xtd::drawing::drawing_2d::pen_type::solid_color, "solid_color"}, {xtd::drawing::drawing_2d::pen_type::hatch_fill, "hatch_fill"}, {xtd::drawing::drawing_2d::pen_type::texture_fill, "texture_fill"}, {xtd::drawing::drawing_2d::pen_type::path_gradient, "path_gradient"}, {xtd::drawing::drawing_2d::pen_type::linear_gradient, "linear_gradient"}, {xtd::drawing::drawing_2d::pen_type::conical_gradient, "conical_gradient"}, {xtd::drawing::drawing_2d::pen_type::radial_gradient, "radial_gradient"}};}
};
/// @endcond
