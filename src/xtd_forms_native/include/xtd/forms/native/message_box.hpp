#pragma once
#include <cstdint>
#include <xtd/ustring.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class message_box {
      public:
        message_box() = delete;
        static int32_t show(intptr_t hwnd, const ustring& text, const ustring& caption, uint32_t options, bool display_help_button);
      };
    }
  }
}
