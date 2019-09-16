#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class button {
      public:
        button() = delete;
        static void default_button(intptr_t control, bool default_button);
      };
    }
  }
}
