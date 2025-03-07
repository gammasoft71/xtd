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
      /// @}
    };
  }
}
