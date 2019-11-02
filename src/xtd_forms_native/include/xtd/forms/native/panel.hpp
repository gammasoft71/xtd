#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class panel {
      public:
        panel() = delete;
        static void virtual_size(intptr_t control, const drawing::size& size);
      };
    }
  }
}
