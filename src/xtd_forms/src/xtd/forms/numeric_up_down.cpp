#include <xtd/forms/native/control.h>
#include <xtd/forms/native/numeric_up_down.h>
#include <xtd/forms/native/up_down_styles.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/numeric_up_down.h"

using namespace xtd;
using namespace xtd::forms;

numeric_up_down::numeric_up_down() {
  //this->back_color_ = this->default_back_color();
  //this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();
}

forms::create_params numeric_up_down::create_params() const {
  forms::create_params create_params = up_down_base::create_params();
  
  create_params.class_name("numericupdown");
  
  if (wrapped_) create_params.style(create_params.style() | UDS_WRAP);
  
  return create_params;
}

numeric_up_down& numeric_up_down::decimal_place(int32_t value) {
  if (decimal_place_ != value) {
    decimal_place_ = value;
    native::numeric_up_down::decimal_place(handle(), decimal_place_);
  }
  return *this;
}

numeric_up_down& numeric_up_down::increment(double value) {
  if (increment_ != value) {
    increment_ = value;
    native::numeric_up_down::increment(handle(), increment_);
  }
  return *this;
}

numeric_up_down& numeric_up_down::maximum(double value) {
  if (maximum_ != value) {
    maximum_ = value;
    native::numeric_up_down::maximum(handle(), maximum_);
    if (minimum_ > value) minimum(value);
    if (value_ > value) this->value(value);
  }
  return *this;
}

numeric_up_down& numeric_up_down::minimum(double value) {
  if (minimum_ != value) {
    minimum_ = value;
    native::numeric_up_down::minimum(handle(), minimum_);
    if (maximum_ < value) maximum(value);
    if (value_ < value) this->value(value);
  }
  return *this;
}

numeric_up_down& numeric_up_down::value(double value) {
  if (value_ != value) {
    if (value > maximum_)
      value_ = maximum_;
    if (value < minimum_)
      value_ = minimum_;
    else
      value_ = value;
    native::numeric_up_down::value(handle(), value_);
    on_value_changed(event_args::empty);
  }
  return *this;
}

numeric_up_down& numeric_up_down::wrapped(bool value) {
  if (this->wrapped_ != value) {
    this->wrapped_ = value;
    this->recreate_handle();
  }
  return *this;
}

void numeric_up_down::on_handle_created(const event_args &e) {
  this->scrollable_control::on_handle_created(e);
  native::numeric_up_down::decimal_place(handle(), decimal_place_);
  native::numeric_up_down::increment(handle(), increment_);
  native::numeric_up_down::maximum(handle(), maximum_);
  native::numeric_up_down::minimum(handle(), minimum_);
  native::numeric_up_down::value(handle(), value_);
}

void numeric_up_down::on_value_changed(const event_args& e) {
  if (this->can_raise_events()) value_changed(*this, e);
}


void numeric_up_down::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_COMMAND: this->wm_command(message); break;
    default: up_down_base::wnd_proc(message);
  }
}

void numeric_up_down::wm_command(message& message) {
  this->def_wnd_proc(message);
  if (value_ != native::numeric_up_down::value(handle())) {
    value_ = native::numeric_up_down::value(handle());
    on_value_changed(event_args::empty);
  }
}
