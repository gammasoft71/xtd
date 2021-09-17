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
        static intptr_t create();
        static void color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void dash_pattern(intptr_t pen, std::vector<float> dash_pattern);
        static void dash_style(intptr_t pen, uint32_t dash_style);
        static void width(intptr_t pen, float width);
        static void destroy(intptr_t pen);
      };
    }
  }
}
