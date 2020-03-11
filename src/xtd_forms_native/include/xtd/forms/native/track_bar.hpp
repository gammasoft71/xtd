#pragma once
#include "../create_params.hpp"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class track_bar static_ {
      public:
        static void large_change(intptr_t control, int32_t large_change);
        static void maximum(intptr_t control, int32_t maximum);
        static void minimum(intptr_t control, int32_t minimum);
        static void small_change(intptr_t control, int32_t small_change);
        static void tick_frequency(intptr_t control, int32_t tick_frequency);
        static int32_t value(intptr_t control);
        static void value(intptr_t control, int32_t value);
      };
    }
  }
}
