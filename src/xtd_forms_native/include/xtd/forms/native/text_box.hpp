#pragma once
#include <xtd/drawing/color.hpp>
#include "../create_params.hpp"
#include <xtd/static.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class text_box static_ {
      public:
        static std::string text(intptr_t control);
        static void text(intptr_t control, const std::string& text);
      };
    }
  }
}
