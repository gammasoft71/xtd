#include <stdexcept>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/loading_indicator.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_loading_indicator.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

void loading_indicator::start(intptr_t control) {
  if (control == 0 || reinterpret_cast<wx_loading_indicator*>(control)->owner_draw_) return;
  static_cast<wxActivityIndicator*>(reinterpret_cast<wx_loading_indicator*>(control)->control())->Start();
}

void loading_indicator::stop(intptr_t control) {
  if (control == 0 || reinterpret_cast<wx_loading_indicator*>(control)->owner_draw_) return;
  static_cast<wxActivityIndicator*>(reinterpret_cast<wx_loading_indicator*>(control)->control())->Stop();
}
