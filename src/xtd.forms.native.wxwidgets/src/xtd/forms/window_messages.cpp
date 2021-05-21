#include <xtd/forms/window_messages.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd::forms;

struct __message_sender__ {
  intptr_t operator()(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
    return native::control::send_message(hwnd, hwnd, msg, wparam, lparam);
  }
};

intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
  return __message_sender__()(hwnd, msg, wparam, lparam);
}
