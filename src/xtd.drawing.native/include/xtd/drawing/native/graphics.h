#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing_native_export.h>
#include "path_fill_mode.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains graphics native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ graphics final static_ {
        friend xtd::drawing::graphics;
      protected:
        /// @name Protected methods
        
        /// @{
        static void clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void clip(intptr_t hdc, intptr_t region);
        static void destroy(intptr_t hdc);
        static void draw_arc(intptr_t hdc, intptr_t pen, float x, float y, float width, float height, float start_angle, float sweep_angle);
        static void draw_bezier(intptr_t hdc, intptr_t pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
        static void draw_ellipse(intptr_t hdc, intptr_t pen, float x, float y, float width, float heigh);
        static void draw_image(intptr_t hdc, intptr_t image, float x, float y);
        static void draw_image_disabled(intptr_t hdc, intptr_t image, float x, float y, float brightness);
        static void draw_line(intptr_t hdc, intptr_t pen, float x1, float y1, float x2, float y2);
        static void draw_path(intptr_t hdc, intptr_t pen, intptr_t graphics_path);
        static void draw_rectangle(intptr_t hdc, intptr_t pen, float x, float y, float width, float height);
        static void draw_rounded_rectangle(intptr_t hdc, intptr_t pen, float x, float y, float width, float height, float radius);
        static void draw_string(intptr_t hdc, const xtd::ustring& text, intptr_t font, float x, float y, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void draw_string(intptr_t hdc, const xtd::ustring& text, intptr_t font, float x, float y, float w, float h, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void fill_ellipse(intptr_t hdc, intptr_t brush, float x, float y, float width, float heigh);
        static void fill_path(intptr_t hdc, intptr_t brush, intptr_t graphics_path, int32_t mode);
        static void fill_pie(intptr_t hdc, intptr_t brush, float x, float y, float width, float height, float start_angle, float sweep_angle);
        static void fill_region(intptr_t hdc, intptr_t brush, intptr_t region);
        static void fill_rectangle(intptr_t hdc, intptr_t brush, float x, float y, float width, float height);
        static void fill_rounded_rectangle(intptr_t hdc, intptr_t brush, float x, float y, float width, float height, float radius);
        static intptr_t from_image(intptr_t image);
        static void interpolation_mode(intptr_t hdc, int32_t interpolation_mode);
        static float get_dpi_x(intptr_t hdc);
        static float get_dpi_y(intptr_t hdc);
        static void pixel_offset_mode(intptr_t hdc, int32_t pixel_offst_mode);
        static void measure_string(intptr_t hdc, const xtd::ustring& text, intptr_t font, float& width, float& height);
        static void rotate_transform(intptr_t hdc, float angle);
        static void smoothing_mode(intptr_t hdc, int32_t smoothing_mode);
        /// @remarks The gamma correction value must be between 0 and 12. The default value is 4.
        static void text_contrast(intptr_t hdc, int32_t text_contrast);
        static void text_rendering_hint(intptr_t hdc, int32_t text_rendering_hint);
        static void translate_clip(intptr_t hdc, float dx, float dy);
        /// @}
      };
    }
  }
}
