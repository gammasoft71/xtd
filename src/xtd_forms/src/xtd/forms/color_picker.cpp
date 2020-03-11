#include <xtd/forms/native/control.h>
#include <xtd/forms/native/color_picker.h>
#include <xtd/forms/native/static_styles.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/color_picker.h"

using namespace xtd;
using namespace xtd::forms;

color_picker::color_picker() {
  can_focus_ = false;
  size_ = default_size();
}

void color_picker::color(const drawing::color& value) {
  if (color_ != value) {
    color_ = value;
    native::color_picker::color(handle(), color_);
    on_color_changed(event_args::empty);
  }
}

forms::create_params color_picker::create_params() const {
  forms::create_params create_params = control::create_params();
  create_params.class_name("colorpicker");
  return create_params;
}

void color_picker::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::color_picker::color(handle(), color_);
}

void color_picker::on_color_changed(const event_args &e) {
  if (this->can_raise_events()) this->color_changed(*this, e);
}

void color_picker::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_COMMAND: wm_click(message); break;
    default: control::wnd_proc(message);
  }
}

void color_picker::wm_click(message& message) {
  def_wnd_proc(message);
  color_ = native::color_picker::color(handle());
  on_color_changed(event_args::empty);
}
