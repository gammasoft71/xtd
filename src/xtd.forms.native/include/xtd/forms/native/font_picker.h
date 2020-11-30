#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ font_picker final static_ {
      public:
        static drawing::color color(intptr_t control);
        static void color(intptr_t control, const drawing::color& color);
        static drawing::font font(intptr_t control);
        static void font(intptr_t control, const drawing::font& font);
      };
    }
  }
}
