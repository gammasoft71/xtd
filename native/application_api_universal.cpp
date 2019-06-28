#include "application_api.h"
#include "form_api.h"
#include <wx/app.h>
#include <wx/window.h>

void native::application_api::do_events() {
  
}

void native::application_api::enable_visual_style() {
  
}

intptr_t native::application_api::main_form() {
  if (!wxTheApp) return 0;
  return (intptr_t)wxTheApp->GetTopWindow();
}

void native::application_api::main_form(intptr_t form) {
  if (!wxTheApp) return;
  if (form == 0) return;
  wxTheApp->SetTopWindow((wxWindow*)form);
}

void native::application_api::register_idle(std::function<void()> idle) {
  
}

void native::application_api::run() {
  native::form_api::initialize_application(); // Must be first
  struct call_on_exit {
    ~call_on_exit() { wxTheApp->OnExit(); }
  } call_on_exit;

  wxTheApp->GetTopWindow()->Show();
  wxTheApp->OnRun();
}

void native::application_api::unregister_idle() {
  
}
