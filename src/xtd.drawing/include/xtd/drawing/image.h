/// @file
/// @brief Contains xtd::drawing::image class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <cstdint>
#include <memory>
#include <iostream>
#include <string>
#include "../drawing_export.h"
#include "imaging/color_palette.h"
#include "imaging/frame_dimension.h"
#include "imaging/image_flags.h"
#include "imaging/image_format.h"
#include "imaging/pixel_format.h"
#include "imaging/property_item.h"
#include "graphics.h"
#include "rectangle.h"
#include "size.h"
#include "size_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief An abstract base class that provides functionality for the bitmap and metafile descended classes.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks To draw an image on a Windows Form, you should use one of the draw_image methods.
    class drawing_export_ image {
    public:
      /// @cond
      image() = default;
      image(const image& image) = default;
      image& operator=(const image& image) = default;
      virtual ~image();
      bool operator==(const image& image) const {return data_->handle_ == image.data_->handle_;}
      bool operator!=(const image& image) const {return !operator==(image);}
      /// @endcond
      
      /// @brief Gets attribute flags for the pixel data of this Image.
      /// @return The integer representing a bitwise combination of image_flags for this Image.
      /// @remarks The integer value returned from this method will correspond to a sum of image_flags, as described in the following table.
      /// | image_flag value                 | Integer representation |
      /// |----------------------------------|------------------------|
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
      int32_t flags() const {return static_cast<int32_t>(data_->flags_);}
      
      /// @brief Gets an array of GUIDs that represent the dimensions of frames within this image.
      /// @return An array of GUIDs that specify the dimensions of frames within this Image from most significant to least significant.
      /// @remarks This method returns information about multiple-frame images, which come in two styles: multiple page and multiple resolution.
      /// @remarks A multiple-page image is an image that contains more than one image. Each page contains a single image (or frame). These pages (or images, or frames) are typically displayed in succession to produce an animated sequence, such as an animated .gif file.
      /// @remarks A multiple-resolution image is an image that contains more than one copy of an image at different resolutions. This is commonly used by MIP mapping where the displayed image size determines the resolution of the image used for drawing. GDI+ can support an arbitrary number of pages (or images, or frames), as well as an arbitrary number of resolutions. The defined dimensions are properties of the frame_dimension.
      const std::vector<guid>& frame_dimentions_list() const {return data_->frame_dimentions_list_;}
      
      /// @brief Get the handle of this image.
      /// @return The handle of this image.
      intptr_t handle() const {return data_->handle_;}
      
      /// @brief Gets the height, in pixels, of this image.
      /// @return The height, in pixels, of this image.
      int32_t height() const {return data_->size_.height();}
      
      /// @brief Gets the horizontal resolution, in pixels per inch, of this image.
      /// @return The horizontal resolution, in pixels per inch, of this image.
      float horizontal_resolution() const {return data_->horizontal_resolution_;}
      
      /// @brief Gets the color palette used for this image.
      /// @return A color_palette that represents the color palette used for this image.
      /// @remarks This property returns a copy of the color_palette object used by this Image.
      imaging::color_palette palette() const {return data_->palette_;}
      /// @brief Sets the color palette used for this image.
      /// @param palette A color_palette that represents the color palette used for this image.
      void palette(const imaging::color_palette& palette) {data_->palette_ = palette;}

      /// @brief Gets the width and height of this image.
      /// @return A SizeF structure that represents the width and height of this image.
      /// @remarks If the image is a bitmap, the width and height are returned in pixels. If the image is a metafile, the width and height are returned in 0.01 millimeter units.
      const size_f& physical_dimension() const {return data_->physical_dimension_;}
      
      /// @brief Gets the pixel format for this image.
      /// @return A pixel_format that represents the pixel format for this image.
      imaging::pixel_format pixel_format() const {return data_->pixel_format_;}
      
      /// @brief Gets IDs of the property items stored in this image.
      /// @return An array of the property IDs, one for each property item stored in this image.
      /// @remarks If the image has no property items or if the image format does not support property items, the property_id_list property returns an empty array (that is, an array of length zero).
      const std::vector<int32_t>& property_id_list() const {return data_->property_id_list_;}
      
      /// @brief Gets all the property items (pieces of metadata) stored in this image.
      /// @return An array of PropertyItem objects, one for each property item stored in the image.
      /// @remarks IIf the image has no property items or if the image format does not support property items, property_items returns an empty array (that is, an array of length zero).
      const std::vector<imaging::property_item>& property_items() const {return data_->property_ityems_;}
      
      /// @brief Gets the file format of this image.
      /// @return The image_format that represents the file format of this image.
      const imaging::image_format& raw_format() const {return data_->raw_format_;}
      
      /// @brief Gets the width and height, in pixels, of this image.
      /// @return A size structure that represents the width and height, in pixels, of this image.
      const drawing::size& size() const {return data_->size_;}
      
      /// @brief Gets an object that provides additional data about the image.
      /// @return The object that provides additional data about the image.
      const std::any& tag() const {return data_->tag_;}
      /// @brief Sets an object that provides additional data about the image.
      /// @param tag The object that provides additional data about the image.
      void tag(const std::any& tag) {data_->tag_ = tag;}
      
      /// @brief Gets the vertical resolution, in pixels per inch, of this image.
      /// @return The vertical resolution, in pixels per inch, of this image.
      float vertical_resolution() const {return data_->vertical_resolution_;}

      /// @brief Gets the width, in pixels, of this image.
      /// @return The width, in pixels, of this image.
      int32_t width() const {return data_->size_.width();}
  
      /// @brief Creates the xtd::drawing::graphics for the image.
      /// @return A xtd::drawing::graphics for the image.
      /// @ingroup drawing
      graphics create_graphics() {return graphics::from_image(*this);}

      static image from_hbitmap(intptr_t hbitmap) {return image(hbitmap);}

      /// @brief Creates an image from the specified file.
      /// @param filename A string that contains the name of the file from which to create the image.
      /// @return The Image this method creates.
      static image from_file(const std::string& filename) {return image(filename);}

      static image from_stream(std::istream& stream) {return image(stream);}

      static image from_data(const char* const* bits) {return image(bits);}
      
      void save(const std::string& filename) const;
      void save(const std::string& filename, const imaging::image_format& format) const;
      void save(std::ostream& stream, const imaging::image_format& format) const;

      static image empty;
      
    protected:
      explicit image(intptr_t hbitmap);
      explicit image(const std::string& fileName);
      explicit image(std::istream& stream);
      explicit image(const char* const* bits);
      image(int32_t width, int32_t height);
      image(const image& image, int32_t width, int32_t height);
      image(const image& image, const rectangle& rect);
      void update_properties();

      struct data {
        imaging::image_flags flags_ = imaging::image_flags::none;
        std::vector<guid> frame_dimentions_list_;
        intptr_t handle_ = 0;
        float horizontal_resolution_ = .0f;
        imaging::color_palette palette_;
        imaging::pixel_format pixel_format_ = imaging::pixel_format::undefined;
        size_f physical_dimension_;
        std::vector<int32_t> property_id_list_;
        std::vector<imaging::property_item> property_ityems_;
        imaging::image_format raw_format_;
        drawing::size size_;
        std::any tag_;
        float vertical_resolution_ = .0f;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
