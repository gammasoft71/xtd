#pragma once
#include <xtd/static.h>
#include <xtd/drawing/image.hpp>
#include <xtd/drawing/size.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class image_list static_ {
      public:
        static intptr_t create(const drawing::size& image_size);
        static void delete_item(intptr_t image_list, size_t pos);
        static void destroy(intptr_t image_list);
        static void insert_item(intptr_t image_list, size_t pos, const drawing::image& image);
        static void update_item(intptr_t image_list, size_t pos, const drawing::image& image);
      };
    }
  }
}
