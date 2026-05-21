#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/window_definitions>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

struct __message_sender__ {
  auto operator()(intptr hwnd, int32 msg, intptr wparam, intptr lparam) -> intptr {
    return xtd::forms::native::control::send_message(hwnd, hwnd, msg, wparam, lparam);
  }
};

auto send_message(intptr hwnd, int32 msg, intptr wparam, intptr lparam) -> intptr {
  return __message_sender__()(hwnd, msg, wparam, lparam);
}
