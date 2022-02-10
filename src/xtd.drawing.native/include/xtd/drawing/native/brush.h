#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <tuple>
#include <vector>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    namespace drawing2d {
      class hatch_brush;
      class conical_gradient_brush;
      class linear_gradient_brush;
      class radial_gradient_brush;
    }
    class brush;
    class solid_brush;
    class texture_brush;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains brush native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ brush final static_ {
        friend xtd::drawing::drawing2d::hatch_brush;
        friend xtd::drawing::drawing2d::conical_gradient_brush;
        friend xtd::drawing::drawing2d::linear_gradient_brush;
        friend xtd::drawing::drawing2d::radial_gradient_brush;
        friend xtd::drawing::brush;
        friend xtd::drawing::solid_brush;
        friend xtd::drawing::texture_brush;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Creates brush.
        /// @return The created brush handle.
        /// @warning Internal use only
        static intptr_t create();
        /// @brief Destroy brush.
        /// @param brush The brush handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr_t brush);
        static void solid(intptr_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void conical_gradient(intptr_t brush, int32_t center_x, int32_t center_y, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float angle);
        static void linear_gradient(intptr_t brush, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float angle);
        static void radial_gradient(intptr_t brush, int32_t center_x, int32_t center_y, int32_t focal_x, int32_t focal_y, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float radius);
        static void texture(intptr_t brush, intptr_t texture);
        /// @}
      };
    }
  }
}
