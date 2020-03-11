#pragma once
#include "../create_params.hpp"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class radio_button static_ {
      public:
        static bool checked(intptr_t control);
        static void checked(intptr_t control, bool checked);
      };
    }
  }
}
