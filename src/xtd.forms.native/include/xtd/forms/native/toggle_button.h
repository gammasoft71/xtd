#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ toggle_button final static_ {
      public:
        static void check_state(intptr_t control, int check_state);
      };
    }
  }
}
