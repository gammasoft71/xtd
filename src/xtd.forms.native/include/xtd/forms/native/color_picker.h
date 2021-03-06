#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ color_picker final static_ {
      public:
        static drawing::color color(intptr_t control);
        static void color(intptr_t control, const drawing::color& color);
      };
    }
  }
}
