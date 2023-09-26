#pragma once
#include "../../../include/xtd/forms/message_dialog"

struct __xtd_forms_message_dialog_closed_caller__ {
  explicit __xtd_forms_message_dialog_closed_caller__(xtd::forms::message_dialog* message_dialog) : message_dialog_(message_dialog) {}
  void on_dialog_closed(xtd::int32 result) {
    message_dialog_->on_dialog_closed(xtd::forms::dialog_closed_event_args(static_cast<xtd::forms::dialog_result>(result)));
    delete this;
  }
private:
  xtd::forms::message_dialog* message_dialog_ = nullptr;
};
