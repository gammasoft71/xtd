#include <xtd/forms/native/progress_bar.hpp>
#include <xtd/forms/native/window_progress_bar.hpp>
#include "../../../include/xtd/forms/progress_bar.hpp"

using namespace xtd;
using namespace xtd::forms;

progress_bar::progress_bar() {
  this->make_control(*this);
  this->control::data_->size_ = this->default_size();
}

progress_bar& progress_bar::operator=(const progress_bar& value) {
  this->control::operator=(value);
  this->data_ = value.data_;
  return *this;
}

progress_bar& progress_bar::marquee_animation_speed(size_t marquee_animation_speed) {
  if (this->data_->marquee_animation_speed_ != marquee_animation_speed) {
    this->data_->marquee_animation_speed_ = marquee_animation_speed;
    native::progress_bar::marquee(this->control::data_->handle_, this->data_->style_ == progress_bar_style::marquee, this->data_->marquee_animation_speed_);
  }
  return *this;
}

progress_bar& progress_bar::maximum(int32_t maximum) {
  if (this->data_->maximum_ != maximum) {
    this->data_->maximum_ = maximum;
    native::progress_bar::maximum(this->control::data_->handle_, this->data_->maximum_);
    if (this->data_->minimum_ > maximum) this->minimum(maximum);
    if (this->data_->value_ > maximum) this->value(maximum);
  }
  return *this;
}

progress_bar& progress_bar::minimum(int32_t minimum) {
  if (this->data_->minimum_ != minimum) {
    this->data_->minimum_ = minimum;
    native::progress_bar::minimum(this->control::data_->handle_, this->data_->minimum_);
    if (this->data_->maximum_ < minimum) this->maximum(minimum);
    if (this->data_->value_ < minimum) this->value(minimum);
  }
  return *this;
}

progress_bar& progress_bar::orientation(forms::orientation orientation) {
  if (this->data_->orientation_ != orientation) {
    this->data_->orientation_ = orientation;
    this->recreate_handle();
  }
  return *this;
}

progress_bar& progress_bar::step(int32_t step) {
  if (this->data_->step_ != step)
    this->data_->step_ = step;
  return *this;
}

progress_bar& progress_bar::style(progress_bar_style style) {
  if (this->data_->style_ != style) {
    this->data_->style_ = style;
    native::progress_bar::marquee(this->control::data_->handle_, this->data_->style_ == progress_bar_style::marquee, this->data_->marquee_animation_speed_);
    if (this->data_->style_ != progress_bar_style::marquee)
      this->recreate_handle();
  }
  return *this;
}

progress_bar& progress_bar::value(int32_t value) {
  if (this->data_->value_ != value) {
    if (value > this->data_->maximum_)
      this->data_->value_ = this->data_->maximum_;
    if (value < this->data_->minimum_)
      this->data_->value_ = this->data_->minimum_;
    else
      this->data_->value_ = value;
    native::progress_bar::value(this->control::data_->handle_, this->data_->value_);
  }
  return *this;
}

forms::create_params progress_bar::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("progressbar");
  
  if (this->data_->style_ == forms::progress_bar_style::continuous) create_params.style(create_params.style() | PBS_SMOOTH);
  if (this->data_->orientation_ == forms::orientation::vertical) create_params.style(create_params.style() | PBS_VERTICAL);

  return create_params;
}

void progress_bar::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  native::progress_bar::maximum(this->control::data_->handle_, this->data_->maximum_);
  native::progress_bar::minimum(this->control::data_->handle_, this->data_->minimum_);
  native::progress_bar::value(this->control::data_->handle_, this->data_->value_);
  native::progress_bar::marquee(this->control::data_->handle_, this->data_->style_ == progress_bar_style::marquee, this->data_->marquee_animation_speed_);
}
