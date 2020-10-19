#pragma once
#include "../../../include/xtd/forms/common_dialog.h"

struct __xtd_forms_input_dialog_closed_caller__ {
  __xtd_forms_input_dialog_closed_caller__(xtd::forms::common_dialog* common_dialog) : common_dialog_(common_dialog) {}
  void on_input_closed(int32_t result) {
    common_dialog_->on_common_dialog_closed(xtd::forms::common_dialog_closed_event_args(static_cast<xtd::forms::dialog_result>(result)));
    delete this;
  }
private:
  xtd::forms::common_dialog* common_dialog_ = nullptr;
};
