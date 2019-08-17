#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/panel.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/panel.hpp"

using namespace xtd;
using namespace xtd::forms;

panel& panel::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

void panel::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  
  if (this->border_style_ == forms::border_style::fixed_single) styles |= WS_BORDER;
  else if (this->border_style_ == forms::border_style::fixed_3d) ex_styles |= WS_EX_CLIENTEDGE;

  this->handle_ = native::panel::create(this->parent_->__get_handle__(), this->default_size(), styles, ex_styles);
  this->control::create_handle();
}
