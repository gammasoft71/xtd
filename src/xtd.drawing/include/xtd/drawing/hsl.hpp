/// @file
/// @brief Contains xtd::drawing::hsl struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>
#include <xtd/string>
#include <xtd/uint32>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The hsl struct.
    /// ```cpp
    /// struct hsl;
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    struct hsl {
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the hue component value of this xtd::drawing::hsl struct.
      /// @param a byte The hue component value of this xtd::drawing::hsl.
      xtd::single hue = .0f;
      /// @brief Gets or sets the saturation component value of this xtd::drawing::hsl struct.
      /// @param r byte The saturation component value of this xtd::drawing::hsl.
      xtd::single saturation = .0f;
      /// @brief Gets or sets the lightness component value of this xtd::drawing::hsl struct.
      /// @param r byte The lightness component value of this xtd::drawing::hsl.
      xtd::single lightness = .0f;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a xtd::hsl struct from the specified hue, saturation, and lightness single values.
      /// @param hue The a single value.
      /// @param saturation The r single value.
      /// @param lightness The g single value.
      /// @return an xtd::drawing::hsl value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_hsl(xtd::single hue, xtd::single saturation, xtd::single lightness) noexcept -> xtd::drawing::hsl {
        return hsl {.hue = hue, .saturation = saturation, .lightness = lightness};
      }
      /// @brief Creates a xtd::hsl struct from the specified axtd::drawing::hsl value.
      /// @param value The hsl value.
      /// @return an xtd::drawing::hsl value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_hsl(const hsl& value) noexcept -> xtd::drawing::hsl {
        return value;
      }
      /// @}
      
      /// @cond
      friend auto operator <<(std::ostream& os, const hsl& value) -> std::ostream& {
        return os << xtd::string::format("hsl [hue = {}, saturation = {}, lightness = {}]", value.hue, value.saturation, value.lightness);
      };
      /// @endcond
    };
  }
}
