#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/progress_bar.h>
#include <xtd/forms/native/progress_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/progress_bar.h"
#include <algorithm>

using namespace xtd;
using namespace xtd::forms;

progress_bar::progress_bar() {
  control_appearance(forms::control_appearance::system);
  set_can_focus(false);
  set_style(control_styles::user_paint | control_styles::use_text_for_accessibility | control_styles::selectable, false);
}

progress_bar& progress_bar::marquee_animation_speed(size_t marquee_animation_speed) {
  if (marquee_animation_speed_ != marquee_animation_speed) {
    marquee_animation_speed_ = marquee_animation_speed;
    if (is_handle_created()) native::progress_bar::marquee(handle(), style_ == progress_bar_style::marquee, marquee_animation_speed_);
  }
  return *this;
}

progress_bar& progress_bar::maximum(int32_t maximum) {
  if (maximum_ != maximum) {
    maximum_ = maximum;
    if (is_handle_created()) native::progress_bar::maximum(handle(), maximum_);
    if (minimum_ > maximum) minimum(maximum);
    if (value_ > maximum) value(maximum);
  }
  return *this;
}

progress_bar& progress_bar::minimum(int32_t minimum) {
  if (minimum_ != minimum) {
    minimum_ = minimum;
    if (is_handle_created()) native::progress_bar::minimum(handle(), minimum_);
    if (maximum_ < minimum) maximum(minimum);
    if (value_ < minimum) value(minimum);
  }
  return *this;
}

progress_bar& progress_bar::orientation(forms::orientation orientation) {
  if (orientation_ != orientation) {
    orientation_ = orientation;
    post_recreate_handle();
  }
  return *this;
}

progress_bar& progress_bar::step(int32_t step) {
  step_ = step;
  return *this;
}

progress_bar& progress_bar::style(progress_bar_style style) {
  if (style_ != style) {
    style_ = style;
    if (is_handle_created()) native::progress_bar::marquee(handle(), style_ == progress_bar_style::marquee, marquee_animation_speed_);
    if (style_ != progress_bar_style::marquee)
      post_recreate_handle();
  }
  return *this;
}

progress_bar& progress_bar::value(int32_t value) {
  if (value_ != value) {
    value_ = std::clamp(value, minimum_, maximum_);
    if (is_handle_created()) native::progress_bar::value(handle(), value_);
  }
  return *this;
}

forms::create_params progress_bar::create_params() const {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("progressbar");
  
  if (style_ == forms::progress_bar_style::continuous) create_params.style(create_params.style() | PBS_SMOOTH);
  if (orientation_ == forms::orientation::vertical) create_params.style(create_params.style() | PBS_VERTICAL);
  
  return create_params;
}

drawing::size progress_bar::default_size() const {
  static auto size = control::default_size();
  return orientation() == forms::orientation::horizontal ? size : drawing::size(size.height(), size.width());
}

void progress_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::progress_bar::maximum(handle(), maximum_);
  native::progress_bar::minimum(handle(), minimum_);
  native::progress_bar::value(handle(), value_);
  native::progress_bar::marquee(handle(), style_ == progress_bar_style::marquee, marquee_animation_speed_);
}
