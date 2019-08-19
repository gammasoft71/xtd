#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class panel {
      public:
        panel() = delete;
        static intptr_t create(const create_params& create_params);
      };
    }
  }
}
