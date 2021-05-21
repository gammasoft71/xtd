#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/font_picker.h>
#include <xtd/forms/native/static_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/font_picker.h"

using namespace xtd;
using namespace xtd::forms;

font_picker::font_picker() {
  can_focus_ = false;
  size_ = default_size();
}

control& font_picker::color(const drawing::color& value) {
  if (color_ != value) {
    color_ = value;
    native::font_picker::color(handle(), color_);
    on_font_changed(event_args::empty);
  }
  return *this;
}

control& font_picker::font(const drawing::font& value) {
  if (font_ != value) {
    font_ = value;
    native::font_picker::font(handle(), font_);
    on_font_changed(event_args::empty);
  }
  return *this;
}

forms::create_params font_picker::create_params() const {
  forms::create_params create_params = control::create_params();
  create_params.class_name("fontpicker");
  return create_params;
}

void font_picker::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::font_picker::color(handle(), color_);
  native::font_picker::font(handle(), font_);
}

void font_picker::on_font_changed(const event_args& e) {
  if (can_raise_events()) font_changed(*this, e);
}

void font_picker::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_COMMAND: wm_click(message); break;
    default: control::wnd_proc(message);
  }
}

void font_picker::wm_click(message& message) {
  def_wnd_proc(message);
  color_ = native::font_picker::color(handle());
  font_ = native::font_picker::font(handle());
  on_font_changed(event_args::empty);
}
