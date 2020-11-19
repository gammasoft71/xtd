#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class context_menu final static_ {
      public:
        static intptr_t create();
        static void destroy(intptr_t context_menu);
      };
    }
  }
}
