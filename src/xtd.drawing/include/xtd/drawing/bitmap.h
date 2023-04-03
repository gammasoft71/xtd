/// @file
/// @brief Contains xtd::drawing::bitmap class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "image.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Encapsulates a GDI+ bitmap, which consists of the pixel data for a graphics image and its attributes. A bitmap is an object used to work with images defined by pixel data.
    /// @code
    /// class drawing_export_ bitmap : public xtd::drawing::image
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::image → xtd::drawing::bitmap
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks To draw an image on a Windows Form, you should use one of the draw_image methods.
    class drawing_export_ bitmap : public xtd::drawing::image {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Represent an empty bitmap.
      static bitmap empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the bitmap class from the specified existing image.
      /// @param original The xtd::drawing::image from which to create the new bitmap.
      explicit bitmap(const image& original);
      /// @brief Initializes a new instance of the bitmap class from the specified existing image, scaled to the specified size.
      /// @param original The xtd::drawing::image from which to create the new bitmap.
      /// @param new_size The xtd::drawing::size structure that represent the size of the new bitmap.
      bitmap(const image& original, const xtd::drawing::size& new_size);
      /// @brief Initializes a new instance of the bitmap class from the specified existing image, scaled to the specified size.
      /// @param original The xtd::drawing::image from which to create the new bitmap.
      /// @param width The width, in pixels, of the new xtd::drawing::bitmap.
      /// @param height The height, in pixels, of the new xtd::drawing::bitmap.
      bitmap(const image& original, int32 width, int32 height);
      /// @brief Initializes a new instance of the bitmap class from the specified existing image, scaled to the specified rectangle.
      /// @param original The xtd::drawing::image from which to create the new bitmap.
      /// @param new_rect The xtd::drawing::rect structure that represent the location and size of the new bitmap.
      bitmap(const image& original, const rectangle& new_rect);
      /// @brief Initializes a new instance of the bitmap class from the specified file.
      /// @param filename The bitmap file name and path.
      /// @remarks The file name and path can be relative to the application or an absolute path. Use this constructor to open images with the following file formats: BMP, GIF, EXIF, JPG, PNG and TIFF. For more information about supported formats, see Types of Bitmaps. The file remains locked until the xtd::drawing::bitmap is disposed.
      explicit bitmap(const xtd::ustring& filename);
      /// @brief Initializes a new instance of the bitmap class from the specified file.
      /// @param filename The bitmap file name and path.
      /// @param use_icm true to use color correction for this xtd::drawing::bitmap; otherwise, false.
      /// @remarks The file name and path can be relative to the application or an absolute path. Use this constructor to open images with the following file formats: BMP, GIF, EXIF, JPG, PNG and TIFF. For more information about supported formats, see Types of Bitmaps. The file remains locked until the xtd::drawing::bitmap is disposed.
      explicit bitmap(const xtd::ustring& filename, bool use_icm);
      /// @brief Initializes a new instance of the bitmap class from the specified data stream.
      /// @param stream The data stream used to load the image.
      /// @remarks You must keep the stream open for the lifetime of the xtd::drawing::bitmap.
        explicit bitmap(std::istream& stream);
      /// @brief Initializes a new instance of the bitmap class from the specified data stream.
      /// @param stream The data stream used to load the image.
      /// @param use_icm true to use color correction for this xtd::drawing::bitmap; otherwise, false.
      /// @remarks You must keep the stream open for the lifetime of the xtd::drawing::bitmap.
      /// @remarks Due to a limitation of the GDI+ decoder, an xtd::argument_exception is thrown if you construct a bitmap from a .png image file with a single dimension greater than 65,535 pixels.
      explicit bitmap(std::istream& stream, bool use_icm);
      /// @brief Initializes a new instance of the bitmap class from the specified data xpm.
      /// @param bits The data xpm used to load the image.
      explicit bitmap(const char* const* bits);
      /// @brief Initializes a new instance of the xtd::drawing::bitmap class with the specified size.
      /// @param width The width, in pixels, of the new bitmap.
      /// @param height The height, in pixels, of the new bitmap.
      bitmap(int32 width, int32 height);
      /// @brief Initializes a new instance of the xtd::drawing::bitmap class with the specified size.
      /// @param width The width, in pixels, of the new bitmap.
      /// @param height The height, in pixels, of the new bitmap.
      /// @param format The pixel format for the new xtd::drawing::bitmap class with the specified size and format.
      bitmap(int32 width, int32 height, xtd::drawing::imaging::pixel_format format);
      /// @brief Initializes a new instance of the xtd::drawing::bitmap class with the specified size.
      /// @param size the size, in pixels, of the new bitmap.
      explicit bitmap(const xtd::drawing::size& size);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Creates a copy of the section of this xtd::drawing::bitmap defined with a specified rectangle.
      /// @param rect Defines the portion of this bitmap to copy.
      bitmap clone(const rectangle& rect) const;
      /// @brief Creates a copy of the section of this xtd::drawing::bitmap defined with a specified rectangle.
      /// @param rect Defines the portion of this bitmap to copy.
      bitmap clone(const rectangle_f& rect) const;
      
      /// @cond
      bitmap(const bitmap& bitmap) = default;
      bitmap& operator =(const bitmap& bitmap) = default;
      /// @endcond
      
      /// @brief Gets the color of the specified pixel in this bitmap.
      /// @param x The x-coordinate of the pixel to retrieve.
      /// @param y The y-coordinate of the pixel to retrieve.
      /// @return A xtd::drawing::color structure that represents the color of the specified pixel.
      drawing::color get_pixel(int32 x, int32 y)  const;
      
      /// @brief Sets the color of the specified pixel in this bitmap.
      /// @param x The x-coordinate of the pixel to retrieve.
      /// @param y The y-coordinate of the pixel to retrieve.
      /// @param color A xtd::drawing::color structure that represents the color of the specified pixel.
      void set_pixel(int32 x, int32 y, const drawing::color& color);
      /// @}
      
    private:
      bitmap() = default;
    };
  }
}
