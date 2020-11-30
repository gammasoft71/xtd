#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ panel final static_ {
      public:
        static void virtual_size(intptr_t control, const drawing::size& size);
      };
    }
  }
}
