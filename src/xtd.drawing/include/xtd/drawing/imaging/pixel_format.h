/// @file
/// @brief Contains xtd::drawing::imaging::pixel_format enum class.
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
         format16bpp_rgb555 = 0x00021005,
         /// @brief Specifies that the format is 16 bits per pixel; 5 bits are used for the red component, 6 bits are used for the green component, and 5 bits are used for the blue component.
         format16bpp_rgb565 = 0x00021006,
         /// @brief Specifies that the format is 24 bits per pixel; 8 bits each are used for the red, green, and blue components.
         format24bpp_rgb = 0x00021808,
         /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the red, green, and blue components. The remaining 8 bits are not used.
         format32bpp_rgb = 0x00022009,
         /// @brief Specifies that the pixel format is 1 bit per pixel and that it uses indexed color. The color table therefore has two colors in it.
         format1bpp_indexed = 0x00030101,
         /// @brief Specifies that the format is 4 bits per pixel, indexed.
         format4bpp_indexed = 0x00030402,
         /// @brief Specifies that the format is 8 bits per pixel, indexed. The color table therefore has 256 colors in it.
         format8bpp_indexed = 0x00030803,
         /// @brief The pixel data contains alpha values that are not premultiplied.
         alpha = 0x00040000,
         /// @brief The pixel format is 16 bits per pixel. The color information specifies 32,768 shades of color, of which 5 bits are red, 5 bits are green, 5 bits are blue, and 1 bit is alpha.
         format16bpp_argb1555 = 0x00061007,
         /// The pixel format contains premultiplied alpha values.
         palpha = 0x00080000,
         /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied, according to the alpha component.
         format32bpp_pargb = 0x000E200B,
         /// @brief Reserved.
         extended = 0x00100000,
         /// @brief The pixel format is 16 bits per pixel. The color information specifies 65536 shades of gray.
         format16bpp_gray_scale = 0x00101004,
         /// @brief Specifies that the format is 48 bits per pixel; 16 bits each are used for the red, green, and blue components.
         format48bpp_rgb = 0x0010300C,
         /// @brief Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied according to the alpha component.
         format64bpp_pargb = 0x001C400E,
         /// @brief The default pixel format of 32 bits per pixel. The format specifies 24-bit color depth and an 8-bit alpha channel.
         canonical = 0x00200000,
         /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components.
         format32bpp_argb = 0x0026200A,
         /// @brief Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components.
         format64bpp_argb = 0x0034400D,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, pixel_format value) {return os << xtd::to_string(value, {{pixel_format::undefined, "undefined"}, {pixel_format::max, "max"}, {pixel_format::indexed, "indexed"}, {pixel_format::gdi, "gdi"}, {pixel_format::format16bpp_rgb555, "format16bpp_rgb555"}, {pixel_format::format16bpp_rgb565, "format16bpp_rgb565"}, {pixel_format::format24bpp_rgb, "format24bpp_rgb"}, {pixel_format::format32bpp_rgb, "format32bpp_rgb"}, {pixel_format::format1bpp_indexed, "format1bpp_indexed"}, {pixel_format::format4bpp_indexed, "format4bpp_indexed"}, {pixel_format::format8bpp_indexed, "format8bpp_indexed"}, {pixel_format::alpha, "alpha"}, {pixel_format::format16bpp_argb1555, "format16bpp_argb1555"}, {pixel_format::palpha, "palpha"}, {pixel_format::format32bpp_pargb, "format32bpp_pargb"}, {pixel_format::extended, "extended"}, {pixel_format::format16bpp_gray_scale, "format16bpp_gray_scale"}, {pixel_format::format48bpp_rgb, "format48bpp_rgb"}, {pixel_format::format64bpp_pargb, "format64bpp_pargb"}, {pixel_format::canonical, "canonical"}, {pixel_format::format32bpp_argb, "format32bpp_argb"}, {pixel_format::format64bpp_argb, "format64bpp_argb"}});}
      inline std::wostream& operator<<(std::wostream& os, pixel_format value) {return os << xtd::to_string(value, {{pixel_format::undefined, L"undefined"}, {pixel_format::max, L"max"}, {pixel_format::indexed, L"indexed"}, {pixel_format::gdi, L"gdi"}, {pixel_format::format16bpp_rgb555, L"format16bpp_rgb555"}, {pixel_format::format16bpp_rgb565, L"format16bpp_rgb565"}, {pixel_format::format24bpp_rgb, L"format24bpp_rgb"}, {pixel_format::format32bpp_rgb, L"format32bpp_rgb"}, {pixel_format::format1bpp_indexed, L"format1bpp_indexed"}, {pixel_format::format4bpp_indexed, L"format4bpp_indexed"}, {pixel_format::format8bpp_indexed, L"format8bpp_indexed"}, {pixel_format::alpha, L"alpha"}, {pixel_format::format16bpp_argb1555, L"format16bpp_argb1555"}, {pixel_format::palpha, L"palpha"}, {pixel_format::format32bpp_pargb, L"format32bpp_pargb"}, {pixel_format::extended, L"extended"}, {pixel_format::format16bpp_gray_scale, L"format16bpp_gray_scale"}, {pixel_format::format48bpp_rgb, L"format48bpp_rgb"}, {pixel_format::format64bpp_pargb, L"format64bpp_pargb"}, {pixel_format::canonical, L"canonical"}, {pixel_format::format32bpp_argb, L"format32bpp_argb"}, {pixel_format::format64bpp_argb, L"format64bpp_argb"}});}
      /// @endcond
    }
  }
}
