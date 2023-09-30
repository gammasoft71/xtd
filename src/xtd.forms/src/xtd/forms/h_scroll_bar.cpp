#include "../../../include/xtd/forms/h_scroll_bar.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar>
#include <xtd/forms/native/scroll_bar_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

h_scroll_bar::h_scroll_bar() : scroll_bar(false) {
  control_appearance(forms::control_appearance::system);
  set_can_focus(false);
}

forms::create_params h_scroll_bar::create_params() const noexcept {
  auto create_params = scroll_bar::create_params();
  create_params.style(create_params.style() | SBS_HORZ);
  return create_params;
}

xtd::drawing::size h_scroll_bar::default_size() const noexcept {
  return {80, control::default_size().height()};
}

h_scroll_bar h_scroll_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = h_scroll_bar {};
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

h_scroll_bar h_scroll_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = h_scroll_bar {};
  result.parent(parent);
  result.minimum(minimum);
  result.maximum(maximum);
  result.value(value);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}
