/// @file
/// @brief Contains xtd::drawing::hsb struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>
#include <xtd/string>
#include <xtd/uint32>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The hsb struct.
    /// ```cpp
    /// struct hsb;
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    struct hsb {
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the hue component value of this xtd::drawing::hsb struct.
      /// @param a byte The hue component value of this xtd::drawing::hsb.
      xtd::single hue = .0f;
      /// @brief Gets or sets the saturation component value of this xtd::drawing::hsb struct.
      /// @param r byte The saturation component value of this xtd::drawing::hsb.
      xtd::single saturation = .0f;
      /// @brief Gets or sets the brightness component value of this xtd::drawing::hsb struct.
      /// @param r byte The brightness component value of this xtd::drawing::hsb.
      xtd::single brightness = .0f;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a xtd::hsb struct from the specified hue, saturation, and brightness single values.
      /// @param hue The a single value.
      /// @param saturation The r single value.
      /// @param brightness The g single value.
      /// @return an xtd::drawing::hsb value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_hsb(xtd::single hue, xtd::single saturation, xtd::single brightness) noexcept -> xtd::drawing::hsb {
        return hsb {.hue = hue, .saturation = saturation, .brightness = brightness};
      }
      /// @brief Creates a xtd::hsb struct from the specified axtd::drawing::hsb value.
      /// @param value The hsb value.
      /// @return an xtd::drawing::hsb value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_hsb(const hsb& value) noexcept -> xtd::drawing::hsb {
        return value;
      }
      /// @}
      
      /// @cond
      friend auto operator <<(std::ostream& os, const hsb& value) -> std::ostream& {
        return os << xtd::string::format("hsb [hue = {}, saturation = {}, brightness = {}]", value.hue, value.saturation, value.brightness);
      };
      /// @endcond
    };
  }
}
