#include<limits>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/domain_up_down.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_domain_up_down.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void domain_up_down::begin_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void domain_up_down::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetItems().RemoveAt(index);
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->updateSpin();
}

void domain_up_down::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void domain_up_down::insert_item(intptr_t control, size_t index, const std::string& value) {
  if (control == 0) return;
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetItems().Insert({value.c_str(), wxMBConvUTF8()}, index);
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->updateSpin();
}

size_t domain_up_down::selected_index(intptr_t control) {
  if (control == 0) return std::numeric_limits<size_t>::max();
  return static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelectedIndex();
}

void domain_up_down::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelectedIndex(index);
}

void domain_up_down::update_item(intptr_t control, size_t index, const std::string& value) {
  if (control == 0) return;
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetItems()[index] = {value.c_str(), wxMBConvUTF8()};
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->updateSpin();
}
