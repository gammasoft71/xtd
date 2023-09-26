#include "../include/xtd/forms/control"
#include "../include/xtd/forms/mouse_event_args"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/mouse_key>
#undef __XTD_FORMS_NATIVE_LIBRARY__

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

mouse_event_args mouse_event_args::create(const message& message, bool double_click_fired, int32 delta) {
  return mouse_event_args(message_to_mouse_buttons(message), double_click_fired  ? 2 : 1, drawing::point{(int16)LOWORD(message.lparam()), (int16)HIWORD(message.lparam())}, delta);
}
