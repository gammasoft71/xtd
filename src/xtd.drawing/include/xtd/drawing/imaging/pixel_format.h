/// @file
/// @brief Contains xtd::drawing::imaging::pixel_format enum class.
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
      /// @brief Specifies the format of the color data for each pixel in the image.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks The pixel format defines the number of bits of memory associated with one pixel of data. The format also defines the order of the color components within a single pixel of data.
      /// @remarks PixelFormat48bppRGB, PixelFormat64bppARGB, and PixelFormat64bppPARGB use 16 bits per color component (channel). GDI+ version 1.0 and 1.1 can read 16-bits-per-channel images, but such images are converted to an 8-bits-per-channel format for processing, displaying, and saving. Each 16-bit color channel can hold a value in the range 0 through 2^13.
      /// @remarks Some of the pixel formats contain premultiplied color values. Premultiplied means that the color values have already been multiplied by an alpha value.
      enum class pixel_format {
        /// The pixel format is undefined.
        undefined = 0,
        /// @brief No pixel format is specified.
        dont_care = 0,
        /// @brief The maximum value for this enumeration.
        max = 0x0000000F,
        /// @brief The pixel data contains color-indexed values, which means the values are an index to colors in the system color table, as opposed to individual color values.
        indexed = 0x00010000,
        /// @brief The pixel data contains GDI colors.
        gdi = 0x00020000,
        /// @brief Specifies that the format is 16 bits per pixel; 5 bits each are used for the red, green, and blue components. The remaining bit is not used.
        format_16bpp_rgb555 = 0x00021005,
        /// @brief Specifies that the format is 16 bits per pixel; 5 bits are used for the red component, 6 bits are used for the green component, and 5 bits are used for the blue component.
        format_16bpp_rgb565 = 0x00021006,
        /// @brief Specifies that the format is 24 bits per pixel; 8 bits each are used for the red, green, and blue components.
        format_24bpp_rgb = 0x00021808,
        /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the red, green, and blue components. The remaining 8 bits are not used.
        format_32bpp_rgb = 0x00022009,
        /// @brief Specifies that the pixel format is 1 bit per pixel and that it uses indexed color. The color table therefore has two colors in it.
        format_1bpp_indexed = 0x00030101,
        /// @brief Specifies that the format is 4 bits per pixel, indexed.
        format_4bpp_indexed = 0x00030402,
        /// @brief Specifies that the format is 8 bits per pixel, indexed. The color table therefore has 256 colors in it.
        format_8bpp_indexed = 0x00030803,
        /// @brief The pixel data contains alpha values that are not premultiplied.
        alpha = 0x00040000,
        /// @brief The pixel format is 16 bits per pixel. The color information specifies 32,768 shades of color, of which 5 bits are red, 5 bits are green, 5 bits are blue, and 1 bit is alpha.
        format_16bpp_argb1555 = 0x00061007,
        /// The pixel format contains premultiplied alpha values.
        palpha = 0x00080000,
        /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied, according to the alpha component.
        format_32bpp_pargb = 0x000E200B,
        /// @brief Reserved.
        extended = 0x00100000,
        /// @brief The pixel format is 16 bits per pixel. The color information specifies 65536 shades of gray.
        format_16bpp_gray_scale = 0x00101004,
        /// @brief Specifies that the format is 48 bits per pixel; 16 bits each are used for the red, green, and blue components.
        format_48bpp_rgb = 0x0010300C,
        /// @brief Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied according to the alpha component.
        format_64bpp_pargb = 0x001C400E,
        /// @brief The default pixel format of 32 bits per pixel. The format specifies 24-bit color depth and an 8-bit alpha channel.
        canonical = 0x00200000,
        /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components.
        format_32bpp_argb = 0x0026200A,
        /// @brief Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components.
        format_64bpp_argb = 0x0034400D,
      };
    }
  }
}

/// @cond
flags_attribute_(xtd::drawing::imaging, pixel_format);

template<> struct xtd::enum_register<xtd::drawing::imaging::pixel_format> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::imaging::pixel_format> {{xtd::drawing::imaging::pixel_format::undefined, "undefined"}, {xtd::drawing::imaging::pixel_format::max, "max"}, {xtd::drawing::imaging::pixel_format::indexed, "indexed"}, {xtd::drawing::imaging::pixel_format::gdi, "gdi"}, {xtd::drawing::imaging::pixel_format::format_16bpp_rgb555, "format_16bpp_rgb555"}, {xtd::drawing::imaging::pixel_format::format_16bpp_rgb565, "format_16bpp_rgb565"}, {xtd::drawing::imaging::pixel_format::format_24bpp_rgb, "format_24bpp_rgb"}, {xtd::drawing::imaging::pixel_format::format_32bpp_rgb, "format_32bpp_rgb"}, {xtd::drawing::imaging::pixel_format::format_1bpp_indexed, "format_1bpp_indexed"}, {xtd::drawing::imaging::pixel_format::format_4bpp_indexed, "format_4bpp_indexed"}, {xtd::drawing::imaging::pixel_format::format_8bpp_indexed, "format_8bpp_indexed"}, {xtd::drawing::imaging::pixel_format::alpha, "alpha"}, {xtd::drawing::imaging::pixel_format::format_16bpp_argb1555, "format_16bpp_argb1555"}, {xtd::drawing::imaging::pixel_format::palpha, "palpha"}, {xtd::drawing::imaging::pixel_format::format_32bpp_pargb, "format_32bpp_pargb"}, {xtd::drawing::imaging::pixel_format::extended, "extended"}, {xtd::drawing::imaging::pixel_format::format_16bpp_gray_scale, "format_16bpp_gray_scale"}, {xtd::drawing::imaging::pixel_format::format_48bpp_rgb, "format_48bpp_rgb"}, {xtd::drawing::imaging::pixel_format::format_64bpp_pargb, "format_64bpp_pargb"}, {xtd::drawing::imaging::pixel_format::canonical, "canonical"}, {xtd::drawing::imaging::pixel_format::format_32bpp_argb, "format_32bpp_argb"}, {xtd::drawing::imaging::pixel_format::format_64bpp_argb, "format_64bpp_argb"}};}
};
/// @endcond
