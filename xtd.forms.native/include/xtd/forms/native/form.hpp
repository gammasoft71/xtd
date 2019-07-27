#pragma once
#include <xtd/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class form {
      public:
        static void close(intptr_t form);
        static intptr_t create(const drawing::size& size);
      };
    }
  }
}
