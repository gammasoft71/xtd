#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class progress_bar {
      public:
        progress_bar() = delete;
        static void value(intptr_t control, int32_t value);
        static void maximum(intptr_t control, int32_t maximum);
        static void minimum(intptr_t control, int32_t minimum);
        static void marquee(intptr_t control, bool marquee, size_t animation_speed);
      };
    }
  }
}
