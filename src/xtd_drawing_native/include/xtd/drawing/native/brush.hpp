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
        static void color(intptr_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void destroy(intptr_t brush);
      };
    }
  }
}
/// @endcond
