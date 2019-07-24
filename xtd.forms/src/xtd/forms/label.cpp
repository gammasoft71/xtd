#include "../../../include/xtd/forms/label.hpp"
#include "../../native/label_api.hpp"

using namespace xtd::forms;

void label::create_handle() {
  this->handle_ = native::label_api::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
}

