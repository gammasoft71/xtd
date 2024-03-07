/// @file
/// @brief Contains xtd::drawing::bitmap class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "imaging/bitmap_data.h"
#include "imaging/image_lock_mode.h"
#include "image.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
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
    /// @ingroup xtd_drawing images
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
      /// @brief Initializes a new instance of the xtd::drawing::bitmap class with the specified size and with the resolution of the specified xtd::drawing::raphics object.
      /// @param width The width, in pixels, of the new bitmap.
      /// @param height The height, in pixels, of the new bitmap.
      /// @param g The Graphics object that specifies the resolution for the new Bitmap.
      /// @remarks The new xtd::drawing::bitmap that this method creates takes its horizontal and vertical resolution from the xtd::drawing::graphics::dpi_x and xtd::drawing::graphics::dpi_y properties of g, respectively.
      bitmap(int32 width, int32 height, const graphics& g);
      /// @brief Initializes a new instance of the xtd::drawing::bitmap class with the specified size.
      /// @param width The width, in pixels, of the new bitmap.
      /// @param height The height, in pixels, of the new bitmap.
      /// @param format The pixel format for the new xtd::drawing::bitmap class with the specified size and format.
      bitmap(int32 width, int32 height, xtd::drawing::imaging::pixel_format format);
      /// @brief Initializes a new instance of the xtd::drawing::bitmap class with the specified size.
      /// @param width The width, in pixels, of the new bitmap.
      /// @param height The height, in pixels, of the new bitmap.
      /// @param stride Integer that specifies the byte offset between the beginning of one scan line and the next. This is usually (but not necessarily) the number of bytes in the pixel format (for example, 2 for 16 bits per pixel) multiplied by the width of the bitmap. The value passed to this parameter must be a multiple of four.
      /// @param format The pixel format for the new xtd::drawing::bitmap class with the specified size and format.
      /// @param scan0 Pointer to an array of bytes that contains the pixel data.
      bitmap(int32 width, int32 height, int32 stride, xtd::drawing::imaging::pixel_format format, intptr scan0);
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
      
      /// @brief Creates a GDI bitmap object from this xtd::drawing::bitmap.
      /// @return A handle to the GDI bitmap object that this method creates.
      /// @remarks You are responsible for calling the GDI DeleteObject method to free the memory used by the GDI bitmap object. For more information about GDI bitmaps, see <a href=https://go.microsoft.com/fwlink/?LinkId=205685>Bitmaps</a> in the Windows GDI documentation.
      intptr get_hbitmap() const;
      
      /// @brief Creates a GDI bitmap object from this xtd::drawing::bitmap.
      /// @param background A xtd::drawing::color structure that specifies the background color. This parameter is ignored if the bitmap is totally opaque.
      /// @return A handle to the GDI bitmap object that this method creates.
      /// @remarks You are responsible for calling the GDI DeleteObject method to free the memory used by the GDI bitmap object. For more information about GDI bitmaps, see <a href=https://go.microsoft.com/fwlink/?LinkId=205685>Bitmaps</a> in the Windows GDI documentation.
      intptr get_hbitmap(const color& background) const;
      
      /// @brief Returns the handle to an icon.
      /// @return A Windows handle to an icon with the same image as the xtd::drawing::bitmap.
      /// @remarks Initially, an icon created from the handle will have the same size as the original bitmap.
      intptr get_hicon() const;
      
      /// @brief Gets the color of the specified pixel in this bitmap.
      /// @param x The x-coordinate of the pixel to retrieve.
      /// @param y The y-coordinate of the pixel to retrieve.
      /// @return A xtd::drawing::color structure that represents the color of the specified pixel.
      drawing::color get_pixel(int32 x, int32 y)  const;
      
      /// @brief Locks a xtd::drawing::bitmap into system memory.
      /// @param rect A xtd::drawing::rectangle structure that specifies the portion of the xtd::drawing::bitmap to lock.
      /// @param flags An xtd::drawing::imaging::image_lock_mode enumeration that specifies the access level (read/write) for the xtd::drawing::bitmap.
      /// @param format A xtd::drawing::imaging::pixel_format enumeration that specifies the data format of this xtd::drawing::bitmap.
      /// @return A xtd::drawing::imaging::bitmap_data that contains information about this lock operation.
      /// @remarks Use the xtd::drawing::bitmap::lock_bits method to lock an existing bitmap in system memory so that it can be changed programmatically. You can change the color of an image with the xtd::drawing::bitmap::set_pixel method, although the xtd::drawing::bitmap::lock_bits method offers better performance for large-scale changes.
      /// @remarks The xtd::drawing::imaging::bitmap_data specifies the attributes of the xtd::drawing::bitmap, such as size, pixel format, the starting address of the pixel data in memory, and length of each scan line (stride).
      /// @remarks When calling this method, you should use a member of the xtd::drawing::imaging::pixel_format enumeration that contains a specific bits-per-pixel (BPP) value. Using xtd::drawing::imaging::pixel_format values such as xtd::drawing::imaging::pixel_format::indexed and xtd::drawing::imaging::pixel_format::gdi will throw an xtd::argument_exception. Also, passing the incorrect pixel format for a bitmap will throw an xtd::argument_exception.
      xtd::drawing::imaging::bitmap_data lock_bits(const rectangle& rect, xtd::drawing::imaging::image_lock_mode flags, xtd::drawing::imaging::pixel_format format);
      /// @brief Locks a xtd::drawing::bitmap into system memory.
      /// @param rect A xtd::drawing::rectangle structure that specifies the portion of the xtd::drawing::bitmap to lock.
      /// @param flags An xtd::drawing::imaging::image_lock_mode enumeration that specifies the access level (read/write) for the xtd::drawing::bitmap.
      /// @param format A xtd::drawing::imaging::pixel_format enumeration that specifies the data format of this xtd::drawing::bitmap.
      /// @param data A xtd::drawing::imaging::bitmap_data that contains information about the lock operation.
      /// @return A xtd::drawing::imaging::bitmap_data that contains information about this lock operation.
      /// @remarks Use the xtd::drawing::bitmap::lock_bits method to lock an existing bitmap in system memory so that it can be changed programmatically. You can change the color of an image with the xtd::drawing::bitmap::set_pixel method, although the xtd::drawing::bitmap::lock_bits method offers better performance for large-scale changes.
      /// @remarks The xtd::drawing::imaging::bitmap_data specifies the attributes of the xtd::drawing::bitmap, such as size, pixel format, the starting address of the pixel data in memory, and length of each scan line (stride).
      /// @remarks When calling this method, you should use a member of the xtd::drawing::imaging::pixel_format enumeration that contains a specific bits-per-pixel (BPP) value. Using xtd::drawing::imaging::pixel_format values such as xtd::drawing::imaging::pixel_format::indexed and xtd::drawing::imaging::pixel_format::gdi will throw an xtd::argument_exception. Also, passing the incorrect pixel format for a bitmap will throw an xtd::argument_exception.
      xtd::drawing::imaging::bitmap_data lock_bits(const rectangle& rect, xtd::drawing::imaging::image_lock_mode flags, xtd::drawing::imaging::pixel_format format, const xtd::drawing::imaging::bitmap_data& data);
      
      /// @brief Makes the default transparent color transparent for this xtd::drawing::bitmap.
      /// @remarks The system palette defines one color as the default transparent, or alpha, color. This method makes the default transparent color transparent for this xtd::drawing::bitmap. If no transparent color is specified by the system, xtd::drawing::color::light_gray is the transparent color.
      /// @remarks When you call xtd::drawing::bitmap::make_transparent, the bitmap will be converted to the xtd::drawing::imaging::pixel_format::format_32bpp_argb format, as this format supports an alpha channel.
      void make_transparent();
      /// @brief Makes the specified color transparent for this xtd::drawing::bitmap.
      /// @param transprent_color The xtd::drawing::color structure that represents the color to make transparent.
      /// @remarks When you call xtd::drawing::bitmap::make_transparent, the bitmap will be converted to the xtd::drawing::imaging::pixel_format::format_32bpp_argb format, as this format supports an alpha channel.
      void make_transparent(const color& transparent_color);
      
      /// @brief Sets the color of the specified pixel in this xtd::drawing::bitmap.
      /// @param x The x-coordinate of the pixel to retrieve.
      /// @param y The y-coordinate of the pixel to retrieve.
      /// @param color A xtd::drawing::color structure that represents the color of the specified pixel.
      void set_pixel(int32 x, int32 y, const drawing::color& color);
      
      /// @brief Sets the resolution for this xtd::drawing::bitmap.
      /// @param x_dpi The horizontal resolution, in dots per inch, of the xtd::drawing::bitmap.
      /// @param y_dpi The vertical resolution, in dots per inch, of the xtd::drawing::bitmap.
      /// @remarks Use this method to set the desired resolution on a newly created bitmap. Changing the resolution of the image does not change its physical size.
      void set_resolution(int32 x_dpi, int32 y_dpi);
      
      /// @brief Unlocks this xtd::drawing::bitmap from system memory.
      /// @param data A xtd::drawing::imaging::bitmap_data that specifies information about the lock operation.
      /// @remarks The xtd::drawing::imaging::bitmap_data specifies the attributes of the xtd::drawing::bitmap, such as size, pixel format, the starting address of the pixel data in memory, and length of each scan line (stride).
      void unlock_bits(const xtd::drawing::imaging::bitmap_data& data);
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief Creates a xtd::drawing::bitmap from a Windows handle to an icon.
      /// @param hicon A handle to an icon.
      /// @return The xtd::drawing::bitmap that this method creates.
      static bitmap from_hicon(intptr icon);
      /// @}

    private:
      bitmap() = default;
    };
  }
}
