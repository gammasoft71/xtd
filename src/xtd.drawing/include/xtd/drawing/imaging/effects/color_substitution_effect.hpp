/// @file
/// @brief Contains xtd::drawing::imaging::effects::color_substitution_effect struct.
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
        /// @brief The xtd::drawing::imaging::effects::color_substitution_effect replaces the source color with the new color.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                               |
        /// | -------------------- | --------------------------------------- |
        /// | @image html ball.png | @image html ball_color_substitution.png |
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::effects::color_substitution_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, color_substitution_effect {260, color::green, color::blue});
        /// result.save("ball_color_extraction.png");
        /// ```
        struct color_substitution_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::color_substitution_effect object.
          color_substitution_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::color_substitution_effect object with specified threshold, source color, and new color.
          /// @param threshold The threshold value (from 0 to 765).
          /// @param source_color The color used when RGB color is upper the threshold value.
          /// @param new_color The color used when RGB color is under or equal the threshold value.
          color_substitution_effect(int32 threshold, color source_color, color new_color);
          /// @}

          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets the threshold value (from 0 to 765).
          /// @param threshold The threshold value (from 0 to 765).
          /// @remarks The threshold is the sum of the RGB components.
          int32 threshold = 0;

          /// @brief Gets or sets the extraction color.
          /// @param source_color The extraction color.
          color source_color;

          /// @brief Gets or sets the other pixels color.
          /// @param new_color The other pixels color.
          color new_color;
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
