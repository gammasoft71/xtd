/// @file
/// @brief Contains xtd::drawing::drawing2d::interpolation_mode enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief The xtd::drawing::drawing2d::interpolation_mode enumeration specifies the algorithm that is used when images are scaled or rotated.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class interpolation_mode {
        /// @brief Equivalent to the xtd::drawing::drawing2d::quality_mode::invalid element of the xtd::drawing::drawing2d::quality_mode enumeration.
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
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, interpolation_mode value) {return os << to_string(value, {{interpolation_mode::invalid, "invalid"}, {interpolation_mode::default_value, "default_value"}, {interpolation_mode::low, "low"}, {interpolation_mode::hight, "hight"}, {interpolation_mode::bilinear, "bilinear"}, {interpolation_mode::bicubic, "bicubic"}, {interpolation_mode::nearest_neighbor, "nearest_neighbor"}, {interpolation_mode::high_quality_bilinear, "high_quality_bilinear"}, {interpolation_mode::high_quality_bicubic, "high_quality_bicubic"}});}
      inline std::wostream& operator<<(std::wostream& os, interpolation_mode value) {return os << to_string(value, {{interpolation_mode::invalid, L"invalid"}, {interpolation_mode::default_value, L"default_value"}, {interpolation_mode::low, L"low"}, {interpolation_mode::hight, L"hight"}, {interpolation_mode::bilinear, L"bilinear"}, {interpolation_mode::bicubic, L"bicubic"}, {interpolation_mode::nearest_neighbor, L"nearest_neighbor"}, {interpolation_mode::high_quality_bilinear, L"high_quality_bilinear"}, {interpolation_mode::high_quality_bicubic, L"high_quality_bicubic"}});}
      /// @endcond
    }
  }
}
