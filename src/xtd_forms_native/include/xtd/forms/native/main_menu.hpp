#pragma once
#include "../create_params.hpp"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class main_menu static_ {
      public:
        static intptr_t create();
        static void destroy(intptr_t main_menu);
      };
    }
  }
}
