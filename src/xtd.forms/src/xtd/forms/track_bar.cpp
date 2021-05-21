#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/track_bar.h>
#include <xtd/forms/native/track_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/track_bar.h"

using namespace xtd;
using namespace xtd::forms;

track_bar::track_bar() {
  set_state(state::auto_size, true);
  size_ = default_size();
}

track_bar& track_bar::large_change(int32_t large_change) {
  if (large_change_ != large_change) {
    large_change_ = large_change;
    native::track_bar::large_change(handle(), large_change_);
  }
  return *this;
}

track_bar& track_bar::maximum(int32_t maximum) {
  if (maximum_ != maximum) {
    maximum_ = maximum;
    native::track_bar::maximum(handle(), maximum_);
    if (minimum_ > maximum) minimum(maximum);
    if (value_ > maximum) value(maximum);
  }
  return *this;
}

track_bar& track_bar::minimum(int32_t minimum) {
  if (minimum_ != minimum) {
    minimum_ = minimum;
    native::track_bar::minimum(handle(), minimum_);
    if (maximum_ < minimum) maximum(minimum);
    if (value_ < minimum) value(minimum);
  }
  return *this;
}

track_bar& track_bar::orientation(forms::orientation orientation) {
  if (orientation_ != orientation) {
    orientation_ = orientation;
    recreate_handle();
  }
  return *this;
}

track_bar& track_bar::small_change(int32_t small_change) {
  if (small_change_ != small_change) {
    small_change_ = small_change;
    native::track_bar::small_change(handle(), small_change_);
  }
  return *this;
}

track_bar& track_bar::tick_frequency(int32_t tick_frequency) {
  if (tick_frequency_ != tick_frequency) {
    tick_frequency_ = tick_frequency;
    native::track_bar::tick_frequency(handle(), tick_frequency_);
  }
  return *this;
}

track_bar& track_bar::tick_style(forms::tick_style tick_style) {
  if (tick_style_ != tick_style) {
    tick_style_ = tick_style;
    recreate_handle();
  }
  return *this;
}

track_bar& track_bar::value(int32_t value) {
  if (value_ != value) {
    if (value > maximum_)
      value_ = maximum_;
    if (value < minimum_)
      value_ = minimum_;
    else
      value_ = value;
    native::track_bar::value(handle(), value_);
    on_value_changed(event_args::empty);
  }
  return *this;
}

forms::create_params track_bar::create_params() const {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("trackbar");
  
  if (orientation_ == forms::orientation::vertical) create_params.style(create_params.style() | TBS_VERT);
  else create_params.style(create_params.style() | TBS_HORZ);

  if (tick_style_ == forms::tick_style::none) create_params.style(create_params.style() | TBS_NOTICKS);
  else if (tick_style_ == forms::tick_style::top_left) create_params.style(create_params.style() | TBS_TOP);
  else if (tick_style_ == forms::tick_style::both) create_params.style(create_params.style() | TBS_BOTH);

  return create_params;
}

void track_bar::on_handle_created(const event_args &e) {
  control::on_handle_created(e);
  native::track_bar::large_change(handle(), large_change_);
  native::track_bar::maximum(handle(), maximum_);
  native::track_bar::minimum(handle(), minimum_);
  native::track_bar::small_change(handle(), small_change_);
  native::track_bar::tick_frequency(handle(), tick_frequency_);
  native::track_bar::value(handle(), value_);
}

drawing::size track_bar::measure_control() const {
  if (orientation_ == forms::orientation::vertical) return {default_size().height(), size_.height()};
  return {size_.width(), default_size().height()};
}

void track_bar::on_scroll(const event_args &e) {
  value_ = native::track_bar::value(handle());
  scroll(*this, e);
}

void track_bar::on_value_changed(const event_args &e) {
  value_changed(*this, e);
}

void track_bar::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_HSCROLL:
    case WM_REFLECT + WM_VSCROLL: wm_scroll(message); break;
    default: control::wnd_proc(message);
  }
}

void track_bar::wm_scroll(message &message) {
  on_scroll(event_args::empty);
  on_value_changed(event_args::empty);
}
