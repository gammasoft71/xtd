#pragma once
#include <cstdint>
#include <xtd/environment.hpp>
#include <xtd/ustring.hpp>
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
        static int32_t border_multiplier_factor();
        static xtd::drawing::size border_size();
        static xtd::drawing::size caption_button_size();
        static int32_t caption_height();
        static int32_t caret_blink_time();
        static int32_t caret_width();
        static ustring computer_name();
      };
    }
  }
}
