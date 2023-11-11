/// @file
/// @brief Contains xtd::drawing::drawing_2d::line_join enum class.
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
      /// @brief Specifies how to join consecutive line or curve segments in a figure (subpath) contained in a xtd::drawing::drawing_2d::graphics_path object.
      /// @par Namespace
      /// xtd::drawing::drawing_2d/
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks Compositing is done during rendering when the source pixels are combined with the destination pixels to produce the resultant pixels. The quality of compositing directly relates to the visual quality of the output and is inversely proportional to the render time. The higher the quality, the slower the render time. This is because the higher the quality level, the more surrounding pixels need to be taken into account during the composite. The linear quality setting (AssumeLinear) compromises by providing better quality than the default quality at a slightly lower speed.
      enum class line_join {
        /// @brief Specifies a mitered join. This produces a sharp corner or a clipped corner, depending on whether the length of the miter exceeds the miter limit.
        miter = 0,
        /// @brief Specifies a beveled join. This produces a diagonal corner.
        bevel = 1,
        /// @brief Specifies a circular join. This produces a smooth, circular arc between the lines.
        round = 2,
        /// @brief Specifies a mitered join. This produces a sharp corner or a beveled corner, depending on whether the length of the miter exceeds the miter limit.
        miter_clipped = 3,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::line_join> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::line_join> {{xtd::drawing::drawing_2d::line_join::miter, "miter"}, {xtd::drawing::drawing_2d::line_join::bevel, "bevel"}, {xtd::drawing::drawing_2d::line_join::round, "round"}, {xtd::drawing::drawing_2d::line_join::miter_clipped, "miter_clipped"}};}
};
/// @endcond
