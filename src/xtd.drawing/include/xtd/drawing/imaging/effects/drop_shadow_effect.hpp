/// @file
/// @brief Contains xtd::drawing::imaging::effects::drop_shadow_effect struct.
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
        /// @brief The xtd::drawing::imaging::effects::drop_shadow_effect add a vertical and/or horizontal shadow to the image.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                        |
        /// | -------------------- | -------------------------------- |
        /// | @image html ball.png | @image html ball_drop_shadow.png |
        /// @par Examples
        /// The following example code shows how tu use xtd::drawing::imaging::effects::drop_shadow_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, drop_shadow_effect {drawing::size {16, 16}, 8, color::black});
        /// result.save("ball_drop_shadow.png");
        /// ```
        struct drop_shadow_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::drop_shadow_effect object.
          drop_shadow_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::drop_shadow_effect with horizontal and vertical shadow.
          /// @param shadow The horizontal and vertical shadow.
          explicit drop_shadow_effect(const xtd::drawing::size& shadow);
          /// @brief Initialise the new instance of xtd::drawing::imaging::drop_shadow_effect with horizontal and vertical shadow, and blur radius.
          /// @param shadow The horizontal and vertical shadow.
          /// @param blur The shadow blur radius.
          drop_shadow_effect(const xtd::drawing::size& shadow, int32 blur);
          /// @brief Initialise the new instance of xtd::drawing::imaging::drop_shadow_effect with horizontal and vertical shadow, blur radius, and shadow color.
          /// @param shadow The horizontal and vertical shadow.
          /// @param blur The shadow blur radius.
          /// @param color The shadow color.
          drop_shadow_effect(const xtd::drawing::size& shadow, int32 blur, const xtd::drawing::color& color);
          /// @}

          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets the shadow blur radius.
          /// @param blur The shadow blur radius.
          int32 blur = 0;
          /// @brief Gets or sets the shadow color.
          /// @param color The shadow color.
          xtd::drawing::color color = xtd::drawing::color::black;
          /// @brief Gets or sets the horizontal and vertical shadow.
          /// @param size The horizontal and vertical shadow.
          xtd::drawing::size shadow;
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
