/// @file
/// @brief Contains xtd::drawing::helpers::rgb struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>
#include <xtd/math>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::helpers namespace contains helpers for xtd::drawing objects, sush as rgb, rbg structs
    namespace helpers {
      /// @brief The rgb struct.
      /// ```cpp
      /// struct rgb;
      /// ```
      /// @par Namespace
      /// xtd::drawing::helpers
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing_helpers
      struct rgb {
        /// @name Public Properties
        
        /// @{
        /// @brief Gets or sets the red component value of this xtd::drawing::helpers::rgb struct.
        /// @param r byte The red component value of this xtd::drawing::helpers::rgb.
        xtd::byte r = 0;
        /// @brief Gets or sets the green component value of this xtd::drawing::helpers::rbg struct.
        /// @param r byte The green component value of this xtd::drawing::helpers::rgb.
        xtd::byte g = 0;
        /// @brief Gets or sets the blue component value of this xtd::drawing::helpers::rbg struct.
        /// @param r byte The blue component value of this xtd::drawing::helpers::rgb.
        xtd::byte b = 0;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Gets the hue-saturation-lightness (HSL) hue value, in degrees, for this xtd::drawing::helpers::rgb structure.
        /// @return The hue, in degrees, of this xtd::drawing::helpers::rgb. The hue is measured in degrees, ranging from 0.0 through 360.0, in HSL color space.
        float get_hue() const noexcept {
          if (r == g && g == b) return 0.0;
          
          auto rc = static_cast<float>(r) / 255.0f;
          auto gc = static_cast<float>(g) / 255.0f;
          auto bc = static_cast<float>(b) / 255.0f;
          
          auto max = static_cast<float>(xtd::math::max(xtd::math::max(rc, gc), bc));
          auto min = static_cast<float>(xtd::math::min(xtd::math::min(rc, gc), bc));
          
          auto delta = max - min;
          
          auto hue = 0.0f;
          if (rc == max) hue = (gc - bc) / delta;
          else if (gc == max) hue = 2 + (bc - rc) / delta;
          else if (bc == max) hue = 4 + (rc - gc) / delta;
          hue *= 60;
          
          if (hue < 0.0) hue += 360.0;
          return hue;
        }
        
        /// @brief Gets the hue-saturation-lightness (HSL) lightness value for this xtd::drawing::helpers::rgb structure.
        /// @return The lightness of this xtd::drawing::helpers::rgb. The lightness ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
        float get_lightness() const noexcept {
          return (static_cast<float>(xtd::math::max(xtd::math::max(r, g), b)) + static_cast<float>(xtd::math::min(xtd::math::min(r, g), b))) / 2.0f / 255.0f;
        }
        
        /// @brief Gets the hue-saturation-lightness (HSL) saturation value for this xtd::drawing::helpers::rgb structure.
        /// @return The saturation of this xtd::drawing::helpers::rgb. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
        float get_saturation() const noexcept {
          auto max = static_cast<float>(xtd::math::max(xtd::math::max(r, g), b)) / 255.0f;
          auto min = static_cast<float>(xtd::math::min(xtd::math::min(r, g), b)) / 255.0f;
          
          if (max == min) return 0.0f;
          
          return (max + min) <= 1.0f ? (max - min) / (max + min) : (max - min) / (2 - max - min);
        }
        
        std::tuple<float, float, float> to_hsl() const noexcept {
          return {get_hue(), get_saturation(), get_lightness()};
        }
        /// @}

        /// @name Public Static Methods
        
        /// @{
        /// @brief Returns the weighted average color between the two given colors.
        /// @param fore_core The foreground color.
        /// @param back_color The background color.
        /// @param alpha The alpha factor
        /// @return The combined color.
        /// @remarks The alpha of `fore_core` is conserved.
        /// @remarks The red, green and blue values are averages using the following formula:
        /// ```cpp
        /// color = fore_core * (1 - weight) + back_color * weight;
        /// ```
        /// @remarks Thus, a weight value of `1.0` will return the background color, while a value of `0.0` will return the foreground color.
        static rgb alpha_blend(const rgb& fore_componant, const rgb& back_componant, double alpha) noexcept {
          alpha = xtd::math::clamp(alpha, 0.0, 1.0);
          return rgb {
            .r = alpha_blend(fore_componant.r, back_componant.r, alpha),
            .g = alpha_blend(fore_componant.g, back_componant.g, alpha),
            .b = alpha_blend(fore_componant.b, back_componant.b, alpha),
          };
        }

        /// @brief Returns the weighted average color component between the two given color components.
        /// @param fore_core The foreground color component.
        /// @param back_color The background color component.
        /// @param alpha The alpha factor
        /// @return The combined color component.
        /// @remarks The alpha of `fore_core` is conserved.
        /// @remarks The red, green and blue values are averages using the following formula:
        /// ```cpp
        /// color = fore_componant * (1 - weight) + back_componant * weight;
        /// ```
        /// @remarks Thus, a weight value of `1.0` will return the background color, while a value of `0.0` will return the foreground color.
        static xtd::byte alpha_blend(xtd::byte fore_componant, xtd::byte back_componant, double alpha) noexcept {
          return static_cast<xtd::byte>(fore_componant * (1 - alpha) + back_componant * alpha);
        }
        
        /// @brief Creates a xtd::drawing::helpers::rgb strucg from the three HSL component (hue, saturation, and lightness) values.
        /// @param hue The xtd::drawing::helpers::rgb saturation. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
        /// @param saturation The xtd::drawing::helpers::rgb saturation. The saturation ranges from 0.0 through 1.0, where 0.0 is grayscale and 1.0 is the most saturated.
        /// @param lightness The xtd::drawing::helpers::rgb lightness. The lightness ranges from 0.0 through 1.0, where 0.0 represents black and 1.0 represents white.
        /// @return The xtd::drawing::helpers::rgb structure that this method creates.
        static rgb from_hsl(float hue, float saturation, float lightness) noexcept {
          // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsl-to-rgb)
          if (saturation == 0) return {static_cast<xtd::byte>(lightness * 255.0f), static_cast<xtd::byte>(lightness * 255.0f), static_cast<xtd::byte>(lightness * 255.0f)};
          
          auto hue_to_rgb = [](float v1, float v2, float vh)->float {
            if (vh < 0) vh += 1;
            if (vh > 1) vh -= 1;
            if ((6 * vh) < 1) return (v1 + (v2 - v1) * 6 * vh);
            if ((2 * vh) < 1) return v2;
            if ((3 * vh) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vh) * 6);
            return v1;
          };
          
          hue = hue / 360.0f;
          auto v2 = (lightness < 0.5f) ? (lightness * (1 + saturation)) : ((lightness + saturation) - (lightness * saturation));
          auto v1 = 2 * lightness - v2;
          
          return {static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue + (1.0f / 3)) * 255.0f), static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue) * 255.0f), static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue - (1.0f / 3)) * 255.0f)};
        }
        /// @}
      };
    }
  }
}
