#pragma once
#include <cstdint>
#include <string>
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class about_dialog static_ {
      public:
        static bool run_dialog(intptr_t hwnd, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright);
      };
    }
  }
}
