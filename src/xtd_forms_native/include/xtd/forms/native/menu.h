#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class menu static_ {
      public:
        static intptr_t create(const std::string& text, const std::vector<intptr_t>& items);
        static void destroy(intptr_t menu);
      };
    }
  }
}
