#include "control_api.h"
#include <wx/control.h>

intptr_t native::control_api::create(intptr_t parent, const xtd::drawing::size& size) {
  if (parent == 0) return 0;
  return (intptr_t) new wxControl((wxWindow*)parent, wxID_ANY, wxDefaultPosition, wxSize(size.width(), size.height()));
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
