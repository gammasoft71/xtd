#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ up_down_button final static_ {
      public:
        static void maximum(intptr_t control, int32_t maximum);
        static void minimum(intptr_t control, int32_t minimum);
        static int32_t value(intptr_t control);
        static void value(intptr_t control, int32_t value);
      };
    }
  }
}
