#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_loading_indicator.hpp"
#include <xtd/forms/native/application>
#include <xtd/forms/native/loading_indicator>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms::native;
using namespace xtd::helpers;

void loading_indicator::start(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxActivityIndicator*>(reinterpret_cast<wx_loading_indicator*>(control)->control())->Start();
}

void loading_indicator::stop(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxActivityIndicator*>(reinterpret_cast<wx_loading_indicator*>(control)->control())->Stop();
}
