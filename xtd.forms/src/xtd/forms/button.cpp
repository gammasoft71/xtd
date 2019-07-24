#include "../../../include/xtd/forms/button.hpp"
#include "../../native/button_api.hpp"

using namespace xtd::forms;

void button::create_handle() {
  this->handle_ = native::button_api::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
}

