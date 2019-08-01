#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/panel.hpp>
#include "../../../include/xtd/forms/panel.hpp"

using namespace xtd;
using namespace xtd::forms;

void panel::border_styles(forms::border_styles border_styles) {
  if (this->border_styles_ != border_styles) {
    this->border_styles_ = border_styles;
    this->re_create_control();
  }
}

void panel::create_handle() {
  native::panel::styles styles = native::panel::styles::none;
  if (this->border_styles_ == forms::border_styles::fixed_single) styles += native::panel::styles::border_fixed_single;
  if (this->border_styles_ == forms::border_styles::fixed_3d) styles += native::panel::styles::border_fixed_3d;
  this->handle_ = native::panel::create(this->parent_->__get_handle__(), this->default_size(), styles);
  this->control::create_handle();
}
