#pragma once
#include "../create_params.hpp"
#include <xtd/static.hpp>
#include <ctime>

namespace xtd {
  namespace forms {
    namespace native {
      class date_time_picker static_ {
      public:
        static void max_date(intptr_t control, const std::tm& date_time);
        static void min_date(intptr_t control, const std::tm& date_time);
        static std::tm value(intptr_t control);
        static void value(intptr_t control, const std::tm& date_time);
      };
    }
  }
}
