#pragma once
#include <cstdint>
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class pen static_ {
      public:
        static intptr_t create();
        static void color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void dash_pattern(intptr_t pen, std::vector<float> dash_pattern);
        static void dash_style(intptr_t pen, uint32_t dash_style);
        static void width(intptr_t pen, float width);
        static void destroy(intptr_t pen);
      };
    }
  }
}
/// @endcond
