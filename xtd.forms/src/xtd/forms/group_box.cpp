#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/group_box.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/group_box.hpp"

using namespace xtd;
using namespace xtd::forms;

group_box::group_box() {
  this->size_ = this->default_size();
}

void group_box::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  this->handle_ = native::group_box::create(this->parent_->__get_handle__(), this->default_size(), styles, ex_styles);
  this->control::create_handle();
}

forms::create_params group_box::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("BUTTON");
  create_params.style(create_params.style() | BS_GROUPBOX);
  
  return create_params;
}
