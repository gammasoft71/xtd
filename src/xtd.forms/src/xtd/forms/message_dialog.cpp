#include <chrono>
#include <thread>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/message_box.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/message_dialog.h"
#include "xtd_forms_message_dialog_closed_caller.h"

using namespace std;
using namespace std::literals;
using namespace std::this_thread;
using namespace xtd;
using namespace xtd::forms;

void message_dialog::reset() {
  buttons_ = xtd::forms::message_dialog_buttons::ok;
  default_button_ = xtd::forms::message_dialog_default_button::button1;
  dialog_style_ = xtd::forms::dialog_style::standard;
  display_help_button_ = false;
  icon_ = xtd::forms::message_dialog_icon::none;
  options_ = static_cast<xtd::forms::message_dialog_options>(0);
  message_ = "";
  text_ = "";
}

xtd::forms::dialog_result message_dialog::show_dialog() {
  on_dialog_closed(dialog_closed_event_args(static_cast<xtd::forms::dialog_result>(native::message_box::show(0, message_, text_, static_cast<uint32_t>(buttons_) + static_cast<uint32_t>(icon_) + static_cast<uint32_t>(default_button_) + static_cast<uint32_t>(options_), display_help_button_))));
  return dialog_result_;
}

xtd::forms::dialog_result message_dialog::show_dialog(const iwin32_window& owner) {
  on_dialog_closed(dialog_closed_event_args(static_cast<xtd::forms::dialog_result>(native::message_box::show(owner.handle(), message_, text_, static_cast<uint32_t>(buttons_) + static_cast<uint32_t>(icon_) + static_cast<uint32_t>(default_button_) + static_cast<uint32_t>(options_), display_help_button_))));
  return dialog_result_;
}

void message_dialog::show_sheet(const iwin32_window& owner) {
  dialog_result_ = xtd::forms::dialog_result::none;
  native::message_box::show_sheet({*new __xtd_forms_message_dialog_closed_caller__(this), &__xtd_forms_message_dialog_closed_caller__::on_dialog_closed}, owner.handle(), message_, text_, static_cast<uint32_t>(buttons_) + static_cast<uint32_t>(icon_) + static_cast<uint32_t>(default_button_) + static_cast<uint32_t>(options_), display_help_button_);
}

xtd::forms::dialog_result message_dialog::show_sheet_dialog(const iwin32_window& owner) {
  show_sheet(owner);
  while(dialog_result_ == xtd::forms::dialog_result::none) {
    application::do_events();
    sleep_for(100ms);
  }
  return dialog_result_;
}
