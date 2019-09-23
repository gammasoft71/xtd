#pragma once
#include <cstdint>
#include <xtd/drawing/point.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class cursor {
      public:
        cursor() = delete;
        static intptr_t create();
        static void destroy(intptr_t cursor);
        static void hide();
        static drawing::point hot_spot(intptr_t cursor);
        static drawing::point position();
        static void position(const drawing::point& position);
        static void show();
      };
    }
  }
}
