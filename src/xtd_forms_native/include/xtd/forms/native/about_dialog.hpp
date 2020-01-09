#pragma once
#include <cstdint>
#include <string>

namespace xtd {
  namespace forms {
    namespace native {
      class about_dialog {
      public:
        about_dialog() = delete;
        static bool run_dialog(intptr_t hwnd, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright);
      };
    }
  }
}
