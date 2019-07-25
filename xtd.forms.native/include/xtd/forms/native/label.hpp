#pragma once
#include <xtd/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class label {
      public:
        static intptr_t create(intptr_t parent, const drawing::size& size);
      };
    }
  }
}
