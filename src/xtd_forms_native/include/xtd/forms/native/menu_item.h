#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class menu_item static_ {
      public:
        static intptr_t create(const std::string& text);
        static void destroy(intptr_t menu_item);
      };
    }
  }
}
