/// @file
/// @brief Contains xtd::drawing::drawing2d::compositing_quality enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies the quality level to use during compositing.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks Compositing is done during rendering when the source pixels are combined with the destination pixels to produce the resultant pixels. The quality of compositing directly relates to the visual quality of the output and is inversely proportional to the render time. The higher the quality, the slower the render time. This is because the higher the quality level, the more surrounding pixels need to be taken into account during the composite. The linear quality setting (AssumeLinear) compromises by providing better quality than the default quality at a slightly lower speed.
      enum class compositing_quality {
        /// @brief Invalid quality.
        invalid = -1,
        /// @brief Default quality.
        default_value = 0,
        /// @brief High speed, low quality.
        high_speed = 1,
        /// @brief High quality, low speed compositing.
        high_quality = 2,
        /// @brief Gamma correction is used.
        gamma_corrected = 3,
        /// @brief Assume linear values.
        assume_linear = 4,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, compositing_quality value) {return os << to_string(value, {{compositing_quality::invalid, "invalid"}, {compositing_quality::default_value, "default_value"}, {compositing_quality::high_speed, "high_speed"}, {compositing_quality::high_quality, "high_quality"}, {compositing_quality::gamma_corrected, "gamma_corrected"}, {compositing_quality::assume_linear, "assume_linear"}});}
      inline std::wostream& operator<<(std::wostream& os, compositing_quality value) {return os << to_string(value, {{compositing_quality::invalid, L"invalid"}, {compositing_quality::default_value, L"default_value"}, {compositing_quality::high_speed, L"high_speed"}, {compositing_quality::high_quality, L"high_quality"}, {compositing_quality::gamma_corrected, L"gamma_corrected"}, {compositing_quality::assume_linear, L"assume_linear"}});}
      /// @endcond
    }
  }
}
