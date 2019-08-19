#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class radio_button {
      public:
        radio_button() = delete;
        static bool checked(intptr_t control);
        static void checked(intptr_t control, bool checked);
      };
    }
  }
}
