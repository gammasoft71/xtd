#if !defined(_WIN32)
#include <unistd.h>
#endif
#include <xtd/environment.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/window_messages.h>
#include <xtd/drawing/system_colors.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_application.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_menu.h"
#include <wx/aboutdlg.h>
#include <wx/sysopt.h>

#if defined(__WXMSW__)
extern int __xtd_win32_enable_dark_mode__;
#elif defined(__WXGTK__)
bool __xtd_gtk_enable_dark_mode__ = false;
bool __xtd_gtk_enable_button_images__ = false;
bool __xtd_gtk_enable_menu_images__ = false;
void __gtk_button_images__(bool enable);
void __gtk_menu_images__(bool enable);
void __gtk_application_prefer_dark_theme__(bool prefer_dark_theme);
#elif defined(__APPLE__)
void __xtd_macos_enable_dark_mode__();
void __xtd_macos_enable_light_mode__();
bool __xtd_macos_dark_mode_enabled__();
#endif

using namespace std;
using namespace xtd;
using namespace xtd::forms::native;

event<wx_application, delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> wx_application::message_filter_proc;

namespace {
bool restart_asked = false;
}

bool application::allow_quit() {
  initialize(); // Must be first
  return true;
}

void application::cleanup() {
  if (wxTheApp) {
    wxTheApp->OnExit();
    wxApp::SetInstance(nullptr);
    wxEntryCleanup();
    delete wxTheApp;
  }
}

bool application::dark_mode_enabled() {
  initialize(); // Must be first
  return drawing::system_colors::window().get_lightness() < 0.5;
  /*
   //the following code check if dark_mode enabled if possible.
   #if defined(__WXMSW__)
   DWORD value = 0, value_size = sizeof(value);
   if (RegGetValue(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &value, &value_size) == ERROR_SUCCESS)
   value;
   return __xtd_win32_enable_dark_mode__ != 0 && (value == 0 || __xtd_win32_enable_dark_mode__ == 1);
   #elif defined(__WXGTK__)
   return drawing::system_colors::window().get_lightness() < 0.5;
   #elif defined(__APPLE__)
   return __xtd_macos_dark_mode_enabled__();
   #endif
   */
}

void application::do_events() {
  initialize(); // Must be first
  wxTheApp->ProcessPendingEvents();
}

void application::do_idle() {
  wxWakeUpIdle();
}

void application::enable_dark_mode() {
#if defined(__WXMSW__)
  __xtd_win32_enable_dark_mode__ = 1;
#elif defined(__WXGTK__)
  __xtd_gtk_enable_dark_mode__ = true;
#elif defined(__APPLE__)
  initialize();
  __xtd_macos_enable_dark_mode__();
#endif
}

void application::enable_button_images() {
#if defined(__WXGTK__)
  __xtd_gtk_enable_button_images__ = true;
#endif
}

void application::enable_light_mode() {
#if defined(__WXMSW__)
  __xtd_win32_enable_dark_mode__ = 0;
#elif defined(__WXGTK__)
  __xtd_gtk_enable_dark_mode__ = false;
#elif defined(__APPLE__)
  initialize(); // Must be first
  __xtd_macos_enable_light_mode__();
#endif
}

void application::enable_menu_images() {
#if defined(__WXGTK__)
  // This option does not work with wxWidgets...
  //__xtd_gtk_enable_menu_images__ = true;
#endif
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
  //wxDISABLE_DEBUG_SUPPORT();
  wxDisableAsserts();
  wxLog::SetLogLevel(wxLOG_Info);
  wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
  wxApp::SetInstance(new wx_application());
  int argc = 0;
  wxEntryStart(argc, (wxChar**)nullptr);
  wxTheApp->CallOnInit();
  wxTheApp->SetExitOnFrameDelete(false);
#if defined(__WXMSW__)
  init_dark_mode(__xtd_win32_enable_dark_mode__);
#elif defined(__WXGTK__)
  __gtk_button_images__(__xtd_gtk_enable_button_images__);
  __gtk_menu_images__(__xtd_gtk_enable_menu_images__);
  __gtk_application_prefer_dark_theme__(__xtd_gtk_enable_dark_mode__);
#elif defined(__APPLE__)
  wxMenuBar::MacSetCommonMenuBar(wx_menu_bar::create_default_menu_bar());
#endif
}

void application::register_message_filter(const delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& message_filter_proc) {
  initialize(); // Must be first
  static_cast<wx_application*>(wxTheApp)->message_filter_proc += message_filter_proc;
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
    class uninitializer {
    public:
      ~uninitializer() { cleanup(); }
    } uninitializer;
    static_cast<wx_application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, true, 0, 0);
    wxTheApp->OnRun();
    static_cast<wx_application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, false, 0, 0);
    static_cast<wx_application*>(wxTheApp)->send_message(0, WM_QUIT, 0, 0, 0);
  }
  if (restart_asked) {
    std::vector<string> command_line_args = environment::get_command_line_args();
    char** argv = new char* [command_line_args.size() + 1];
    for (size_t index = 0; index < command_line_args.size(); index++)
      argv[index] = command_line_args[index].data();
    argv[command_line_args.size()] = 0;
    execv(argv[0], argv);
    delete[] argv;
    _Exit(0);
  }
}

void application::use_wait_cursor(bool use_wait_cursor) {
  if (use_wait_cursor) wxBeginBusyCursor();
  else wxEndBusyCursor();
}

void application::yield() {
  initialize(); // Must be first
  wxYield();
}
