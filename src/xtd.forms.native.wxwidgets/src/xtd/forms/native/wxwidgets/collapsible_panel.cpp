#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_collapsible_panel.hpp"
#include <xtd/forms/native/collapsible_panel>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;
using namespace xtd::helpers;

bool collapsible_panel::expanded(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return false;
  }
  return !static_cast<wxScrolled<wxCollapsiblePane>*>(reinterpret_cast<control_handler*>(control)->control())->IsCollapsed();
}

void collapsible_panel::expanded(intptr control, bool expand) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxScrolled<wxCollapsiblePane>*>(reinterpret_cast<control_handler*>(control)->control())->Collapse(!expand);
}
