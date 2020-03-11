#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/scrollable_control.h"

using namespace xtd;
using namespace xtd::forms;

forms::create_params scrollable_control::create_params() const {
  forms::create_params create_params = control::create_params();
  
  if (this->auto_scroll_) {
    create_params.style(create_params.style() | WS_HSCROLL | WS_VSCROLL);
    create_params.ex_style(create_params.ex_style() | WS_EX_AUTOSCROLL);
  } else {
    if (this->hscroll_) create_params.style(create_params.style() | WS_HSCROLL);
    if (this->vscroll_) create_params.style(create_params.style() | WS_VSCROLL);
  }
  
  return create_params;
}
