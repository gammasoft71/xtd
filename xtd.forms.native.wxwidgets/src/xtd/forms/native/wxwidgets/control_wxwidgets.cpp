#include <map>
#include <stdexcept>
#include <xtd/forms/native/control.hpp>
#include "control_handler.hpp"
#include <wx/control.h>

namespace {
  class wx_control : public control_handler {
  public:
    wx_control(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
      this->create<wxControl>(parent, id, pos, size, style);
    }
  };
}

intptr_t xtd::forms::native::control::create(intptr_t parent, const xtd::drawing::size& size) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  return reinterpret_cast<intptr_t>(new wx_control(((control_handler*)parent)->control(), wxID_ANY, wxDefaultPosition, wxSize(size.width(), size.height())));
}

intptr_t xtd::forms::native::control::def_wnd_proc(intptr_t control, intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle) {
  switch (msg) {
  case WM_GETTEXTLENGTH: return (reinterpret_cast<control_handler*>(hwnd))->control()->GetLabel().ToStdString().size(); break;
  case WM_GETTEXT: return strlen(strncpy(reinterpret_cast<char*>(lparam), reinterpret_cast<control_handler*>(hwnd)->control()->GetLabel().ToStdString().c_str(), wparam)); break;
  }
  if (handle != 0) return reinterpret_cast<control_handler*>(control)->def_wnd_proc(hwnd, msg, wparam, lparam, presult, handle);
  return 0;
}

void xtd::forms::native::control::destroy(intptr_t control) {
  if (control == 0) return;
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Destroy();
  del(control);
}

void xtd::forms::native::control::del(intptr_t control) {
  if (control == 0) return;
  delete reinterpret_cast<class control_handler*>(control);
}

xtd::drawing::size xtd::forms::native::control::client_size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void xtd::forms::native::control::client_size(intptr_t control, const xtd::drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetClientSize(size.width(), size.height());
}

bool xtd::forms::native::control::enabled(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsEnabled();
}

void xtd::forms::native::control::enabled(intptr_t control, bool enabled) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Enable(enabled);
}

intptr_t xtd::forms::native::control::handle(intptr_t control) {
  if (control == 0) return 0;
  return reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetHandle());
}

xtd::drawing::point xtd::forms::native::control::location(intptr_t control) {
  if (control == 0) return {};
  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  return {location.x, location.y};
}

void xtd::forms::native::control::location(intptr_t control, const xtd::drawing::point& location) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetPosition(wxPoint(location.x(), location.y()));
}

xtd::drawing::size xtd::forms::native::control::size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void xtd::forms::native::control::size(intptr_t control, const xtd::drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetSize(size.width(), size.height());
}

std::string xtd::forms::native::control::text(intptr_t control) {
  if (control == 0) return {};
  //return reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString();
  intptr_t result = send_message(control, control, WM_GETTEXTLENGTH, 0, 0);
  std::string text(result, 0);
  result = send_message(control, control, WM_GETTEXT, result + 1, reinterpret_cast<intptr_t>(text.data()));
  return text;
}

void xtd::forms::native::control::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetLabel(text);
  send_message(control, control, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString().c_str()));
}

bool xtd::forms::native::control::visible(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsShown();
}

void xtd::forms::native::control::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  if (visible)
   reinterpret_cast<control_handler*>(control)->control()->Show();
  else
    reinterpret_cast<control_handler*>(control)->control()->Hide();
}

void xtd::forms::native::control::register_wnd_proc(intptr_t control, const xtd::delegate<intptr_t(intptr_t, int, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->register_wnd_proc(wnd_proc);
}

intptr_t xtd::forms::native::control::send_message(intptr_t control, intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam) {
  if (hwnd == 0) return -1;
  return reinterpret_cast<control_handler*>(control)->send_message(hwnd, msg, wparam, lparam, 0);
}
