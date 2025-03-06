/// @file
/// @brief Contains xtd::drawing::imaging::effects::gamma_correction_effect struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "effect.hpp"
#include "../../color.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief The xtd::drawing::imaging::effects namespace provides functionality for adding effects to images.
      namespace effects {
        /// @brief The xtd::drawing::imaging::effects::gamma_correction_effect changes the gamma of the image with r, g, and b correction.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                             |
        /// | -------------------- | ------------------------------------- |
        /// | @image html ball.png | @image html ball_gamma_correction.png |
        /// @par Examples
        /// The following example code shows how tu use xtd::drawing::imaging::effects::gamma_correction_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, gamma_correction_effect {2.0, 1.6, 0.8});
        /// result.save("ball_gamma_correction.png");
        /// ```
        struct gamma_correction_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::gamma_correction_effect object.
          gamma_correction_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::gamma_correction_effect object with specified percent.
          /// @param r The red correction between `0.1` and `5.0`.
          /// @param g The green correction between `0.1` and `5.0`.
          /// @param b The blue correction between `0.1` and `5.0`.
          /// @ramrks The `1.0` values are default and represent the original color.
          gamma_correction_effect(double r, double g, double b);
          /// @}

          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets the red correction.
          /// @param r The red correction between `0.1` and `5.0`.
          /// @remarks The `1.0` value is default and represents the original red componant color.
          double r = 1.0;
          /// @brief Gets or sets the green correction.
          /// @param g The green correction between `0.1` and `5.0`.
          /// @remarks The `1.0` value is default and represents the original green componant color.
          double g = 1.0;
          /// @brief Gets or sets the blue correction.
          /// @param b The blue correction between `0.1` and `5.0`.
          /// @remarks The `1.0` value is default and represents the original blue componant color.
          double b = 1.0;
          /// @}

        protected:
          /// @name Protected Methods
          
          /// @{
          /// @brief Apply the effect.
          /// @param graphics The graphics to apply effect.
          /// @param image The image where the effect is applied.
          void apply(xtd::drawing::image& image) const override;
          /// @}
        };
      }
    }
  }
}
