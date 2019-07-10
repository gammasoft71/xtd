#include "../application_api.hpp"
#include "control_handler.hpp"
#include <wx/app.h>
#include <wx/window.h>

std::unique_ptr< wxInitializer> __wxinitializer;

bool native::application_api::allow_quit() {
  return true;
}

void native::application_api::do_events() {
  wxYield();
}

void native::application_api::enable_visual_style() {
  initialize_application(); // Must be first
  wxTheApp->SetUseBestVisual(true);
}

void native::application_api::exit() {
  wxExit();
}

void native::application_api::initialize_application() {
  if (wxTheApp) return;
  wxApp::SetInstance(new wxApp());
  __wxinitializer = std::make_unique<wxInitializer>();
  wxTheApp->CallOnInit();
}

intptr_t native::application_api::main_form() {
  if (!wxTheApp) return 0;
  return (intptr_t)wxTheApp->GetTopWindow();
}

void native::application_api::main_form(intptr_t form) {
  if (form == 0) return;
  if (!wxTheApp) return;
  wxTheApp->SetTopWindow(reinterpret_cast<control_handler*>(form)->control());
}

void native::application_api::register_idle(std::function<void()> idle) {
  
}

void native::application_api::run() {
  initialize_application(); // Must be first
  if (wxTheApp->GetTopWindow()) wxTheApp->GetTopWindow()->Show();
  struct call_on_exit {
    ~call_on_exit() {
      wxTheApp->OnExit();
      __wxinitializer = nullptr;
    }
  } call_on_exit;
  wxTheApp->OnRun();
}

void native::application_api::unregister_idle() {
  
}
