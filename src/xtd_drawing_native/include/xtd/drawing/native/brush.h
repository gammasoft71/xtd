#pragma once
#include <cstdint>
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class brush static_ {
      public:
        static intptr_t create();
        static void solid(intptr_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void linear_gradient(intptr_t brush, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint8_t a1, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t a2, uint8_t r2, uint8_t g2, uint8_t b2);
        static void destroy(intptr_t brush);
      };
    }
  }
}
/// @endcond
