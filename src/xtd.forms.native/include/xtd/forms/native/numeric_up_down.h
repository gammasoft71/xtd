#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ numeric_up_down final static_ {
      public:
        static void decimal_place(intptr_t control, int32_t decimal_place);
        static void increment(intptr_t control, double increment);
        static void maximum(intptr_t control, double maximum);
        static void minimum(intptr_t control, double minimum);
        static double value(intptr_t control);
        static void value(intptr_t control, double value);
      };
    }
  }
}
