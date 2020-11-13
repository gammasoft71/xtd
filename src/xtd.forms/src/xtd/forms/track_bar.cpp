#include <xtd/forms/native/track_bar.h>
#include <xtd/forms/window_messages.h>
#include <xtd/forms/native/track_bar_styles.h>
#include "../../../include/xtd/forms/track_bar.h"

using namespace xtd;
using namespace xtd::forms;

track_bar::track_bar() {
  this->set_state(state::auto_size, true);
  this->size_ = this->default_size();
}

track_bar& track_bar::large_change(int32_t large_change) {
  if (this->large_change_ != large_change) {
    this->large_change_ = large_change;
    native::track_bar::large_change(handle(), this->large_change_);
  }
  return *this;
}

track_bar& track_bar::maximum(int32_t maximum) {
  if (this->maximum_ != maximum) {
    this->maximum_ = maximum;
    native::track_bar::maximum(handle(), this->maximum_);
    if (this->minimum_ > maximum) this->minimum(maximum);
    if (this->value_ > maximum) this->value(maximum);
  }
  return *this;
}

track_bar& track_bar::minimum(int32_t minimum) {
  if (this->minimum_ != minimum) {
    this->minimum_ = minimum;
    native::track_bar::minimum(handle(), this->minimum_);
    if (this->maximum_ < minimum) this->maximum(minimum);
    if (this->value_ < minimum) this->value(minimum);
  }
  return *this;
}

track_bar& track_bar::orientation(forms::orientation orientation) {
  if (this->orientation_ != orientation) {
    this->orientation_ = orientation;
    this->recreate_handle();
  }
  return *this;
}

track_bar& track_bar::small_change(int32_t small_change) {
  if (this->small_change_ != small_change) {
    this->small_change_ = small_change;
    native::track_bar::small_change(handle(), this->small_change_);
  }
  return *this;
}

track_bar& track_bar::tick_frequency(int32_t tick_frequency) {
  if (this->tick_frequency_ != tick_frequency) {
    this->tick_frequency_ = tick_frequency;
    native::track_bar::tick_frequency(handle(), this->tick_frequency_);
  }
  return *this;
}

track_bar& track_bar::tick_style(forms::tick_style tick_style) {
  if (this->tick_style_ != tick_style) {
    this->tick_style_ = tick_style;
    this->recreate_handle();
  }
  return *this;
}

track_bar& track_bar::value(int32_t value) {
  if (this->value_ != value) {
    if (value > this->maximum_)
      this->value_ = this->maximum_;
    if (value < this->minimum_)
      this->value_ = this->minimum_;
    else
      this->value_ = value;
    native::track_bar::value(handle(), this->value_);
    this->on_value_changed(event_args::empty);
  }
  return *this;
}

forms::create_params track_bar::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("trackbar");
  
  if (this->orientation_ == forms::orientation::vertical) create_params.style(create_params.style() | TBS_VERT);
  else create_params.style(create_params.style() | TBS_HORZ);

  if (this->tick_style_ == forms::tick_style::none) create_params.style(create_params.style() | TBS_NOTICKS);
  else if (this->tick_style_ == forms::tick_style::top_left) create_params.style(create_params.style() | TBS_TOP);
  else if (this->tick_style_ == forms::tick_style::both) create_params.style(create_params.style() | TBS_BOTH);

  return create_params;
}

void track_bar::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  native::track_bar::large_change(handle(), this->large_change_);
  native::track_bar::maximum(handle(), this->maximum_);
  native::track_bar::minimum(handle(), this->minimum_);
  native::track_bar::small_change(handle(), this->small_change_);
  native::track_bar::tick_frequency(handle(), this->tick_frequency_);
  native::track_bar::value(handle(), this->value_);
}

drawing::size track_bar::measure_control() const {
  if (this->orientation_ == forms::orientation::vertical) return {this->default_size().height(), this->size_.height()};
  return {this->size_.width(), this->default_size().height()};
}

void track_bar::on_scroll(const event_args &e) {
  this->value_ = native::track_bar::value(handle());
  this->scroll(*this, e);
}

void track_bar::on_value_changed(const event_args &e) {
  this->value_changed(*this, e);
}

void track_bar::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_HSCROLL:
    case WM_REFLECT + WM_VSCROLL: this->wm_scroll(message); break;
    default: this->control::wnd_proc(message);
  }
}

void track_bar::wm_scroll(message &message) {
  this->on_scroll(event_args::empty);
  this->on_value_changed(event_args::empty);
}
