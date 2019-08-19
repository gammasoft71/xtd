#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/label.hpp>
#include <xtd/forms/native/window_static.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/label.hpp"

using namespace xtd;
using namespace xtd::forms;

label::label() {
  this->size_ = this->default_size();
}

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
  this->handle_ = native::label::create(this->create_params());
  this->control::create_handle();
}

forms::create_params label::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("STATIC");
  create_params.style(create_params.style() | SS_LEFT);

  if (this->auto_size_) create_params.style(create_params.style() | SS_AUTOSIZE);
  else create_params.style(create_params.style() | SS_LEFT);
    
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);

  return create_params;
}
