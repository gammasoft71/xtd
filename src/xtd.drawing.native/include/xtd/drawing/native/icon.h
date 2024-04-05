#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <istream>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class icon;
    class image;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains icon native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ icon final static_ {
        friend xtd::drawing::icon;
        friend xtd::drawing::image;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates an icon from specified filename.
        /// @param filename The filename of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr create(const xtd::ustring& filename);
        /// @brief Creates an icon from specified filename, and size.
        /// @param filename The filename of the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr create(const xtd::ustring& filename, int32 width, int32 height);
        /// @brief Creates an icon from specified std::stream.
        /// @param stream The stream containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr create(std::istream& stream);
        /// @brief Creates an icon from specified std::stream, and size.
        /// @param stream The stream containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr create(std::istream& stream, int32 width, int32 height);
        /// @brief Creates an icon from bits.
        /// @param bits The bits containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        /// @remarks This method is used for creating an icon from an XPM (or XBM) image.
        static intptr create(const char* const* bits);
        /// @brief Creates an icon from specified bits, and size.
        /// @param stream The bits containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @remarks This method is used for creating an icons from an XPM (or XBM) image.
        /// @warning Internal use only
        static intptr create(const char* const* bits, int32 width, int32 height);
        /// @brief Creates an icon from image.
        /// @param image The image handle containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr create(intptr image);
        /// @brief Creates an icon from specified icon, and size.
        /// @param icon The icon handle containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr create(intptr icon, int32 width, int32 height);
        
        /// @brief Destroys the icon.
        /// @param icon The icon handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr icon);
        
        /// @brief Creates an icon from handle.
        /// @param handle The icon handle .
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr from_handle(intptr handle);
        
        /// @brief Gets the height of icon.
        /// @param icon The icon handle .
        /// @return The height of icon.
        /// @warning Internal use only
        static int32 get_height(intptr icon);
        
        /// @brief Gets the width of icon.
        /// @param icon The icon handle .
        /// @return The width of icon.
        /// @warning Internal use only
        static int32 get_width(intptr icon);
        
        /// @brief Saves icon to the specified output filename.
        /// @param icon The icon handle .
        /// @param filename The file to save to.
        /// @warning Internal use only
        static void save(intptr icon, const xtd::ustring& filename);
        /// @brief Saves icon to the specified output std::ostream.
        /// @param icon The icon handle .
        /// @param stream The std::ostream to save to.
        /// @warning Internal use only
        static void save(intptr icon, std::ostream& stream, size_t raw_format);
        
        /// @brief Converts icon to an image.
        /// @param icon The icon handle .
        /// @return A image handle that represents the converted icon.
        /// @warning Internal use only
        static intptr to_image(intptr icon);
        /// @}
      };
    }
  }
}
