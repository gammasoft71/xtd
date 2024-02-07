#include "../../../include/xtd/forms/up_down_base.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <optional>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct up_down_base::data {
  forms::border_sides border_sides = forms::border_sides::all;
  optional<forms::border_style> border_style;
};

forms::border_sides up_down_base::border_sides() const noexcept {
  return data_->border_sides;
}

up_down_base& up_down_base::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides == border_sides) return *this;
  data_->border_sides = border_sides;
  if (control_appearance() == forms::control_appearance::standard) invalidate();
  return *this;
}

forms::border_style up_down_base::border_style() const noexcept {
  return data_->border_style.value_or(forms::border_style::fixed_single);
}

up_down_base& up_down_base::border_style(forms::border_style value) {
  if (this->border_style() == value) return *this;
  data_->border_style = value;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

up_down_base& up_down_base::border_style(std::nullptr_t) {
  if (!data_->border_style) return *this;
  data_->border_style.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

up_down_base::up_down_base() : data_(std::make_shared<data>()) {
  set_style(control_styles::opaque | control_styles::fixed_height | control_styles::resize_redraw, true);
  set_style(control_styles::standard_click, false);
  set_style(control_styles::use_text_for_accessibility, false);
}

forms::create_params up_down_base::create_params() const noexcept {
  auto create_params = container_control::create_params();
  
  if (border_style() == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (border_style() != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}
