#include <memory>
#include <xtd/forms/native/busy_dialog.h>
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/busy_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
}

void busy_dialog::reset() {
  dialog_style_ = xtd::forms::dialog_style::standard;
  icon_ = xtd::drawing::image::empty;
  text_ = "";
  description_ = "";
}

void busy_dialog::show() {
  native_ = dialog_style_ == xtd::forms::dialog_style::system;
  if (native_)
    handle_ = native::busy_dialog::create(0, xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)), text_, description_, back_color_, fore_color_, transparency_);
}

void busy_dialog::show(const iwin32_window& owner) {
  native_ = dialog_style_ == xtd::forms::dialog_style::system;
  if (native_)
    handle_ = native::busy_dialog::create(owner.handle(), xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)), text_, description_, back_color_, fore_color_, transparency_);
}

void busy_dialog::hide() {
  if (!handle_) return;
  if (native_) native::busy_dialog::destroy(handle_);
  native_ = false;
  handle_ = 0;
}
