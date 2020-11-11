#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>

namespace xtd {
  namespace forms {
    namespace native {
      class button static_ {
      public:
        static void image(intptr_t control, const drawing::image& image);
        static void image_align(intptr_t control, uint32_t align);
        static void set_default_button(intptr_t control);
      };
    }
  }
}
