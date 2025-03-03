/// @file
/// @brief Contains xtd::drawing::image_converter class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "image.hpp"
#include "rotate_flip_type.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class bitmap;
    /// @endcond
    
    /// @brief Converts images to and from xtd::drawing::image class. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ image_converter final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::image_converter
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    class drawing_export_ image_converter final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Converts into lower and upper colors of the specified image with specified threshold, upper color and lower color.
      /// @param image The image to convert into lower and upper colors.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param upper_color The color used when RGB color is upper the threshold value.
      /// @param lower_color The color used when RGB color is under or equal the threshold value.
      /// @par Appearance
      /// | Original             | Converted                    |
      /// | -------------------- | ---------------------------- |
      /// | @image html ball.png | @image html ball_bitonal.png |
      static void bitonal(xtd::drawing::image& image, int32 threshold, const color& upper_color, const color& lower_color);
      /// @brief Creates a new lower and upper image of the specified image with specified threshold, upper color and lower color.
      /// @param image The image to convert into lower and upper colors.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param upper_color The color used when RGB color is upper the threshold value.
      /// @param lower_color The color used when RGB color is under or equal the threshold value.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                    |
      /// | -------------------- | ---------------------------- |
      /// | @image html ball.png | @image html ball_bitonal.png |
      static xtd::drawing::image bitonal(const xtd::drawing::image& image, int32 threshold, const color& upper_color, const color& lower_color);

      /// @brief Blur the specified image with the specified radius.
      /// @param image The image to blur.
      /// @param radius The radius of the blur in pixels.
      /// @remarks If the radius is `0`, there will be no blurring.
      /// @par Appearance
      /// | Original             | Converted                 |
      /// | -------------------- | ------------------------- |
      /// | @image html ball.png | @image html ball_blur.png |
      static void blur(xtd::drawing::image& image, int32 radius);
      /// @brief Creates a new blurred image of the specified image with the specified radius.
      /// @param image The image to blur.
      /// @param radius The radius of the blur in pixels.
      /// @return The converted image.
      /// @remarks If the radius is `0`, there will be no blurring.
      /// @par Appearance
      /// | Original             | Converted                 |
      /// | -------------------- | ------------------------- |
      /// | @image html ball.png | @image html ball_blur.png |
      static xtd::drawing::image blur(const xtd::drawing::image& image, int32 radius);

      /// @brief Change the brightness of the specified image with specified percent.
      /// @param image The image to brightness.
      /// @param percent The percent factor in %.
      /// @remarks `0.0` will make the image completely black. `1.0` is default and represents the original image. Values over `1.0` will provide brighter results.
      /// @par Appearance
      /// | Original             | Converted                       |
      /// | -------------------- | ------------------------------- |
      /// | @image html ball.png | @image html ball_brightness.png |
      static void brightness(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with brightness changed of the specified image with specified percent.
      /// @param image The image to brightness.
      /// @param percent The percent factor in % (from 0.0 to 2.0).
      /// @return The converted image.
      /// @remarks `0.0` will make the image completely black. `1.0` is default and represents the original image. Values over `1.0` will provide brighter results.
      /// @par Appearance
      /// | Original             | Converted                       |
      /// | -------------------- | ------------------------------- |
      /// | @image html ball.png | @image html ball_brightness.png |
      static xtd::drawing::image brightness(const xtd::drawing::image& image, double percent);
      
      /// @brief Add / remove the specified color from the specified image with the specified percent.
      /// @param image The image to update.
      /// @param color The color to add / remove.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @par Appearance
      /// | Original             | Converted                  |
      /// | -------------------- | -------------------------- |
      /// | @image html ball.png | @image html ball_color.png |
      static void color(xtd::drawing::image& image, const xtd::drawing::color& color, double percent);
      /// @brief Create a new image with the specified color that will be added/removed from the specified image with the specified percent.
      /// @param image The image to update.
      /// @param color The color to add / remove.
      /// @param percent The percent factor in % (from 0.0 to 2.0).
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                  |
      /// | -------------------- | -------------------------- |
      /// | @image html ball.png | @image html ball_color.png |
      static xtd::drawing::image color(const xtd::drawing::image& image, const xtd::drawing::color& color, double percent);

      /// @brief Filters image with specified color and replaces all other colors with other specified color.
      /// @param image The image to filter color.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param extraction_color The extraction color.
      /// @param other_pixels_color The other pixels color.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                             |
      /// | -------------------- | ------------------------------------- |
      /// | @image html ball.png | @image html ball_color_extraction.png |
      static void color_extraction(xtd::drawing::image& image, int32 threshold, const drawing::color& extraction_color, const xtd::drawing::color& other_pixels_color) noexcept;
      /// @brief Creates a new filtered image with specified color and replaces all other colors with other specified color.
      /// @param image The image to filter color.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param extraction_color The extraction color.
      /// @param other_pixels_color The other pixels color.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                             |
      /// | -------------------- | ------------------------------------- |
      /// | @image html ball.png | @image html ball_color_extraction.png |
      static xtd::drawing::image color_extraction(const xtd::drawing::image& image, int32 threshold, const drawing::color& extraction_color, const xtd::drawing::color& other_pixels_color) noexcept;

      /// @brief Replaces the specified source color with the new color.
      /// @param image The image to filter.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param source_color The source color.
      /// @param new_color The new color.
      /// @par Appearance
      /// | Original             | Converted                               |
      /// | -------------------- | --------------------------------------- |
      /// | @image html ball.png | @image html ball_color_substitution.png |
      static void color_substitution(xtd::drawing::image& image, int32 threshold, const drawing::color& source_color, const xtd::drawing::color& new_color) noexcept;
      /// @brief Creates a new image where the specified source color is replaced by the new color.
      /// @param image The image to filter.
      /// @param threshold The threshold value (from 0 to 765).
      /// @param source_color The source color.
      /// @param new_color The new color.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                               |
      /// | -------------------- | --------------------------------------- |
      /// | @image html ball.png | @image html ball_color_substitution.png |
      static xtd::drawing::image color_substitution(const xtd::drawing::image& image, int32 threshold, const drawing::color& source_color, const xtd::drawing::color& new_color) noexcept;

      /// @brief Change the contrast of the specified image with specified percent factor.
      /// @param image The image to change contrast.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks Thus, `1.0` returns the original image, while the other values give a contrasting image.
      /// @par Appearance
      /// | Original             | Converted                     |
      /// | -------------------- | ----------------------------- |
      /// | @image html ball.png | @image html ball_contrast.png |
      static void contrast(xtd::drawing::image& image, double percent);
      /// @brief Creates a new contrasting image of the specified image with specified percent factor.
      /// @param image The image to change contrast.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks Thus, `1.0` returns the original image, while the other values give a contrasting image.
      /// @par Appearance
      /// | Original             | Converted                     |
      /// | -------------------- | ----------------------------- |
      /// | @image html ball.png | @image html ball_contrast.png |
      static xtd::drawing::image contrast(const xtd::drawing::image& image, double percent);
  
      /// @brief Crops image with of the specified image with specified recatngle.
      /// @param image The image to change the size.
      /// @param size The new size.
      /// @par Appearance
      /// | Original             | Converted                 |
      /// | -------------------- | ------------------------- |
      /// | @image html ball.png | @image html ball_crop.png |
      static void crop(xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle);
      /// @brief Creates a new cropped image of the specified image with specified rectangle.
      /// @param image The image to crop.
      /// @param rectangle The rectangle of the crop.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                 |
      /// | -------------------- | -------------------------- |
      /// | @image html ball.png | @image html ball_crop.png |
      static xtd::drawing::image crop(const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle);

      /// @brief Disable the specified image with specified reference background color.
      /// @param image The image to disble.
      /// @param back_color The reference background color.
      /// @par Appearance
      /// | Original             | Converted                     |
      /// | -------------------- | ----------------------------- |
      /// | @image html ball.png | @image html ball_disabled.png |
      static void disabled(xtd::drawing::image& image, const xtd::drawing::color& back_color);
      /// @brief Creates a new disabled image of the specified image with specified reference background color.
      /// @param image The image to disble.
      /// @param back_color The reference background color.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                     |
      /// | -------------------- | ----------------------------- |
      /// | @image html ball.png | @image html ball_disabled.png |
      static xtd::drawing::image disabled(const xtd::drawing::image& image, const xtd::drawing::color& back_color);
      /// @brief Disabled the specified image with specified brightness.
      /// @param image The image to dissable.
      /// @param brightness The brightness of the reference background color.
      /// @par Appearance
      /// | Original             | Converted                     |
      /// | -------------------- | ----------------------------- |
      /// | @image html ball.png | @image html ball_disabled.png |
      static void disabled(xtd::drawing::image& image, float brightness);
      /// @brief Creates a new disabled image of the specified image with specified brightness.
      /// @param image The image to dissable.
      /// @param brightness The brightness of the reference background color.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                     |
      /// | -------------------- | ----------------------------- |
      /// | @image html ball.png | @image html ball_disabled.png |
      static xtd::drawing::image disabled(const xtd::drawing::image& image, float brightness);

      /// @brief Add drop shadow to the specified image, with specified horizontal and vertical shadow, blur radius, and the shadow color.
      /// @param image The image to add drop shadow.
      /// @param horizontal_shadow Specifies a pixel value for the horizontal shadow in pixels. Negative values place the shadow to the left of the image.
      /// @param vertical_shadow Specifies a pixel value for the vertical shadow in pixels. Negative values place the shadow to the left of the image.
      /// @param blur Adds a blur effect to the shadow in pixels. A larger value will create more blur (the shadow becomes bigger and lighter). Negative values are not allowed. If no value is specified, 0 is used (the shadow's edge is sharp).
      /// @param color Adds a color to the shadow.
      /// @par Appearance
      /// | Original             | Converted                        |
      /// | -------------------- | -------------------------------- |
      /// | @image html ball.png | @image html ball_drop_shadow.png |
      static void drop_shadow(xtd::drawing::image& image, int32 horizontal_shadow, int32 vertical_shadow, int32 blur, const xtd::drawing::color& color);
      /// @brief Create a new imgae with drop shadow with the specified image, horizontal and vertical shadow, blur radius, and the shadow color.
      /// @param image The image to add drop shadow.
      /// @param horizontal_shadow Specifies a pixel value for the horizontal shadow in pixels. Negative values place the shadow to the left of the image.
      /// @param vertical_shadow Specifies a pixel value for the vertical shadow in pixels. Negative values place the shadow to the left of the image.
      /// @param blur Adds a blur effect to the shadow in pixels. A larger value will create more blur (the shadow becomes bigger and lighter). Negative values are not allowed. If no value is specified, 0 is used (the shadow's edge is sharp).
      /// @param color Adds a color to the shadow.
      /// @par Appearance
      /// | Original             | Converted                        |
      /// | -------------------- | -------------------------------- |
      /// | @image html ball.png | @image html ball_drop_shadow.png |
      static xtd::drawing::image drop_shadow(const xtd::drawing::image& image, int32 horizontal_shadow, int32 vertical_shadow, int32 blur, const xtd::drawing::color& color);

      /// @brief Change the gamma of the specified image with specified r, g, ad b corrections.
      /// @param image The image to change the gamma.
      /// @param r The red correction from 0.1 to 5.
      /// @param g The green correction from 0.1 to 5.
      /// @param b The blue correction from 0.1 to 5.
      /// @par Appearance
      /// | Original             | Converted                             |
      /// | -------------------- | ------------------------------------- |
      /// | @image html ball.png | @image html ball_gamma_correction.png |
      static void gamma_correction(xtd::drawing::image& image, double r, double g, double b);
      /// @brief Creates a new image with gamma correction of the specified image with specified r, g, ad b corrections.
      /// @param image The image to change the gamma.
      /// @param r The red correction from 0.1 to 5.
      /// @param g The green correction from 0.1 to 5.
      /// @param b The blue correction from 0.1 to 5.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                             |
      /// | -------------------- | ------------------------------------- |
      /// | @image html ball.png | @image html ball_gamma_correction.png |
      static xtd::drawing::image gamma_correction(const xtd::drawing::image& image, double r, double g, double b);

      /// @brief Converts into grayscale of the specified image.
      /// @param image The image to be transformed into grayscale.
      /// @par Appearance
      /// | Original             | Converted                      |
      /// | -------------------- | ------------------------------ |
      /// | @image html ball.png | @image html ball_grayscale.png |
      static void grayscale(xtd::drawing::image& image);
      /// @brief Creates a new image with grayscale colors of the specified image.
      /// @param image The image to be transformed into grayscale.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                      |
      /// | -------------------- | ------------------------------ |
      /// | @image html ball.png | @image html ball_grayscale.png |
      static xtd::drawing::image grayscale(const xtd::drawing::image& image);
      /// @brief Converts into grayscale of the specified image with specified percent factor.
      /// @param image The image to be transformed into grayscale.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks Thus, `1.0` will make the color completely gray, while `0.0` return the original image.
      /// @par Appearance
      /// | Original             | Converted                      |
      /// | -------------------- | ------------------------------ |
      /// | @image html ball.png | @image html ball_grayscale.png |
      static void grayscale(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with grayscale colors of the specified image with specified percent factor.
      /// @param image The image to be transformed into grayscale.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks Thus, `1.0` will make the color completely gray, while `0.0` return the original image.
      /// @par Appearance
      /// | Original             | Converted                      |
      /// | -------------------- | ------------------------------ |
      /// | @image html ball.png | @image html ball_grayscale.png |
      static xtd::drawing::image grayscale(const xtd::drawing::image& image, double percent);

      /// @brief Rotate hue colors of the specified image with specified angle.
      /// @param image The image to rotate hue colors.
      /// @param angle The angle in degrees (form 0 to 360).
      /// @par Appearance
      /// | Original             | Converted                       |
      /// | -------------------- | ------------------------------- |
      /// | @image html ball.png | @image html ball_hue_rotate.png |
      static void hue_rotate(xtd::drawing::image& image, int angle);
      /// @brief Creates a new image with rotated hue colors of the specified image with specified angle.
      /// @param image The image to rotate hue colors.
      /// @param angle The angle in degrees (form 0 to 360).
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                       |
      /// | -------------------- | ------------------------------- |
      /// | @image html ball.png | @image html ball_hue_rotate.png |
      static xtd::drawing::image hue_rotate(const xtd::drawing::image& image, int angle);

      /// @brief Inverts colors of the specified image.
      /// @param image The image to invert colors.
      /// @par Appearance
      /// | Original             | Converted                   |
      /// | -------------------- | --------------------------- |
      /// | @image html ball.png | @image html ball_invert.png |
      static void invert(xtd::drawing::image& image);
      /// @brief Creates a new image with inverted colors of the specified image.
      /// @param image The image to invert colors.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                   |
      /// | -------------------- | --------------------------- |
      /// | @image html ball.png | @image html ball_invert.png |
      static xtd::drawing::image invert(const xtd::drawing::image& image);
      /// @brief Inverts colors of the specified image with specified percent factor.
      /// @param image The image to invert colors.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks `0.0` will represents the original image. `1.0` will provide image with inverted colors.
      /// @par Appearance
      /// | Original             | Converted                   |
      /// | -------------------- | --------------------------- |
      /// | @image html ball.png | @image html ball_invert.png |
      static void invert(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with inverted colors of the specified image with specified percent factor.
      /// @param image The image to invert colors.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks `0.0` will represents the original image. `1.0` will provide image with inverted colors.
      /// @par Appearance
      /// | Original             | Converted                   |
      /// | -------------------- | --------------------------- |
      /// | @image html ball.png | @image html ball_invert.png |
      static xtd::drawing::image invert(const xtd::drawing::image& image, double percent);

      /// @brief Changes the opacity level of the specified image with specified percent factor.
      /// @param image The image to change the opacity level.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks `0.0` will represents a transparent image. `1.0` will provide the original image.
      /// @par Appearance
      /// | Original             | Converted                    |
      /// | -------------------- | ---------------------------- |
      /// | @image html ball.png | @image html ball_opacity.png |
      static void opacity(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with opacity level of the specified image with specified percent factor.
      /// @param image The image to change the opacity level.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks `0.0` will represents a transparent image. `1.0` will provide the original image.
      /// @par Appearance
      /// | Original             | Converted                    |
      /// | -------------------- | ---------------------------- |
      /// | @image html ball.png | @image html ball_opacity.png |
      static xtd::drawing::image opacity(const xtd::drawing::image& image, double percent);

      /// @brief Rescale image with of the specified image with specified size.
      /// @param image The image to change the size.
      /// @param size The new size.
      /// @par Appearance
      /// | Original             | Converted                    |
      /// | -------------------- | ---------------------------- |
      /// | @image html ball.png | @image html ball_rescale.png |
      static void rescale(xtd::drawing::image& image, const xtd::drawing::size& size);
      /// @brief Creates a new resacaling image with new size of the specified image with specified size.
      /// @param image The image to change the size.
      /// @param size The new size.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                    |
      /// | -------------------- | ---------------------------- |
      /// | @image html ball.png | @image html ball_rescale.png |
      static xtd::drawing::image rescale(const xtd::drawing::image& image, const xtd::drawing::size& size);

      /// @brief Resize image with of the specified image with specified size.
      /// @param image The image to change the size.
      /// @param size The new size.
      /// @par Appearance
      /// | Original             | Converted                   |
      /// | -------------------- | --------------------------- |
      /// | @image html ball.png | @image html ball_resize.png |
      static void resize(xtd::drawing::image& image, const xtd::drawing::size& size);
      /// @brief Creates a new resized image with new size of the specified image with specified size.
      /// @param image The image to change the size.
      /// @param size The new size.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                   |
      /// | -------------------- | --------------------------- |
      /// | @image html ball.png | @image html ball_resize.png |
      static xtd::drawing::image resize(const xtd::drawing::image& image, const xtd::drawing::size& size);
      /// @brief Resize image with of the specified image with specified size.
      /// @param image The image to change the size.
      /// @param rectangle The new rectangle.
      /// @par Appearance
      /// | Original             | Converted                   |
      /// | -------------------- | --------------------------- |
      /// | @image html ball.png | @image html ball_resize.png |
      static void resize(xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle);
      /// @brief Creates a new resized image with new size of the specified image with specified size.
      /// @param image The image to change the size.
      /// @param rectangle The new rectangle.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                   |
      /// | -------------------- | --------------------------- |
      /// | @image html ball.png | @image html ball_resize.png |
      static xtd::drawing::image resize(const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle);

      /// @brief Rotates, flips, or rotates and flips of the specified image with specified rotate flip type.
      /// @param image The image to be rotated, flipped or rotated and flipped.
      /// @param rotate_flip_type A xtd::drawing::rotate_flip_type member that specifies the type of rotation and flip to apply to the image.
      /// @remarks The xtd::drawing::image::rotate_flip method rotates the image clockwise.
      /// @par Appearance
      /// | Original             | Converted                        |
      /// | -------------------- | -------------------------------- |
      /// | @image html ball.png | @image html ball_rotate_flip.png |
      static void rotate_flip(xtd::drawing::image& image, xtd::drawing::rotate_flip_type rotate_flip_type);
      /// @brief Creates a new image with rotations, flips, or rotations and flips of the specified image with specified rotate flip type.
      /// @param image The image to be rotated, flipped or rotated and flipped.
      /// @param rotate_flip_type A xtd::drawing::rotate_flip_type member that specifies the type of rotation and flip to apply to the image.
      /// @return The converted image.
      /// @remarks The xtd::drawing::image::rotate_flip method rotates the image clockwise.
      /// @par Appearance
      /// | Original             | Converted                        |
      /// | -------------------- | -------------------------------- |
      /// | @image html ball.png | @image html ball_rotate_flip.png |
      static xtd::drawing::image rotate_flip(const xtd::drawing::image& image, xtd::drawing::rotate_flip_type rotate_flip_type);
      
      /// @brief Change the saturate of the specified image with specified percent factor.
      /// @param image The image to change saturation.
      /// @param percent The percent factor in %.
      /// @remarks Thus, `1.0` returns the original image, while the other values give a saturate image.
      /// @par Appearance
      /// | Original             | Converted                     |
      /// | -------------------- | ----------------------------- |
      /// | @image html ball.png | @image html ball_saturate.png |
      static void saturate(xtd::drawing::image& image, double percent);
      /// @brief Creates a new saturate image of the specified image with specified percent factor.
      /// @param image The image to change saturation.
      /// @param percent The percent factor in %.
      /// @return The converted image.
      /// @remarks Thus, `1.0` returns the original image, while the other values give a saturate image.
      /// @par Appearance
      /// | Original             | Converted                     |
      /// | -------------------- | ----------------------------- |
      /// | @image html ball.png | @image html ball_saturate.png |
      static xtd::drawing::image saturate(const xtd::drawing::image& image, double percent);

      /// @brief Converts into sepia colors of the specified image.
      /// @param image The image to be transformed into sepia.
      /// @par Appearance
      /// | Original             | Converted                  |
      /// | -------------------- | -------------------------- |
      /// | @image html ball.png | @image html ball_sepia.png |
      static void sepia(xtd::drawing::image& image);
      /// @brief Creates a new image with sepia colors of the specified image.
      /// @param image The image to be transformed into sepia.
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                  |
      /// | -------------------- | -------------------------- |
      /// | @image html ball.png | @image html ball_sepia.png |
      static xtd::drawing::image sepia(const xtd::drawing::image& image);
      /// @brief Converts into sepia colors of the specified image with specified percent factor.
      /// @param image The image to be transformed into sepia.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @remarks Thus, `1.0` will make the color completely sepia, while `0.0` return the original image.
      /// @par Appearance
      /// | Original             | Converted                  |
      /// | -------------------- | -------------------------- |
      /// | @image html ball.png | @image html ball_sepia.png |
      static void sepia(xtd::drawing::image& image, double percent);
      /// @brief Creates a new image with sepia colors of the specified image with specified percent factor.
      /// @param image The image to be transformed into sepia.
      /// @param percent The percent factor in % (from 0.0 to 1.0).
      /// @return The converted image.
      /// @remarks Thus, `1.0` will make the color completely sepia, while `0.0` return the original image.
      /// @par Appearance
      /// | Original             | Converted                  |
      /// | -------------------- | -------------------------- |
      /// | @image html ball.png | @image html ball_sepia.png |
      static xtd::drawing::image sepia(const xtd::drawing::image& image, double percent);

      /// @brief Converts into black and white colors of the specified image with specified threshold.
      /// @param image The image to convert into black and white colors.
      /// @param threshold The threshold value (from 0 to 765).
      /// @par Appearance
      /// | Original             | Converted                      |
      /// | -------------------- | ------------------------------ |
      /// | @image html ball.png | @image html ball_threshold.png |
      static void threshold(xtd::drawing::image& image, int32 threshold);
      /// @brief Creates a new black and white image of the specified image with specified threshold.
      /// @param image The image to convert into black and white colors.
      /// @param threshold The threshold value (from 0 to 765).
      /// @return The converted image.
      /// @par Appearance
      /// | Original             | Converted                      |
      /// | -------------------- | ------------------------------ |
      /// | @image html ball.png | @image html ball_threshold.png |
      static xtd::drawing::image threshold(const xtd::drawing::image& image, int32 threshold);
      /// @}
    };
  }
}
