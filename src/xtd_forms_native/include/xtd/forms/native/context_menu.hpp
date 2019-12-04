#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class context_menu {
      public:
        context_menu() = delete;

        static intptr_t create();
        static void destroy(intptr_t context_menu);
      };
    }
  }
}
