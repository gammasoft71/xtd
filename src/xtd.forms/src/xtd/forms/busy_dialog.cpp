#include <memory>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/busy_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/busy_box.h"
#include "../../../include/xtd/forms/busy_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
}

busy_dialog* busy_box::dialog_ = nullptr;

void busy_dialog::reset() {
  dialog_style_ = xtd::forms::dialog_style::standard;
  icon_ = xtd::drawing::image::empty;
  text_ = "";
  description_ = "";
}

void busy_dialog::show() {
  native_ = dialog_style_ == xtd::forms::dialog_style::system;
  if (native_)
    handle_ = native::busy_dialog::create(0, xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)), text_, description_, back_color_, fore_color_, opacity_);
  application::do_events();
}

void busy_dialog::show(const iwin32_window& owner) {
  native_ = dialog_style_ == xtd::forms::dialog_style::system;
  if (native_)
    handle_ = native::busy_dialog::create(owner.handle(), xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)), text_, description_, back_color_, fore_color_, opacity_);
  application::do_events();
}

void busy_dialog::hide() {
  if (!handle_) return;
  if (native_) native::busy_dialog::destroy(handle_);
  native_ = false;
  handle_ = 0;
}
