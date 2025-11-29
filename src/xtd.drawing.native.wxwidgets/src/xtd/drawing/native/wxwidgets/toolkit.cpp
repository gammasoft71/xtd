#include <wx/app.h>
#include <wx/image.h>
#include <wx/memory.h>
#include <wx/sysopt.h>
#include <wx/version.h>
#undef interface
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/toolkit>
#include <xtd/drawing/native/wx_application>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/diagnostics/assert>
#include <xtd/diagnostics/boolean_switch>
#include <xtd/call_once>
#include <xtd/delegate>
#include <xtd/event>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing::native;

#if defined (_WIN32)
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
#endif

namespace {
  wxAssertHandler_t original_assert_handler = nullptr;
  
  void xtd_assert_handler(const wxString& file, int32 line, const wxString& func, const wxString& cond, const wxString& msg) noexcept {
    static boolean_switch show_wx_assert("wx_assert", "Shows wxAssert log", "true");
    try {
      // Workaround : wxWidgets generates an unknown assertion when there is a double mouse click event on an empty area of wxCalendarCtrl.
      if (func == "wxCalendarCtrl::HitTest" && cond == "\"Assert failure\"" && msg == "unexpected") return;
      // Workaround : wxWidgets generates an assert if wxApp is not running when call exit.
      if (func == "wxEventLoopBase::Exit" && cond == "\"IsRunning()\"" && msg == "Use ScheduleExit() on not running loop") return;
      // Workaround : wxWidgets generates an assert if bitmap is empty.
      if (func.Contains("GetHeight") && cond == "\"IsOk()\"" && msg == "invalid bitmap") return;
      // Workaround : wxWidgets generates an assert if bitmap is empty.
      if (func.Contains("GetWidth") && cond == "\"IsOk()\"" && msg == "invalid bitmap") return;
      // Workaround : wxWidgets generates an assert if wxPaintDC is not call in paint event.
      if (func.Contains("wxPaintDCImpl::wxPaintDCImpl") && cond == "\"paintStack.top().window == window\"" && msg == "wxPaintDC must be associated with the window being repainted") return;
      // Workaround : wxWidgets generates an assert if wxPaintDC is not call in paint event.
      if (func.Contains("wxClientDCImpl::DoGetSize") && cond == "\"m_window\"" && msg == "wxClientDCImpl without a window?") return;
      // Workaround : wxWidgets generates an assert if wxPaintDC is not call in paint event.
      if (func.Contains("wxTextMeasure::BeginMeasuring") && cond == "m_hdc" && msg == "Must not be used with non-native wxDCs") return;
      // Workaround : wxWidgets generates an assert if wxPaintDC is not call with the window being repainted.
      if (func.Contains("wxPaintDCImpl") && cond == "\"paintStack.top().window == window\"" && msg == "wxPaintDC must be associated with the window being repainted") return;
      // Workaround : Call wxClientDCImpl without a window.
      if (func.Contains("DoGetSize") && cond == "\"m_window\"" && msg == "wxClientDCImpl without a window?") return;
      
      if (xtd::diagnostics::debug::__should_aborted__(stack_frame {string {static_cast<const char*>(file.c_str())}, as<uint32>(line), string {static_cast<const char*>(func.c_str())}}, !show_wx_assert.enabled(), "wxAssert", string::format("cond={}, msg={}", string {static_cast<const char*>(cond.c_str())}, string {static_cast<const char*>(msg.c_str())}))) debug_break_();
    } catch (const xtd::exception& e) {
      if (xtd::diagnostics::debug::__should_aborted__(stack_frame {string {static_cast<const char*>(file.c_str())}, as<uint32>(line), string {static_cast<const char*>(func.c_str())}}, !show_wx_assert.enabled(), "xtd_assert_handler", string::format("Exception occured : {}", e.to_string()))) debug_break_();
    } catch (const std::exception& e) {
      if (xtd::diagnostics::debug::__should_aborted__(stack_frame {string {static_cast<const char*>(file.c_str())}, as<uint32>(line), string {static_cast<const char*>(func.c_str())}}, !show_wx_assert.enabled(), "xtd_assert_handler", string::format("Exception occured : {}", e.what()))) debug_break_();
    }
  }
}

intptr xtd::drawing::native::toolkit::initialize() {
  if (wxTheApp) return 0;
  #if defined(_MSC_VER)
  // Workaround : Dump memory leak : Remove temporary memory check...
  _CrtSetDbgFlag(_CRTDBG_CHECK_DEFAULT_DF);
  #endif
  wxDISABLE_DEBUG_SUPPORT();
  original_assert_handler = wxSetAssertHandler(&xtd_assert_handler);
  wxLog::SetLogLevel(wxLOG_Info);
  wxSystemOptions::SetOption("gtk.tlw.can-set-transparent", 1);
  wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
  wxApp::SetInstance(new wx_application());
  int32 argc = 0;
  wxEntryStart(argc, reinterpret_cast<char**>(0));
  // Workaround : On macOS, call only one wxApp::CallOnInit because after calling wxApp::CleanUp, calling wxApp::CallOnInit again is blocking...
  #if defined(__APPLE__)
  call_once_ {
    wxTheApp->CallOnInit();
  };
  #else
  wxTheApp->CallOnInit();
  #endif
  wxTheApp->SetExitOnFrameDelete(false);
  wxInitAllImageHandlers();
  return 0;
}

void xtd::drawing::native::toolkit::shutdown(intptr handle) {
  if (!wxTheApp) return;
  wxImage::CleanUpHandlers();
  wxEntryCleanup();
}

string xtd::drawing::native::toolkit::name() {
  return "wxWidgets";
}

xtd::version xtd::drawing::native::toolkit::version() {
  return xtd::version(wxMAJOR_VERSION, wxMINOR_VERSION, wxRELEASE_NUMBER, wxSUBRELEASE_NUMBER);
}
