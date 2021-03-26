#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ button final static_ {
      public:
        static void set_default_button(intptr_t control);
      };
    }
  }
}
