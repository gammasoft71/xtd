#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/icon.h>

namespace xtd {
  namespace forms {
    namespace native {
      class busy_dialog static_ {
      public:
        static intptr_t create(intptr_t hwnd, const xtd::drawing::icon& icon, const std::string& text, const std::string& description, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, double transparency);
        static void destroy(intptr_t dialog);
      };
    }
  }
}
