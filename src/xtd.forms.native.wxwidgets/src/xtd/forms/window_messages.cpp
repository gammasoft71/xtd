#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages>

using namespace xtd;
using namespace xtd::forms;

struct __message_sender__ {
  intptr operator()(intptr hwnd, int32 msg, intptr wparam, intptr lparam) {
    return xtd::forms::native::control::send_message(hwnd, hwnd, msg, wparam, lparam);
  }
};

intptr send_message(intptr hwnd, int32 msg, intptr wparam, intptr lparam) {
  return __message_sender__()(hwnd, msg, wparam, lparam);
}
