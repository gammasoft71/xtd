#include "../../../include/xtd/forms/numeric_up_down.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/numeric_up_down>
#include <xtd/forms/native/up_down_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/as>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

struct numeric_up_down::data {
  int32 decimal_place = 0;
  double increment = 1.0;
  double maximum = 100.0;
  double minimum = 0.0;
  double value = 0.0;
  bool wrapped = false;
};

numeric_up_down::numeric_up_down() : data_(xtd::new_sptr<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
}

double numeric_up_down::decimal_place() const noexcept {
  return data_->decimal_place;
}

numeric_up_down& numeric_up_down::decimal_place(int32 value) {
  if (data_->decimal_place == value) return *this;
  data_->decimal_place = value;
  if (is_handle_created()) native::numeric_up_down::decimal_place(handle(), data_->decimal_place);
  return *this;
}

double numeric_up_down::increment() const noexcept {
  return data_->increment;
}

numeric_up_down& numeric_up_down::increment(double value) {
  if (data_->increment == value) return *this;
  data_->increment = value;
  if (is_handle_created()) native::numeric_up_down::increment(handle(), data_->increment);
  return *this;
}

double numeric_up_down::maximum() const noexcept {
  return data_->maximum;
}

numeric_up_down& numeric_up_down::maximum(double value) {
  if (data_->maximum == value) return *this;
  data_->maximum = value;
  if (is_handle_created()) native::numeric_up_down::maximum(handle(), data_->maximum);
  if (data_->minimum > value) minimum(value);
  if (data_->value > value) this->value(value);
  return *this;
}

double numeric_up_down::minimum() const noexcept {
  return data_->minimum;
}

numeric_up_down& numeric_up_down::minimum(double value) {
  if (data_->minimum == value) return *this;
  data_->minimum = value;
  if (is_handle_created()) native::numeric_up_down::minimum(handle(), data_->minimum);
  if (data_->maximum < value) maximum(value);
  if (data_->value < value) this->value(value);
  return *this;
}

double numeric_up_down::value() const noexcept {
  return data_->value;
}

numeric_up_down& numeric_up_down::value(double value) {
  if (data_->value == value) return *this;
  if (value > data_->maximum) data_->value = data_->maximum;
  else if (value < data_->minimum) data_->value = data_->minimum;
  else data_->value = value;
  if (is_handle_created()) native::numeric_up_down::value(handle(), data_->value);
  on_value_changed(event_args::empty);
  return *this;
}

bool numeric_up_down::wrapped() const noexcept {
  return data_->wrapped;
}

numeric_up_down& numeric_up_down::wrapped(bool value) {
  if (data_->wrapped == value) return *this;
  data_->wrapped = value;
  post_recreate_handle();
  return *this;
}

numeric_up_down numeric_up_down::create() {
  return numeric_up_down {};
}

numeric_up_down numeric_up_down::create(const drawing::point& location) {
  auto result = numeric_up_down {};
  result.location(location);
  return result;
}

numeric_up_down numeric_up_down::create(const drawing::point& location, const drawing::size& size) {
  auto result = numeric_up_down {};
  result.location(location);
  result.size(size);
  return result;
}

numeric_up_down numeric_up_down::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = numeric_up_down {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

numeric_up_down numeric_up_down::create(double value) {
  auto result = numeric_up_down {};
  result.value(value);
  return result;
}

numeric_up_down numeric_up_down::create(double value, const drawing::point& location) {
  auto result = numeric_up_down {};
  result.value(value);
  result.location(location);
  return result;
}

numeric_up_down numeric_up_down::create(double value, const drawing::point& location, const drawing::size& size) {
  auto result = numeric_up_down {};
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

numeric_up_down numeric_up_down::create(double value, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = numeric_up_down {};
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

numeric_up_down numeric_up_down::create(double value, double maximum) {
  auto result = numeric_up_down {};
  result.maximum(maximum);
  result.value(value);
  return result;
}

numeric_up_down numeric_up_down::create(double value, double maximum, const drawing::point& location) {
  auto result = numeric_up_down {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

numeric_up_down numeric_up_down::create(double value, double maximum, const drawing::point& location, const drawing::size& size) {
  auto result = numeric_up_down {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

numeric_up_down numeric_up_down::create(double value, double maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = numeric_up_down {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

numeric_up_down numeric_up_down::create(double value, double minimum, double maximum) {
  auto result = numeric_up_down {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  return result;
}

numeric_up_down numeric_up_down::create(double value, double minimum, double maximum, const drawing::point& location) {
  auto result = numeric_up_down {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

numeric_up_down numeric_up_down::create(double value, double minimum, double maximum, const drawing::point& location, const drawing::size& size) {
  auto result = numeric_up_down {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

numeric_up_down numeric_up_down::create(double value, double minimum, double maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = numeric_up_down {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent) {
  auto result = numeric_up_down {};
  result.parent(parent);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, const drawing::point& location) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.location(location);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.value(value);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, const drawing::point& location) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, const drawing::point& location, const drawing::size& size) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, double maximum) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, double maximum, const drawing::point& location) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, double maximum, const drawing::point& location, const drawing::size& size) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, double maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, double minimum, double maximum) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, double minimum, double maximum, const drawing::point& location) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, double minimum, double maximum, const drawing::point& location, const drawing::size& size) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

numeric_up_down numeric_up_down::create(const control& parent, double value, double minimum, double maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = numeric_up_down {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void numeric_up_down::set_range(double min_value, double max_value) {
  minimum(min_value);
  maximum(min_value > max_value ? min_value : max_value);
}

xtd::string numeric_up_down::to_string() const noexcept {
  return string::format("{}, minimum: {}, maximum: {}, value: {}", get_type().full_name(), data_->minimum, data_->maximum, data_->value);
}

drawing::color numeric_up_down::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color numeric_up_down::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

forms::create_params numeric_up_down::create_params() const noexcept {
  auto create_params = up_down_base::create_params();
  create_params.class_name("numericupdown");
  if (data_->wrapped) create_params.style(create_params.style() | UDS_WRAP);
  return create_params;
}

xtd::uptr<xtd::object> numeric_up_down::clone() const {
  auto result = xtd::new_uptr<numeric_up_down>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).chars().c_str());
  return result;
}

void numeric_up_down::on_handle_created(const event_args& e) {
  scrollable_control::on_handle_created(e);
  native::numeric_up_down::decimal_place(handle(), data_->decimal_place);
  native::numeric_up_down::increment(handle(), data_->increment);
  native::numeric_up_down::minimum(handle(), data_->minimum);
  native::numeric_up_down::maximum(handle(), data_->maximum);
  native::numeric_up_down::value(handle(), data_->value);
}

void numeric_up_down::on_value_changed(const event_args& e) {
  if (!can_raise_events()) return;
  auto safe_value_changed = value_changed;
  if (safe_value_changed.is_empty()) return;
  safe_value_changed(*this, e);
}

void numeric_up_down::on_lost_focus(const event_args& e) {
  up_down_base::on_lost_focus(e);
  auto text_value = .0;
  if (!xtd::string::is_empty(text()) && try_parse<double>(text().chars(), text_value, number_styles::number))
    value(text_value);
}

void numeric_up_down::wnd_proc(message& message) {
  switch (message.msg) {
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: up_down_base::wnd_proc(message);
  }
}

void numeric_up_down::wm_command_control(message& message) {
  def_wnd_proc(message);
  if (data_->value != native::numeric_up_down::value(handle())) {
    data_->value = native::numeric_up_down::value(handle());
    on_value_changed(event_args::empty);
  }
}
