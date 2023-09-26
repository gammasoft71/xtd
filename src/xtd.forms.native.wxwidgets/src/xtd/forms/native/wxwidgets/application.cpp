#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/toolkit>
#include <xtd/drawing/native/wx_application>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode"
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler"
#include <xtd/forms/native/application>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/forms/window_messages>
#include <xtd/threading/thread>
#include <xtd/chrono>
#include <xtd/environment>
#include <wx/aboutdlg.h>
#include <wx/evtloop.h>
#include <wx/sysopt.h>

#if defined(__WXMSW__)
#include <wx/msw/registry.h>
extern drawing_native_export_ xtd::int32 __xtd_win32_enable_dark_mode__;
static wxTimer* __system_color_detection_timer__;
static bool __is_dark_mode__ = false;
static void __on_timer_system_color_detection__(wxTimerEvent& e) {
  static wxRegKey key(wxRegKey::HKCU, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize");
  long value;
  key.QueryValue("AppsUseLightTheme", &value);
  if (__is_dark_mode__ != !value) {
    __is_dark_mode__ = !value;
    init_dark_mode(__is_dark_mode__);
    auto top_level_windows = wxTopLevelWindows;
    for (auto window : top_level_windows) {
      wxCommandEvent eventSysColourChanged(wxEVT_SYS_COLOUR_CHANGED, window->GetId());
      eventSysColourChanged.SetEventObject(window);
      window->ProcessWindowEvent(eventSysColourChanged);
      
      wxCommandEvent eventRecreate(wxEVT_RECREATE, window->GetId());
      eventRecreate.SetEventObject(window);
      window->ProcessWindowEvent(eventRecreate);
    }
  }
}

#elif defined(__WXGTK__)
bool __xtd_gtk_enable_dark_mode__ = false;
bool __xtd_gtk_enable_button_images__ = false;
bool __xtd_gtk_enable_menu_images__ = false;
void __gtk_button_images__(bool enable);
void __gtk_menu_images__(bool enable);
void __gtk_application_prefer_dark_theme__(bool prefer_dark_theme);
#elif defined(__WXOSX__)
void __xtd_macos_enable_dark_mode__();
void __xtd_macos_enable_light_mode__();
bool __xtd_macos_dark_mode_enabled__();
#endif
extern drawing_native_export_ bool __enable_system_font_size__ ;
extern bool __enable_font_size_correction__;

using namespace xtd;
using namespace xtd::drawing::native;
using namespace xtd::forms::native;
using namespace xtd::threading;

std::vector<control_handler*> __control_handler_to_delete_items__;

wxMenuBar* __create_default_menu_bar__();

namespace {
  void process_idle() {
    for (control_handler* item : __control_handler_to_delete_items__)
      delete item;
    __control_handler_to_delete_items__.clear();
  }
}

event<wx_application, delegate<bool(intptr, int32, intptr, intptr, intptr)>> wx_application::message_filter_proc;

bool application::allow_quit() {
  initialize(); // Must be first
  return true;
}

void application::cleanup() {
  drawing::native::toolkit::shutdown(0);
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
   #elif defined(__WXOSX__)
   return __xtd_macos_dark_mode_enabled__();
   #endif
   */
}

void application::disable_font_size_correction() {
  __enable_font_size_correction__ = false;
}

void application::do_events() {
  initialize(); // Must be first
  //if (!wxTheApp || !wxTheApp->GetMainLoop()) return;
  //wxTheApp->GetMainLoop()->Dispatch();
  if (!wxTheApp) return;
  wxTheApp->Yield();
}

void application::do_idle() {
  thread::sleep(20_ms);
  wxWakeUpIdle();
}

void application::enable_dark_mode() {
  #if defined(__WXMSW__)
  __xtd_win32_enable_dark_mode__ = 1;
  #elif defined(__WXGTK__)
  __xtd_gtk_enable_dark_mode__ = true;
  #elif defined(__WXOSX__)
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
  #elif defined(__WXOSX__)
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

void application::enable_system_font_size() {
  initialize(); // Must be first
  #if defined(__WXGTK__)
  __enable_system_font_size__ = true;
  #endif
}

void application::enable_visual_style() {
  initialize(); // Must be first
  wxTheApp->SetUseBestVisual(true);
}

void application::exit() {
  if (wxTheApp)
    wxTheApp->ExitMainLoop();
  else
    ::exit(EXIT_SUCCESS);
}

void application::initialize() {
  static bool initialized = false;
  if (initialized) return;
  initialized = true;
  
  drawing::native::toolkit::initialize();
  static_cast<wx_application*>(wxApp::GetInstance())->processIdle += process_idle;
  #if defined(__WXMSW__)
  wxRegKey key(wxRegKey::HKCU, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize");
  long value;
  key.QueryValue("AppsUseLightTheme", &value);
  __is_dark_mode__ = !value;
  
  __system_color_detection_timer__ = new wxTimer();
  __system_color_detection_timer__->Bind(wxEVT_TIMER, __on_timer_system_color_detection__);
  __system_color_detection_timer__->Start(1000);
  
  init_dark_mode(__xtd_win32_enable_dark_mode__);
  #elif defined(__WXGTK__)
  __gtk_button_images__(__xtd_gtk_enable_button_images__);
  __gtk_menu_images__(__xtd_gtk_enable_menu_images__);
  __gtk_application_prefer_dark_theme__(__xtd_gtk_enable_dark_mode__);
  #elif defined(__WXOSX__)
  wxMenuBar::MacSetCommonMenuBar(__create_default_menu_bar__());
  #endif
}

void application::register_message_filter(const delegate<bool(intptr, int32, intptr, intptr, intptr)>& message_filter_proc) {
  initialize(); // Must be first
  static_cast<wx_application*>(wxTheApp)->message_filter_proc += message_filter_proc;
}

void application::register_thread_exception(const delegate<bool()>& thread_exception) {
  application::initialize(); // Must be first
  static_cast<wx_application*>(wxTheApp)->thread_exception += thread_exception;
}

void application::register_wnd_proc(const delegate<intptr(intptr, int32, intptr, intptr, intptr)>& wnd_proc) {
  initialize(); // Must be first
  static_cast<wx_application*>(wxTheApp)->wnd_proc += wnd_proc;
}

void application::restart(bool exit_after_restart) {
  auto command_line_args = environment::get_command_line_args().size() ? environment::get_command_line_args()[0] : "";
  for (auto index = 1_sz; index < environment::get_command_line_args().size(); ++index)
    command_line_args += ustring::format(" {}", (environment::get_command_line_args()[index].find(" ") ? environment::get_command_line_args()[index].quoted() : environment::get_command_line_args()[index]));
  wxExecute(command_line_args);
  if (exit_after_restart) environment::exit(0);
}

void application::run() {
  initialize(); { // Must be first
    static_cast<wx_application*>(wxTheApp)->send_message(0, WM_ACTIVATEAPP, true, 0, 0);
    static_cast<wx_application*>(wxTheApp)->MainLoop();
    static_cast<wx_application*>(wxTheApp)->send_message(0, WM_QUIT, 0, 0, 0);
    
    #if defined(__WXMSW__)
    __system_color_detection_timer__->Unbind(wxEVT_TIMER, __on_timer_system_color_detection__);
    delete __system_color_detection_timer__;
    #endif
    
    wxApp::SetInstance(nullptr);
    delete wxTheApp;
  }
}

void application::use_wait_cursor(bool use_wait_cursor) {
  if (use_wait_cursor) wxBeginBusyCursor();
  else wxEndBusyCursor();
}
