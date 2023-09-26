#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_radio_button"
#include <xtd/forms/native/radio_button>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void radio_button::checked(intptr control, bool checked) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  wx_radio_button* radio_button = reinterpret_cast<wx_radio_button*>(control);
  if (dynamic_cast<wxRadioButton*>(radio_button->control()) != nullptr) {
    radio_button->hidden_radio_button->SetValue(!checked);
    static_cast<wxRadioButton*>(radio_button->control())->SetValue(checked);
  } else
    static_cast<wxToggleButton*>(radio_button->control())->SetValue(checked);
}
