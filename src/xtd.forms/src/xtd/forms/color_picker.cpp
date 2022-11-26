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
  control_appearance(forms::control_appearance::system);
  set_can_focus(false);
}

void color_picker::color(const drawing::color& value) {
  if (color_ != value) {
    color_ = value;
    if (is_handle_created()) native::color_picker::color(handle(), color_);
    on_color_picker_changed(color_picker_event_args(color_));
  }
}

forms::create_params color_picker::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  create_params.class_name("colorpicker");
  if (alpha_color_) create_params.style(create_params.style() | CC_ALPHACOLOR);
  return create_params;
}

void color_picker::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::color_picker::color(handle(), color_);
}

void color_picker::on_color_picker_changed(const color_picker_event_args& e) {
  if (can_raise_events()) color_picker_changed(*this, e);
}

void color_picker::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: control::wnd_proc(message);
  }
}

void color_picker::wm_command_control(message& message) {
  control::wnd_proc(message);
  switch (HIWORD(message.wparam())) {
    case CPN_SELCHANGE: wm_command_control_selchange(message); break;
    default: break;
  }
}

void color_picker::wm_command_control_selchange(message& message) {
  color_ = native::color_picker::color(handle());
  on_color_picker_changed(color_picker_event_args(color_));
}
