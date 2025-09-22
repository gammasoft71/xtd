#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_light_button.hpp"
#include <xtd/forms/native/light_button>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms::native;
using namespace xtd::helpers;

void light_button::check_state(intptr control, int32 state) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().chars().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
}
