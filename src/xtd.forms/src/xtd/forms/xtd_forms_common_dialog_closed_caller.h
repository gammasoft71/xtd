#pragma once
#include "../../../include/xtd/forms/common_dialog.h"

struct __xtd_forms_common_dialog_closed_caller__ {
  __xtd_forms_common_dialog_closed_caller__(xtd::forms::common_dialog* common_dialog) : common_dialog_(common_dialog) {}
  void on_common_dialog_closed(bool result) {
    common_dialog_->on_dialog_closed(xtd::forms::dialog_closed_event_args(result ? xtd::forms::dialog_result::ok : xtd::forms::dialog_result::cancel));
    delete this;
  }
private:
  xtd::forms::common_dialog* common_dialog_ = nullptr;
};
