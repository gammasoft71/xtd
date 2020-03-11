#include <xtd/strings.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/message_keys.h>
#include "../include/xtd/forms/control.h"
#include "../include/xtd/forms/mouse_event_args.h"

using namespace std;
using namespace xtd::forms;

namespace {
  mouse_buttons message_to_mouse_buttons(const message& message) {
    if (message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_LBUTTONDOWN || message.msg() == WM_LBUTTONUP)
      return mouse_buttons::left;
    else if (message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_RBUTTONDOWN || message.msg() == WM_RBUTTONUP)
      return mouse_buttons::right;
    else if (message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_MBUTTONDOWN || message.msg() == WM_MBUTTONUP)
      return mouse_buttons::middle;
    else if (message.msg() == WM_XBUTTONDBLCLK || message.msg() == WM_XBUTTONDOWN || message.msg() == WM_XBUTTONUP)
      return (message.wparam() & MK_XBUTTON2) == MK_XBUTTON2 ? mouse_buttons::x_button2 : mouse_buttons::x_button1;
    return mouse_buttons::none;
  }
}

mouse_event_args mouse_event_args::create(const message& message, bool double_click_fired, int32_t delta) {
  drawing::point location((int32_t)LOWORD(message.lparam()), (int32_t)HIWORD(message.lparam()));
  if (forms::control::from_handle(message.hwnd()).has_value())
    location = forms::control::from_handle(message.hwnd()).value().get().point_to_client(location);
  return mouse_event_args(message_to_mouse_buttons(message), location, double_click_fired  ? 2 : 1, delta);
}
