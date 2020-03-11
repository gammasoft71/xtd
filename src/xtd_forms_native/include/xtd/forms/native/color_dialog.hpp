#pragma once
#include <cstdint>
#include <optional>
#include <vector>
#include <xtd/static.h>
#include <xtd/drawing/color.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class color_dialog static_ {
      public:
        static bool run_dialog(intptr_t hwnd, drawing::color& color, std::optional<std::vector<int32_t>>& custom_colors, size_t options_);
      };
    }
  }
}
