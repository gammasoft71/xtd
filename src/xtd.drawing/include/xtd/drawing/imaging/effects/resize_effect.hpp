/// @file
/// @brief Contains xtd::drawing::imaging::effects::resize_effect struct.
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
        /// @brief The xtd::drawing::imaging::effects::resize_effect resizes the image with new rectangle and optionnaly fill color.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Appearance
        /// | Original             | Converted                   |
        /// | -------------------- | --------------------------- |
        /// | @image html ball.png | @image html ball_resize.png |
        /// @par Examples
        /// The following example code shows how tu use xtd::drawing::imaging::effects::resize_effect with image.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, resize_effect {drawing::size {240, 240}});
        /// result.save("ball_resize.png");
        /// ```
        struct resize_effect : effect {
          /// @name Public Constructors
          
          /// @{
          /// @brief Initialise the new instance of xtd::drawing::imaging::resize_effect object.
          resize_effect() = default;
          /// @brief Initialise the new instance of xtd::drawing::imaging::resize with rectangle.
          /// @param size The new rectangle.
          explicit resize_effect(const xtd::drawing::rectangle& rectangle);
          /// @brief Initialise the new instance of xtd::drawing::imaging::resize with rectangle and auto determine fill color boolean.
          /// @param size The new rectangle.
          /// @param auto_determine_fill_color The auto fill color.
          /// @remarks The `auto_determine_fill_color` boolean is used to determina automatically de best color to fill borders when resizing is greater than the original size.
          resize_effect(const xtd::drawing::rectangle& rectangle, bool auto_determine_fill_color);
          /// @brief Initialise the new instance of xtd::drawing::imaging::resize with rectangle and fill color.
          /// @param size The new rectangle.
          /// @param fill_color The fill color. The default value is xtd::drawing::color::transparent.
          /// @remarks The `fill_color` color is used to fill borders when resizing is greater than the original size.
          resize_effect(const xtd::drawing::rectangle& rectangle, const xtd::drawing::color& fill_color);
          /// @brief Initialise the new instance of xtd::drawing::imaging::resize_effect with size.
          /// @param size The new size.
          /// @remarks The poition is esual to xtd::drawing::point {0, 0}.
          explicit resize_effect(const xtd::drawing::size& size);
          /// @brief Initialise the new instance of xtd::drawing::imaging::resize_effect with size and auto determine fill color boolean.
          /// @param size The new size.
          /// @param auto_determine_fill_color The auto fill color.
          /// @remarks The poition is esual to xtd::drawing::point {0, 0}.
          /// @remarks The `auto_determine_fill_color` boolean is used to determina automatically de best color to fill borders when resizing is greater than the original size.
          resize_effect(const xtd::drawing::size& size, bool auto_determine_fill_color);
          /// @brief Initialise the new instance of xtd::drawing::imaging::resize_effect resize with size and fill color.
          /// @param size The new size.
          /// @param fill_color The fill color. The default value is xtd::drawing::color::transparent.
          /// @remarks The poition is esual to xtd::drawing::point {0, 0}.
          /// @remarks The `fill_color` color is used to fill borders when resizing is greater than the original size.
          resize_effect(const xtd::drawing::size& size, const xtd::drawing::color& fill_color);
          /// @}

          /// @name Public Properties
          
          /// @{
          /// @brief Gets or sets the fill color.
          /// @param auto_determine_fill_color The auto fill color. The default value is `false`.
          /// @remarks The `auto_determine_fill_color` boolean is used to determina automatically de best color to fill borders when resizing is greater than the original size.
          /// @remarks The 'fill_color' has no effect if `auto_determine_fill_color` is set to `true'.
          bool auto_determine_fill_color = false;

          /// @brief Gets or sets the fill color.
          /// @param fill_color The fill color. The default value is xtd::drawing::color::transparent.
          /// @remarks The `fill_color` color is used to fill borders when resizing is greater than the original size.
          /// @remarks The 'fill_color' has no effect if `auto_determine_fill_color` is set to `true'.
          xtd::drawing::color fill_color = xtd::drawing::color::transparent;

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
