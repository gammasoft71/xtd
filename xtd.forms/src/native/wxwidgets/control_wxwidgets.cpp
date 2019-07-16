#include <map>
#include <stdexcept>
#include "../control_api.hpp"
#include "control_handler.hpp"
#include <wx/control.h>

namespace {
  class control : public control_handler {
  public:
    control(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
      this->create<wxControl>(parent, id, pos, size, style);
    }
  };
}

intptr_t native::control_api::create(intptr_t parent, const xtd::drawing::size& size) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  return reinterpret_cast<intptr_t>(new control(((control_handler*)parent)->control(), wxID_ANY, wxDefaultPosition, wxSize(size.width(), size.height())));
}

void native::control_api::def_wnd_proc(xtd::forms::message& message) {
  switch (message.msg()) {
  case WM_GETTEXTLENGTH: message.result(reinterpret_cast<control_handler*>(message.hwnd())->control()->GetLabel().ToStdString().size()); break;
  case WM_GETTEXT: message.result(strlen(strncpy(reinterpret_cast<char*>(message.lparam()), reinterpret_cast<control_handler*>(message.hwnd())->control()->GetLabel().ToStdString().c_str(), message.wparam()))); break;
  }
}

void native::control_api::destroy(intptr_t control) {
  if (control == 0) return;
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Destroy();
  del(control);
}

void native::control_api::del(intptr_t control) {
  if (control == 0) return;
  delete reinterpret_cast<class control_handler*>(control);
}

xtd::drawing::size native::control_api::client_size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void native::control_api::client_size(intptr_t control, const xtd::drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetClientSize(size.width(), size.height());
}

bool native::control_api::enabled(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsEnabled();
}

void native::control_api::enabled(intptr_t control, bool enabled) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Enable(enabled);
}

intptr_t native::control_api::handle(intptr_t control) {
  if (control == 0) return 0;
  return reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetHandle());
}

xtd::drawing::point native::control_api::location(intptr_t control) {
  if (control == 0) return {};
  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  return {location.x, location.y};
}

void native::control_api::location(intptr_t control, const xtd::drawing::point& location) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetPosition(wxPoint(location.x(), location.y()));
}

xtd::drawing::size native::control_api::size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void native::control_api::size(intptr_t control, const xtd::drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetSize(size.width(), size.height());
}

std::string native::control_api::text(intptr_t control) {
  if (control == 0) return {};
  //return reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString();
  intptr_t result = send_message(control, control, WM_GETTEXTLENGTH, 0, 0);
  std::string text(result, 0);
  result = send_message(control, control, WM_GETTEXT, result + 1, reinterpret_cast<intptr_t>(text.data()));
  return text;
}

void native::control_api::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetLabel(text);
  send_message(control, control, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString().c_str()));
}

bool native::control_api::visible(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsShown();
}

void native::control_api::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  if (visible)
   reinterpret_cast<control_handler*>(control)->control()->Show();
  else
    reinterpret_cast<control_handler*>(control)->control()->Hide();
}

void native::control_api::register_wnd_proc(intptr_t control, xtd::delegate<void(xtd::forms::message &)> wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->register_wnd_proc(wnd_proc);
}

void native::control_api::unregister_wnd_proc(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->unregister_wnd_proc();
}

intptr_t native::control_api::send_message(intptr_t control, intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam) {
  if (hwnd == 0) return -1;
  return reinterpret_cast<control_handler*>(control)->send_message(hwnd, msg, wparam, lparam, 0);
}
