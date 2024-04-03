#include "../../../include/xtd/forms/progress_bar.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/progress_bar>
#include <xtd/forms/native/progress_bar_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/math>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct progress_bar::data {
  size_t marquee_animation_speed = 100;
  int32 maximum = 100;
  int32 minimum = 0;
  forms::orientation orientation = forms::orientation::horizontal;
  int32 step = 10;
  progress_bar_style style = progress_bar_style::blocks;
  int32 value = 0;
};

progress_bar::progress_bar() : data_(std::make_shared<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_can_focus(false);
  set_style(control_styles::user_paint | control_styles::use_text_for_accessibility | control_styles::selectable, false);
}

size_t progress_bar::marquee_animation_speed() const noexcept {
  return data_->marquee_animation_speed;
}

progress_bar& progress_bar::marquee_animation_speed(size_t marquee_animation_speed) {
  if (data_->marquee_animation_speed == marquee_animation_speed) return *this;
  data_->marquee_animation_speed = marquee_animation_speed;
  if (is_handle_created()) native::progress_bar::marquee(handle(), data_->style == progress_bar_style::marquee, data_->marquee_animation_speed);
  return *this;
}

int32 progress_bar::maximum() const noexcept {
  return data_->maximum;
}

progress_bar& progress_bar::maximum(int32 maximum) {
  if (data_->maximum == maximum) return *this;
  data_->maximum = maximum;
  if (is_handle_created()) native::progress_bar::maximum(handle(), data_->maximum);
  minimum(math::min(data_->minimum, maximum));
  value(math::min(data_->value, maximum));
  return *this;
}

int32 progress_bar::minimum() const noexcept {
  return data_->minimum;
}

progress_bar& progress_bar::minimum(int32 minimum) {
  if (data_->minimum == minimum) return *this;
  data_->minimum = minimum;
  if (is_handle_created()) native::progress_bar::minimum(handle(), data_->minimum);
  maximum(math::max(data_->maximum, minimum));
  value(math::max(data_->value, minimum));
  return *this;
}

forms::orientation progress_bar::orientation() const noexcept {
  return data_->orientation;
}

progress_bar& progress_bar::orientation(forms::orientation orientation) {
  if (!enum_object<>::is_defined<forms::orientation>(orientation)) throw argument_out_of_range_exception {csf_};
  if (data_->orientation == orientation) return *this;
  data_->orientation = orientation;
  post_recreate_handle();
  return *this;
}

int32 progress_bar::step() const noexcept {
  return data_->step;
}

progress_bar& progress_bar::step(int32 step) {
  data_->step = step;
  return *this;
}

progress_bar_style progress_bar::style() const noexcept {
  return data_->style;
}

progress_bar& progress_bar::style(progress_bar_style style) {
  if (!enum_object<>::is_defined<progress_bar_style>(style)) throw argument_out_of_range_exception {csf_};
  if (data_->style == style) return *this;
  data_->style = style;
  if (is_handle_created()) native::progress_bar::marquee(handle(), data_->style == progress_bar_style::marquee, data_->marquee_animation_speed);
  if (data_->style != progress_bar_style::marquee) post_recreate_handle();
  return *this;
}

int32 progress_bar::value() const noexcept {
  return data_->value;
}

progress_bar& progress_bar::value(int32 value) {
  if (data_->value == value) return *this;
  data_->value = math::clamp(value, data_->minimum, data_->maximum);
  if (is_handle_created()) native::progress_bar::value(handle(), data_->value);
  return *this;
}

progress_bar progress_bar::create() {
  return progress_bar {};
}

progress_bar progress_bar::create(const drawing::point& location) {
  auto result = progress_bar {};
  result.location(location);
  return result;
}

progress_bar progress_bar::create(const drawing::point& location, const drawing::size& size) {
  auto result = progress_bar {};
  result.location(location);
  result.size(size);
  return result;
}

progress_bar progress_bar::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = progress_bar {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

progress_bar progress_bar::create(int32 value) {
  auto result = progress_bar {};
  result.value(value);
  return result;
}

progress_bar progress_bar::create(int32 value, const drawing::point& location) {
  auto result = progress_bar {};
  result.value(value);
  result.location(location);
  return result;
}

progress_bar progress_bar::create(int32 value, const drawing::point& location, const drawing::size& size) {
  auto result = progress_bar {};
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

progress_bar progress_bar::create(int32 value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = progress_bar {};
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

progress_bar progress_bar::create(int32 value, int32 maximum) {
  auto result = progress_bar {};
  result.maximum(maximum);
  result.value(value);
  return result;
}

progress_bar progress_bar::create(int32 value, int32 maximum, const drawing::point& location) {
  auto result = progress_bar {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

progress_bar progress_bar::create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = progress_bar {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

progress_bar progress_bar::create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = progress_bar {};
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

progress_bar progress_bar::create(int32 value, int32 minimum, int32 maximum) {
  auto result = progress_bar {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  return result;
}

progress_bar progress_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location) {
  auto result = progress_bar {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

progress_bar progress_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = progress_bar {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

progress_bar progress_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = progress_bar {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

progress_bar progress_bar::create(const control& parent) {
  auto result = progress_bar {};
  result.parent(parent);
  return result;
}

progress_bar progress_bar::create(const control& parent, const drawing::point& location) {
  auto result = progress_bar {};
  result.parent(parent);
  result.location(location);
  return result;
}

progress_bar progress_bar::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = progress_bar {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

progress_bar progress_bar::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = progress_bar {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value) {
  auto result = progress_bar {};
  result.parent(parent);
  result.value(value);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, const drawing::point& location) {
  auto result = progress_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size) {
  auto result = progress_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = progress_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, int32 maximum) {
  auto result = progress_bar {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location) {
  auto result = progress_bar {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = progress_bar {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = progress_bar {};
  result.parent(parent);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum) {
  auto result = progress_bar {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location) {
  auto result = progress_bar {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = progress_bar {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

progress_bar progress_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = progress_bar {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void progress_bar::increment(int32 value) {
  this->value(data_->value + value);
}

void progress_bar::perform_step() {
  increment(step());
}

void progress_bar::set_range(int32 min_value, int32 max_value) {
  minimum(min_value);
  maximum(min_value > max_value ? min_value : max_value);
}

xtd::ustring progress_bar::to_string() const noexcept {
  return ustring::format("{}, minimum: {}, maximum: {}, value: {}", get_type().full_name(), data_->minimum, data_->maximum, data_->value);
}

forms::create_params progress_bar::create_params() const noexcept {
  auto create_params = control::create_params();
  create_params.class_name("progressbar");
  if (data_->style == forms::progress_bar_style::continuous) create_params.style(create_params.style() | PBS_SMOOTH);
  if (data_->orientation == forms::orientation::vertical) create_params.style(create_params.style() | PBS_VERTICAL);
  return create_params;
}

drawing::size progress_bar::default_size() const noexcept {
  static auto size = control::default_size();
  return orientation() == forms::orientation::horizontal ? size : drawing::size(size.height(), size.width());
}

unique_ptr<xtd::object> progress_bar::clone() const {
  auto result = make_unique<progress_bar>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::ustring::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
  return result;
}

void progress_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::progress_bar::maximum(handle(), data_->maximum);
  native::progress_bar::minimum(handle(), data_->minimum);
  native::progress_bar::value(handle(), data_->value);
  native::progress_bar::marquee(handle(), data_->style == progress_bar_style::marquee, data_->marquee_animation_speed);
}
