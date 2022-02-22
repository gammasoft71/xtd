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
    class pen;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains pen native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ pen final static_ {
        friend xtd::drawing::pen;
      protected:
        /// @name Protected methods
        
        /// @{
        static intptr_t create();
        static void solid_color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b, float width, float dash_offset, std::vector<float> dashes);
        static void hatch_fill(intptr_t pen, intptr_t brush, float width);
        static void conical_gradient(intptr_t pen, intptr_t brush, float width);
        static void linear_gradient(intptr_t pen, intptr_t brush, float width);
        static void line_join(intptr_t pen, int32_t line_join);
        static void radial_gradient(intptr_t pen, intptr_t brush, float width);
        static void texture_fill(intptr_t pen, intptr_t brush, float width);
        static void destroy(intptr_t pen);
        /// @}
      };
    }
  }
}
