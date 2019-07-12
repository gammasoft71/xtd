#include "../application_api.hpp"
#include "control_handler.hpp"
#include <wx/app.h>
#include <wx/window.h>

namespace {
  class application : public wxApp {
  public:
    application() = default;
    
    bool ProcessEvent(wxEvent &event) override {
      if (event.GetEventType() == wxEVT_IDLE)
        this->idle_();
      return this->wxApp::ProcessEvent(event);
    }

    void register_idle(xtd::delegate<void()> idle) {
      this->idle_ = idle;
    }
    
    void unregister_idle() {
      //this->idle_ = xtd::delegate<void()>();
    }

  private:
    xtd::delegate<void()> idle_;
  };

  std::unique_ptr< wxInitializer> wxinitializer;
}

bool native::application_api::allow_quit() {
  initialize_application(); // Must be first
  return true;
}

void native::application_api::do_events() {
  initialize_application(); // Must be first
  wxYield();
}

void native::application_api::do_idle() {
  wxWakeUpIdle();
}

void native::application_api::enable_visual_style() {
  initialize_application(); // Must be first
  wxTheApp->SetUseBestVisual(true);
}

void native::application_api::exit() {
  initialize_application(); // Must be first
  wxExit();
}

void native::application_api::initialize_application() {
  if (wxTheApp) return;
  wxApp::SetInstance(new application());
  wxinitializer = std::make_unique<wxInitializer>();
  wxTheApp->CallOnInit();
}

intptr_t native::application_api::main_form() {
  initialize_application(); // Must be first
  return (intptr_t)wxTheApp->GetTopWindow();
}

void native::application_api::main_form(intptr_t form) {
  initialize_application(); // Must be first
  if (form == 0) return;
  wxTheApp->SetTopWindow(reinterpret_cast<control_handler*>(form)->control());
}

void native::application_api::register_idle(xtd::delegate<void()> idle) {
  initialize_application(); // Must be first
  static_cast<application*>(wxTheApp)->register_idle(idle);
}

void native::application_api::run() {
  initialize_application(); // Must be first
  if (wxTheApp->GetTopWindow()) wxTheApp->GetTopWindow()->Show();
  struct call_on_exit {
    ~call_on_exit() {
      wxTheApp->OnExit();
      wxinitializer = nullptr;
    }
  } call_on_exit;
  wxTheApp->OnRun();
}

void native::application_api::unregister_idle() {
  initialize_application(); // Must be first

}
