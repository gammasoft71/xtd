#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class form {
      public:
        form() = delete;
        static void close(intptr_t form);
        static int32_t show_dialog(intptr_t form);
        static void end_dialog(intptr_t form, int32_t result);
      };
    }
  }
}
