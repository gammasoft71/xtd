#pragma once
#include <xtd/drawing/color.h>
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class text_box static_ {
      public:
        static void append(intptr_t control, const std::string& text);
        static void select(intptr_t control, size_t start, size_t length);
        static std::string text(intptr_t control);
        static void text(intptr_t control, const std::string& text);
      };
    }
  }
}
