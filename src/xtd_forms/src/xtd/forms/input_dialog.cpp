#include <xtd/forms/native/input_dialog.h>
#include "../../../include/xtd/forms/input_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct __xtd_forms_input_dialog_closed_caller__ {
  __xtd_forms_input_dialog_closed_caller__(input_dialog* input) {}
  void on_input_closed(int32_t result) {input_->input_dialog::on_input_dialog_closed(static_cast<dialog_result>(result));}
  
private:
  input_dialog* input_ = nullptr;
};


void input_dialog::reset() {
  caption_ = "";
  multiline_ = false;
  text_ = "";
  use_system_password_char_ = false;
  value_ = "";
}

dialog_result input_dialog::show_dialog() {
  return static_cast<dialog_result>(native::input_dialog::show_dialog(0, text_, caption_, value_, multiline_, use_system_password_char_));
}

dialog_result input_dialog::show_dialog(const iwin32_window& owner) {
  return static_cast<dialog_result>(native::input_dialog::show_dialog(owner.handle(), text_, caption_, value_, multiline_, use_system_password_char_));
}

void input_dialog::show_sheet_dialog(const iwin32_window& owner) {
  native::input_dialog::show_sheet_dialog({__xtd_forms_input_dialog_closed_caller__(this), &__xtd_forms_input_dialog_closed_caller__::on_input_closed}, owner.handle(), text_, caption_, value_, multiline_, use_system_password_char_);
}
