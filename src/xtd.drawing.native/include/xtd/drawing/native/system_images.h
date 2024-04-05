#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class system_images_base;
    class system_images;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains system images native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ system_images final static_ {
        friend xtd::drawing::system_images_base;
        friend xtd::drawing::system_images;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Gets system image from specified name and size.
        /// @param name The system image name.
        /// @param width The system image width in pixels.
        /// @param height The system image height in pixels.
        /// @return An image handle that contains the system image from specified name.
        /// @remarks Returns 0 if no system image.
        /// @warning Internal use only
        static intptr from_name(const xtd::ustring& name, int32 width, int32 height);
        /// @}
      };
    }
  }
}
