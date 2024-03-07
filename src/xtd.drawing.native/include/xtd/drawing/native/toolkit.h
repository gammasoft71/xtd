#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/version.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace forms {
    namespace native {
      class application;
      class toolkit;
    }
  }
  /// @endcond
  
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @cond
      class brush;
      class font;
      class font_family;
      class graphics_path;
      class icon;
      class image;
      class matrix;
      class pen;
      class region;
      class system_colors;
      class system_fonts;
      /// @endcond
      
      /// @brief Contains toolkit native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ toolkit final static_ {
        friend xtd::drawing::native::brush;
        friend xtd::drawing::native::font;
        friend xtd::drawing::native::font_family;
        friend xtd::drawing::native::graphics_path;
        friend xtd::drawing::native::icon;
        friend xtd::drawing::native::image;
        friend xtd::drawing::native::matrix;
        friend xtd::drawing::native::pen;
        friend xtd::drawing::native::region;
        friend xtd::drawing::native::system_colors;
        friend xtd::drawing::native::system_fonts;
        friend xtd::forms::native::application;
        friend xtd::forms::native::toolkit;
      protected:
        /// @name Protected static methods
        
        /// @{
        /// @brief Initiazes toolkit.
        /// @return The toolkit handle.
        /// @warning Internal use only
        static intptr initialize();
        
        /// @brief Shutdowns toolkit.
        /// @param handle The toolkit handle.
        /// @warning Internal use only
        static void shutdown(intptr handle);
        
        /// @brief Gets the toolkit name.
        /// @return The toolkit name.
        /// @warning Internal use only
        static xtd::ustring name();
        
        /// @brief Gets the toolkit version.
        /// @return The toolkit version.
        /// @warning Internal use only
        static xtd::version version();
        /// @}
      };
    }
  }
}
