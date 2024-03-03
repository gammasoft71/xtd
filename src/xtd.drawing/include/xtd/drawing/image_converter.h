/// @file
/// @brief Contains xtd::drawing::image_converter class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "image.h"
#include "rotate_flip_type.h"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class bitmap;
    /// @endcond
    
    /// @brief Converts images to and from xtd::drawing::image class. This class cannot be inherited.
    /// @code
    /// class drawing_export_ image_converter final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::image_converter
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    class drawing_export_ image_converter final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Converts into lower and upper colors of the specified image with specified threshold, upper color and lower color.
      /// @param image The image to convert into lower and upper colors.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param upper_color The color used when RGB color is upper the threshold value.
      /// @param lower_color The color used when RGB color is under or equal the threshold value.
      static void bitonal(xtd::drawing::image& image, int32 threshold, const color& upper_color, const color& lower_color);
      /// @brief Creates a new lower and upper image of the specified image with specified threshold, upper color and lower color.
      /// @param image The image to convert into lower and upper colors.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param upper_color The color used when RGB color is upper the threshold value.
      /// @param lower_color The color used when RGB color is under or equal the threshold value.
      /// @return The converted image.
      static xtd::drawing::image bitonal(const xtd::drawing::image& image, int32 threshold, const color& upper_color, const color& lower_color);

      /// @brief Blur the specified image with the specified radius.
      /// @param image The image to blur.
      /// @param radius The radius of the blur in pixels.
      /// @remarks If the radius is `0`, there will be no blurring.
      static void blur(xtd::drawing::image& image, int32 radius);
      /// @brief Creates a new blurred image of the specified image with the specified radius.
      /// @param image The image to blur.
      /// @param radius The radius of the blur in pixels.
      /// @return The converted image.
      /// @remarks If the radius is `0`, there will be no blurring.
      static xtd::drawing::image blur(const xtd::drawing::image& image, int32 radius);

      /// @brief Change the brightness of the specified image with specified percent.
      /// @param image The image to brightness.
      /// @param percent The percent factor in %.
      /// @remarks `0.0` will make the image completely black. `1.0` is default and represents the original image. Values over `1.0` will provide brighter results.
      static void brightness(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with brightness changed of the specified image with specified percent.
      /// @param image The image to brightness.
      /// @param percent The percent factor in % (from 0.0 to 2.0).
      /// @return The converted image.
      /// @remarks `0.0` will make the image completely black. `1.0` is default and represents the original image. Values over `1.0` will provide brighter results.
      static xtd::drawing::image brightness(const xtd::drawing::image& image, double percent);
      
      /// @brief Add / remove the specified color from the specified image with the specified percent.
      /// @param image The image to update.
      /// @param color The color to add / remove.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      static void color(xtd::drawing::image& image, const xtd::drawing::color& color, double percent);
      /// @brief Create a new image with the specified color that will be added/removed from the specified image with the specified percent.
      /// @param image The image to update.
      /// @param color The color to add / remove.
      /// @param percent The percent factor in % (from 0.0 to 2.0).
      /// @return The converted image.
      static xtd::drawing::image color(const xtd::drawing::image& image, const xtd::drawing::color& color, double percent);

      /// @brief Filters image with specified color and replaces all other colors with other specified color.
      /// @param image The image to filter color.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param extraction_color The extraction color.
      /// @param other_pixels_color The other pixels color.
      /// @return The converted image.
      static void color_extraction(xtd::drawing::image& image, int32 threshold, const drawing::color& extraction_color, const xtd::drawing::color& other_pixels_color) noexcept;
      /// @brief Creates a new filtered image with specified color and replaces all other colors with other specified color.
      /// @param image The image to filter color.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param extraction_color The extraction color.
      /// @param other_pixels_color The other pixels color.
      /// @return The converted image.
      static xtd::drawing::image color_extraction(const xtd::drawing::image& image, int32 threshold, const drawing::color& extraction_color, const xtd::drawing::color& other_pixels_color) noexcept;

      /// @brief Change the contrast of the specified image with specified percent factor.
      /// @param image The image to change contrast.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks Thus, `1.0` returns the original image, while the other values give a contrasting image.
      static void contrast(xtd::drawing::image& image, double percent);
      /// @brief Creates a new contrasting image of the specified image with specified percent factor.
      /// @param image The image to change contrast.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks Thus, `1.0` returns the original image, while the other values give a contrasting image.
      static xtd::drawing::image contrast(const xtd::drawing::image& image, double percent);
      
      /// @brief Disable the specified image with specified reference background color.
      /// @param image The image to disble.
      /// @param back_color The reference background color.
      static void disabled(xtd::drawing::image& image, const xtd::drawing::color& back_color);
      /// @brief Creates a new disabled image of the specified image with specified reference background color.
      /// @param image The image to disble.
      /// @param back_color The reference background color.
      /// @return The converted image.
      static xtd::drawing::image disabled(const xtd::drawing::image& image, const xtd::drawing::color& back_color);
      /// @brief Disabled the specified image with specified brightness.
      /// @param image The image to dissable.
      /// @param brightness The brightness of the reference background color.
      static void disabled(xtd::drawing::image& image, float brightness);
      /// @brief Creates a new disabled image of the specified image with specified brightness.
      /// @param image The image to dissable.
      /// @param brightness The brightness of the reference background color.
      /// @return The converted image.
      static xtd::drawing::image disabled(const xtd::drawing::image& image, float brightness);

      /// @brief Converts into grayscale of the specified image.
      /// @param image The image to be transformed into grayscale.
      static void grayscale(xtd::drawing::image& image);
      /// @brief Creates a new image with grayscale colors of the specified image.
      /// @param image The image to be transformed into grayscale.
      /// @return The converted image.
      static xtd::drawing::image grayscale(const xtd::drawing::image& image);
      /// @brief Converts into grayscale of the specified image with specified percent factor.
      /// @param image The image to be transformed into grayscale.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks Thus, `1.0` will make the color completely gray, while `0.0` return the original image.
      static void grayscale(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with grayscale colors of the specified image with specified percent factor.
      /// @param image The image to be transformed into grayscale.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks Thus, `1.0` will make the color completely gray, while `0.0` return the original image.
      static xtd::drawing::image grayscale(const xtd::drawing::image& image, double percent);

      /// @brief Rotate hue colors of the specified image with specified angle.
      /// @param image The image to rotate hue colors.
      /// @param angle The angle in degrees (form 0 to 360).
      static void hue_rotate(xtd::drawing::image& image, int angle);
      /// @brief Creates a new image with rotated hue colors of the specified image with specified angle.
      /// @param image The image to rotate hue colors.
      /// @param angle The angle in degrees (form 0 to 360).
      /// @return The converted image.
      static xtd::drawing::image hue_rotate(const xtd::drawing::image& image, int angle);

      /// @brief Inverts colors of the specified image.
      /// @param image The image to invert colors.
      static void invert(xtd::drawing::image& image);
      /// @brief Creates a new image with inverted colors of the specified image.
      /// @param image The image to invert colors.
      /// @return The converted image.
      static xtd::drawing::image invert(const xtd::drawing::image& image);
      /// @brief Inverts colors of the specified image with specified percent factor.
      /// @param image The image to invert colors.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks `0.0` will represents the original image. `1.0` will provide image with inverted colors.
      static void invert(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with inverted colors of the specified image with specified percent factor.
      /// @param image The image to invert colors.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks `0.0` will represents the original image. `1.0` will provide image with inverted colors.
      static xtd::drawing::image invert(const xtd::drawing::image& image, double percent);

      /// @brief Changes the opacity level of the specified image with specified percent factor.
      /// @param image The image to change the opacity level.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks `0.0` will represents a transparent image. `1.0` will provide the original image.
      static void opacity(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with opacity level of the specified image with specified percent factor.
      /// @param image The image to change the opacity level.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks `0.0` will represents a transparent image. `1.0` will provide the original image.
      static xtd::drawing::image opacity(const xtd::drawing::image& image, double percent);

      /// @brief Resize image with of the specified image with specified size.
      /// @param image The image to change the size.
      /// @param size The new size.
      static void resize(xtd::drawing::image& image, const xtd::drawing::size& size);
      /// @brief Creates a new image with new size of the specified image with specified size.
      /// @param image The image to change the size.
      /// @param size The new size.
      /// @return The converted image.
      static xtd::drawing::image resize(const xtd::drawing::image& image, const xtd::drawing::size& size);

      /// @brief Rotates, flips, or rotates and flips of the specified image with specified rotate flip type.
      /// @param image The image to be rotated, flipped or rotated and flipped.
      /// @param rotate_flip_type A xtd::drawing::rotate_flip_type member that specifies the type of rotation and flip to apply to the image.
      /// @remarks The xtd::drawing::image::rotate_flip method rotates the image clockwise.
      static void rotate_flip(xtd::drawing::image& image, xtd::drawing::rotate_flip_type rotate_flip_type);
      /// @brief Creates a new image with rotations, flips, or rotations and flips of the specified image with specified rotate flip type.
      /// @param image The image to be rotated, flipped or rotated and flipped.
      /// @param rotate_flip_type A xtd::drawing::rotate_flip_type member that specifies the type of rotation and flip to apply to the image.
      /// @return The converted image.
      /// @remarks The xtd::drawing::image::rotate_flip method rotates the image clockwise.
      static xtd::drawing::image rotate_flip(const xtd::drawing::image& image, xtd::drawing::rotate_flip_type rotate_flip_type);
      
      /// @brief Change the saturate of the specified image with specified percent factor.
      /// @param image The image to change saturation.
      /// @param percent The percent factor in %.
      /// @remarks Thus, `1.0` returns the original image, while the other values give a saturate image.
      static void saturate(xtd::drawing::image& image, double percent);
      /// @brief Creates a new saturate image of the specified image with specified percent factor.
      /// @param image The image to change saturation.
      /// @param percent The percent factor in %.
      /// @return The converted image.
      /// @remarks Thus, `1.0` returns the original image, while the other values give a saturate image.
      static xtd::drawing::image saturate(const xtd::drawing::image& image, double percent);

      /// @brief Converts into sepia colors of the specified image.
      /// @param image The image to be transformed into sepia.
      static void sepia(xtd::drawing::image& image);
      /// @brief Creates a new image with sepia colors of the specified image.
      /// @param image The image to be transformed into sepia.
      /// @return The converted image.
      static xtd::drawing::image sepia(const xtd::drawing::image& image);
      /// @brief Converts into sepia colors of the specified image with specified percent factor.
      /// @param image The image to be transformed into sepia.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks Thus, `1.0` will make the color completely sepia, while `0.0` return the original image.
      static void sepia(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with sepia colors of the specified image with specified percent factor.
      /// @param image The image to be transformed into sepia.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks Thus, `1.0` will make the color completely sepia, while `0.0` return the original image.
      static xtd::drawing::image sepia(const xtd::drawing::image& image, double percent);

      /// @brief Converts into black and white colors of the specified image with specified threshold.
      /// @param image The image to convert into black and white colors.
      /// @param threshold The threshold value (from 0 to 765).
      static void threshold(xtd::drawing::image& image, int32 threshold);
      /// @brief Creates a new black and white image of the specified image with specified threshold.
      /// @param image The image to convert into black and white colors.
      /// @param threshold The threshold value (from 0 to 765).
      /// @return The converted image.
      static xtd::drawing::image threshold(const xtd::drawing::image& image, int32 threshold);
      /// @}
    };
  }
}
