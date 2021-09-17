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
        static void clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void destroy(intptr_t hdc);
        static void draw_arc(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
        static void draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4);
        static void draw_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t heigh);
        static void draw_image(intptr_t hdc, intptr_t image, int32_t x, int32_t y);
        static void draw_image_disabled(intptr_t hdc, intptr_t image, int32_t x, int32_t y, float brightness);
        static void draw_line(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
        static void draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height);
        static void draw_rounded_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius);
        static void draw_string(intptr_t hdc, const xtd::ustring& text, intptr_t font, int32_t x, int32_t y, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void draw_string(intptr_t hdc, const xtd::ustring& text, intptr_t font, int32_t x, int32_t y, int32_t w, int32_t h, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void fill_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t heigh);
        static void fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
        static void fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height);
        static void fill_rounded_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius);
        static intptr_t from_image(intptr_t image);
        static void measure_string(intptr_t hdc, const xtd::ustring& text, intptr_t font, int32_t& width, int32_t& height);
        static void rotate_transform(intptr_t hdc, float angle);
        static void translate_clip(intptr_t hdc, int32_t dx, int32_t dy);
      };
    }
  }
}
