#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_domain_up_down.hpp"
#include <xtd/forms/native/domain_up_down>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include<limits>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;
using namespace xtd::helpers;

void domain_up_down::begin_update(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void domain_up_down::delete_item(intptr control, size_t index) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetItems().RemoveAt(index);
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->updateSpin();
}

void domain_up_down::end_update(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void domain_up_down::insert_item(intptr control, size_t index, const string& value) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetItems().Insert(xtd::convert_string::to_wstring(value).chars().c_str(), index);
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->updateSpin();
}

size_t domain_up_down::selected_index(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return 0;
  }
  return static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelectedIndex();
}

void domain_up_down::selected_index(intptr control, size_t index) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  return static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelectedIndex(index);
}

void domain_up_down::update_item(intptr control, size_t index, const string& value) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetItems()[index] = xtd::convert_string::to_wstring(value).chars().c_str();
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->updateSpin();
}
