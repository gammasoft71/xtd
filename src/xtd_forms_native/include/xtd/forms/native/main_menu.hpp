#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class main_menu {
      public:
        main_menu() = delete;

        static intptr_t create();
        static void destroy(intptr_t main_menu);
      };
    }
  }
}
