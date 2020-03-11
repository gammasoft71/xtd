#pragma once
#include <xtd/drawing/image.hpp>
#include "../create_params.hpp"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class picture_box static_ {
      public:
        static void clear(intptr_t control);
        static void image(intptr_t control, const drawing::image& image);
      };
    }
  }
}
