#include <xtd/forms/native/radio_button.hpp>
#include "wx_radio_button.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

bool radio_button::checked(intptr_t control) {
  if (control == 0) return false;
  if (dynamic_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control()) != nullptr)
    return static_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  return static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}

void radio_button::checked(intptr_t control, bool checked) {
  if (control == 0) return;
  control_handler* ctrl = reinterpret_cast<control_handler*>(control);
  if (dynamic_cast<wxRadioButton*>(ctrl->control()) != nullptr) {
    reinterpret_cast<wx_radio_button*>(control)->hiden_radio_button->SetValue(!checked);
    static_cast<wxRadioButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(checked);
  } else {
    reinterpret_cast<wx_radio_button*>(control)->hiden_radio_button->SetValue(checked);
    static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(checked);
  }
}
