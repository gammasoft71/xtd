#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
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
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class icon;
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
      protected:
        /// @name Protected methods
        
        /// @{
        static intptr_t create(const xtd::ustring& filename);
        static intptr_t create(const xtd::ustring& filename, int32_t width, int32_t height);
        static intptr_t create(std::istream& stream);
        static intptr_t create(const char* const* bits);
        static intptr_t create(intptr_t image);
        static intptr_t create(intptr_t icon, int32_t width, int32_t height);
        static void destroy(intptr_t icon);
        static intptr_t from_handle(intptr_t handle);
        static int32_t get_height(intptr_t icon);
        static int32_t get_width(intptr_t icon);
        static void save(intptr_t icon, const xtd::ustring& filename);
        static void save(intptr_t icon, std::ostream& stream, size_t raw_format);
        static intptr_t to_image(intptr_t icon);
        /// @}
      };
    }
  }
}
