#pragma once
#include <xtd/drawing/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class form {
      public:
        form() = delete;
        static void close(intptr_t form);
        static intptr_t create(const drawing::size& size);
      };
    }
  }
}
