#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/up_down_base.h"

using namespace xtd;
using namespace xtd::forms;

up_down_base::up_down_base() {
  this->size_ = this->default_size();
}

up_down_base& up_down_base::border_style(forms::border_style value) {
  if (border_style_ != value) {
    border_style_ = value;
    recreate_handle();
  }
  return *this;
}

forms::create_params up_down_base::create_params() const {
  forms::create_params create_params = container_control::create_params();
  
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);

  return create_params;
}
