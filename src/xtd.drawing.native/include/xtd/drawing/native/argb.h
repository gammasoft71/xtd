#pragma once
#include <cstdint>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      /// @todo Remove struct argb and replace by uint8_t a, uint8_t r, uint8_t g, b...
      struct argb {
        uint8_t a = 0;
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
      };
    }
  }
}
/// @endcond
