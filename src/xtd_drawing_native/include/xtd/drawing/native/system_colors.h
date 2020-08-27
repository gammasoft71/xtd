#pragma once
#include <cstdint>
#include <vector>
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class system_colors static_ {
      public:
        static bool force_set_system_color();
        static uint32_t to_argb(intptr_t color);
        static intptr_t accent();
        static intptr_t accent_text();
        static intptr_t active_border();
        static intptr_t active_caption();
        static intptr_t active_caption_text();
        static intptr_t app_workspace();
        static intptr_t button_face();
        static intptr_t button_highlight();
        static intptr_t button_shadow();
        static intptr_t control();
        static intptr_t control_dark();
        static intptr_t control_dark_dark();
        static intptr_t control_light();
        static intptr_t control_light_light();
        static intptr_t control_text();
        static intptr_t desktop();
        static intptr_t gradient_active_caption();
        static intptr_t gradient_inactive_caption();
        static intptr_t gray_text();
        static intptr_t highlight();
        static intptr_t highlight_text();
        static intptr_t hot_track();
        static intptr_t inactive_border();
        static intptr_t inactive_caption();
        static intptr_t inactive_caption_text();
        static intptr_t info();
        static intptr_t info_text();
        static intptr_t menu();
        static intptr_t menu_bar();
        static intptr_t menu_highlight();
        static intptr_t menu_text();
        static intptr_t scroll_bar();
        static intptr_t window();
        static intptr_t window_frame();
        static intptr_t window_text();
      };
    }
  }
}
/// @endcond
