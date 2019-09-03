#include <xtd/environment.hpp>
#include <xtd/forms/native/button.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/button.hpp"

using namespace xtd;
using namespace xtd::forms;

button::button() {
  this->make_control(*this);
  this->control::data_->size_ = this->default_size();
}

button& button::operator=(const button& value) {
  this->control::operator=(value);
  this->data_ = value.data_;
  return *this;
}

forms::create_params button::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("BUTTON");
  create_params.style(create_params.style() | BS_PUSHBUTTON);
  
  return create_params;
}

