/// @file
/// @brief Contains xtd::drawing::imaging::effects::rotate_flip_effect struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "effect.hpp"
#include "../../color.hpp"
#include "../../rotate_flip_type.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief The xtd::drawing::imaging::effects namespace provides functionality for adding effects to images.
      namespace effects {
        /// @brief The xtd::drawing::imaging::effects::rotate_flip_effect Rotates, flips, or rotates and flips of the image with rotate flip type.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                        |
        /// | -------------------- | -------------------------------- |
        /// | @image html ball.png | @image html ball_rotate_flip.png |
        /// @par Examples
        /// The following example code shows how tu use xtd::drawing::imaging::effects::rotate_flip_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, rotate_flip_effect {rotate_flip_type::rotate_180_flip_x});
        /// result.save("ball_rotate_flip.png");
        /// ```
        struct rotate_flip_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::rotate_flip_effect object.
          rotate_flip_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::rotate_flip_effect object with specified percent.
          /// @param rotate_flip_type A xtd::drawing::rotate_flip_type member that specifies the type of rotation and flip to apply to the image.
          explicit rotate_flip_effect(xtd::drawing::rotate_flip_type rotate_flip_type);
          /// @}

          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets the rotatation and flip type.
          /// @param rotate_flip_type A xtd::drawing::rotate_flip_type member that specifies the type of rotation and flip to apply to the image.
          xtd::drawing::rotate_flip_type rotate_flip_type = xtd::drawing::rotate_flip_type::rotate_none_flip_none;
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
