#pragma once
#include <cstdint>
#include <string>
#include <xtd/delegate.h>
#include <xtd/environment.h>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ folder_browser_dialog final static_ {
      public:
        static bool run_dialog(intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options);
        static void run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options);
      };
    }
  }
}
