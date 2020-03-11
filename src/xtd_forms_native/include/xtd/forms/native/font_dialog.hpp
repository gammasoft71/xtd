#pragma once
#include <cstdint>
#include <xtd/static.h>
#include <xtd/drawing/color.hpp>
#include <xtd/drawing/font.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class font_dialog static_ {
      public:
        static bool run_dialog(intptr_t hwnd, drawing::font& font, drawing::color& color, size_t options, size_t min_size, size_t max_size, bool show_color);
      };
    }
  }
}
