#include <cstdio>
#include <string>
#include <xtd/drawing/point,hpp>
#include <xtd/drawing/rectangle.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class screen {
      public:
        screen() = delete;
        static size_t count();
        static int32_t bits_per_pixel(size_t index);
        static drawing::rectangle bounds(size_t index);
        static std::string device_name(size_t index);
        static bool primary(size_t index);
        static drawing::rectangle working_area(size_t index);
        static size_t from_handle(intptr handle);
        static size_t from_point(const drawing::point& poi t);
      };
    }
  }
}
