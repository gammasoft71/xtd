#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <ctime>

namespace xtd {
  namespace forms {
    namespace native {
      class date_time_picker static_ {
      public:
        static std::chrono::system_clock::time_point value(intptr_t control);
        static void value(intptr_t control, std::chrono::system_clock::time_point date_time);
      };
    }
  }
}
