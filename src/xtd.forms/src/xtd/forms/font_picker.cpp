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
  control_appearance(forms::control_appearance::system);
}

const drawing::color& font_picker::color() const noexcept {
  return data_->color;
}

control& font_picker::color(const drawing::color& value) {
  if (data_->color != value) {
    data_->color = value;
    if (is_handle_created()) native::font_picker::color(handle(), data_->color);
    on_font_picker_changed(font_picker_event_args(data_->font, data_->color));
  }
  return *this;
}

drawing::font font_picker::font() const noexcept {
  return data_->font;
}

control& font_picker::font(const drawing::font& value) {
  if (data_->font != value) {
    data_->font = value;
    if (is_handle_created()) native::font_picker::font(handle(), data_->font);
    on_font_picker_changed(font_picker_event_args(data_->font, data_->color));
  }
  return *this;
}

forms::create_params font_picker::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  create_params.class_name("fontpicker");
  return create_params;
}

void font_picker::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  if (is_handle_created()) {
    native::font_picker::color(handle(), data_->color);
    native::font_picker::font(handle(), data_->font);
  }
}

void font_picker::on_font_picker_changed(const font_picker_event_args& e) {
  if (can_raise_events()) font_picker_changed(*this, e);
}

void font_picker::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: control::wnd_proc(message);
  }
}

void font_picker::wm_command_control(message& message) {
  control::wnd_proc(message);
  switch (HIWORD(message.wparam())) {
    case FPN_SELCHANGE: wm_command_control_selchange(message); break;
    default: break;
  }
}

void font_picker::wm_command_control_selchange(message& message) {
  data_->color = native::font_picker::color(handle());
  data_->font = native::font_picker::font(handle());
  on_font_picker_changed(font_picker_event_args(data_->font, data_->color));
}
