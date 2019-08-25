#pragma once
#include <cstdint>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class graphics {
      public:
        static void clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static intptr_t create_graphics();
        static void destroy(intptr_t hdc);
      };
    }
  }
}
/// @endcond
