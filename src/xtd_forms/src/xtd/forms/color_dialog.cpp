#include <xtd/forms/native/color_dialog.h>
#include "../../../include/xtd/forms/color_dialog.h"

using namespace xtd;
using namespace xtd::forms;

void color_dialog::reset() {
  this->color_ = drawing::color::black;
  this->custom_colors_.reset();
  this->options_ = CC_ALPHACOLOR | CC_PREVENTFULLOPEN;
}

bool color_dialog::run_dialog(intptr_t owner) {
  return native::color_dialog::run_dialog(owner, this->color_, this->custom_colors_, this->options_);
}
