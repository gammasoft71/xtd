#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ collapsible_panel final static_ {
      public:
        static bool expanded(intptr_t handle);
        static void expanded(intptr_t handle, bool expanded);
      };
    }
  }
}
