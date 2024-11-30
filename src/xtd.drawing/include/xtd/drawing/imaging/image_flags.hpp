/// @file
/// @brief Contains xtd::drawing::imaging::image_flags  class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Specifies the attributes of the pixel data contained in an xtd::drawing::image object. The xtd::drawing:iImage::flags property returns a member of this enumeration.
      /// @par Namespace
      /// xtd::drawing::imaging
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
    }
  }
}

/// @cond
flags_attribute_(xtd::drawing::imaging, image_flags);

template<> struct xtd::enum_register<xtd::drawing::imaging::image_flags> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::imaging::image_flags> {{xtd::drawing::imaging::image_flags::none, "none"}, {xtd::drawing::imaging::image_flags::scalable, "scalable"}, {xtd::drawing::imaging::image_flags::has_alpha, "has_alpha"}, {xtd::drawing::imaging::image_flags::has_translucent, "has_translucent"}, {xtd::drawing::imaging::image_flags::partially_scalable, "partially_scalable"}, {xtd::drawing::imaging::image_flags::color_space_rgb, "color_space_rgb"}, {xtd::drawing::imaging::image_flags::color_space_cmyk, "color_space_cmyk"}, {xtd::drawing::imaging::image_flags::color_space_gray, "color_space_gray"}, {xtd::drawing::imaging::image_flags::color_space_ycbcr, "color_space_ycbcr"}, {xtd::drawing::imaging::image_flags::color_space_ycck, "color_space_ycck"}, {xtd::drawing::imaging::image_flags::has_real_dpi, "has_real_dpi"}, {xtd::drawing::imaging::image_flags::has_real_pixel_size, "has_real_pixel_size"}, {xtd::drawing::imaging::image_flags::read_only, "read_only"}, {xtd::drawing::imaging::image_flags::caching, "caching"}};}
};
/// @endcond
