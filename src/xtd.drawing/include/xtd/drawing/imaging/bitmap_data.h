/// @file
/// @brief Contains xtd::drawing::imaging::bitmap_data class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "pixel_format"
#include <xtd/object>
#include <xtd/types>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The bitmap_data class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Specifies the attributes of a bitmap image. The xtd::drawing::imaging::bitmap_data class is used by the xtd::drawing::bitmap::lock_bits and xtd::drawing::bitmap::unlock_bits methods of the xtd::drawing::bitmap class. Not inheritable.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      class bitmap_data final : public object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::imaging::bitmap_data class.
        bitmap_data() = default;
        /// @}
        
        /// @cond
        bitmap_data(const bitmap_data&) = default;
        bitmap_data& operator =(const bitmap_data&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the pixel height of the xtd::drawing::bitmap object. Also sometimes referred to as the number of scan lines.
        /// @return The pixel height of the xtd::drawing::bitmap object.
        int32 height() const noexcept;
        /// @brief Sets the pixel height of the xtd::drawing::bitmap object. Also sometimes referred to as the number of scan lines.
        /// @param value The pixel height of the xtd::drawing::bitmap object.
        /// @return This current instance.
        bitmap_data& height(int32 value) noexcept;
        
        /// @brief Gets the format of the pixel information in the xtd::drawing::bitmap object that returned this xtd::drawing::imaging::bitmap_data object.
        /// @return A xtd::drawing::imaging::pixel_format that specifies the format of the pixel information in the associated xtd::drawing::bitmap object.
        /// @remarks The format defines how many bits of memory are needed to store the color information for a single pixel.
        xtd::drawing::imaging::pixel_format pixel_format() const noexcept;
        /// @brief Sets the format of the pixel information in the xtd::drawing::bitmap object that returned this xtd::drawing::imaging::bitmap_data object.
        /// @param value A xtd::drawing::imaging::pixel_format that specifies the format of the pixel information in the associated xtd::drawing::bitmap object.
        /// @return This current instance.
        /// @remarks The format defines how many bits of memory are needed to store the color information for a single pixel.
        bitmap_data& pixel_format(xtd::drawing::imaging::pixel_format value) noexcept;
        
        /// @brief Reserved. Do not use.
        /// @return Reserved. Do not use.
        int32 reserved() const noexcept;
        /// @brief Reserved. Do not use.
        /// @param value Reserved. Do not use.
        /// @return This current instance.
        bitmap_data& reserved(int32 value) noexcept;
        
        /// @brief Gets or sets the address of the first pixel data in the bitmap. This can also be thought of as the first scan line in the bitmap.
        /// @return The address of the first pixel data in the bitmap.
        intptr scan0() const noexcept;
        /// @brief Sets or sets the address of the first pixel data in the bitmap. This can also be thought of as the first scan line in the bitmap.
        /// @param value The address of the first pixel data in the bitmap.
        /// @return This current instance.
        bitmap_data& scan0(intptr value) noexcept;
        
        /// @brief Gets the stride width (also called scan width) of the xtd::drawing::bitmap object.
        /// @return The stride width, in bytes, of the xtd::drawing::bitmap object.
        /// @remarks The stride is the width of a single row of pixels (a scan line), rounded up to a four-byte boundary. If the stride is positive, the bitmap is top-down. If the stride is negative, the bitmap is bottom-up.
        int32 stride() const noexcept;
        /// @brief Sets the stride width (also called scan width) of the xtd::drawing::bitmap object.
        /// @param value The stride width, in bytes, of the xtd::drawing::bitmap object.
        /// @return This current instance.
        /// @remarks The stride is the width of a single row of pixels (a scan line), rounded up to a four-byte boundary. If the stride is positive, the bitmap is top-down. If the stride is negative, the bitmap is bottom-up.
        bitmap_data& stride(int32 value) noexcept;
        
        /// @brief Gets or sets the pixel width of the xtd::drawing::bitmap object. This can also be thought of as the number of pixels in one scan line.
        /// @return The pixel width of the xtd::drawing::bitmap object.
        int32 width() const noexcept;
        /// @brief Sets or sets the pixel width of the xtd::drawing::bitmap object. This can also be thought of as the number of pixels in one scan line.
        /// @param value The pixel width of the xtd::drawing::bitmap object.
        /// @return This current instance.
        bitmap_data& width(int32 value) noexcept;
        /// @}
        
      private:
        int32 height_ = 0;
        xtd::drawing::imaging::pixel_format pixel_format_ = xtd::drawing::imaging::pixel_format::undefined;
        int32 reserved_ = 0;
        intptr scan0_ = 0;
        int32 stride_ = 0;
        int32 width_ = 0;
      };
    }
  }
}
