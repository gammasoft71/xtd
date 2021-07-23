/// @file
/// @brief Contains xtd::drawing::imaging::image_flags  class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Specifies the attributes of the pixel data contained in an xtd::drawing::image object. The xtd::drawing:iImage::flags property returns a member of this enumeration.
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class image_flags {
        /// @brief There is no format information.
        none = 0,
        /// @brief The pixel data is scalable.
        scalable = 0b1,
        /// @brief The pixel data contains alpha information.
        has_alpha = 0b10,
        /// @brief Specifies that the pixel data has alpha values other than 0 (transparent) and 255 (opaque).
        has_translucent = 0b100,
        /// @brief The pixel data is partially scalable, but there are some limitations.
        partially_scalable = 0b1000,
        /// @brief The pixel data uses an RGB color space.
        color_space_rgb = 0b10000,
        /// @brief The pixel data uses a CMYK color space.
        color_space_cmyk = 0b100000,
        /// @brief The pixel data is grayscale.
        color_space_gray = 0b1000000,
        /// @brief Specifies that the image is stored using a YCBCR color space.
        color_space_ycbcr = 0b10000000,
        /// @brief Specifies that the image is stored using a YCCK color space.
        color_space_ycck = 0b100000000,
        /// @brief Specifies that dots per inch information is stored in the image.
        has_real_dpi = 0b1000000000000,
        /// @brief Specifies that the pixel size is stored in the image.
        has_real_pixel_size = 0b10000000000000,
        /// @brief The pixel data is read-only.
        read_only = 0b10000000000000000,
        /// @brief The pixel data can be cached for faster access.
        caching = 0b100000000000000000,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, image_flags value) {return os << xtd::to_string(value, {{image_flags::none, "none"}, {image_flags::scalable, "scalable"}, {image_flags::has_alpha, "has_alpha"}, {image_flags::has_translucent, "has_translucent"}, {image_flags::partially_scalable, "partially_scalable"}, {image_flags::color_space_rgb, "color_space_rgb"}, {image_flags::color_space_cmyk, "color_space_cmyk"}, {image_flags::color_space_gray, "color_space_gray"}, {image_flags::color_space_ycbcr, "color_space_ycbcr"}, {image_flags::color_space_ycck, "color_space_ycck"}, {image_flags::has_real_dpi, "has_real_dpi"}, {image_flags::has_real_pixel_size, "has_real_pixel_size"}, {image_flags::read_only, "read_only"}, {image_flags::caching, "caching"}});}
      inline std::wostream& operator<<(std::wostream& os, image_flags value) {return os << xtd::to_string(value, {{image_flags::none, L"none"}, {image_flags::scalable, L"scalable"}, {image_flags::has_alpha, L"has_alpha"}, {image_flags::has_translucent, L"has_translucent"}, {image_flags::partially_scalable, L"partially_scalable"}, {image_flags::color_space_rgb, L"color_space_rgb"}, {image_flags::color_space_cmyk, L"color_space_cmyk"}, {image_flags::color_space_gray, L"color_space_gray"}, {image_flags::color_space_ycbcr, L"color_space_ycbcr"}, {image_flags::color_space_ycck, L"color_space_ycck"}, {image_flags::has_real_dpi, L"has_real_dpi"}, {image_flags::has_real_pixel_size, L"has_real_pixel_size"}, {image_flags::read_only, L"read_only"}, {image_flags::caching, L"caching"}});}
      /// @endcond
    }
  }
}
