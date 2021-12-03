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
  data_->dialog_style = xtd::forms::dialog_style::standard;
  data_->icon = xtd::drawing::image::empty;
  data_->text = "";
  data_->description = "";
}

void busy_dialog::show() {
  data_->native = data_->dialog_style == xtd::forms::dialog_style::system;
  if (data_->native)
    data_->handle = native::busy_dialog::create(0, xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->text, data_->description, data_->back_color, data_->fore_color, data_->opacity);
  application::do_events();
}

void busy_dialog::show(const iwin32_window& owner) {
  data_->native = data_->dialog_style == xtd::forms::dialog_style::system;
  if (data_->native)
    data_->handle = native::busy_dialog::create(owner.handle(), xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->text, data_->description, data_->back_color, data_->fore_color, data_->opacity);
  application::do_events();
}

void busy_dialog::hide() {
  if (!data_->handle) return;
  if (data_->native) native::busy_dialog::destroy(data_->handle);
  data_->native = false;
  data_->handle = 0;
}
