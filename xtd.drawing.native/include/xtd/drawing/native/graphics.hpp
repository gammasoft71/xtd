#pragma once
#include <cstdint>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class graphics {
      public:
        static intptr_t create_graphics();
        static intptr_t create_paint_graphics(intptr_t control);
        static void destroy(intptr_t hdc);
      };
    }
  }
}
/// @endcond
