#pragma once
#include <cstdint>
#include <string>

namespace xtd {
  namespace forms {
    namespace native {
      class message_box {
      public:
        static int show(intptr_t hwnd, const std::string& text, const std::string& caption, unsigned int options, bool display_help_button);
      };
    }
  }
}
