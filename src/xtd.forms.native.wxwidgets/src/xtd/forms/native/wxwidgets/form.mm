#if defined(__WXOSX__)
#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_form"
#include <xtd/forms/native/form>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <AppKit/AppKit.h>

using namespace xtd;
using namespace xtd::forms::native;

bool __toggle_full_screen_frame__(wxTopLevelWindow* control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  return ([[control->GetHandle() window] styleMask] & NSWindowStyleMaskFullScreen) == NSWindowStyleMaskFullScreen;
}

void __toggle_full_screen_frame__(wxTopLevelWindow* control, bool full_screen) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (full_screen != __toggle_full_screen_frame__(control)) [[control->GetHandle() window] toggleFullScreen:[control->GetHandle() window]];
}
#endif
