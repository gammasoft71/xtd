/// @file
/// @brief Contains xtd::drawing::icon class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <memory>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"
#include "bitmap.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
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
    /// @ingroup xtd_drawing drawing
    class drawing_export_ icon : public xtd::object {
    public:
      /// @name Fileds

      /// @{
      static icon empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the Icon class from the specified file name.
      /// @param filename The file to load the Icon from.
      /// @remarks An icon resource can contain multiple icon images. One icon file may contain images in several sizes and color depths. The image that is used in an application depends on the operating system and settings. The following list details the typical sizes for an icon:
      /// * 16 pixels x 16 pixels
      /// * 32 pixels x 32 pixels
      /// * 48 pixels x 48 pixels
      /// @remarks This constructor returns the smallest image that is contained in the specified file.
      explicit icon(const xtd::ustring& filename);
      /// @brief Initializes a new instance of the Icon class of the specified size from the specified file.
      /// @param filename The file to load the Icon from.
      /// @param size The desired size of the icon.
      /// @remarks If the specified file does not contain an image that matches the desired size, the icon that has the closest size is returned.
      /// @remarks The filename should include the complete path if it is not in the current application directory.
      icon(const xtd::ustring& filename, const xtd::drawing::size& size);
      /// @brief Initializes a new instance of the Icon class with the specified width and height from the specified file.
      /// @param filename The file to load the Icon from.
      /// @param width The desired width of the Icon.
      /// @param height The desired height of the Icon.
      /// @remarks If the specified file does not contain an image that matches the desired height and width, the icon that has the closest size is returned.
      /// @remarks The filename should include the complete path if it is not in the current application directory.
      icon(const xtd::ustring& filename, int32_t width, int32_t height);
      /// @brief Initializes a new instance of the Icon class from the specified data stream.
      /// @param stream The data stream from which to load the Icon.
      /// @remarks An icon resource can contain multiple icon images. One icon file may contain images in several sizes and color depths. The image that is used in an application depends on the operating system and settings. The following list details the typical sizes for an icon:
      /// * 16 pixels x 16 pixels
      /// * 32 pixels x 32 pixels
      /// * 48 pixels x 48 pixels
      /// @remarks This constructor returns the smallest image that is contained in the specified stream.
      explicit icon(std::istream& stream);
      
      icon(std::istream& stream, const xtd::drawing::size& size);

      icon(std::istream& stream, int32_t width, int32_t height);
      
      explicit icon(const char* const* bits);
      
      icon(const char* const* bits, const xtd::drawing::size& size);
      
      icon(const char* const* bits, int32_t width, int32_t height);

      icon(const icon& icon, const xtd::drawing::size& size);
      
      icon(const icon& icon, int32_t width, int32_t height);
      /// @}
      
      /// @cond
      icon() = default;
      icon(const icon& icon) = default;
      icon& operator=(const icon& icon) = default;
      bool operator==(const icon& icon) const;
      bool operator!=(const icon& icon) const;
      ~icon();
      /// @endcond

      /// @name Properties
      
      /// @brief Get the handle of this icon. This is not a copy of the handle; do not free it.
      /// @return The Windows handle for the icon.
      intptr_t handle() const;
      
      int32_t height() const;

      const xtd::drawing::size& size() const;

      int32_t width() const;
      /// @}
      
      void save(const xtd::ustring& filename) const;
      void save(std::ostream& stream) const;
      
      static icon from_handle(intptr_t handle);

      static icon from_bitmap(const xtd::drawing::bitmap& bitmap);

      bitmap to_bitmap() const;
      
      /// @brief Gets a human-readable string that describes the xtd::drawing::icon.
      /// @return A string that describes the xtd::drawing::icon.
      xtd::ustring to_string() const noexcept override {return ustring::full_class_name(*this);}

    private:
      explicit icon(const bitmap& bitmap);
      struct data {
        intptr_t handle = 0;
        xtd::drawing::size size;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
