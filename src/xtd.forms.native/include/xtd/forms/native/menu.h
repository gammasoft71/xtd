#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ menu final static_ {
      public:
        static intptr_t create(const std::string& text, const std::vector<intptr_t>& items);
        static void destroy(intptr_t menu);
      };
    }
  }
}
