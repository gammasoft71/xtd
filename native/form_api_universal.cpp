#include "form_api.h"
#include <wx/app.h>
#include <wx/frame.h>

intptr_t native::form_api::create() {
return (intptr_t) new wxFrame(nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 300));
}

void native::form_api::initialize_application() {
  if (wxTheApp) return;
  
  int argc = 0;
  char* argv[0];
  wxInitialize(argc, argv);
  new wxApp();
  
  wxTheApp->CallOnInit();
}

