/// @file
/// @brief Contains xtd::drawing::image class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "drawing_2d/interpolation_mode.hpp"
#include "imaging/color_palette.hpp"
#include "imaging/encoder_parameters.hpp"
#include "imaging/frame_dimension.hpp"
#include "imaging/image_flags.hpp"
#include "imaging/image_format.hpp"
#include "imaging/pixel_format.hpp"
#include "imaging/property_item.hpp"
#include "graphics.hpp"
#include "graphics_unit.hpp"
#include "rectangle.hpp"
#include "rotate_flip_type.hpp"
#include "size.hpp"
#include "size_f.hpp"
#include <xtd/any_object>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class bitmap;
    namespace imaging::effects {
      struct resize_effect;
      struct scale_effect;
    }
    /// @endcond
    
    /// @brief An abstract base class that provides functionality for the bitmap and metafile descended classes.
    /// ```cpp
    /// class drawing_export_ image : public xtd::object, public xtd::iequatable<image>
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::drawing::image
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks To draw an image on a Windows Form, you should use one of the draw_image methods.
    class drawing_export_ image : public xtd::object, public xtd::iequatable<image> {
      struct data;
      
    public:
      /// @cond
      image();
      image(image&&) = default;
      image(const image& image) = default;
      image& operator =(const image& image) = default;
      ~image();
      /// @endcond
      
      /// @name Public Fields
      
      /// @{
      /// @brief Represent an empty xtd::drawing::image.
      static image empty;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the image alpha pointer, which represents the alpha data of the image.
      /// @return The pointer or alpha image.
      /// @remarks The size of this data is 1 byte (alpha) * height() * width().
      /// @remarks If the image has no handle, such as an empty image, this method returns nullptr.
      /// @warning Be careful when using this pointer as there is no control and you can exceed its size and create irreparable problems.
      /// @remarks To access the position of a specific pixel, it's best to use the xtd::drawing::image::get_pixel and xtd::drawing::image::set_pixel methods.
      [[nodiscard]] auto alpha() const -> const xtd::byte*;
      
      /// @brief Gets the image alpha pointer, which represents the alpha data of the image.
      /// @return The pointer or alpha image.
      /// @remarks The size of this data is 1 byte (alpha) * height() * width().
      /// @remarks If the image has no handle, such as an empty image, this method returns nullptr.
      /// @warning Be careful when using this pointer as there is no control and you can exceed its size and create irreparable problems.
      /// @remarks To access the position of a specific pixel, it's best to use the xtd::drawing::image::get_pixel and xtd::drawing::image::set_pixel methods.
      [[nodiscard]] auto alpha() -> xtd::byte*;
      
      /// @brief Gets attribute flags for the pixel data of this xtd::drawing::image.
      /// @return The integer representing a bitwise combination of xtd::drawing::imaging::image_flags for this xtd::drawing::image.
      /// @remarks The integer value returned from this method will correspond to a sum of image_flags, as described in the following table.
      /// | image_flag value                 | Integer representation |
      /// | -------------------------------- | ---------------------- |
      /// | image_flags_none                 | 0                      |
      /// | Iimage_flags_scalable            | 1                      |
      /// | Iimage_flags_has_alpha           | 2                      |
      /// | Iimage_flags_has_translucent     | 4                      |
      /// | Iimage_flags_partially_scalable  | 8                      |
      /// | Iimage_flags_color_space_rgb     | 16                     |
      /// | Iimage_flags_color_space_cmyk    | 32                     |
      /// | Iimage_flags_color_space_gray    | 64                     |
      /// | Iimage_flags_color_space_ycbr    | 128                    |
      /// | Iimage_flags_color_space_ycck    | 256                    |
      /// | Iimage_flags_has_real_dpi        | 4096                   |
      /// | Iimage_flags_has_real_pixel_size | 8192                   |
      /// | Iimage_flags_read_only           | 65536                  |
      /// | Iimage_flags_caching             | 131072                 |
      /// @remarks For example, if the Flags property for an image returned 77960, the image_flags for the image would be read_only, has_real_dpi, has_real_pixel_size, color_space_ycbcr, and partially_scalable.
      [[nodiscard]] auto flags() const noexcept -> xtd::int32;
      
      /// @brief Gets an array of GUIDs that represent the dimensions of frames within this image.
      /// @return An array of GUIDs that specify the dimensions of frames within this xtd::drawing::image from most significant to least significant.
      /// @remarks This method returns information about multiple-frame images, which come in two styles: multiple page and multiple resolution.
      /// @remarks A multiple-page image is an image that contains more than one image. Each page contains a single image (or frame). These pages (or images, or frames) are typically displayed in succession to produce an animated sequence, such as an animated .gif file.
      /// @remarks A multiple-resolution image is an image that contains more than one copy of an image at different resolutions. This is commonly used by MIP mapping where the displayed image size determines the resolution of the image used for drawing. GDI+ can support an arbitrary number of pages (or images, or frames), as well as an arbitrary number of resolutions. The defined dimensions are properties of the frame_dimension.
      [[nodiscard]] auto frame_dimentions_list() const noexcept -> xtd::array<guid>;
      
      /// @brief Gets the handle of this image.
      /// @return The handle of this image.
      [[nodiscard]] auto handle() const noexcept -> xtd::intptr;
      
      /// @brief Gets the height, in pixels, of this image.
      /// @return The height, in pixels, of this image.
      [[nodiscard]] auto height() const noexcept -> xtd::int32;
      
      /// @brief Gets the horizontal resolution, in pixels per inch, of this image.
      /// @return The horizontal resolution, in pixels per inch, of this image.
      [[nodiscard]] auto horizontal_resolution() const noexcept -> float;
      
      /// @brief Gets the color palette used for this image.
      /// @return An xtd::drawing::imaging::color_palette that represents the color palette used for this image.
      /// @remarks This property returns a copy of the xtd::drawing::imaging::color_palette object used by this xtd::drawing::image.
      [[nodiscard]] auto palette() const noexcept -> xtd::drawing::imaging::color_palette;
      /// @brief Sets the color palette used for this image.
      /// @param palette A color_palette that represents the color palette used for this image.
      auto palette(const xtd::drawing::imaging::color_palette& palette) noexcept -> void;
      
      /// @brief Gets the width and height of this image.
      /// @return A xtd::drawing::size_f structure that represents the width and height of this image.
      /// @remarks If the image is a bitmap, the width and height are returned in pixels. If the image is a metafile, the width and height are returned in 0.01 millimeter units.
      [[nodiscard]] auto physical_dimension() const noexcept -> const xtd::drawing::size_f&;
      
      /// @brief Gets the pixel format for this image.
      /// @return A pixel_format that represents the pixel format for this image.
      [[nodiscard]] auto pixel_format() const noexcept -> xtd::drawing::imaging::pixel_format;
      
      /// @brief Gets IDs of the property items stored in this image.
      /// @return An array of the property IDs, one for each property item stored in this image.
      /// @remarks If the image has no property items or if the image format does not support property items, the property_id_list property returns an empty array (that is, an array of length zero).
      [[nodiscard]] auto property_id_list() const noexcept -> const xtd::array<xtd::int32>&;
      
      /// @brief Gets all the property items (pieces of metadata) stored in this image.
      /// @return An array of xtd::drawing::imaging::property_item objects, one for each property item stored in the image.
      /// @remarks IIf the image has no property items or if the image format does not support property items, property_items returns an empty array (that is, an array of length zero).
      [[nodiscard]] auto property_items() const noexcept -> const xtd::array<xtd::drawing::imaging::property_item>&;
      
      /// @brief Gets the file format of this image.
      /// @return The image_format that represents the file format of this image.
      [[nodiscard]] auto raw_format() const noexcept -> const xtd::drawing::imaging::image_format&;
      
      /// @brief Gets the image data pointer, which represents the RGB data of the image.
      /// @return The pointer or data image.
      /// @remarks This is most often used when doing direct image manipulation. The return value points to an array of characters in RGBRGBRGB... format in the top-to-bottom, left-to-right order, that is the first RGB triplet corresponds to the first pixel of the first row, the second one — to the second pixel of the first row and so on until the end of the first row, with second row following after it and so on.
      /// @remarks The size of this data is 3 bytes (RGB) * height() * width().
      /// @remarks If the image has no handle, such as an empty image, this method returns nullptr.
      /// @warning Be careful when using this pointer as there is no control and you can exceed its size and create irreparable problems.
      /// @remarks To access the position of a specific pixel, it's best to use the xtd::drawing::image::get_pixel and xtd::drawing::image::set_pixel methods.
      [[nodiscard]] auto rgb() const -> const xtd::byte*;
      
      /// @brief Gets the image data pointer, which represents the RGB data of the image.
      /// @return The pointer or data image.
      /// @remarks This is most often used when doing direct image manipulation. The return value points to an array of characters in RGBRGBRGB... format in the top-to-bottom, left-to-right order, that is the first RGB triplet corresponds to the first pixel of the first row, the second one — to the second pixel of the first row and so on until the end of the first row, with second row following after it and so on.
      /// @remarks The size of this data is 3 bytes (RGB) * height() * width().
      /// @remarks If the image has no handle, such as an empty image, this method returns nullptr.
      /// @warning Be careful when using this pointer as there is no control and you can exceed its size and create irreparable problems.
      /// @remarks To access the position of a specific pixel, it's best to use the xtd::drawing::image::get_pixel and xtd::drawing::image::set_pixel methods.
      [[nodiscard]] auto rgb() -> xtd::byte*;
      
      /// @brief Gets the width and height, in pixels, of this image.
      /// @return A size structure that represents the width and height, in pixels, of this image.
      [[nodiscard]] auto size() const noexcept -> const xtd::drawing::size&;
      
      /// @brief Gets an object that provides additional data about the image.
      /// @return The object that provides additional data about the image.
      [[nodiscard]] auto tag() const noexcept -> const xtd::any_object&;
      /// @brief Sets an object that provides additional data about the image.
      /// @param tag The object that provides additional data about the image.
      auto tag(const xtd::any_object& tag) noexcept -> void;
      
      /// @brief Gets the vertical resolution, in pixels per inch, of this image.
      /// @return The vertical resolution, in pixels per inch, of this image.
      [[nodiscard]] auto vertical_resolution() const noexcept -> float;
      
      /// @brief Gets the width, in pixels, of this image.
      /// @return The width, in pixels, of this image.
      [[nodiscard]] auto width() const noexcept -> xtd::int32;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Creates an exact copy of this xtd::drawing::image.
      /// @return The xtd::drawing::image this method creates.
      [[nodiscard]] auto clone() const -> image;
      
      /// @brief Creates the xtd::drawing::graphics for the image.
      /// @return A xtd::drawing::graphics for the image.
      [[nodiscard]] auto create_graphics() -> xtd::drawing::graphics;
      
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override;
      /// @brief Indicates whether the current object is equal to another object of the same type.
      /// @param other An object to compare with this object.
      /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
      [[nodiscard]] auto equals(const image& other) const noexcept -> bool override;
      
      /// @brief Gets the bounds of the image in the specified unit.
      /// @param page_unit One of the xtd::drawing::graphics_unit values indicating the unit of measure for the bounding rectangle.
      /// @return The xtd::drawing::rectangle_f that represents the bounds of the image, in the specified unit.
      [[nodiscard]] auto get_bounds(xtd::drawing::graphics_unit page_unit) const noexcept -> xtd::drawing::rectangle_f;
      
      /// @brief Returns information about the parameters supported by the specified image encoder.
      /// @param guid A GUID that specifies the image encoder.
      /// @return An xtd::drawing::imaging::encoder_parameters that contains an array of xtd::drawing::imaging::encoder_parameter objects. Each xtd::drawing::imaging::encoder_parameter contains information about one of the parameters supported by the specified image encoder.
      [[nodiscard]] auto get_encoder_parameter_list(xtd::guid encoder) const noexcept -> xtd::drawing::imaging::encoder_parameters;
      
      /// @brief Returns the number of frames of the specified dimension.
      /// @param dimension A xtd::drawing::imaging::frame_dimension that specifies the identity of the dimension type.
      /// @return The number of frames in the specified dimension.
      /// @remarks This method returns information about multiple-frame images, which come in two styles: multiple page and multiple resolution.
      /// @remarks A multiple-page image is an image that contains more than one image. Each page contains a single image (or frame). These pages (or images, or frames) are typically displayed in succession to produce an animated sequence, such as an animated .gif file.
      /// @remarks A multiple-resolution image is an image that contains more than one copy of an image at different resolutions. This is commonly used by MIP mapping where the displayed image size determines the resolution of the image used for drawing. GDI+ can support an arbitrary number of pages (or images, or frames), as well as an arbitrary number of resolutions. The defined dimensions are properties of the xtd::drawing::imaging::frame_dimension.
      [[nodiscard]] auto get_frame_count(const xtd::drawing::imaging::frame_dimension& dimension) const -> xtd::usize;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      /// @brief Gets the specified property item from this xtd::drawing::image.
      /// @param propid The ID of the property item to get.
      /// @return The xtd::drawing::imaging::property_item this method gets.
      /// @exception xtd::argument_exception The image format of this image does not support property items.
      /// @remarks For a list of property item IDs and links to more information, see Id.
      /// @remarks It is difficult to set property items, because the xtd::drawing::imaging::property_item class has no public constructors. One way to work around this restriction is to obtain a xtd::drawing::imaging::property_item by retrieving the xtd::drawing::image::property_item property value or calling the xtd::drawing::image::get_property_item method of an xtd::drawing::image that already has property items. Then you can set the fields of the xtd::drawing::imaging::property_item and pass it to xtd::drawing::image::set_property_item.
      [[nodiscard]] auto get_property_item(int32 propid) -> xtd::drawing::imaging::property_item;
      
      /// @brief Returns a thumbnail for this xtd::drawing::image.
      /// @param thbmb_width The width, in pixels, of the requested thumbnail image.
      /// @param thum_height The height, in pixels, of the requested thumbnail image.
      /// @return An xtd::drawing::image that represents the thumbnail.
      /// @remarks If the xtd::drawing::image contains an embedded thumbnail image, this method retrieves the embedded thumbnail and scales it to the requested size. If the xtd::drawing::image does not contain an embedded thumbnail image, this method creates a thumbnail image by scaling the main image.
      /// @remarks The xtd::drawing::image::get_thumbnail_image method works well when the requested thumbnail image has a size of about 120 x 120 pixels. If you request a large thumbnail image (for example, 300 x 300) from an xtd::drawing::image that has an embedded thumbnail, there could be a noticeable loss of quality in the thumbnail image. It might be better to scale the main image (instead of scaling the embedded thumbnail) by calling the xtd::drawing::graphics::draw_image method.
      [[nodiscard]] auto get_thmbnail_image(int32 thumb_width, int32 thunb_height) noexcept -> xtd::drawing::image;
      
      /// @brief Rotates, flips, or rotates and flips the xtd::drawing::image.
      /// @param rotate_flip_type A xtd::drawing::rotate_flip_type member that specifies the type of rotation and flip to apply to the image.
      /// @remarks The xtd::drawing::image::rotate_flip method rotates the image clockwise.
      /// @remarks If you wish to draw on an image once it has been rotated, you should always retrieve a new graphics object from the image, otherwise an exception could occur.
      auto rotate_flip(xtd::drawing::rotate_flip_type rotate_flip_type) -> void;
      
      /// @brief Saves this xtd::drawing::image to the specified file or stream.
      /// @param filename A string that contains the name of the file to which to save this xtd::drawing::image.
      /// @remarks If no encoder exists for the file format of the image, the Portable Network Graphics (PNG) encoder is used. When you use the xtd::drawing::image::save method to save a graphic image as a Windows Metafile Format (WMF) or Enhanced Metafile Format (EMF) file, the resulting file is saved as a Portable Network Graphics (PNG) file. This behavior occurs because the GDI+ component of the .NET Framework does not have an encoder that you can use to save files as .wmf or .emf files.
      /// @remarks Saving the image to the same file it was constructed from is not allowed and throws an exception.
      auto save(const xtd::string& filename) const -> void;
      /// @brief Saves this xtd::drawing::image to the specified file in the specified format.
      /// @param filename A string that contains the name of the file to which to save this xtd::drawing::image.
      /// @param format The xtd::drawing::imaging::image_format for this xtd::drawing::image.
      auto save(const xtd::string& filename, const xtd::drawing::imaging::image_format& format) const -> void;
      /// @brief Saves this image to the specified stream in the specified format.
      /// @param stream The std::otream where the image will be saved.
      /// @param format The xtd::drawing::imaging::image_format for this xtd::drawing::image.
      /// @remarks You should avoid saving an image to the same stream that was used to construct it. Doing so might damage the stream.
      /// @remarks The image must be saved to the stream at an offset of zero. If any additional data has been written to the stream before saving the image, the image data in the stream will be corrupted.
      auto save(std::ostream& stream, const xtd::drawing::imaging::image_format& format) const -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates an image from the specified file.
      /// @param filename A string that contains the name of the file from which to create the image.
      /// @return The xtd::drawing::image this method creates.
      [[nodiscard]] static auto from_file(const xtd::string& filename) -> image;
      
      /// @brief Creates a xtd::drawing::bitmap from a handle to a GDI bitmap.
      /// @param hbitmap The GDI bitmap handle from which to create the xtd::drawing::bitmap.
      /// @return The xtd::drawing::bitmap this method creates.
      /// @remarks The xtd::drawing::image::from_hbitmap method makes a copy of the GDI bitmap; so you can release the incoming GDI bitmap using the GDI DeleteObject method immediately after creating the new xtd::drawing::image.
      [[nodiscard]] static auto from_hbitmap(xtd::intptr hbitmap) -> bitmap;
      
      /// @brief Creates an xtd::drawing::image from the specified data stream.
      /// @param stream A std::istream that contains the data for this xtd::drawing::image.
      /// @return The xtd::drawing::image this method creates.
      /// @remarks You must keep the stream open for the lifetime of the xtd::drawing::image.
      /// @note The xtd::drawing::image class does not support alpha transparency in bitmaps. To enable alpha transparency, use PNG images with 32 bits per pixel.
      [[nodiscard]] static auto from_stream(std::istream& stream) -> image;
      
      /// @brief Creates an xtd::drawing::image from the specified data pointer, width and hieght.
      /// @param data A pointer that contains the data for the xtd::drawing::image.
      /// @param width The width for the xtd::drawing::image.
      /// @param height The height for the xtd::drawing::image.
      /// @return The xtd::drawing::image this method creates.
      /// @remarks This method is used for creating a xtd::drawing::image from an XBM image.
      /// @note Use xtd::drawing::image::from_file instead xtd::drawing::image::from_xbm_data.
      [[nodiscard]] static auto from_xbm_data(const unsigned char* bits, int32 width, int32 height) -> bitmap;
      
      /// @brief Creates an xtd::drawing::image from the specified data pointer.
      /// @param data A pointer that contains the data for the xtd::drawing::image.
      /// @return The xtd::drawing::image this method creates.
      /// @remarks This method is used for creating a xtd::drawing::image from an XPM image.
      /// @note Use xtd::drawing::image::from_file instead xtd::drawing::image::from_xpm_data.
      [[nodiscard]] static auto from_xpm_data(const char* const* bits) -> bitmap;
      
      /// @brief Returns the color depth, in number of bits per pixel, of the specified pixel format.
      /// @param pixfmt The xtd::drawing::imaging::pixel_format member that specifies the format for which to find the size.
      /// @return The color depth of the specified pixel format.
      [[nodiscard]] static auto get_pixel_format_size(xtd::drawing::imaging::pixel_format pixfmt) noexcept -> xtd::int32;
      
      /// @brief Returns a value that indicates whether the pixel format for this xtd::drawing::image contains alpha information.
      /// @param pixfmt The PixelFormat to test.
      /// @return `true` if pixfmt contains alpha information; otherwise, `false`.
      [[nodiscard]] static auto is_alpha_pixel_format(xtd::drawing::imaging::pixel_format pixfmt) noexcept -> bool;
      
      /// @brief Returns a value that indicates whether the pixel format is 32 bits per pixel.
      /// @param pixfmt The PixelFormat to test.
      /// @return `true` if pixfmt is canonical; otherwise, `false`.
      [[nodiscard]] static auto is_canonical_pixel_format(xtd::drawing::imaging::pixel_format pixfmt) noexcept -> bool;
      
      /// @brief Returns a value that indicates whether the pixel format is 64 bits per pixel.
      /// @param pixfmt The PixelFormat to test.
      /// @return `true` if pixfmt is extended; otherwise, `false`.
      [[nodiscard]] static auto is_extended_pixel_format(xtd::drawing::imaging::pixel_format pixfmt) noexcept -> bool;
      /// @}
      
    protected:
      /// @cond
      friend xtd::drawing::imaging::effects::resize_effect;
      friend xtd::drawing::imaging::effects::scale_effect;
      explicit image(xtd::intptr hbitmap);
      explicit image(const xtd::string& filename);
      explicit image(const xtd::string& filename, bool use_icm);
      explicit image(std::istream& stream);
      explicit image(std::istream& stream, bool use_icm);
      image(xtd::int32 width, xtd::int32 height);
      image(xtd::int32 width, xtd::int32 height, float horizontal_resolution, float vertical_resolution);
      image(xtd::int32 width, xtd::int32 height, xtd::drawing::imaging::pixel_format format);
      image(xtd::int32 width, xtd::int32 height, xtd::int32 stride, xtd::drawing::imaging::pixel_format format, xtd::intptr scan0);
      image(const image& image, xtd::int32 width, xtd::int32 height);
      image(const image& image, const xtd::drawing::rectangle& rect);
      [[nodiscard]] static auto from_hicon(xtd::intptr hicon) -> image;
      [[nodiscard]] auto get_pixel(xtd::int32 x, xtd::int32 y) const -> xtd::drawing::color;
      auto resize(const xtd::drawing::rectangle& rect, const xtd::drawing::color& fill_color) -> void;
      auto scale(const xtd::drawing::size& size, xtd::drawing::drawing_2d::interpolation_mode interpolation_mode) -> void;
      auto set_pixel(xtd::int32 x, xtd::int32 y, const xtd::drawing::color& color) -> void;
      auto set_pixel_format(xtd::drawing::imaging::pixel_format value) -> void;
      /// @endcond
      
    private:
      auto update_properties() -> void;
      
      xtd::sptr<data> data_;
    };
  }
}

#include "../literals/system_images.hpp"
