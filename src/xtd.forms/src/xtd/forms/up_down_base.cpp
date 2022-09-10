#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/up_down_base.h"

using namespace xtd;
using namespace xtd::forms;

up_down_base& up_down_base::border_sides(forms::border_sides border_sides) {
  if (border_sides_ != border_sides) {
    border_sides_ = border_sides;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

up_down_base& up_down_base::border_style(forms::border_style value) {
  if (border_style_ != value) {
    border_style_ = value;
    post_recreate_handle();
  }
  return *this;
}

up_down_base::up_down_base() {
  set_style(control_styles::opaque | control_styles::fixed_height | control_styles::resize_redraw, true);
  set_style(control_styles::standard_click, false);
  set_style(control_styles::use_text_for_accessibility, false);
}

forms::create_params up_down_base::create_params() const {
  forms::create_params create_params = container_control::create_params();
  
  if (border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (border_style_ != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}
