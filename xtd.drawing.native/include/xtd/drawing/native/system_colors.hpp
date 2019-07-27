#pragma once
#include <cstdint>
#include <vector>

namespace xtd {
  namespace drawing {
    namespace native {
      class system_colors {
      public:
        static unsigned int active_border();
        static unsigned int active_caption();
        static unsigned int active_caption_text();
        static unsigned int app_workspace();
        static unsigned int button_face();
        static unsigned int button_highlight();
        static unsigned int button_shadow();
        static unsigned int control();
        static unsigned int control_dark();
        static unsigned int control_dark_dark();
        static unsigned int control_light();
        static unsigned int control_light_light();
        static unsigned int control_text();
        static unsigned int desktop();
        static unsigned int gradient_active_caption();
        static unsigned int gradient_inactive_caption();
        static unsigned int gray_text();
        static unsigned int highlight();
        static unsigned int highlight_text();
        static unsigned int hot_track();
        static unsigned int inactive_border();
        static unsigned int inactive_caption();
        static unsigned int inactive_caption_text();
        static unsigned int info();
        static unsigned int info_text();
        static unsigned int menu();
        static unsigned int menu_bar();
        static unsigned int menu_highlight();
        static unsigned int menu_text();
        static unsigned int scroll_bar();
        static unsigned int window();
        static unsigned int window_frame();
        static unsigned int window_text();
      };
    }
  }
}
