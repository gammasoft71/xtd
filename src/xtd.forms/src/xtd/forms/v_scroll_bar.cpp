#include "../../../include/xtd/forms/v_scroll_bar"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar>
#include <xtd/forms/native/scroll_bar_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

v_scroll_bar::v_scroll_bar() : scroll_bar(true) {
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
