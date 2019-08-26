#pragma once
#include <cstdint>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class graphics {
      public:
        static void clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void destroy(intptr_t hdc);
        static void draw_arc(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
        static void draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4);
        static void draw_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t heigh);
        static void draw_line(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
        static void draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height);
        static void fill_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t heigh);
        static void fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
        static void fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height);
      };
    }
  }
}
/// @endcond
