#include <xtd/forms/native/application.hpp>
#include <xtd/forms/window_messages.hpp>
#include "control_handler.hpp"
#include <wx/aboutdlg.h>
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/window.h>

using namespace std;
using namespace xtd;
using namespace xtd::forms::native;

namespace {
  class wx_application : public wxApp {
  public:
    wx_application() = default;

    bool ProcessEvent(wxEvent &event) override {
      if (event.GetEventType() == wxEVT_ACTIVATE_APP) {
        wxActivateEvent& acitvate_event = static_cast<wxActivateEvent&>(event);
        send_message(0, WM_ACTIVATEAPP, acitvate_event.GetActive(), 0, reinterpret_cast<intptr_t>(&event));
      } else if (event.GetEventType() == wxEVT_IDLE)
        send_message(0, WM_ENTERIDLE, 0, 0, reinterpret_cast<intptr_t>(&event));
      return this->wxApp::ProcessEvent(event);
    }

    intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
      return this->wnd_proc(hwnd, msg, wparam, lparam, handle);
    }

    bool OnInit() override {
#if __WXOSX__
      wxMenuBar* menubar = new wxMenuBar();
      wxMenu* menuWindow = new wxMenu();
      wxMenuItem* aboutMenuItem = new wxMenuItem(menuWindow, wxID_ANY, "About");
      
      menubar->Append(menuWindow, "Window");
      menubar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        if (event.GetId() == wxID_ABOUT) wxAboutBox(wxAboutDialogInfo());
        else event.Skip();
      });
      
      wxApp::s_macAboutMenuItemId = aboutMenuItem->GetId();
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
      wxApp::s_macWindowMenuTitleName = "Window";
#endif
      wxMenuBar::MacSetCommonMenuBar(menubar);
#endif
      return true;
    }
    
    event<wx_application, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> wnd_proc;
  };
  
  unique_ptr<wxInitializer> wxinitializer;
}

bool application::allow_quit() {
  initialize_application(); // Must be first
  return true;
}

void application::do_events() {
  initialize_application(); // Must be first
  wxYield();
}

void application::do_idle() {
  wxWakeUpIdle();
}

void application::enable_visual_style() {
  initialize_application(); // Must be first
  wxTheApp->SetUseBestVisual(true);
}

void application::exit() {
  initialize_application(); // Must be first
  wxExit();
}

void application::initialize_application() {
  if (wxTheApp) return;
  wxApp::SetInstance(new wx_application());
  wxinitializer = make_unique<wxInitializer>();
  wxTheApp->CallOnInit();
}

intptr_t application::main_form() {
  initialize_application(); // Must be first
  return (intptr_t)wxTheApp->GetTopWindow();
}

void application::main_form(intptr_t form) {
  initialize_application(); // Must be first
  if (form == 0) return;
  wxTheApp->SetTopWindow(reinterpret_cast<control_handler*>(form)->control());
}

vector<intptr_t> application::open_forms() {
  vector<intptr_t> forms;
  for (wxWindow* window : wxTopLevelWindows)
    forms.push_back(reinterpret_cast<intptr_t>(window->GetHandle()));
  return forms;
}

void application::register_wnd_proc(const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  initialize_application(); // Must be first
  static_cast<wx_application*>(wxTheApp)->wnd_proc += wnd_proc;
}

void application::run() {
  initialize_application(); // Must be first
  static_cast<wx_application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, true, 0, 0);
  struct call_on_exit {
    ~call_on_exit() {
      wxTheApp->OnExit();
      wxinitializer = nullptr;
    }
  } call_on_exit;
  wxTheApp->OnRun();
  static_cast<wx_application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, false, 0, 0);
}
