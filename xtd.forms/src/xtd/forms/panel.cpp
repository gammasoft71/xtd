#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/panel.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/panel.hpp"

using namespace xtd;
using namespace xtd::forms;

panel::panel() {
  this->size_ = this->default_size();
}

panel& panel::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

void panel::create_handle() {
  this->handle_ = native::panel::create(this->create_params());
  this->control::create_handle();
}

forms::create_params panel::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}
