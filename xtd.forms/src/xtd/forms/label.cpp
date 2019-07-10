#include "../../../include/xtd/forms/label.hpp"
#include "../../native/label_api.hpp"

xtd::forms::label::label() {
}

void xtd::forms::label::create_handle() {
  this->handle_ = native::label_api::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
}

