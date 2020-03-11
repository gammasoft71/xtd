#pragma once
#include "../create_params.hpp"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class panel static_ {
      public:
        static void virtual_size(intptr_t control, const drawing::size& size);
      };
    }
  }
}
