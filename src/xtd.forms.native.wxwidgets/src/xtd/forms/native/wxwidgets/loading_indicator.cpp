#include <stdexcept>
#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/loading_indicator.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_loading_indicator.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

void loading_indicator::start(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxActivityIndicator*>(reinterpret_cast<wx_loading_indicator*>(control)->control())->Start();
}

void loading_indicator::stop(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxActivityIndicator*>(reinterpret_cast<wx_loading_indicator*>(control)->control())->Stop();
}
