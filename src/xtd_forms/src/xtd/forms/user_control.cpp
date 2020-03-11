#include <xtd/forms/native/control.h>
#include <xtd/forms/native/user_control.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/user_control.h"

using namespace xtd;
using namespace xtd::forms;

user_control::user_control() {
  this->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->size_ = this->default_size();
}

user_control& user_control::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

user_control& user_control::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

forms::create_params user_control::create_params() const {
  forms::create_params create_params = this->scrollable_control::create_params();
  
  create_params.class_name("usercontrol");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}

void user_control::on_layout(const event_args& e) {
  this->scrollable_control::on_layout(e);
  if (auto_scroll_) native::user_control::virtual_size(handle(), display_rectangle().size());
}
