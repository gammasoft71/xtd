#pragma once
#include "../create_params.hpp"
#include <xtd/drawing/color.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class color_picker {
      public:
        color_picker() = delete;
        static drawing::color color(intptr_t control);
        static void color(intptr_t control, const drawing::color& color);
      };
    }
  }
}
