#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ progress_bar final static_ {
      public:
        static void marquee(intptr_t control, bool marquee, size_t animation_speed);
        static void maximum(intptr_t control, int32_t maximum);
        static void minimum(intptr_t control, int32_t minimum);
        static void value(intptr_t control, int32_t value);
      };
    }
  }
}
