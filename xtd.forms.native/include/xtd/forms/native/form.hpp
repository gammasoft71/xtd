#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class form {
      public:
        form() = delete;
        static void close(intptr_t form);
      };
    }
  }
}
