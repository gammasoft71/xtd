#pragma once
#include <cstdint>
#include <string>
#include <xtd/delegate.h>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ message_box final static_ {
      public:
        static int32_t show(intptr_t hwnd, const std::string& text, const std::string& caption, uint32_t options, bool display_help_button);
        static void show_sheet(xtd::delegate<void(int)> on_dialog_closed, intptr_t hwnd, const std::string& text, const std::string& caption, uint32_t options, bool display_help_button);
      };
    }
  }
}
