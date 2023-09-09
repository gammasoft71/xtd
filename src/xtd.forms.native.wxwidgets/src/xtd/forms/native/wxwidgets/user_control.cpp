#include <stdexcept>
#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/user_control.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_user_control.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void user_control::virtual_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetVirtualSize(wxSize(size.width(), size.height()));
  if (dynamic_cast<wxScrolled<wx_user_panel>*>(reinterpret_cast<control_handler*>(control)->control())) static_cast<wxScrolled<wx_user_panel>*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollRate(10, 10);
}
