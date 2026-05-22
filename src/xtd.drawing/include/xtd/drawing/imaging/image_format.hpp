/// @file
/// @brief Contains xtd::drawing::imaging::image_format class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
    /// @brief The xtd::drawing::imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
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
        [[nodiscard]] auto guid() const noexcept -> const xtd::guid;
        /// @}
        
        /// @name Public Static Properties
        
        /// @{
        /// @brief Gets the bitmap (BMP) image format.
        /// @return An image_format object that indicates the bitmap image format.
        [[nodiscard]] static auto bmp() noexcept -> image_format;
        
        /// @brief Gets the enhanced metafile (EMF) image format.
        /// @return An image_format object that indicates the enhanced metafile image format.
        [[nodiscard]] static auto emf() noexcept -> image_format;
        
        /// @brief Gets the Exchangeable Image File (Exif) format.
        /// @return An image_format object that indicates the Exif format.
        [[nodiscard]] static auto exif() noexcept -> image_format;
        
        /// @brief Gets the Graphics Interchange Format (GIF) image format.
        /// @return An image_format object that indicates the GIF image format.
        [[nodiscard]] static auto gif() noexcept -> image_format;
        
        /// @brief Gets the windows icon (ico) image format.
        /// @return An image_format object that indicates the icon image format.
        [[nodiscard]] static auto ico() noexcept -> image_format;
        
        /// @brief Gets the Joint Photographic Experts Group (JPEG) image format.
        /// @return An image_format object that indicates the JOEG image format.
        [[nodiscard]] static auto jpeg() noexcept -> image_format;
        
        /// @brief Gets the format of a bitmap in memory.
        /// @return An image_format object that indicates the bitmap memory image format.
        [[nodiscard]] static auto memory_bmp() noexcept -> image_format;
        
        /// @brief Gets the W3C Portable Network Graphics (PNG) image format.
        /// @return An image_format object that indicates the PNG image format.
        [[nodiscard]] static auto png() noexcept -> image_format;
        
        /// @brief Gets the Tagged Image File Format (TIFF) image format.
        /// @return An image_format object that indicates the TIFF image format.
        [[nodiscard]] static auto tiff() noexcept -> image_format;
        
        /// @brief Gets the Windows metafile (WMF) image format.
        /// @return An image_format object that indicates the WMF image format.
        [[nodiscard]] static auto wmf() noexcept -> image_format;
        
        /// @brief Gets the GIF memory format.
        /// @return An image_format object that indicates the GIF mempry image format.
        [[nodiscard]] static auto memory_gif() noexcept -> image_format;
        
        /// @brief Gets the ICO memory format.
        /// @return An image_format object that indicates the icon memory image format.
        [[nodiscard]] static auto memory_ico() noexcept -> image_format;
        
        /// @brief Gets the JPEG memory format.
        /// @return An image_format object that indicates the JPEG memory image format.
        [[nodiscard]] static auto memory_jpeg() noexcept -> image_format;
        
        /// @brief Gets the PNG memory format.
        /// @return An image_format object that indicates the PNG memory image format.
        [[nodiscard]] static auto memory_png() noexcept -> image_format;
        
        /// @brief Gets the TIFF memory.
        /// @return An image_format object that indicates the TIFF memory image format.
        [[nodiscard]] static auto memory_tiff() noexcept -> image_format;
        
        /// @brief Gets the cursor (CUR) image format.
        /// @return An image_format object that indicates the cursor image format.
        [[nodiscard]] static auto cur() noexcept -> image_format;
        
        /// @brief Gets the CUR memory.
        /// @return An image_format object that indicates the CUR memory image format.
        [[nodiscard]] static auto memory_cur() noexcept -> image_format;
        
        /// @brief Gets the x bitmap (XBM) image format.
        /// @return An image_format object that indicates the XBM image format.
        [[nodiscard]] static auto xbm() noexcept -> image_format;
        
        /// @brief Gets the XMB memory.
        /// @return An image_format object that indicates the XBM memory image format.
        [[nodiscard]] static auto memory_xbm() noexcept -> image_format;
        
        /// @brief Gets the x pixmap (XPM) image format.
        /// @return An image_format object that indicates the XPM image format.
        [[nodiscard]] static auto xpm() noexcept -> image_format;
        
        /// @brief Gets the XPM memory.
        /// @return An image_format object that indicates the XPM memory image format.
        [[nodiscard]] static auto memory_xpm() noexcept -> image_format;
        
        /// @brief Gets the portable pixmap (PNM) image format.
        /// @return An image_format object that indicates the PNM image format.
        [[nodiscard]] static auto pnm() noexcept -> image_format;
        
        /// @brief Gets the PNM memory.
        /// @return An image_format object that indicates the PNM memory image format.
        [[nodiscard]] static auto memory_pnm() noexcept -> image_format;
        
        /// @brief Gets the pcx (PCX) image format.
        /// @return An image_format object that indicates the PCX image format.
        [[nodiscard]] static auto pcx() noexcept -> image_format;
        
        /// @brief Gets the PCX memory.
        /// @return An image_format object that indicates the PCX memory image format.
        [[nodiscard]] static auto memory_pcx() noexcept -> image_format;
        
        /// @brief Gets the apple pict (PICT) image format.
        /// @return An image_format object that indicates the PICT image format.
        [[nodiscard]] static auto pict() noexcept -> image_format;
        
        /// @brief Gets the PICT memory.
        /// @return An image_format object that indicates the PICT memory image format.
        [[nodiscard]] static auto memory_pict() noexcept -> image_format;
        
        /// @brief Gets the apple icon (ICON) image format.
        /// @return An image_format object that indicates the ICON image format.
        [[nodiscard]] static auto icon() noexcept -> image_format;
        
        /// @brief Gets the ICON memory.
        /// @return An image_format object that indicates the ICOM memory image format.
        [[nodiscard]] static auto memory_icon() noexcept -> image_format;
        
        /// @brief Gets the apple cursor (CURSOR) image format.
        /// @return An image_format object that indicates the CURSOR format.
        [[nodiscard]] static auto cursor() noexcept -> image_format;
        
        /// @brief Gets the CURSOR memory.
        /// @return An image_format object that indicates the CURSOR memory image format.
        [[nodiscard]] static auto memory_cursor() noexcept -> image_format;
        
        /// @brief Gets the animated file cursor (ANI) image format.
        /// @return An image_format object that indicates the ANI image format.
        [[nodiscard]] static auto ani() noexcept -> image_format;
        
        /// @brief Gets the iif (IIF) image format.
        /// @return An image_format object that indicates the IIF image format.
        [[nodiscard]] static auto iif() noexcept -> image_format;
        
        /// @brief Gets the truevision targa (TGA) image format.
        /// @return An image_format object that indicates the TGA image format.
        [[nodiscard]] static auto tga() noexcept -> image_format;
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
        [[nodiscard]] auto compare_to(const image_format& value) const noexcept -> int32 override;
        
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const image_format& other) const noexcept -> bool override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
        
        /// @brief Converts this image_format object to a human-readable string.
        /// @return A string that represents this image_format object.
        [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
        /// @}
        
      private:
        xtd::guid guid_;
      };
    }
  }
}
