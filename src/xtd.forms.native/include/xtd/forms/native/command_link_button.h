#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ command_link_button final static_ {
      public:
        static void image(intptr_t control, const drawing::image& image);
        static void image_align(intptr_t control, uint32_t align);
      };
    }
  }
}
