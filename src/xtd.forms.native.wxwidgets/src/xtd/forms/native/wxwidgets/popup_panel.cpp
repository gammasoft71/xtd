#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_popup_panel.hpp"
#include <xtd/forms/native/popup_panel>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/popupwin.h>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;
using namespace xtd::helpers;

void popup_panel::ignore_mouse_messages(intptr control, bool value) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxPopup*>(reinterpret_cast<control_handler*>(control)->control())->IgnoreMouseMessages(value);
}

void popup_panel::set_region(intptr control, intptr region) {
  if (!control || !region || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxNonOwnedWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetShape(*reinterpret_cast<wxRegion*>(region));
}

void popup_panel::virtual_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  reinterpret_cast<control_handler*>(control)->main_control()->SetVirtualSize(wxSize(size.width, size.height));
  if (dynamic_cast<wxPopupPanel*>(reinterpret_cast<control_handler*>(control)->main_control())) static_cast<wxPopupPanel*>(reinterpret_cast<control_handler*>(control)->main_control())->SetScrollRate(10, 10);
}
