#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class progress_bar static_ {
      public:
        static void value(intptr_t control, int32_t value);
        static void maximum(intptr_t control, int32_t maximum);
        static void minimum(intptr_t control, int32_t minimum);
        static void marquee(intptr_t control, bool marquee, size_t animation_speed);
      };
    }
  }
}
