#include <xtd/forms/native/color_dialog.h>
#include "../../../include/xtd/forms/color_dialog.h"

using namespace xtd;
using namespace xtd::forms;

void color_dialog::reset() {
  dialog_result_ = xtd::forms::dialog_result::none;
  color_ = drawing::color::black;
  custom_colors_.reset();
  options_ = CC_ALPHACOLOR | CC_PREVENTFULLOPEN;
}

bool color_dialog::run_dialog(intptr_t owner) {
  return native::color_dialog::run_dialog(owner, color_, custom_colors_, options_);
}

void color_dialog::run_sheet_dialog(intptr_t owner) {
  /// @todo call native::color_dialog::run_sheeet_dialog and catch close event...
  on_common_dialog_closed(common_dialog_closed_event_args(native::color_dialog::run_dialog(owner, color_, custom_colors_, options_) ? dialog_result::ok : dialog_result::cancel));
}
