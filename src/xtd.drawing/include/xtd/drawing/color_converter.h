/// @file
/// @brief Contains xtd::drawing::color class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "color.h"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Transforme colors to and from xtd::drawing::color class. This class cannot be inherited.
    /// @code
    /// class drawing_export_ color_converter final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::image_converter
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ color_converter final static_ {
    public:
      /// @brief Returns the weighted average color between the two given colors.
      /// @param fore_core The foreground color.
      /// @param back_color The background color.
      /// @param alpha The alpha factor
      /// @return The combined color.
      /// @remarks The alpha of color1 is conserved.
      /// @remarks The red, green and blue values are averages using the following formula:
      /// @code
      /// color = fore_core * (1 - weight) + back_color * weight;
      /// @endcode
      /// @remarks Thus, a weight value of `1.0` will return the background color, while a value of `0.0` will return the foreground color.
      static xtd::drawing::color alpha_blend(const xtd::drawing::color& fore_core, const xtd::drawing::color& back_color, double alpha) noexcept;
      
      /// @brief Returns the weighted average color between the two given colors.
      /// @param color1 The first color.
      /// @param color2 The second color.
      /// @param weight The weighting factor
      /// @return The average color.
      /// @remarks The alpha of color1 is conserved.
      /// @remarks The red, green and blue values are averages using the following formula:
      /// @code
      /// color = color1 * (1 - weight) + color2 * weight;
      /// @endcode
      /// @remarks Thus, a weight value of `1.0` will return the second color, while a value of `0.0` will return the first color.
      static xtd::drawing::color average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, double weight) noexcept;
      /// @brief Returns the weighted average color between the two given colors.
      /// @param color1 The first color.
      /// @param color2 The second color.
      /// @param weight The weighting factor
      /// @param average_alpha if true alpha was compute to; otherwise the alpha result is the alpha of color1
      /// @return The average color.
      /// @remarks The alpha, red, green and blue values are averages using the following formula:
      /// @code
      /// color = color1 * (1 - weight) + color2 * weight;
      /// @endcode
      /// @remarks Thus, a weight value of 1.0 will return the first color, while a value of 0.0 will return the second color.
      static xtd::drawing::color average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, double weight, bool average_alpha) noexcept;

      /// @brief Creates a new lower or upper color of the specified color with specified threshold, upper color, and lower color.
      /// @param color The color to threshold.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param upper_color The color used when RGB color is upper the threshold value.
      /// @param lower_color The color used when RGB color is under or equal the threshold value.
      /// @return The new color.
      static xtd::drawing::color bi_tonal(const drawing::color& color, int32 threshold, const drawing::color& upper_color, const drawing::color& lower_color) noexcept;

      /// @brief Creates a new color with brightness changed of the specified color with specified percent.
      /// @param color The color to brightness.
      /// @param percent The percent factor in % (from 0.0 to 2.0).
      /// @return The new color.
      /// @remarks 0.0` will make the color completely black. `1.0` is default and represents the original color. Values over `1.0` will provide brighter results.
      static xtd::drawing::color brightness(const xtd::drawing::color& color, double percent) noexcept;
      
      /// @brief Creates a new contrasting color of the specified color with specified percent factor.
      /// @param color The color to change contrast.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The new color.
      /// @remarks Thus, `1.0` returns the original color, while the other values give a contrasting color.
      static xtd::drawing::color contrast(const xtd::drawing::color& color, double percent) noexcept;
      
      /// @brief Creates a new darker color of the specified color with 33% factor.
      /// @param color The color to dark.
      /// @return The new color.
      static xtd::drawing::color dark(const xtd::drawing::color& color) noexcept;
      /// @brief Creates a new darker color of the specified color with specified percent factor.
      /// @param color The color to dark.
      /// @param percent The darker factor in % (from 0.0 to 1.0).
      /// @return The new color.
      /// @remarks Thus, a percent value of `1.0` will return the xtd::drawing::color::black, while a value of `0.0` will return the color.
      static xtd::drawing::color dark(const xtd::drawing::color& color, double percent) noexcept;
      
      /// @brief Creates a new disabled color of the specified color with specified reference background color.
      /// @param fore_color The fore color to disabled.
      /// @param back_color The reference background color.
      /// @return The new color.
      static xtd::drawing::color disabled(const xtd::drawing::color& fore_color, const xtd::drawing::color& back_color) noexcept;
      /// @brief Creates a new disabled color of the specified color with specified brightness.
      /// @param fore_color The fore color to disabled.
      /// @param brightness The brightness of the reference backgroung color.
      /// @return The new color.
      static xtd::drawing::color disabled(const xtd::drawing::color& fore_color, float brightness) noexcept;
      
      /// @brief Creates a new gray color of the specified color.
      /// @param color The color to grayscale.
      /// @return The new color.
      static xtd::drawing::color grayscale(const xtd::drawing::color& color) noexcept;
      /// @brief Creates a new gray color of the specified color with specified percent factor.
      /// @param color The color to grayscale.
      /// @param percent The percent factor.
      /// @return The new color.
      /// @remarks Thus, `1.0` will make the color completely gray, while `0.0` return the original color.
      static xtd::drawing::color grayscale(const xtd::drawing::color& color, double percent) noexcept;
      
      /// @brief Creates a new color with rotated hue of the specified color with specified angle.
      /// @param color The color to rotate hue.
      /// @param angle The angle in degrees (form 0 to 360).
      /// @return The new color.
      static xtd::drawing::color hue_rotate(const xtd::drawing::color& color, int angle) noexcept;
      
      /// @brief Creates a new inverted color of the specified color.
      /// @param color The color to invert.
      /// @return The new color.
      static xtd::drawing::color invert(const xtd::drawing::color& color) noexcept;
      /// @brief Creates a new inverted color of the specified color with specified percent factor.
      /// @param color The color to invert.
      /// @return The new color.
      /// @remarks `0.0` will represents the original color. `1.0` will provide inverted color.
      static xtd::drawing::color invert(const xtd::drawing::color& color, double percent) noexcept;
      
      /// @brief Creates a new lighter color of the specified color with 33% factor.
      /// @param color The color to light.
      /// @return The new color.
      static xtd::drawing::color light(const xtd::drawing::color& color) noexcept;
      /// @brief Creates a new lighter color of the specified color with specified percent factor.
      /// @param color The color to light.
      /// @param percent The lighter factor in % (from 0.0 to 1.0).
      /// @return The new color.
      /// @remarks Thus, a percent value of `1.0` will return the xtd::drawing::color::black, while a value of `0.0` will return the color.
      static xtd::drawing::color light(const xtd::drawing::color& color, double percent) noexcept;

      /// @brief Creates a new color with saturation changed of the specified color.
      /// @param color The color to saturate.
      /// @param percent The saturatiob factor in %
      /// @return The new result.
      /// @remarks Thus, `1.0` return the original color. while other will make a saturate color.
      static xtd::drawing::color saturate(const xtd::drawing::color& color, double percent) noexcept;
      
      /// @brief Creates a new sepia color of the specified color.
      /// @param color The color to sepia.
      /// @return The new color.
      static xtd::drawing::color sepia(const xtd::drawing::color& color) noexcept;
      /// @brief Creates a new sepia color of the specified color with specified percent factor.
      /// @param color The color to sepia.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The new color.
      /// @remarks Thus, `1.0` will make the color completely sepia, while `0.0` return the original color.
      static xtd::drawing::color sepia(const xtd::drawing::color& color, double percent) noexcept;

      /// @brief Creates a new black or white color of the specified color with specified threshold.
      /// @param color The color to threshold.
      /// @param threshold The threshold value (from 0 to 765).
      /// @return The new color.
      static xtd::drawing::color threshold(const xtd::drawing::color& color, int32 threshold) noexcept;
    };
  }
}
