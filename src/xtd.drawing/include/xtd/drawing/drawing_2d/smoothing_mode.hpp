/// @file
/// @brief Contains xtd::drawing::drawing_2d::smoothing_mode enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Specifies whether smoothing (antialiasing) is applied to lines and curves and the edges of filled areas.
      /// @par Namespace
      /// xtd::drawing::drawing_2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks Dxtd::drawing::drawing_2d::smoothing_mode::dfault_value, xtd::drawing::drawing_2d::smoothing_mode::none, and xtd::drawing::drawing_2d::smoothing_mode::xtd::drawing::drawing_2d::smoothing_mode::high_speed are equivalent and specify rendering without smoothing applied.
      /// @remarks xtd::drawing::drawing_2d::smoothing_mode::anti_alias and xtd::drawing::drawing_2d::smoothing_mode::high_quality are equivalent and specify rendering with smoothing applied.
      /// @note When the xtd::drawing::graphics::smoothing_mode property is specified by using the xtd::drawing::drawing_2d::smoothing_mode enumeration, it does not affect text. To set the text rendering quality, use the xtd::drawing::graphics::text_rendering_hint property and the xtd::drawing::drawing_2d::text_rendering_hint enumeration.
      /// @note When the xtd::drawing::graphics::smoothing_mode property is specified by using the xtd::drawing::drawing_2d::smoothing_mode enumeration, it does not affect areas filled by a path gradient brush. Areas filled by using a xtd::drawing::drawing_2d::path_gradient_brush object are rendered the same way (aliased) regardless of the setting for the xtd::drawing::graphics::smoothing_mode property.
      enum class smoothing_mode {
        /// @brief Specifies an invalid mode.
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
        anti_alias = 4,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::smoothing_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::smoothing_mode> {{xtd::drawing::drawing_2d::smoothing_mode::invalid, "invalid"}, {xtd::drawing::drawing_2d::smoothing_mode::default_value, "default_value"}, {xtd::drawing::drawing_2d::smoothing_mode::high_speed, "high_speed"}, {xtd::drawing::drawing_2d::smoothing_mode::high_quality, "high_quality"}, {xtd::drawing::drawing_2d::smoothing_mode::none, "none"}, {xtd::drawing::drawing_2d::smoothing_mode::anti_alias, "anti_alias"}};}
};
/// @endcond
