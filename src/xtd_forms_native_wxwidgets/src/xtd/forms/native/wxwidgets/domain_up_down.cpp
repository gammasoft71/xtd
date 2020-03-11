#include <xtd/forms/native/domain_up_down.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_domain_up_down.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void domain_up_down::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetItems().RemoveAt(index);
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->updateSpin();
}

void domain_up_down::insert_item(intptr_t control, size_t index, const std::string& value) {
  if (control == 0) return;
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetItems().Insert({value.c_str(), wxMBConvUTF8()}, index);
  static_cast<wxDomainSpinCtrl*>(reinterpret_cast<control_handler*>(control)->control())->updateSpin();
}

size_t domain_up_down::selected_index(intptr_t control) {
  if (control == 0) return -1;
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
