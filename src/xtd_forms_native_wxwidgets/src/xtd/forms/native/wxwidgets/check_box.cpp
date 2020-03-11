#include <xtd/forms/native/check_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_check_box.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  wxCheckBoxState to_check_box_state(int value) {
    switch (value) {
      case BST_UNCHECKED: return wxCheckBoxState::wxCHK_UNCHECKED;
      case BST_CHECKED: return wxCheckBoxState::wxCHK_CHECKED;
      case BST_INDETERMINATE: return wxCheckBoxState::wxCHK_UNDETERMINED;
      default: return wxCheckBoxState::wxCHK_UNCHECKED;
    }
  }
  
  int from_check_box_state(wxCheckBoxState value) {
    switch (value) {
      case wxCheckBoxState::wxCHK_UNCHECKED: return BST_UNCHECKED;
      case wxCheckBoxState::wxCHK_CHECKED: return BST_CHECKED;
      case wxCheckBoxState::wxCHK_UNDETERMINED: return BST_INDETERMINATE;
      default: return BST_UNCHECKED;
    }
  }
}

int check_box::check_state(intptr_t control) {
  if (control == 0) return false;
  if (dynamic_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr)
    return from_check_box_state(static_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control())->Get3StateValue());
  else
    return static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}

void check_box::check_state(intptr_t control, int state) {
  if (control == 0) return;
  if (dynamic_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr)
    static_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control())->Set3StateValue(to_check_box_state(state));
  else
    static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(state);
}
