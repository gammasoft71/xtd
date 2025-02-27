/// @file
/// @brief Contains xtd::drawing::imaging::effects::posterize_effect class.
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
        /// @brief Represents the base class for all effects.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                      |
        /// | -------------------- | ------------------------------ |
        /// | @image html ball.png | @image html ball_posterize.png |
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::effects::posterize_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, posterize_effect {2});
        /// result.save("ball_posterize.png");
        /// ```
        struct posterize_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::posterize_effect object.
          posterize_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::posterize_effect object with specified levels.
          /// @param levels The levels value (from 1 to 256).
          /// @remarks If the level is equal to or greater than 256, the result is identical to the original image.
          /// @remarks If the level is equal to or less than 1, the image is black.
          explicit posterize_effect(int32 levels);
          /// @}

          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets the levels value (from 1 to 256).
          /// @param levels The levels value (from 1 to 256).
          /// @remarks If the level is equal to or greater than 256, the result is identical to the original image.
          /// @remarks If the level is equal to or less than 1, the image is black.
          int32 levels = 256;
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
