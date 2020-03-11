#pragma once
#include "../create_params.hpp"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class check_box static_ {
      public:
        static int check_state(intptr_t control);
        static void check_state(intptr_t control, int check_state);
      };
    }
  }
}
