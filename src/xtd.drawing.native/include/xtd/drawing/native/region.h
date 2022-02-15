#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class region;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains region native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ region final static_ {
        friend xtd::drawing::region;
      protected:
        /// @name Protected methods
        
        /// @{
        static intptr_t create(float x, float y, float width, float height);
        static intptr_t create(intptr_t graphics_path);
        static void destroy(intptr_t handle);
        static void complement(intptr_t handle, intptr_t region);
        static void exclude(intptr_t handle, intptr_t region);
        static void intersect(intptr_t handle, intptr_t region);
        static void make_union(intptr_t handle, intptr_t region);
        static void make_xor(intptr_t handle, intptr_t region);
        /// @}
      };
    }
  }
}
