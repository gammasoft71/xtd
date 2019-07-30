#pragma once
#include <xtd/drawing/color.hpp>
#include <xtd/drawing/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class text_box {
      public:
        static intptr_t create(intptr_t parent, const drawing::size& size);
        static drawing::color default_back_color();
        static drawing::color default_fore_color();
        static std::string text(intptr_t control);
        static void text(intptr_t control, const std::string& text);
      };
    }
  }
}
