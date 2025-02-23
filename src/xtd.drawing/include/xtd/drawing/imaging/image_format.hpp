/// @file
/// @brief Contains xtd::drawing::imaging::image_format class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/guid>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>
#include <cstdint>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Specifies the file format of the image. Not inheritable.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      class image_format final : public object, public icomparable<image_format>, public xtd::iequatable<image_format> {
      public:
        /// @cond
        image_format() = default;
        /// @endcond
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the image_format class by using the specified guid structure.
        /// @param guid The guid structure that specifies a particular image format.
        /// @remarks Typically you use the static properties of the image_format class to specify a particular format such as Png or Jpeg, rather than constructing a new image_format.
        explicit image_format(const guid& guid) noexcept;
        /// @}
        
        /// @cond
        image_format(const image_format&) = default;
        image_format& operator =(const image_format&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets a guid structure that represents this image_format object.
        /// @return A guid structure that represents this image_format object.
        const xtd::guid guid() const noexcept;
        /// @}

        /// @name Public Static Properties
        
        /// @{
        /// @brief Gets the bitmap (BMP) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format bmp() noexcept;
        
        /// @brief Gets the enhanced metafile (EMF) image format.
        /// @return An image_format object that indicates the enhanced metafile image format.
        static image_format emf() noexcept;
        
        /// @brief Gets the Exchangeable Image File (Exif) format.
        /// @return An image_format object that indicates the Exif format.
        static image_format exif() noexcept;
        
        /// @brief Gets the Graphics Interchange Format (GIF) image format.
        /// @return An image_format object that indicates the GIF image format.
        static image_format gif() noexcept;
        
        /// @brief Gets the windows icon (ico) image format.
        /// @return An image_format object that indicates the icon image format.
        static image_format ico() noexcept;
        
        /// @brief Gets the Joint Photographic Experts Group (JPEG) image format.
        /// @return An image_format object that indicates the JOEG image format.
        static image_format jpeg() noexcept;
        
        /// @brief Gets the format of a bitmap in memory.
        /// @return An image_format object that indicates the bitmap memory image format.
        static image_format memory_bmp() noexcept;
        
        /// @brief Gets the W3C Portable Network Graphics (PNG) image format.
        /// @return An image_format object that indicates the PNG image format.
        static image_format png() noexcept;
        
        /// @brief Gets the Tagged Image File Format (TIFF) image format.
        /// @return An image_format object that indicates the TIFF image format.
        static image_format tiff() noexcept;
        
        /// @brief Gets the Windows metafile (WMF) image format.
        /// @return An image_format object that indicates the WMF image format.
        static image_format wmf() noexcept;
        
        /// @brief Gets the GIF memory format.
        /// @return An image_format object that indicates the GIF mempry image format.
        static image_format memory_gif() noexcept;
        
        /// @brief Gets the ICO memory format.
        /// @return An image_format object that indicates the icon memory image format.
        static image_format memory_ico() noexcept;
        
        /// @brief Gets the JPEG memory format.
        /// @return An image_format object that indicates the JPEG memory image format.
        static image_format memory_jpeg() noexcept;
        
        /// @brief Gets the PNG memory format.
        /// @return An image_format object that indicates the PNG memory image format.
        static image_format memory_png() noexcept;
        
        /// @brief Gets the TIFF memory.
        /// @return An image_format object that indicates the TIFF memory image format.
        static image_format memory_tiff() noexcept;
        
        /// @brief Gets the cursor (CUR) image format.
        /// @return An image_format object that indicates the cursor image format.
        static image_format cur() noexcept;
        
        /// @brief Gets the CUR memory.
        /// @return An image_format object that indicates the CUR memory image format.
        static image_format memory_cur() noexcept;
        
        /// @brief Gets the x bitmap (XBM) image format.
        /// @return An image_format object that indicates the XBM image format.
        static image_format xbm() noexcept;
        
        /// @brief Gets the XMB memory.
        /// @return An image_format object that indicates the XBM memory image format.
        static image_format memory_xbm() noexcept;
        
        /// @brief Gets the x pixmap (XPM) image format.
        /// @return An image_format object that indicates the XPM image format.
        static image_format xpm() noexcept;
        
        /// @brief Gets the XPM memory.
        /// @return An image_format object that indicates the XPM memory image format.
        static image_format memory_xpm() noexcept;
        
        /// @brief Gets the portable pixmap (PNM) image format.
        /// @return An image_format object that indicates the PNM image format.
        static image_format pnm() noexcept;
        
        /// @brief Gets the PNM memory.
        /// @return An image_format object that indicates the PNM memory image format.
        static image_format memory_pnm() noexcept;

        /// @brief Gets the pcx (PCX) image format.
        /// @return An image_format object that indicates the PCX image format.
        static image_format pcx() noexcept;
        
        /// @brief Gets the PCX memory.
        /// @return An image_format object that indicates the PCX memory image format.
        static image_format memory_pcx() noexcept;
        
        /// @brief Gets the apple pict (PICT) image format.
        /// @return An image_format object that indicates the PICT image format.
        static image_format pict() noexcept;
        
        /// @brief Gets the PICT memory.
        /// @return An image_format object that indicates the PICT memory image format.
        static image_format memory_pict() noexcept;
        
        /// @brief Gets the apple icon (ICON) image format.
        /// @return An image_format object that indicates the ICON image format.
        static image_format icon() noexcept;
        
        /// @brief Gets the ICON memory.
        /// @return An image_format object that indicates the ICOM memory image format.
        static image_format memory_icon() noexcept;
        
        /// @brief Gets the apple cursor (CURSOR) image format.
        /// @return An image_format object that indicates the CURSOR format.
        static image_format cursor() noexcept;
        
        /// @brief Gets the CURSOR memory.
        /// @return An image_format object that indicates the CURSOR memory image format.
        static image_format memory_cursor() noexcept;
        
        /// @brief Gets the animated file cursor (ANI) image format.
        /// @return An image_format object that indicates the ANI image format.
        static image_format ani() noexcept;
        
        /// @brief Gets the iif (IIF) image format.
        /// @return An image_format object that indicates the IIF image format.
        static image_format iif() noexcept;
        
        /// @brief Gets the truevision targa (TGA) image format.
        /// @return An image_format object that indicates the TGA image format.
        static image_format tga() noexcept;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Compares the current instance with another object of the same type.
        /// @param obj An object to compare with this instance.
        /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
        /// The return value has these meanings:
        ///
        /// | Value             | Condition                          |
        /// | ----------------- | ---------------------------------- |
        /// | Less than zero    | This instance is less than obj.    |
        /// | Zero              | This instance is equal to obj.     |
        /// | Greater than zero | This instance is greater than obj. |
        int32 compare_to(const image_format& value) const noexcept override;
        
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const object& obj) const noexcept override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const image_format& other) const noexcept override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        xtd::size get_hash_code() const noexcept override;

        /// @brief Converts this image_format object to a human-readable string.
        /// @return A string that represents this image_format object.
        xtd::string to_string() const noexcept override;
        /// @}
        
      private:
        xtd::guid guid_;
      };
    }
  }
}
