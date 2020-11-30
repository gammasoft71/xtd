#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ context_menu final static_ {
      public:
        static intptr_t create();
        static void destroy(intptr_t context_menu);
      };
    }
  }
}
