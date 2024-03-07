/// @file
/// @brief Contains xtd::drawing::imaging::image_format class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/guid>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
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
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the image_format class by using the specified guid structure.
        /// @param guid The guid structure that specifies a particular image format.
        /// @remarks Typically you use the static properties of the image_format class to specify a particular format such as Png or Jpeg, rather than constructing a new image_format.
        explicit image_format(const guid& guid) : guid_(guid) {}
        /// @}
        
        /// @cond
        image_format(const image_format&) = default;
        image_format& operator =(const image_format&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets a guid structure that represents this image_format object.
        /// @return A guid structure that represents this image_format object.
        const xtd::guid guid() const noexcept {return guid_;}
        /// @}

        /// @name Static properties
        
        /// @{
        /// @brief Gets the bitmap (BMP) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format bmp() noexcept {return image_format(xtd::guid("b96b3cab-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the enhanced metafile (EMF) image format.
        /// @return An image_format object that indicates the enhanced metafile image format.
        static image_format emf() noexcept {return image_format(xtd::guid("b96b3cac-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Exchangeable Image File (Exif) format.
        /// @return An image_format object that indicates the Exif format.
        static image_format exif() noexcept {return image_format(xtd::guid("b96b3cb2-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Graphics Interchange Format (GIF) image format.
        /// @return An image_format object that indicates the GIF image format.
        static image_format gif() noexcept {return image_format(xtd::guid("b96b3cb0-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the windows icon (ico) image format.
        /// @return An image_format object that indicates the icon image format.
        static image_format ico() noexcept {return image_format(xtd::guid("b96b3cb5-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Joint Photographic Experts Group (JPEG) image format.
        /// @return An image_format object that indicates the JOEG image format.
        static image_format jpeg() noexcept {return image_format(xtd::guid("b96b3cae-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the format of a bitmap in memory.
        /// @return An image_format object that indicates the bitmap memory image format.
        static image_format memory_bmp() noexcept {return image_format(xtd::guid("b96b3caa-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the W3C Portable Network Graphics (PNG) image format.
        /// @return An image_format object that indicates the PNG image format.
        static image_format png() noexcept {return image_format(xtd::guid("b96b3caf-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Tagged Image File Format (TIFF) image format.
        /// @return An image_format object that indicates the TIFF image format.
        static image_format tiff() noexcept {return image_format(xtd::guid("b96b3cb1-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Windows metafile (WMF) image format.
        /// @return An image_format object that indicates the WMF image format.
        static image_format wmf() noexcept {return image_format(xtd::guid("b96b3cad-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the GIF memory format.
        /// @return An image_format object that indicates the GIF mempry image format.
        static image_format memory_gif() noexcept {return image_format(xtd::guid("b96b3cb6-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the ICO memory format.
        /// @return An image_format object that indicates the icon memory image format.
        static image_format memory_ico() noexcept {return image_format(xtd::guid("b96b3cb7-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the JPEG memory format.
        /// @return An image_format object that indicates the JPEG memory image format.
        static image_format memory_jpeg() noexcept {return image_format(xtd::guid("b96b3cb8-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the PNG memory format.
        /// @return An image_format object that indicates the PNG memory image format.
        static image_format memory_png() noexcept {return image_format(xtd::guid("b96b3cb9-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the TIFF memory.
        /// @return An image_format object that indicates the TIFF memory image format.
        static image_format memory_tiff() noexcept {return image_format(xtd::guid("b96b3cba-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the cursor (CUR) image format.
        /// @return An image_format object that indicates the cursor image format.
        static image_format cur() noexcept {return image_format(xtd::guid("b96b3cbb-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the CUR memory.
        /// @return An image_format object that indicates the CUR memory image format.
        static image_format memory_cur() noexcept {return image_format(xtd::guid("b96b3cbc-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the x bitmap (XBM) image format.
        /// @return An image_format object that indicates the XBM image format.
        static image_format xbm() noexcept {return image_format(xtd::guid("b96b3cbd-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the XMB memory.
        /// @return An image_format object that indicates the XBM memory image format.
        static image_format memory_xbm() noexcept {return image_format(xtd::guid("b96b3cbe-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the x pixmap (XPM) image format.
        /// @return An image_format object that indicates the XPM image format.
        static image_format xpm() noexcept {return image_format(xtd::guid("b96b3cbf-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the XPM memory.
        /// @return An image_format object that indicates the XPM memory image format.
        static image_format memory_xpm() noexcept {return image_format(xtd::guid("b96b3cc0-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the portable pixmap (PNM) image format.
        /// @return An image_format object that indicates the PNM image format.
        static image_format pnm() noexcept {return image_format(xtd::guid("b96b3cc1-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the PNM memory.
        /// @return An image_format object that indicates the PNM memory image format.
        static image_format memory_pnm() noexcept {return image_format(xtd::guid("b96b3cc2-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the pcx (PCX) image format.
        /// @return An image_format object that indicates the PCX image format.
        static image_format pcx() noexcept {return image_format(xtd::guid("b96b3cc3-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the PCX memory.
        /// @return An image_format object that indicates the PCX memory image format.
        static image_format memory_pcx() noexcept {return image_format(xtd::guid("b96b3cc4-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the apple pict (PICT) image format.
        /// @return An image_format object that indicates the PICT image format.
        static image_format pict() noexcept {return image_format(xtd::guid("b96b3cc5-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the PICT memory.
        /// @return An image_format object that indicates the PICT memory image format.
        static image_format memory_pict() noexcept {return image_format(xtd::guid("b96b3cc6-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the apple icon (ICON) image format.
        /// @return An image_format object that indicates the ICON image format.
        static image_format icon() noexcept {return image_format(xtd::guid("b96b3cc7-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the ICON memory.
        /// @return An image_format object that indicates the ICOM memory image format.
        static image_format memory_icon() noexcept {return image_format(xtd::guid("b96b3cc8-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the apple cursor (CURSOR) image format.
        /// @return An image_format object that indicates the CURSOR format.
        static image_format cursor() noexcept {return image_format(xtd::guid("b96b3cc9-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the CURSOR memory.
        /// @return An image_format object that indicates the CURSOR memory image format.
        static image_format memory_cursor() noexcept {return image_format(xtd::guid("b96b3cca-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the animated file cursor (ANI) image format.
        /// @return An image_format object that indicates the ANI image format.
        static image_format ani() noexcept {return image_format(xtd::guid("b96b3ccb-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the iif (IIF) image format.
        /// @return An image_format object that indicates the IIF image format.
        static image_format iif() noexcept {return image_format(xtd::guid("b96b3ccc-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the truevision targa (TGA) image format.
        /// @return An image_format object that indicates the TGA image format.
        static image_format tga() noexcept {return image_format(xtd::guid("b96b3ccd-0728-11d3-9d7b-0000f81ef32e"));}
        /// @}
        
        /// @name Methods
        
        /// @{
        int32 compare_to(const image_format& value) const noexcept override {return guid_ < value.guid_ ? -1 : guid_ > value.guid_ ? 1 : 0;}
        bool equals(const image_format& value) const noexcept override {return guid_ == value.guid_;}
        
        /// @brief Converts this image_format object to a human-readable string.
        /// @return A string that represents this image_format object.
        xtd::ustring to_string() const noexcept override {return ustring::format("[image_format: {}]", guid_);}
        /// @}
        
      private:
        xtd::guid guid_;
      };
    }
  }
}
