#include <map>
#include "../control_api.hpp"
#include "ControlEvent.hpp"
#include <wx/control.h>

class Control : public control_handler {
public:
  Control(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
    this->create<wxControl>(parent, id, pos, size, style);
  }
};

intptr_t native::control_api::create(intptr_t parent, const xtd::drawing::size& size) {
  if (parent == 0) return 0;
  return (intptr_t) new Control(((control_handler*)parent)->control(), wxID_ANY, wxDefaultPosition, wxSize(size.width(), size.height()));
}

xtd::drawing::size native::control_api::client_size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = ((control_handler*)control)->control()->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void native::control_api::client_size(intptr_t control, const xtd::drawing::size& size) {
  if (control == 0) return;
  ((control_handler*)control)->control()->SetClientSize(size.width(), size.height());
}

xtd::drawing::point native::control_api::location(intptr_t control) {
  if (control == 0) return {};
  wxPoint location = ((control_handler*)control)->control()->GetPosition();
  return {location.x, location.y};
}

void native::control_api::location(intptr_t control, const xtd::drawing::point& location) {
  if (control == 0) return;
  ((wxControl*)control)->SetPosition(wxPoint(location.x(), location.y()));
}

xtd::drawing::size native::control_api::size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = ((control_handler*)control)->control()->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void native::control_api::size(intptr_t control, const xtd::drawing::size& size) {
  if (control == 0) return;
  ((control_handler*)control)->control()->SetSize(size.width(), size.height());
}

std::string native::control_api::text(intptr_t control) {
  if (control == 0) return {};
  return ((control_handler*)control)->control()->GetLabel().ToStdString();
}

void native::control_api::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  ((control_handler*)control)->control()->SetLabel(text);
}

bool native::control_api::visible(intptr_t control) {
  if (control == 0) return false;
  return ((control_handler*)control)->control()->IsShown();
}

void native::control_api::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  if (visible)
    ((control_handler*)control)->control()->Show();
  else
    ((control_handler*)control)->control()->Hide();
}

void native::control_api::register_wnd_proc(intptr_t control, xtd::delegate<void(xtd::forms::message &)> wnd_proc) {
  ((control_handler*)control)->register_wnd_proc(wnd_proc);
}

void native::control_api::unregister_wnd_proc(intptr_t control) {
  ((control_handler*)control)->unregister_wnd_proc();
}

intptr_t native::control_api::send_message(intptr_t control, intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam) {
  if (hwnd == 0) return -1;
  return ((control_handler*)control)->send_message(hwnd, msg, wparam, lparam);
}
