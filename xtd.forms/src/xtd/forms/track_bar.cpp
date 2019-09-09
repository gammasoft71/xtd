#include <xtd/forms/native/track_bar.hpp>
#include <xtd/forms/window_messages.hpp>
#include <xtd/forms/native/window_track_bar.hpp>
#include "../../../include/xtd/forms/track_bar.hpp"

using namespace xtd;
using namespace xtd::forms;

track_bar::track_bar() {
  this->make_control(*this);
  this->control::data_->auto_size_ = true;
  this->control::data_->size_ = this->default_size();
}

track_bar& track_bar::operator=(const track_bar& value) {
  this->control::operator=(value);
  this->scroll = value.scroll;
  this->value_changed = value.value_changed;
  this->data_ = value.data_;
  return *this;
}

track_bar& track_bar::large_change(int32_t large_change) {
  if (this->data_->large_change_ != large_change) {
    this->data_->large_change_ = large_change;
    native::track_bar::large_change(this->control::data_->handle_, this->data_->large_change_);
  }
  return *this;
}

track_bar& track_bar::maximum(int32_t maximum) {
  if (this->data_->maximum_ != maximum) {
    this->data_->maximum_ = maximum;
    native::track_bar::maximum(this->control::data_->handle_, this->data_->maximum_);
    if (this->data_->minimum_ > maximum) this->minimum(maximum);
    if (this->data_->value_ > maximum) this->value(maximum);
  }
  return *this;
}

track_bar& track_bar::minimum(int32_t minimum) {
  if (this->data_->minimum_ != minimum) {
    this->data_->minimum_ = minimum;
    native::track_bar::minimum(this->control::data_->handle_, this->data_->minimum_);
    if (this->data_->maximum_ < minimum) this->maximum(minimum);
    if (this->data_->value_ < minimum) this->value(minimum);
  }
  return *this;
}

track_bar& track_bar::orientation(forms::orientation orientation) {
  if (this->data_->orientation_ != orientation) {
    this->data_->orientation_ = orientation;
    this->recreate_handle();
  }
  return *this;
}

track_bar& track_bar::small_change(int32_t small_change) {
  if (this->data_->small_change_ != small_change) {
    this->data_->small_change_ = small_change;
    native::track_bar::small_change(this->control::data_->handle_, this->data_->small_change_);
  }
  return *this;
}

track_bar& track_bar::tick_frequency(int32_t tick_frequency) {
  if (this->data_->tick_frequency_ != tick_frequency) {
    this->data_->tick_frequency_ = tick_frequency;
    native::track_bar::tick_frequency(this->control::data_->handle_, this->data_->tick_frequency_);
  }
  return *this;
}

track_bar& track_bar::tick_style(forms::tick_style tick_style) {
  if (this->data_->tick_style_ != tick_style) {
    this->data_->tick_style_ = tick_style;
    this->recreate_handle();
  }
  return *this;
}

track_bar& track_bar::value(int32_t value) {
  if (this->data_->value_ != value) {
    if (value > this->data_->maximum_)
      this->data_->value_ = this->data_->maximum_;
    if (value < this->data_->minimum_)
      this->data_->value_ = this->data_->minimum_;
    else
      this->data_->value_ = value;
    native::track_bar::value(this->control::data_->handle_, this->data_->value_);
    this->on_value_changed(event_args::empty);
  }
  return *this;
}

forms::create_params track_bar::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("trackbar");
  
  if (this->data_->orientation_ == forms::orientation::vertical) create_params.style(create_params.style() | TBS_VERT);
  else create_params.style(create_params.style() | TBS_HORZ);

  if (this->data_->tick_style_ == forms::tick_style::none) create_params.style(create_params.style() | TBS_NOTICKS);
  else if (this->data_->tick_style_ == forms::tick_style::top_left) create_params.style(create_params.style() | TBS_TOP);
  else if (this->data_->tick_style_ == forms::tick_style::both) create_params.style(create_params.style() | TBS_BOTH);

  return create_params;
}

void track_bar::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  native::track_bar::large_change(this->control::data_->handle_, this->data_->large_change_);
  native::track_bar::maximum(this->control::data_->handle_, this->data_->maximum_);
  native::track_bar::minimum(this->control::data_->handle_, this->data_->minimum_);
  native::track_bar::small_change(this->control::data_->handle_, this->data_->small_change_);
  native::track_bar::tick_frequency(this->control::data_->handle_, this->data_->tick_frequency_);
  native::track_bar::value(this->control::data_->handle_, this->data_->value_);
}

drawing::size track_bar::measure_control() const {
  if (this->data_->orientation_ == forms::orientation::vertical) return {this->default_size().height(), this->control::data_->size_.height()};
  return {this->control::data_->size_.width(), this->default_size().height()};
}

void track_bar::on_scroll(const event_args &e) {
  this->data_->value_ = native::track_bar::value(this->control::data_->handle_);
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
