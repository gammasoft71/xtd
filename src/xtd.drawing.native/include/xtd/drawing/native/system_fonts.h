#pragma once
#include <cstdint>
#include <vector>
#include <xtd/static.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class system_fonts static_ {
      public:
        static intptr_t caption_font();
        static intptr_t default_font();
        static intptr_t dialog_font();
        static intptr_t icon_title_font();
        static intptr_t menu_font();
        static intptr_t message_box_font();
        static intptr_t small_caption_font();
        static intptr_t status_font();
      };
    }
  }
}
/// @endcond
