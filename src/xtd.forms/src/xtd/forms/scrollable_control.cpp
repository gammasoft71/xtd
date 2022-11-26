#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/scrollable_control.h"

using namespace xtd;
using namespace xtd::forms;

scrollable_control::scrollable_control() {
  set_state(state::tab_stop, false);
  set_style(control_styles::container_control, true);
  set_style(control_styles::all_painting_in_wm_paint, false);
}

forms::create_params scrollable_control::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  
  if (auto_scroll_) {
    create_params.style(create_params.style() | WS_HSCROLL | WS_VSCROLL);
    create_params.ex_style(create_params.ex_style() | WS_EX_AUTOSCROLL);
  } else {
    if (h_scroll_) create_params.style(create_params.style() | WS_HSCROLL);
    if (v_scroll_) create_params.style(create_params.style() | WS_VSCROLL);
  }
  
  return create_params;
}
