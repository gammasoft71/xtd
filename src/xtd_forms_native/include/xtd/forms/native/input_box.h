#pragma once
#include <cstdint>
#include <string>
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class input_box static_ {
      public:
        static bool run_dialog(intptr_t hwnd, const std::string& message, const std::string& caption, std::string& value, bool multiline, bool use_system_password_char);
      };
    }
  }
}
