#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/numeric_up_down.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/numeric_up_down.hpp"

using namespace xtd;
using namespace xtd::forms;

numeric_up_down::numeric_up_down() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();
}

forms::create_params numeric_up_down::create_params() const {
  forms::create_params create_params = up_down_base::create_params();
  
  create_params.class_name("numericupdown");
  
  return create_params;
}

numeric_up_down& numeric_up_down::decimal_place(int32_t value) {
  if (decimal_place_ != value) {
    decimal_place_ = value;
    native::numeric_up_down::decimal_place(handle_, decimal_place_);
  }
  return *this;
}

numeric_up_down& numeric_up_down::increment(double value) {
  if (increment_ != value) {
    increment_ = value;
    native::numeric_up_down::increment(handle_, increment_);
  }
  return *this;
}

numeric_up_down& numeric_up_down::maximum(double value) {
  if (maximum_ != value) {
    maximum_ = value;
    native::numeric_up_down::maximum(handle_, maximum_);
    if (minimum_ > value) minimum(value);
    if (value_ > value) this->value(value);
  }
  return *this;
}

numeric_up_down& numeric_up_down::minimum(double value) {
  if (minimum_ != value) {
    minimum_ = value;
    native::numeric_up_down::minimum(handle_, minimum_);
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
    native::numeric_up_down::value(handle_, value_);
  }
  return *this;
}

void numeric_up_down::on_handle_created(const event_args &e) {
  this->scrollable_control::on_handle_created(e);
  native::numeric_up_down::decimal_place(handle_, decimal_place_);
  native::numeric_up_down::increment(handle_, increment_);
  native::numeric_up_down::maximum(handle_, maximum_);
  native::numeric_up_down::minimum(handle_, minimum_);
  native::numeric_up_down::value(handle_, value_);
}

void numeric_up_down::on_text_changed(const event_args& e) {
  value_ = native::numeric_up_down::value(handle_);
  up_down_base::on_text_changed(e);
  on_value_changed(event_args::empty);
}

void numeric_up_down::on_value_changed(const event_args& e) {
  if (this->can_raise_events()) value_changed(*this, e);
}
