#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_check_box.h"
#include <xtd/forms/native/check_box>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <map>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void check_box::check_state(intptr control, int32 state) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  if (dynamic_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr)
    static_cast<wxCheckBox*>(reinterpret_cast<control_handler*>(control)->control())->Set3StateValue([](int32 value)->wxCheckBoxState {return std::map<int32, wxCheckBoxState> {{BST_UNCHECKED, wxCheckBoxState::wxCHK_UNCHECKED}, {BST_CHECKED, wxCheckBoxState::wxCHK_CHECKED}, {BST_INDETERMINATE, wxCheckBoxState::wxCHK_UNDETERMINED}} [value];}(state));
  else
    static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(state);
}
