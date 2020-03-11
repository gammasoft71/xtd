#pragma once
#include <cstdint>
#include <string>
#include <xtd/static.h>
#include <xtd/environment.h>
#include <xtd/drawing/size.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class system_information static_ {
      public:
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
        static std::string computer_name();
        static xtd::drawing::size cursor_size();
        static bool dbcs_enabled();
        static bool debug_os();
        static xtd::drawing::size double_click_size();
        static int32_t double_click_time();
        static bool drag_full_windows();
        static xtd::drawing::size drag_size();
        static xtd::drawing::size fixed_frame_border_size();
        static int32_t font_smoothing_contrast();
        static int32_t font_smoothing_type();
      };
    }
  }
}
