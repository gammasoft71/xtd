#if !defined(_WIN32)
#include <unistd.h>
#endif
#include <xtd/environment.hpp>
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
      //else if (event.GetEventType() == wxEVT_END_SESSION)
      //  send_message(0, WM_QUIT, 0, 0, reinterpret_cast<intptr_t>(&event));
      return this->wxApp::ProcessEvent(event);
    }
    
    intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
      return this->wnd_proc(hwnd, msg, wparam, lparam, handle);
    }
    
    event<wx_application, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> wnd_proc;
  };

  bool restart_asked = false;
}

bool application::allow_quit() {
  initialize(); // Must be first
  return true;
}

void application::cleanup() {
  if (wxTheApp) {
    wxTheApp->OnExit();
    wxEntryCleanup();
    delete wxTheApp;
    wxApp::SetInstance(nullptr);
  }
}

void application::do_events() {
  initialize(); // Must be first
  wxTheApp->ProcessPendingEvents();
}

void application::do_idle() {
  wxWakeUpIdle();
}

void application::enable_visual_style() {
  initialize(); // Must be first
  wxTheApp->SetUseBestVisual(true);
}

void application::exit() {
  if (wxTheApp)
    wxTheApp->ExitMainLoop();
}

void application::initialize() {
  if (wxTheApp) return;
  wxApp::SetInstance(new wx_application());
  int argc = 0;
  wxEntryStart(argc, (wxChar**)nullptr);
  wxTheApp->CallOnInit();
  wxTheApp->SetExitOnFrameDelete(false);
#if __WXOSX__
  wxMenuBar* menubar = new wxMenuBar();
  wxMenu* menuWindow = new wxMenu();
  wxMenuItem* aboutMenuItem = new wxMenuItem(menuWindow, wxID_ANY, "About");
  
  menubar->Append(menuWindow, "Window");
  menubar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
    if (event.GetId() == wxID_ABOUT) wxAboutBox(wxAboutDialogInfo());
    if (event.GetId() == wxID_EXIT) {
      bool can_quit = true;
      for (wxWindow* window : wxTopLevelWindows) {
        can_quit = window->Close();
        if (!can_quit) break;
      }
      if (can_quit) wxTheApp->ExitMainLoop();
    } else event.Skip();
  });
  
  wxApp::s_macAboutMenuItemId = aboutMenuItem->GetId();
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
  wxApp::s_macWindowMenuTitleName = "Window";
#endif
  wxMenuBar::MacSetCommonMenuBar(menubar);
#endif
}

intptr_t application::main_form() {
  initialize(); // Must be first
  return (intptr_t)wxTheApp->GetTopWindow();
}

void application::register_wnd_proc(const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  initialize(); // Must be first
  static_cast<wx_application*>(wxTheApp)->wnd_proc += wnd_proc;
}

void application::restart() {
  restart_asked = true;
}

void application::run() {
  initialize(); { // Must be first
    struct uninitializer {
      ~uninitializer() {cleanup();}
    } uninitializer;
    static_cast<wx_application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, true, 0, 0);
    wxTheApp->OnRun();
    static_cast<wx_application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, false, 0, 0);
    static_cast<wx_application*>(wxTheApp)->send_message(0, WM_QUIT, 0, 0, 0);
  }
  if (restart_asked) {
    std::vector<std::string> command_line_args = environment::get_command_line_args();
    char** argv = new char*[command_line_args.size() + 1];
    for(int index = 0; index <command_line_args.size(); index++)
      argv[index] = command_line_args[index].data();
    argv[command_line_args.size()] = 0;
    execv(argv[0], argv);
    delete [] argv;
    _Exit(0);
  }
}

