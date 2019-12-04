#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class menu {
      public:
        menu() = delete;

        static intptr_t create();
        static void destroy(intptr_t menu);
      };
    }
  }
}
