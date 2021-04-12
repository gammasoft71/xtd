#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ tab_page final static_ {
      public:
        static void image_index(intptr_t control, size_t image_index);
        static void text(intptr_t control, const std::string& text);
      };
    }
  }
}
