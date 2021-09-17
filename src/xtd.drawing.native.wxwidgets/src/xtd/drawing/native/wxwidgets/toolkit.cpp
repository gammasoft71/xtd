#include <xtd/delegate.h>
#include <xtd/event.h>
#include <xtd/diagnostics/boolean_switch.h>
#include <xtd/diagnostics/debug.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/toolkit.h>
#include <xtd/drawing/native/wx_application.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/image.h>
#include <wx/memory.h>
#include <wx/sysopt.h>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing::native;

namespace {
  wxAssertHandler_t original_assert_handler = nullptr;
  boolean_switch show_wx_assert("wx_assert", "Shows wxAssert log", "true");
  
  void xtd_assert_handler(const wxString& file, int line, const wxString& func, const wxString& cond, const wxString& msg) {
    debug::write_line_if(show_wx_assert.enabled(), "wxAssert");
    debug::write_line_if(show_wx_assert.enabled(), "--------");
    debug::write_line_if(show_wx_assert.enabled(), ustring::format("cond={}, msg={}", cond, msg));
    debug::write_line_if(show_wx_assert.enabled(), ustring::format("  at {} in {}:line {}", func, file, line));
  }
}

intptr_t toolkit::initialize() {
  if (wxTheApp) return 0;
#ifdef _MSC_VER
  // Workaround : Dump memory leak : Remove temporary memory check...
  _CrtSetDbgFlag(_CRTDBG_CHECK_DEFAULT_DF);
#endif
  wxDISABLE_DEBUG_SUPPORT();
  original_assert_handler = wxSetAssertHandler(&xtd_assert_handler);
  wxLog::SetLogLevel(wxLOG_Info);
  wxSystemOptions::SetOption("gtk.tlw.can-set-transparent", 1);
  wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
  wxApp::SetInstance(new wx_application());
  int argc = 0;
  wxEntryStart(argc, (wxChar**)nullptr);
  wxTheApp->CallOnInit();
  wxTheApp->SetExitOnFrameDelete(false);
  wxInitAllImageHandlers();
  return 0;
}

void toolkit::shutdown(intptr_t handle) {
  if (!wxTheApp) return;

  wxImage::CleanUpHandlers();
  wxTheApp->OnExit();
  wxApp::SetInstance(nullptr);
  delete wxTheApp;
}
