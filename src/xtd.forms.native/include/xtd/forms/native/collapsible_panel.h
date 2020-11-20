#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class collapsible_panel final static_ {
      public:
        static bool expanded(intptr_t handle);
        static void expanded(intptr_t handle, bool expanded);
      };
    }
  }
}
