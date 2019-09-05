#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/label.hpp>
#include <xtd/forms/native/window_static.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/label.hpp"

using namespace xtd;
using namespace xtd::forms;

label::label() {
  this->make_control(*this);
  this->control::data_->size_ = this->default_size();
}

label& label::operator=(const label& value) {
  this->control::operator=(value);
  this->data_ = value.data_;
  return *this;
}

label& label::border_style(forms::border_style border_style) {
  if (this->data_->border_style_ != border_style) {
    this->data_->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

forms::create_params label::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("STATIC");
  create_params.style(create_params.style() | SS_LEFT);

  if (this->control::data_->auto_size_) {
    drawing::size size = this->measure_string();
    create_params.width(size.width());
    create_params.height(size.height());
  }
  else create_params.style(create_params.style() | SS_LEFT);
    
  if (this->data_->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->data_->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);

  return create_params;
}

drawing::size label::measure_string() const {
  return drawing::size::ceiling(this->create_graphics().measure_string(this->control::data_->text_, this->font())) + drawing::size(2 + (this->data_->border_style_ == border_style::none ? 0 : 4), 1 + (this->data_->border_style_ == border_style::none ? 0 : 4));
}

void label::force_update_size() {
  this->control::data_->size_ = this->control::data_->client_size_ = this->measure_string();
  native::control::size(this->control::data_->handle_, this->control::data_->size_);
}
