#pragma once
#include <xtd/drawing/image.hpp>
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class picture_box {
      public:
        picture_box() = delete;
        static void clear(intptr_t control);
        static void image(intptr_t control, const drawing::image& image);
      };
    }
  }
}
