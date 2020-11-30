#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <ctime>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ date_time_picker final static_ {
      public:
        static std::chrono::system_clock::time_point value(intptr_t control);
        static void value(intptr_t control, std::chrono::system_clock::time_point date_time);
      };
    }
  }
}
