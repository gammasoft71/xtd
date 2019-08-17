#pragma once
#include <xtd/drawing/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class label {
      public:
        label() = delete;
        static intptr_t create(intptr_t parent, const drawing::size& size, size_t styles, size_t ex_styles);
      };
    }
  }
}
