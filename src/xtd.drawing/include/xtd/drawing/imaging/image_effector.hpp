/// @file
/// @brief Contains xtd::drawing::imaging::image_effector  class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static>
#include "effects/effect.hpp"
#include "../image.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief The xtd::drawing::imaging::image_effector allows effects defined in the xtd::drawing::imaging::effects namespace to be applied to both xtd::drawing::image and xtd::drawing::graphics via overloaded xtd::drawing::imaging::image_effector::set_effect methods. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing effects
      /// @par Examples
      /// The following code shows how to use xtd::drawing::imaging::image_effector, and all effect inherited from xtd::drawing::imaging::effects::effect.
      /// [image_converter](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/drawing/image_converter/README.md)
      class image_effector static_ {
      public:
        /// @name Public Static Methods
        
        /// @{
        /// @brief Sets the specified effects to the specifid image.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param effect The effect to apply.
        /// @return The resulting image.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, and effect.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, blur_effect {10});
        /// result.save("ball_blur.png");
        /// ```
        static xtd::drawing::image set_effect(const xtd::drawing::image& image, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param width Width of the bounding rectangle to with apply effect.
        /// @param height Height of the bounding rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @return The resulting image.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, x, y width, height, and effect.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, 50, 50, 200, 200, blur_effect {10});
        /// result.save("ball_blur.png");
        /// ```
        static xtd::drawing::image set_effect(const xtd::drawing::image& image, int32 x, int32 y, int32 width, int32 height, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param width Width of the bounding rectangle to with apply effect.
        /// @param height Height of the bounding rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @return The resulting image.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, x, y width, height, and effect.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// auto result = image_effector::set_effect(img, 50.0f, 50.0f, 200.0f, 200.0f, blur_effect {10});
        /// result.save("ball_blur.png");
        /// ```
        static xtd::drawing::image set_effect(const xtd::drawing::image& image, float x, float y, float width, float height, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @return The resulting image.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, rectangle, and effect.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// const auto rect = rectangle {50, 50, 200, 200};
        /// auto result = image_effector::set_effect(img, rect, blur_effect {10});
        /// result.save("ball_blur.png");
        /// ```
        static xtd::drawing::image set_effect(const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @return The resulting image.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, rectangle, and effect.
        /// ```cpp
        /// const auto img = image::from_file("ball.png");
        /// const auto rect = rectangle_f {50.0f, 50.0f, 200.0f, 200.0f};
        /// auto result = image_effector::set_effect(img, rect, blur_effect {10});
        /// result.save("ball_blur.png");
        /// ```
        static xtd::drawing::image set_effect(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, and effect.
        /// ```cpp
        /// auto img = image::from_file("ball.png");
        /// image_effector::set_effect(img, blur_effect {10});
        /// image.save("ball_blur.png");
        /// ```
        static void set_effect(xtd::drawing::image& image, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param width Width of the bounding rectangle to with apply effect.
        /// @param height Height of the bounding rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, x, y, width, height, and effect.
        /// ```cpp
        /// auto img = image::from_file("ball.png");
        /// image_effector::set_effect(img, 50, 50, 200, 200, blur_effect {10});
        /// image.save("ball_blur.png");
        /// ```
        static void set_effect(xtd::drawing::image& image, int32 x, int32 y, int32 width, int32 height, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param width Width of the bounding rectangle to with apply effect.
        /// @param height Height of the bounding rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, x, y, width, height, and effect.
        /// ```cpp
        /// auto img = image::from_file("ball.png");
        /// image_effector::set_effect(img, 50.0f, 50.0f, 200.0f, 200.0f, blur_effect {10});
        /// image.save("ball_blur.png");
        /// ```
        static void set_effect(xtd::drawing::image& image, float x, float y, float width, float height, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, rectangle, and effect.
        /// ```cpp
        /// auto img = image::from_file("ball.png");
        /// const auto rect = rectangle {50, 50, 200, 200};
        /// image_effector::set_effect(img, rect, blur_effect {10});
        /// image.save("ball_blur.png");
        /// ```
        static void set_effect(xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with image, rectangle, and effect.
        /// ```cpp
        /// auto img = image::from_file("ball.png");
        /// const auto rect = rectangle_f {50.0f, 50.0f, 200.0f, 200.0f};
        /// image_effector::set_effect(img, rect, blur_effect {10});
        /// image.save("ball_blur.png");
        /// ```
        static void set_effect(xtd::drawing::image& image, const xtd::drawing::rectangle_f& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid graphics.
        /// @param image The xtd::drawing::graphics to which to apply the effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with graphics, and effect.
        /// ```cpp
        /// void owner_control::set_blur_effect(graphics& g) {
        ///   image_effector::set_effect(g, blur_effect {10});
        /// }
        /// ```
        static void set_effect(xtd::drawing::graphics& graphics, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid graphics with rectangle.
        /// @param image The xtd::drawing::graphics to which to apply the effect.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param width Width of the bounding rectangle to with apply effect.
        /// @param height Height of the bounding rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with graphics, rectangle, and effect.
        /// ```cpp
        /// void owner_control::on_paint(xtd::forms::paint_event_args& e) override {
        ///   // ...
        ///   image_effector::set_effect(e.graphics(), 50, 50, 200, 200, blur_effect {10});
        /// }
        /// ```
        static void set_effect(xtd::drawing::graphics& graphics, int32 x, int32 y, int32 width, int32 height, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid graphics with rectangle.
        /// @param image The xtd::drawing::graphics to which to apply the effect.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle to with apply effect.
        /// @param width Width of the bounding rectangle to with apply effect.
        /// @param height Height of the bounding rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with graphics, rectangle, and effect.
        /// ```cpp
        /// void owner_control::on_paint(xtd::forms::paint_event_args& e) override {
        ///   // ...
        ///   image_effector::set_effect(e.graphics(), 50.0f, 50.0f, 200.0f, 200.0f, blur_effect {10});
        /// }
        /// ```
        static void set_effect(xtd::drawing::graphics& graphics, float x, float y, float width, float height, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid graphics with rectangle.
        /// @param image The xtd::drawing::graphics to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with graphics, rectangle, and effect.
        /// ```cpp
        /// void owner_control::on_paint(xtd::forms::paint_event_args& e) override {
        ///   // ...
        ///   image_effector::set_effect(e.graphics(), e.clip_rectangle(), blur_effect {10});
        /// }
        /// ```
        static void set_effect(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid graphics with rectangle.
        /// @param image The xtd::drawing::graphics to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @par Examples
        /// The following example code shows hot tu use xtd::drawing::imaging::image_effector::set_effect with graphics, rectangle, and effect.
        /// ```cpp
        /// void owner_control::on_paint(xtd::forms::paint_event_args& e) override {
        ///   // ...
        ///   const auto rect = rectangle_f {50.0f, 50.0f, 200.0f, 200.0f};
        ///   image_effector::set_effect(e.graphics(), rect, blur_effect {10});
        /// }
        /// ```
        static void set_effect(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle_f& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @}
      };
    }
  }
}
