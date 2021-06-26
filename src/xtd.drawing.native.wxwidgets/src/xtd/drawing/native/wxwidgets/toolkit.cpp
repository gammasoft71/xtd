#include <xtd/delegate.h>
#include <xtd/event.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/toolkit.h>
#include <xtd/drawing/native/wx_application.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/image.h>
#include <wx/memory.h>
#include <wx/sysopt.h>

using namespace xtd;
using namespace xtd::drawing::native;

intptr_t toolkit::initialize() {
  if (wxTheApp) return 0;
#ifdef _MSC_VER
  // Workaround : Dump memory leak : Remove temporary memory check...
  int current_crt_dbg_flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
  current_crt_dbg_flag &= ~(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
  _CrtSetDbgFlag(current_crt_dbg_flag);
#endif
  wxDISABLE_DEBUG_SUPPORT();
  wxDisableAsserts();
  wxLog::SetLogLevel(wxLOG_Info);
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
