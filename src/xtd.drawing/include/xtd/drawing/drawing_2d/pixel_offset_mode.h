/// @file
/// @brief Contains xtd::drawing::drawing_2d::pixel_offset_mode enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Specifies how pixels are offset during rendering.
      /// @par Namespace
      /// xtd::drawing::drawing_2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @rremarks By offsetting pixels during rendering, you can improve render quality at the cost of render speed.
      enum class pixel_offset_mode {
        /// @brief Specifies the default mode.
        invalid = -1,
        /// @brief Specifies default mode.
        default_value = 0,
        /// @brief Specifies high speed, low quality rendering.
        high_speed = 1,
        /// @brief Specifies high quality, low speed rendering.
        high_quality = 2,
        /// @brief Specifies no pixel offset.
        none = 3,
        /// @brief Specifies that pixels are offset by -.5 units, both horizontally and vertically, for high speed antialiasing.
        half = 4,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::pixel_offset_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::pixel_offset_mode> {{xtd::drawing::drawing_2d::pixel_offset_mode::invalid, "invalid"}, {xtd::drawing::drawing_2d::pixel_offset_mode::default_value, "default_value"}, {xtd::drawing::drawing_2d::pixel_offset_mode::high_speed, "high_speed"}, {xtd::drawing::drawing_2d::pixel_offset_mode::high_quality, "high_quality"}, {xtd::drawing::drawing_2d::pixel_offset_mode::none, "none"}, {xtd::drawing::drawing_2d::pixel_offset_mode::half, "half"}};}
};
/// @endcond
