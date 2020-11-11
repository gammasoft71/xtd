#include "../../../include/xtd/forms/window_messages.h"
#include "../../../include/xtd/forms/native/control.h"

using namespace xtd::forms;
intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
  return native::control::send_message(hwnd, hwnd, msg, wparam, lparam);
}
