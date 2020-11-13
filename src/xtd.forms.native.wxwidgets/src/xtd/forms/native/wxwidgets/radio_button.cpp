#include <xtd/forms/native/radio_button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_radio_button.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void radio_button::checked(intptr_t control, bool checked) {
  if (control == 0 || reinterpret_cast<wx_radio_button*>(control)->owner_draw_) return;
  wx_radio_button* radio_button = reinterpret_cast<wx_radio_button*>(control);
  if (dynamic_cast<wxRadioButton*>(radio_button->control()) != nullptr) {
    radio_button->hiden_radio_button->SetValue(!checked);
    static_cast<wxRadioButton*>(radio_button->control())->SetValue(checked);
  } else {
    static_cast<wxToggleButton*>(radio_button->control())->SetValue(checked);
  }
}
