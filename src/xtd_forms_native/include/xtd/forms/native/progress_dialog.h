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
      class progress_dialog static_ {
      public:
        static bool cancelled(intptr_t dialog);
        static intptr_t create(intptr_t hwnd, const std::string& text, const std::string& message, const std::vector<std::string>& informations, size_t animation_speed, int32_t minimum, int32_t maximum, int32_t value, size_t options);
        static void destroy(intptr_t dialog);
        static void informations(intptr_t dialog, const std::vector<std::string>& informations);
        static void marquee(intptr_t dialog, bool marquee, size_t animation_speed);
        static void maximum(intptr_t dialog, int32_t maximum);
        static void message(intptr_t dialog, const std::string& message);
        static void minimum(intptr_t dialog, int32_t minimum);
        static void resume(intptr_t dialog);
        static bool skipped(intptr_t dialog);
        static void value(intptr_t dialog, int32_t value);
      };
    }
  }
}
