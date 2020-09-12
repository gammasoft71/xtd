#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class toggle_button static_ {
      public:
        static void check_state(intptr_t control, int check_state);
      };
    }
  }
}
