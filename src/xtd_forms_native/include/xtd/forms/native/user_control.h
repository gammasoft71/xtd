#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class user_control static_ {
      public:
        static void virtual_size(intptr_t control, const drawing::size& size);
      };
    }
  }
}
