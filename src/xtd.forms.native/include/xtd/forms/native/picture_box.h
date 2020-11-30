#pragma once
#include <xtd/drawing/image.h>
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ picture_box final static_ {
      public:
        static void clear(intptr_t control);
        static void image(intptr_t control, const drawing::image& image);
      };
    }
  }
}
