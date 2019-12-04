#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class menu_item {
      public:
        menu_item() = delete;

        static intptr_t create();
        static void destroy(intptr_t menu_item);
      };
    }
  }
}
