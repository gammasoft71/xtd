#include <xtd/forms/native/progress_bar.h>
#include <xtd/forms/native/progress_bar_styles.h>
#include "../../../include/xtd/forms/progress_bar.h"

using namespace xtd;
using namespace xtd::forms;

progress_bar::progress_bar() {
  this->can_focus_ = false;
  this->size_ = this->default_size();
}

progress_bar& progress_bar::marquee_animation_speed(size_t marquee_animation_speed) {
  if (this->marquee_animation_speed_ != marquee_animation_speed) {
    this->marquee_animation_speed_ = marquee_animation_speed;
    native::progress_bar::marquee(handle(), this->style_ == progress_bar_style::marquee, this->marquee_animation_speed_);
  }
  return *this;
}

progress_bar& progress_bar::maximum(int32_t maximum) {
  if (this->maximum_ != maximum) {
    this->maximum_ = maximum;
    native::progress_bar::maximum(handle(), this->maximum_);
    if (this->minimum_ > maximum) this->minimum(maximum);
    if (this->value_ > maximum) this->value(maximum);
  }
  return *this;
}

progress_bar& progress_bar::minimum(int32_t minimum) {
  if (this->minimum_ != minimum) {
    this->minimum_ = minimum;
    native::progress_bar::minimum(handle(), this->minimum_);
    if (this->maximum_ < minimum) this->maximum(minimum);
    if (this->value_ < minimum) this->value(minimum);
  }
  return *this;
}

progress_bar& progress_bar::orientation(forms::orientation orientation) {
  if (this->orientation_ != orientation) {
    this->orientation_ = orientation;
    this->recreate_handle();
  }
  return *this;
}

progress_bar& progress_bar::step(int32_t step) {
  if (this->step_ != step)
    this->step_ = step;
  return *this;
}

progress_bar& progress_bar::style(progress_bar_style style) {
  if (this->style_ != style) {
    this->style_ = style;
    native::progress_bar::marquee(handle(), this->style_ == progress_bar_style::marquee, this->marquee_animation_speed_);
    if (this->style_ != progress_bar_style::marquee)
      this->recreate_handle();
  }
  return *this;
}

progress_bar& progress_bar::value(int32_t value) {
  if (this->value_ != value) {
    if (value > this->maximum_)
      this->value_ = this->maximum_;
    if (value < this->minimum_)
      this->value_ = this->minimum_;
    else
      this->value_ = value;
    native::progress_bar::value(handle(), this->value_);
  }
  return *this;
}

forms::create_params progress_bar::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("progressbar");
  
  if (this->style_ == forms::progress_bar_style::continuous) create_params.style(create_params.style() | PBS_SMOOTH);
  if (this->orientation_ == forms::orientation::vertical) create_params.style(create_params.style() | PBS_VERTICAL);

  return create_params;
}

void progress_bar::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  native::progress_bar::maximum(handle(), this->maximum_);
  native::progress_bar::minimum(handle(), this->minimum_);
  native::progress_bar::value(handle(), this->value_);
  native::progress_bar::marquee(handle(), this->style_ == progress_bar_style::marquee, this->marquee_animation_speed_);
}
