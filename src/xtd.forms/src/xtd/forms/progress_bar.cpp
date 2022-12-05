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

size_t progress_bar::marquee_animation_speed() const noexcept {
  return data_->marquee_animation_speed;
}

progress_bar& progress_bar::marquee_animation_speed(size_t marquee_animation_speed) {
  if (data_->marquee_animation_speed != marquee_animation_speed) {
    data_->marquee_animation_speed = marquee_animation_speed;
    if (is_handle_created()) native::progress_bar::marquee(handle(), data_->style == progress_bar_style::marquee, data_->marquee_animation_speed);
  }
  return *this;
}

int32_t progress_bar::maximum() const noexcept {
  return data_->maximum;
}

progress_bar& progress_bar::maximum(int32_t maximum) {
  if (data_->maximum != maximum) {
    data_->maximum = maximum;
    if (is_handle_created()) native::progress_bar::maximum(handle(), data_->maximum);
    if (data_->minimum > maximum) minimum(maximum);
    if (data_->value > maximum) value(maximum);
  }
  return *this;
}

int32_t progress_bar::minimum() const noexcept {
  return data_->minimum;
}

progress_bar& progress_bar::minimum(int32_t minimum) {
  if (data_->minimum != minimum) {
    data_->minimum = minimum;
    if (is_handle_created()) native::progress_bar::minimum(handle(), data_->minimum);
    if (data_->maximum < minimum) maximum(minimum);
    if (data_->value < minimum) value(minimum);
  }
  return *this;
}

forms::orientation progress_bar::orientation() const noexcept {
  return data_->orientation;
}

progress_bar& progress_bar::orientation(forms::orientation orientation) {
  if (data_->orientation != orientation) {
    data_->orientation = orientation;
    post_recreate_handle();
  }
  return *this;
}

int32_t progress_bar::step() const noexcept {
  return data_->step;
}

progress_bar& progress_bar::step(int32_t step) {
  data_->step = step;
  return *this;
}

progress_bar_style progress_bar::style() const noexcept {
  return data_->style;
}

progress_bar& progress_bar::style(progress_bar_style style) {
  if (data_->style != style) {
    data_->style = style;
    if (is_handle_created()) native::progress_bar::marquee(handle(), data_->style == progress_bar_style::marquee, data_->marquee_animation_speed);
    if (data_->style != progress_bar_style::marquee)
      post_recreate_handle();
  }
  return *this;
}

int32_t progress_bar::value() const noexcept {
  return data_->value;
}

progress_bar& progress_bar::value(int32_t value) {
  if (data_->value != value) {
    data_->value = std::clamp(value, data_->minimum, data_->maximum);
    if (is_handle_created()) native::progress_bar::value(handle(), data_->value);
  }
  return *this;
}

void progress_bar::increment(int32_t value) {
  if (data_->value + value < data_->minimum)
    this->value(data_->minimum);
  if (data_->value + value > data_->maximum)
    this->value(data_->maximum);
  else
    this->value(data_->value + value);
}

void progress_bar::perform_step() {
  increment(step());
}

void progress_bar::set_range(int32_t min_value, int32_t max_value) {
  minimum(min_value);
  maximum(min_value > max_value ? min_value : max_value);
}

xtd::ustring progress_bar::to_string() const noexcept {
  return ustring::format("{}, minimum: {}, maximum: {}, value: {}", ustring::full_class_name(*this), data_->minimum, data_->maximum, data_->value);
}

forms::create_params progress_bar::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("progressbar");
  
  if (data_->style == forms::progress_bar_style::continuous) create_params.style(create_params.style() | PBS_SMOOTH);
  if (data_->orientation == forms::orientation::vertical) create_params.style(create_params.style() | PBS_VERTICAL);
  
  return create_params;
}

drawing::size progress_bar::default_size() const noexcept {
  static auto size = control::default_size();
  return orientation() == forms::orientation::horizontal ? size : drawing::size(size.height(), size.width());
}

void progress_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::progress_bar::maximum(handle(), data_->maximum);
  native::progress_bar::minimum(handle(), data_->minimum);
  native::progress_bar::value(handle(), data_->value);
  native::progress_bar::marquee(handle(), data_->style == progress_bar_style::marquee, data_->marquee_animation_speed);
}
