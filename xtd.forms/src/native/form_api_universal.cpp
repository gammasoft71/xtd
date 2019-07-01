#include "form_api.h"
#include <wx/app.h>
#include <wx/frame.h>

intptr_t native::form_api::create(const xtd::drawing::size& size) {
  return (intptr_t) new wxFrame(nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(size.width(), size.height()));
}

void native::form_api::initialize_application() {
  if (wxTheApp) return;  
  wxInitialize();
  wxApp::SetInstance(new wxApp());
  wxTheApp->CallOnInit();
}

