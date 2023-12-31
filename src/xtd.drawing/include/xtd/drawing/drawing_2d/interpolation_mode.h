/// @file
/// @brief Contains xtd::drawing::drawing_2d::interpolation_mode enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "drawing2d.h"
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief The xtd::drawing::drawing_2d::interpolation_mode enumeration specifies the algorithm that is used when images are scaled or rotated.
      /// @par Namespace
      /// xtd::drawing::drawing_2d/
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class interpolation_mode {
        /// @brief Equivalent to the xtd::drawing::drawing_2d::quality_mode::invalid element of the xtd::drawing::drawing_2d::quality_mode enumeration.
        invalid = -1,
        /// @brief Specifies default mode.
        default_value = 0,
        /// @brief Specifies low quality interpolation.
        low = 1,
        /// @brief Specifies high quality interpolation.
        hight = 2,
        /// @brief Specifies bilinear interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 50 percent of its original size.
        bilinear = 3,
        /// @brief Specifies bicubic interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 25 percent of its original size.
        bicubic = 4,
        /// @brief Specifies nearest-neighbor interpolation.
        nearest_neighbor = 5,
        /// @brief Specifies high-quality, bilinear interpolation. Prefiltering is performed to ensure high-quality shrinking.
        high_quality_bilinear = 6,
        /// @brief Specifies high-quality, bicubic interpolation. Prefiltering is performed to ensure high-quality shrinking. This mode produces the highest quality transformed images.
        high_quality_bicubic = 7,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::interpolation_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::interpolation_mode> {{xtd::drawing::drawing_2d::interpolation_mode::invalid, "invalid"}, {xtd::drawing::drawing_2d::interpolation_mode::default_value, "default_value"}, {xtd::drawing::drawing_2d::interpolation_mode::low, "low"}, {xtd::drawing::drawing_2d::interpolation_mode::hight, "hight"}, {xtd::drawing::drawing_2d::interpolation_mode::bilinear, "bilinear"}, {xtd::drawing::drawing_2d::interpolation_mode::bicubic, "bicubic"}, {xtd::drawing::drawing_2d::interpolation_mode::nearest_neighbor, "nearest_neighbor"}, {xtd::drawing::drawing_2d::interpolation_mode::high_quality_bilinear, "high_quality_bilinear"}, {xtd::drawing::drawing_2d::interpolation_mode::high_quality_bicubic, "high_quality_bicubic"}};}
};
/// @endcond
