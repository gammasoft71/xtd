/// @file
/// @brief Contains xtd::drawing::icon class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "bitmap.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <cstdint>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Represents a Windows icon, which is a small bitmap image that is used to represent an object. Icons can be thought of as transparent bitmaps, although their size is determined by the system.
    /// @code
    /// class drawing_export_ icon : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::icon
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    class drawing_export_ icon : public xtd::object, public xtd::iequatable<icon> {
      struct data;
      
    public:
      /// @name Fileds
      
      /// @{
      static icon empty;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::drawing::icon class from the specified file name.
      /// @param filename The file to load the xtd::drawing::icon from.
      /// @remarks An icon resource can contain multiple icon images. One icon file may contain images in several sizes and color depths. The image that is used in an application depends on the operating system and settings. The following list details the typical sizes for an icon:
      /// * 16 pixels x 16 pixels
      /// * 32 pixels x 32 pixels
      /// * 48 pixels x 48 pixels
      /// @remarks This constructor returns the smallest image that is contained in the specified file.
      explicit icon(const xtd::ustring& filename);
      /// @brief Initializes a new instance of the xtd::drawing::icon class of the specified size from the specified file.
      /// @param filename The file to load the xtd::drawing::icon from.
      /// @param size The desired size of the icon.
      /// @remarks If the specified file does not contain an image that matches the desired size, the icon that has the closest size is returned.
      /// @remarks The filename should include the complete path if it is not in the current application directory.
      icon(const xtd::ustring& filename, const xtd::drawing::size& size);
      /// @brief Initializes a new instance of the xtd::drawing::icon class with the specified width and height from the specified file.
      /// @param filename The file to load the xtd::drawing::icon from.
      /// @param width The desired width of the xtd::drawing::icon.
      /// @param height The desired height of the xtd::drawing::icon.
      /// @remarks If the specified file does not contain an image that matches the desired height and width, the icon that has the closest size is returned.
      /// @remarks The filename should include the complete path if it is not in the current application directory.
      icon(const xtd::ustring& filename, int32 width, int32 height);
      /// @brief Initializes a new instance of the xtd::drawing::icon class from the specified data stream.
      /// @param stream The data stream from which to load the xtd::drawing::icon.
      /// @remarks An icon resource can contain multiple icon images. One icon file may contain images in several sizes and color depths. The image that is used in an application depends on the operating system and settings. The following list details the typical sizes for an icon:
      /// * 16 pixels x 16 pixels
      /// * 32 pixels x 32 pixels
      /// * 48 pixels x 48 pixels
      /// @remarks This constructor returns the smallest image that is contained in the specified stream.
      explicit icon(std::istream& stream);
      /// @brief Initializes a new instance of the xtd::drawing::icon class of the specified size from the specified stream.
      /// @param stream The data stream from which to load the xtd::drawing::icon.
      /// @param size The desired size of the icon.
      icon(std::istream& stream, const xtd::drawing::size& size);
      /// @brief Initializes a new instance of the xtd::drawing::icon class from the specified data stream and with the specified width and height.
      /// @param stream The data stream from which to load the xtd::drawing::icon.
      /// @param width The width, in pixels, of the icon.
      /// @param height The height, in pixels, of the icon.
      icon(std::istream& stream, int32 width, int32 height);
      /// @brief Initializes a new instance of the xtd::drawing::icon class from the specified data.
      /// @param stream The data stream from which to load the xtd::drawing::icon.
      /// @remarks An icon resource can contain multiple icon images. One icon file may contain images in several sizes and color depths. The image that is used in an application depends on the operating system and settings. The following list details the typical sizes for an icon:
      /// * 16 pixels x 16 pixels
      /// * 32 pixels x 32 pixels
      /// * 48 pixels x 48 pixels
      /// @remarks This constructor returns the smallest image that is contained in the specified data.
      /// @remarks This constructor is used for creating a xtd::drawing::icon from an xpm (or xbm) image.
      explicit icon(const char* const* bits);
      /// @brief Initializes a new instance of the xtd::drawing::icon class of the specified size from the specified data.
      /// @param stream The data stream from which to load the xtd::drawing::icon.
      /// @param size The desired size of the icon.
      /// @remarks This constructor is used for creating a xtd::drawing::icon from an xpm (or xbm) image.
      icon(const char* const* bits, const xtd::drawing::size& size);
      /// @brief Initializes a new instance of the xtd::drawing::icon class from the specified data and with the specified width and height.
      /// @param stream The data stream from which to load the xtd::drawing::icon.
      /// @param width The width, in pixels, of the icon.
      /// @param height The height, in pixels, of the icon.
      /// @remarks This constructor is used for creating a xtd::drawing::icon from an xpm (or xbm) image.
      icon(const char* const* bits, int32 width, int32 height);
      /// @brief Initializes a new instance of the xtd::drawing::icon class and attempts to find a version of the icon that matches the requested size.
      /// @param original The xtd::drawing::icon from which to load the newly sized icon.
      /// @param size A xtd::drawing::size structure that specifies the height and width of the new xtd::drawing::icon.
      /// @remarks If a version cannot be found that exactly matches the size, the closest match is used. If the original parameter is an xtd::drawing::icon that has a single size, this method only creates a duplicate icon. Use the stretching capabilities of the xtd::graphics::drawing::draw_image method to resize the icon.
      icon(const icon& original, const xtd::drawing::size& size);
      /// @brief Initializes a new instance of the xtd::drawing::icon class and attempts to find a version of the icon that matches the requested size.
      /// @param original The xtd::drawing::icon from which to load the newly sized icon.
      /// @param width The width of the new icon.
      /// @param height The height of the new icon.
      /// @remarks If a version cannot be found that exactly matches the size, the closest match is used. If the original parameter is an xtd::drawing::icon that has a single size, this method only creates a duplicate icon. Use the stretching capabilities of the xtd::graphics::drawing::draw_image method to resize the icon.
      icon(const icon& original, int32 width, int32 height);
      /// @}
      
      /// @cond
      icon();
      icon(const icon& icon) = default;
      icon& operator =(const icon& icon) = default;
      ~icon();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the handle of this icon. This is not a copy of the handle; do not free it.
      /// @return The Windows handle for the icon.
      intptr handle() const noexcept;
      
      /// @brief Gets the height of this xtd::drawing::icon.
      /// @return The height of this xtd::drawing::icon.
      int32 height() const noexcept;
      
      /// @brief Gets the size of this xtd::drawing::icon.
      /// @return The size of this xtd::drawing::icon.
      const xtd::drawing::size& size() const noexcept;
      
      /// @brief Gets the width of this xtd::drawing::icon.
      /// @return The width of this xtd::drawing::icon.
      int32 width() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      bool equals(const icon& icon) const noexcept override;
      
      /// @brief Saves this xtd::drawing::icon to the specified output filename.
      /// @param filename The file to save to.
      void save(const xtd::ustring& filename) const;
      /// @brief Saves this xtd::drawing::icon to the specified output std::ostream.
      /// @param stream The std::ostream to save to.
      void save(std::ostream& stream) const;
      
      /// @brief Converts this xtd::drawing::icon to a GDI+ xtd::drawing::bitmap.
      /// @return A Bitmap that represents the converted xtd::drawing::icon.
      /// @remarks The transparent areas of the icon are lost when it is converted to a bitmap, and the transparent color of the resulting bitmap is set to RGB(13,11,12). The returned bitmap has the same height and width as the original icon.
      xtd::drawing::bitmap to_bitmap() const;
      
      /// @brief Gets a human-readable string that describes the xtd::drawing::icon.
      /// @return A string that describes the xtd::drawing::icon.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
      /// @brief Creates a GDI+ xtd::drawing::icon from the specified Windows handle to an icon (HICON).
      /// @param handle A Windows handle to an icon.
      /// @return The xtd::drawing::icon this method creates.
      /// @remarks When using this method, you must dispose of the original icon by using the DestroyIcon method in the Windows API to ensure that the resources are released.
      static icon from_handle(intptr handle);
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a GDI+ xtd::drawing::icon from the specified bitmap.
      /// @param bitmap A xtd::drawing::bitmap use to create xtd::drawing::icon.
      /// @return The xtd::drawing::icon this method creates.
      static icon from_bitmap(const xtd::drawing::bitmap& bitmap);
      /// @}

    private:
      explicit icon(const bitmap& bitmap);
      
      std::shared_ptr<data> data_;
    };
  }
}
