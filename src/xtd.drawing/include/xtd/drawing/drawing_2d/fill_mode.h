/// @file
/// @brief Contains xtd::drawing::drawing_2d/::fill_mode enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "drawing2d"
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Specifies how the interior of a closed path is filled.
      /// @par Namespace
      /// xtd::drawing
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks An application fills the interior of a path using one of two fill modes: alternate or winding. The mode determines how to fill and clip the interior of a closed figure.
      /// @remarks The default mode is xtd::drawing::drawin2d::fill_mode::alternate. To determine the interiors of closed figures in the alternate mode, draw a line from any arbitrary start point in the path to some point obviously outside the path. If the line crosses an odd number of path segments, the starting point is inside the closed region and is therefore part of the fill or clipping area. An even number of crossings means that the point is not in an area to be filled or clipped. An open figure is filled or clipped by using a line to connect the last point to the first point of the figure.
      /// @remarks The xtd::drawing::drawin2d::fill_mode::winding mode considers the direction of the path segments at each intersection. It adds one for every clockwise intersection, and subtracts one for every counterclockwise intersection. If the result is nonzero, the point is considered inside the fill or clip area. A zero count means that the point lies outside the fill or clip area.
      /// @remarks A figure is considered clockwise or counterclockwise based on the order in which the segments of the figure are drawn.
      enum class fill_mode {
        /// @brief Specifies the alternate fill mode.
        alternate,
        /// @brief Specifies the winding fill mode.
        winding,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::fill_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::fill_mode> {{xtd::drawing::drawing_2d::fill_mode::alternate, "alternate"}, {xtd::drawing::drawing_2d::fill_mode::winding, "winding"}};}
};
/// @endcond
