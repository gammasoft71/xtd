/// @file
/// @brief Contains xtd::drawing::image_transformer class.
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
    
    /// @brief Transforme images to and from xtd::drawing::image class. This class cannot be inherited.
    /// @code
    /// class drawing_export_ image_transformer final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::image_transformer
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    class drawing_export_ image_transformer final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Returns a blur version of the specified image with radius value of 10.
      /// @param image The image to blured.
      /// @return the blured image result.
      static xtd::drawing::image blur(const xtd::drawing::image& image);
      /// @brief Returns a blur version of the specified image with radius.
      /// @param image The image to blured.
      /// @param radius The radius of the blur, specified as a <length>.
      /// @return the blured image result.
      /// @remarks No blur effect, if the radius is `0`.
      static xtd::drawing::image blur(const xtd::drawing::image& image, int32 radius);
      
      /// @brief Returns a brightness version of the specified image with percent factor.
      /// @param image The image to brightness.
      /// @param percent The percent factor.
      /// @return The adjusted image result.
      /// @remarks 0% will make the image completely black. 100% is default and represents the original image. Values over 100% will provide brighter results.
      static xtd::drawing::image brightness(const xtd::drawing::image& image, double percent);
      
      /// @brief Returns a contrasted version of the specified image with percent factor.
      /// @param image The image to change contrast.
      /// @param percent The percent factor.
      /// @return The contrasted image result.
      /// @remarks Thus, `1.0` return the original image. while other will make a contrasted image.
      static xtd::drawing::image contrast(const xtd::drawing::image& image, double percent);
      
      /// @brief Returns a disabled version of the specified image and background color.
      /// @param image The image to brightness.
      /// @param back_color The reference background color.
      /// @return The disabled image result.
      static xtd::drawing::image disabled(const xtd::drawing::image& image, const color& back_color);
      /// @brief Returns a disabled version of the specified image and background color.
      /// @param image The image to brightness.
      /// @param brightness The brightness of the reference background color.
      /// @return The disabled image result.
      static xtd::drawing::image disabled(const xtd::drawing::image& image, float brightness);
      
      /// @brief Returns an invert version of the specified image with percent factor.
      /// @param image The image to invert.
      /// @param percent The percent factor.
      /// @return The adjusted image result.
      /// @remarks 0% will represents the original image. 100% will provide image with inverted colors.
      static xtd::drawing::image invert(const xtd::drawing::image& image, double percent);
      
      /// @brief Returns a grayscale version of the specified image with percent factor.
      /// @param image The image to grayscale.
      /// @param percent The percent factor.
      /// @return the grayscale image result.
      /// @remarks Thus, `1.0` will make the color completely gray, while `0.0` return the original image.
      static xtd::drawing::image grayscale(const xtd::drawing::image& image, double percent);
      /// @brief Returns a grayscale version of the specified image.
      /// @param image The image to grayscale.
      /// @return the grayscale image result.
      static xtd::drawing::image grayscale(const xtd::drawing::image& image);
      
      /// @brief Returns an opacity level version of the specified image with percent factor.
      /// @param image The image to change the opacity level.
      /// @param percent The percent factor.
      /// @return The adjusted image result.
      /// @remarks 0% will represents a transparent image. 100% will provide the original image.
      static xtd::drawing::image opacity(const xtd::drawing::image& image, double percent);
      
      /// @brief Rotates, flips, or rotates and flips the xtd::drawing::image.
      /// @param rotate_flip_type A xtd::drawing::rotate_flip_type member that specifies the type of rotation and flip to apply to the image.
      /// @remarks The xtd::drawing::image::rotate_flip method rotates the image clockwise.
      /// @remarks If you wish to draw on an image once it has been rotated, you should always retrieve a new graphics object from the image, otherwise an exception could occur.
      static xtd::drawing::image rotate_flip(const xtd::drawing::image& image, xtd::drawing::rotate_flip_type rotate_flip_type);
      
      /// @brief Returns a sepia version of the specified image with percent factor.
      /// @param image The image to sepia.
      /// @param percent The percent factor.
      /// @return the sepia image result.
      /// @remarks Thus, `1.0` will make the color completely sepia, while `0.0` return the original image.
      static xtd::drawing::image sepia(const xtd::drawing::image& image, double percent);
      /// @brief Returns a sepia version of the specified image.
      /// @param image The image to sepia.
      /// @return the sepia image result.
      static xtd::drawing::image sepia(const xtd::drawing::image& image);
      /// @}
    };
  }
}
