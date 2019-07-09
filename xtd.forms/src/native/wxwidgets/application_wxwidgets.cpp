#include "../application_api.hpp"
#include "control_handler.hpp"
#include "../form_api.hpp"
#include <wx/app.h>
#include <wx/window.h>

bool native::application_api::allow_quit() {
  return true;
}

void native::application_api::do_events() {
  wxYield();
}

void native::application_api::enable_visual_style() {
  wxTheApp->SetUseBestVisual(true);
}

void native::application_api::exit() {
  wxExit();
}

intptr_t native::application_api::main_form() {
  if (!wxTheApp) return 0;
  return (intptr_t)wxTheApp->GetTopWindow();
}

void native::application_api::main_form(intptr_t form) {
  if (form == 0) return;
  if (!wxTheApp) return;
  wxTheApp->SetTopWindow(((control_handler*)form)->control());
}

void native::application_api::register_idle(std::function<void()> idle) {
  
}

void native::application_api::run() {
  native::form_api::initialize_application(); // Must be first
  struct call_on_exit {
    ~call_on_exit() {wxTheApp->OnExit();}
  } call_on_exit;

  wxTheApp->GetTopWindow()->Show();
  wxTheApp->OnRun();
}

void native::application_api::unregister_idle() {
  
}
