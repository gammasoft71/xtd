#pragma once
#include <cstdint>
#include <string>
#include <xtd/delegate.h>
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class input_dialog static_ {
      public:
        static int32_t show_dialog(intptr_t hwnd, const std::string& text, const std::string& message, std::string& value, bool multiline, bool use_system_password_char);
        static void show_sheet(xtd::delegate<void(int32_t, const std::string&)> on_dialog_closed, intptr_t hwnd, const std::string& text, const std::string& message, std::string& value, bool multiline, bool use_system_password_char);
        static int32_t show_sheet_dialog(intptr_t hwnd, const std::string& text, const std::string& message, std::string& value, bool multiline, bool use_system_password_char);
      };
    }
  }
}
