#include "../../../include/xtd/forms/xtd_about_box.h"
#include "../../../include/xtd/forms/xtd_about_dialog.h"

using namespace xtd;
using namespace xtd::forms;

void xtd_about_box::show(const iwin32_window& owner) {
  static auto dialog = xtd_about_dialog {};
  dialog.show(owner);
}

void xtd_about_box::show() {
  static auto dialog = xtd_about_dialog {};
  dialog.show();
}
