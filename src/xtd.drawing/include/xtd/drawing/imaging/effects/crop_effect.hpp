/// @file
/// @brief Contains xtd::drawing::imaging::effects::crop_effect struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "effect.hpp"
#include "../../color.hpp"
#include "../../system_colors.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief The xtd::drawing::imaging::effects namespace provides functionality for adding effects to images.
      namespace effects {
        /// @brief The xtd::drawing::imaging::effects::crop_effect crops the image with new rectangle.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                 |
        /// | -------------------- | ------------------------- |
        /// | @image html ball.png | @image html ball_crop.png |
        /// @par Examples
        /// The following example code shows how tu use xtd::drawing::imaging::effects::crop_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, crop_effect {rectangle {25, 25, 240, 240}});
        /// result.save("ball_crop.png");
        /// ```
        /// @remarks The
        struct crop_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::crop_effect object.
          crop_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::crop_effect with specified rectangle.
          /// @param size The new rectangle.
          explicit crop_effect(const xtd::drawing::rectangle& rectangle);
          /// @brief Initialise the new instance of xtd::drawing::imaging::crop_effect with specified size.
          /// @param size The new size.
          /// @remarks The poition is esual to xtd::drawing::point {0, 0}.
          explicit crop_effect(const xtd::drawing::size& size);
          /// @}

          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets the new rectangle.
          /// @param size The new rectangle.
          xtd::drawing::rectangle rectangle;

          /// @brief Sets the new size.
          /// @param size The new size.
          void size(const xtd::drawing::size& value);
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
