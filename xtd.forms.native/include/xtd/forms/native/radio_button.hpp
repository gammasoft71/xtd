#pragma once
#include <xtd/drawing/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class radio_button {
      public:
        radio_button() = delete;
        static intptr_t create(intptr_t parent, const drawing::size& size, size_t styles, size_t ex_styles);
        static bool checked(intptr_t control);
        static void checked(intptr_t control, bool checked);
      };
    }
  }
}
