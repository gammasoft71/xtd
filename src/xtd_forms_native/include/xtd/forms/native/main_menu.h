#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class main_menu static_ {
      public:
        static intptr_t create(const std::vector<intptr_t>& menu_items);
        static void destroy(intptr_t main_menu);
        static intptr_t update(const std::vector<intptr_t>& menu_items);
      };
    }
  }
}
