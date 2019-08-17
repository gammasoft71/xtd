#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/label.hpp>
#include <xtd/forms/native/window_static.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/label.hpp"

using namespace xtd;
using namespace xtd::forms;

label& label::auto_size(bool auto_size) {
  if (this->auto_size_ != auto_size) {
    this->auto_size_ = auto_size;
    this->recreate_handle();
    this->on_auto_size_changed(event_args::empty);
  }
  return *this;
}

label& label::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

void label::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  
  if (this->auto_size_) styles += SS_AUTOSIZE;
  if (this->border_style_ == forms::border_style::fixed_single) styles |= WS_BORDER;
  else if (this->border_style_ == forms::border_style::fixed_3d) ex_styles |= WS_EX_CLIENTEDGE;

  this->handle_ = native::label::create(this->parent_->__get_handle__(), this->default_size(), styles, ex_styles);
  this->control::create_handle();
}
