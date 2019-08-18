#include <xtd/environment.hpp>
#include <xtd/forms/native/button.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/button.hpp"

using namespace xtd;
using namespace xtd::forms;

button::button() {
  this->create_params_.class_name("Button").style(BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD);
  this->size(this->default_size());
}

void button::create_handle() {
  this->handle_ = native::button::create(this->parent_->__get_handle__(), this->default_size(), 0, 0);
  this->control::create_handle();
}
