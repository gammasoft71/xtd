#include "../../../include/xtd/forms/v_scroll_bar.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar>
#include <xtd/forms/native/scroll_bar_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

v_scroll_bar::v_scroll_bar() : scroll_bar(true) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_can_focus(false);
}

forms::create_params v_scroll_bar::create_params() const noexcept {
  auto create_params = scroll_bar::create_params();
  create_params.style(create_params.style() | SBS_VERT);
  return create_params;
}

xtd::drawing::size v_scroll_bar::default_size() const noexcept {
  return {control::default_size().width(), 80};
}

v_scroll_bar v_scroll_bar::create() {
  return v_scroll_bar {};
}

v_scroll_bar v_scroll_bar::create(const drawing::point& location) {
  auto result = v_scroll_bar {};
  result.location(location);
  return result;
}

v_scroll_bar v_scroll_bar::create(const drawing::point& location, const drawing::size& size) {
  auto result = v_scroll_bar {};
  result.location(location);
  result.size(size);
  return result;
}

v_scroll_bar v_scroll_bar::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = v_scroll_bar {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value) {
  auto result = v_scroll_bar {};
  result.value(value);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, const drawing::point& location) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.location(location);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, const drawing::point& location, const drawing::size& size) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, int32 maximum) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.maximum(maximum);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, int32 maximum, const drawing::point& location) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, int32 minimum, int32 maximum) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  return result;
}

v_scroll_bar v_scroll_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = v_scroll_bar {};
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, const drawing::point& location) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.location(location);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, const drawing::point& location) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, int32 maximum) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.maximum(maximum);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  return result;
}

v_scroll_bar v_scroll_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = v_scroll_bar {};
  result.parent(parent);
  result.value(value);
  result.minimum(minimum);
  result.maximum(maximum);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}
