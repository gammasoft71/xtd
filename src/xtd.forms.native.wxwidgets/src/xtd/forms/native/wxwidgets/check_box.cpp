#include <map>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/check_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_check_box.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void check_box::check_state(intptr_t control, int32_t state) {
  if (control == 0 || reinterpret_cast<wx_check_box*>(control)->owner_draw_) return;
  if (dynamic_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr)
    static_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control())->Set3StateValue([](int value)->wxCheckBoxState {return std::map<int, wxCheckBoxState> {{BST_UNCHECKED, wxCheckBoxState::wxCHK_UNCHECKED}, {BST_CHECKED, wxCheckBoxState::wxCHK_CHECKED}, {BST_INDETERMINATE, wxCheckBoxState::wxCHK_UNDETERMINED}}[value];}(state));
  else
    static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(state);
}
