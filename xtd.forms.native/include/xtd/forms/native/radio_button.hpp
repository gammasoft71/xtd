#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class radio_button {
      public:
        radio_button() = delete;
        static intptr_t create(const create_params& create_params);
        static bool checked(intptr_t control);
        static void checked(intptr_t control, bool checked);
      };
    }
  }
}
