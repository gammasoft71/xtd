#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/color_picker.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/static_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/choose_color_flags.h>
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
  if (alpha_color_) create_params.style(create_params.style() | CC_ALPHACOLOR);
  return create_params;
}

void color_picker::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::color_picker::color(handle(), color_);
}

void color_picker::on_color_changed(const event_args &e) {
  if (can_raise_events()) color_changed(*this, e);
}

void color_picker::wnd_proc(message& message) {
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
