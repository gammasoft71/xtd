#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar.h>
#include <xtd/forms/native/scroll_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/h_scroll_bar.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

h_scroll_bar::h_scroll_bar() : scroll_bar(false) {
  control_appearance(forms::control_appearance::system);
  set_can_focus(false);
}

forms::create_params h_scroll_bar::create_params() const noexcept {
  forms::create_params create_params = scroll_bar::create_params();
  
  create_params.style(create_params.style() | SBS_HORZ);
  
  return create_params;
}

xtd::drawing::size h_scroll_bar::default_size() const noexcept {
  return {80, control::default_size().height()};
}

h_scroll_bar h_scroll_bar::create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  h_scroll_bar item;
  item.minimum(minimum);
  item.maximum(maximum);
  item.value(value);
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}

h_scroll_bar h_scroll_bar::create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  h_scroll_bar item;
  item.parent(parent);
  item.minimum(minimum);
  item.maximum(maximum);
  item.value(value);
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}
