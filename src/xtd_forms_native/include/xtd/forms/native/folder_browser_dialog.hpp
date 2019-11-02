#pragma once
#include <cstdint>
#include <xtd/environment.hpp>
#include <xtd/ustring.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class folder_browser_dialog {
      public:
        folder_browser_dialog() = delete;
        static bool run_dialog(intptr_t hwnd, const ustring& description, environment::special_folder root_folder, ustring& selected_path, size_t options);
      };
    }
  }
}
