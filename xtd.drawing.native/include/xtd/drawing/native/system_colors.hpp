#pragma once
#include <cstdint>
#include <vector>

namespace xtd {
  namespace drawing {
    namespace native {
      class system_colors {
      public:
        static uint32_t active_border();
        static uint32_t active_caption();
        static uint32_t active_caption_text();
        static uint32_t app_workspace();
        static uint32_t button_face();
        static uint32_t button_highlight();
        static uint32_t button_shadow();
        static uint32_t control();
        static uint32_t control_dark();
        static uint32_t control_dark_dark();
        static uint32_t control_light();
        static uint32_t control_light_light();
        static uint32_t control_text();
        static uint32_t desktop();
        static uint32_t gradient_active_caption();
        static uint32_t gradient_inactive_caption();
        static uint32_t gray_text();
        static uint32_t highlight();
        static uint32_t highlight_text();
        static uint32_t hot_track();
        static uint32_t inactive_border();
        static uint32_t inactive_caption();
        static uint32_t inactive_caption_text();
        static uint32_t info();
        static uint32_t info_text();
        static uint32_t menu();
        static uint32_t menu_bar();
        static uint32_t menu_highlight();
        static uint32_t menu_text();
        static uint32_t scroll_bar();
        static uint32_t window();
        static uint32_t window_frame();
        static uint32_t window_text();
      };
    }
  }
}
