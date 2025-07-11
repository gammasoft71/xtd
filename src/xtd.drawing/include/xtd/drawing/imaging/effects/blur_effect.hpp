/// @file
/// @brief Contains xtd::drawing::imaging::effects::blur_effect struct.
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
        /// @brief The xtd::drawing::imaging::effects::blur_effect blurs the image with radius.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                 |
        /// | -------------------- | ------------------------- |
        /// | @image html ball.png | @image html ball_blur.png |
        /// @par Examples
        /// The following example code shows how tu use xtd::drawing::imaging::effects::blur_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, blur_effect {10});
        /// result.save("ball_blur.png");
        /// ```
        struct blur_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::blur_effect object.
          blur_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::blur_effect object with specified horizontal and vertical radius.
          /// @param radius The radius of the blur in pixels.
          explicit blur_effect(int32 radius);
          /// @brief Initialise the new instance of xtd::drawing::imaging::blur_effect object with specified horizontal and vertical radius, and expand edge boolean.
          /// @param radius The radius of the blur in pixels.
          /// @param expand_edge `true` if the bitmap expands by an amount equal to the radius so that it can have soft edges. `false` if the bitmap remains the same size and the soft edges are clipped.
          blur_effect(int32 radius, bool expand_edge);
          /// @brief Initialise the new instance of xtd::drawing::imaging::blur_effect object with specified horizontal and vertical radius.
          /// @param horizontal_radius The horizontal radius of the blur in pixels.
          /// @param vertical_radius The vertical radius of the blur in pixels.
          blur_effect(int32 horizontal_radius, int32 vertical_radius);
          /// @brief Initialise the new instance of xtd::drawing::imaging::blur_effect object with specified horizontal and vertical radius, and expand edge boolean.
          /// @param horizontal_radius The horizontal radius of the blur in pixels.
          /// @param vertical_radius The vertical radius of the blur in pixels.
          /// @param expand_edge `true` if the bitmap expands by an amount equal to the radius so that it can have soft edges. `false` if the bitmap remains the same size and the soft edges are clipped.
          blur_effect(int32 horizontal_radius, int32 vertical_radius, bool expand_edge);
          /// @}
          
          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets a value that indicates whether the bitmap expands by an amount equal to the blur radius.
          /// @param expand_edge `true` if the bitmap expands by an amount equal to the radius so that it can have soft edges. `false` if the bitmap remains the same size and the soft edges are clipped.
          bool expand_edge = false;
          
          /// @brief Gets or sets the horizontal radius value.
          /// @param horizontal_radius The horizontal radius of the blur in pixels.
          /// @remarks If the `horizontal_radius` is `0`, there will be no horizontal blurring.
          int32 horizontal_radius = 0;
          
          /// @brief Gets or sets the vertical radius value.
          /// @param vertical_radius The vertical radius of the blur in pixels.
          /// @remarks If the `vertical_radius` is `0`, there will be no vertical blurring.
          int32 vertical_radius = 0;
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
