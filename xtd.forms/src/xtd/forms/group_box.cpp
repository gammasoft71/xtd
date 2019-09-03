#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/group_box.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/group_box.hpp"

using namespace xtd;
using namespace xtd::forms;

group_box::group_box() {
  this->make_control(*this);
  this->control::data_->size_ = this->default_size();
}

forms::create_params group_box::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("GROUPBOX"); // "BUTTON" for win32
  create_params.style(create_params.style() | BS_GROUPBOX);
  
  return create_params;
}

group_box& group_box::operator=(const group_box& value) {
  this->control::operator=(value);
  this->data_ = value.data_;
  return *this;
}
