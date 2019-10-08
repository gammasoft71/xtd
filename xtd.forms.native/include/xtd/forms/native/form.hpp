#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class form {
      public:
        form() = delete;
        static void activate(intptr_t form);
        static void close(intptr_t form);
        static void default_control(intptr_t form, intptr_t default_control);
        static int32_t show_dialog(intptr_t form);
        static void end_dialog(intptr_t form, int32_t result);
      };
    }
  }
}
