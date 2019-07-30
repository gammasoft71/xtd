#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/label.hpp>
#include "../../../include/xtd/forms/label.hpp"

using namespace xtd;
using namespace xtd::forms;

void label::auto_size(bool auto_size) {
  if (this->auto_size_ != auto_size) {
    this->auto_size_ = auto_size;
    this->re_create_control();
    this->on_auto_size_changed(event_args::empty);
  }
}

void label::border_styles(forms::border_styles border_styles) {
  if (this->border_styles_ != border_styles) {
    this->border_styles_ = border_styles;
    this->re_create_control();
  }
}

void label::create_handle() {
  native::label::styles styles = native::label::styles::none;
  if (this->auto_size_) styles += native::label::styles::auto_size;
  if (this->border_styles_ == forms::border_styles::fixed_single) styles += native::label::styles::border_fixed_single;
  if (this->border_styles_ == forms::border_styles::fixed_3d) styles += native::label::styles::border_fixed_3d;
  this->handle_ = native::label::create(this->parent_->__get_handle__(), this->default_size(), styles);
  this->control::create_handle();
}
