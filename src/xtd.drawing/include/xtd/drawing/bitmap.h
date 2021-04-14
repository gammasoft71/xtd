/// @file
/// @brief Contains xtd::drawing::bitmap class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "image.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Encapsulates a GDI+ bitmap, which consists of the pixel data for a graphics image and its attributes. A bitmap is an object used to work with images defined by pixel data.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks To draw an image on a Windows Form, you should use one of the draw_image methods.
    class drawing_export_ bitmap : public xtd::drawing::image {
    public:
      explicit bitmap(const image& image) : xtd::drawing::image(image) {}

      bitmap(const image& image, const drawing::size& size) : xtd::drawing::image(image, size.width(), size.height()) {}

      bitmap(const image& image, const rectangle& rect) : xtd::drawing::image(image, rect) {}

      explicit bitmap(const std::string& filename) : xtd::drawing::image(filename) {}

      explicit bitmap(std::istream& stream) : xtd::drawing::image(stream) {}

      explicit bitmap(const char* const* bits) : xtd::drawing::image(bits) {}
      
      bitmap(int32_t width, int32_t height) : xtd::drawing::image(width, height) {}
      
      explicit bitmap(const xtd::drawing::size& size) : xtd::drawing::image(size.width(), size.height()) {}

      bitmap clone(const rectangle& rect) {return bitmap(*this, rect);}

      /// @cond
      bitmap(const bitmap& bitmap) = default;
      bitmap& operator=(const bitmap& bitmap) = default;
      /// @endcond

      drawing::color get_pixel(int32_t x, int32_t y) const;
      
      void set_pixel(int32_t x, int32_t y, const drawing::color& color);

      static bitmap empty;
      
    private:
      bitmap() = default;
    };
  }
}
