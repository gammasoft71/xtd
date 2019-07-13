#include "../application_api.hpp"
#include "control_handler.hpp"
#include <wx/app.h>
#include <wx/window.h>

namespace {
  class application : public wxApp {
  public:
    application() = default;

    bool ProcessEvent(wxEvent &event) override {
      if (event.GetEventType() == wxEVT_ACTIVATE_APP) {
        wxActivateEvent& acitvate_event = static_cast<wxActivateEvent&>(event);
        send_message(0, WM_ACTIVATEAPP, acitvate_event.GetActive(), 0, reinterpret_cast<intptr_t>(&event));
      //}  else if (event.GetEventType() == wxEVT_END_SESSION) {
      //  send_message(0, WM_QUIT, 0, 0, reinterpret_cast<intptr_t>(&event));
      } else if (event.GetEventType() == wxEVT_IDLE)
        send_message(0, WM_ENTERIDLE, 0, 0, reinterpret_cast<intptr_t>(&event));
      return this->wxApp::ProcessEvent(event);
    }

    void register_wnd_proc(xtd::delegate<void(xtd::forms::message&)> wnd_proc) {
      this->wnd_proc_ = wnd_proc;
    }
    
    void unregister_wnd_proc() {
      //this->wnd_proc_ = xtd::delegate<void(xtd::forms::message&)>();
    }
    
    intptr_t send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
      if (this->wnd_proc_ == nullptr) return -1;
      xtd::forms::message message = xtd::forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
      this->wnd_proc_(message);
      return message.result();
    }

  private:
    xtd::delegate<void(xtd::forms::message&)> wnd_proc_;
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

std::vector<intptr_t> native::application_api::open_forms() {
  std::vector<intptr_t> forms;
  wxWindowList::compatibility_iterator node = wxTopLevelWindows.GetFirst();
  while (node) {
    wxWindow* window = node->GetData();
    forms.push_back(reinterpret_cast<intptr_t>(window->GetHandle()));
    node = node->GetNext();
  }
  return forms;
}

void native::application_api::register_wnd_proc(xtd::delegate<void(xtd::forms::message&)> wnd_proc) {
  initialize_application(); // Must be first
  static_cast<application*>(wxTheApp)->register_wnd_proc(wnd_proc);
}

void native::application_api::run() {
  initialize_application(); // Must be first
  if (wxTheApp->GetTopWindow()) wxTheApp->GetTopWindow()->Show();
  static_cast<application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, true, 0, 0);
  struct call_on_exit {
    ~call_on_exit() {
      wxTheApp->OnExit();
      wxinitializer = nullptr;
    }
  } call_on_exit;
  wxTheApp->OnRun();
  static_cast<application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, false, 0, 0);
  static_cast<application*>(wxTheApp)->send_message(0, WM_QUIT, false, 0, 0);
}

void native::application_api::unregister_wnd_proc() {
  static_cast<application*>(wxTheApp)->unregister_wnd_proc();
}
