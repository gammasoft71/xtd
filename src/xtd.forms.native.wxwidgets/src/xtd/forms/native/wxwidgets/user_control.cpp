#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_user_control.hpp"
#include <xtd/forms/native/user_control>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void user_control::virtual_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetVirtualSize(wxSize(size.width, size.height));
  if (dynamic_cast<wxScrolled<wx_user_panel>*>(reinterpret_cast<control_handler*>(control)->control())) static_cast<wxScrolled<wx_user_panel>*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollRate(10, 10);
}
