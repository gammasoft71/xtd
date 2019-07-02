#include <map>
#include "control_api.hpp"
#include <wx/control.h>

class Control : public wxControl {
public:
  Control(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : wxControl(parent, id, pos, size, style) {}

  void OnSizeChanged(wxSizeEvent& event) {
    
  }
  
private:
  wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(Control, wxControl)
  EVT_SIZE(Control::OnSizeChanged)
wxEND_EVENT_TABLE()

intptr_t native::control_api::create(intptr_t parent, const xtd::drawing::size& size) {
  if (parent == 0) return 0;
  return (intptr_t) new Control((wxWindow*)parent, wxID_ANY, wxDefaultPosition, wxSize(size.width(), size.height()));
}

xtd::drawing::size native::control_api::client_size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = ((wxControl*)control)->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void native::control_api::client_size(intptr_t control, const xtd::drawing::size& size) {
  if (control == 0) return;
  ((wxControl*)control)->SetClientSize(size.width(), size.height());
}

xtd::drawing::point native::control_api::location(intptr_t control) {
  if (control == 0) return {};
  wxPoint location = ((wxControl*)control)->GetPosition();
  return {location.x, location.y};
}

void native::control_api::location(intptr_t control, const xtd::drawing::point& location) {
  if (control == 0) return;
  ((wxControl*)control)->SetPosition(wxPoint(location.x(), location.y()));
}

xtd::drawing::size native::control_api::size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = ((wxControl*)control)->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void native::control_api::size(intptr_t control, const xtd::drawing::size& size) {
  if (control == 0) return;
  ((wxControl*)control)->SetSize(size.width(), size.height());
}

std::string native::control_api::text(intptr_t control) {
  if (control == 0) return {};
  return ((wxControl*)control)->GetLabel().ToStdString();
}

void native::control_api::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  ((wxControl*)control)->SetLabel(text);
}

bool native::control_api::visible(intptr_t control) {
  if (control == 0) return false;
  return ((wxControl*)control)->IsShown();
}

void native::control_api::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  if (visible)
    ((wxControl*)control)->Show();
  else
    ((wxControl*)control)->Hide();
}

namespace {
  void register_control_size_changed(intptr_t control, xtd::delegate<void(const xtd::event_args&)> callback) {
    static std::map<intptr_t, xtd::delegate<void(const xtd::event_args&)>> callbacks;
    callbacks[control] += callback;
    ((wxControl*)control)->Bind(wxEVT_SIZE, [&](wxSizeEvent& event) {
      callbacks[(intptr_t)event.GetEventObject()](xtd::event_args::empty);
    });
  }
}

void native::control_api::register_client_size_changed(intptr_t control, xtd::delegate<void(const xtd::event_args&)> callback) {
  register_control_size_changed(control, callback);
}

void native::control_api::register_location_changed(intptr_t control, xtd::delegate<void(const xtd::event_args&)> callback) {
  static std::map<intptr_t, xtd::delegate<void(const xtd::event_args&)>> callbacks;
  callbacks[control] += callback;
  ((wxControl*)control)->Bind(wxEVT_MOVE, [&](wxMoveEvent& event) {
    callbacks[(intptr_t)event.GetEventObject()](xtd::event_args::empty);
  });
}

void native::control_api::register_size_changed(intptr_t control, xtd::delegate<void(const xtd::event_args&)> callback) {
  register_control_size_changed(control, callback);
}
