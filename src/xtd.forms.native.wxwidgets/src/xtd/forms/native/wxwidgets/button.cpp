#include <xtd/argument_exception.h>
#include <xtd/cdebug.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

void button::set_default_button(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetDefault();
}
