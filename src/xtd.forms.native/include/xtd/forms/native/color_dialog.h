#pragma once
#include <cstdint>
#include <optional>
#include <vector>
#include <xtd/delegate.h>
#include <xtd/static.h>
#include <xtd/drawing/color.h>

namespace xtd {
  namespace forms {
    namespace native {
      class color_dialog final static_ {
      public:
        static bool run_dialog(intptr_t hwnd, drawing::color& color, std::optional<std::vector<int32_t>>& custom_colors, size_t options);
        static void run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, drawing::color& color, std::optional<std::vector<int32_t>>& custom_colors, size_t options);
      };
    }
  }
}
