#include <xtd/forms/native/input_dialog.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/input_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct __xtd_forms_input_dialog_closed_caller__ {
  __xtd_forms_input_dialog_closed_caller__(xtd::forms::input_dialog* input_dialog) : input_dialog_(input_dialog) {}
  void on_input_closed(int32_t result, const std::string& value) {
    input_dialog_->input_dialog::on_input_dialog_closed(input_dialog_closed_event_args(static_cast<dialog_result>(result), value));
    delete this;
  }
private:
  xtd::forms::input_dialog* input_dialog_ = nullptr;
};


void input_dialog::reset() {
  caption_ = "";
  multiline_ = false;
  text_ = "";
  use_system_password_char_ = false;
  value_ = "";
}

dialog_result input_dialog::show_dialog() {
  application::raise_enter_thread_modal(event_args::empty);
  auto result = static_cast<dialog_result>(native::input_dialog::show_dialog(0, text_, caption_, value_, multiline_, use_system_password_char_));
  on_input_dialog_closed(input_dialog_closed_event_args(result, value_));
  return result;
}

dialog_result input_dialog::show_dialog(const iwin32_window& owner) {
  application::raise_enter_thread_modal(event_args::empty);
  auto result = static_cast<dialog_result>(native::input_dialog::show_dialog(owner.handle(), text_, caption_, value_, multiline_, use_system_password_char_));
  on_input_dialog_closed(input_dialog_closed_event_args(result, value_));
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

void input_dialog::show_sheet_dialog(const iwin32_window& owner) {
  application::raise_enter_thread_modal(event_args::empty);
  native::input_dialog::show_sheet_dialog({*new __xtd_forms_input_dialog_closed_caller__(this), &__xtd_forms_input_dialog_closed_caller__::on_input_closed}, owner.handle(), text_, caption_, value_, multiline_, use_system_password_char_);
  application::raise_leave_thread_modal(event_args::empty);
}
