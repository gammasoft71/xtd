#pragma once
#include <cstdint>
#include <xtd/drawing/size.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class system_information {
      public:
        system_information() = delete;
        static int32_t active_window_tracking_delay();
        static int32_t arrange_direction();
        static int32_t arrange_starting_position();
        static int32_t boot_mode();
        static xtd::drawing::size border_3d_size();
      };
    }
  }
}
