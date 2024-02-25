#include "../../../include/xtd/forms/track_bar.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/track_bar>
#include <xtd/forms/native/track_bar_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages>
#include <algorithm>

using namespace xtd;
using namespace xtd::forms;

struct track_bar::data {
  int32 large_change = 5;
  int32 maximum = 10;
  int32 minimum = 0;
  forms::orientation orientation = forms::orientation::horizontal;
  int32 small_change = 1;
  int32 tick_frequency = 1;
  forms::tick_style tick_style = forms::tick_style::bottom_right;
  int32 value = 0;
};

track_bar::track_bar() : data_(std::make_shared<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint, false);
  set_style(control_styles::use_text_for_accessibility, false);
}

int32 track_bar::large_change() const noexcept {
  return data_->large_change;
}

track_bar& track_bar::large_change(int32 large_change) {
  if (data_->large_change == large_change) return *this;
  data_->large_change = large_change;
  if (is_handle_created()) native::track_bar::large_change(handle(), data_->large_change);
  return *this;
}

int32 track_bar::maximum() const noexcept {
  return data_->maximum;
}

track_bar& track_bar::maximum(int32 maximum) {
  if (data_->maximum == maximum) return *this;
  data_->maximum = maximum;
  if (is_handle_created()) native::track_bar::maximum(handle(), data_->maximum);
  if (data_->minimum > maximum) minimum(maximum);
  if (data_->value > maximum) value(maximum);
  return *this;
}

int32 track_bar::minimum() const noexcept {
  return data_->minimum;
}

track_bar& track_bar::minimum(int32 minimum) {
  if (data_->minimum == minimum) return *this;
  data_->minimum = minimum;
  if (is_handle_created()) native::track_bar::minimum(handle(), data_->minimum);
  if (data_->maximum < minimum) maximum(minimum);
  if (data_->value < minimum) value(minimum);
  return *this;
}

forms::orientation track_bar::orientation() const noexcept {
  return data_->orientation;
}

track_bar& track_bar::orientation(forms::orientation orientation) {
  if (data_->orientation == orientation) return *this;
  data_->orientation = orientation;
  post_recreate_handle();
  return *this;
}

int32 track_bar::small_change() const noexcept {
  return data_->small_change;
}

track_bar& track_bar::small_change(int32 small_change) {
  if (data_->small_change == small_change) return *this;
  data_->small_change = small_change;
  if (is_handle_created()) native::track_bar::small_change(handle(), data_->small_change);
  return *this;
}

int32 track_bar::tick_frequency() const noexcept {
  return data_->tick_frequency;
}

track_bar& track_bar::tick_frequency(int32 tick_frequency) {
  if (data_->tick_frequency == tick_frequency) return *this;
  data_->tick_frequency = tick_frequency;
  if (is_handle_created()) native::track_bar::tick_frequency(handle(), data_->tick_frequency);
  return *this;
}

forms::tick_style track_bar::tick_style() const noexcept {
  return data_->tick_style;
}

track_bar& track_bar::tick_style(forms::tick_style tick_style) {
  if (data_->tick_style == tick_style) return *this;
  data_->tick_style = tick_style;
  post_recreate_handle();
  return *this;
}

int32 track_bar::value() const noexcept {
  return data_->value;
}

track_bar& track_bar::value(int32 value) {
  if (data_->value == value) return *this;
  data_->value = std::clamp(value, data_->minimum, data_->maximum);
  if (is_handle_created()) native::track_bar::value(handle(), data_->value);
  on_value_changed(event_args::empty);
  return *this;
}

track_bar track_bar::create() {
  return track_bar {};
}

track_bar track_bar::create(const drawing::point& location) {
  auto result = track_bar {};
  result.location(location);
  return result;
}

track_bar track_bar::create(const drawing::point& location, const drawing::size& size) {
  auto result = track_bar {};
  result.location(location);
  result.size(size);
  return result;
}

track_bar track_bar::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = track_bar {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

track_bar track_bar::create(int32 value) {
  auto result = track_bar {};
  result.value(value);
  return result;
}

track_bar track_bar::create(int32 value, const drawing::point& location) {
  auto result = track_bar {};
  result.value(value);
  result.location(location);
  return result;
}

track_bar track_bar::create(int32 value, const drawing::point& location, const drawing::size& size) {
  auto result = track_bar {};
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

track_bar track_bar::create(int32 value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = track_bar {};
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

track_bar track_bar::create(int32 value, int32 maximum) {
  auto result = track_bar {};
  result.value(value);
  result.maximum(maximum);
  return result;
}

track_bar track_bar::create(int32 value, int32 maximum, const drawing::point& location) {
  auto result = track_bar {};
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  return result;
}

track_bar track_bar::create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = track_bar {};
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  return result;
}

track_bar track_bar::create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = track_bar {};
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

track_bar track_bar::create(int32 value, int32 minimum, int32 maximum) {
  auto result = track_bar {};
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  return result;
}

track_bar track_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location) {
  auto result = track_bar {};
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  return result;
}

track_bar track_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = track_bar {};
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  return result;
}

track_bar track_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = track_bar {};
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

track_bar track_bar::create(const control& parent) {
  auto result = track_bar {};
  result.parent(parent);
  return result;
}

track_bar track_bar::create(const control& parent, const drawing::point& location) {
  auto result = track_bar {};
  result.parent(parent);
  result.location(location);
  return result;
}

track_bar track_bar::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = track_bar {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

track_bar track_bar::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = track_bar {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, const drawing::point& location) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, int32 maximum) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.maximum(maximum);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  return result;
}

track_bar track_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = track_bar {};
  result.parent(parent);
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void track_bar::set_range(int32 min_value, int32 max_value) {
  minimum(min_value);
  maximum(min_value > max_value ? min_value : max_value);
}

xtd::ustring track_bar::to_string() const noexcept {
  return ustring::format("{}, minimum: {}, maximum: {}, value: {}", get_type().full_name(), data_->minimum, data_->maximum, data_->value);
}

forms::create_params track_bar::create_params() const noexcept {
  auto create_params = control::create_params();
  
  create_params.class_name("trackbar");
  
  if (data_->orientation == forms::orientation::vertical) create_params.style(create_params.style() | TBS_VERT);
  else create_params.style(create_params.style() | TBS_HORZ);
  
  if (data_->tick_style == forms::tick_style::none) create_params.style(create_params.style() | TBS_NOTICKS);
  else if (data_->tick_style == forms::tick_style::top_left) create_params.style(create_params.style() | TBS_TOP);
  else if (data_->tick_style == forms::tick_style::both) create_params.style(create_params.style() | TBS_BOTH);
  
  return create_params;
}

drawing::size track_bar::default_size() const noexcept {
  static auto size = control::default_size();
  return orientation() == forms::orientation::horizontal ? size : drawing::size(size.height(), size.width());
}

void track_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::track_bar::large_change(handle(), large_change());
  native::track_bar::maximum(handle(), maximum());
  native::track_bar::minimum(handle(), minimum());
  native::track_bar::small_change(handle(), small_change());
  native::track_bar::tick_frequency(handle(), tick_frequency());
  native::track_bar::value(handle(), value());
}

void track_bar::on_scroll(const event_args& e) {
  if (is_handle_created()) data_->value = native::track_bar::value(handle());
  scroll(*this, e);
}

void track_bar::on_value_changed(const event_args& e) {
  value_changed(*this, e);
}

void track_bar::set_bounds_core(int32 x, int32 y, int32 width, int32 height, bounds_specified specified) {
  control::set_bounds_core(x, y, width, height, specified);
  if ((specified & bounds_specified::width) == bounds_specified::width || (specified & bounds_specified::height) == bounds_specified::height)
    post_recreate_handle();
}

void track_bar::set_client_size_core(int32 width, int32 height) {
  control::set_client_size_core(width, height);
  post_recreate_handle();
}

void track_bar::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_HSCROLL:
    case WM_REFLECT + WM_VSCROLL: wm_scroll_control(message); break;
    default: control::wnd_proc(message);
  }
}

void track_bar::wm_scroll_control(message& message) {
  on_scroll(event_args::empty);
  on_value_changed(event_args::empty);
}
