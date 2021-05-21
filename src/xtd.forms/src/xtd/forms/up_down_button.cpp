#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/up_down_button.h>
#include <xtd/forms/native/up_down_styles.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/scroll_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/up_down_button.h"

using namespace xtd;
using namespace xtd::forms;

up_down_button::up_down_button() {
  size_ = default_size();
}

forms::create_params up_down_button::create_params() const {
  forms::create_params create_params = button_base::create_params();
  
  create_params.class_name("updownbutton");
  
  if (orientation_ == forms::orientation::horizontal) create_params.style(create_params.style() | UDS_HORZ);
  if (wrapped_) create_params.style(create_params.style() | UDS_WRAP);

  return create_params;
}

up_down_button& up_down_button::maximum(int32_t value) {
  if (maximum_ != value) {
    maximum_ = value;
    native::up_down_button::maximum(handle(), maximum_);
    if (minimum_ > value) minimum(value);
    if (value_ > value) this->value(value);
  }
  return *this;
}

up_down_button& up_down_button::minimum(int32_t value) {
  if (minimum_ != value) {
    minimum_ = value;
    native::up_down_button::minimum(handle(), minimum_);
    if (maximum_ < value) maximum(value);
    if (value_ < value) this->value(value);
  }
  return *this;
}

up_down_button& up_down_button::orientation(forms::orientation orientation) {
  if (orientation_ != orientation) {
    orientation_ = orientation;
    recreate_handle();
  }
  return *this;
}

up_down_button& up_down_button::wrapped(bool value) {
  if (wrapped_ != value) {
    wrapped_ = value;
    recreate_handle();
  }
  return *this;
}

up_down_button& up_down_button::value(int32_t value) {
  if (value_ != value) {
    if (value > maximum_)
      value_ = maximum_;
    if (value < minimum_)
      value_ = minimum_;
    else
      value_ = value;
    native::up_down_button::value(handle(), value_);
    on_value_changed(event_args::empty);
  }
  return *this;
}

void up_down_button::on_handle_created(const event_args &e) {
  button_base::on_handle_created(e);
  native::up_down_button::maximum(handle(), maximum_);
  native::up_down_button::minimum(handle(), minimum_);
  native::up_down_button::value(handle(), value_);
}

void up_down_button::on_scroll(const event_args& e) {
  if (can_raise_events()) scroll(*this, e);
}

void up_down_button::on_value_changed(const event_args& e) {
  if (can_raise_events()) value_changed(*this, e);
}

void up_down_button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_HSCROLL:
    case WM_REFLECT + WM_VSCROLL: wm_scroll(message); break;
    default: control::wnd_proc(message);
  }
}

void up_down_button::wm_scroll(message &message) {
  if (message.wparam() == SB_LINEDOWN) value_ = value_ > minimum_ ? value_ - 1 : maximum_;
  if (message.wparam() == SB_LINEUP) value_ = value_ < maximum_ ? value_ + 1 : minimum_;
  on_scroll(event_args::empty);
  on_value_changed(event_args::empty);
  control::def_wnd_proc(message);
}
