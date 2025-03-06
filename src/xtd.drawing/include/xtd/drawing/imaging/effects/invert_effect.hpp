/// @file
/// @brief Contains xtd::drawing::imaging::effects::invert_effect struct.
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
        /// @brief The xtd::drawing::imaging::effects::invert_effect inverts the color of the image with percent factor.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                   |
        /// | -------------------- | --------------------------- |
        /// | @image html ball.png | @image html ball_invert.png |
        /// @par Examples
        /// The following example code shows how tu use xtd::drawing::imaging::effects::invert_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, invert_effect {1.0});
        /// result.save("ball_invert.png");
        /// ```
        struct invert_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::invert_effect object.
          invert_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::invert_effect object with specified percent.
          /// @param percent The percent factor in %.
          explicit invert_effect(double percent);
          /// @}

          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets the percent factor in %.
          /// @param percent The percent factor in %.
          /// @remarks `0.0` will represents the original image. `0.5`gray image. `1.0` will provide image with inverted colors.
          double percent = 0.0;
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
