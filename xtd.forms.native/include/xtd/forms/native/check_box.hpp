#pragma once
#include <xtd/drawing/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class check_box {
      public:
        static intptr_t create(intptr_t parent, const drawing::size& size, bool three_state);
        static int check_state(intptr_t control);
        static void check_state(intptr_t control, int check_state);
      };
    }
  }
}
