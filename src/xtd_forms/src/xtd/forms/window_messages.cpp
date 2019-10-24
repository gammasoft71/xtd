#include "../../../include/xtd/forms/window_messages.hpp"
#include "../../native/control_api.hpp"

intptr_t send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam) {
  return native::control_api::send_message(hwnd, hwnd, msg, wparam, lparam);
}
