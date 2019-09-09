#include "../../../include/xtd/forms/button_base.hpp"
#include <xtd/forms/native/window_button.hpp>

using namespace xtd;
using namespace xtd::forms;

button_base::button_base() {
  this->make_control(*this);
  this->control::data_->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->control::data_->size_ = this->default_size();
}

button_base& button_base::operator=(const button_base& value) {
  this->control::operator=(value);
  this->data_ = value.data_;
  return *this;
}

forms::create_params button_base::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("button");
  
  return create_params;
}

drawing::size button_base::measure_control() const {
  return this->control::measure_text() + drawing::size(13, 0);
}

