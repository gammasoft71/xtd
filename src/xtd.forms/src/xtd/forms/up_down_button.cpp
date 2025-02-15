#include "../../../include/xtd/forms/up_down_button.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/up_down_button>
#include <xtd/forms/native/up_down_styles>
#include <xtd/forms/native/window_styles>
#include <xtd/forms/native/scroll_bar_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

struct up_down_button::data {
  bool wrapped = false;
  int32 maximum = 100;
  int32 minimum = 0;
  forms::orientation orientation = forms::orientation::vertical;
  int32 value = 0;
};

up_down_button::up_down_button() : data_(xtd::new_sptr<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
}

int32 up_down_button::maximum() const noexcept {return data_->maximum;}

up_down_button& up_down_button::maximum(int32 value) {
  if (data_->maximum == value) return *this;
  data_->maximum = value;
  if (is_handle_created()) native::up_down_button::maximum(handle(), data_->maximum);
  if (data_->minimum > value) minimum(value);
  if (data_->value > value) this->value(value);
  return *this;
}

int32 up_down_button::minimum() const noexcept {
  return data_->minimum;
}

up_down_button& up_down_button::minimum(int32 value) {
  if (data_->minimum == value) return *this;
  data_->minimum = value;
  if (is_handle_created()) native::up_down_button::minimum(handle(), data_->minimum);
  if (data_->maximum < value) maximum(value);
  if (data_->value < value) this->value(value);
  return *this;
}

forms::orientation up_down_button::orientation() const noexcept {
  return data_->orientation;
}

up_down_button& up_down_button::orientation(forms::orientation orientation) {
  if (data_->orientation == orientation) return *this;
  data_->orientation = orientation;
  post_recreate_handle();
  return *this;
}

int32 up_down_button::value() const noexcept {
  return data_->value;
}

up_down_button& up_down_button::value(int32 value) {
  if (data_->value == value) return *this;
  if (value > data_->maximum) data_->value = data_->maximum;
  else if (value < data_->minimum) data_->value = data_->minimum;
  else data_->value = value;
  if (is_handle_created()) native::up_down_button::value(handle(), data_->value);
  on_value_changed(event_args::empty);
  return *this;
}

bool up_down_button::wrapped() const noexcept {
  return data_->wrapped;
}

up_down_button& up_down_button::wrapped(bool value) {
  if (data_->wrapped == value) return *this;
  data_->wrapped = value;
  post_recreate_handle();
  return *this;
}

up_down_button up_down_button::create() {
  return up_down_button {};
}

up_down_button up_down_button::create(const drawing::point& location) {
  auto result = up_down_button {};
  result.location(location);
  return result;
}

up_down_button up_down_button::create(const drawing::point& location, const drawing::size& size) {
  auto result = up_down_button {};
  result.location(location);
  result.size(size);
  return result;
}

up_down_button up_down_button::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = up_down_button {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

up_down_button up_down_button::create(int32 value) {
  auto result = up_down_button {};
  result.value(value);
  return result;
}

up_down_button up_down_button::create(int32 value, const drawing::point& location) {
  auto result = up_down_button {};
  result.value(value);
  result.location(location);
  return result;
}

up_down_button up_down_button::create(int32 value, const drawing::point& location, const drawing::size& size) {
  auto result = up_down_button {};
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

up_down_button up_down_button::create(int32 value, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = up_down_button {};
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

up_down_button up_down_button::create(int32 value, int32 maximum) {
  auto result = up_down_button {};
  result.maximum(maximum);
  result.value(value);
  return result;
}

up_down_button up_down_button::create(int32 value, int32 maximum, const drawing::point& location) {
  auto result = up_down_button {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

up_down_button up_down_button::create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = up_down_button {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

up_down_button up_down_button::create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = up_down_button {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

up_down_button up_down_button::create(int32 value, int32 minimum, int32 maximum) {
  auto result = up_down_button {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  return result;
}

up_down_button up_down_button::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location) {
  auto result = up_down_button {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

up_down_button up_down_button::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = up_down_button {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

up_down_button up_down_button::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = up_down_button {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

up_down_button up_down_button::create(const control& parent) {
  auto result = up_down_button {};
  result.parent(parent);
  return result;
}

up_down_button up_down_button::create(const control& parent, const drawing::point& location) {
  auto result = up_down_button {};
  result.parent(parent);
  result.location(location);
  return result;
}

up_down_button up_down_button::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = up_down_button {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

up_down_button up_down_button::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = up_down_button {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value) {
  auto result = up_down_button {};
  result.parent(parent);
  result.value(value);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, const drawing::point& location) {
  auto result = up_down_button {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size) {
  auto result = up_down_button {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = up_down_button {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, int32 maximum) {
  auto result = up_down_button {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, int32 maximum, const drawing::point& location) {
  auto result = up_down_button {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = up_down_button {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = up_down_button {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, int32 minimum, int32 maximum) {
  auto result = up_down_button {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location) {
  auto result = up_down_button {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = up_down_button {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

up_down_button up_down_button::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = up_down_button {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}


void up_down_button::set_range(int32 min_value, int32 max_value) {
  minimum(min_value);
  maximum(min_value > max_value ? min_value : max_value);
}

xtd::string up_down_button::to_string() const noexcept {
  return string::format("{}, minimum: {}, maximum: {}, value: {}", get_type().full_name(), data_->minimum, data_->maximum, data_->value);
}

forms::create_params up_down_button::create_params() const noexcept {
  auto create_params = button_base::create_params();
  
  create_params.class_name("updownbutton");
  
  if (data_->orientation == forms::orientation::horizontal) create_params.style(create_params.style() | UDS_HORZ);
  if (data_->wrapped) create_params.style(create_params.style() | UDS_WRAP);
  
  return create_params;
}

xtd::uptr<xtd::object> up_down_button::clone() const {
  auto result = xtd::new_uptr<up_down_button>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

void up_down_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  native::up_down_button::maximum(handle(), data_->maximum);
  native::up_down_button::minimum(handle(), data_->minimum);
  native::up_down_button::value(handle(), data_->value);
}

void up_down_button::on_scroll(const event_args& e) {
  if (can_raise_events()) scroll(*this, e);
}

void up_down_button::on_value_changed(const event_args& e) {
  if (can_raise_events()) value_changed(*this, e);
}

void up_down_button::wnd_proc(message& message) {
  switch (message.msg) {
    case WM_REFLECT + WM_HSCROLL:
    case WM_REFLECT + WM_VSCROLL: wm_scroll_control(message); break;
    default: control::wnd_proc(message);
  }
}

void up_down_button::wm_scroll_control(message& message) {
  if (message.wparam == SB_LINEDOWN) data_->value = data_->value > data_->minimum ? data_->value - 1 : data_->maximum;
  if (message.wparam == SB_LINEUP) data_->value = data_->value < data_->maximum ? data_->value + 1 : data_->minimum;
  on_scroll(event_args::empty);
  on_value_changed(event_args::empty);
  control::def_wnd_proc(message);
}
