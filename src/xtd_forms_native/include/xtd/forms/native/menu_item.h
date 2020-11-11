#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>

namespace xtd {
  namespace forms {
    namespace native {
      class menu_item static_ {
      public:
        static intptr_t create(const std::string& text, const xtd::drawing::image& image, int kind, bool checked, size_t shortcut);
        static void destroy(intptr_t handle);
        static int menu_id(intptr_t handle);
      };
    }
  }
}
