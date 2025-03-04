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
      /// @ingroup xtd_drawing
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
        /// @}
      };
    }
  }
}
