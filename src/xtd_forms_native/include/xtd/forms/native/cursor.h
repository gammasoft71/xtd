#pragma once
#include <cstdint>
#include <xtd/static.h>
#include <xtd/drawing/point.h>
#include <xtd/drawing/size.h>

namespace xtd {
  namespace forms {
    namespace native {
      class cursor static_ {
      public:
        static intptr_t create();
        static intptr_t create(intptr_t image, const drawing::point& hot_spot);
        static intptr_t copy(intptr_t cursor);
        static void destroy(intptr_t cursor);
        static void hide();
        static drawing::point hot_spot(intptr_t cursor);
        static drawing::point position();
        static void position(const drawing::point& position);
        static drawing::size size(intptr_t cursor);
        static void show();
      };
    }
  }
}
