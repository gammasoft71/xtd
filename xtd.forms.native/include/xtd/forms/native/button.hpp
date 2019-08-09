#pragma once
#include <xtd/drawing/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class button {
      public:
        button() = delete;
        static intptr_t create(intptr_t parent, const drawing::size& size);
      };
    }
  }
}
