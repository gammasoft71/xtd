/// @file
/// @brief Contains xtd::drawing::scale_type enum class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the type of algorithm used for image scaling.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    enum class scale_type {
      /// @brief Specifies the default image scaling.
      /// @remarks When the image size is increased, the xtd::drawing::scale_type::bicubic algorithm is used. When the image size is decreased, the algorhme xtd::drawing::scale_type::box_average is used.
      default_scaling = 0,
      /// @brief Specifies the simplest and fastest algorithm.
      nearest = 1,
      /// @brief Specifies the algorithm that is a compromise between xtd::drawing::scale_type::nearest and xtd::drawing::scale_type::bicubic.
      bilinear = 2,
      /// @brief Specifies the algorithm of the highest quality but with the slowest execution time.
      /// @remarks This method is generally used to increase the size of an image.
      bicubic = 3,
      /// @brief Specifies the algorithm that uses the surrounding pixels to calculate an average that will be used for the new pixels.
      /// @remarks This method is generally used to reduce the size of an image.
      box_average = 4,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::scale_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::scale_type> {{xtd::drawing::scale_type::default_scaling, "default_scaling"}, {xtd::drawing::scale_type::nearest, "nearest"}, {xtd::drawing::scale_type::bilinear, "bilinear"}, {xtd::drawing::scale_type::bicubic, "bicubic"}, {xtd::drawing::scale_type::box_average, "box_average"}};}
};
/// @endcond
