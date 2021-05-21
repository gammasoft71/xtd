#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal used only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class drawing_native_export_ system_fonts final static_ {
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
