#pragma once
#include <cstdint>
#include <string>

namespace xtd {
  namespace forms {
    namespace native {
      class message_box {
      public:
        message_box() = delete;
        static int32_t show(intptr_t hwnd, const std::string& text, const std::string& caption, uint32_t options, bool display_help_button);
      };
    }
  }
}
