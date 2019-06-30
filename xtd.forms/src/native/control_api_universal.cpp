#include "control_api.h"
#include <wx/control.h>

intptr_t native::control_api::create(intptr_t parent) {
  if (parent == 0) return 0;
  return (intptr_t) new wxControl((wxWindow*)parent, wxID_ANY);
}

std::string native::control_api::text(intptr_t control) {
  if (control == 0) return {};
  return ((wxControl*)control)->GetLabel().ToStdString();
}

void native::control_api::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  ((wxControl*)control)->SetLabel(text);
}

void native::control_api::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  if (visible)
    ((wxControl*)control)->Show();
  else
    ((wxControl*)control)->Hide();
}
