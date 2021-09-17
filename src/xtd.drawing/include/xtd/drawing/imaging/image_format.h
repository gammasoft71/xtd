/// @file
/// @brief Contains xtd::drawing::imaging::image_format class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <ostream>
#include <string>
#include <xtd/guid.h>
#include <xtd/object.h>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
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
      class image_format final : public object {
      public:
        /// @cond
        image_format() = default;
        /// @endcond

        /// @brief Initializes a new instance of the image_format class by using the specified guid structure.
        /// @param guid The guid structure that specifies a particular image format.
        /// @remarks Typically you use the static properties of the image_format class to specify a particular format such as Png or Jpeg, rather than constructing a new image_format.
        explicit image_format(const guid& guid) : guid_(guid) {}
        
        /// @cond
        image_format(const image_format&) = default;
        image_format& operator=(const image_format&) = default;
        bool operator==(const image_format& value) const {return guid_ == value.guid_;}
        bool operator!=(const image_format& value) const {return !operator==(value);}
        bool operator<(const image_format& value) const {return guid_ < value.guid_;}
        bool operator<=(const image_format& value) const {return guid_ <= value.guid_;}
        bool operator>(const image_format& value) const {return guid_ > value.guid_;}
        bool operator>=(const image_format& value) const {return guid_ >= value.guid_;}
        /// @endcond
        
        /// @brief Gets a guid structure that represents this image_format object.
        /// @return A guid structure that represents this image_format object.
        const xtd::guid guid() const {return guid_;}
        
        /// @brief Gets the bitmap (BMP) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format bmp() {return image_format(xtd::guid("b96b3cab-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the enhanced metafile (EMF) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format emf() {return image_format(xtd::guid("b96b3cac-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Exchangeable Image File (Exif) format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format exif() {return image_format(xtd::guid("b96b3cb2-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Graphics Interchange Format (GIF) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format gif() {return image_format(xtd::guid("b96b3cb0-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the windows icon (ico) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format ico() {return image_format(xtd::guid("b96b3cb5-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Joint Photographic Experts Group (JPEG) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format jpeg() {return image_format(xtd::guid("b96b3cae-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the format of a bitmap in memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_bmp() {return image_format(xtd::guid("b96b3caa-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the W3C Portable Network Graphics (PNG) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format png() {return image_format(xtd::guid("b96b3caf-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Tagged Image File Format (TIFF) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format tiff() {return image_format(xtd::guid("b96b3cb1-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the Windows metafile (WMF) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format wmf() {return image_format(xtd::guid("b96b3cad-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the gif memory format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_gif() {return image_format(xtd::guid("b96b3cb6-0728-11d3-9d7b-0000f81ef32e"));}

        /// @brief Gets the ico memory format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_ico() {return image_format(xtd::guid("b96b3cb7-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the jpeg memory format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_jpeg() {return image_format(xtd::guid("b96b3cb8-0728-11d3-9d7b-0000f81ef32e"));}

        /// @brief Gets the ipng memory format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_png() {return image_format(xtd::guid("b96b3cb9-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the tiff memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_tiff() {return image_format(xtd::guid("b96b3cba-0728-11d3-9d7b-0000f81ef32e"));}

        /// @brief Gets the cursor (cur) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format cur() {return image_format(xtd::guid("b96b3cbb-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the cur memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_cur() {return image_format(xtd::guid("b96b3cbc-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the x bitmap (xbm) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format xbm() {return image_format(xtd::guid("b96b3cbd-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the xbm memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_xbm() {return image_format(xtd::guid("b96b3cbe-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the x pixmap (xpm) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format xpm() {return image_format(xtd::guid("b96b3cbf-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the xpm memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_xpm() {return image_format(xtd::guid("b96b3cc0-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the portable pixmap (pnm) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format pnm() {return image_format(xtd::guid("b96b3cc1-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the pnm memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_pnm() {return image_format(xtd::guid("b96b3cc2-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the pcx (pcx) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format pcx() {return image_format(xtd::guid("b96b3cc3-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the pcx memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_pcx() {return image_format(xtd::guid("b96b3cc4-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the apple pict (pict) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format pict() {return image_format(xtd::guid("b96b3cc5-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the pict memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_pict() {return image_format(xtd::guid("b96b3cc6-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the apple icon (pict) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format icon() {return image_format(xtd::guid("b96b3cc7-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the icon memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_icon() {return image_format(xtd::guid("b96b3cc8-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the apple cursor) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format cursor() {return image_format(xtd::guid("b96b3cc9-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the cursor memory.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format memory_cursor() {return image_format(xtd::guid("b96b3cca-0728-11d3-9d7b-0000f81ef32e"));}
        
        /// @brief Gets the animated file cursor (ani) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format ani() {return image_format(xtd::guid("b96b3ccb-0728-11d3-9d7b-0000f81ef32e"));}

        /// @brief Gets the iif image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format iif() {return image_format(xtd::guid("b96b3ccc-0728-11d3-9d7b-0000f81ef32e"));}

        /// @brief Gets the truevision targa (tga) image format.
        /// @return An image_format object that indicates the bitmap image format.
        static image_format tga() {return image_format(xtd::guid("b96b3ccd-0728-11d3-9d7b-0000f81ef32e"));}

        /// @brief Converts this image_format object to a human-readable string.
        /// @return A string that represents this image_format object.
        xtd::ustring to_string() const noexcept override {return ustring::format("[image_format: {}]", guid_);}
        
        /// @cond
        friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::imaging::image_format& image_format) noexcept {
          return os << image_format.to_string();
        }
        /// @endcond

      private:
        xtd::guid guid_;
      };
    }
  }
}
